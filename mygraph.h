#ifndef nvd
#define nvd

#include <math.h>

/*LINE ALGORITHMS*/
double findSlope(int x1, int y1, int x2, int y2)
{
	double slope = (double)(y2 - y1)/(x2 - x1);
	return slope;
}

void drawLine01(int x1, int y1, int x2, int y2, int color)
{
	int dx,dy,x,y,end,d;
	dy = abs(y2 - y1);
	dx = abs(x2 - x1);

	d = 2*dy-dx;

	if(x1 > x2)
	{
		x = x2;
		y = y2;
		end = x1;
	}
	else
	{
		x = x1;
		y = y1;
		end = x2;
	}
	putpixel(x,y,color);

	//Line Drawing
	while(x <= end)
	{
		if(d < 0)
			d += 2*dy;
		else
		{
			d += 2*(dy - dx);
			y++;
		}
		x++;
		putpixel(x,y,color);
	}
}

void drawLine10(int x1, int y1, int x2, int y2, int color)
{
	int dx,dy,x,y,end,d;
	dy = abs(y2 - y1);
	dx = abs(x2 - x1);

	d=2*dy-dx;

	if(x1 > x2)
	{
		x = x1;
		y = y1;
		end = x2;
	}
	else
	{
		x = x2;
		y = y2;
		end = x1;
	}

	putpixel(x,y,color);

	//Line Drawing
	while(x>=end)
	{
		if(d < 0)
			d += 2*dy;
		else
		{
			d += 2*(dy - dx);
			y++;
		}
		x--;
		putpixel(x,y,color);
	}
}


void drawLine1n(int x1, int y1, int x2, int y2, int color)
{
	int dx,dy,x,y,end,d;
	dy = abs(y2 - y1);
	dx = abs(x2 - x1);

	d=dy-2*dx;

	if(y1 > y2)
	{
		x = x2;
		y = y2;
		end = y1;
	}
	else
	{
		x = x1;
		y = y1;
		end = y2;
	}

	putpixel(x,y,color);

	//Line Drawing
	while(y <= end)
	{
		if(d < 0)
			d += 2*dx;
		else
		{
			d -= 2*(dy - dx);
			x++;
		}
		y++;
		putpixel(x,y,color);
	}
}

void drawLinen1(int x1, int y1, int x2, int y2, int color)
{
	int dx,dy,x,y,end,d;
	dy = abs(y2 - y1);
	dx = abs(x2 - x1);

	d=dy-2*dx;

	if(x1 > x2)
	{
		x = x1;
		y = y1;
		end = y2;
	}
	else
	{
		x = x2;
		y = y2;
		end = y1;
	}

	putpixel(x,y,color);

	//Line Drawing
	while(y <= end)
	{
		if(d < 0)
			d += 2*dx;
		else
		{
			d -= 2*(dy - dx);
			x--;
		}

		y++;
		putpixel(x,y,color);
	}
}

void myline(int x1, int y1, int x2, int y2, int color)
{
	double slope = findSlope(x1, y1, x2, y2);

	if(slope <= 1.0 && slope >= 0.0)
		drawLine01(x1, y1, x2, y2, color);
	else if(slope >= -1.0 && slope < 0.0)
		drawLine10(x1, y1, x2, y2, color);
	else if(slope > 1.0)
		drawLine1n(x1, y1, x2, y2, color);
	else
		drawLinen1(x1, y1, x2, y2, color);

}

/*CIRCLE ALGORITHMS*/
void plotcircle(int x, int y, int x1,int y1, int color)
{
    putpixel(x+x1, y+y1, color);
    putpixel(y+x1, x+y1, color);
    putpixel(-x+x1, y+y1, color);
    putpixel(y+x1, -x+y1, color);
    putpixel(x+x1, -y+y1, color);
    putpixel(-y+x1, x+y1, color);
    putpixel(-x+x1, -y+y1, color);
    putpixel(-y+x1, -x+y1, color);
}

//Circle Function using First Differential
void mycircle1(int x1, int y1, int r, int color)
{
    int d, x, y;

    x = 0;
    y = r;
    d = 1-r;

    plotcircle(x, y, x1, y1, color);
    while(x<=y)
    {
        if(d<=0)
            d+=2*x+3;
        else
        {
            d+=2*(x-y)+5;
            y--;
        }
        x++;
        plotcircle(x, y, x1, y1, color);
    }
}

