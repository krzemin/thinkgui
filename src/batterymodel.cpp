#include "batterymodel.h"
#include "fileio.h"

void BatteryModel::refresh() {
    curState = FileIO::read(batConfig.smapidir + "/state").toString().trimmed();
    remainingDischarge = FileIO::read(batConfig.smapidir + "/remaining_running_time")
            .toInt();
    remainingCharge = FileIO::read(batConfig.smapidir + "/remaining_charging_time")
            .toInt();
    remainingPercent = FileIO::read(batConfig.smapidir + "/remaining_percent")
            .toInt();
    stopChargeTresh = FileIO::read(batConfig.smapidir + "/stop_charge_thresh")
            .toInt();
}

QString& BatteryModel::name() {
    return batConfig.name;
}

QString BatteryModel::state() {
    return curState;
}

QString BatteryModel::formatTime(int minutes) {
    return QString("%1h %2m").arg(minutes/60).arg(minutes%60);
}

QString BatteryModel::getRemainingDischargeTime() {
    return formatTime(remainingDischarge);
}

QString BatteryModel::getRemainingChargeTime() {
    return formatTime(remainingCharge);
}

int BatteryModel::getRemainingPercent() {
    return remainingPercent;
}

int BatteryModel::getStopChargeTresh() {
    return stopChargeTresh;
}

void BatteryModel::setStopChargeTresh(int percent) {
    FileIO::write(batConfig.smapidir + "/stop_charge_thresh", percent);
}
