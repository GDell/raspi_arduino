import bluetooth

def receiveMessages():
  server_sock=bluetooth.BluetoothSocket( bluetooth.RFCOMM )

  port = 1
  server_sock.bind(("",port))
  server_sock.listen(1)

  client_sock, address = server_sock.accept()
  print "Accepted connection from " + str(address)

  data = client_sock.recv(1024)
  print "received [%s]" % data

  client_sock.close()
  server_sock.close()

def sendMessageTo(targetBluetoothMacAddress):
  port = 1
  sock=bluetooth.BluetoothSocket( bluetooth.RFCOMM )
  sock.connect((targetBluetoothMacAddress, 2))
  sock.send("hello!!")
  sock.close()

def lookUpNearbyBluetoothDevices():
  # print "Searching for nearby bluetooth devices ... "
  # nearby_devices = bluetooth.discover_devices()
  # for bdaddr in nearby_devices:
  #   print str(bluetooth.lookup_name( bdaddr )) + " [" + str(bdaddr) + "]"
  #Look for all Bluetooth devices

  print "Searching for devices..."
  print ""
  #Create an array with all the MAC
  #addresses of the detected devices
  nearby_devices = bluetooth.discover_devices()
  #Run through all the devices found and list their name
  num = 0
  print "Select your device by entering its coresponding number..."
  for i in nearby_devices:
  	num+=1
  	print num , ": " , bluetooth.lookup_name( i )

  #Allow the user to select their Arduino
  #bluetooth module. They must have paired
  #it before hand.
  selection = input("> ") - 1
  print "You have selected", bluetooth.lookup_name(nearby_devices[selection])
  bd_addr = nearby_devices[selection]
  print "BD addr:"+str(bd_addr)
  sendMessageTo(bd_addr)



lookUpNearbyBluetoothDevices()

# print "Provide address:"
# theNum = str(3input())
