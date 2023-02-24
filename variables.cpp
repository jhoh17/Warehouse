#include "pch.h"
#include "functions.h"
#include "variables.h"





/****************************************************************************/
/* PSIM Parameter */
/****************************************************************************/
double OSCFreq = 100.0e6;					// Psim System Clock : 100MHz 
double PWMFreq = 100.0e3;					// PWM Frequency : 100kHz 
double PWMPRD = 1. / PWMFreq;				// PWM, carrier period : 10usec(100kHz)
double Tsamp = 100.0e-6;					// 100usec sampling period 
int MLPRD_ratio = (int)(Tsamp / PWMPRD);	// Main Loop period 
int MLCNT = 0;								// Main Loop Count 

/****************************************************************************/


// Vabcn Para
float Van = 0., Vbn = 0., Vcn = 0.; 
float VanPre = 0., VbnPre = 0., VcnPre = 0.;



// SCR_Ctrl_Para
int SCR1_Gating = 0, SCR2_Gating = 0, SCR3_Gating = 0, SCR_Gating4 = 0;
int SCR_Cnt = 0, SCR1_Cnt = 0, SCR2_Cnt = 0, SCR3_Cnt = 0; 
int	SCR_Ontime = 5, SCR1_Ontime = 5, SCR2_Ontime = 5, SCR3_Ontime = 5; 
int Van_Flag = 0, Vbn_Flag = 0, Vcn_Flag = 0;
int gating = 0, gating1 = 0;
float Van_SCR_trig = 250.; 


// Buck Para
float Err_Vout1 = 0., Vout1_ref = 40., Vout1 = 0.;
float Pctl_Vbk = 0., Kp_Vbk = 0.1;
float Ictl_Vbk_integ = 0., Ki_Vbk = 100.0;
float Vout1_buck_ref = 0., Vout1_buck_duty = 0., Vdc_sys = 0.;


// PFC Parameters
// Define following variables as "static" in order to retain their value.... At first time, this para was static double.. 
float yv = 0.0;
float yi = 0.0;
float uv = 0.0;
float ui = 0.0;
float iref = 0.0;
int count = 0;
int Ncount = 0;
int flagSample = 1;
int npulse = 0;
int npulse_next = 0;


float Voref = 10.5, Vcarr = 10., Vi, iL, Vo, Vm;
float errv, erri;


int A001 = 1;
int A002 = 2;
int A003 = 3;
int A004 = 4;
int A005 = 5;


// Temparay
float a1 = 0., b1 = 0., temp1 = 0., Ptemp1 = 0., Itemp1 = 0.;

/* Angle Detection */
float zeta = 1.;
float Wn = 200.0;
float Em = 179.62924;//220Vrms
float Wc_pll = 200.;
float zeta_pll = 1.;
float Kp_pll = 0.;
float Ki_pll = 0.;
float Ki_pll_angleT = 0.;
float Ki_pll_angle = 0.;
float Err_Ede_pll = 0.;
float Ede_pll_ref_integ = 0.;
float Ede_pll_ref_fb = 0.;
float West = 0.;
float Wrated = 376.9911;


/* SRF_PLL */
float EdseP_L = 0., EdseP_old = 0., EqseP_L = 0., EqseP_old = 0.;







/****************************************************************************/

/* Input Voltages */
float Eab = 0., Ebc = 0., Eca = 0.;
float Ea = 0., Eb = 0., Ec = 0., Eds = 0., Eqs = 0., Ede = 0., Eqe = 0.;


/* Angle Detection */
float Kp_angle = 0.002, Ki_angle = 0.5, Ki_angleT = 0.;
float Err_Ede = 0., angle_integ = 0., Del_angle = 0., angle = 0.;
float sin_angle = 0., cos_angle = 0.;

/* Low-pass Filter(Ede, Eqe) */
float La_Ee = 0., Lb_Ee = 0., Wc_Ee = 60.;
float Ede_L = 0., Eqe_L = 0., Ede_old = 0., Eqe_old = 0.;





