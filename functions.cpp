#include "pch.h"
#include "variables.h"
#include "functions.h"
#include <math.h>



/*--------------------------------------*/
/*	 Arctangent				            */
/*--------------------------------------*/
int ATAN_ADDR;
float ATAN_FUN(float y, float x)
{
	float th;

	x += 1.e-38;

	if (y < x)
	{
		if (y > -x)
		{
			if (y > 0.)	th = *(float*)(ATAN_ADDR + (int)(y / x * ATAN_NUM));				// section 1
			else		th = -*(float*)(ATAN_ADDR + (int)(-y / x * ATAN_NUM));			// section 8
		}
		else
		{
			if (x > 0.)	th = -0.5 * FPI + *(float*)(ATAN_ADDR + (int)(-x / y * ATAN_NUM));	// section 7
			else		th = -0.5 * FPI - *(float*)(ATAN_ADDR + (int)(x / y * ATAN_NUM));		// section 6
		}
	}
	else
	{
		if (y > -x)
		{
			if (x > 0.)	th = 0.5 * FPI - *(float*)(ATAN_ADDR + (int)(x / y * ATAN_NUM));		// section 2
			else		th = 0.5 * FPI + *(float*)(ATAN_ADDR + (int)(-x / y * ATAN_NUM));		// section 3
		}
		else
		{
			if (y > 0.)	th = FPI - *(float*)(ATAN_ADDR + (int)(-y / x * ATAN_NUM));			// section 4
			else		th = -FPI + *(float*)(ATAN_ADDR + (int)(y / x * ATAN_NUM));			// section 5
		}
	}

	return th;
}




int hap01(int x, int y)
{
	int z;

	z = x + y;
	return z;
}



int hapLimit01(int x, int y)
{
	static int z = 1;

	z = z++;
	if (z > 1000) z = 0;
	return z;
}



















