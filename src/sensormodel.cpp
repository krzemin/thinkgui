#include "sensormodel.h"
#include "fileio.h"

void SensorModel::refresh() {
    curValue = FileIO::read(config.value).toInt() / 1000;
    curHighValue = FileIO::read(config.highValue).toInt() / 1000;
    curCritValue = FileIO::read(config.critValue).toInt() / 1000;
}

QString& SensorModel::name() {
    return config.name;
}

QString SensorModel::value() {
    QString f = config.format;
    return f.replace("%val", QString::number(curValue))
            .replace("%deg", QString(QChar(0xB0)));
}

QString SensorModel::highValue() {
    QString f = config.highFormat;
    return f.replace("%val", QString::number(curHighValue))
            .replace("%deg", QString(QChar(0xB0)));
}

QString SensorModel::critValue() {
    QString f = config.critFormat;
    return f.replace("%val", QString::number(curCritValue))
            .replace("%deg", QString(QChar(0xB0)));
}
