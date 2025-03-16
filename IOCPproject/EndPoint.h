#pragma once


class EndPoint
{
private:
	static const short  PORT_ANY = 0;
	sockaddr_in			m_Address;

public:
	EndPoint() = default;
	EndPoint(const std::string& ip, u_short port);
	EndPoint(const sockaddr_in& addr);
	~EndPoint();

public:
	std::string GetIPAddress() const;
	u_short		GetPortNum() const;

public:
	// static 
	static std::string	GetIPAddress(const sockaddr_in& sockaddr);
	static u_short		GetPortNum(const sockaddr_in& sockaddr);
	static EndPoint		Any(u_short port);

};

