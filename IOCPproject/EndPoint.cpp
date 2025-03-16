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
	// -> binary format ����Ʈ ���� -> ����� ���� �� �ִ� ���ڿ� ���·� ��ȯ 
	const int	MAX_IPV4_LEN = 256;
	char		ip[MAX_IPV4_LEN]{};
	auto		p = ::inet_ntop(AF_INET, &sockaddr.sin_addr, ip, MAX_IPV4_LEN);

	if (p == nullptr)
		return "wrong socket name!";
	return std::string(ip);
}

u_short EndPoint::GetPortNum(const sockaddr_in& sockaddr)
{
	return ::ntohs(sockaddr.sin_port); // network to host short - ȣ��Ʈ �ý��� ����Ʈ ������ �°� ��ȯ 
}

EndPoint EndPoint::Any(u_short port)
{
	EndPoint ep{};
	ep.m_Address.sin_family      = AF_INET;				// IPv4
	ep.m_Address.sin_port        = ::htons(port);		// ���� ��Ʈ��ȣ�� ���� ������ �����ϵ��� ����!
	ep.m_Address.sin_addr.s_addr = ::htonl(INADDR_ANY); // ��� ��Ʈ��ũ �������̽����� ������ ����!
	return ep;
}
