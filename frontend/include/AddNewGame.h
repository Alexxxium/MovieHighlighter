#ifndef ADDNEWGAME_H
#define ADDNEWGAME_H

#include <QDialog>


namespace Ui { class AddNewGame; }


namespace mv
{
    class AddNewGame: public QDialog
    {
        Q_OBJECT

    public:

        explicit AddNewGame(QWidget *parent = nullptr);
        ~AddNewGame();


    private slots:

        void on_ok_push_btn_clicked();
        void on_cancel_push_btn_clicked();

    private:

        Ui::AddNewGame *ui;
    };
}

#endif // ADDNEWGAME_H
