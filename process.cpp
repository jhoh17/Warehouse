#include "pch.h"
#include "Variables.h"
#include "Functions.h"
#include <math.h>

void func_buck(); 
void func_1scr_ctrl();
void func_4scr_ctrl(); 

void loop()
{
	// func_1scr_ctrl();
	func_4scr_ctrl(); 
	// func_buck();  

}









/****************************************************************************/
void func_1scr_ctrl()
{
	if (Van > 200)
	{
		gating1 = 1;
	}
	else
	{
		gating1 = 0; 
	}
}


void func_4scr_ctrl()
{
	if (Van > 200)
	{
		SCRGating1 = 1;
		SCRGating2 = 0;
		SCRGating3 = 0;
		SCRGating4 = 1;
	}
	else
	{
		SCRGating1 = 0;
		SCRGating2 = 1;
		SCRGating3 = 1;
		SCRGating4 = 0;
	}
}





void func_buck()
{
	Err_Vout1 = Vout1_ref - Vout1;
	Pctl_Vbk = Kp_Vbk * Err_Vout1;
	Ictl_Vbk_integ += Ki_Vbk * Err_Vout1 * Tcsamp;
	Vout1_buck_ref = Pctl_Vbk + Ictl_Vbk_integ;

	Vout1_buck_duty = Vout1_buck_ref / Vdc_sys;
	npulse_next = Ncount * Vout1_buck_duty;
}







/****************************************************************************/



	/***********************/
	/* Output Parameter */
	/***********************/


/****************************************************************************/














