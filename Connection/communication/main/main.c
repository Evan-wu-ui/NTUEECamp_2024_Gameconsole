#include <stdio.h>
#include "freertos/FreeRTOS.h"

#include <string.h>
<<<<<<< HEAD
<<<<<<< HEAD
#include "driver/uart.h"
=======
>>>>>>> 8f548d9 (modify main.c & readme & urat->uart)
=======
>>>>>>> 8f548d9e2f897cc93accbd454370bf141499391a
#include "uartFunction.h"
// 全域變數
char* array;
uint8_t numm;
char ch;
<<<<<<< HEAD
<<<<<<< HEAD

void setup() {
    // 初始化 UART0 用于print输出
    const uart_config_t uart_config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_APB,
    };
    uart_param_config(UART_NUM_0, &uart_config);
    uart_driver_install(UART_NUM_0, 256, 0, 0, NULL, 0);
=======
void setup() {
>>>>>>> 8f548d9 (modify main.c & readme & urat->uart)
=======
void setup() {
>>>>>>> 8f548d9e2f897cc93accbd454370bf141499391a
    // 配置 UART
    uartSetup();
    // 初始化测试数据
    array = (char*)malloc(60 * sizeof(char));//開超過需要的記憶體空間(需要57)
    strcpy(array, "data try  data try data try data try sign try !@#$^ &*()");
    numm = 85;
    ch = 'y';
    //初始化timeout
<<<<<<< HEAD
<<<<<<< HEAD
    setTimeoutMs(75);
=======
    setTimeoutMs(200);
>>>>>>> 8f548d9 (modify main.c & readme & urat->uart)
=======
    setTimeoutMs(200);
>>>>>>> 8f548d9e2f897cc93accbd454370bf141499391a
}

void loop() {
    sendCharArray(array);//傳送兩次
    sendUint8(numm);
    sendChar(ch);
    sendCharArray(array);//多傳送為了測試clearbuffer
    sendUint8(numm);
    sendChar(ch);

<<<<<<< HEAD
<<<<<<< HEAD
    vTaskDelay(200/portTICK_PERIOD_MS);//每個loop 200ms(並等待數據傳進buffer)
=======
    vTaskDelay(500/portTICK_PERIOD_MS);//每個loop 500ms(並等待數據傳進buffer)
>>>>>>> 8f548d9 (modify main.c & readme & urat->uart)
=======
    vTaskDelay(500/portTICK_PERIOD_MS);//每個loop 500ms(並等待數據傳進buffer)
>>>>>>> 8f548d9e2f897cc93accbd454370bf141499391a
    printf("initial bufferavaliable:%d\n\n",receiveAvaliable());//應是118

    char* a = receiveCharArray();//接收char array
    printf("Received array: %s\n", a ? a : "NULL");
    printf("bufferavaliable after receive charArray:%d\n\n",receiveAvaliable());//應是61

    uint8_t num = receiveUint8();//接收uint8
    printf("Received num: %u\n", num);
    printf("bufferavaliable after receive charArray uint8:%d\n\n",receiveAvaliable());//應是60

    char received_ch = receiveChar();//接收char
    printf("Received char: %c\n", received_ch);
    printf("bufferavaliable after receive charArray uint8 char:%d\n\n",receiveAvaliable());//應是59

    clearBuffer();
    printf("bufferavaliable after clearBuffer:%d\n\n\n\n",receiveAvaliable());//應是0

    free(a);
}
void app_main() {
    setup();
    while (true) {
        loop();
    }
}
