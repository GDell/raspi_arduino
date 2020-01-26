from flask import Flask
import socket
app = Flask(__name__)

@app.route('/')
def hello_world():
    return 'Hello, World!'


# Function to display hostname and
# IP address
def get_Host_name_IP():
    try:
        host_name = socket.gethostname()
        host_ip = socket.gethostbyname(host_name)
        print("Hostname :  ",host_name)
        print("IP : ",host_ip)
    except:
        print("Unable to get Hostname and IP")

# Driver code
get_Host_name_IP() #Function call

if __name__ == '__main__':
    # This is used when running locally. Gunicorn is used to run the
    # application on Google App Engine. See entrypoint in app.yaml.
    app.run(host='192.168.1.176', port=80, debug=True)
