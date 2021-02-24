#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    InitialUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitialUI()
{
    ui->setupUi(this);
    //一定要先show再获取参数，不然未初始化好，参数会错误
    this->show();
    //设置界面背景颜色
    setPalette(QPalette(Qt::darkGray));
    //设置默认值
    setDefaultValue();
    //触发显示背景界面，主界面和辅助界面
    setInit3D();
    this->update();
    ui->Btn_Confirm->setStyleSheet("background: rgb(0,255,0)");//绿色提示操作
    ui->textBrowser->setText(QStringLiteral("初始化完成！"));
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(DrawAuto()));

}
//参数确认按键
void MainWindow::on_Btn_Confirm_clicked()
{
    ui->Btn_Confirm->setStyleSheet("background: rgb(225,225,225)");//原始按钮颜色
    getPara();//读取参数，三个结构体，并分配数据存储空间
    ui->Btn_GetDir->setStyleSheet("background: rgb(0,255,0)");//绿色提示操作
}
//选择待处理的文件
void MainWindow::on_Btn_GetDir_clicked()
{
    ui->Btn_GetDir->setStyleSheet("background: rgb(225,225,225)");
    QString s = QFileDialog::getOpenFileName(
                this, QStringLiteral("选择要处理的文件"),
                ".",
                QStringLiteral("DCA1000文件 (*.bin);;"));
    ui->line_path->setText(s);
    ui->textBrowser->append(ui->line_path->text());
    ui->Btn_Proc->setStyleSheet("background: rgb(0,255,0)");
}
//处理按键触发
void MainWindow::on_Btn_Proc_clicked()
{
    ui->Btn_Proc->setStyleSheet("background: rgb(0,255,0)");//绿色提示操作
    //读取全部原始数据
    getData();
    //启动数据处理,5帧一循环
    flag = 1;//开启绘图,1表示背景和航迹同时绘制
    process();

}
void MainWindow::process()
{
    ui->textBrowser->append(QStringLiteral("开始处理！"));
    //跳着处理
    cnt_Tracks = 0;//航迹计数置零
    cnt_music = 0;//伪谱数计数置零
    int cnt_batch = 0,frame_cur,N_batch = (radar.N_frame-(TBD.N_frame-1)*TBD.deltaN_frame)/delN_cont;
    // frame = 1  6 11 16 --- 946   951   956
    for (int frame = 1; frame<=radar.N_frame-(TBD.N_frame-1)*TBD.deltaN_frame; frame+=delN_cont) {//
        //*****************数据重组*************************//
        for (int index = 0; index<TBD.N_frame;index++) {//0 1 2 3 4
            frame_cur = frame+index*TBD.deltaN_frame;//1 11 21 31 41
            int index_0 = index*size_frame*2;
            int index_1 = (frame_cur-1)*size_frame*4;
            short res;
            for (size_t i = 0; i < size_frame*2; i++) {
                res = arry.at(index_1 + 2*i)&0x00FF;
                res |= arry.at(index_1 + 2*i+1)<<8&0xFF00;
                Data_input[index_0 + i] = (float)res;//<5,4,128,256,2>
            }
        }
        //*****************当前批次GPU处理***************//
        MFDOA(Tracks_batch, &cnt_batch_tracks, Data_music_batch, Data_RD_batch, Data_mea_batch, Data_mer_batch, Data_input, radar, TBD, ps);
        //qDebug()<<"point2";
        qDebug()<<QStringLiteral("当前第")+QString::number(frame)+QStringLiteral("帧开头，有")+QString::number(cnt_batch_tracks)+QStringLiteral("个目标！");
        //*****************中间缓存数据填充***************//
        memcpy(&Data_RD[cnt_batch*size_batch_channel],Data_RD_batch,size_batch_channel * sizeof (float));
        memcpy(&Data_mea[cnt_batch*size_batch_theta],Data_mea_batch,size_batch_theta * sizeof (float));
        memcpy(&Data_mer[cnt_batch*size_batch_theta],Data_mer_batch,size_batch_theta * sizeof (float));

        if(cnt_batch_tracks!=0){
            int index_2,index_3;
            for (size_t cnt_tracks_cur = 1;cnt_tracks_cur<=cnt_batch_tracks;cnt_tracks_cur++) {
                //填充航迹
                index_2 = cnt_Tracks*size_track;
                Tracks_index[cnt_Tracks] = cnt_batch+1;//批次编号
                memcpy(&Tracks[index_2],&Tracks_batch[(cnt_tracks_cur-1)*size_track],size_track*sizeof (float));
                for (size_t item = 0;item<size_track;item++) {
                    this->model->setItem(cnt_Tracks, item, new QStandardItem(QString::number(Tracks[index_2+item]) ) );
                    //model->setItem(cnt_Tracks, item, new QStandardItem(QString::number(10) ) );
                }
                //填充伪谱
                for(size_t f = 0; f<TBD.N_frame;f++){
                    index_3 = cnt_music*181;
                    memcpy(&Data_music[index_3],&Data_music_batch[(cnt_tracks_cur-1)*TBD.N_frame*181+f*181],181*sizeof (float));
                    cnt_music++;
                }
                cnt_Tracks++;
            }
        }
        cnt_batch_tracks = 0;//回归初值
        this->update();//显示刷新
        //界面显示
        cnt_batch++;
        ui->textBrowser->append(QStringLiteral("已完成第")+QString::number(cnt_batch)+QStringLiteral("批次！"));
        ui->progressBar_proc->setValue(cnt_batch*100/N_batch);
    }
    ui->textBrowser->append(QStringLiteral("处理完成！"));
    ui->Btn_Proc->setStyleSheet("background: rgb(225,225,225)");
}


