#pragma once

namespace IO {
	enum class TYPE : UINT8 {
		ACCEPT,
		CONNECT,
		DISCONNECT,
		SEND,
		RECV,
	};
}

class WSAOVERLAPPEDEX : public WSAOVERLAPPED
{
	

};

