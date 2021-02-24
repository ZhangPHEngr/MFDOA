//用于包含常用的头文件，不用再在每个cpp文件中重复添加
#ifndef HEADSET_H
#define HEADSET_H

#include <QApplication>
#include <QMainWindow>
#include <QTextCodec>
#include <qtextcodec.h>
#include <QDebug>//输出调试
#include <QScreen> //当前屏幕信息，用于自动适配屏幕大小
#include <QPainter>//绘图函数
#include <QPen>
#include <QFont>
#include <QtMath>
#include <QFile>
#include <QTimer>
#include <QFileDialog>
#include <QList>
#include <QStandardItem>
#include <QMessageBox>
#include <QButtonGroup>
#include <QString>
#include <QtDataVisualization>
#include <QtDataVisualization/Q3DSurface>
using namespace QtDataVisualization;
#include <QtCharts>  //必须这么设置
#include "qwchartview.h"
//自定义头文件
#include "para.h"
#include "MFDOAProcess.h"

#endif // HEADSET_H
