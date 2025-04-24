#include <stdio.h>
#include "Display.h"
#include "ultrasonic.h"

void app_main(void)
{
    Display_config disp_cfg = {
        .dev_addr = 0x3C, //0x3C
        .height_res = 64, //default for sh1106
        .width_res = 128, //defualt for sh1106
        .io_scl = GPIO_NUM_12,
        .io_sda = GPIO_NUM_11,
        .port_num = 1,
    };
    disp_handle display = init_display(&disp_cfg);
    if(!display){
        ESP_LOGI("ERROR: ", "Display was not created");
        return;
    }
    esp_err_t err;

    // ultrasonic_config_t sonic_cfg = {
    //     .echo_pin = GPIO_NUM_15,
    //     .trig_pin = GPIO_NUM_21,
    // };
    
    // ultrasonic_init(&sonic_cfg);

    // err = add_menu(display, "Main");
    
    char *txt = "hello world!";
    // data = ultrasonic_measure();
    // Convert float to string 
    // sprintf(txt, "%.2f", data); // Formats the float to 2 decimal places 
    err = add_label(display, txt);
    while(1){

        vTaskDelay(pdMS_TO_TICKS(30));
    }
}