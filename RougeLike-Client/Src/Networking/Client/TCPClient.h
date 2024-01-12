#pragma once

#include <asio.hpp>
#include <asio/ts/buffer.hpp>
#include <asio/ts/internet.hpp>

class TCPClient{
public:
	void Connect();

	void Read();
	void SendPacket();
private:
	asio::io_context context;
};