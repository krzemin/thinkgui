#ifndef FANWIDGET_H
#define FANWIDGET_H

#include <QWidget>
#include "fanmodel.h"

namespace Ui {
class FanWidget;
}

class FanWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit FanWidget(QWidget *parent = 0);
    ~FanWidget();
    
    void setModel(FanModel * model) {
        fanModel = model;
    }

    FanModel & model() {
        return *fanModel;
    }

    void refresh();

private:
    Ui::FanWidget *ui;
    FanModel *fanModel;
};

#endif // FANWIDGET_H
