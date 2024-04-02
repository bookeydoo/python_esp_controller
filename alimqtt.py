import socket

HOST = '0.0.0.0'
PORT = 4080

def main():
    with socket.socket(socket.AFINET, socket.SOCKSTREAM) as serversocket:
        serversocket.bind((HOST, PORT))
        serversocket.listen(1)

        print(f'TCP server is listening on port {PORT}...')

        conn, addr = serversocket.accept()
        print(f'Connected to {addr}')

        while True:
            data = conn.recv(1024)
            if not data:
                break

            command = data.decode('utf-8')

            if command == '1':
                print('Executing command 1')

                conn.send(b'Command 1 executed successfully')
            elif command == '2':
                print('Executing command 2')

                conn.send(b'Command 2 executed successfully')
            else:
                print('Unknown command')
                conn.send(b'Unknown command')

        conn.close()

    main()