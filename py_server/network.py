import socket

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

def get_Host_name_IP():
    try:
        # global host_name
        # global host_ip
        host_name = socket.gethostname()
        host_ip = get_ip()
        print("Hostname :  ",host_name)
        print("IP : ",host_ip)
        return host_ip , host_name
    except:
        print("Unable to get Hostname and IP")
