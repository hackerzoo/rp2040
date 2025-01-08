#include <stdio.h>

#include "pico/stdlib.h"

// 定义 LED 引脚
#define LED_PIN 25

int main() {
    // 初始化板载 LED
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    // 初始化标准输入输出，使用 USB 虚拟串口
    stdio_init_all();

    // 等待串口就绪
    while (!stdio_usb_connected()) {
        sleep_ms(100);
    }
    printf("Pico is ready to receive data!\n");

    while (true) {
        int ch = getchar_timeout_us(1000);  // 非阻塞读取数据
        if (ch != PICO_ERROR_TIMEOUT) {     // 如果读取到数据

            if (ch == '1') {
                gpio_put(LED_PIN, 1);  // 打开 LED
                printf("LED ON\t");
                printf("LED state: %d\n", gpio_get(LED_PIN));  // 读取引脚状态
            } else if (ch == '0') {
                gpio_put(LED_PIN, 0);  // 关闭 LED
                printf("LED OFF\t");
                printf("LED state: %d\n", gpio_get(LED_PIN));  // 读取引脚状态
            } else {
                printf("Invalid data: %c\n", ch);
            }
        }
    }

    return 0;
}
