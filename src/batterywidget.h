#ifndef BATTERYWIDGET_H
#define BATTERYWIDGET_H

#include <QWidget>
#include "batterymodel.h"
#include "advancedbatterydialog.h"

namespace Ui {
class BatteryWidget;
}

class BatteryWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit BatteryWidget(QWidget *parent = 0);
    ~BatteryWidget();
    
    void setModel(BatteryModel * model) {
        batteryModel = model;
    }

    BatteryModel & model() {
        return *batteryModel;
    }

    void refresh();


public slots:
    void setStopChargeTresh(int percent);
    void showAdvancedInfo();

private:
    Ui::BatteryWidget *ui;
    BatteryModel *batteryModel;
};

#endif // BATTERYWIDGET_H
