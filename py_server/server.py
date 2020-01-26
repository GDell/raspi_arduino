from flask import Flask
import socket
app = Flask(__name__)

@app.route('/')
def hello_world():
    return 'Hello, World!'


def get_ip():
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    try:
        # doesn't even have to be reachable
        s.connect(('10.255.255.255', 1))
        IP = s.getsockname()[0]
    except:
        IP = '127.0.0.1'
    finally:
        s.close()
    return IP

# Function to display hostname and
# IP address
def get_Host_name_IP():
    try:
        global host_name
        global host_ip
        host_name = socket.gethostname()
        host_ip = get_ip()
        print("Hostname :  ",host_name)
        print("IP : ",host_ip)
    except:
        print("Unable to get Hostname and IP")

# Driver code
get_Host_name_IP() #Function call


if __name__ == '__main__':
    # get_Host_name_IP() #Function call
    # This is used when running locally. Gunicorn is used to run the
    # application on Google App Engine. See entrypoint in app.yaml.
    app.run(host=host_ip, port=80, debug=True)
