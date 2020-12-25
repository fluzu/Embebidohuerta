//
// Created by Facu on 09/11/2020.
//

#include "stm32f4xx.h"
#include "stm32f411xe.h"    //revisar hace falta "discovery" estee puede ser incorrecto
#include "BSP.h"

typedef struct {
    GPIO_TypeDef Port;
    uint16_t Pin;
}str_pinled;

struct  str_pinled pinLed_Rojo = {GPIOA, GPIO_PIN_2};
struct  str_pinled pinLed_Verde = {GPIOA, GPIO_PIN_3};

void BSP_Init(void){
    GPIO_InitTypeDef pinLed;

    //falta inicializar clocks
    pinLed.Mode = GPIO_MODE_OUTPUT_PP;
    pinLed.Pull = GPIO_NOPULL;
    pinLed.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    pinLed.Pin = pinLed_Rojo.Pin;
    HAL_GPIO_Init(pinLed_Rojo.port, &pinLed);

    pinLed.Pin = pinLed_Verde.Pin;
    HAL_GPIO_Init(pinLed_Verde.Port, &pinLed);
}

void BSP_Led_On(void *led){
    struct  str_pinled *myLed = (struct str_pinled *)led;
    void HAL_GPIO_WritePin(myLed->Port, myLed->Pin, GPIO_PIN_SET);
}

void BSP_Led_Off(void *led){
    struct  str_pinled *myLed = (struct str_pinled *)led;
    void HAL_GPIO_WritePin(myLed->Port, myLed->Pin, GPIO_PIN_RESET);
}











//#define NUM_LEDS 2

//void *LedRojo, *LedVerde;

//int main(void)
//{
//    BSP_Init();

//    while(1){
//        BSP_Led_On(LedRojo);
//    }
//}

