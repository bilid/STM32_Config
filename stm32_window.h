#ifndef STM32_WINDOW_H
#define STM32_WINDOW_H

#include <QMainWindow>

#include "ui_nivc.h"
#include "ui_gpio.h"
namespace Ui {
class STM32_Window;
}

class STM32_Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit STM32_Window(QWidget *parent = 0);
    ~STM32_Window();

private:
    Ui::STM32_Window *ui;

    UI_NIVC  *p_UI_NIVC;
    UI_GPIO  *p_UI_GPIO;
    void UI_NINT();
};

#endif // STM32_WINDOW_H
