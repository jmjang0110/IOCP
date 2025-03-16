#include "pch.h"
#include "IOCP.h"

IOCP::IOCP()
{
}

IOCP::~IOCP()
{
}

bool IOCP::Start(std::wstring ip, UINT16 port)
{
	return false;
}

bool IOCP::Close()
{
	return false;
}

void IOCP::GQCS(CompletionInfo& info, UINT32 msTimeout)
{
	info.success = ::GetQueuedCompletionStatus(m_IOCPhandle
											 , &info.bytes
											 , (PULONG_PTR)&info.key
											 , &info.overEx
											 , msTimeout);
}
