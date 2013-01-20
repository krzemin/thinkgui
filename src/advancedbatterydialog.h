#ifndef ADVANCEDBATTERYDIALOG_H
#define ADVANCEDBATTERYDIALOG_H

#include <QDialog>

namespace Ui {
class AdvancedBatteryDialog;
}

class AdvancedBatteryDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit AdvancedBatteryDialog(const QString & batteryPath,
                                   const QString & batteryName,
                                   QWidget *parent = 0);
    ~AdvancedBatteryDialog();
    
private:
    Ui::AdvancedBatteryDialog *ui;
};

#endif // ADVANCEDBATTERYDIALOG_H