//手动绘制按钮触发
void MainWindow::on_Btn_draw_clicked()
{
    draw_batch = ui->line_batch->text().toInt();
    draw_frame = ui->line_frame->text().toInt();
    draw_channel = ui->line_channel->text().toInt();
    draw_MeaV = ui->line_MeaV->text().toInt();
    draw_MerV = ui->line_MerV->text().toInt();

    show3D();
    showMusic();
}

//update()函数触发该刷新函数
void MainWindow::paintEvent(QPaintEvent *)
{
    if(flag == 0){
        drawMainAreaBack();
    }
    else if(flag == 1){
        drawMainAreaBack();
        plotTracks();
    }

}

//****************************************绘图函数****************************************//
void MainWindow::show3D()
{
    //Data_RD
    int x,z,index_0=0;
    float y;
    int index = (draw_batch-1)*size_batch_channel+ (draw_frame-1)*radar.N_channel*radar.N_chirp*radar.N_sample+(draw_channel-1)*radar.N_chirp*radar.N_sample;
    for (x =1 ; x <=radar.N_chirp; x++)//x
    {
        QSurfaceDataRow *newRow = new QSurfaceDataRow(radar.N_sample); //一行的数据
        index_0=0;
        for (z = 1; z <=radar.N_sample; z++)//z
        {
            y = Data_RD[index+(x-1)*radar.N_sample+z-1];
            (*newRow)[index_0++].setPosition(QVector3D(x, y, z));
        }
        *dataArray_1 << newRow;
    }
    proxy_1->resetArray(dataArray_1);


    //Data_mea
    index = (draw_batch-1)*size_batch_theta+(draw_frame-1)*radar.N_chirp*ps.N_theta*radar.N_sample+(draw_MeaV-1)*ps.N_theta*radar.N_sample;
    for (x =1 ; x <=radar.N_sample; x++)//x
    {
        QSurfaceDataRow *newRow = new QSurfaceDataRow(ps.N_theta); //一行的数据
        index_0=0;
        for (z = 1; z <=ps.N_theta; z++)//z
        {
            y = Data_mea[index+(z-1)*radar.N_sample+x-1];
            (*newRow)[index_0++].setPosition(QVector3D(x, y, z));
        }
        *dataArray_2 << newRow;
    }
    proxy_2->resetArray(dataArray_2);

    //Data_mer
    index = (draw_batch-1)*size_batch_theta+(draw_frame-1)*radar.N_chirp*ps.N_theta*radar.N_sample+(draw_MerV-1)*ps.N_theta*radar.N_sample;
    for (x =1 ; x <=radar.N_sample; x++)//x
    {
        QSurfaceDataRow *newRow = new QSurfaceDataRow(ps.N_theta); //一行的数据
        index_0=0;
        for (z = 1; z <=ps.N_theta; z++)//z
        {
            y = Data_mer[index+(z-1)*radar.N_sample+x-1];
            (*newRow)[index_0++].setPosition(QVector3D(x, y, z));
        }
        *dataArray_3 << newRow;
    }
    proxy_3->resetArray(dataArray_3);

}

//指定绘制Data_music中的MUSIC伪谱
void MainWindow::showMusic()
{
    chart->removeSeries(series_music);
    series_music = new QLineSeries();
    chart->addSeries(series_music); //序列添加到图表
    float max_value = 0.0f;
    for (int i = 0; i<cnt_Tracks;i++) {
        if(Tracks_index[i]==draw_batch){
            int index = i*TBD.N_frame;
            //qDebug()<<QString::number(index);
            for(int theta=-90;theta<=90;theta++)
            {
                float da = Data_music[(index+draw_frame-1)*181+theta+91];
                series_music->append(theta,da);//
                if(da>max_value){
                    max_value = da;
                }
            }
        }
    }

    axisY->setRange(0, max_value+0.5);
    chart->setAxisX(axisX, series_music); //为序列设置坐标轴
    chart->setAxisY(axisY, series_music); //
}

