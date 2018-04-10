#include "ui_gpio.h"
#include "ui_ui_gpio.h"

UI_GPIO::UI_GPIO(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UI_GPIO)
{
    ui->setupUi(this);
    getRCCFuc();
    getRCC_AHB2Periph();
    getNewState();
    getGPIO_Pin();
    getGPIO_Mode();
    getGPIO_Speed();
    getGPIOX();
    UIInit();
    SIGNALSLOT();

}

UI_GPIO::~UI_GPIO()
{
    delete ui;
}

void UI_GPIO::getRCCFuc()
{
    RCCFuc<<"RCC_APB2PeriphClockCmd";
}

void UI_GPIO::UIInit()
{
    ui->cob_FUC->addItems(RCCFuc);
    ui->cob_RCC_AHB2Periph->addItems(RCC_AHB2Periph);
    ui->NewState->addItems(NewState);
    ui->GPIO_Pin->addItems(GPIO_Pin);
    ui->cob_GPIO_Speed->addItems(GPIO_Speed);
    ui->cobGPIO_Mode->addItems(GPIO_Mode);
    ui->cobGPIOX->addItems(GPIOX);
    ////////////////////////////////////////////////////
    ui->cobGPIOX2->addItems(GPIOX);
    ui->GPIO_Pin_2->addItems(GPIO_Pin);

}

void UI_GPIO::SIGNALSLOT()
{
       QObject::connect(ui->OK_BTN,SIGNAL(clicked(bool)),this,SLOT(UpdataText()));
       QObject::connect(ui->OK_BTN_2,SIGNAL(clicked(bool)),this,SLOT(GPIO_SetBits()));
}


void UI_GPIO::getRCC_AHB2Periph()
{
    RCC_AHB2Periph<<"RCC_APB2Periph_AFIO"<<"RCC_APB2Periph_GPIOA"<<"RCC_APB2Periph_GPIOA"<<"RCC_APB2Periph_GPIOB"
                 <<"RCC_APB2Periph_GPIOC"<<"RCC_APB2Periph_GPIOD"<<"RCC_APB2Periph_GPIOE"<<"RCC_APB2Periph_ADC1 "<<"RCC_APB2Periph_ADC2"
                <<"RCC_APB2Periph_TIM1"<<"RCC_APB2Periph_SPI1"<<"RCC_APB2Periph_USART1"<<"RCC_APB2Periph_ALL";
}

void UI_GPIO::getNewState()
{
    NewState<<"ENABLE"<<"DISABLE ";
}

void UI_GPIO::getGPIO_Pin()
{
    GPIO_Pin<<"GPIO_Pin_None"<<"GPIO_Pin_0"<<"GPIO_Pin_1"<<"GPIO_Pin_2"<<"GPIO_Pin_3"<<"GPIO_Pin_4"<<"GPIO_Pin_5"<<"GPIO_Pin_6"
           <<"GPIO_Pin_6"<<"GPIO_Pin_7"<<"GPIO_Pin_8"<<"GPIO_Pin_9"<<"GPIO_Pin_10"<<"GPIO_Pin_11"<<"GPIO_Pin_12"<<"GPIO_Pin_13"<<"GPIO_Pin_14"
          <<"GPIO_Pin_15"  <<"GPIO_Pin_All";
}

void UI_GPIO::getGPIO_Mode()
{
    GPIO_Mode<<"GPIO_Mode_AIN"<<"GPIO_Mode_IN_FLOATING"
            <<"GPIO_Mode_IPD"<<"GPIO_Mode_IPU"<<"GPIO_Mode_Out_OD"
           <<"GPIO_Mode_Out_PP"<<"GPIO_Mode_AF_OD"<<"GPIO_Mode_AF_PP";
}

void UI_GPIO::getGPIO_Speed()
{
    GPIO_Speed<<"GPIO_Speed_10MHz"<<"GPIO_Speed_2MHz"<<"GPIO_Speed_50MHz";
}

void UI_GPIO::getGPIOX()
{
    GPIOX<<"GPIOA"<<"GPIOB"<<"GPIOC"<<"GPIOD"<<"GPIOE"<<"GPIOF";
}

void UI_GPIO::UpdataText()
{
        QString  code=QString(
                "GPIO_InitTypeDef   "+ui->InitStructure->toPlainText()+";\n"
                +ui->cob_FUC->currentText()+"(" + ui->cob_RCC_AHB2Periph->currentText()  +","+ui->NewState->currentText()+");\n"
                +"GPIO_InitStructture.GPIO_Pin="+ui->GPIO_Pin->currentText()+";\n"
                +"GPIO_InitStructture.GPIO_Speed="+ui->cob_GPIO_Speed->currentText() +  ";\n"
                +"GPIO_InitStructture.GPIO_Mode="+ui->cobGPIO_Mode->currentText() +  ";\n"
                +"GPIO_Init("+ui->cobGPIOX->currentText()+",   &"+ui->InitStructure->toPlainText()+");\n"
                );
    ui->CODEtextEdit->setText(code);
}

void UI_GPIO::GPIO_SetBits()
{
    QString  code=QString(
                "GPIO_SetBits("+ui->cobGPIOX2->currentText()+","+ui->GPIO_Pin_2->currentText()+");\n"
            );
    ui->FUNC_CODE->setText(code);
}


