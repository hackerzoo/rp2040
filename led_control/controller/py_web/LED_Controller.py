from flask import Flask, request, jsonify
import serial
from flask_cors import CORS

# 初始化 Flask
app = Flask(__name__)
# 启用跨域支持
CORS(app)  

# 配置串口
SERIAL_PORT = "COM7"  # 根据实际情况修改
BAUD_RATE = 115200
try:
    pico_serial = serial.Serial(SERIAL_PORT, BAUD_RATE)
except Exception as e:
    print(f"Failed to connect to serial port: {e}")
    pico_serial = None


@app.route('/control', methods=['POST'])
def control_led():
    """控制 LED 的 API"""
    if pico_serial is None:
        return jsonify({"error": "Serial port not connected"}), 500

    data = request.json 
    command = data.get('command')

    if command not in ['1', '0']:
        return jsonify({"error": "Invalid command"}), 400

    try:
        pico_serial.write(command.encode())  # 发送命令到串口
        return jsonify({"message": f"LED is {'ON' if command == '1' else 'OFF'}"})
    except Exception as e:
        return jsonify({"error": str(e)}), 500

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)  # 在本地运行服务器