//******************初始化主界面*******************//
void MainWindow::drawMainAreaBack()
{
    QPainter painter(this);
    //painter设置,创建QPainter对象
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);
    //设置画笔
    QPen pen;
    pen.setWidth(2); //线宽
    pen.setColor(Qt::darkGreen); //划线颜色
    pen.setStyle(Qt::SolidLine); //线的样式：实线
    painter.setPen(pen);

    //设置文字属性
    QFont font;
    font.setPointSize(12); //设置大小为12像素
    font.setBold(true);  //设置为粗体
    painter.setFont(font);

    //设置画刷
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    painter.setBrush(brush);
    //屏幕参数计算
    int central_X = 960;
    int central_Y = 580;
    int R = 500;
    //******************绘制背景圆*******************//
    QRect rect_back(0,0,0,0);
    int index_rect = 0;
    //100像素对应10米
    for (int width = R*2; width>=200 ; width-=200) {
        rect_back.setLeft((1920-width)/2);
        rect_back.setTop(80+100*(index_rect++));
        rect_back.setWidth(width);
        rect_back.setHeight(width);
        painter.drawPie(rect_back,30*16,120*16);
    }
    //******************绘制参考边*******************//
    pen.setStyle(Qt::DotLine); //线的样式：虚线
    painter.setPen(pen);
    double t;
    QString txt_angle;
    QRect rect_angle(0,0,0,0);
    for (int theta = -50 ; theta <= 60 ; theta+=10 ) {
        t = (double)(90-theta)/180*M_PI;
        painter.drawLine(central_X,central_Y,central_X+R*cos(t),central_Y-R*sin(t));
        //******************绘制角度标*******************//
        float left = central_X+R*cos(t);
        float right = central_Y-R*sin(t);
        if(theta>0){
            left -= theta/3.0;
            right -= theta/8.0;
        }//矫正位置
        rect_angle.setLeft(left);
        rect_angle.setTop(right);
        rect_angle.setWidth(50);
        rect_angle.setHeight(30);
        txt_angle = QString::number(theta,10);
        painter.drawText(rect_angle, txt_angle);

    }
    //******************绘制距离标*******************//
    QString txt_range;
    QRect rect_range(0,0,0,0);
    double coe_c = cos(150.0/180.0*M_PI);
    double coe_s = sin(150.0/180.0*M_PI);
    for (int r = 100 ; r<=R ; r+=100) {
        rect_range.setLeft(central_X+coe_c*r-20);
        rect_range.setTop(central_Y-coe_s*r-10);
        rect_range.setWidth(50);
        rect_range.setHeight(30);
        txt_range = QString::number(r/10,10)+"m";
        painter.drawText(rect_range, txt_range);
    }


}
void MainWindow::plotTracks()
{

    QPainter painter2(this);
    //painter设置,创建QPainter对象
    painter2.setRenderHint(QPainter::Antialiasing);
    painter2.setRenderHint(QPainter::TextAntialiasing);
    //设置画笔
    QPen pen;
    pen.setWidth(2); //线宽
    pen.setColor(Qt::red); //划线颜色
    pen.setStyle(Qt::SolidLine); //线的样式：实线
    painter2.setPen(pen);

    int central_X = 960;
    int central_Y = 580;
    int index;
    for (int cnt_tracks = 1; cnt_tracks <= cnt_Tracks; cnt_tracks++) {
        index = (cnt_tracks-1)*size_track;
        for (size_t frame = 0; frame<TBD.N_frame-1; frame++) {//0 1 2 3
            float theta_s = Tracks[index+frame*2];
            float r_s = Tracks[index+frame*2+1]*10;
            float theta_e = Tracks[index+frame*2+2];
            float r_e = Tracks[index+frame*2+3]*10;
            float x_s = central_X+r_s*cos((90-theta_s)/180.0*M_PI);
            float y_s = central_Y-r_s*sin((90-theta_s)/180.0*M_PI);
            float x_e = central_X+r_e*cos((90-theta_e)/180.0*M_PI);
            float y_e = central_Y-r_e*sin((90-theta_e)/180.0*M_PI);
            QLine line(x_s,y_s,x_e,y_e);
            painter2.drawLine(line);
            //ui->textBrowser->setText(QStringLiteral("完成"));
        }
    }



}

