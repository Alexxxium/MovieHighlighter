/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *propertyes_group_box;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_7;
    QFormLayout *formLayout_4;
    QLabel *ttk_lable;
    QDoubleSpinBox *ttk_spin;
    QLabel *tak_lable;
    QDoubleSpinBox *tak_spin;
    QLabel *tbk_lable;
    QDoubleSpinBox *tbk_spin;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout_2;
    QLabel *width_lable;
    QLabel *pos_metrixs_lable;
    QSpinBox *posY_spin;
    QSpinBox *width_spin;
    QLabel *posX_lable;
    QSpinBox *posX_spin;
    QLabel *height_lable;
    QLabel *size_metrix_lable;
    QLabel *posY_lable;
    QSpinBox *height_spin;
    QSpacerItem *horizontalSpacer_3;
    QFormLayout *formLayout_5;
    QLabel *frame_step_lable;
    QSpinBox *frame_step_spin;
    QLabel *threshold_lable;
    QDoubleSpinBox *threshold_spin;
    QLabel *threads_count_lable;
    QSpinBox *threads_count_spin;
    QSpacerItem *verticalSpacer;
    QPushButton *save_push_btn;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *new_push_btn;
    QPushButton *delete_push_btn;
    QCheckBox *checkBox;
    QLabel *game_lable;
    QComboBox *games_list;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout_5;
    QLabel *template_lable;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *template_line_edit;
    QPushButton *set_push_btn;
    QSpacerItem *horizontalSpacer_7;
    QTextBrowser *textBrowser;
    QFormLayout *formLayout_3;
    QLabel *input_video_lable;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *input_video_line_edit;
    QPushButton *input_video_push_btn;
    QLabel *output_dir_lable;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *output_dir_line_edit;
    QPushButton *output_dir_push_btn;
    QLabel *movie_name_lable;
    QLineEdit *movie_name_line_edit;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer;
    QPushButton *clean_psh_btn;
    QPushButton *create_movie_push_btn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(762, 822);
        MainWindow->setMinimumSize(QSize(600, 0));
        MainWindow->setWindowTitle(QString::fromUtf8("MovieHighlighter"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        propertyes_group_box = new QGroupBox(centralwidget);
        propertyes_group_box->setObjectName(QString::fromUtf8("propertyes_group_box"));
        propertyes_group_box->setMinimumSize(QSize(200, 0));
        propertyes_group_box->setMaximumSize(QSize(177, 16777215));
        gridLayout_4 = new QGridLayout(propertyes_group_box);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setSizeConstraint(QLayout::SetFixedSize);
        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        formLayout_4->setSizeConstraint(QLayout::SetMinimumSize);
        ttk_lable = new QLabel(propertyes_group_box);
        ttk_lable->setObjectName(QString::fromUtf8("ttk_lable"));
        QFont font;
        font.setPointSize(9);
        ttk_lable->setFont(font);

        formLayout_4->setWidget(0, QFormLayout::LabelRole, ttk_lable);

        ttk_spin = new QDoubleSpinBox(propertyes_group_box);
        ttk_spin->setObjectName(QString::fromUtf8("ttk_spin"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Comic Sans MS"));
        ttk_spin->setFont(font1);
        ttk_spin->setStyleSheet(QString::fromUtf8(""));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, ttk_spin);

        tak_lable = new QLabel(propertyes_group_box);
        tak_lable->setObjectName(QString::fromUtf8("tak_lable"));
        tak_lable->setFont(font);

        formLayout_4->setWidget(1, QFormLayout::LabelRole, tak_lable);

        tak_spin = new QDoubleSpinBox(propertyes_group_box);
        tak_spin->setObjectName(QString::fromUtf8("tak_spin"));
        tak_spin->setFont(font1);

        formLayout_4->setWidget(1, QFormLayout::FieldRole, tak_spin);

        tbk_lable = new QLabel(propertyes_group_box);
        tbk_lable->setObjectName(QString::fromUtf8("tbk_lable"));
        tbk_lable->setFont(font);

        formLayout_4->setWidget(2, QFormLayout::LabelRole, tbk_lable);

        tbk_spin = new QDoubleSpinBox(propertyes_group_box);
        tbk_spin->setObjectName(QString::fromUtf8("tbk_spin"));
        tbk_spin->setFont(font1);

        formLayout_4->setWidget(2, QFormLayout::FieldRole, tbk_spin);


        verticalLayout_7->addLayout(formLayout_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_7->addItem(horizontalSpacer_2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        width_lable = new QLabel(propertyes_group_box);
        width_lable->setObjectName(QString::fromUtf8("width_lable"));

        gridLayout_2->addWidget(width_lable, 3, 1, 1, 1);

        pos_metrixs_lable = new QLabel(propertyes_group_box);
        pos_metrixs_lable->setObjectName(QString::fromUtf8("pos_metrixs_lable"));
        pos_metrixs_lable->setFont(font);

        gridLayout_2->addWidget(pos_metrixs_lable, 0, 0, 2, 1);

        posY_spin = new QSpinBox(propertyes_group_box);
        posY_spin->setObjectName(QString::fromUtf8("posY_spin"));
        posY_spin->setMinimumSize(QSize(50, 0));
        posY_spin->setFont(font1);

        gridLayout_2->addWidget(posY_spin, 1, 2, 1, 1);

        width_spin = new QSpinBox(propertyes_group_box);
        width_spin->setObjectName(QString::fromUtf8("width_spin"));
        width_spin->setMinimumSize(QSize(50, 0));
        width_spin->setFont(font1);

        gridLayout_2->addWidget(width_spin, 2, 2, 1, 1);

        posX_lable = new QLabel(propertyes_group_box);
        posX_lable->setObjectName(QString::fromUtf8("posX_lable"));

        gridLayout_2->addWidget(posX_lable, 0, 1, 1, 1);

        posX_spin = new QSpinBox(propertyes_group_box);
        posX_spin->setObjectName(QString::fromUtf8("posX_spin"));
        posX_spin->setEnabled(true);
        posX_spin->setMinimumSize(QSize(50, 0));
        posX_spin->setFont(font1);

        gridLayout_2->addWidget(posX_spin, 0, 2, 1, 1);

        height_lable = new QLabel(propertyes_group_box);
        height_lable->setObjectName(QString::fromUtf8("height_lable"));

        gridLayout_2->addWidget(height_lable, 2, 1, 1, 1);

        size_metrix_lable = new QLabel(propertyes_group_box);
        size_metrix_lable->setObjectName(QString::fromUtf8("size_metrix_lable"));
        size_metrix_lable->setFont(font);

        gridLayout_2->addWidget(size_metrix_lable, 2, 0, 2, 1);

        posY_lable = new QLabel(propertyes_group_box);
        posY_lable->setObjectName(QString::fromUtf8("posY_lable"));

        gridLayout_2->addWidget(posY_lable, 1, 1, 1, 1);

        height_spin = new QSpinBox(propertyes_group_box);
        height_spin->setObjectName(QString::fromUtf8("height_spin"));
        height_spin->setMinimumSize(QSize(50, 0));
        height_spin->setFont(font1);

        gridLayout_2->addWidget(height_spin, 3, 2, 1, 1);


        verticalLayout_7->addLayout(gridLayout_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_7->addItem(horizontalSpacer_3);

        formLayout_5 = new QFormLayout();
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        frame_step_lable = new QLabel(propertyes_group_box);
        frame_step_lable->setObjectName(QString::fromUtf8("frame_step_lable"));
        frame_step_lable->setFont(font);

        formLayout_5->setWidget(0, QFormLayout::LabelRole, frame_step_lable);

        frame_step_spin = new QSpinBox(propertyes_group_box);
        frame_step_spin->setObjectName(QString::fromUtf8("frame_step_spin"));
        frame_step_spin->setFont(font1);

        formLayout_5->setWidget(0, QFormLayout::FieldRole, frame_step_spin);

        threshold_lable = new QLabel(propertyes_group_box);
        threshold_lable->setObjectName(QString::fromUtf8("threshold_lable"));
        threshold_lable->setFont(font);

        formLayout_5->setWidget(1, QFormLayout::LabelRole, threshold_lable);

        threshold_spin = new QDoubleSpinBox(propertyes_group_box);
        threshold_spin->setObjectName(QString::fromUtf8("threshold_spin"));
        threshold_spin->setFont(font1);

        formLayout_5->setWidget(1, QFormLayout::FieldRole, threshold_spin);

        threads_count_lable = new QLabel(propertyes_group_box);
        threads_count_lable->setObjectName(QString::fromUtf8("threads_count_lable"));
        threads_count_lable->setFont(font);

        formLayout_5->setWidget(2, QFormLayout::LabelRole, threads_count_lable);

        threads_count_spin = new QSpinBox(propertyes_group_box);
        threads_count_spin->setObjectName(QString::fromUtf8("threads_count_spin"));
        threads_count_spin->setFont(font1);

        formLayout_5->setWidget(2, QFormLayout::FieldRole, threads_count_spin);


        verticalLayout_7->addLayout(formLayout_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer);

        save_push_btn = new QPushButton(propertyes_group_box);
        save_push_btn->setObjectName(QString::fromUtf8("save_push_btn"));
        save_push_btn->setMaximumSize(QSize(16777215, 16777215));
        save_push_btn->setLayoutDirection(Qt::LeftToRight);
        save_push_btn->setFlat(false);

        verticalLayout_7->addWidget(save_push_btn);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(26);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        new_push_btn = new QPushButton(propertyes_group_box);
        new_push_btn->setObjectName(QString::fromUtf8("new_push_btn"));

        horizontalLayout_7->addWidget(new_push_btn);

        delete_push_btn = new QPushButton(propertyes_group_box);
        delete_push_btn->setObjectName(QString::fromUtf8("delete_push_btn"));
        delete_push_btn->setMaximumSize(QSize(75, 16777215));

        horizontalLayout_7->addWidget(delete_push_btn);


        verticalLayout_7->addLayout(horizontalLayout_7);


        gridLayout_4->addLayout(verticalLayout_7, 9, 0, 1, 1);

        checkBox = new QCheckBox(propertyes_group_box);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        gridLayout_4->addWidget(checkBox, 7, 0, 1, 1);

        game_lable = new QLabel(propertyes_group_box);
        game_lable->setObjectName(QString::fromUtf8("game_lable"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setWeight(50);
        game_lable->setFont(font2);

        gridLayout_4->addWidget(game_lable, 0, 0, 1, 1);

        games_list = new QComboBox(propertyes_group_box);
        games_list->setObjectName(QString::fromUtf8("games_list"));
        games_list->setFont(font1);

        gridLayout_4->addWidget(games_list, 1, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_6, 2, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_4, 5, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_5, 8, 0, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        template_lable = new QLabel(propertyes_group_box);
        template_lable->setObjectName(QString::fromUtf8("template_lable"));
        QFont font3;
        font3.setPointSize(10);
        template_lable->setFont(font3);

        verticalLayout_5->addWidget(template_lable);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        template_line_edit = new QLineEdit(propertyes_group_box);
        template_line_edit->setObjectName(QString::fromUtf8("template_line_edit"));
        template_line_edit->setEnabled(false);
        template_line_edit->setFont(font1);

        horizontalLayout_3->addWidget(template_line_edit);

        set_push_btn = new QPushButton(propertyes_group_box);
        set_push_btn->setObjectName(QString::fromUtf8("set_push_btn"));
        set_push_btn->setMinimumSize(QSize(75, 0));
        set_push_btn->setMaximumSize(QSize(15, 16777215));
        set_push_btn->setBaseSize(QSize(20, 0));

        horizontalLayout_3->addWidget(set_push_btn);


        verticalLayout_5->addLayout(horizontalLayout_3);


        gridLayout_4->addLayout(verticalLayout_5, 3, 0, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_7, 6, 0, 1, 1);


        horizontalLayout_2->addWidget(propertyes_group_box);

        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setFont(font1);

        horizontalLayout_2->addWidget(textBrowser);


        gridLayout_3->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        input_video_lable = new QLabel(centralwidget);
        input_video_lable->setObjectName(QString::fromUtf8("input_video_lable"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, input_video_lable);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        input_video_line_edit = new QLineEdit(centralwidget);
        input_video_line_edit->setObjectName(QString::fromUtf8("input_video_line_edit"));
        input_video_line_edit->setFont(font1);

        horizontalLayout_4->addWidget(input_video_line_edit);

        input_video_push_btn = new QPushButton(centralwidget);
        input_video_push_btn->setObjectName(QString::fromUtf8("input_video_push_btn"));

        horizontalLayout_4->addWidget(input_video_push_btn);


        formLayout_3->setLayout(0, QFormLayout::FieldRole, horizontalLayout_4);

        output_dir_lable = new QLabel(centralwidget);
        output_dir_lable->setObjectName(QString::fromUtf8("output_dir_lable"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, output_dir_lable);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        output_dir_line_edit = new QLineEdit(centralwidget);
        output_dir_line_edit->setObjectName(QString::fromUtf8("output_dir_line_edit"));
        output_dir_line_edit->setFont(font1);

        horizontalLayout_5->addWidget(output_dir_line_edit);

        output_dir_push_btn = new QPushButton(centralwidget);
        output_dir_push_btn->setObjectName(QString::fromUtf8("output_dir_push_btn"));

        horizontalLayout_5->addWidget(output_dir_push_btn);


        formLayout_3->setLayout(1, QFormLayout::FieldRole, horizontalLayout_5);

        movie_name_lable = new QLabel(centralwidget);
        movie_name_lable->setObjectName(QString::fromUtf8("movie_name_lable"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, movie_name_lable);

        movie_name_line_edit = new QLineEdit(centralwidget);
        movie_name_line_edit->setObjectName(QString::fromUtf8("movie_name_line_edit"));
        movie_name_line_edit->setFont(font1);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, movie_name_line_edit);


        gridLayout_3->addLayout(formLayout_3, 0, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        clean_psh_btn = new QPushButton(centralwidget);
        clean_psh_btn->setObjectName(QString::fromUtf8("clean_psh_btn"));

        horizontalLayout_8->addWidget(clean_psh_btn);

        create_movie_push_btn = new QPushButton(centralwidget);
        create_movie_push_btn->setObjectName(QString::fromUtf8("create_movie_push_btn"));

        horizontalLayout_8->addWidget(create_movie_push_btn);


        gridLayout_3->addLayout(horizontalLayout_8, 3, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 762, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        propertyes_group_box->setTitle(QString());
#ifndef QT_NO_TOOLTIP
        ttk_lable->setToolTip(QApplication::translate("MainWindow", "How many seconds write to movie befor kill", nullptr));
#endif // QT_NO_TOOLTIP
        ttk_lable->setText(QApplication::translate("MainWindow", "time to kill (s):", nullptr));
#ifndef QT_NO_TOOLTIP
        ttk_spin->setToolTip(QApplication::translate("MainWindow", "How many seconds write to movie befor kill", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        tak_lable->setToolTip(QApplication::translate("MainWindow", "How many seconds write to movie after kill", nullptr));
#endif // QT_NO_TOOLTIP
        tak_lable->setText(QApplication::translate("MainWindow", "time after kill (s):", nullptr));
#ifndef QT_NO_TOOLTIP
        tak_spin->setToolTip(QApplication::translate("MainWindow", "How many seconds write to movie after kill", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        tbk_lable->setToolTip(QApplication::translate("MainWindow", "How many seconds count before splice moments", nullptr));
#endif // QT_NO_TOOLTIP
        tbk_lable->setText(QApplication::translate("MainWindow", "time between kills (s): ", nullptr));
#ifndef QT_NO_TOOLTIP
        tbk_spin->setToolTip(QApplication::translate("MainWindow", "How many seconds count before splice moments", nullptr));
#endif // QT_NO_TOOLTIP
        width_lable->setText(QApplication::translate("MainWindow", "H:", nullptr));
#ifndef QT_NO_TOOLTIP
        pos_metrixs_lable->setToolTip(QApplication::translate("MainWindow", "Start point (x, y) in your video (not monitor)", nullptr));
#endif // QT_NO_TOOLTIP
        pos_metrixs_lable->setText(QApplication::translate("MainWindow", "<html><head/><body><p>top left position<br/>in search area (px)</p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        posY_spin->setToolTip(QApplication::translate("MainWindow", "Rectangel from point ", nullptr));
#endif // QT_NO_TOOLTIP
        posX_lable->setText(QApplication::translate("MainWindow", "X:", nullptr));
#ifndef QT_NO_TOOLTIP
        posX_spin->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        height_lable->setText(QApplication::translate("MainWindow", "W:", nullptr));
#ifndef QT_NO_TOOLTIP
        size_metrix_lable->setToolTip(QApplication::translate("MainWindow", "Rectagel where search kills flags", nullptr));
#endif // QT_NO_TOOLTIP
        size_metrix_lable->setText(QApplication::translate("MainWindow", "sizes of\n"
"search area     (px)", nullptr));
        posY_lable->setText(QApplication::translate("MainWindow", "Y:", nullptr));
#ifndef QT_NO_TOOLTIP
        frame_step_lable->setToolTip(QApplication::translate("MainWindow", "How many frames skip - increment", nullptr));
#endif // QT_NO_TOOLTIP
        frame_step_lable->setText(QApplication::translate("MainWindow", "frame step:", nullptr));
#ifndef QT_NO_TOOLTIP
        frame_step_spin->setToolTip(QApplication::translate("MainWindow", "How many frames skip - increment", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        threshold_lable->setToolTip(QApplication::translate("MainWindow", "Threshold of match", nullptr));
#endif // QT_NO_TOOLTIP
        threshold_lable->setText(QApplication::translate("MainWindow", "threshold:", nullptr));
#ifndef QT_NO_TOOLTIP
        threshold_spin->setToolTip(QApplication::translate("MainWindow", "Threshold of match", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        threads_count_lable->setToolTip(QApplication::translate("MainWindow", "You can set optimal value for your PC", nullptr));
#endif // QT_NO_TOOLTIP
        threads_count_lable->setText(QApplication::translate("MainWindow", "threads count:               ", nullptr));
#ifndef QT_NO_TOOLTIP
        threads_count_spin->setToolTip(QApplication::translate("MainWindow", "You can set optimal value for your PC", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        save_push_btn->setToolTip(QApplication::translate("MainWindow", "Save current settings", nullptr));
#endif // QT_NO_TOOLTIP
        save_push_btn->setText(QApplication::translate("MainWindow", "Save", nullptr));
#ifndef QT_NO_TOOLTIP
        new_push_btn->setToolTip(QApplication::translate("MainWindow", "Create new game's settings", nullptr));
#endif // QT_NO_TOOLTIP
        new_push_btn->setText(QApplication::translate("MainWindow", "New", nullptr));
#ifndef QT_NO_TOOLTIP
        delete_push_btn->setToolTip(QApplication::translate("MainWindow", "Delete current settings", nullptr));
#endif // QT_NO_TOOLTIP
        delete_push_btn->setText(QApplication::translate("MainWindow", "Delete", nullptr));
#ifndef QT_NO_TOOLTIP
        checkBox->setToolTip(QApplication::translate("MainWindow", "You can look to real time proccess", nullptr));
#endif // QT_NO_TOOLTIP
        checkBox->setText(QApplication::translate("MainWindow", "show run-time proccess", nullptr));
#ifndef QT_NO_TOOLTIP
        game_lable->setToolTip(QApplication::translate("MainWindow", "Your settings names", nullptr));
#endif // QT_NO_TOOLTIP
        game_lable->setText(QApplication::translate("MainWindow", "Game:", nullptr));
#ifndef QT_NO_TOOLTIP
        games_list->setToolTip(QApplication::translate("MainWindow", "Your settings names", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        template_lable->setToolTip(QApplication::translate("MainWindow", "Image which used for finding kills", nullptr));
#endif // QT_NO_TOOLTIP
        template_lable->setText(QApplication::translate("MainWindow", "Template:", nullptr));
#ifndef QT_NO_TOOLTIP
        template_line_edit->setToolTip(QApplication::translate("MainWindow", "Image which used for finding kills", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        set_push_btn->setToolTip(QApplication::translate("MainWindow", "Select image", nullptr));
#endif // QT_NO_TOOLTIP
        set_push_btn->setText(QApplication::translate("MainWindow", "Set", nullptr));
#ifndef QT_NO_TOOLTIP
        input_video_lable->setToolTip(QApplication::translate("MainWindow", "Path to video whith game", nullptr));
#endif // QT_NO_TOOLTIP
        input_video_lable->setText(QApplication::translate("MainWindow", "    Input video:", nullptr));
#ifndef QT_NO_TOOLTIP
        input_video_line_edit->setToolTip(QApplication::translate("MainWindow", "Path to video whith game", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        input_video_push_btn->setToolTip(QApplication::translate("MainWindow", "Select video", nullptr));
#endif // QT_NO_TOOLTIP
        input_video_push_btn->setText(QApplication::translate("MainWindow", "Browse", nullptr));
#ifndef QT_NO_TOOLTIP
        output_dir_lable->setToolTip(QApplication::translate("MainWindow", "Path to folder for movie-game", nullptr));
#endif // QT_NO_TOOLTIP
        output_dir_lable->setText(QApplication::translate("MainWindow", "    Output dir:", nullptr));
#ifndef QT_NO_TOOLTIP
        output_dir_line_edit->setToolTip(QApplication::translate("MainWindow", "Path to folder for movie-game", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        output_dir_push_btn->setToolTip(QApplication::translate("MainWindow", "Select directory", nullptr));
#endif // QT_NO_TOOLTIP
        output_dir_push_btn->setText(QApplication::translate("MainWindow", "Browse", nullptr));
#ifndef QT_NO_TOOLTIP
        movie_name_lable->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Movie-game name</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        movie_name_lable->setText(QApplication::translate("MainWindow", "    Movie name:", nullptr));
#ifndef QT_NO_TOOLTIP
        movie_name_line_edit->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Movie-game name</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        clean_psh_btn->setToolTip(QApplication::translate("MainWindow", "Clean text browser", nullptr));
#endif // QT_NO_TOOLTIP
        clean_psh_btn->setText(QApplication::translate("MainWindow", "Clean", nullptr));
#ifndef QT_NO_TOOLTIP
        create_movie_push_btn->setToolTip(QApplication::translate("MainWindow", "Create clip", nullptr));
#endif // QT_NO_TOOLTIP
        create_movie_push_btn->setText(QApplication::translate("MainWindow", "Create Movie", nullptr));
        Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
