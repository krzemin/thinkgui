#include "advancedbatterydialog.h"
#include "ui_advancedbatterydialog.h"
#include "fileio.h"

AdvancedBatteryDialog::AdvancedBatteryDialog(const QString & batteryPath,
                                             const QString & batteryName,
                                             QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdvancedBatteryDialog)
{
    ui->setupUi(this);
    ui->gbInfo->setTitle(batteryName);

    ui->barCodeLabelValue->setText(FileIO::read(batteryPath + "/barcoding")
                                   .toString().trimmed());
    ui->chemistryLabelValue->setText(FileIO::read(batteryPath + "/chemistry")
                                     .toString().trimmed());
    ui->cycleCountLabelValue->setText(FileIO::read(batteryPath
                                  + "/cycle_count").toString().trimmed());
    QString designVoltage = QString("%1 V").arg(FileIO::read(batteryPath
               + "/design_voltage").toString().trimmed().toFloat() / 1000.0f);
    ui->designVoltageLabelValue->setText(designVoltage);
    QString designCapacity = QString("%1 mAh").arg(FileIO::read(batteryPath
            + "/design_capacity").toString().trimmed().toInt() / 10);
    ui->designCapacityLabelValue->setText(designCapacity);
    QString lastFullCapacity = QString("%1 mAh").arg(FileIO::read(batteryPath
            + "/last_full_capacity").toString().trimmed().toInt() / 10);
    ui->lastFullCapacityLabelValue->setText(lastFullCapacity);
    ui->firstUseDateLabelValue->setText(FileIO::read(batteryPath
                                  + "/first_use_date").toString().trimmed());
    ui->manufactureDateLabelValue->setText(FileIO::read(batteryPath
                           + "/manufacture_date").toString().trimmed());
    ui->manufacturerLabelValue->setText(FileIO::read(batteryPath
                             + "/manufacturer").toString().trimmed());
    ui->modelLabelValue->setText(FileIO::read(batteryPath
                                + "/model").toString().trimmed());
    ui->serialLabelValue->setText(FileIO::read(batteryPath
                                      + "/serial").toString().trimmed());
}

AdvancedBatteryDialog::~AdvancedBatteryDialog()
{
    delete ui;
}
