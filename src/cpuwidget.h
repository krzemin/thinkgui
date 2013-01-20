#ifndef CPUWIDGET_H
#define CPUWIDGET_H

#include <QWidget>
#include <QStringList>
#include "cpumodel.h"
#include "config.h"

namespace Ui {
class CpuWidget;
}

class CpuWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit CpuWidget(QWidget *parent = 0);
    ~CpuWidget();
    
    void setModel(CpuModel * model) {
        cpuModel = model;
    }

    CpuModel & model() {
        return *cpuModel;
    }

    void refresh();

public slots:
    void setGovernor(const QString &governor);
    void setFrequency(int index);

private:
    Ui::CpuWidget *ui;
    CpuModel *cpuModel;
    QStringList governors;
};

#endif // CPUWIDGET_H
