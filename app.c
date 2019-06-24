#include <base.h>
#include "sound.h"

#define FILENAME "1.mp3"
#define _MP3 3

int r ; 
int g ; 
int b ; 

int ypos; 

int32 timer;
int32 timer2 ;
int32 timer3 ;
int32 timer4 ;

int init(void)
{
	startTimer();
	
	return 0 ;
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

	return 0 ;
}

void startTimer()
{
	timer = timercreate();
	timer2 = timercreate();
	timer3 = timercreate();
	timer4 = timercreate();

	timerstart(timer,1000,1234,"timer0",1);
	timerstart(timer2,3000,4578,"timer1",0);
	timerstart(timer3,10,5487,"timer22",1);
	timerstart(timer4,3,4878,"timer33",1);
}

void timer0(int data)
{
	drawString();
}

void timer1(int data)
{
	sing();
}

void timer22(int data)
{
	drawline();
}

void timer33()
{
	drawpoint();
}

void drawpoint()
{
	int xpos = rand()%240 ;
	int ypos = rand()%320 ;
	int r = rand()%255;
	int g = rand()%255;
	int b = rand()%255 ;

	dpointex(xpos, ypos, r,g,b);
	ref(0,0,SCRW,SCRH);
}

void drawline()
{
	int x1pos = 120;
	int x2pos = rand()%240;
	int y1pos = 160 ;
	int y2pos = rand()%320;

	int r = rand()%255;
	int g = rand()%255;
	int b = rand()%255 ;

	dline(x1pos,y1pos,x2pos,y2pos,r,g,b);
	ref(0,0,SCRW,SCRH);
}
// sing a song 
void sing()
{
	if(soundinit(_MP3))
	{
		dtext("不支持",0,0,255,255,255,FALSE,1);
	}
	else
	{
		soundloadfile(_MP3,FILENAME);
	    soundplay(_MP3,0,FALSE);
	}
	
}

// Draw Strings
void drawString()
{
	r = rand()%255 ;
	g =rand() % 255;
	b = rand()% 255 ;
	ypos = rand()%320 ;

    cls(0,0,0);
	dtext("李双龙的第一个MRP程序",0,ypos,r,g,b,0,0);
	ref(0,0,SCRW,SCRH);
}

int pause(void)
{
	return 0 ;
}

int resume(void)
{
	return 0 ;
}

int exitapp(void)
{
	timerdel(timer);
	timerdel(timer2);
	timerdel(timer3);
	timerdel(timer4);
	soundstop(_MP3);
	soundclose(_MP3);
	exit();
	return 0 ;
}