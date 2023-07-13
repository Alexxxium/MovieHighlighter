#include "ui_AddNewGame.h"
#include "ui_mainwindow.h"
#include "AddNewGame.h"
#include "mainwindow.h"
#include "Controller.h"



namespace mv
{
    AddNewGame::AddNewGame(QWidget *parent):
        QDialog(parent),
        ui(new Ui::AddNewGame)
    {
        ui->setupUi(this);

        constexpr auto title = "New game";
        setWindowTitle(title);
        setWindowIcon(QPixmap(":/src/style/M.png"));
    }

    AddNewGame::~AddNewGame()
    {
        delete ui;
    }



//Slots:

    void AddNewGame::on_ok_push_btn_clicked()
    {
        constexpr int min_len = 2;
        const auto &text = ui->line_edit->text();
        const auto &list = MainWindow::getInstanseUI()->games_list; 

        if (text.size() >= min_len && list->findText(text) == -1) {
            list->addItem(text);
            list->setCurrentIndex(list->count() - 1);
            std::unique_ptr<data::Data> data(ctrl::parseUserInput());
            ctrl::saveSettings(text, *data);
            closeEvent(nullptr);
        }
    }

    void AddNewGame::on_cancel_push_btn_clicked()
    {
        closeEvent(nullptr);
    }
}
