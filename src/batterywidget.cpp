#include <QDesktopWidget>
#include "batterywidget.h"
#include "ui_batterywidget.h"

BatteryWidget::BatteryWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BatteryWidget)
{
    ui->setupUi(this);

    connect(ui->stopChargingSlider,
            SIGNAL(sliderMoved(int)),
            SLOT(setStopChargeTresh(int)));
    connect(ui->advancedButton,
            SIGNAL(clicked()),
            SLOT(showAdvancedInfo()));
}

BatteryWidget::~BatteryWidget()
{
    delete ui;
    delete batteryModel;
}

void BatteryWidget::refresh() {
    batteryModel->refresh();

    ui->nameLabel->setText(batteryModel->name());
    ui->statusLabelValue->setText(batteryModel->state());

    if(batteryModel->state() == "none") {
        ui->percentProgressBar->setEnabled(false);
        ui->percentProgressBar->setValue(0);
        ui->advancedButton->setEnabled(false);
        ui->timeLabel->setText("Remaining time");
        ui->timeValueLabel->setText("not discharging");
    } else {
        ui->percentProgressBar->setEnabled(true);
        ui->percentProgressBar->setValue(batteryModel->getRemainingPercent());
        ui->advancedButton->setEnabled(true);

        if (batteryModel->state() == "charging") {
            ui->timeLabel->setText("Remaining charging time");
            ui->timeValueLabel->setText(
                            batteryModel->getRemainingChargeTime()
                        );
        } else  if(batteryModel->state() == "discharging") {
            ui->timeLabel->setText("Remaining time");
            ui->timeValueLabel->setText(
                            batteryModel->getRemainingDischargeTime()
                        );
        } else {
            ui->timeLabel->setText("Remaining time");
            ui->timeValueLabel->setText("not discharging");
        }
    }

    if(batteryModel->getStopChargeTresh() % 5 != 0) {
        setStopChargeTresh((batteryModel->getStopChargeTresh() / 5) * 5);
    }

    QString stopChargeValue = QString("%1%")
            .arg(batteryModel->getStopChargeTresh());
    ui->stopChargingValueLabel->setText(stopChargeValue);
    ui->stopChargingSlider->setValue(batteryModel->getStopChargeTresh() / 5);
}

void BatteryWidget::setStopChargeTresh(int percent) {
    batteryModel->setStopChargeTresh(percent * 5);
}

void BatteryWidget::showAdvancedInfo() {
    AdvancedBatteryDialog *abd = new AdvancedBatteryDialog(
                batteryModel->config().smapidir,
                batteryModel->config().name,
                this);
    abd->setModal(true);
    abd->setGeometry(QStyle::alignedRect(
                          Qt::LeftToRight,
                          Qt::AlignCenter,
                          abd->size(),
                          qApp->desktop()->availableGeometry()
                      ));
    abd->exec();
    delete abd;
}
