#include <base.h>

int32 timer;

int init(void)
{
	startTimer();
        return 0;
}

void startTimer()
{
	timer = timercreate();
	timerstart(timer,1000,1234,"timer0",1);
}

void timer0(int data)
{
	int x1pos = rand()%240 ;
	int x2pos = rand()%240;
	int y1pos = rand()%320 ;
	int y2pos = rand()%320;

	int r = rand()%255;
	int g = rand()%255;
	int b = rand()%255 ;

	dline(x1pos,y1pos,x2pos,y2pos,r,g,b);
	ref(0,0,SCRW,SCRH);
}

int event(int type, int p1, int p2)
{
    if(KY_DOWN == type)
    {
        switch(p1)
        {
        case _SRIGHT:
            exitapp();
            break;
        case _1:
            break;
        }
    }

    return 0;
}

int pause(void)
{
    return 0;
}

int resume(void)
{
    return 0;
}

int exitapp(void)
{
	timerdel(timer);
	exit();
	return 0 ;
}
