#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "headSet.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public://公有属性

public://公有方法
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private://私有属性
    Ui::MainWindow *ui;
    QStandardItemModel *model;
    struct Radar_para radar;
    struct TBD_para TBD;
    struct ProcSetting ps;
    QByteArray arry;//存储着全部的数据，byte形式
    int delN_cont;//连续批处理5帧一间隔
    int size_frame;//4*128*256
    int size_all;//1000/10*4*128*256
    int size_frame_theta;//16*128*256
    int size_all_theta;//1000/10*16*128*256
    int size_batch_channel;//5*4*128*256
    int size_batch_theta;//5*16*128*256
    int size_track;//2*5+3
    float* Data_input;//函数输入数据//5*4*128*256*2
    float* Data_RD;//总RD平面//1000/10*4*128*256
    float* Data_RD_batch;//批RD平面//5*4*128*256
    float* Data_mea;//总量测空间//1000/10*128*16*256
    float* Data_mea_batch;//批量测空间//5*128*16*256
    float* Data_mer;//总值函数空间//1000/10*3*128*16*256
    float* Data_mer_batch;//批值函数空间//5*3*128*16*256
    float* Data_music;//总谱数据//1000*181
    int cnt_music;//总谱计数//1000*2
    float* Data_music_index;//总谱索引
    float* Data_music_batch;//批谱数据
    float* Data_music_batch_index;//批谱索引
    int flag = 0;//画图标志符号 0 只画背景  1 画背景和目标

    float* Tracks;//总航迹结果
    float* Tracks_index;
    int cnt_Tracks;//航迹计数
    float* Tracks_batch;//单批次航迹数据
    int cnt_batch_tracks;//单批次航迹计数

    QWidget         *graphContainer_1,*graphContainer_2,*graphContainer_3;
    Q3DSurface      *graph3D_1,*graph3D_2,*graph3D_3;//三维图表
    QSurface3DSeries    *series_1,*series_2,*series_3;//序列
    QSurfaceDataProxy   *proxy_1,*proxy_2,*proxy_3;//数据代理
    QChart *chart;
    QValueAxis *axisX;
    QValueAxis *axisY;
    QLineSeries *series_music;
    QSurfaceDataArray *dataArray_1;
    QSurfaceDataArray *dataArray_2;
    QSurfaceDataArray *dataArray_3;
    int draw_batch ;
    int draw_frame ;
    int draw_channel;
    int draw_MeaV ;
    int draw_MerV;
    int draw_batch_2s  ;
    int draw_batch_2e;
    int draw_frame_2s ;
    int draw_frame_2e;
    int draw_channel_2;
    int draw_MeaV_2 ;
    int draw_MerV_2;
    QTimer *timer;
    int draw_batch_cnt;
    int draw_frame_cnt;
    int cnt_play;

private://私有方法
    void InitialUI();//用于初始化显示界面，包括主显示界面和辅1~4显示界面
    void paintEvent(QPaintEvent *);
    void drawMainAreaBack();
    void getPara();//读取参数
    void getData();//读取bin文件
    void setDefaultValue();//设置默认值
    void process();//GPU函数处理
    void SaveRealDataMer(float* data, char*path, long size);
    void setInit3D();//3D绘图初始化
    void show3D();
    void showMusic();
    void plotTracks();

private slots:
    void on_Btn_Exit_clicked();
    void on_Btn_Proc_clicked();
    void on_Btn_GetDir_clicked();
    void on_Btn_Confirm_clicked();
    void on_Btn_draw_clicked();
    void on_Btn_draw_auto_clicked();
    void DrawAuto();
};
#endif // MAINWINDOW_H
