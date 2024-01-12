#include "TCPClient.h"

#include <string>
#include <iostream>


void TCPClient::Connect() {
	asio::error_code ec;

	// Get the address of somewhere
	asio::ip::tcp::endpoint endpoint(asio::ip::make_address("127.0.0.1", ec), 8888);

	// Create a socket
	asio::ip::tcp::socket socket(context);

	socket.connect(endpoint, ec);

	if(!ec) {
		std::cout << "Connected" << std::endl;
	}
	else {
		std::cout << "Failed to connect " << ec.message() << std::endl;
	}

	if (socket.is_open()) {
		socket.wait(socket.wait_read);

		size_t bytes = socket.available();
		std::cout << "Bytes Available " << bytes << std::endl;

		if (bytes > 0) {
			std::vector<char> vBuffer(bytes);
			socket.read_some(asio::buffer(vBuffer.data(), vBuffer.size()), ec);

			for (auto c : vBuffer) {
				std::cout << c;
			}
		}
		socket.wait(socket.wait_read);

		bytes = socket.available();
		std::cout << "Bytes Available " << bytes << std::endl;

		if (bytes > 0) {
			std::vector<char> vBuffer(bytes);
			socket.read_some(asio::buffer(vBuffer.data(), vBuffer.size()), ec);

			for (auto c : vBuffer) {
				std::cout << c;
			}
		}
		socket.shutdown(socket.shutdown_both);
		socket.close();
		context.stop();
	}

	/*
	using boost::asio::ip::tcp;
	boost::asio::io_service io_service;
	//tcp::socket socket(io_service);
	socket = new boost::asio::ip::tcp::socket(io_service);

	boost::system::error_code ec;
	socket->connect(tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 8888), ec);

	if (ec) {
		printf("Unable to connect to server\n");
		return;
	}
	SendPacket();
	Read();

	

	delete socket;
	*/
}

void TCPClient::Read() {
	/*
	boost::system::error_code error;
	boost::asio::streambuf receive_buffer;

	boost::asio::read(*socket, receive_buffer, boost::asio::transfer_all(), error);
	if (error && error != boost::asio::error::eof) {
		std::cout << "receive failed: " << error.message() << std::endl;
	}
	else {
		const char* data = boost::asio::buffer_cast<const char*>(receive_buffer.data());
		std::cout << data << std::endl;
		Read();
		
	}*/
}

void TCPClient::SendPacket() {
	/*
	std::string msg = "HELLO WORLD\n";
	boost::system::error_code error;
	boost::asio::write(*socket, boost::asio::buffer(msg), error);
	if (!error) {
		printf("Sent Data\n");
	}
	else {
		printf("Error sending data\n");
	}
	*/
}