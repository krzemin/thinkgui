#include "sensorwidget.h"
#include "ui_sensorwidget.h"

SensorWidget::SensorWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SensorWidget)
{
    ui->setupUi(this);
}

SensorWidget::~SensorWidget()
{
    delete ui;
    delete sensorModel;
}

void SensorWidget::refresh() {
    sensorModel->refresh();
    ui->nameLabel->setText(sensorModel->name());
    ui->valueLabel->setText(sensorModel->value());
    ui->highValueLabel->setText(sensorModel->highValue());
    ui->critValueLabel->setText(sensorModel->critValue());
}