//****************************************3D绘图****************************************//
void MainWindow::setInit3D(){

    //读取雷达参数
    radar.N_chirp = ui->line_N_chirp->text().toInt();
    radar.N_channel = ui->line_N_channel->text().toInt();
    radar.N_sample = ui->line_N_sample->text().toInt();
    //读取处理参数
    ps.N_theta = ui->line_N_theta->text().toInt();


    QLinearGradient grGtoR;
    grGtoR.setColorAt(1.0, Qt::darkGreen);
    grGtoR.setColorAt(0.5, Qt::yellow);
    grGtoR.setColorAt(0.2, Qt::red);
    grGtoR.setColorAt(0.0, Qt::darkRed);
    //********************第一窗口******************//
    graph3D_1 = new Q3DSurface();
    graphContainer_1 = QWidget::createWindowContainer(graph3D_1);
    //创建坐标轴 (X,Z,Y)
    QValue3DAxis *axisX_1=new QValue3DAxis;
    axisX_1->setTitle("Axis X");
    axisX_1->setTitleVisible(true);
    //axisX_1->setAutoAdjustRange(true);
    axisX_1->setRange(0,radar.N_chirp);
    graph3D_1->setAxisX(axisX_1);

    QValue3DAxis *axisZ_1=new QValue3DAxis;
    axisZ_1->setTitle("Axis Z");
    axisZ_1->setTitleVisible(true);
    axisZ_1->setRange(0,radar.N_sample);
    //axisZ_1->setAutoAdjustRange(true);
    graph3D_1->setAxisZ(axisZ_1);

    QValue3DAxis *axisY_1=new QValue3DAxis;
    axisY_1->setTitle("Axis Y");
    axisY_1->setTitleVisible(true);
    //axisY_1->setRange(-10,10);
    axisY_1->setAutoAdjustRange(true);
    graph3D_1->setAxisY(axisY_1);
    //设置视角
    graph3D_1->scene()->activeCamera()->setCameraPosition(50,10,130);
    //创建数据代理
    proxy_1 = new QSurfaceDataProxy();
    series_1 = new QSurface3DSeries(proxy_1);
    series_1->setItemLabelFormat("(@xLabel @yLabel @zLabel)");
    series_1->setMeshSmooth(true);
    graph3D_1->activeTheme()->setLabelBackgroundEnabled(false);

    series_1->setDrawMode(QSurface3DSeries::DrawSurfaceAndWireframe);
    graph3D_1->addSeries(series_1);

    series_1->setBaseGradient(grGtoR);
    series_1->setColorStyle(Q3DTheme::ColorStyleRangeGradient);

    dataArray_1 = new QSurfaceDataArray; //数组
    dataArray_1->reserve(radar.N_chirp);//256

    int x=1,z=1;
    for (x =1 ; x <=radar.N_chirp; x++)//x
    {
        QSurfaceDataRow *newRow = new QSurfaceDataRow(radar.N_sample); //一行的数据
        int index=0;
        z = 1;
        for (z = 1; z <=radar.N_sample; z++)//z
        {
            (*newRow)[index++].setPosition(QVector3D(x, 0, z));
            z+=1;
        }
        x+=1;
        *dataArray_1 << newRow;

    }

    proxy_1->resetArray(dataArray_1);
    ui->Layout_RD->addWidget(graphContainer_1);
    graphContainer_1->show();

    //********************第二窗口******************//

    graph3D_2 = new QtDataVisualization::Q3DSurface();
    graphContainer_2 = QWidget::createWindowContainer(graph3D_2);
    //创建坐标轴
    QValue3DAxis *axisX_2=new QValue3DAxis;
    axisX_2->setTitle("Axis X");
    axisX_2->setTitleVisible(true);
    axisX_2->setRange(0,radar.N_sample);
    graph3D_2->setAxisX(axisX_2);

    QValue3DAxis *axisZ_2=new QValue3DAxis;
    axisZ_2->setTitle("Axis Z");
    axisZ_2->setTitleVisible(true);
    axisZ_2->setRange(0,ps.N_theta);
    graph3D_2->setAxisZ(axisZ_2);

    QValue3DAxis *axisY_2=new QValue3DAxis;
    axisY_2->setTitle("Axis Y");
    axisY_2->setTitleVisible(true);
    axisY_2->setAutoAdjustRange(true);
    graph3D_2->setAxisY(axisY_2);
    //设置视角
    graph3D_2->scene()->activeCamera()->setCameraPosition(70,10,150);
    //创建数据代理
    proxy_2 = new QSurfaceDataProxy();
    series_2 = new QSurface3DSeries(proxy_2);
    series_2->setItemLabelFormat("(@xLabel @yLabel @zLabel)");
    series_2->setMeshSmooth(true);
    graph3D_2->activeTheme()->setLabelBackgroundEnabled(false);

    series_2->setDrawMode(QSurface3DSeries::DrawSurfaceAndWireframe);
    graph3D_2->addSeries(series_2);
    series_2->setBaseGradient(grGtoR);
    series_2->setColorStyle(Q3DTheme::ColorStyleRangeGradient);

    dataArray_2 = new QSurfaceDataArray; //数组
    dataArray_2->reserve(radar.N_sample);//

    for (x =1 ; x <=radar.N_sample; x++)//x
    {
        QSurfaceDataRow *newRow = new QSurfaceDataRow(ps.N_theta); //一行的数据
        int index=0;
        for (z = 1; z <=ps.N_theta; z++)//y
        {
            (*newRow)[index++].setPosition(QVector3D(x, 0, z));
        }
        *dataArray_2 << newRow;
    }

    proxy_2->resetArray(dataArray_2);
    ui->Layout_Mea->addWidget(graphContainer_2);

    //********************第三窗口******************//
    graph3D_3 = new QtDataVisualization::Q3DSurface();
    graphContainer_3 = QWidget::createWindowContainer(graph3D_3);
    //创建坐标轴
    QValue3DAxis *axisX_3=new QValue3DAxis;
    axisX_3->setTitle("Axis X");
    axisX_3->setTitleVisible(true);
    axisX_3->setRange(0,radar.N_sample);
    graph3D_3->setAxisX(axisX_3);

    QValue3DAxis *axisZ_3=new QValue3DAxis;
    axisZ_3->setTitle("Axis Z");
    axisZ_3->setTitleVisible(true);
    axisZ_3->setRange(0,ps.N_theta);
    graph3D_3->setAxisZ(axisZ_3);

    QValue3DAxis *axisY_3=new QValue3DAxis;
    axisY_3->setTitle("Axis Y");
    axisY_3->setTitleVisible(true);
    axisY_3->setAutoAdjustRange(true);
    graph3D_3->setAxisY(axisY_3);
    //设置视角
    graph3D_3->scene()->activeCamera()->setCameraPosition(70,10,150);
    //创建数据代理
    proxy_3 = new QSurfaceDataProxy();
    series_3 = new QSurface3DSeries(proxy_3);
    series_3->setItemLabelFormat("(@xLabel @yLabel @zLabel)");
    series_3->setMeshSmooth(true);
    graph3D_3->activeTheme()->setLabelBackgroundEnabled(false);

    series_3->setDrawMode(QSurface3DSeries::DrawSurfaceAndWireframe);
    graph3D_3->addSeries(series_3);
    series_3->setBaseGradient(grGtoR);
    series_3->setColorStyle(Q3DTheme::ColorStyleRangeGradient);

    dataArray_3 = new QSurfaceDataArray; //数组
    dataArray_3->reserve(radar.N_sample);//256

    for (x =1 ; x <=radar.N_sample; x++)//x
    {
        QSurfaceDataRow *newRow = new QSurfaceDataRow(ps.N_theta); //一行的数据
        int index=0;
        for (z = 1; z <=ps.N_theta; z++)//y
        {
            (*newRow)[index++].setPosition(QVector3D(x, 0, z));
        }
        *dataArray_3 << newRow;
    }

    proxy_3->resetArray(dataArray_3);
    ui->Layout_Mer->addWidget(graphContainer_3);
    //统一设置主题
    Q3DTheme *currentTheme_1 = graph3D_1->activeTheme();
    currentTheme_1->setType(Q3DTheme::Theme(7));
    Q3DTheme *currentTheme_2 = graph3D_2->activeTheme();
    currentTheme_2->setType(Q3DTheme::Theme(7));
    Q3DTheme *currentTheme_3 = graph3D_3->activeTheme();
    currentTheme_3->setType(Q3DTheme::Theme(7));

    //********************第四窗口******************//
    QChartView *chartView=new QChartView(this); //创建 ChartView
    chart = new QChart(); //创建 Chart
    chart->setTheme(QChart::ChartThemeDark);
    chart->setTitle("Pseudo Spectrum of MUSIC");
    chartView->setChart(chart); //Chart添加到ChartView
    ui->Layout_Music->setChart(chart);
    axisX = new QValueAxis; //X 轴
    axisX->setRange(-90, 90); //设置坐标轴范围
    axisX->setTitleText("Degree"); //标题
    axisY = new QValueAxis; //Y 轴
    axisY->setRange(0, 3);
    axisY->setTitleText("Value");

    series_music = new QLineSeries();
    chart->addSeries(series_music); //序列添加到图表
    for(int i=-90;i<=90;i++)
    {
        series_music->append(i,0);
    }
    chart->setAxisX(axisX, series_music); //为序列设置坐标轴
    chart->setAxisY(axisY, series_music); //

}



