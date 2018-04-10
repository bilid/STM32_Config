#include "ui_nivc.h"
#include "ui_ui_nivc.h"

UI_NIVC::UI_NIVC(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UI_NIVC)
{
    ui->setupUi(this);
    getNVIC_IRQChannel();
    getPriority();
    getNewState();
    UIInit();
}

UI_NIVC::~UI_NIVC()
{
    delete ui;
}

void UI_NIVC::getNVIC_IRQChannel()
{
    NVIC_IRQChannel <<"WWDG_IRQChannel"<<"PVD_IRQChannel"<<"TAMPER_IRQChannel "<<"RTC_IRQChannel "
                   <<"FlashItf_IRQChannel "<<"RCC_IRQChannel "<<"EXTI0_IRQChannel "<<"EXTI1_IRQChannel "<<"EXTI2_IRQChannel "
                  <<"EXTI3_IRQChannel "<<"EXTI4_IRQChannel "<<"DMAChannel1_IRQChannel "<<"DMAChannel2_IRQChannel "
                 <<"DMAChannel3_IRQChannel "<<"DMAChannel4_IRQChannel"<<"DMAChannel5_IRQChannel "<<"DMAChannel6_IRQChannel "
                <<"DMAChannel7_IRQChannel "<<"ADC_IRQChannel"<<"USB_HP_CANTX_IRQChannel "<<"USB_LP_CAN_RX0_IRQChannel "
               <<"CAN_RX1_IRQChannel "<<"EXTI9_5_IRQChannel"<<"TIM1_BRK_IRQChannel"<<"TIM1_UP_IRQChannel"<<"TIM1_TRG_COM_IRQChannel"
              <<"TIM1_CC_IRQChannel"<<"TIM2_IRQChannel"<<"TIM3_IRQChannel"<<"TIM4_IRQChannel"<<"I2C1_EV_IRQChannel"<<"I2C1_ER_IRQChannel"
             <<"I2C2_EV_IRQChannel"<<"I2C2_ER_IRQChannel"<<"SPI1_IRQChannel"<<"SPI2_IRQChannel"<<"USART1_IRQChannel"
            <<"USART2_IRQChannel"<<"USART3_IRQChannel"<<"EXTI15_10_IRQChannel"<<"RTCAlarm_IRQChannel"<<"USBWakeUp_IRQChannel";
}

void UI_NIVC::UIInit()
{
    ui->cob_CHANNEL->addItems(NVIC_IRQChannel);
    ui->cobPriority->addItems(Priority);
    ui->cobSubPriority->addItems(Priority);
    ui->cob_NEWSTAT->addItems(NewState);
}

void UI_NIVC::getPriority()
{
    Priority<<"0"<<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8"<<"9"<<"10"<<"11"<<"12"<<"13"<<"14"<<"15";
}

void UI_NIVC::getNewState()
{
        NewState<<"ENABLE"<<"DISABLE ";
}

