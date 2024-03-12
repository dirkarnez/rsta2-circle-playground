#include "kernel.h"
#include <circle/timer.h>
#include <assert.h>


#define GPIO_BUTTON	18	// connect a button between this GPIO and GND

static const char FromKernel[] = "kernel";

CKernel::CKernel (void)
:	m_Screen (m_Options.GetWidth (), m_Options.GetHeight ()),
	m_Timer (&m_Interrupt),
	m_Logger (m_Options.GetLogLevel (), &m_Timer),
	m_GPIOManager (&m_Interrupt),
	m_ButtonPin (GPIO_BUTTON, GPIOModeInputPullDown, &m_GPIOManager)
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

	if (bOK)
	{
		bOK = m_Interrupt.Initialize ();
	}

	if (bOK)
	{
		bOK = m_Timer.Initialize ();
	}

	if (bOK)
	{
		bOK = m_GPIOManager.Initialize ();
	}
	
	return bOK;
}

TShutdownMode CKernel::Run (void)
{
	//m_Logger.Write (FromKernel, LogNotice, "Compile time: " __DATE__ " " __TIME__);

	m_ButtonPin.ConnectInterrupt (InterruptHandler, this);
	m_ButtonPin.EnableInterrupt (GPIOInterruptOnRisingEdge);

	while (1)
	{
		u32 nNumber = m_Random.GetNumber () % 100; //0 到 4,294,967,295
		// static const char ScreenMsg[] = "Hello screen!\n";
		//m_Serial.Write (ScreenMsg, sizeof ScreenMsg-1);

		static const char SerialMsg[] = "in the loop!\n";
		m_Serial.Write (SerialMsg, sizeof SerialMsg-1);

		CString Source;
		Source.Format ("%u", nNumber);
		m_Serial.Write (Source, Source.GetLength());
		
		CTimer::SimpleMsDelay (1000);
		// char Buffer[100];
		// int nBytesRead = m_Serial.Read (Buffer, sizeof Buffer);
		// if (nBytesRead > 0)
		// {
		// 	m_Screen.Write (Buffer, nBytesRead);
		// }
	}
	
	m_ButtonPin.DisableInterrupt ();
	return ShutdownHalt;
}

void CKernel::InterruptHandler (void)
{
	static const char SerialMsg[] = "Hello UART!\n";
	m_Serial.Write (SerialMsg, sizeof SerialMsg-1);
}

void CKernel::InterruptHandler (void *pParam)
{
	CKernel *pThis = (CKernel *) pParam;
	pThis->InterruptHandler();
}
