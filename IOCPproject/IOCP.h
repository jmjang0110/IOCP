#pragma once


struct CompletionInfo {
	LONG64 key;
	DWORD bytes;
	BOOL success;
	WSAOVERLAPPED* overEx;
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


};

