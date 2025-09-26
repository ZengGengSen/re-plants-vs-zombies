#include "NetworkManager.h"
#include <winsock.h>
#include <wininet.h>

using namespace Sexy;

NetworkManager::NetworkManager()
{
	mConnectionStatus = CONNECTION_UNKNOWN;
	mLastCheckTime = 0;
}

NetworkManager::~NetworkManager()
{
}

void NetworkManager::UpdateConnectionStatus()
{
	// Simple connectivity check using WinINet
	DWORD dwFlags;
	if (InternetGetConnectedState(&dwFlags, 0))
	{
		mConnectionStatus = CONNECTION_CONNECTED;
	}
	else
	{
		mConnectionStatus = CONNECTION_OFFLINE;
	}
	
	mLastCheckTime = GetTickCount();
}

void NetworkManager::Update()
{
	ulong aCurrentTime = GetTickCount();
	
	// Check connection status periodically
	if (mConnectionStatus == CONNECTION_UNKNOWN || 
		(aCurrentTime - mLastCheckTime > CHECK_INTERVAL))
	{
		UpdateConnectionStatus();
	}
}

NetworkManager::ConnectionStatus NetworkManager::GetConnectionStatus()
{
	return mConnectionStatus;
}

bool NetworkManager::IsConnected()
{
	return mConnectionStatus == CONNECTION_CONNECTED;
}

void NetworkManager::ForceCheck()
{
	UpdateConnectionStatus();
}