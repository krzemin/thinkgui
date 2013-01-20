#include <QRegExp>
#include "cpumodel.h"
#include "fileio.h"

void CpuModel::refresh() {

    curFreq = FileIO::read(config.sysdir + "/scaling_cur_freq").toInt();
    minFreq = FileIO::read(config.sysdir + "/scaling_min_freq").toInt();
    maxFreq = FileIO::read(config.sysdir + "/scaling_max_freq").toInt();

    governor = FileIO::read(config.sysdir + "/scaling_governor")
                .toString().trimmed();
    governors = FileIO::read(config.sysdir + "/scaling_available_governors")
                .toString().split(QRegExp("\\s"), QString::SkipEmptyParts);

    governors.sort();

    QString setspeed = FileIO::read(config.sysdir + "/scaling_setspeed")
                        .toString().trimmed();

    freqChangeSupported = !setspeed.isEmpty()
                          && setspeed.indexOf("unsupported") == -1;

    QStringList fqList;
    fqList = FileIO::read(config.sysdir + "/scaling_available_frequencies")
            .toString().split(QRegExp("\\s"), QString::SkipEmptyParts);
    frequencies.clear();
    foreach(QString fq, fqList) {
        frequencies.append(fq.toInt());
    }
    qSort(frequencies);
}

QString& CpuModel::name() {
    return config.name;
}

int CpuModel::freq() {
    return curFreq;
}

QString CpuModel::freqString() {
    return QString("%1 MHz").arg(curFreq/1000);
}


QString CpuModel::freqRange() {
    return QString("%1 MHz - %2 MHz").arg(minFreq/1000).arg(maxFreq/1000);
}

bool CpuModel::isFreqChangeSupported() {
    return freqChangeSupported;
}

QString CpuModel::curGovernor() {
    return governor;
}

QStringList CpuModel::availableGovernors() {
    return governors;
}

QVector<int>& CpuModel::availableFrequencies() {
    return frequencies;
}

void CpuModel::setFrequency(int frequency) {
    FileIO::write(config.sysdir + "/scaling_setspeed", frequency);
}

void CpuModel::setMinFrequency(int frequency) {
    FileIO::write(config.sysdir + "/scaling_min_freq", frequency);
}

void CpuModel::setMaxFrequency(int frequency) {
    FileIO::write(config.sysdir + "/scaling_max_freq", frequency);
}

int CpuModel::minFrequency() {
    return minFreq;
}

int CpuModel::maxFrequency() {
    return maxFreq;
}

void CpuModel::setGovernor(const QString & governor) {
    FileIO::write(config.sysdir + "/scaling_governor", governor);
}
