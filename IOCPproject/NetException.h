#pragma once

#include <stdexcept>
class NetException : public std::exception
{
private:
	std::string m_ErrorMsg;

public:
	NetException(const std::string& info);
	virtual ~NetException();

	virtual const char* what() const override; // std::exception ���� ���ǵ� ���� �����Լ� 
		
};

