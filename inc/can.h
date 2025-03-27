#include "zephyr/drivers/gpio.h"
#include <zephyr/device.h>
#include <zephyr/drivers/can.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

/*
 * É necessário rodar Init_CAN() e em um loop while rodar CAN_Tick()
 */

int Init_CAN();

// Essa função deve ser chamada em algum while loop
int CAN_Tick();

int send_kill_switch(bool piloto, bool kill);