void MainWindow::setDefaultValue()
{
    ui->line_N_Frame->setText("1000");
    ui->line_N_chirp->setText("128");
    ui->line_N_channel->setText("4");
    ui->line_N_sample->setText("256");
    ui->line_fc->setText("76");
    ui->line_B->setText("599.64");
    ui->line_PRT->setText("160");
    ui->line_delT_pulse->setText("54");
    ui->line_fs->setText("5000");
    ui->line_delT_frame->setText("40");
    ui->line_N_K->setText("5");
    ui->line_N_vt->setText("1");
    ui->line_N_Q->setText("3");
    ui->line_threshold->setText("86582");
    ui->line_distance->setText("3");
    ui->line_R_lr->setText("1");
    ui->line_delN_frame->setText("10");
    ui->line_N_pulse->setText("2");
    ui->line_N_theta->setText("16");
    ui->line_delN_cont->setText("5");
    //初始化设置数据回放
    ui->line_batch->setText("1");
    ui->line_frame->setText("1");
    ui->line_channel->setText("1");
    ui->line_MeaV->setText("10");
    ui->line_MerV->setText("10");
    ui->line_batch_2s->setText("1");
    ui->line_batch_2e->setText("10");
    ui->line_frame_2s->setText("1");
    ui->line_frame_2e->setText("5");
    ui->line_channel_2->setText("1");
    ui->line_MeaV_2->setText("10");
    ui->line_MerV_2->setText("10");
    ui->line_delt->setText("200");
    //初始化设置tableView
    this->model = new QStandardItemModel;   //创建一个标准的条目模型
    this->ui->tableView->setModel(model);   //将tableview设置成model这个标准条目模型的模板, model设置的内容都将显示在tableview上
    ui->tableView->setStyleSheet("QHeaderView::section{background:black}");
    ui->tableView->setStyleSheet("QScrollBar:vertical{"
                                       "background:#000000;"
                                       "padding-top:20px;"               //上预留位置（放置向上箭头）
                                       "padding-bottom:20px;"            //下预留位置（放置向下箭头）
                                       "border:1px solid #d7d7d7;}"
                                       "QScrollBar::handle:vertical{"    //垂直滚动条区域样式
                                                            "background:#000000;}"
                                       "QScrollBar::add-line:vertical{"
                                                            "background:#000000 ;"
                                       "border:1px solid #d7d7d7;}"
                                       "QScrollBar::sub-line:vertical{"
                                                            "background:#000000;"
                                       "border:1px solid #d7d7d7;}"
                                       "QScrollBar::up-arrow:vertical{"
                                       "border: 1px solid white;	width: 14px;	height: 14px;"
                                       "image:url(:/TabWidgt/Icon/up.jpg);}"
                                       "QScrollBar::down-arrow:vertical{"
                                       "border: 1px solid white;width: 14px;height: 14px;"
                                       "image:url(:/TabWidgt/Icon/down.jpg);}"
                                       "QTableView::item{border:1px dashed green;}"
                                       );
    ui->tableView->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(0,0,0);"
                                                           "border:1px solid white;"
                                                           "font:10pt '宋体';"
                                                           "color:rgb(0,255,0);};");
    //ui->tableView->verticalHeader()->hide();
    //ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(0,0,0);"
                                                         "font:10pt '宋体';"
                                                         "color:rgb(0,255,0);};");

    this->model->setHorizontalHeaderItem(0, new QStandardItem(QStringLiteral("θ1")) );
    this->model->setHorizontalHeaderItem(1, new QStandardItem(QStringLiteral("r1")));
    this->model->setHorizontalHeaderItem(2, new QStandardItem(QStringLiteral("θ2")));
    this->model->setHorizontalHeaderItem(3, new QStandardItem(QStringLiteral("r2")));
    this->model->setHorizontalHeaderItem(4, new QStandardItem(QStringLiteral("θ3")));
    this->model->setHorizontalHeaderItem(5, new QStandardItem(QStringLiteral("r3")));
    this->model->setHorizontalHeaderItem(6, new QStandardItem(QStringLiteral("θ4")));
    this->model->setHorizontalHeaderItem(7, new QStandardItem(QStringLiteral("r4")));
    this->model->setHorizontalHeaderItem(8, new QStandardItem(QStringLiteral("θ5")));
    this->model->setHorizontalHeaderItem(9, new QStandardItem(QStringLiteral("r5")));
    this->model->setHorizontalHeaderItem(10, new QStandardItem(QStringLiteral("vθ")));
    this->model->setHorizontalHeaderItem(11, new QStandardItem(QStringLiteral("vr")));
    this->model->setHorizontalHeaderItem(12, new QStandardItem(QStringLiteral("Amp")));

    this->ui->tableView->setColumnWidth(0, 30);    //设置列的宽度
    this->ui->tableView->setColumnWidth(1, 60);
    this->ui->tableView->setColumnWidth(2, 30);
    this->ui->tableView->setColumnWidth(3, 60);
    this->ui->tableView->setColumnWidth(4, 30);
    this->ui->tableView->setColumnWidth(5, 60);
    this->ui->tableView->setColumnWidth(6, 30);
    this->ui->tableView->setColumnWidth(7, 60);
    this->ui->tableView->setColumnWidth(8, 30);
    this->ui->tableView->setColumnWidth(9, 60);
    this->ui->tableView->setColumnWidth(10, 30);
    this->ui->tableView->setColumnWidth(11, 30);
    this->ui->tableView->setColumnWidth(12, 100);
