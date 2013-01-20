#include "cpuwidget.h"
#include "ui_cpuwidget.h"

CpuWidget::CpuWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CpuWidget)
{
    ui->setupUi(this);
    connect(ui->governorComboBox,
            SIGNAL(activated(QString)),
            SLOT(setGovernor(QString)));
    connect(ui->freqSlider,
            SIGNAL(sliderMoved(int)),
            SLOT(setFrequency(int)));
}

CpuWidget::~CpuWidget()
{
    delete ui;
    delete cpuModel;
}

void CpuWidget::refresh() {
    cpuModel->refresh();

    ui->nameLabel->setText(cpuModel->name());
    ui->currentFreqLabel->setText(cpuModel->freqString());
    ui->freqRangeLabel->setText(cpuModel->freqRange());

    if(governors != cpuModel->availableGovernors()) {
        governors = cpuModel->availableGovernors();

        ui->governorComboBox->clear();
        ui->governorComboBox->addItems(governors);
    }

    int idx = governors.indexOf(cpuModel->curGovernor());
    ui->governorComboBox->setCurrentIndex(idx);

    ui->freqSlider->setEnabled(cpuModel->isFreqChangeSupported());


    QVector<int> &frequencies = cpuModel->availableFrequencies();

    int minF = cpuModel->minFrequency();
    int maxF = cpuModel->maxFrequency();

    QVector<int>::iterator itMinF = qLowerBound(frequencies.begin(),
                                                frequencies.end(), minF);
    if(itMinF == frequencies.end()) itMinF--;

    QVector<int>::iterator itMaxF = qLowerBound(frequencies.begin(),
                                                frequencies.end(), maxF);
    if(itMaxF == frequencies.end()) itMaxF--;

    ui->freqSlider->setMinimum(itMinF - frequencies.begin());
    ui->freqSlider->setMaximum(itMaxF - frequencies.begin());

    idx = frequencies.indexOf(cpuModel->freq());
    ui->freqSlider->setValue(idx);
}


void CpuWidget::setGovernor(const QString &governor)
{
    cpuModel->setGovernor(governor);

    if(GlobalConfig().governors.contains(governor)) {
        QPair<int, int> governorMinMax = GlobalConfig().governors[governor];
        QVector<int> & frequencies = cpuModel->availableFrequencies();

        if(governorMinMax.first == -2) {
            cpuModel->setMinFrequency(frequencies.first());
        } else {
            cpuModel->setMinFrequency(governorMinMax.first);
        }
        if(governorMinMax.second == -1) {
            cpuModel->setMaxFrequency(frequencies.last());
        } else {
            cpuModel->setMaxFrequency(governorMinMax.second);
        }
    }
}

void CpuWidget::setFrequency(int index)
{
    QVector<int> & frequencies = cpuModel->availableFrequencies();
    cpuModel->setFrequency(frequencies.at(index));
}
