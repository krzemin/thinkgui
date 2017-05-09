#ifndef FANMODEL_H
#define FANMODEL_H

#include <QString>
#include "fanconfig.h"

class FanModel
{
    FanConfig config;
    int curValue;
    int curHighValue;

public:
    FanModel(const FanConfig & config) {
        this->config = config;
    }

    void refresh();

    QString& name();
    QString value();
    QString highValue();

};

#endif // FANMODEL_H
