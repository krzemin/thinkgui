#include "fanwidget.h"
#include "ui_fanwidget.h"

FanWidget::FanWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FanWidget)
{
    ui->setupUi(this);
}

FanWidget::~FanWidget()
{
    delete ui;
    delete fanModel;
}

void FanWidget::refresh() {
    fanModel->refresh();
    ui->nameLabel->setText(fanModel->name());
    ui->valueLabel->setText(fanModel->value());
    ui->highValueLabel->setText(fanModel->highValue());
}
