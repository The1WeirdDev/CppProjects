#include <cstdio>
#include <iostream>
#include <deque>

#ifdef _WIN32
#define _WIN_WINNT 0x0A00
#endif

#define ASIO_STANDALONE

#include <asio.hpp>
#include <asio/ts/buffer.hpp>
#include <asio/ts/internet.hpp>
#include <asio/basic_streambuf.hpp>

#include <memory>
//Connection
/*
Client will connect
server will send client packet about the player
rest is history
*/

class TCPConnection {
public:
	std::deque<std::string> messages;
	std::array<char, 4096> read_buffer;

	~TCPConnection() {
	}
	asio::ip::tcp::socket socket;
	TCPConnection(asio::io_context* io_context) : socket(*io_context){
		
	}
	static std::shared_ptr<TCPConnection> Create(asio::io_context* io_context) {
		return std::make_shared<TCPConnection>(io_context);
	}
	asio::ip::tcp::socket* GetSocket() {
		return &socket;
	}
	
	void Write(const char* data) {
		try {
			messages.push_back(std::string(data));

			if(messages.size() < 2)
				AsyncWrite();
		}
		catch (std::exception e) {
			std::cout << e.what() << std::endl;
		}
	}

	void AsyncRead() {
		socket.async_read_some(asio::buffer(read_buffer, 1000), [this](const asio::error_code& error, size_t bytes_transferred) {
			if (error) {
				printf("Client disconnected\n");
			}

			else {
				std::stringstream message;
				for (int i = 0; i < bytes_transferred; i++) {
					std::cout << read_buffer[i] << std::endl;
				}


				AsyncRead();
			}
		});
	}

	void AsyncWrite() {
		asio::async_write(*GetSocket(), asio::buffer(messages.front()),
			[this](const asio::error_code& error, size_t bytes_transferred) {
				if (error) {
					printf("Error sending data\n");
				}
				else {
					printf("Sent %d bytes\n", (int)bytes_transferred);
				}

				messages.pop_front();

				if (messages.size() > 0)
					AsyncWrite();
			});
	}
};
class Server {
public:
	asio::io_context context;
	std::shared_ptr<asio::ip::tcp::acceptor> acceptor;

	std::vector<std::shared_ptr<TCPConnection>> connections;
	void Run() {
		try {
			int port = 8888;
			acceptor = std::make_shared<asio::ip::tcp::acceptor>(asio::ip::tcp::acceptor(context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port)));
			
			//NewClient();

			StartAcceptingClients();
			context.run();
		}
		catch (std::exception e) {

		}
	}

	void StartAcceptingClients() {

		//std::shared_ptr< asio::ip::tcp::socket> socket = std::make_shared< asio::ip::tcp::socket>(context);
		try {
		std::shared_ptr<TCPConnection> connection = TCPConnection::Create(&context);
		connections.push_back(connection);
		printf("Accepting Clients\n");

		acceptor->async_accept(*connection->GetSocket(), [connection, this](const asio::error_code& error) {
				if (error) {
					printf("Failed Accept Client\n");
				}
				else {
					printf("Accepted Client\n");

					connection->Write("Hello Client\n");
					connection->AsyncRead();
				}

				StartAcceptingClients();
			});


		}
		catch (std::exception e) {
			std::cout << e.what() << std::endl;
		}
	}
};

int main(int argc, char** argv) {
	Server server;
	server.Run();
}