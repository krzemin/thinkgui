#ifndef CONFIG_H
#define CONFIG_H

#include<QVector>
#include<QSettings>
#include<QHash>
#include<QPair>

#include "cpuconfig.h"
#include "sensorconfig.h"
#include "batteryconfig.h"

class Config
{
    Config();

    int decodeGovernorFreq(const QString & string);

public:
    void load();

    int refresh;
    QVector<CpuConfig> cpus;
    QVector<SensorConfig> sensors;
    QVector<BatteryConfig> bats;
    QHash<QString, QPair<int, int> > governors;
    friend Config& GlobalConfig();

};

Config& GlobalConfig();



#endif // CONFIG_H
