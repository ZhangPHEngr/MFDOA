#ifndef PARA_H
#define PARA_H

//雷达参数，共10个
struct Radar_para
{
    int N_frame;//总采集帧数
    int N_chirp;//chirp数
    int N_channel;//阵列天线数
    int N_sample;//chirp采样数
    double fc;//载频起始带宽
    double B;//发射信号的带宽
    double PRT;//脉冲重复周期,PRT
    double deltaT_pulse;//脉宽（存在占空比） 60 - 6(ADC采样时间)
    double fs;//采样频率
    double deltaT_frame;//帧间时间间隔

};
//TBD处理参数，共7个
struct TBD_para
{
    int N_frame;
    int N_vt;//补充的切向速度
    int N_Q;//状态转移空间
    double threshold;//检测门限
    int N_tracks = 1000000;//最大的可保存显示航迹数
    int distance;//干扰航迹删除距离
    int R_lr;//DOA估计时左右取快拍的距离
    int deltaN_frame;//取帧间隔数

};
//处理参数，共2个
struct ProcSetting
{
    int N_pulse;
    int N_theta;

};

#endif // PARA_H
