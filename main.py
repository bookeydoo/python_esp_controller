import socket
import threading

def check_connection(ip, port):
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect((ip, int(port)))
    
    try:
        client_socket.connect((ip, int(port)))
        print("Connection successful")
    except (socket.gaierror, ConnectionRefusedError):
        print("Connection failed, retrying...")
    
    
# Input IP address and port number
Ip_add = input("Enter the IP address: ")
port_no = input("Enter the port number: ")

# Create a thread to check the connection


connection_thread = threading.Thread(target=check_connection, args=(Ip_add, port_no))
connection_thread.start()
 


# Other parts of your program
print("Please choose from the following options:")
print("1. Send back a heartbeat")
print("2. Begin vertical mission")
print("3. Upload the file of readings when you are done")
while 1:
 msg = input("->")
 if msg == '1':
    # First condition
    print("first condition met ")
    
    pass
 elif msg == '2':
    # Second condition
    print("second condition met")
    pass
else:
    # Third condition
    pass



connection_thread.join()