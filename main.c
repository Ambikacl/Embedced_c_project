/**
 * @file main.c
 * @author Ambika C L (259806);
 * @brief Activity_1
 * @version 0.1
 * @date 2021-04-24
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "act1.h"
#include "act2.h"

int main(void)
{
    Init_Ports();/* Initialize Ports */
	/* if and only if both button sensor and heater switch is on(pressed) LED turns ON */
	Led_Status();
    return 0;
}
