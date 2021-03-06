// IsDebuggerPresentTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <stdio.h>

BOOL isDebuggerPresent();

BOOL isDebuggerPresent()
{
	BOOL result = FALSE;
	HINSTANCE kern_lib = LoadLibraryEx(L"kernel32.dll", NULL, 0);
	if (kern_lib) {
		FARPROC lIsDebuggerPresent = GetProcAddress(kern_lib, "IsDebuggerPresent");
		if (lIsDebuggerPresent && lIsDebuggerPresent()) {
			result = TRUE;
		}
		FreeLibrary(kern_lib);
	}
	return result;
}

int main ()
{
	if (isDebuggerPresent())
	{
		MessageBox(GetForegroundWindow(), L"Debugger detected!\nStop debugging me now!", L"HELP!", MB_ICONSTOP);
	}
	else
	{
		MessageBox(GetForegroundWindow(), L"Yay!! No debugger here!", L":)", MB_OK);
	}
	return 0;
}


