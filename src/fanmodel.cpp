#include "fanmodel.h"
#include "fileio.h"

void FanModel::refresh() {
    curValue = FileIO::read(config.value).toInt() ;
    curHighValue = FileIO::read(config.highValue).toInt();
}

QString& FanModel::name() {
    return config.name;
}

QString FanModel::value() {
    QString f = config.format;
    return f.replace("%val", QString::number(curValue));
}

QString FanModel::highValue() {
    QString f = config.highFormat;
    return f.replace("%val", QString::number(curHighValue))
            .replace("%deg", QString(QChar(0xB0)));
}
