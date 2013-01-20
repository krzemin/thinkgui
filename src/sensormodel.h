#ifndef SENSORMODEL_H
#define SENSORMODEL_H

#include <QString>
#include "sensorconfig.h"

class SensorModel
{
    SensorConfig config;
    int curValue;
    int curHighValue;
    int curCritValue;

public:
    SensorModel(const SensorConfig & config) {
        this->config = config;
    }

    void refresh();

    QString& name();
    QString value();
    QString highValue();
    QString critValue();

};

#endif // SENSORMODEL_H