//    /*setItem设置条目栏中的一个格子的信息*/
   //this->model->setItem(2, 5, new QStandardItem("20" ) );

}
void MainWindow::getPara(){
    //读取雷达参数
    radar.N_frame = ui->line_N_Frame->text().toInt();
    radar.N_chirp = ui->line_N_chirp->text().toInt();
    radar.N_channel = ui->line_N_channel->text().toInt();
    radar.N_sample = ui->line_N_sample->text().toInt();
    radar.fc = ui->line_fc->text().toDouble()*1e9;
    radar.B  = ui->line_B->text().toDouble()*1e6;
    radar.PRT = ui->line_PRT->text().toDouble()*1e-6;
    radar.deltaT_pulse = ui->line_delT_pulse->text().toDouble()*1e-6;
    radar.fs = ui->line_fs->text().toDouble()*1e3;
    radar.deltaT_frame = ui->line_delT_frame->text().toDouble()*1e-3;
    //读取TBD参数
    TBD.N_frame = ui->line_N_K->text().toInt();
    TBD.N_vt = ui->line_N_vt->text().toInt();
    TBD.N_Q = ui->line_N_Q->text().toInt();
    TBD.threshold = ui->line_threshold->text().toDouble();
    TBD.distance = ui->line_distance->text().toInt();
    TBD.R_lr = ui->line_R_lr->text().toInt();
    TBD.deltaN_frame = ui->line_delN_frame->text().toInt();
    //读取处理参数
    ps.N_pulse = ui->line_N_pulse->text().toInt();
    ps.N_theta = ui->line_N_theta->text().toInt();
    delN_cont = ui->line_delN_cont->text().toInt();
    ui->textBrowser->append(QStringLiteral("参数读取完成！"));

    //空间分配
    size_frame = radar.N_channel*radar.N_chirp*radar.N_sample;//4*128*256
    size_all = radar.N_frame/delN_cont*TBD.N_frame*size_frame;//1000/5  *  5*4*128*256
    size_frame_theta = ps.N_theta*radar.N_chirp*radar.N_sample;//16*128*256
    size_all_theta = radar.N_frame/delN_cont*TBD.N_frame*size_frame_theta;//1000/5  *5*16*128*256
    size_batch_channel = TBD.N_frame*size_frame;//5*4*128*256
    size_batch_theta = TBD.N_frame*size_frame_theta; //5*16*128*256
    size_track = 2*TBD.N_frame+3;
    //输入数据
    Data_input = (float*)malloc( size_batch_channel*2 * sizeof(float));//5*4*128*256*2
    //输出数据
    Data_RD = (float*)malloc(size_all * sizeof (float));//1000/5  *  5*4*128*256
    Data_RD_batch = (float*)malloc(size_batch_channel * sizeof (float));//5*4*128*256
    Data_mea = (float*)malloc(size_all_theta * sizeof (float));//1000/5  *5*16*128*256
    Data_mea_batch = (float*)malloc(size_batch_theta * sizeof (float));//5*128*16*256
    Data_mer = (float*)malloc(TBD.N_vt*size_all_theta * sizeof (float));//1000/5  *5*16*128*256
    Data_mer_batch = (float*)malloc(TBD.N_vt*size_batch_theta * sizeof (float));//5*3*128*16*256

    cnt_music = 0;
    Data_music = (float*)malloc(2000*181*sizeof (float));//2000*[批次编号 帧标号 伪谱数据]
    Data_music_batch = (float*)malloc(200*181*sizeof (float));//200*181

    Tracks = (float*)malloc(1000*size_track*sizeof (float));//[航迹数据]
    Tracks_index = (float*)malloc(1000*sizeof (float));//帧标号
    Tracks_batch = (float*)malloc(1000*size_track*sizeof (float));

    ui->textBrowser->append(QStringLiteral("空间分配完成！"));
}
void MainWindow::on_Btn_Exit_clicked()
{
    QApplication::exit();
}

