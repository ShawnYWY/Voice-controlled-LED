/*
   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "speech_commands_action.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"

#define BLINK_GPIO 22

void speech_commands_action(int command_id)
{
    printf("Commands ID: %d.\n", command_id);
    gpio_pad_select_gpio(BLINK_GPIO);
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
    switch (command_id)
    {
    case 0:
        printf("\n -TURN ON -\n");
        gpio_set_level(BLINK_GPIO, 1);
        break;
    
    case 1:
        printf("\n -TURN OFF -\n");
        gpio_set_level(BLINK_GPIO, 0);
        break;

    case 9:
        printf("\n -TURN ON -\n");
        gpio_set_level(BLINK_GPIO, 1);
        break;

    case 10:
        printf("\n -TURN OFF -\n");
        gpio_set_level(BLINK_GPIO, 0);
        break;
    
    default:
        break;
    }
    


}