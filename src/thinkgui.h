#ifndef THINKGUI_H
#define THINKGUI_H

#include <QDialog>
#include <QVector>
#include <QTimer>

#include "cpuwidget.h"
#include "sensorwidget.h"
#include "fanwidget.h"
#include "batterywidget.h"

namespace Ui {
class ThinkGui;
}

class ThinkGui : public QDialog
{
    Q_OBJECT
    
public:
    explicit ThinkGui(QWidget *parent = 0, Qt::WindowFlags flags = 0);
    ~ThinkGui();

public slots:
    void refresh();
    
private slots:
    void conservativeClicked();
    void ondemandClicked();
    void performanceClicked();
    void powersaveClicked();
    void userspaceClicked();

private:
    Ui::ThinkGui *ui;
    QVector<CpuWidget*> cpu;
    QVector<SensorWidget*> sensor;
    QVector<FanWidget*> fan;
    QVector<BatteryWidget*> bat;
    QTimer *updateTimer;

    void initCpuWidgets();
    void initSensorWidgets();
    void initFanWidgets();
    void initBatteryWidgets();
    void setAllGovernors(const QString & governor);
};

#endif // THINKGUI_H
