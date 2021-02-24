/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qwchartview.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_6;
    QTableView *tableView;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout_5;
    QTextBrowser *textBrowser;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_12;
    QPushButton *Btn_Exit;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QGroupBox *groupBox_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_10;
    QLabel *label_6;
    QLineEdit *line_B;
    QLineEdit *line_N_Frame;
    QLabel *label_11;
    QLineEdit *line_N_sample;
    QLabel *label_2;
    QLabel *label_8;
    QLineEdit *line_PRT;
    QLabel *label_3;
    QLabel *label_9;
    QLabel *label_7;
    QLineEdit *line_fc;
    QLabel *label_5;
    QLineEdit *line_delT_pulse;
    QLabel *label_4;
    QLineEdit *line_delT_frame;
    QLineEdit *line_N_chirp;
    QLineEdit *line_fs;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLineEdit *line_N_channel;
    QFrame *line;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QWidget *tab_2;
    QLineEdit *line_N_vt;
    QLabel *label_27;
    QLabel *label_12;
    QLabel *label_25;
    QLabel *label_26;
    QLineEdit *line_R_lr;
    QLabel *label_24;
    QLineEdit *line_N_K;
    QLabel *label_23;
    QLineEdit *line_threshold;
    QLineEdit *line_distance;
    QLineEdit *line_N_Q;
    QLabel *label_28;
    QLineEdit *line_delN_frame;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_33;
    QLabel *label_34;
    QLabel *label_35;
    QLabel *label_36;
    QLabel *label_37;
    QWidget *tab_3;
    QLabel *label_29;
    QLabel *label_38;
    QLineEdit *line_N_pulse;
    QLabel *label_39;
    QLabel *label_30;
    QLineEdit *line_N_theta;
    QPushButton *Btn_Confirm;
    QLabel *label_55;
    QLineEdit *line_delN_cont;
    QLabel *label_56;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *line_path;
    QPushButton *Btn_GetDir;
    QProgressBar *progressBar_proc;
    QPushButton *Btn_Proc;
    QTabWidget *tabWidget_2;
    QWidget *sd;
    QPushButton *Btn_draw_auto;
    QLabel *label_45;
    QLabel *label_46;
    QLabel *label_47;
    QLabel *label_48;
    QLineEdit *line_MeaV_2;
    QLabel *label_49;
    QLineEdit *line_frame_2s;
    QLineEdit *line_batch_2s;
    QLineEdit *line_channel_2;
    QLineEdit *line_MerV_2;
    QLabel *label_50;
    QLineEdit *line_batch_2e;
    QLabel *label_51;
    QLineEdit *line_frame_2e;
    QProgressBar *progressBar_play;
    QLineEdit *line_delt;
    QLabel *label_52;
    QLabel *label_53;
    QWidget *tab_5;
    QPushButton *Btn_draw;
    QLabel *label_41;
    QLabel *label_40;
    QLabel *label_43;
    QLabel *label_42;
    QLineEdit *line_MeaV;
    QLabel *label_44;
    QLineEdit *line_frame;
    QLineEdit *line_batch;
    QLineEdit *line_channel;
    QLineEdit *line_MerV;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *groupBox_8;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *Layout_RD;
    QHBoxLayout *horizontalLayout_8;
    QGroupBox *groupBox_9;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *Layout_Mea;
    QHBoxLayout *horizontalLayout_7;
    QGroupBox *groupBox_10;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *Layout_Mer;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox_11;
    QWChartView *Layout_Music;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1920, 1080);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalWidget = new QWidget(centralwidget);
        verticalWidget->setObjectName(QString::fromUtf8("verticalWidget"));
        verticalWidget->setGeometry(QRect(0, 0, 1921, 1041));
        verticalLayout = new QVBoxLayout(verticalWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalWidget = new QWidget(verticalWidget);
        horizontalWidget->setObjectName(QString::fromUtf8("horizontalWidget"));
        horizontalLayout = new QHBoxLayout(horizontalWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox_5 = new QGroupBox(horizontalWidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Devanagari"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        groupBox_5->setFont(font);
        verticalLayout_6 = new QVBoxLayout(groupBox_5);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        tableView = new QTableView(groupBox_5);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setStyleSheet(QString::fromUtf8(""));
        tableView->setFrameShape(QFrame::StyledPanel);

        verticalLayout_6->addWidget(tableView);


        verticalLayout_3->addWidget(groupBox_5);

        groupBox_7 = new QGroupBox(horizontalWidget);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setFont(font);
        verticalLayout_5 = new QVBoxLayout(groupBox_7);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        textBrowser = new QTextBrowser(groupBox_7);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_5->addWidget(textBrowser);


        verticalLayout_3->addWidget(groupBox_7);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 1);

        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groupBox_12 = new QGroupBox(horizontalWidget);
        groupBox_12->setObjectName(QString::fromUtf8("groupBox_12"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Consolas"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        groupBox_12->setFont(font1);
        Btn_Exit = new QPushButton(groupBox_12);
        Btn_Exit->setObjectName(QString::fromUtf8("Btn_Exit"));
        Btn_Exit->setGeometry(QRect(850, 10, 81, 51));

        verticalLayout_4->addWidget(groupBox_12);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(horizontalWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Consolas"));
        font2.setPointSize(10);
        groupBox->setFont(font2);
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 10, 451, 241));
        groupBox_3->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 127);"));
        tabWidget = new QTabWidget(groupBox_3);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 20, 431, 201));
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 127);"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label_10 = new QLabel(tab);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(220, 110, 52, 16));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(40, 140, 65, 16));
        line_B = new QLineEdit(tab);
        line_B->setObjectName(QString::fromUtf8("line_B"));
        line_B->setGeometry(QRect(290, 20, 61, 21));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(line_B->sizePolicy().hasHeightForWidth());
        line_B->setSizePolicy(sizePolicy1);
        line_N_Frame = new QLineEdit(tab);
        line_N_Frame->setObjectName(QString::fromUtf8("line_N_Frame"));
        line_N_Frame->setGeometry(QRect(124, 21, 51, 21));
        sizePolicy1.setHeightForWidth(line_N_Frame->sizePolicy().hasHeightForWidth());
        line_N_Frame->setSizePolicy(sizePolicy1);
        label_11 = new QLabel(tab);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(220, 140, 65, 16));
        line_N_sample = new QLineEdit(tab);
        line_N_sample->setObjectName(QString::fromUtf8("line_N_sample"));
        line_N_sample->setGeometry(QRect(124, 110, 51, 21));
        sizePolicy1.setHeightForWidth(line_N_sample->sizePolicy().hasHeightForWidth());
        line_N_sample->setSizePolicy(sizePolicy1);
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 21, 65, 16));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(220, 50, 34, 16));
        line_PRT = new QLineEdit(tab);
        line_PRT->setObjectName(QString::fromUtf8("line_PRT"));
        line_PRT->setGeometry(QRect(290, 50, 61, 21));
        sizePolicy1.setHeightForWidth(line_PRT->sizePolicy().hasHeightForWidth());
        line_PRT->setSizePolicy(sizePolicy1);
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 50, 78, 16));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(220, 80, 39, 16));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(220, 20, 65, 16));
        line_fc = new QLineEdit(tab);
        line_fc->setObjectName(QString::fromUtf8("line_fc"));
        line_fc->setGeometry(QRect(124, 140, 51, 21));
        sizePolicy1.setHeightForWidth(line_fc->sizePolicy().hasHeightForWidth());
        line_fc->setSizePolicy(sizePolicy1);
        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(40, 110, 78, 16));
        line_delT_pulse = new QLineEdit(tab);
        line_delT_pulse->setObjectName(QString::fromUtf8("line_delT_pulse"));
        line_delT_pulse->setGeometry(QRect(290, 80, 61, 21));
        sizePolicy1.setHeightForWidth(line_delT_pulse->sizePolicy().hasHeightForWidth());
        line_delT_pulse->setSizePolicy(sizePolicy1);
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 80, 78, 16));
        line_delT_frame = new QLineEdit(tab);
        line_delT_frame->setObjectName(QString::fromUtf8("line_delT_frame"));
        line_delT_frame->setGeometry(QRect(290, 140, 61, 21));
        sizePolicy1.setHeightForWidth(line_delT_frame->sizePolicy().hasHeightForWidth());
        line_delT_frame->setSizePolicy(sizePolicy1);
        line_N_chirp = new QLineEdit(tab);
        line_N_chirp->setObjectName(QString::fromUtf8("line_N_chirp"));
        line_N_chirp->setGeometry(QRect(124, 80, 51, 21));
        sizePolicy1.setHeightForWidth(line_N_chirp->sizePolicy().hasHeightForWidth());
        line_N_chirp->setSizePolicy(sizePolicy1);
        line_fs = new QLineEdit(tab);
        line_fs->setObjectName(QString::fromUtf8("line_fs"));
        line_fs->setGeometry(QRect(290, 110, 61, 21));
        sizePolicy1.setHeightForWidth(line_fs->sizePolicy().hasHeightForWidth());
        line_fs->setSizePolicy(sizePolicy1);
        label_13 = new QLabel(tab);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(180, 21, 16, 16));
        label_14 = new QLabel(tab);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(180, 50, 16, 16));
        label_15 = new QLabel(tab);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(180, 80, 16, 16));
        label_16 = new QLabel(tab);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(180, 110, 16, 16));
        label_17 = new QLabel(tab);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(180, 140, 21, 16));
        line_N_channel = new QLineEdit(tab);
        line_N_channel->setObjectName(QString::fromUtf8("line_N_channel"));
        line_N_channel->setGeometry(QRect(124, 50, 51, 21));
        sizePolicy1.setHeightForWidth(line_N_channel->sizePolicy().hasHeightForWidth());
        line_N_channel->setSizePolicy(sizePolicy1);
        line = new QFrame(tab);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(200, 0, 20, 181));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        label_18 = new QLabel(tab);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(360, 20, 21, 16));
        label_19 = new QLabel(tab);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(360, 50, 21, 16));
        label_20 = new QLabel(tab);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(360, 80, 21, 16));
        label_21 = new QLabel(tab);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(360, 110, 31, 16));
        label_22 = new QLabel(tab);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(360, 140, 21, 16));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        line_N_vt = new QLineEdit(tab_2);
        line_N_vt->setObjectName(QString::fromUtf8("line_N_vt"));
        line_N_vt->setGeometry(QRect(216, 32, 81, 17));
        label_27 = new QLabel(tab_2);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(119, 124, 78, 16));
        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(119, 9, 65, 16));
        label_25 = new QLabel(tab_2);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(119, 78, 65, 16));
        label_26 = new QLabel(tab_2);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(119, 101, 91, 16));
        line_R_lr = new QLineEdit(tab_2);
        line_R_lr->setObjectName(QString::fromUtf8("line_R_lr"));
        line_R_lr->setGeometry(QRect(216, 124, 81, 17));
        label_24 = new QLabel(tab_2);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(119, 55, 91, 16));
        line_N_K = new QLineEdit(tab_2);
        line_N_K->setObjectName(QString::fromUtf8("line_N_K"));
        line_N_K->setGeometry(QRect(216, 9, 81, 17));
        label_23 = new QLabel(tab_2);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(119, 32, 91, 16));
        line_threshold = new QLineEdit(tab_2);
        line_threshold->setObjectName(QString::fromUtf8("line_threshold"));
        line_threshold->setGeometry(QRect(216, 78, 81, 17));
        line_distance = new QLineEdit(tab_2);
        line_distance->setObjectName(QString::fromUtf8("line_distance"));
        line_distance->setGeometry(QRect(216, 101, 81, 17));
        line_N_Q = new QLineEdit(tab_2);
        line_N_Q->setObjectName(QString::fromUtf8("line_N_Q"));
        line_N_Q->setGeometry(QRect(216, 55, 81, 17));
        label_28 = new QLabel(tab_2);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(119, 147, 65, 16));
        line_delN_frame = new QLineEdit(tab_2);
        line_delN_frame->setObjectName(QString::fromUtf8("line_delN_frame"));
        line_delN_frame->setGeometry(QRect(216, 147, 81, 17));
        label_31 = new QLabel(tab_2);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(310, 9, 16, 16));
        label_32 = new QLabel(tab_2);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(310, 32, 16, 16));
        label_33 = new QLabel(tab_2);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(310, 55, 16, 16));
        label_34 = new QLabel(tab_2);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(353, 78, 16, 16));
        label_35 = new QLabel(tab_2);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(310, 101, 16, 16));
        label_36 = new QLabel(tab_2);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setGeometry(QRect(310, 124, 16, 16));
        label_37 = new QLabel(tab_2);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(310, 147, 16, 16));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        label_29 = new QLabel(tab_3);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(119, 19, 78, 16));
        label_38 = new QLabel(tab_3);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setGeometry(QRect(300, 19, 16, 16));
        line_N_pulse = new QLineEdit(tab_3);
        line_N_pulse->setObjectName(QString::fromUtf8("line_N_pulse"));
        line_N_pulse->setGeometry(QRect(216, 19, 71, 21));
        label_39 = new QLabel(tab_3);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setGeometry(QRect(300, 56, 16, 16));
        label_30 = new QLabel(tab_3);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(119, 56, 72, 16));
        line_N_theta = new QLineEdit(tab_3);
        line_N_theta->setObjectName(QString::fromUtf8("line_N_theta"));
        line_N_theta->setGeometry(QRect(216, 56, 71, 21));
        Btn_Confirm = new QPushButton(tab_3);
        Btn_Confirm->setObjectName(QString::fromUtf8("Btn_Confirm"));
        Btn_Confirm->setGeometry(QRect(210, 130, 81, 23));
        label_55 = new QLabel(tab_3);
        label_55->setObjectName(QString::fromUtf8("label_55"));
        label_55->setGeometry(QRect(119, 93, 91, 16));
        line_delN_cont = new QLineEdit(tab_3);
        line_delN_cont->setObjectName(QString::fromUtf8("line_delN_cont"));
        line_delN_cont->setGeometry(QRect(216, 93, 71, 21));
        label_56 = new QLabel(tab_3);
        label_56->setObjectName(QString::fromUtf8("label_56"));
        label_56->setGeometry(QRect(300, 93, 16, 16));
        tabWidget->addTab(tab_3, QString());
        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 260, 451, 81));
        groupBox_4->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 127);"));
        gridLayout = new QGridLayout(groupBox_4);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox_4);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        line_path = new QLineEdit(groupBox_4);
        line_path->setObjectName(QString::fromUtf8("line_path"));

        gridLayout->addWidget(line_path, 0, 1, 1, 1);

        Btn_GetDir = new QPushButton(groupBox_4);
        Btn_GetDir->setObjectName(QString::fromUtf8("Btn_GetDir"));

        gridLayout->addWidget(Btn_GetDir, 0, 2, 1, 1);

        progressBar_proc = new QProgressBar(groupBox_4);
        progressBar_proc->setObjectName(QString::fromUtf8("progressBar_proc"));
        progressBar_proc->setValue(24);

        gridLayout->addWidget(progressBar_proc, 1, 0, 1, 2);

        Btn_Proc = new QPushButton(groupBox_4);
        Btn_Proc->setObjectName(QString::fromUtf8("Btn_Proc"));

        gridLayout->addWidget(Btn_Proc, 1, 2, 1, 1);

        tabWidget_2 = new QTabWidget(groupBox);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(6, 349, 451, 231));
        tabWidget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 127);"));
        sd = new QWidget();
        sd->setObjectName(QString::fromUtf8("sd"));
        Btn_draw_auto = new QPushButton(sd);
        Btn_draw_auto->setObjectName(QString::fromUtf8("Btn_draw_auto"));
        Btn_draw_auto->setGeometry(QRect(320, 170, 91, 23));
        label_45 = new QLabel(sd);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setGeometry(QRect(37, 50, 39, 16));
        label_46 = new QLabel(sd);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setGeometry(QRect(37, 20, 65, 16));
        label_47 = new QLabel(sd);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setGeometry(QRect(37, 80, 105, 16));
        label_48 = new QLabel(sd);
        label_48->setObjectName(QString::fromUtf8("label_48"));
        label_48->setGeometry(QRect(37, 110, 104, 16));
        line_MeaV_2 = new QLineEdit(sd);
        line_MeaV_2->setObjectName(QString::fromUtf8("line_MeaV_2"));
        line_MeaV_2->setGeometry(QRect(160, 110, 91, 21));
        label_49 = new QLabel(sd);
        label_49->setObjectName(QString::fromUtf8("label_49"));
        label_49->setGeometry(QRect(37, 140, 117, 16));
        line_frame_2s = new QLineEdit(sd);
        line_frame_2s->setObjectName(QString::fromUtf8("line_frame_2s"));
        line_frame_2s->setGeometry(QRect(160, 50, 91, 21));
        line_batch_2s = new QLineEdit(sd);
        line_batch_2s->setObjectName(QString::fromUtf8("line_batch_2s"));
        line_batch_2s->setGeometry(QRect(160, 20, 91, 21));
        line_batch_2s->setStyleSheet(QString::fromUtf8(""));
        line_channel_2 = new QLineEdit(sd);
        line_channel_2->setObjectName(QString::fromUtf8("line_channel_2"));
        line_channel_2->setGeometry(QRect(160, 80, 91, 21));
        line_MerV_2 = new QLineEdit(sd);
        line_MerV_2->setObjectName(QString::fromUtf8("line_MerV_2"));
        line_MerV_2->setGeometry(QRect(160, 140, 91, 21));
        label_50 = new QLabel(sd);
        label_50->setObjectName(QString::fromUtf8("label_50"));
        label_50->setGeometry(QRect(280, 20, 16, 16));
        line_batch_2e = new QLineEdit(sd);
        line_batch_2e->setObjectName(QString::fromUtf8("line_batch_2e"));
        line_batch_2e->setGeometry(QRect(320, 20, 91, 21));
        line_batch_2e->setStyleSheet(QString::fromUtf8(""));
        label_51 = new QLabel(sd);
        label_51->setObjectName(QString::fromUtf8("label_51"));
        label_51->setGeometry(QRect(280, 50, 16, 16));
        line_frame_2e = new QLineEdit(sd);
        line_frame_2e->setObjectName(QString::fromUtf8("line_frame_2e"));
        line_frame_2e->setGeometry(QRect(320, 50, 91, 21));
        progressBar_play = new QProgressBar(sd);
        progressBar_play->setObjectName(QString::fromUtf8("progressBar_play"));
        progressBar_play->setGeometry(QRect(40, 170, 241, 23));
        progressBar_play->setValue(24);
        line_delt = new QLineEdit(sd);
        line_delt->setObjectName(QString::fromUtf8("line_delt"));
        line_delt->setGeometry(QRect(320, 140, 91, 21));
        label_52 = new QLabel(sd);
        label_52->setObjectName(QString::fromUtf8("label_52"));
        label_52->setGeometry(QRect(280, 140, 31, 16));
        label_53 = new QLabel(sd);
        label_53->setObjectName(QString::fromUtf8("label_53"));
        label_53->setGeometry(QRect(420, 140, 31, 16));
        tabWidget_2->addTab(sd, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        Btn_draw = new QPushButton(tab_5);
        Btn_draw->setObjectName(QString::fromUtf8("Btn_draw"));
        Btn_draw->setGeometry(QRect(240, 160, 91, 23));
        label_41 = new QLabel(tab_5);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setGeometry(QRect(117, 52, 39, 16));
        label_40 = new QLabel(tab_5);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setGeometry(QRect(117, 25, 65, 16));
        label_43 = new QLabel(tab_5);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setGeometry(QRect(117, 106, 104, 16));
        label_42 = new QLabel(tab_5);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setGeometry(QRect(117, 79, 105, 16));
        line_MeaV = new QLineEdit(tab_5);
        line_MeaV->setObjectName(QString::fromUtf8("line_MeaV"));
        line_MeaV->setGeometry(QRect(240, 106, 91, 21));
        label_44 = new QLabel(tab_5);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setGeometry(QRect(117, 133, 117, 16));
        line_frame = new QLineEdit(tab_5);
        line_frame->setObjectName(QString::fromUtf8("line_frame"));
        line_frame->setGeometry(QRect(240, 52, 91, 21));
        line_batch = new QLineEdit(tab_5);
        line_batch->setObjectName(QString::fromUtf8("line_batch"));
        line_batch->setGeometry(QRect(240, 25, 91, 21));
        line_batch->setStyleSheet(QString::fromUtf8(""));
        line_channel = new QLineEdit(tab_5);
        line_channel->setObjectName(QString::fromUtf8("line_channel"));
        line_channel->setGeometry(QRect(240, 79, 91, 21));
        line_MerV = new QLineEdit(tab_5);
        line_MerV->setObjectName(QString::fromUtf8("line_MerV"));
        line_MerV->setGeometry(QRect(240, 133, 91, 21));
        tabWidget_2->addTab(tab_5, QString());

        verticalLayout_2->addWidget(groupBox);

        verticalLayout_2->setStretch(0, 3);

        horizontalLayout->addLayout(verticalLayout_2);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 6);
        horizontalLayout->setStretch(2, 3);

        verticalLayout->addWidget(horizontalWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        groupBox_8 = new QGroupBox(verticalWidget);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setFont(font1);
        verticalLayoutWidget = new QWidget(groupBox_8);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 30, 451, 371));
        Layout_RD = new QVBoxLayout(verticalLayoutWidget);
        Layout_RD->setObjectName(QString::fromUtf8("Layout_RD"));
        Layout_RD->setContentsMargins(0, 0, 0, 0);

        horizontalLayout_5->addWidget(groupBox_8);


        horizontalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        groupBox_9 = new QGroupBox(verticalWidget);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        groupBox_9->setFont(font1);
        verticalLayoutWidget_2 = new QWidget(groupBox_9);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 30, 451, 371));
        Layout_Mea = new QVBoxLayout(verticalLayoutWidget_2);
        Layout_Mea->setObjectName(QString::fromUtf8("Layout_Mea"));
        Layout_Mea->setContentsMargins(0, 0, 0, 0);

        horizontalLayout_8->addWidget(groupBox_9);


        horizontalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        groupBox_10 = new QGroupBox(verticalWidget);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        groupBox_10->setFont(font1);
        verticalLayoutWidget_3 = new QWidget(groupBox_10);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 30, 451, 371));
        Layout_Mer = new QVBoxLayout(verticalLayoutWidget_3);
        Layout_Mer->setObjectName(QString::fromUtf8("Layout_Mer"));
        Layout_Mer->setContentsMargins(0, 0, 0, 0);

        horizontalLayout_7->addWidget(groupBox_10);


        horizontalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        groupBox_11 = new QGroupBox(verticalWidget);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        groupBox_11->setFont(font1);
        Layout_Music = new QWChartView(groupBox_11);
        Layout_Music->setObjectName(QString::fromUtf8("Layout_Music"));
        Layout_Music->setGeometry(QRect(0, 20, 471, 391));

        horizontalLayout_4->addWidget(groupBox_11);


        horizontalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(0, 3);
        verticalLayout->setStretch(1, 2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1920, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "\347\233\256\346\240\207\350\210\252\350\277\271", nullptr));
        groupBox_7->setTitle(QApplication::translate("MainWindow", " \346\227\245\345\277\227\350\276\223\345\207\272", nullptr));
        groupBox_12->setTitle(QApplication::translate("MainWindow", "\345\234\272\346\231\257\346\230\276\347\244\272", nullptr));
        Btn_Exit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        groupBox->setTitle(QString());
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "\351\207\207\346\240\267\347\216\207\357\274\232", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\350\265\267\345\247\213\350\275\275\351\242\221\357\274\232", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "\345\270\247\351\227\264\351\227\264\351\232\224\357\274\232", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\345\270\247\346\225\260\357\274\232", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "PRT\357\274\232", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\345\244\251\347\272\277\351\230\265\345\210\227\346\225\260\357\274\232", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\350\204\211\345\256\275\357\274\232", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\344\277\241\345\217\267\345\270\246\345\256\275\357\274\232", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\350\204\211\345\206\262\351\207\207\346\240\267\346\225\260\357\274\232", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\350\260\203\351\242\221\350\204\211\345\206\262\346\225\260\357\274\232", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "\345\270\247", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "\344\270\252", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "\344\270\252", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "\344\270\252", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "GHz", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "MHz", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "us", nullptr));
        label_20->setText(QApplication::translate("MainWindow", "us", nullptr));
        label_21->setText(QApplication::translate("MainWindow", "ksps", nullptr));
        label_22->setText(QApplication::translate("MainWindow", "ms", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\351\233\267\350\276\276\345\217\202\346\225\260", nullptr));
        label_27->setText(QApplication::translate("MainWindow", "\346\211\251\345\261\225\345\277\253\346\213\215\346\225\260\357\274\232", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "\347\247\257\347\264\257\345\270\247\346\225\260\357\274\232", nullptr));
        label_25->setText(QApplication::translate("MainWindow", "\346\243\200\346\265\213\351\227\250\351\231\220\357\274\232", nullptr));
        label_26->setText(QApplication::translate("MainWindow", "\345\271\262\346\211\260\345\210\240\351\231\244\350\267\235\347\246\273\357\274\232", nullptr));
        label_24->setText(QApplication::translate("MainWindow", "\347\212\266\346\200\201\350\275\254\347\247\273\347\251\272\351\227\264\357\274\232", nullptr));
        label_23->setText(QApplication::translate("MainWindow", "\350\241\245\345\205\205\345\210\207\345\220\221\351\200\237\345\272\246\357\274\232", nullptr));
        label_28->setText(QApplication::translate("MainWindow", "\345\217\226\345\270\247\351\227\264\351\232\224\357\274\232", nullptr));
        label_31->setText(QApplication::translate("MainWindow", "\345\270\247", nullptr));
        label_32->setText(QApplication::translate("MainWindow", "\344\270\252", nullptr));
        label_33->setText(QApplication::translate("MainWindow", "\344\270\252", nullptr));
        label_34->setText(QString());
        label_35->setText(QApplication::translate("MainWindow", "\344\270\252", nullptr));
        label_36->setText(QApplication::translate("MainWindow", "\344\270\252", nullptr));
        label_37->setText(QApplication::translate("MainWindow", "\345\270\247", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "TBD\345\217\202\346\225\260", nullptr));
        label_29->setText(QApplication::translate("MainWindow", "\350\204\211\345\206\262\345\257\271\346\266\210\346\225\260\357\274\232", nullptr));
        label_38->setText(QApplication::translate("MainWindow", "\344\270\252", nullptr));
        label_39->setText(QApplication::translate("MainWindow", "\344\270\252", nullptr));
        label_30->setText(QApplication::translate("MainWindow", " \350\247\222\345\272\246\347\273\264\346\225\260\357\274\232", nullptr));
        Btn_Confirm->setText(QApplication::translate("MainWindow", "\347\241\256\350\256\244\345\217\202\346\225\260", nullptr));
        label_55->setText(QApplication::translate("MainWindow", "\350\277\236\347\273\255\345\244\204\347\220\206\351\227\264\351\232\224\357\274\232", nullptr));
        label_56->setText(QApplication::translate("MainWindow", "\345\270\247", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", " \345\244\204\347\220\206\345\217\202\346\225\260", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\346\225\260\346\215\256\350\275\275\345\205\245", nullptr));
        label->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266\350\267\257\345\276\204\357\274\232", nullptr));
        Btn_GetDir->setText(QApplication::translate("MainWindow", "...", nullptr));
        Btn_Proc->setText(QApplication::translate("MainWindow", " \350\275\275\345\205\245\345\271\266\345\244\204\347\220\206", nullptr));
        Btn_draw_auto->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\347\273\230\345\210\266", nullptr));
        label_45->setText(QApplication::translate("MainWindow", "\345\270\247\345\272\217\357\274\232", nullptr));
        label_46->setText(QApplication::translate("MainWindow", "\345\244\204\347\220\206\346\211\271\346\254\241\357\274\232", nullptr));
        label_47->setText(QApplication::translate("MainWindow", "RD\350\260\261\345\244\251\347\272\277\351\200\232\351\201\223\345\217\267\357\274\232", nullptr));
        label_48->setText(QApplication::translate("MainWindow", "\351\207\217\346\265\213\345\271\263\351\235\242\351\200\237\345\272\246\345\217\267\357\274\232", nullptr));
        label_49->setText(QApplication::translate("MainWindow", "\345\200\274\345\207\275\346\225\260\345\271\263\351\235\242\351\200\237\345\272\246\345\217\267\357\274\232", nullptr));
        label_50->setText(QApplication::translate("MainWindow", "\345\210\260", nullptr));
        label_51->setText(QApplication::translate("MainWindow", "\345\210\260", nullptr));
        label_52->setText(QApplication::translate("MainWindow", "\346\227\266\345\273\266\357\274\232", nullptr));
        label_53->setText(QApplication::translate("MainWindow", "ms", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(sd), QApplication::translate("MainWindow", "\350\207\252\345\212\250\345\233\236\346\224\276", nullptr));
        Btn_draw->setText(QApplication::translate("MainWindow", " \346\211\213\345\212\250\347\273\230\345\210\266", nullptr));
        label_41->setText(QApplication::translate("MainWindow", "\345\270\247\345\272\217\357\274\232", nullptr));
        label_40->setText(QApplication::translate("MainWindow", "\345\244\204\347\220\206\346\211\271\346\254\241\357\274\232", nullptr));
        label_43->setText(QApplication::translate("MainWindow", "\351\207\217\346\265\213\345\271\263\351\235\242\351\200\237\345\272\246\345\217\267\357\274\232", nullptr));
        label_42->setText(QApplication::translate("MainWindow", "RD\350\260\261\345\244\251\347\272\277\351\200\232\351\201\223\345\217\267\357\274\232", nullptr));
        label_44->setText(QApplication::translate("MainWindow", "\345\200\274\345\207\275\346\225\260\345\271\263\351\235\242\351\200\237\345\272\246\345\217\267\357\274\232", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("MainWindow", "\346\211\213\345\212\250\345\233\236\346\224\276", nullptr));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "Range-Doppler\345\271\263\351\235\242", nullptr));
        groupBox_9->setTitle(QApplication::translate("MainWindow", "\351\207\217\346\265\213\345\271\263\351\235\242", nullptr));
        groupBox_10->setTitle(QApplication::translate("MainWindow", "\345\200\274\345\207\275\346\225\260\345\271\263\351\235\242", nullptr));
        groupBox_11->setTitle(QApplication::translate("MainWindow", "MUSIC\344\274\252\350\260\261", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
