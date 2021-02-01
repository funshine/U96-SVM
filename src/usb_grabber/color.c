#include "color.h"

void rgb2yuyv(u8* p_yuv, int w, int h, u8 lR, u8 lG, u8 lB, u8 rR, u8 rG, u8 rB)
{
    int i=0, j=0;
    for(j=0;j<h;j++)
    {
		lR++;
		lG++;
		lB++;
    	rR++;
    	rG++;
    	rB++;
    	for(i=0;i<w;i+=4)
    	{
        	p_yuv[j*w*2+i+0] = RGB2Y(lR, lG, lB);
        	p_yuv[j*w*2+i+1] = RGB2U(lR, lG, lB);
        	p_yuv[j*w*2+i+2] = RGB2Y(lR, lG, lB);
        	p_yuv[j*w*2+i+3] = RGB2V(lR, lG, lB);

        	p_yuv[j*w*2+w+i+0] = RGB2Y(rR, rG, rB);
        	p_yuv[j*w*2+w+i+1] = RGB2U(rR, rG, rB);
        	p_yuv[j*w*2+w+i+2] = RGB2Y(rR, rG, rB);
        	p_yuv[j*w*2+w+i+3] = RGB2V(rR, rG, rB);
    	}
    }
}
