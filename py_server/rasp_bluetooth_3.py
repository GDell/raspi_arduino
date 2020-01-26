import bluetooth, time

HCO6_MAC_ADDRESS = '98:D3:51:FD:B7:46'
HCO5_MAC_ADDRESS = 'FC:58:FA:22:CA:01'

def sendMessageTo(targetBluetoothMacAddress, send_data):
    port = 1
    sock=bluetooth.BluetoothSocket( bluetooth.RFCOMM )
    sock.connect((targetBluetoothMacAddress, 1))
    time.sleep(.5)
    print("CONNECTED!")
    sock.send(send_data.encode('utf-8'))
    print("SENT DATA: "+str(send_data))
    time.sleep(1)
    sock.close()

def lookUpNearbyBluetoothDevices():
    print("Searching for nearby bluetooth devices ... ")
    nearby_devices = bluetooth.discover_devices()
    for bdaddr in nearby_devices:
        print(str(bluetooth.lookup_name( bdaddr )) + " [" + str(bdaddr) + "]")

def selectFromNearByDevices():
    print("Searching for devices...\n")
    #Create an array with all the MAC
    #addresses of the detected devices
    nearby_devices = bluetooth.discover_devices()
    #Run through all the devices found and list their name
    num = 0
    print("Select your device by entering its coresponding number...")
    for i in nearby_devices:
    	num+=1
    	print(num , ": " , bluetooth.lookup_name( i ))

    #Allow the user to select their Arduino
    #bluetooth module. They must have paired
    #it before hand.
    selection = input("> ") - 1
    print("You have selected", bluetooth.lookup_name(nearby_devices[selection]))
    bd_addr = nearby_devices[selection]
    print("BD addr:"+str(bd_addr))


sendMessageTo(HCO6_MAC_ADDRESS, "Hello! Testing Bluetooth ...")
# lookUpNearbyBluetoothDevices()
