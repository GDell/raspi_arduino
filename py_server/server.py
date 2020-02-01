from flask import Flask
from flask import Flask as BaseFlask, Config as BaseConfig, render_template, request, jsonify
app = Flask(__name__)
import server
import rasp_bluetooth_3
import network

@app.route('/')
def hello_world():
    return 'Hello, World!'

@app.route('/api/led/color/<string:color>')
def set_rgb_led():
    print("TODO")

@app.route('/bluetooth_devices')
def search_for_devices():
    data = {
        'bluetooth_devices' : rasp_bluetooth_3.lookUpNearbyBluetoothDevices()
    }
    return jsonify(data)


# Driver code
global host_ip
global host_name

host_ip , host_name= network.get_Host_name_IP() #Function call

if __name__ == '__main__':
    # get_Host_name_IP() #Function call
    # This is used when running locally. Gunicorn is used to run the
    # application on Google App Engine. See entrypoint in app.yaml.
    app.run(host=host_ip, port=80, debug=True)
