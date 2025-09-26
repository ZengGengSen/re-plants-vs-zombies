#ifndef __NETWORKMANAGER_H__
#define __NETWORKMANAGER_H__

#include "Common.h"

namespace Sexy
{

class NetworkManager
{
public:
	enum ConnectionStatus
	{
		CONNECTION_UNKNOWN,
		CONNECTION_OFFLINE,
		CONNECTION_CONNECTED,
		CONNECTION_ERROR
	};

private:
	ConnectionStatus		mConnectionStatus;
	ulong					mLastCheckTime;
	static const ulong		CHECK_INTERVAL = 30000; // 30 seconds

	void					UpdateConnectionStatus();

public:
	NetworkManager();
	virtual ~NetworkManager();

	void					Update();
	ConnectionStatus		GetConnectionStatus();
	bool					IsConnected();
	void					ForceCheck();
};

};

#endif //__NETWORKMANAGER_H__