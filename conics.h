#include <graphics.h>
#ifndef CONICS_H_INCLUDED
#define CONICS_H_INCLUDED




void ellipsevert(int x1, int y1, int a, int b, int color)
{
    int x,y;
    double d;

    x = 0;
    y = b;
    d = (b*b) + (0.25*a*a) - (a*a*b);

    plotellipse(y, x, x1, y1, color);
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
        plotellipse(y, x, x1, y1, color);
    }

    d = (b*b*(x + 0.5)*(x + 0.5)) + (a*a*(y-1)*(y-1)) - (a*a*b*b);

    plotellipse(y, x, x1, y1, color);
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
        plotellipse(y, x, x1, y1, color);
    }
}

#endif // CONICS_H_INCLUDED
