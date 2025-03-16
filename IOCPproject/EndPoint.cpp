#include "pch.h"
#include "EndPoint.h"

EndPoint::EndPoint(const std::string& ip, u_short port)
{
	m_Address.sin_family = AF_INET;
	m_Address.sin_port = ::htons(port);
	inet_pton(AF_INET, ip.c_str(), &m_Address.sin_addr);
}

EndPoint::EndPoint(const sockaddr_in& addr)
{
	m_Address = addr;
}

EndPoint::~EndPoint()
{
	
}

std::string EndPoint::GetIPAddress() const
{
	return EndPoint::GetIPAddress(m_Address);
}

u_short EndPoint::GetPortNum() const
{
	return EndPoint::GetPortNum(m_Address);
}


// -------------- static ------------------
std::string EndPoint::GetIPAddress(const sockaddr_in& sockaddr)
{
	// internet network to presentation 
	// -> binary format 바이트 순서 -> 사람이 읽을 수 있는 문자열 형태로 변환 
	const int	MAX_IPV4_LEN = 256;
	char		ip[MAX_IPV4_LEN]{};
	auto		p = ::inet_ntop(AF_INET, &sockaddr.sin_addr, ip, MAX_IPV4_LEN);

	if (p == nullptr)
		return "wrong socket name!";
	return std::string(ip);
}

u_short EndPoint::GetPortNum(const sockaddr_in& sockaddr)
{
	return ::ntohs(sockaddr.sin_port); // network to host short - 호스트 시스템 바이트 순서에 맞게 변환 
}

EndPoint EndPoint::Any(u_short port)
{
	EndPoint ep{};
	ep.m_Address.sin_family      = AF_INET;				// IPv4
	ep.m_Address.sin_port        = ::htons(port);		// 지정 포트번호에 대해 연결을 수신하도록 하자!
	ep.m_Address.sin_addr.s_addr = ::htonl(INADDR_ANY); // 모든 네트워크 인터페이스에서 연결을 받자!
	return ep;
}
