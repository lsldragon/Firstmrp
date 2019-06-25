#include <base.h>

int init(void)
{
	cls(0,0,0);
	drect(10,10,30,50,255,249,0);
	dline(30,30,80,80,255,0,0);
	dpointex(100,100,0,255,0);
	ref(0,0,SCRW,SCRH);
    return 0;
}

int event(int type, int p1, int p2)
{
    if(KY_DOWN == type)
    {
        switch(p1)
        {
        case _SRIGHT:
            exit();
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