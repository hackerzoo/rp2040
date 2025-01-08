#include "hardware/pwm.h"
#include "pico/stdlib.h"

// 定义 LED 连接的 GPIO 引脚
const uint LED_PIN = 25;

int main() {
    // 初始化标准输入输出
    stdio_init_all();

    // 设置 LED_PIN 为 PWM
    gpio_set_function(LED_PIN, GPIO_FUNC_PWM);

    // 获取 PWM 切片号和通道号
    uint slice_num = pwm_gpio_to_slice_num(LED_PIN);
    uint channel = pwm_gpio_to_channel(LED_PIN);

    // 配置 PWM 的频率
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 4.0f);  // 设置时钟分频
    pwm_init(slice_num, &config, true);

    // 循环实现呼吸灯效果
    while (true) {
        // 增亮过程
        for (uint16_t duty = 0; duty < 65535; duty += 256) {
            pwm_set_chan_level(slice_num, channel, duty);
            sleep_ms(5);  // 调整步长间隔以控制速度
        }

        // 变暗过程
        for (uint16_t duty = 65535; duty > 0; duty -= 256) {
            pwm_set_chan_level(slice_num, channel, duty);
            sleep_ms(5);
        }
    }

    return 0;
}
