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

class OverEx : public WSAOVERLAPPED
{
	

};

