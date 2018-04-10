#ifndef UI_GPIO_H
#define UI_GPIO_H

#include <QWidget>

namespace Ui {
class UI_GPIO;
}

class UI_GPIO : public QWidget
{
    Q_OBJECT

public:
    explicit UI_GPIO(QWidget *parent = 0);
    ~UI_GPIO();
    void getRCCFuc();
    void UIInit();
    void SIGNALSLOT();
    void getRCC_AHB2Periph();
    void getNewState();
    void getGPIO_Pin();
    void getGPIO_Mode();
    void getGPIO_Speed();
    void getGPIOX();

private:
    Ui::UI_GPIO *ui;
    QStringList RCCFuc;
    QStringList RCC_AHB2Periph;
    QStringList NewState;
    QStringList GPIO_Pin;
    QStringList GPIO_Speed;
    QStringList   GPIO_Mode ;
    QStringList   GPIOX ;

private slots:
    void UpdataText();
    void GPIO_SetBits ();
};


#endif // UI_GPIO_H
