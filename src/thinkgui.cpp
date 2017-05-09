#include <QSet>
#include "thinkgui.h"
#include "ui_thinkgui.h"
#include "config.h"

ThinkGui::ThinkGui(QWidget *parent, Qt::WindowFlags flags) :
    QDialog(parent, flags),
    ui(new Ui::ThinkGui)
{
    ui->setupUi(this);
    initCpuWidgets();
    initSensorWidgets();
    initFanWidgets();
    initBatteryWidgets();
    refresh();
    updateTimer = new QTimer(this);
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(refresh()));
    updateTimer->start(GlobalConfig().refresh);

    connect(ui->conservativeButton,
            SIGNAL(clicked()),
            SLOT(conservativeClicked()));
    connect(ui->ondemandButton,
            SIGNAL(clicked()),
            SLOT(ondemandClicked()));
    connect(ui->powersaveButton,
            SIGNAL(clicked()),
            SLOT(powersaveClicked()));
    connect(ui->performanceButton,
            SIGNAL(clicked()),
            SLOT(performanceClicked()));
    connect(ui->userspaceButton,
            SIGNAL(clicked()),
            SLOT(userspaceClicked()));
}

ThinkGui::~ThinkGui()
{
    updateTimer->stop();
    delete updateTimer;

    foreach(CpuWidget *c, cpu) {
        delete c;
    }
    cpu.clear();

    foreach(SensorWidget *s, sensor) {
        delete s;
    }
    sensor.clear();

    foreach(FanWidget *f, fan) {
        delete f;
    }
    fan.clear();
    
    foreach(BatteryWidget *b, bat) {
        delete b;
    }
    bat.clear();

    delete ui;
}


void ThinkGui::initCpuWidgets() {

    foreach(CpuConfig cpuCfg, GlobalConfig().cpus) {
        CpuWidget *cWidget = new CpuWidget();
        CpuModel *cModel = new CpuModel(cpuCfg);
        cWidget->setModel(cModel);
        cpu.append(cWidget);
        ui->cpuGroupBox->layout()->addWidget(cWidget);
    }
}

void ThinkGui::initSensorWidgets() {
    foreach(SensorConfig sensorCfg, GlobalConfig().sensors) {
        SensorWidget *sWidget = new SensorWidget();
        SensorModel *sModel = new SensorModel(sensorCfg);
        sWidget->setModel(sModel);
        sensor.append(sWidget);
        ui->sensorsGroupBox->layout()->addWidget(sWidget);
    }
}

void ThinkGui::initFanWidgets() {
    foreach(FanConfig fanCfg, GlobalConfig().fans) {
        FanWidget *fWidget = new FanWidget();
        FanModel *fModel = new FanModel(fanCfg);
        fWidget->setModel(fModel);
        fan.append(fWidget);
        ui->fansGroupBox->layout()->addWidget(fWidget);
    }
}

void ThinkGui::initBatteryWidgets() {
    foreach(BatteryConfig batCfg, GlobalConfig().bats) {
        BatteryWidget *bWidget = new BatteryWidget();
        BatteryModel *bModel = new BatteryModel(batCfg);
        bWidget->setModel(bModel);
        bat.append(bWidget);
        ui->batteryGroupBox->layout()->addWidget(bWidget);
    }
}

void ThinkGui::refresh() {
    QSet<QString> governors;

    foreach(CpuWidget *cWidget, cpu) {
        cWidget->refresh();
        foreach(QString g, cWidget->model().availableGovernors()) {
            governors.insert(g);
        }
    }

    ui->conservativeButton->setEnabled(governors.contains("conservative"));
    ui->ondemandButton->setEnabled(governors.contains("ondemand"));
    ui->performanceButton->setEnabled(governors.contains("performance"));
    ui->powersaveButton->setEnabled(governors.contains("powersave"));
    ui->userspaceButton->setEnabled(governors.contains("userspace"));

    foreach(SensorWidget *sWidget, sensor) {
        sWidget->refresh();
    }

    foreach(FanWidget *fWidget, fan) {
        fWidget->refresh();
    }

    foreach(BatteryWidget *bWidget, bat) {
        bWidget->refresh();
    }
}

void ThinkGui::setAllGovernors(const QString & governor) {
    foreach(CpuWidget *cWidget, cpu) {
        cWidget->setGovernor(governor);
    }
}

void ThinkGui::conservativeClicked()
{
    setAllGovernors("conservative");
}

void ThinkGui::ondemandClicked()
{
    setAllGovernors("ondemand");
}

void ThinkGui::performanceClicked()
{
    setAllGovernors("performance");
}

void ThinkGui::powersaveClicked()
{
    setAllGovernors("powersave");
}

void ThinkGui::userspaceClicked()
{
    setAllGovernors("userspace");
}
