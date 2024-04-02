import socket
import threading

# Input IP address and port number

Ip_add = input("Enter the IP address: ")
port_no = input("Enter the port number: ")


client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

def check_connection(ip ):
    
    try:
        client_socket.connect((ip, 4080))
        print("Connection successful")
    except (socket.gaierror, ConnectionRefusedError):
        print("Connection failed, retrying...")


def send_command(client_socket,command):
    client_socket.send(command.encode())    
    
    

# Create a thread to check the connection


connection_thread = threading.Thread(target=check_connection, args=(Ip_add))
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
    send_command(client_socket,'1')
    
    pass
 elif msg == '2':
    # Second condition
    print("second condition met")
    send_command(client_socket,'1')
    
    pass
else:
    # Third condition
    pass



connection_thread.join()