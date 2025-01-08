#include <conio.h>  // Windows 专用

#include <asio.hpp>
#include <iostream>
#include <string>
#include <thread>

void read_from_serial(asio::serial_port &serial) {
    try {
        char data[256];  // 接收缓冲区
        while (true) {
            std::size_t bytes_read =
                serial.read_some(asio::buffer(data, sizeof(data)));
            if (bytes_read > 0) {
                std::cout << "Received: ";
                std::cout.write(data, bytes_read);
                std::cout << std::endl;
            }
        }
    } catch (std::exception &e) {
        std::cerr << "Error in reading: " << e.what() << std::endl;
    }
}

int main() {
    try {
        // 打开串口
        std::string port = "COM7";  // 根据实际端口号修改
        asio::io_service io;
        asio::serial_port serial(io, port);

        // 设置串口参数
        serial.set_option(asio::serial_port_base::baud_rate(9600));
        serial.set_option(asio::serial_port_base::character_size(8));
        serial.set_option(asio::serial_port_base::parity(
            asio::serial_port_base::parity::none));
        serial.set_option(asio::serial_port_base::stop_bits(
            asio::serial_port_base::stop_bits::one));
        serial.set_option(asio::serial_port_base::flow_control(
            asio::serial_port_base::flow_control::none));

        // 启动读取线程
        std::thread reader_thread(read_from_serial, std::ref(serial));

        // 主线程负责发送数据
        std::cout << "Enter '1' to turn ON the LED, '0' to turn OFF:\n";
        char command;
        while (true) {
            if (_kbhit()) {               // 检测是否有键盘输入
                char command = _getch();  // 获取按键（无需按下回车）
                if (command == '1' || command == '0') {
                    asio::write(serial, asio::buffer(&command, 1));
                    std::cout << "Sent: " << command << std::endl;
                } else {
                    std::cout << "Invalid command. Please enter '1' or '0'."
                              << std::endl;
                }
            }
        }

        // 等待读取线程结束（理论上主循环不会退出）
        reader_thread.join();
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return -1;
    }
    return 0;
}
