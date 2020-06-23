#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<process.h>
#include<dos.h>
#include<math.h>

void fill(int x,int y,int newc,int oldc);
void fillt(int x,int y,int newc,int oldc);
void bFill(int ,int ,int ,int);
int check_touch(int x , int y, int r);
void exiter();

void liner();
void spiker();

void main()
{
int gd,gm;
int a,j,b,i,ch,st;
  detectgraph(&gd,&gm);
  initgraph(&gd,&gm,"c:\\turboc3\\bgi");
  setfillstyle(9 ,4);
  setbkcolor(7);
  outtextxy(230,100,"WELCOME TO BOUNCING BALL");
  outtextxy(230,130,"Press space to start game");
  outtextxy(180,200,"CONTROLS::");
  outtextxy(180,230,"Space :\t To Jump");
  outtextxy(180,260,"Ctrl+x:\t To Exit Game");
  st = getch();
 if(st == 32)
  {
	do
	{
	for(i=1;i<=600;i++)
		{
			//setbkcolor(7);
			setcolor(15);
			circle(30+i,380,20);
			//fill(31+i,381,4,0);
			//bFill(31+i,381,4,15);
			floodfill(31+i,381,15);
			delay(10);
			cleardevice();
			outtextxy(230,130,"Press space to Jump");
			setcolor(2);
		       //	line(0,400,630,400);
		       liner();
		       spiker();

		       /*	line(140,370,120,400);
			line(160,400,140,370);
			//setbkcolor(9);
			line(340,370,320,400);
			line(360,400,340,370);
			line(440,370,420,400);
			line(460,400,440,370);*/


			if(kbhit())
			{
				ch=getch();
				if(ch==32)
				{
					for(j=0;j<=50;j++,i++)
					{
						cleardevice();
						setcolor(2);
					       /*	line(140,370,120,400);
						line(160,400,140,370);
						//setbkcolor(9);
						line(340,370,320,400);
						line(360,400,340,370);
						line(440,370,420,400);
						line(460,400,440,370);

						line(0,400,630,400);*/
						spiker();
						liner();


						a=380-j;
						setcolor(15);
						outtextxy(230,130,"Press space to Jump");
						circle(30+i,a,20);
					       /*	if(check_touch(30+i,a,20)==0)
						   exit(0); */
						//bFill(31+i,a,4,15);
						floodfill(31+i,a,15);
						b=30+i;

						delay(10);
						if(check_touch(30+i,a,20)==0)
						  exiter();
					}
					for(j=0;j<=50;j++,i++)
					{
						cleardevice();
						setcolor(2);
						/*line(140,370,120,400);
						line(160,400,140,370);
						//setbkcolor(9);
						line(340,370,320,400);
						line(360,400,340,370);
						line(440,370,420,400);
						line(460,400,440,370);

						line(0,400,630,400);*/
						spiker();
						liner();
						setcolor(15);
						outtextxy(230,130,"Press space to Jump");
						circle(b+j,a+j,20);
						//bFill(b+j,a+j,4,15);
						floodfill(b+j,a+j,15);
						delay(10);
						if(check_touch(30+i,a,20)==0)
						  exiter();
					}
				}
				else if(ch == 24)
					exit(0);
			}
		}
	 }while(ch!=24);
	}
	 else if(st == 24)
		exit(0);
getch();
closegraph();
}


void fill(int x,int y,int newc,int oldc)
{
int c;
c=getpixel(x,y);
if(c==oldc)
	{
		setcolor(newc);
		putpixel(x,y,newc);
		fill(x+1,y,newc,oldc);
		fill(x,y+1,newc,oldc);
		fill(x-1,y,newc,oldc);
		fill(x,y-1,newc,oldc);
	}
}
void fillt(int x,int y,int newc,int oldc)
{
int c;
c=getpixel(x,y);
	if(c==oldc)
	{
		setcolor(newc);
		putpixel(x,y,newc);
		fillt(x-1,y,newc,oldc);
		fillt(x+1,y,newc,oldc);
		fillt(x,y-1,newc,oldc);
		fillt(x,y+1,newc,oldc);
		fillt(x+1,y+1,newc,oldc);
		fillt(x-1,y+1,newc,oldc);
		fillt(x-1,y-1,newc,oldc);
		fillt(x+1,y-1,newc,oldc);
	}
}


void bFill(int x,int y,int newc,int boundc)
{
	if(getpixel(x,y) != boundc && getpixel(x,y) != newc)
	{
		putpixel(x,y,newc);
		bFill(x+1,y,newc,boundc);
		bFill(x,y+1,newc,boundc);
		bFill(x-1,y,newc,boundc);
		bFill(x,y-1,newc,boundc);
	}
}

void liner()
 {
line(0,400,630,400);
}

void spiker()
{
rectangle(140,370,160,400);
rectangle(340,370,360,400);
rectangle(390,370,400,400);
  }



int check_touch(int x, int y, int r)
 {
  if( (x+r>=140 && x+r<=160) && (y+r>=370 && y+r<=400))
    return 0 ;
 else if( (x+r>=140 && x+r<=160) && (y+r>=370 && y+r<=400))
    return 0;
 else if( (x+r>=390 && x+r<=400) && (y+r>=370 && y+r<=400))
    return 0;
 else
   return 1;
}


void exiter()
 {
 //outtextxy(230,130,"end game")
 outtextxy(300,200,"end game press enter to continue");
 getch();
 exit(0);
}



/*int cof_a=1,cof_b,cof_c;
void create_eq(int x1, int y1, int x2, int y2)
 {
  float m;
  m =  (x2-x1)/(y2-y1);
  cof_b = -1*m;
  cof_c = x1-y1;
}

int check_touch(int x, int y, int r)
 {
 float c,d,e;
 create_eq(140,370,120,400)
 c = cof_a*x+cof_b*y+cof_c;
 e = sqrt(pow(cof_a,2)+pow(cof_b,2));
 d = c/e;

 //create_eqn(140,370,120,400);

 if(d < 0)
 d = d * -1;

 if(d==r || d<r)
 return 0;
 else
 return 1;

  }*/