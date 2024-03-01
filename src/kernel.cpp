#include "kernel.h"
#include <circle/timer.h>
#include <assert.h>

static const char FromKernel[] = "kernel";

CKernel::CKernel (void)
:	m_Screen (m_Options.GetWidth (), m_Options.GetHeight ()),
	m_Logger (m_Options.GetLogLevel ())
{
	m_ActLED.Blink (5);	// show we are alive
}

CKernel::~CKernel (void)
{
}

boolean CKernel::Initialize (void)
{
	boolean bOK = TRUE;

	if (bOK)
	{
		bOK = m_Screen.Initialize ();
	}
	
	if (bOK)
	{
		bOK = m_Serial.Initialize (115200);
	}
	
	if (bOK)
	{
		CDevice *pTarget = m_DeviceNameService.GetDevice (m_Options.GetLogDevice (), FALSE);
		if (pTarget == 0)
		{
			pTarget = &m_Screen;
		}

		bOK = m_Logger.Initialize (pTarget);
	}
	
	return bOK;
}

TShutdownMode CKernel::Run (void)
{
	m_Logger.Write (FromKernel, LogNotice, "Compile time: " __DATE__ " " __TIME__);

	while (1)
	{
		static const char ScreenMsg[] = "Hello screen!\n";
		m_Screen.Write (ScreenMsg, sizeof ScreenMsg-1);

		static const char SerialMsg[] = "Hello UART!\n";
		m_Serial.Write (SerialMsg, sizeof SerialMsg-1);

		char Buffer[100];
		int nBytesRead = m_Serial.Read (Buffer, sizeof Buffer);
		if (nBytesRead > 0)
		{
			m_Screen.Write (Buffer, nBytesRead);
		}

		CTimer::SimpleMsDelay (1000);
	}

	return ShutdownHalt;
}