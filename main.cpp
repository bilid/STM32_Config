#include "stm32_window.h"
#include <QApplication>
#include "chosearm.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    STM32_Window w;
    ChoseARM LOGIN;
    LOGIN.show();
    if(LOGIN.exec()==QDialog::Accepted)
    {
        w.show();
        return a.exec();
    }
    else {
         return  0;
    }



}
