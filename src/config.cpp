#include "config.h"
#include <QTextStream>
#include <QStringList>

Config::Config()
{
    load();
}

void Config::load() {
    QSettings settings(QSettings::IniFormat, QSettings::UserScope, "thinkgui");
    settings.sync();

    refresh = settings.value("refresh", 1000).toInt();

    int cpus = settings.value("cpus", 0).toInt();

    for(int i = 0; i < cpus; ++i) {
        QString section;
        QTextStream ts(&section);
        ts << "cpu" << i;

        settings.beginGroup(section);
        CpuConfig cpu;
        cpu.name = settings.value("name", section).toString();
        cpu.sysdir = settings.value("sysdir").toString();
        this->cpus.append(cpu);
        settings.endGroup();
    }

    int sensors = settings.value("sensors", 0).toInt();
    for(int i = 0; i < sensors; ++i) {
        QString section;
        QTextStream ts(&section);
        ts << "sensor" << i;

        settings.beginGroup(section);
        SensorConfig sensor;
        sensor.name = settings.value("name", section).toString();
        sensor.format = settings.value("format").toString();
        sensor.value = settings.value("value").toString();
        sensor.highFormat = settings.value("high_format").toString();
        sensor.highValue = settings.value("high_value").toString();
        sensor.critFormat = settings.value("crit_format").toString();
        sensor.critValue = settings.value("crit_value").toString();
        this->sensors.append(sensor);
        settings.endGroup();
    }

    int batteries = settings.value("batteries", 0).toInt();
    for(int i = 0; i < batteries; ++i) {
        QString section;
        QTextStream ts(&section);
        ts << "battery" << i;

        settings.beginGroup(section);
        BatteryConfig battery;
        battery.name = settings.value("name", section).toString();
        battery.smapidir = settings.value("smapidir").toString();
        this->bats.append(battery);
        settings.endGroup();
    }

    settings.beginGroup("governors");
    QStringList keys = settings.childKeys();

    foreach(QString key, keys) {
        QString value = settings.value(key, "").toString();

        if(key.endsWith("min")) {
            QString governor = key.left(key.indexOf('_'));
            governors[governor].first = decodeGovernorFreq(value);
        } else if(key.endsWith("max")) {
            QString governor = key.left(key.indexOf('_'));
            governors[governor].second = decodeGovernorFreq(value);
        } else {
            continue;
        }
    }

    settings.endGroup();
}

int Config::decodeGovernorFreq(const QString & string) {
    if(string == "max") {
        return -1;
    } else if (string == "min") {
        return -2;
    }
    return string.toInt() * 1000;
}


Config& GlobalConfig() {
    static Config cfg;
    return cfg;
}
