#pragma once
#include "pch.h"


/****************************************************************************/
/* PSIM Parameter */
/****************************************************************************/

extern double OscFreq;
extern double Tsamp;
extern double CarrierFreq; 
extern int Tcratio; 
extern int Tccnt; 
extern double Tcsamp; 


// Vabc Para
extern double Van, Vbn, Vcn;


// SCR_Ctrl_Para
extern int SCRGating1, SCRGating2, SCRGating3, SCRGating4;
extern int gating, gating1;

// Buck Para
extern double Err_Vout1, Vout1_ref, Vout1;
extern double Pctl_Vbk, Kp_Vbk;
extern double Ictl_Vbk_integ, Ki_Vbk;
extern double Vout1_buck_ref, Vout1_buck_duty, Vdc_sys;



// PFC Parameters
// Define following variables as "static" in order to retain their value.... At first time, this para was static double.. 
extern double yv;
extern double yi;
extern double uv;
extern double ui;
extern double iref;
extern int count;
extern int Ncount;
extern int flagSample;
extern int npulse;
extern int npulse_next;
extern int gating;

extern double Voref, Vcarr, Vi, iL, Vo, Vm;
extern double errv, erri; 






extern int A001;
extern int A002;
extern int A003;
extern int A004;
extern int A005;





