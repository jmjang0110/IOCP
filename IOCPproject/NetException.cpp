#include "pch.h"
#include "NetException.h"

NetException::NetException(const std::string& info)
{
    LPSTR msgBuffer{};

    int errCode = ::WSAGetLastError();
    // ���� �ڵ忡 �ش��ϴ� �޽��� 
    size_t size = ::FormatMessageA(
                         FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM
                        ,NULL
                        ,errCode
                        ,MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT)
                        ,(LPSTR)&msgBuffer
                        , 0
                        , NULL);

    // ���� �޽��� ���� ! 
    m_ErrorMsg = "[" + std::to_string(errCode) + "] " + info + " : " + msgBuffer + "\n";
    ::LocalFree(msgBuffer);

}

NetException::~NetException()
{
}

const char* NetException::what() const
{
    return m_ErrorMsg.c_str();
}
