#ifndef BATTERYMODEL_H
#define BATTERYMODEL_H

#include <QString>
#include "batteryconfig.h"

class BatteryModel
{
    BatteryConfig batConfig;

    QString curState;
    int remainingDischarge;
    int remainingCharge;
    int remainingPercent;
    int stopChargeTresh;

    QString formatTime(int minutes);

public:
    BatteryModel(const BatteryConfig & config) {
        this->batConfig = config;
    }

    void refresh();
    BatteryConfig& config() {
        return batConfig;
    }

    QString& name();
    QString state();
    QString getRemainingDischargeTime();
    QString getRemainingChargeTime();

    int getRemainingPercent();

    int getStopChargeTresh();
    void setStopChargeTresh(int percent);

};

#endif // BATTERYMODEL_H
