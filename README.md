# rp2040



#### 项目简介

本仓库包含一系列关于树莓派 Pico (RP2040) 的学习与实验代码，旨在帮助开发者掌握基本的硬件控制技巧与编程实践。以下是各个实验模块的简介：

led_control/
该模块包含使用windows控制 LED 灯的代码，包含三种控制方式：c++ asio串口通信、python flask网页控制、html5网页串口控制。

manual/
此目录包含一系列基础实验，采取了和其他项目不一样的CMake管理方式，此目录中的项目需要修改CMakeLists.txt中的绝对路径，而**此目录之外的项目需要通过vscode的Raspberry Pi Pico插件导入**。

blink/: 简单的 LED 闪烁实验，通过编程实现 LED 按照指定的时间间隔闪烁。
breath/: 实现 LED 的“呼吸”效果，使其亮度逐渐增大然后逐渐减小，模拟呼吸的节奏。
helloworld/: 最基础的实验，向COM7端口发送一个简单的“Hello World”消息，帮助熟悉树莓派 Pico 上的编程环境。
onboard_temperature/:
该模块展示了如何读取树莓派 Pico 板载温度传感器的数据，并将其用于简单的温度监测应用。

pwm_led_fade/
通过 PWM 控制技术实现 LED 亮度渐变效果。适用于学习如何使用脉冲宽度调制 (PWM) 控制硬件的亮度、速度等变量。

目录结构
```bash
├── led_control/           # LED 上位机控制开关实验
├── manual/                # 基础实验手册
│   ├── blink/             # LED 闪烁实验
│   ├── breath/            # LED 呼吸效果实验
│   └── helloworld/        # "Hello World" 实验
├── onboard_temperature/   # 读取板载温度传感器数据
└── pwm_led_fade/          # LED 渐变亮度实验
```