//Circle Function using Second Differential
void mycircle2(int x1, int y1, int r, int color)
{
    int d, x, y, delE, delSE;

    x = 0;
    y = r;
    d = 1-r;
    delE = 3;
    delSE = 5-2*r;

    plotcircle(x, y, x1, y1, color);
    while(x<=y)
    {
        if(d<=0)
        {
            d+=delE;
            delE+=2;
            delSE+=2;
        }

        else
        {
            d+=delSE;
            delE+=2;
            delSE+=4;
            y--;
        }
        x++;
        plotcircle(x, y, x1, y1, color);
    }
}

/*ELLIPSE ALGORITHMS*/
void plotellipse(int x, int y, int x1, int y1, int color)
{
    putpixel(x+x1, y+y1, color);
    putpixel(-x+x1, y+y1, color);
    putpixel(x+x1, -y+y1, color);
    putpixel(-x+x1, -y+y1, color);
}

//Ellipse Function using First Differential
void myellipse1(int x1, int y1, int a, int b, int color)
{
    int x,y;
    double d;

    x = 0;
    y = b;
    d = (b*b) + (0.25*a*a) - (a*a*b);

    plotellipse(x, y, x1, y1, color);
    while((b*b*x) <= (a*a*y))
    {
        if(d<=0)
            d+=(b*b*(2*x+3));

        else
        {
            d+=(b*b*(2*x+3))+(2*a*a*(1-y));
            y--;
        }
        x++;
        plotellipse(x, y, x1, y1, color);
    }

    d = (b*b*(x + 0.5)*(x + 0.5)) + (a*a*(y-1)*(y-1)) - (a*a*b*b);

    plotellipse(x, y, x1, y1, color);
    while(y > 0)
    {
        if(d>=0)
            d+=a*a*(3-2*y);

        else
        {
            d+=(2*b*b*(1+x))+(a*a*(3-2*y));
            x++;
        }
        y--;
        plotellipse(x, y, x1, y1, color);
    }
}

//Ellipse Function using Second Differential
void myellipse2(int x1, int y1, int a, int b, int color)
{
    int x, y;
    double d, deltaE, deltaSE, deltaS;

    x = 0;
    y = b;
    d = (b*b)+(0.25*a*a)-(a*a*b);
    deltaE = 3*b*b;
    deltaSE = (3*b*b)+(2*a*a*(1-b));

    plotellipse(x, y, x1, y1, color);
    while((b*b*x) <= (a*a*y))
    {
        if(d<=0)
        {
            d+=deltaE;
            deltaE+=2*b*b;
            deltaSE+=2*b*b;
        }

        else
        {
            d+=deltaSE;
            deltaE+=2*b*b;
            deltaSE+=2*(a*a+b*b);
            y--;
        }
        x++;
        plotellipse(x, y, x1, y1, color);
    }

    d = ((b*b*(x + 0.5)*(x + 0.5))+(a*a*(y-1)*(y-1))-(a*a*b*b));
    deltaS = (a*a)*(3-(2*y));
    deltaSE = ((a*a)*(3-(2*y))+(2*b*b*(x+1)));

    plotellipse(x, y, x1, y1, color);
    while(y>=0)
    {
        if(d>=0)
        {
            d+=deltaS;
            deltaS+=2*a*a;
            deltaSE+=2*a*a;
        }

        else
        {
            d+=deltaSE;
            deltaS+=2*a*a;
            deltaSE+=2*(a*a+b*b);
            x++;
        }
        y--;
        plotellipse(x, y, x1, y1, color);
    }
}

/*PARABOLA ALGORITHMS*/
//Plotparabola function
void plotparabola(int x, int y, int x1, int y1, int color)
{
    putpixel(x1+x, y1+y, color);
    putpixel(x1+x, y1-y, color);
}

//Parabola Function using First Differential
void myparabola1(int x1, int y1, int xmax, int p, int color)
{
    int x, y;
    double d;

    x = 0;
    y = 0;
    d = 1-p;

    plotparabola(x, y, x1, y1, color);
    while(y<=p && x<=xmax)
    {
        if(d<=0)
            d+=(3+2*y);
        else
        {
            d+=(3+2*y-2*p);
            x++;
        }
        y++;

        plotparabola(x, y, x1, y1, color);
    }

    d = (y + 0.5)*(y + 0.5) - 2*p*(x+1);
    plotparabola(x, y, x1, y1, color);

    while(x<=xmax)
    {
        if(d>=0)
            d+=-2*p;
        else
        {
            d+=-2*p+2+2*y;
            y++;
        }
        x++;
        plotparabola(x, y, x1, y1, color);
    }
}

#endif
