#ifndef UI_NIVC_H
#define UI_NIVC_H

#include <QWidget>

namespace Ui {
class UI_NIVC;
}

class UI_NIVC : public QWidget
{
    Q_OBJECT

public:
    explicit UI_NIVC(QWidget *parent = 0);
    ~UI_NIVC();
    void getNVIC_IRQChannel();
    void UIInit();
    void getPriority();
    void getNewState();

private:
    Ui::UI_NIVC *ui;
    QStringList NVIC_IRQChannel ;
    QStringList Priority;
    QStringList     NewState ;
};

#endif // UI_NIVC_H
