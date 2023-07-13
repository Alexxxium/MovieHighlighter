#include <QDir>
#include <QMutex>
#include <QProcess>
#include <QFileInfo>
#include <QException>
#include <QJsonObject>
#include <QMessageBox>
#include <QJsonDocument>

#include "Controller.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "MovieExceptions.h"



namespace mv::ctrl
{
//Aliases:
	const QString
		CurrDir = QDir::currentPath(),
		TemplDir = "/templates",
		SttngsDir = "/settings",
		DfltName = "default",
		PrevName = "previos",
		JsonF = ".json",
		Slsh = "/",

		IVP = "input_video_path",	OVD = "output_video_dir",	OVN = "output_video_name",	OVF = "output_video_format", 
		TIP = "template_img_path",	PtX = "point_x",			PtY = "point_y",			SAW = "search_area_w",			SAH = "search_area_h",		PRV = "prev",
		TTK = "ttk", TAK = "tak",	TBK = "tbk",				FrS = "frame_step",			Threshold = "threashold",		Threads = "threads_count",	CHECK = "cheked";
	


	Controller* Controller::singleton = nullptr;


	Controller* Controller::getInstanse() noexcept
	{
		if (!singleton) {
			singleton = new Controller;
		}
		return singleton;
	}

	void Controller::catchLog(const std::string &log)
	{
		mutex.lock();
		std::this_thread::sleep_for(std::chrono::milliseconds(10));		// WTF
		MainWindow::getInstanseUI()->textBrowser->append(log.c_str());
		mutex.unlock();
	}

	
	void Controller::createMovie() noexcept
	{
		constexpr auto
			error = "Error",
			run_time_err = "Run time error",
			unknown_type = "Unknown run time error!";
		
		std::unique_ptr<data::Data> user_input(parseUserInput());
		auto movie = Movie::getInstanse();

		try {
			user_input->dataIsValid();
			movie->updateData(std::move(*user_input));

			frize();
			std::thread backend([&]() { movie->createMovie(); });
			backend.detach();

			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
		catch (const std::exception &exc) {
			QMessageBox::information(nullptr, error, exc.what());
		}
	}

	void Controller::frize(bool val)
	{
		auto ui = MainWindow::getInstanseUI();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		ui->create_movie_push_btn->setEnabled(val);
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		ui->clean_psh_btn->setEnabled(val);
	}

	void createPreviosFile(const QString &nameArg)
	{
		QFile file(PrevName + JsonF);
		if (file.open(QIODevice::WriteOnly)) {
			QJsonObject obj;
			obj[PRV] = nameArg;
			QJsonDocument doc(std::move(obj));
			file.write(doc.toJson());
		}
		else {
			throw exc::invalidJson;
		}
	}

	void saveSettings(const QString &name, const data::Data &data)
	{
		QString file_path = CurrDir + SttngsDir + Slsh + name + JsonF;
		QString file_dir = CurrDir + SttngsDir;

		QFile file(file_path);
		QDir dir(file_dir);

		if (!dir.exists()) {
			dir.mkdir(CurrDir + SttngsDir);
		}
		if (file.open(QIODevice::WriteOnly)) {
			QJsonObject obj;
			parseUserInput(obj, data);
			QJsonDocument doc(obj);
			file.write(doc.toJson());
			file.close();
		}
		else {
			throw exc::invalidJson;
		}
	}

	void loadSettings(const QString &name)
	{
		QString file_path = CurrDir + SttngsDir + Slsh + name + JsonF;
		QString file_dir = CurrDir + SttngsDir;

		QFile file(file_path);
		QDir dir(file_dir);

		if (!dir.exists()) {
			dir.mkdir(CurrDir + SttngsDir);
		}
		if (file.open(QIODevice::ReadOnly)) {
			QJsonDocument doc = std::move(QJsonDocument::fromJson(std::move(file.readAll())));
			parseJsonToUi(doc.object());
			file.close();
		}
	}

	void deleteSettings(const QString &name)
	{
		QString file_path = CurrDir + SttngsDir + Slsh + name + JsonF;
		QFile file(file_path);
		file.remove();
	}


	void loadPreviosUserSettings()
	{
		QFile prev_file(CurrDir + Slsh + PrevName + JsonF);

		if (prev_file.open(QIODevice::ReadOnly)) {
			QJsonDocument doc = std::move(QJsonDocument::fromJson(std::move(prev_file.readAll())));
			QString name = doc[PRV].toString();
			prev_file.close();

			QFile sttngs(CurrDir + Slsh + SttngsDir + Slsh + name + JsonF);

			if (sttngs.open(QIODevice::ReadOnly)) {
				QDir dir(CurrDir + Slsh + SttngsDir);
				dir.setNameFilters(QStringList() << "*.json");

				QFileInfoList fileInfos = dir.entryInfoList();
				auto ui = MainWindow::getInstanseUI();

				for (const auto &i : fileInfos) {
					ui->games_list->addItem(i.baseName());
				}

				ui->games_list->setCurrentIndex(ui->games_list->findText(name));

				QJsonDocument sttngs_doc = std::move(QJsonDocument::fromJson(std::move(sttngs.readAll())));
				sttngs.close();
				parseJsonToUi(sttngs_doc.object());
			}
			else {										// default.json/some previos .json was lost!
				saveSettings(DfltName, data::Data());
				createPreviosFile();
				loadPreviosUserSettings();
			}
		}
		else {											// previos.json was lost
			createPreviosFile();
			loadPreviosUserSettings();
		}
	}


	void startBackend() noexcept
	{
		std::unique_ptr<data::Data> user_data(parseUserInput());
		auto movie = Movie::getInstanse();

		try {
			user_data->dataIsValid();
			movie->updateData(std::move(*user_data));

			std::thread backend([&]() { movie->createMovie(); });
			backend.detach();

			std::this_thread::sleep_for(std::chrono::seconds(1));			// Used user_data in createMovie until it is destroyed!
		}
		catch (const std::exception &exc) {
			QMessageBox::information(nullptr, "Error", exc.what());
		}
		catch (...) {
			QMessageBox::information(nullptr, "Error", "Unknown run-time error");
		}
	}


//Parsers:

	data::Data* parseUserInput() noexcept
	{
		data::Data *res = new data::Data;
		auto ui = MainWindow::getInstanseUI();
		QFileInfo file(ui->input_video_line_edit->text());
		
		res->input_video_path = ui->input_video_line_edit->text().toUtf8().constData();
		res->output_video_dir = ui->output_dir_line_edit->text().toUtf8().constData();
		res->output_video_name = ui->movie_name_line_edit->text().toUtf8().constData();
		res->output_video_format = "." + std::move(file.suffix().toStdString());
		res->template_img_path = (CurrDir + TemplDir + Slsh + ui->template_line_edit->text()).toUtf8().constData();
		res->template_pos = { ui->posX_spin->value(), ui->posY_spin->value() };
		res->search_area = { ui->width_spin->value(), ui->height_spin->value() };
		res->time_to_kill = ui->ttk_spin->value();
		res->time_after_kill = ui->tak_spin->value();
		res->time_between_kills = ui->tbk_spin->value();
		res->frame_step = ui->frame_step_spin->value();
		res->threshold = ui->threshold_spin->value();
		res->threads_count = ui->threads_count_spin->value();

		return res;
	}

	void parseUserInput(QJsonObject &write_obj) noexcept
	{
		const auto ui = MainWindow::getInstanseUI();
		QFileInfo file(ui->input_video_line_edit->text());

		write_obj[IVP] = ui->input_video_line_edit->text();
		write_obj[OVD] = ui->output_dir_line_edit->text();
		write_obj[OVN] = ui->movie_name_line_edit->text();
		write_obj[OVF] = file.suffix();
		write_obj[TIP] = CurrDir + TemplDir + Slsh + ui->template_line_edit->text();
		write_obj[PtX] = ui->posX_spin->value();
		write_obj[PtY] = ui->posY_spin->value();
		write_obj[SAW] = ui->width_spin->value();
		write_obj[SAH] = ui->height_spin->value();
		write_obj[TTK] = ui->ttk_spin->value();
		write_obj[TAK] = ui->tak_spin->value();
		write_obj[TBK] = ui->tbk_spin->value();
		write_obj[FrS] = ui->frame_step_spin->value();
		write_obj[Threshold] = ui->threshold_spin->value();
		write_obj[Threads] = ui->threads_count_spin->value();
	}

	void parseUserInput(QJsonObject &write_obj, const data::Data &data)
	{
		const auto ui = MainWindow::getInstanseUI();
		QFileInfo file(data.input_video_path.c_str());

		write_obj[IVP] = data.input_video_path.c_str();
		write_obj[OVD] = data.output_video_dir.c_str();
		write_obj[OVN] = data.output_video_name.c_str();
		write_obj[OVF] = file.suffix();
		write_obj[TIP] = CurrDir + TemplDir + Slsh + ui->template_line_edit->text();
		write_obj[PtX] = data.template_pos.x;
		write_obj[PtY] = data.template_pos.y;
		write_obj[SAW] = data.search_area.width;
		write_obj[SAH] = data.search_area.height;
		write_obj[TTK] = data.time_to_kill;
		write_obj[TAK] = data.time_after_kill;
		write_obj[TBK] = data.time_between_kills;
		write_obj[FrS] = data.frame_step;
		write_obj[Threshold] = data.threshold;
		write_obj[Threads] = data.threads_count;
	}

	void parseJsonToUi(const QJsonObject &source_obj)
	{
		auto ui = MainWindow::getInstanseUI();

		ui->input_video_line_edit->setText(source_obj[IVP].toString());
		ui->output_dir_line_edit->setText(source_obj[OVD].toString());
		ui->movie_name_line_edit->setText(source_obj[OVN].toString());
		ui->template_line_edit->setText(QFileInfo(source_obj[TIP].toString()).fileName());
		ui->posX_spin->setValue(source_obj[PtX].toInt());
		ui->posY_spin->setValue(source_obj[PtY].toInt());
		ui->width_spin->setValue(source_obj[SAW].toInt());
		ui->height_spin->setValue(source_obj[SAH].toInt());
		ui->ttk_spin->setValue(source_obj[TTK].toDouble());
		ui->tak_spin->setValue(source_obj[TAK].toDouble());
		ui->tbk_spin->setValue(source_obj[TBK].toDouble());
		ui->frame_step_spin->setValue(source_obj[FrS].toInt());
		ui->threshold_spin->setValue(source_obj[Threshold].toDouble());
		ui->threads_count_spin->setValue(source_obj[Threads].toInt());
	}
}
