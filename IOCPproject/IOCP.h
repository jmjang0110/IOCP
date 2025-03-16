#pragma once

/*
------------------------
		 IOCP
		  |
		Server 
		Client
------------------------
*/


class OverlappedEx;

struct CompletionInfo {
	WSAOVERLAPPED* overEx;
	LONG64			key;
	DWORD			bytes;
	BOOL			success;
};

class IOCP
{
private:
	HANDLE		m_IOCPhandle{};
	SOCKADDR_IN m_SockAddr{};

public:
	IOCP();
	~IOCP();

public:
	virtual bool Start(std::wstring ip, UINT16 port);
	virtual bool Close();

public:
	// GetQueuedCompletionStatus
	void GQCS(CompletionInfo& info, UINT32 msTimeout);
};

