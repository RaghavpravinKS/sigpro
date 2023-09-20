import socket

# Define the server host and port
host = '10.7.61.104'  # Replace with your server's IP address
port = 25000  # Choose a port number

# Create a socket object
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Bind the socket to the host and port
server_socket.bind((host, port))

# Listen for incoming connections
server_socket.listen(1)

print(f"Listening on {host}:{port}")

# Accept a connection from a client
client_socket, client_address = server_socket.accept()
print(f"Connection from {client_address}")

while True:
    # Receive data from the client
    data = client_socket.recv(1024)
    
    if not data:
        break
    
    print(f"Received data: {data}")

# Close the sockets
client_socket.close()
server_socket.close()
