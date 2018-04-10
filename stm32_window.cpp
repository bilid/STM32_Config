#include "stm32_window.h"
#include "ui_stm32_window.h"
#include "QComboBox"
#include "chosearm.h"
STM32_Window::STM32_Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::STM32_Window)
{
    ui->setupUi(this);
    UI_NINT();

}

STM32_Window::~STM32_Window()
{
    delete ui;
}

void STM32_Window::UI_NINT()
{

    p_UI_NIVC=new UI_NIVC;
    p_UI_GPIO =new UI_GPIO;
    ui->tabWidget->addTab(p_UI_GPIO,tr("GPIO"));
    ui->tabWidget->addTab(p_UI_NIVC,tr("NIVC"));

}
