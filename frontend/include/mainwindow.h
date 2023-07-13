#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


namespace mv
{
    class MainWindow: public QMainWindow
    {
        Q_OBJECT

    public:

        static Ui::MainWindow* getInstanseUI() noexcept;
        static MainWindow* getInstanse(QWidget *parent = nullptr) noexcept;

        Ui::MainWindow* UI() noexcept;

        void setEnableUI(bool status) noexcept;

        friend void hashPath(QString &path, MainWindow *appl) noexcept;


    private slots:

        void on_set_push_btn_clicked();
        void on_new_push_btn_clicked();
        void on_clean_psh_btn_clicked();
        void on_save_push_btn_clicked();
        void on_delete_push_btn_clicked();
        void on_output_dir_push_btn_clicked();
        void on_input_video_push_btn_clicked();
        void on_games_list_activated(int index);
        void closeEvent(QCloseEvent *event) override;


    private:

        Ui::MainWindow *ui;
        static MainWindow *singleton;
        
        ~MainWindow();
        MainWindow(MainWindow &&) = delete;
        MainWindow(const MainWindow &) = delete;
        explicit MainWindow(QWidget *parent = nullptr);
    };
}

#endif // MAINWINDOW_H