void MainWindow::getData(){
    //读取文件
    QFile file(ui->line_path->text());
    //QFile file(QStringLiteral("G://1.bin"));
    if(!file.open(QIODevice::ReadOnly))
        ui->textBrowser->append(QStringLiteral("数据读入失败！"));
    arry = file.readAll();
    file.close();
    ui->textBrowser->append(QStringLiteral("已完成数据读入"));
}


void MainWindow::on_Btn_draw_auto_clicked()
{
    draw_batch_2s = ui->line_batch_2s->text().toInt() ;
    draw_batch_2e = ui->line_batch_2e->text().toInt() ;
    draw_frame_2s = ui->line_frame_2s->text().toInt() ;
    draw_frame_2e = ui->line_frame_2e->text().toInt() ;
    draw_channel_2 = ui->line_channel_2->text().toInt() ;
    draw_MeaV_2 = ui->line_MeaV_2->text().toInt() ;
    draw_MerV_2 = ui->line_MerV_2->text().toInt() ;

    draw_batch_cnt = draw_batch_2s;
    draw_frame_cnt = draw_frame_2s;
    cnt_play = 0;

    timer->start();
    timer->setInterval(ui->line_delt->text().toInt());    //设置定时周期//创建定时器

}
void MainWindow::DrawAuto()
{

    if(draw_frame_cnt > draw_frame_2e){
        draw_frame_cnt = draw_frame_2s;
        draw_batch_cnt++;

    }
    if(draw_batch_cnt > draw_batch_2e){
        timer->stop();
        return;
    }
    ui->progressBar_play->setValue((cnt_play++)*100/((draw_frame_2e-draw_frame_2s+1)*(draw_batch_2e-draw_batch_2s+1)));
    //Data_RD
    int x,z,index_0=0;
    float y;
    int index = (draw_batch_cnt-1)*size_batch_channel+ (draw_frame_cnt-1)*radar.N_channel*radar.N_chirp*radar.N_sample+(draw_channel_2-1)*radar.N_chirp*radar.N_sample;
    for (x =1 ; x <=radar.N_chirp; x++)//x
    {
        QSurfaceDataRow *newRow = new QSurfaceDataRow(radar.N_sample); //一行的数据
        index_0=0;
        for (z = 1; z <=radar.N_sample; z++)//z
        {
            y = Data_RD[index+(x-1)*radar.N_sample+z-1];
            (*newRow)[index_0++].setPosition(QVector3D(x, y, z));
        }
        *dataArray_1 << newRow;
    }
    proxy_1->resetArray(dataArray_1);


    //Data_mea
    index = (draw_batch_cnt-1)*size_batch_theta+(draw_frame_cnt-1)*radar.N_chirp*ps.N_theta*radar.N_sample+(draw_MeaV_2-1)*ps.N_theta*radar.N_sample;
    for (x =1 ; x <=radar.N_sample; x++)//x
    {
        QSurfaceDataRow *newRow = new QSurfaceDataRow(ps.N_theta); //一行的数据
        index_0=0;
        for (z = 1; z <=ps.N_theta; z++)//z
        {
            y = Data_mea[index+(z-1)*radar.N_sample+x-1];
            (*newRow)[index_0++].setPosition(QVector3D(x, y, z));
        }
        *dataArray_2 << newRow;
    }
    proxy_2->resetArray(dataArray_2);

    //Data_mer
    index = (draw_batch_cnt-1)*size_batch_theta+(draw_frame_cnt-1)*radar.N_chirp*ps.N_theta*radar.N_sample+(draw_MerV_2-1)*ps.N_theta*radar.N_sample;
    for (x =1 ; x <=radar.N_sample; x++)//x
    {
        QSurfaceDataRow *newRow = new QSurfaceDataRow(ps.N_theta); //一行的数据
        index_0=0;
        for (z = 1; z <=ps.N_theta; z++)//z
        {
            y = Data_mer[index+(z-1)*radar.N_sample+x-1];
            (*newRow)[index_0++].setPosition(QVector3D(x, y, z));
        }
        *dataArray_3 << newRow;
    }
    proxy_3->resetArray(dataArray_3);

    chart->removeSeries(series_music);
    series_music = new QLineSeries();
    chart->addSeries(series_music); //序列添加到图表
    float max_value = 0.0f;
    for (int i = 0; i<cnt_Tracks;i++) {
        if(Tracks_index[i]==draw_batch_cnt){
            int index = i*TBD.N_frame;
            //qDebug()<<QString::number(index);
            for(int theta=-90;theta<=90;theta++)
            {
                float da = Data_music[(index+draw_frame_cnt-1)*181+theta+91];
                series_music->append(theta,da);//
                if(da>max_value){
                    max_value = da;
                }
            }
        }
    }
    axisY->setRange(0, max_value+0.5);
    chart->setAxisX(axisX, series_music); //为序列设置坐标轴
    chart->setAxisY(axisY, series_music); //

    draw_frame_cnt++;
}
