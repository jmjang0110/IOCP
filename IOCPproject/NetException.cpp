#include "pch.h"
#include "NetException.h"

NetException::NetException(const std::string& info)
{
    LPSTR msgBuffer{};

    int errCode = ::WSAGetLastError();
    // 오류 코드에 해당하는 메시지 
    size_t size = ::FormatMessageA(
                         FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM
                        ,NULL
                        ,errCode
                        ,MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT)
                        ,(LPSTR)&msgBuffer
                        , 0
                        , NULL);

    // 에러 메시지 저장 ! 
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
