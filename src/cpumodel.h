#ifndef CPUMODEL_H
#define CPUMODEL_H

#include <QString>
#include <QStringList>
#include <QVector>
#include "cpuconfig.h"

class CpuModel
{
    CpuConfig config;
    int curFreq;
    int minFreq;
    int maxFreq;
    QVector<int> frequencies;
    QString governor;
    QStringList governors;
    bool freqChangeSupported;

public:
    CpuModel(const CpuConfig & config) {
        this->config = config;
    }

    void refresh();

    QString& name();
    int freq();
    QString freqString();
    QString freqRange();
    bool isFreqChangeSupported();
    QString curGovernor();
    QStringList availableGovernors();
    QVector<int>& availableFrequencies();
    int minFrequency();
    int maxFrequency();

    void setGovernor(const QString & governor);
    void setFrequency(int frequency);
    void setMinFrequency(int frequency);
    void setMaxFrequency(int frequency);
};

#endif // CPUMODEL_H
