#pragma once
#include <QObject>

#include "Movie.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"


#define SHOW_MODE() mv::MainWindow::getInstanseUI()->checkBox->isChecked();


namespace mv::ctrl
{
	extern const QString

//Path aliases:
		SttngsDir,
		TemplDir,
		DfltName,
		CurrDir,
		JsonF,
		Slsh,

//Json aliases:
		IVP, OVD, OVN, OVF, TIP, PtX,
		PtY, SAW, SAH, TTK, TAK, TBK,
		FrS, Threshold, Threads, PRV;


	void createPreviosFile(const QString &nameArg = DfltName);

	void loadPreviosUserSettings();

	void saveSettings(const QString &name, const data::Data &data);

	void loadSettings(const QString &name);

	void deleteSettings(const QString &name);

	void startBackend() noexcept;


//Signal hander:

	class Controller : public QObject
	{
		Q_OBJECT

	private:

		static Controller *singleton;

		Controller() = default;
		~Controller() = default;
		Controller(Controller&&) = delete;
		Controller(const Controller&) = delete;

	public:

		static Controller* getInstanse() noexcept;

	public slots:

		void catchLog(const std::string &log);
		void createMovie() noexcept;
		void frize(bool val = false);
	};


//Parsers:

	data::Data* parseUserInput() noexcept;

	void parseUserInput(QJsonObject &write_obj) noexcept;

	void parseUserInput(QJsonObject &write_obj, const data::Data &data);

	void parseJsonToUi(const QJsonObject &source_obj);
}
