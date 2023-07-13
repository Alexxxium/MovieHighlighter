#include "MovieExceptions.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "AddNewGame.h"
#include "Controller.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QFileInfo>
#include <QPixMap>



namespace mv
{
    MainWindow *MainWindow::singleton = nullptr;

    MainWindow::MainWindow(QWidget *parent):
        QMainWindow(parent),
        ui(new Ui::MainWindow)
    {
        ui->setupUi(this);

        constexpr int max_len = 10000, mid_len = 1000, one = 1, null = 0, threads_count = 9;
        constexpr double max_loc = 0.99, min_loc = 0.01;

        ui->posX_spin->setRange(null, max_len);
        ui->posY_spin->setRange(null, max_len);
        ui->width_spin->setRange(one, max_len);
        ui->height_spin->setRange(one, max_len);
        ui->frame_step_spin->setRange(one, mid_len);
        ui->threshold_spin->setRange(min_loc, max_loc);
        ui->threads_count_spin->setRange(one, threads_count);
        ui->threshold_spin->setSingleStep(min_loc);
        
        singleton = this;                           // Crutch! Because calling controller with not yet instantiated UI!
        ctrl::loadPreviosUserSettings();
        
        connect(ui->create_movie_push_btn, &QPushButton::clicked, ctrl::Controller::getInstanse(), &ctrl::Controller::createMovie);

       setWindowIcon(QPixmap(":/src/style/M.png"));
    }

    MainWindow::~MainWindow()
    {
        ctrl::createPreviosFile(ui->games_list->currentText());
        delete ui;
    }



    MainWindow *MainWindow::getInstanse(QWidget *parent) noexcept
    {
        if (!singleton) {
            singleton = new MainWindow(parent);
        }
        return singleton;
    }

    Ui::MainWindow *MainWindow::getInstanseUI() noexcept
    {
        if (!singleton) {
            return nullptr;
        }
        return singleton->ui;
    }



    void MainWindow::setEnableUI(bool val) noexcept
    {
        ui->input_video_line_edit->setEnabled(val);
        ui->output_dir_line_edit->setEnabled(val);
        ui->movie_name_line_edit->setEnabled(val);
        ui->template_line_edit->setEnabled(val);
        ui->posX_spin->setEnabled(val);
        ui->posY_spin->setEnabled(val);
        ui->width_spin->setEnabled(val);
        ui->height_spin->setEnabled(val);
        ui->ttk_spin->setEnabled(val);
        ui->tak_spin->setEnabled(val);
        ui->tbk_spin->setEnabled(val);
        ui->frame_step_spin->setEnabled(val);
        ui->threshold_spin->setEnabled(val);
        ui->threads_count_spin->setEnabled(val);
        ui->games_list->setEnabled(val);
        ui->input_video_push_btn->setEnabled(val);
        ui->output_dir_push_btn->setEnabled(val);
        ui->set_push_btn->setEnabled(val);
        ui->save_push_btn->setEnabled(val);
        ui->new_push_btn->setEnabled(val);
        ui->delete_push_btn->setEnabled(val);
        ui->create_movie_push_btn->setEnabled(val);
    }



    inline Ui::MainWindow *MainWindow::UI() noexcept
    {
        return ui;
    }

    inline void hashPath(QString &path, MainWindow *appl) noexcept
    {
        path = appl->ui->games_list->currentText() + '-' + QFileInfo(path).fileName();
    }



// Slots:
  
    void MainWindow::on_input_video_push_btn_clicked()
    {
        constexpr auto
            title = "Input video:",
            filter = "Media files (*.mp4 *.avi *.mkv)";

        QString user_chouse = QFileDialog::getOpenFileName(nullptr, title, "", filter);

        if (user_chouse.isEmpty()) {
            return;
        }

        ui->input_video_line_edit->setText(user_chouse);
    }

    void MainWindow::on_output_dir_push_btn_clicked()
    {
        constexpr auto title = "Output Directory:";
        QString user_chouse = QFileDialog::getExistingDirectory(nullptr, title, "", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

        if (user_chouse.isEmpty()) {
            return;
        }

        ui->output_dir_line_edit->setText(user_chouse);
    }

    void MainWindow::on_set_push_btn_clicked()
    {
        constexpr auto
            title = "Chouse Template:",
            filter = "Images (*.png *.jpeg *.jpg *.bmp)";
        
        QString user_chouse = QFileDialog::getOpenFileName(nullptr, title, "", filter);
        QFile src(user_chouse);

        if (user_chouse.isEmpty()) {
            return;
        }

        QString dir = ctrl::CurrDir + ctrl::TemplDir;
        QDir templates(dir);
        
        if (!templates.exists()) {
            templates.mkdir(dir);
        }

        hashPath(user_chouse, this);
        src.copy(dir + '/' + user_chouse);
        
        ui->template_line_edit->setText(user_chouse);
    }



    void MainWindow::on_save_push_btn_clicked()
    {
        std::unique_ptr<data::Data> data(ctrl::parseUserInput());
        ctrl::saveSettings(ui->games_list->currentText(), *data);
    }

    void MainWindow::on_new_push_btn_clicked()
    {
        std::unique_ptr<AddNewGame> dialog(new AddNewGame);
        dialog->exec();
    }

    void MainWindow::on_clean_psh_btn_clicked()
    {
        ui->textBrowser->clear();
    }

    void MainWindow::on_delete_push_btn_clicked()
    {
        if (ui->games_list->count() <= 1) {
            return;
        }

        constexpr auto 
            title = "Delete dialog", 
            prefix = "Do you really want to remove game settings: ";
        QString message = prefix + ui->games_list->currentText() + '?';

        QMessageBox::StandardButton reply = QMessageBox::question(this, title, message, QMessageBox::Ok | QMessageBox::Cancel);
        
        if (reply == QMessageBox::Ok) {
            ctrl::deleteSettings(ui->games_list->currentText());
            ui->games_list->removeItem(ui->games_list->currentIndex());
            ctrl::loadSettings(ui->games_list->itemText(ui->games_list->currentIndex()));
        }
    }

    void MainWindow::on_games_list_activated(int index)
    {
        static int prev = 0;

        if (prev != index) {
            ctrl::loadSettings(ui->games_list->itemText(index));
            prev = index;
        }
    }

    void MainWindow::closeEvent(QCloseEvent *event)
    {
        ctrl::createPreviosFile(ui->games_list->currentText());
        ctrl::saveSettings(ui->games_list->currentText(), *ctrl::parseUserInput());
        delete ui;
    }
}
