#include "chosearm.h"
#include "ui_chosearm.h"

ChoseARM::ChoseARM(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChoseARM)
{
    ui->setupUi(this);
    QObject::connect(ui->OK_BTN,SIGNAL(clicked(bool)),this,SLOT( sendMODEL()));
    QObject::connect(this,SIGNAL(choseModel()),this,SLOT(accept()));


}

ChoseARM::~ChoseARM()
{
    delete ui;
}

ChoseARM::sendMODEL()
{

    if(ui->MCUModel->currentText()=="STM32F103C8T6")
    {
        emit choseModel() ;
    }
    else
    {
        QMessageBox::information(this, tr("提示信息"), tr("对不起，此软件暂不支持其它型号的MCU"), QMessageBox::NoButton);
    }


}


