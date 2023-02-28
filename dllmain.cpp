// dllmain.cpp : DLL 애플리케이션의 진입점을 정의합니다.
#include "pch.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

/****************************************************************************/
// This is a sample C program for Microsoft C/C++ 6.0.
// The generated DLL is to be linked to PSIM.

// To compile the program into DLL, you can open the workspace file "msvc_dll.dsw" 
// as provided.

// This sample program calculates the rms of a 60-Hz input in[0], and
// stores the output in out[0].

// Variables:
//      t: Time, passed from PSIM by value
//   delt: Time step, passed from PSIM by value
//     in: input array, passed from PSIM by reference
//    out: output array, sent back to PSIM (Note: the values of out[*] can
//         be modified in PSIM)

// The maximum length of the input and output array "in" and "out" is 30.

// Because we used static/global variables in this example, the DLL 
// can only be used once per schematic file.  



/****************************************************************************/
/* PSIM DLL MAIN */
/****************************************************************************/

#include "Variables.h"
#include "Functions.h"
#include "Process.h"
#include <math.h>

#define _USE_MATH_DEFINES
#include <cmath>


__declspec(dllexport) void simuser(double t, double delt, double* in, double* out)
{
	// delt : Psim time step
	// Tsamp : Sampling time(PWM Carrier Freq) 
	// Ncount : Psim internal PWM Samping Time equalized counts
	// Calculate the no. of count Tsamp in one period
	Ncount = Tsamp / delt;   

	// Check if the counter reaches the end of the period. If yes,
	// set the sampling flag to 1. 
	if (count == Ncount)
	{
		flagSample = 1;			// Reset the counter to 0.
		count = 0;  			// Update the on-time pulse width
		npulse = npulse_next;	// PWM Duty Calc   
	}



	// If the sampling flag is 1, sample the inputs and calculate the
	// on-time pulse width npulse.
	if (flagSample == 1)
	{
		flagSample = 0;			// Reset the sampling flag

		if (Tccnt == Tcratio)
		{
			Tccnt = 0; 
			/***********************/
			/* Input Parameter */
			/***********************/
			// Vdc_sys = in[0];
			Van = in[0]; 
			// iL = in[1];
			// Vout1 = in[2];





			/***********************/
			/* Main Loop */
			/***********************/
			loop();
		}
		Tccnt++; 
	}




	/***********************/
	/* Generate the switch gating signal */ 
	/***********************/	
	if (count <= npulse)
	{
		gating = 1;
	}
	else
	{
		gating = 0;
	}






	/***********************/
	/* Output Parameter */ 
	/***********************/
	out[0] = gating;
	out[1] = SCRGating1;
	out[2] = SCRGating2;
	out[3] = SCRGating3;
	out[4] = SCRGating4;

	out[5] = npulse;
	out[6] = gating;
	out[7] = iref;
	out[8] = npulse;
	out[9] = gating;

	out[10] = iref;
	out[11] = npulse;
	out[12] = gating;
	out[13] = iref;
	out[14] = npulse;

	out[15] = Van;
	out[16] = SCRGating1;
	out[17] = SCRGating2;
	out[18] = A004;
	out[19] = FPI;

	out[20] = Vout1;
	out[21] = Vdc_sys;
	out[22] = Tccnt;
	out[23] = Tsamp;
	out[24] = Tcsamp;

	// Increment the counter by 1
	count++;
}

/****************************************************************************/




