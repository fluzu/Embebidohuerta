//
// Created by Facundo Luzuriaga on 09/11/2020.
//

#ifndef TESTLCDI2C_BSP_H
#define TESTLCDI2C_BSP_H

void BSP_Init(void);

void BSP_Led_Init(void);
void BSP_Led_On(void *led);
void BSP_Led_Off(void *led);

#endif //TESTLCDI2C_BSP_H
