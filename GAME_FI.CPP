#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<time.h>
//#define UP 72;
//#define DOWN 80;
//#define RIGHT 77;
//#define LEFT 75;
//#define ENTER 13;
//#define ESC 27;

union REGS in,out;

void load_mouse_driver()
	{

	 out.x.cx=0;out.x.bx=0;
	 in.x.ax=1;
	 int86(0x33,&in,&out);

	 in.x.ax=7;
	 in.x.cx=0;
	 in.x.dx=639;
	 int86(0x33,&in,&out);
	 in.x.ax=8;
	 in.x.cx=0;
	 in.x.dx=479;
	 int86(0x33,&in,&out);


	}

void unload_mouse_driver()
	{
	 in.x.ax=2;
	 int86(0x33,&in,&out);

	}

struct mystruct
{
  int i;
  char ch[100];
}s[50],re[50];

void help(){

	int gd=DETECT,gm,xp4=150,yp4=300,xp5=150,yp5=350;

	initgraph(&gd,&gm,"C:/TC/bgi");

	setcolor(15);
	settextstyle(3,0,2);
	outtextxy(100,60,"HELP");

	setcolor(15);
	outtextxy(100,100,"-> / D");
	setcolor(LIGHTGRAY);
	outtextxy(230,100,"for Right-Move");
	setcolor(15);
	outtextxy(100,130,"<- / A");
	setcolor(LIGHTGRAY);
	outtextxy(230,130,"for Left-Move");
	setcolor(15);
	outtextxy(100,160,"P");
	setcolor(LIGHTGRAY);
	outtextxy(230,160,"for PAUSE");
	setcolor(15);
	outtextxy(100,190,"R");
	setcolor(LIGHTGRAY);
	outtextxy(230,190,"for RETRY");
	setcolor(15);
	outtextxy(100,220,"ENTER");
	setcolor(LIGHTGRAY);
	outtextxy(230,220,"for MENU");
	setcolor(15);
	outtextxy(100,250,"ESC");
	setcolor(LIGHTGRAY);
	outtextxy(230,250,"for Exit");
	setcolor(RED);
	line(xp4-30,yp4,xp4+30,yp4); //upper line of platform
	line(xp4-30,yp4+10,xp4+30,yp4+10); //down line  of platform
	line(xp4-30,yp4,xp4-30,yp4+10); //connector 1
	line(xp4-31,yp4+1,xp4-31,yp4+9);
	line(xp4-32,yp4+2,xp4-32,yp4+8);
	line(xp4-33,yp4+3,xp4-33,yp4+7);
	line(xp4-34,yp4+4,xp4-34,yp4+6);
	line(xp4+30,yp4,xp4+30,yp4+10); //connector 2
	line(xp4+31,yp4+1,xp4+31,yp4+9);
	line(xp4+32,yp4+2,xp4+32,yp4+8);
	line(xp4+33,yp4+3,xp4+33,yp4+7);
	line(xp4+34,yp4+4,xp4+34,yp4+6);
	arc(xp4-45,yp4,300,245,7);
	arc(xp4-45,yp4+8,135,40,4);
	line(xp4-34,yp4+11,xp4-52,yp4+25);
	line(xp4-57,yp4+11,xp4-38,yp4+25);
	circle(xp4-47,yp4-1,2);
	circle(xp4-43,yp4-1,2);
	arc(xp4+45,yp4,300,245,7);
	arc(xp4+45,yp4+8,135,40,4);
	line(xp4+34,yp4+11,xp4+52,yp4+25);
	line(xp4+57,yp4+11,xp4+38,yp4+25);
	circle(xp4+47,yp4-1,2);
	circle(xp4+43,yp4-1,2);
	setcolor(LIGHTGRAY);
	outtextxy(230,290,"Avoid This");

	setcolor(YELLOW);
	line(xp5-30,yp5,xp5+30,yp5); //upper line of platform
	line(xp5-30,yp5+10,xp5+30,yp5+10); //down line  of platform
	line(xp5-30,yp5,xp5-30,yp5+10); //connector 1
	line(xp5-31,yp5+1,xp5-31,yp5+9);
	line(xp5-32,yp5+2,xp5-32,yp5+8);
	line(xp5-33,yp5+3,xp5-33,yp5+7);
	line(xp5-34,yp5+4,xp5-34,yp5+6);
	line(xp5+30,yp5,xp5+30,yp5+10); //connector 2
	line(xp5+31,yp5+1,xp5+31,yp5+9);
	line(xp5+32,yp5+2,xp5+32,yp5+8);
	line(xp5+33,yp5+3,xp5+33,yp5+7);
	line(xp5+34,yp5+4,xp5+34,yp5+6);
	arc(xp5-40,yp5,0,270,5);
	arc(xp5-40,yp5+10,180,90,5);
	line(xp5-41,yp5-9,xp5-41,yp5+19);
	line(xp5-39,yp5-9,xp5-39,yp5+19);
	arc(xp5+40,yp5,0,270,5);
	arc(xp5+40,yp5+10,180,90,5);
	line(xp5+41,yp5-9,xp5+41,yp5+19);
	line(xp5+39,yp5-9,xp5+39,yp5+19);

	setcolor(LIGHTGRAY);
	outtextxy(230,340,"Jump on This For 100 Points Bonus");


	char ch=getch();
	//if(ch==27)	exit(0);
	cleardevice();
	//closegraph();

}


void credential(){

	int gd=DETECT,gm;

	initgraph(&gd,&gm,"C:/TC/bgi");
	int i;
	setcolor(GREEN);
	settextstyle(3,0,3);
	outtextxy(80,100,"Developers");
	for(i=0;i<10;i++){
		setcolor(i+4);
		outtextxy(100,130,"Zamiur Rahman");
		delay(300);
		setcolor(i+6);
		outtextxy(120,155,"Ekramul Islam");
		delay(300);
		setcolor(13-i);
		outtextxy(140,180,"Mufakkharul Islam");
		delay(300);



	}

	settextstyle(3,0,1);
	setcolor(BROWN);
	outtextxy(420,130,"[12.01.04.140]");
	setcolor(LIGHTGRAY);
	outtextxy(440,155,"[12.01.04.142]");
	setcolor(LIGHTRED);
	outtextxy(460,180,"[12.01.04.150]");

	for(i=0;i<5;i++){

		setcolor(RED);
		outtextxy(470,420,"copyright of N.R.E");
		delay(600);
		setcolor(15);
		outtextxy(470,420,"copyright of N.R.E");
		delay(600);
	}

	setcolor(WHITE);
	outtextxy(200,440,"Press any KEY for MENU");
	getch();
	cleardevice();
}

int playnow()
{
	int gd=DETECT,gm,y1,y=-49,z,yp=410,xp=320,xpc,xpc1,xpc2,xpc3,xpc4,xpc5,x=320;
	int xp1,xp2,xp3,xp4,xp5,yp1,yp2,yp3,yp4,yp5,k=0,c=1,score=0;
	int check=0;
	char scr[25];
	char sc[10]="SCORE:";
	char cj[100]="CARTOON JUMP";
	initgraph(&gd,&gm,"C:/TC/bgi");
	randomize();
	for(k=0;k<10;k++){
	xp=30+random(610);
	xp1=30+random(610);
	xp2=30+random(610);
	xp3=30+random(610);
	xp4=30+random(610);
	xp5=30+random(610);
	c=1;
	x=xp;
	//while(1){
	for(yp=0,yp1=-120,yp2=-240,yp3=-360,yp4=-720,yp5=-500;k<490;yp++,yp1++,yp2++,yp3++,yp4++,yp5++,check++){
	 if(kbhit()){
		char ch=getch();
		if(ch=='a'||ch==75)
			x=x-15;
		 else if(ch=='d'||ch==77)
			x=x+15;
	     else if(ch=='w'||ch==72)
			y=y-11;
		else if(ch=='p'){
		setcolor(BLUE);
		settextstyle(3,HORIZ_DIR,4);
		outtextxy(180,235,"Paused For 10sec");
		sleep(10);
		setcolor(BLACK);
		settextstyle(3,HORIZ_DIR,4);
		outtextxy(180,235,"Paused For 10sec");
		}
		 else if(ch=='e'||ch==27){
			cleardevice();
			return 0;
			}
	 } //kb hit ends

	 setcolor(c);
	line(xp-30,yp,xp+30,yp); //upper line of platform
	line(xp-30,yp+10,xp+30,yp+10); //down line  of platform
	line(xp-30,yp,xp-30,yp+10); //connector 1
	line(xp-31,yp+1,xp-31,yp+9);
	line(xp-32,yp+2,xp-32,yp+8);
	line(xp-33,yp+3,xp-33,yp+7);
	line(xp-34,yp+4,xp-34,yp+6);
	line(xp+30,yp,xp+30,yp+10); //connector 2
	line(xp+31,yp+1,xp+31,yp+9);
	line(xp+32,yp+2,xp+32,yp+8);
	line(xp+33,yp+3,xp+33,yp+7);
	line(xp+34,yp+4,xp+34,yp+6);

	setcolor(c+1);
	line(xp1-30,yp1,xp1+30,yp1); //upper line of platform
	line(xp1-30,yp1+10,xp1+30,yp1+10); //down line  of platform
	line(xp1-30,yp1,xp1-30,yp1+10); //connector 1
	line(xp1-31,yp1+1,xp1-31,yp1+9);
	line(xp1-32,yp1+2,xp1-32,yp1+8);
	line(xp1-33,yp1+3,xp1-33,yp1+7);
	line(xp1-34,yp1+4,xp1-34,yp1+6);
	line(xp1+30,yp1,xp1+30,yp1+10); //connector 2
	line(xp1+31,yp1+1,xp1+31,yp1+9);
	line(xp1+32,yp1+2,xp1+32,yp1+8);
	line(xp1+33,yp1+3,xp1+33,yp1+7);
	line(xp1+34,yp1+4,xp1+34,yp1+6);

	setcolor(3);
	line(xp2-30,yp2,xp2+30,yp2); //upper line of platform
	line(xp2-30,yp2+10,xp2+30,yp2+10); //down line  of platform
	line(xp2-30,yp2,xp2-30,yp2+10); //connector 1
	line(xp2-31,yp2+1,xp2-31,yp2+9);
	line(xp2-32,yp2+2,xp2-32,yp2+8);
	line(xp2-33,yp2+3,xp2-33,yp2+7);
	line(xp2-34,yp2+4,xp2-34,yp2+6);
	line(xp2+30,yp2,xp2+30,yp2+10); //connector 2
	line(xp2+31,yp2+1,xp2+31,yp2+9);
	line(xp2+32,yp2+2,xp2+32,yp2+8);
	line(xp2+33,yp2+3,xp2+33,yp2+7);
	line(xp2+34,yp2+4,xp2+34,yp2+6);

	setcolor(5);
	line(xp3-30,yp3,xp3+30,yp3); //upper line of platform
	line(xp3-30,yp3+10,xp3+30,yp3+10); //down line  of platform
	line(xp3-30,yp3,xp3-30,yp3+10); //connector 1
	line(xp3-31,yp3+1,xp3-31,yp3+9);
	line(xp3-32,yp3+2,xp3-32,yp3+8);
	line(xp3-33,yp3+3,xp3-33,yp3+7);
	line(xp3-34,yp3+4,xp3-34,yp3+6);
	line(xp3+30,yp3,xp3+30,yp3+10); //connector 2
	line(xp3+31,yp3+1,xp3+31,yp3+9);
	line(xp3+32,yp3+2,xp3+32,yp3+8);
	line(xp3+33,yp3+3,xp3+33,yp3+7);
	line(xp3+34,yp3+4,xp3+34,yp3+6);

	setcolor(RED);
	line(xp4-30,yp4,xp4+30,yp4); //upper line of platform
	line(xp4-30,yp4+10,xp4+30,yp4+10); //down line  of platform
	line(xp4-30,yp4,xp4-30,yp4+10); //connector 1
	line(xp4-31,yp4+1,xp4-31,yp4+9);
	line(xp4-32,yp4+2,xp4-32,yp4+8);
	line(xp4-33,yp4+3,xp4-33,yp4+7);
	line(xp4-34,yp4+4,xp4-34,yp4+6);
	line(xp4+30,yp4,xp4+30,yp4+10); //connector 2
	line(xp4+31,yp4+1,xp4+31,yp4+9);
	line(xp4+32,yp4+2,xp4+32,yp4+8);
	line(xp4+33,yp4+3,xp4+33,yp4+7);
	line(xp4+34,yp4+4,xp4+34,yp4+6);
	arc(xp4-45,yp4,300,245,7);
	arc(xp4-45,yp4+8,135,40,4);
	line(xp4-34,yp4+11,xp4-52,yp4+25);
	line(xp4-57,yp4+11,xp4-38,yp4+25);
	circle(xp4-47,yp4-1,2);
	circle(xp4-43,yp4-1,2);
	arc(xp4+45,yp4,300,245,7);
	arc(xp4+45,yp4+8,135,40,4);
	line(xp4+34,yp4+11,xp4+52,yp4+25);
	line(xp4+57,yp4+11,xp4+38,yp4+25);
	circle(xp4+47,yp4-1,2);
	circle(xp4+43,yp4-1,2);


	setcolor(YELLOW);
	line(xp5-30,yp5,xp5+30,yp5); //upper line of platform
	line(xp5-30,yp5+10,xp5+30,yp5+10); //down line  of platform
	line(xp5-30,yp5,xp5-30,yp5+10); //connector 1
	line(xp5-31,yp5+1,xp5-31,yp5+9);
	line(xp5-32,yp5+2,xp5-32,yp5+8);
	line(xp5-33,yp5+3,xp5-33,yp5+7);
	line(xp5-34,yp5+4,xp5-34,yp5+6);
	line(xp5+30,yp5,xp5+30,yp5+10); //connector 2
	line(xp5+31,yp5+1,xp5+31,yp5+9);
	line(xp5+32,yp5+2,xp5+32,yp5+8);
	line(xp5+33,yp5+3,xp5+33,yp5+7);
	line(xp5+34,yp5+4,xp5+34,yp5+6);
	arc(xp5-40,yp5,0,270,5);
	arc(xp5-40,yp5+10,180,90,5);
	line(xp5-41,yp5-9,xp5-41,yp5+19);
	line(xp5-39,yp5-9,xp5-39,yp5+19);
	arc(xp5+40,yp5,0,270,5);
	arc(xp5+40,yp5+10,180,90,5);
	line(xp5+41,yp5-9,xp5+41,yp5+19);
	line(xp5+39,yp5-9,xp5+39,yp5+19);


	if(yp==480){
		yp=0;
		xp=30+random(570);
	}
	if(yp1==480){
		yp1=0;
		xp1=30+random(570);
	}
	if(yp2==480){
		yp2=0;
		xp2=30+random(570);
	}
	if(yp3==480){
		yp3=0;
		xp3=30+random(570);
	}
	if(yp4==1000){
		yp4=-720;
		xp4=30+random(570);
	}
	if(yp5==600){
		yp5=-500;
		xp5=30+random(570);
	}
       //	c++;
       //	if(c==15){
       //	c=1;
      //	}

	//code of doodle platform ends

	//        ***** condition checking starts ******

/*out*/	 if(y+32==yp || y+32==yp1 || y+32==yp2 || y+32==yp3 || y+32==yp4 || y+32==yp5){      //will check if platform and doodle has same height

	   xpc=xp-30;
	   xpc1=xp1-30;
	   xpc2=xp2-30;
	   xpc3=xp3-30;
	   xpc4=xp4-30;
	   xpc5=xp5-30;

/*n cd 1*/	   if(x==xpc && y+32==yp){
	    for(y1=0;y1<22;y1++){
	     z=y;
	     y=z-y1;
	     setcolor(15);
	     arc(x,y,0,180,15); //head of cartoon
	     line(x+15,y,x+25,y); //upper nose line
	     line(x+25,y,x+25,y+5); //nose line up-down
	     line(x+25,y+5,x+15,y+5); //lower nose line
	     line(x+15,y+5,x+15,y+25);  //right body line
	     line(x+15,y+25,x-15,y+25);  //body line connector
	     line(x-15,y,x-15,y+25);  //left body line
	     line(x-15,y+20,x+15,y+20);   //belt lower
	     line(x-15,y+15,x+15,y+15);   //b. middle
	     line(x-15,y+10,x+15,y+10);    //belt highest
	     line(x-8,y+25,x-8,y+30);    //left foot
	     line(x-5,y+25,x-5,y+30);
	     line(x+5,y+25,x+5,y+30);    //right foot
	     line(x+8,y+25,x+8,y+30);
	     line(x-9,y+30,x-4,y+30);  //shoe left
	     line(x-10,y+31,x-3,y+31);
	     line(x+4,y+30,x+9,y+30);  //shoe right
	     line(x+3,y+31,x+10,y+31);
	     circle(x+5,y-5,2);       //eye color

	     //coloring the doodle head
		  setfillstyle(1,6);
	    // floodfill(x,y,15);
	     //coloring the belt 1
	     setfillstyle(1,2);
	     floodfill(x-5,y+12,15);
	     //coloring the belt 2
	     setfillstyle(1,RED);
	     floodfill(x-5,y+17,15);
	     //coloring the belt 3
	     setfillstyle(1,2);
	     floodfill(x-5,y+22,15);

  /*upore uther delay */	     delay(10);

	     setcolor(0);
	     arc(x,y,0,180,15); //head of cartoon
	     line(x+15,y,x+25,y); //upper nose line
	     line(x+25,y,x+25,y+5); //nose line up-down
	     line(x+25,y+5,x+15,y+5); //lower nose line
	     line(x+15,y+5,x+15,y+25);  //right body line
	     line(x+15,y+25,x-15,y+25);  //body line connector
	     line(x-15,y,x-15,y+25);  //left body line
	     line(x-15,y+20,x+15,y+20);   //belt lower
	     line(x-15,y+15,x+15,y+15);   //b. middle
	     line(x-15,y+10,x+15,y+10);    //belt highest
	     line(x-8,y+25,x-8,y+30);    //left foot
	     line(x-5,y+25,x-5,y+30);
	     line(x+5,y+25,x+5,y+30);    //right foot
	     line(x+8,y+25,x+8,y+30);
	     line(x-9,y+30,x-4,y+30);  //shoe left
	     line(x-10,y+31,x-3,y+31);
	     line(x+4,y+30,x+9,y+30);  //shoe right
	     line(x+3,y+31,x+10,y+31);
	     circle(x+5,y-5,2);       //eye color

	     //coloring the doodle head

	     setfillstyle(1,0);
	     floodfill(x,y,0);
	     //coloring the belt 1
	     setfillstyle(1,0);
	     floodfill(x-5,y+12,0);
	     //coloring the belt 2
	     setfillstyle(1,0);
	     floodfill(x-5,y+17,0);
	     //coloring the belt 3
	     setfillstyle(1,0);
	     floodfill(x-5,y+22,0);
	    // setcolor(BLACK);
	    // outtextxy(0,100,scr);
	    }
	    score=score+10;
	    setcolor(BLACK);
	    settextstyle(3,HORIZ_DIR,1);
	    outtextxy(115,30,scr);
	}
/*n cd 2*/	   else if(x==xpc1 && y+32==yp1){
	    for(y1=0;y1<22;y1++){
	     z=y;
	     y=z-y1;
	     setcolor(15);
	     arc(x,y,0,180,15); //head of cartoon
	     line(x+15,y,x+25,y); //upper nose line
	     line(x+25,y,x+25,y+5); //nose line up-down
	     line(x+25,y+5,x+15,y+5); //lower nose line
	     line(x+15,y+5,x+15,y+25);  //right body line
	     line(x+15,y+25,x-15,y+25);  //body line connector
	     line(x-15,y,x-15,y+25);  //left body line
	     line(x-15,y+20,x+15,y+20);   //belt lower
	     line(x-15,y+15,x+15,y+15);   //b. middle
	     line(x-15,y+10,x+15,y+10);    //belt highest
	     line(x-8,y+25,x-8,y+30);    //left foot
	     line(x-5,y+25,x-5,y+30);
	     line(x+5,y+25,x+5,y+30);    //right foot
	     line(x+8,y+25,x+8,y+30);
	     line(x-9,y+30,x-4,y+30);  //shoe left
	     line(x-10,y+31,x-3,y+31);
	     line(x+4,y+30,x+9,y+30);  //shoe right
	     line(x+3,y+31,x+10,y+31);
	     circle(x+5,y-5,2);       //eye color

	     //coloring the doodle head
		  setfillstyle(1,6);
	    // floodfill(x,y,15);
	     //coloring the belt 1
	     setfillstyle(1,2);
	     floodfill(x-5,y+12,15);
	     //coloring the belt 2
	     setfillstyle(1,RED);
	     floodfill(x-5,y+17,15);
	     //coloring the belt 3
	     setfillstyle(1,2);
	     floodfill(x-5,y+22,15);

  /*upore uther delay */	     delay(10);

	     setcolor(0);
	     arc(x,y,0,180,15); //head of cartoon
	     line(x+15,y,x+25,y); //upper nose line
	     line(x+25,y,x+25,y+5); //nose line up-down
	     line(x+25,y+5,x+15,y+5); //lower nose line
	     line(x+15,y+5,x+15,y+25);  //right body line
	     line(x+15,y+25,x-15,y+25);  //body line connector
	     line(x-15,y,x-15,y+25);  //left body line
	     line(x-15,y+20,x+15,y+20);   //belt lower
	     line(x-15,y+15,x+15,y+15);   //b. middle
	     line(x-15,y+10,x+15,y+10);    //belt highest
	     line(x-8,y+25,x-8,y+30);    //left foot
	     line(x-5,y+25,x-5,y+30);
	     line(x+5,y+25,x+5,y+30);    //right foot
	     line(x+8,y+25,x+8,y+30);
	     line(x-9,y+30,x-4,y+30);  //shoe left
	     line(x-10,y+31,x-3,y+31);
	     line(x+4,y+30,x+9,y+30);  //shoe right
	     line(x+3,y+31,x+10,y+31);
	     circle(x+5,y-5,2);       //eye color

	     //coloring the doodle head

	     setfillstyle(1,0);
	     floodfill(x,y,0);
	     //coloring the belt 1
	     setfillstyle(1,0);
	     floodfill(x-5,y+12,0);
	     //coloring the belt 2
	     setfillstyle(1,0);
	     floodfill(x-5,y+17,0);
	     //coloring the belt 3
	     setfillstyle(1,0);
	     floodfill(x-5,y+22,0);
	    // setcolor(BLACK);
	    // outtextxy(0,100,scr);
	    }
	    score=score+10;
	    setcolor(BLACK);
	    settextstyle(3,HORIZ_DIR,1);
	    outtextxy(115,30,scr);
	}
/*n cd 3*/	   else if(x==xpc2 && y+32==yp2){
	    for(y1=0;y1<22;y1++){
	     z=y;
	     y=z-y1;
	     setcolor(15);
	     arc(x,y,0,180,15); //head of cartoon
	     line(x+15,y,x+25,y); //upper nose line
	     line(x+25,y,x+25,y+5); //nose line up-down
	     line(x+25,y+5,x+15,y+5); //lower nose line
	     line(x+15,y+5,x+15,y+25);  //right body line
	     line(x+15,y+25,x-15,y+25);  //body line connector
	     line(x-15,y,x-15,y+25);  //left body line
	     line(x-15,y+20,x+15,y+20);   //belt lower
	     line(x-15,y+15,x+15,y+15);   //b. middle
	     line(x-15,y+10,x+15,y+10);    //belt highest
	     line(x-8,y+25,x-8,y+30);    //left foot
	     line(x-5,y+25,x-5,y+30);
	     line(x+5,y+25,x+5,y+30);    //right foot
	     line(x+8,y+25,x+8,y+30);
	     line(x-9,y+30,x-4,y+30);  //shoe left
	     line(x-10,y+31,x-3,y+31);
	     line(x+4,y+30,x+9,y+30);  //shoe right
	     line(x+3,y+31,x+10,y+31);
	     circle(x+5,y-5,2);       //eye color

	     //coloring the doodle head
		  setfillstyle(1,6);
	    // floodfill(x,y,15);
	     //coloring the belt 1
	     setfillstyle(1,2);
	     floodfill(x-5,y+12,15);
	     //coloring the belt 2
	     setfillstyle(1,RED);
	     floodfill(x-5,y+17,15);
	     //coloring the belt 3
	     setfillstyle(1,2);
	     floodfill(x-5,y+22,15);

  /*upore uther delay */	  //   delay(10);

	     setcolor(0);
	     arc(x,y,0,180,15); //head of cartoon
	     line(x+15,y,x+25,y); //upper nose line
	     line(x+25,y,x+25,y+5); //nose line up-down
	     line(x+25,y+5,x+15,y+5); //lower nose line
	     line(x+15,y+5,x+15,y+25);  //right body line
	     line(x+15,y+25,x-15,y+25);  //body line connector
	     line(x-15,y,x-15,y+25);  //left body line
	     line(x-15,y+20,x+15,y+20);   //belt lower
	     line(x-15,y+15,x+15,y+15);   //b. middle
	     line(x-15,y+10,x+15,y+10);    //belt highest
	     line(x-8,y+25,x-8,y+30);    //left foot
	     line(x-5,y+25,x-5,y+30);
	     line(x+5,y+25,x+5,y+30);    //right foot
	     line(x+8,y+25,x+8,y+30);
	     line(x-9,y+30,x-4,y+30);  //shoe left
	     line(x-10,y+31,x-3,y+31);
	     line(x+4,y+30,x+9,y+30);  //shoe right
	     line(x+3,y+31,x+10,y+31);
	     circle(x+5,y-5,2);       //eye color

	     //coloring the doodle head

	     setfillstyle(1,0);
	     floodfill(x,y,0);
	     //coloring the belt 1
	     setfillstyle(1,0);
	     floodfill(x-5,y+12,0);
	     //coloring the belt 2
	     setfillstyle(1,0);
	     floodfill(x-5,y+17,0);
	     //coloring the belt 3
	     setfillstyle(1,0);
	     floodfill(x-5,y+22,0);
	    // setcolor(BLACK);
	    // outtextxy(0,100,scr);
	    }
	    score=score+100;
	    setcolor(BLACK);
	    settextstyle(3,HORIZ_DIR,1);
	    outtextxy(115,30,scr);
	}

	      else if(x==xpc5 && y+32==yp5){
	    for(y1=0;y1<22;y1++){
	     z=y;
	     y=z-y1;
	     setcolor(15);
	     arc(x,y,0,180,15); //head of cartoon
	     line(x+15,y,x+25,y); //upper nose line
	     line(x+25,y,x+25,y+5); //nose line up-down
	     line(x+25,y+5,x+15,y+5); //lower nose line
	     line(x+15,y+5,x+15,y+25);  //right body line
	     line(x+15,y+25,x-15,y+25);  //body line connector
	     line(x-15,y,x-15,y+25);  //left body line
	     line(x-15,y+20,x+15,y+20);   //belt lower
	     line(x-15,y+15,x+15,y+15);   //b. middle
	     line(x-15,y+10,x+15,y+10);    //belt highest
	     line(x-8,y+25,x-8,y+30);    //left foot
	     line(x-5,y+25,x-5,y+30);
	     line(x+5,y+25,x+5,y+30);    //right foot
	     line(x+8,y+25,x+8,y+30);
	     line(x-9,y+30,x-4,y+30);  //shoe left
	     line(x-10,y+31,x-3,y+31);
	     line(x+4,y+30,x+9,y+30);  //shoe right
	     line(x+3,y+31,x+10,y+31);
	     circle(x+5,y-5,2);       //eye color

	     //coloring the doodle head
		  setfillstyle(1,6);
	    // floodfill(x,y,15);
	     //coloring the belt 1
	     setfillstyle(1,2);
	     floodfill(x-5,y+12,15);
	     //coloring the belt 2
	     setfillstyle(1,RED);
	     floodfill(x-5,y+17,15);
	     //coloring the belt 3
	     setfillstyle(1,2);
	     floodfill(x-5,y+22,15);

  /*upore uther delay */	     delay(10);

	     setcolor(0);
	     arc(x,y,0,180,15); //head of cartoon
	     line(x+15,y,x+25,y); //upper nose line
	     line(x+25,y,x+25,y+5); //nose line up-down
	     line(x+25,y+5,x+15,y+5); //lower nose line
	     line(x+15,y+5,x+15,y+25);  //right body line
	     line(x+15,y+25,x-15,y+25);  //body line connector
	     line(x-15,y,x-15,y+25);  //left body line
	     line(x-15,y+20,x+15,y+20);   //belt lower
	     line(x-15,y+15,x+15,y+15);   //b. middle
	     line(x-15,y+10,x+15,y+10);    //belt highest
	     line(x-8,y+25,x-8,y+30);    //left foot
	     line(x-5,y+25,x-5,y+30);
	     line(x+5,y+25,x+5,y+30);    //right foot
	     line(x+8,y+25,x+8,y+30);
	     line(x-9,y+30,x-4,y+30);  //shoe left
	     line(x-10,y+31,x-3,y+31);
	     line(x+4,y+30,x+9,y+30);  //shoe right
	     line(x+3,y+31,x+10,y+31);
	     circle(x+5,y-5,2);       //eye color

	     //coloring the doodle head

	     setfillstyle(1,0);
	     floodfill(x,y,0);
	     //coloring the belt 1
	     setfillstyle(1,0);
	     floodfill(x-5,y+12,0);
	     //coloring the belt 2
	     setfillstyle(1,0);
	     floodfill(x-5,y+17,0);
	     //coloring the belt 3
	     setfillstyle(1,0);
	     floodfill(x-5,y+22,0);
	    // setcolor(BLACK);
	    // outtextxy(0,100,scr);
	    }
	    setcolor(BLACK);
	    settextstyle(3,HORIZ_DIR,1);
	    outtextxy(115,30,scr);
	}
	  else if(x==xpc4 && y+32==yp4){
	  goto exit1;
	  }


/*n cd 4*/	   else if(x==xpc3 && y+32==yp3){

       new1: for(y1=0;y1<22;y1++){
	     z=y;
	     y=z-y1;
	     setcolor(15);
	     arc(x,y,0,180,15); //head of cartoon
	     line(x+15,y,x+25,y); //upper nose line
	     line(x+25,y,x+25,y+5); //nose line up-down
	     line(x+25,y+5,x+15,y+5); //lower nose line
	     line(x+15,y+5,x+15,y+25);  //right body line
	     line(x+15,y+25,x-15,y+25);  //body line connector
	     line(x-15,y,x-15,y+25);  //left body line
	     line(x-15,y+20,x+15,y+20);   //belt lower
	     line(x-15,y+15,x+15,y+15);   //b. middle
	     line(x-15,y+10,x+15,y+10);    //belt highest
	     line(x-8,y+25,x-8,y+30);    //left foot
	     line(x-5,y+25,x-5,y+30);
	     line(x+5,y+25,x+5,y+30);    //right foot
	     line(x+8,y+25,x+8,y+30);
	     line(x-9,y+30,x-4,y+30);  //shoe left
	     line(x-10,y+31,x-3,y+31);
	     line(x+4,y+30,x+9,y+30);  //shoe right
	     line(x+3,y+31,x+10,y+31);
	     circle(x+5,y-5,2);       //eye color

	     //coloring the doodle head
		  setfillstyle(1,6);
	    // floodfill(x,y,15);
	     //coloring the belt 1
	     setfillstyle(1,2);
	     floodfill(x-5,y+12,15);
	     //coloring the belt 2
	     setfillstyle(1,RED);
	     floodfill(x-5,y+17,15);
	     //coloring the belt 3
	     setfillstyle(1,2);
	     floodfill(x-5,y+22,15);

  /*upore uther delay */	     delay(10);

	     setcolor(0);
	     arc(x,y,0,180,15); //head of cartoon
	     line(x+15,y,x+25,y); //upper nose line
	     line(x+25,y,x+25,y+5); //nose line up-down
	     line(x+25,y+5,x+15,y+5); //lower nose line
	     line(x+15,y+5,x+15,y+25);  //right body line
	     line(x+15,y+25,x-15,y+25);  //body line connector
	     line(x-15,y,x-15,y+25);  //left body line
	     line(x-15,y+20,x+15,y+20);   //belt lower
	     line(x-15,y+15,x+15,y+15);   //b. middle
	     line(x-15,y+10,x+15,y+10);    //belt highest
	     line(x-8,y+25,x-8,y+30);    //left foot
	     line(x-5,y+25,x-5,y+30);
	     line(x+5,y+25,x+5,y+30);    //right foot
	     line(x+8,y+25,x+8,y+30);
	     line(x-9,y+30,x-4,y+30);  //shoe left
	     line(x-10,y+31,x-3,y+31);
	     line(x+4,y+30,x+9,y+30);  //shoe right
	     line(x+3,y+31,x+10,y+31);
	     circle(x+5,y-5,2);       //eye color

	     //coloring the doodle head

	     setfillstyle(1,0);
	     floodfill(x,y,0);
	     //coloring the belt 1
	     setfillstyle(1,0);
	     floodfill(x-5,y+12,0);
	     //coloring the belt 2
	     setfillstyle(1,0);
	     floodfill(x-5,y+17,0);
	     //coloring the belt 3
	     setfillstyle(1,0);
	     floodfill(x-5,y+22,0);
	    // setcolor(BLACK);
	    // outtextxy(0,100,scr);
	    }
	    score=score+10;
	    setcolor(BLACK);
	    settextstyle(3,HORIZ_DIR,1);
	    outtextxy(115,30,scr);
	}    //end of for loop  THAT WILL TAKE THE DOODLE UP

// ***x check cndition
/*n cd 5 else*/	else{
	  //  printf("inner else");		          // incase x and xp are not same
	    for(int t=1;t<65;t++){
	    xpc=xp-30;
	    xpc1=xp1-30;
	    xpc2=xp2-30;
	    xpc3=xp3-30;
	    xpc4=xp4-30;
	    xpc5=xp5-30;

	       xpc=xpc+t;
	       xpc1=xpc1+t;
	       xpc2=xpc2+t;
	       xpc3=xpc3+t;
	       xpc4=xpc4+t;
	       xpc5=xpc5+t;
	       if(xpc==x && y+32==yp){
	       sound(1500);
	       delay(5);
	       nosound();
	       goto new1;
	       }
	       else if(xpc1==x && y+32==yp1){
	       sound(1500);
	       delay(10);
	       nosound();
	       goto new1;
	       }
	       else if(xpc2==x && y+32==yp2){
	       sound(1500);
	       delay(10);
	       nosound();
	       goto new1;
	       }
	       else if(xpc3==x && y+32==yp3){
		  sound(1500);
		  delay(10);
		  nosound();
		  goto new1;
		  }
		  else if(xpc4==x && y+32==yp4){
		  goto exit1;
		  }
		  else if(xpc5==x && y+32==yp5){
		  score=score+100;
		  sound(1500);
		  setcolor(YELLOW);
		  outtextxy(165,40,"BONUS !!!");
		  delay(10);
		  setcolor(BLACK);
		  outtextxy(165,40,"BONUS !!!");
		  nosound();
		  goto new1;
		  }
		 //	if(xpc==x || xpc1==x || xpc2==x || xpc3==x){
		 //	(y+32==yp || y+32==yp1 || y+32==yp2 || y+32==yp3)
		 //	printf("x=%d,xpc=%d,xpc1=%d,xpc2=%d,xpc3=%d\n",x,xpc,xpc1,xpc2,xpc3);
		 //	goto new1; }
		 //	else if(){
		 //
		//	}
		else if(t==64){
		goto new6;

		}
		else continue;
		}
	    }
	}	//if else statement for finding X ends
 /*outer else*/	else{  // y same na thakle ei else dia doodle will come down
	 new6:	  y++;
	 // printf("y is %d",y);
	    for(int l=0;l<1;l++){
	    setcolor(15);
	  //  printf("y is %d\n",y);
	    arc(x,y,0,180,15); //head of cartoon
	    line(x+15,y,x+25,y); //upper nose line
	    line(x+25,y,x+25,y+5); //nose line up-down
	    line(x+25,y+5,x+15,y+5); //lower nose line
	    line(x+15,y+5,x+15,y+25);  //right body line
	    line(x+15,y+25,x-15,y+25);  //body line connector
	    line(x-15,y,x-15,y+25);  //left body line
	    line(x-15,y+20,x+15,y+20);   //belt lower
	    line(x-15,y+15,x+15,y+15);   //b. middle
	    line(x-15,y+10,x+15,y+10);    //belt highest
	    line(x-8,y+25,x-8,y+30);    //left foot
	    line(x-5,y+25,x-5,y+30);
	    line(x+5,y+25,x+5,y+30);    //right foot
	    line(x+8,y+25,x+8,y+30);
	    line(x-9,y+30,x-4,y+30);  //shoe left
	    line(x-10,y+31,x-3,y+31);
	    line(x+4,y+30,x+9,y+30);  //shoe right
	    line(x+3,y+31,x+10,y+31);
	    circle(x+5,y-5,2);       //eye               color

	    //coloring the doodle head
	    setfillstyle(1,6);
	    floodfill(x,y,15);
	    //coloring the belt 1
	    setfillstyle(1,2);
	    floodfill(x-5,y+12,15);
	    //coloring the belt 2
	    setfillstyle(1,RED);
	    floodfill(x-5,y+17,15);
	    //coloring the belt 3
	    setfillstyle(1,2);
	    floodfill(x-5,y+22,15);

	  //  delay(100); //delay of main game

	    setcolor(0);
	    arc(x,y,0,180,15); //head of cartoon
	    line(x+15,y,x+25,y); //upper nose line
	    line(x+25,y,x+25,y+5); //nose line up-down
	    line(x+25,y+5,x+15,y+5); //lower nose line
	    line(x+15,y+5,x+15,y+25);  //right body line
	    line(x+15,y+25,x-15,y+25);  //body line connector
	    line(x-15,y,x-15,y+25);  //left body line
	    line(x-15,y+20,x+15,y+20);   //belt lower
	    line(x-15,y+15,x+15,y+15);   //b. middle
	    line(x-15,y+10,x+15,y+10);    //belt highest
	    line(x-8,y+25,x-8,y+30);    //left foot
	    line(x-5,y+25,x-5,y+30);
	    line(x+5,y+25,x+5,y+30);    //right foot
	    line(x+8,y+25,x+8,y+30);
	    line(x-9,y+30,x-4,y+30);  //shoe left
	    line(x-10,y+31,x-3,y+31);
	    line(x+4,y+30,x+9,y+30);  //shoe right
	    line(x+3,y+31,x+10,y+31);
	    circle(x+5,y-5,2);       //eye               color

	    //coloring the doodle head
	    setfillstyle(1,0);
	    floodfill(x,y,0);
	    //coloring the belt 1
	    setfillstyle(1,0);
	    floodfill(x-5,y+12,0);
	    //coloring the belt 2
	    setfillstyle(1,0);
	    floodfill(x-5,y+17,0);
	    //coloring the belt 3
	    setfillstyle(1,0);
	    floodfill(x-5,y+22,0);
	    }
	  }// niche nama sesh
/**/	  delay(1);   //delay of main game
	   y++;
	   if(x<10)
	   x=10;
	   if(x>629)
	   x=629;
	   if(y<0 && check>500){
	   y=0;
	   }
	   if(y>479){
  exit1:   cleardevice();
	setcolor(RED);
	settextstyle(3,0,4);
	outtextxy(200,240,"Your Score is : ");
	outtextxy(450,240,scr);
	delay(3000);
	cleardevice();
    FILE *st;
		 st=fopen("C:\\TC\\stream.txt","wb");

   if (st== NULL)
   {
	printf("Cannot open output file.\n");
	return 1;
   }
    fread(&re,sizeof(s[1]),50,st);


   s[0].i=re[0].i;
    s[1].i=re[1].i;
	s[2].i=re[2].i;
   //getch();
   if(s[2].i<score)
    s[2].i=score;


	int k,j,t;
	 for(k=1;k<=4;k++){
		for(j=0;j<k-1;j++){
			if(s[j].i<s[j+1].i){
			t=s[j].i;
			s[j].i=s[j+1].i;
			s[j+1].i=t;
			}
		}
	 }

	 fwrite(&s, sizeof(s[1]),50, st);
	 fclose(st);
	  // int n=4;
	   while(1){
	   setcolor(BLUE);
	   settextstyle(3,HORIZ_DIR,3);
	outtextxy(230,40,"Thanx For Playing");
	   setcolor(RED);
	settextstyle(3,HORIZ_DIR,4);
	outtextxy(240,240,"GAME OVER");
	  /*	delay(50);
	setcolor(BLUE);
	settextstyle(3,HORIZ_DIR,4);
	outtextxy(240,240,"GAME OVER");   */
	setcolor(GREEN);
	settextstyle(3,HORIZ_DIR,3);
	outtextxy(50,420,"Press R for Retry.           Press ESC to Exit.");
	setcolor(WHITE);
	settextstyle(3,0,1);
	outtextxy(205,450,"Press ENTER for MENU");

		if(kbhit()){
		char c=getch();
		if(c=='r')
		playnow();
		 else if(c=='e'||c==27){
			cleardevice();
			exit(1);
			}
		 else if(c==13){
			cleardevice();
			return 0;
			}
	   }
	   }
	   }
	    for(int l=0;l<1;l++){
	    setcolor(15);
	    arc(x,y,0,180,15); //head of cartoon
	    line(x+15,y,x+25,y); //upper nose line
	    line(x+25,y,x+25,y+5); //nose line up-down
	    line(x+25,y+5,x+15,y+5); //lower nose line
	    line(x+15,y+5,x+15,y+25);  //right body line
	    line(x+15,y+25,x-15,y+25);  //body line connector
	    line(x-15,y,x-15,y+25);  //left body line
	    line(x-15,y+20,x+15,y+20);   //belt lower
	    line(x-15,y+15,x+15,y+15);   //b. middle
	    line(x-15,y+10,x+15,y+10);    //belt highest
	    line(x-8,y+25,x-8,y+30);    //left foot
	    line(x-5,y+25,x-5,y+30);
	    line(x+5,y+25,x+5,y+30);    //right foot
	    line(x+8,y+25,x+8,y+30);
	    line(x-9,y+30,x-4,y+30);  //shoe left
	    line(x-10,y+31,x-3,y+31);
	    line(x+4,y+30,x+9,y+30);  //shoe right
	    line(x+3,y+31,x+10,y+31);
	    circle(x+5,y-5,2);       //eye               color

	    //coloring the doodle head
	    setfillstyle(1,6);
	    floodfill(x,y,15);
	    //coloring the belt 1
	    setfillstyle(1,2);
	    floodfill(x-5,y+12,15);
	    //coloring the belt 2
	    setfillstyle(1,RED);
	    floodfill(x-5,y+17,15);
	    //coloring the belt 3
	    setfillstyle(1,2);
	    floodfill(x-5,y+22,15);

	  // delay(1);

	    setcolor(0);
	    arc(x,y,0,180,15); //head of cartoon
	    line(x+15,y,x+25,y); //upper nose line
	    line(x+25,y,x+25,y+5); //nose line up-down
	    line(x+25,y+5,x+15,y+5); //lower nose line
	    line(x+15,y+5,x+15,y+25);  //right body line
	    line(x+15,y+25,x-15,y+25);  //body line connector
	    line(x-15,y,x-15,y+25);  //left body line
	    line(x-15,y+20,x+15,y+20);   //belt lower
	    line(x-15,y+15,x+15,y+15);   //b. middle
	    line(x-15,y+10,x+15,y+10);    //belt highest
	    line(x-8,y+25,x-8,y+30);    //left foot
	    line(x-5,y+25,x-5,y+30);
	    line(x+5,y+25,x+5,y+30);    //right foot
	    line(x+8,y+25,x+8,y+30);
	    line(x-9,y+30,x-4,y+30);  //shoe left
	    line(x-10,y+31,x-3,y+31);
	    line(x+4,y+30,x+9,y+30);  //shoe right
	    line(x+3,y+31,x+10,y+31);
	    circle(x+5,y-5,2);       //eye               color

	    //coloring the doodle head
	    setfillstyle(1,0);
	    floodfill(x,y,0);
	    //coloring the belt 1
	    setfillstyle(1,0);
	    floodfill(x-5,y+12,0);
	    //coloring the belt 2
	    setfillstyle(1,0);
	    floodfill(x-5,y+17,0);
	    //coloring the belt 3
	    setfillstyle(1,0);
	    floodfill(x-5,y+22,0);
	    }


	setcolor(0);
	line(xp-30,yp,xp+30,yp); //upper line of platform
	line(xp-30,yp+10,xp+30,yp+10); //down line  of platform
	line(xp-30,yp,xp-30,yp+10); //connector 1
	line(xp-31,yp+1,xp-31,yp+9);
	line(xp-32,yp+2,xp-32,yp+8);
	line(xp-33,yp+3,xp-33,yp+7);
	line(xp-34,yp+4,xp-34,yp+6);
	line(xp+30,yp,xp+30,yp+10); //connector 2
	line(xp+31,yp+1,xp+31,yp+9);
	line(xp+32,yp+2,xp+32,yp+8);
	line(xp+33,yp+3,xp+33,yp+7);
	line(xp+34,yp+4,xp+34,yp+6);

	setcolor(0);
	line(xp1-30,yp1,xp1+30,yp1); //upper line of platform
	line(xp1-30,yp1+10,xp1+30,yp1+10); //down line  of platform
	line(xp1-30,yp1,xp1-30,yp1+10); //connector 1
	line(xp1-31,yp1+1,xp1-31,yp1+9);
	line(xp1-32,yp1+2,xp1-32,yp1+8);
	line(xp1-33,yp1+3,xp1-33,yp1+7);
	line(xp1-34,yp1+4,xp1-34,yp1+6);
	line(xp1+30,yp1,xp1+30,yp1+10); //connector 2
	line(xp1+31,yp1+1,xp1+31,yp1+9);
	line(xp1+32,yp1+2,xp1+32,yp1+8);
	line(xp1+33,yp1+3,xp1+33,yp1+7);
	line(xp1+34,yp1+4,xp1+34,yp1+6);

	setcolor(0);
	line(xp2-30,yp2,xp2+30,yp2); //upper line of platform
	line(xp2-30,yp2+10,xp2+30,yp2+10); //down line  of platform
	line(xp2-30,yp2,xp2-30,yp2+10); //connector 1
	line(xp2-31,yp2+1,xp2-31,yp2+9);
	line(xp2-32,yp2+2,xp2-32,yp2+8);
	line(xp2-33,yp2+3,xp2-33,yp2+7);
	line(xp2-34,yp2+4,xp2-34,yp2+6);
	line(xp2+30,yp2,xp2+30,yp2+10); //connector 2
	line(xp2+31,yp2+1,xp2+31,yp2+9);
	line(xp2+32,yp2+2,xp2+32,yp2+8);
	line(xp2+33,yp2+3,xp2+33,yp2+7);
	line(xp2+34,yp2+4,xp2+34,yp2+6);

	setcolor(0);
	line(xp3-30,yp3,xp3+30,yp3); //upper line of platform
	line(xp3-30,yp3+10,xp3+30,yp3+10); //down line  of platform
	line(xp3-30,yp3,xp3-30,yp3+10); //connector 1
	line(xp3-31,yp3+1,xp3-31,yp3+9);
	line(xp3-32,yp3+2,xp3-32,yp3+8);
	line(xp3-33,yp3+3,xp3-33,yp3+7);
	line(xp3-34,yp3+4,xp3-34,yp3+6);
	line(xp3+30,yp3,xp3+30,yp3+10); //connector 2
	line(xp3+31,yp3+1,xp3+31,yp3+9);
	line(xp3+32,yp3+2,xp3+32,yp3+8);
	line(xp3+33,yp3+3,xp3+33,yp3+7);
	line(xp3+34,yp3+4,xp3+34,yp3+6);

	setcolor(0);
	line(xp4-30,yp4,xp4+30,yp4); //upper line of platform
	line(xp4-30,yp4+10,xp4+30,yp4+10); //down line  of platform
	line(xp4-30,yp4,xp4-30,yp4+10); //connector 1
	line(xp4-31,yp4+1,xp4-31,yp4+9);
	line(xp4-32,yp4+2,xp4-32,yp4+8);
	line(xp4-33,yp4+3,xp4-33,yp4+7);
	line(xp4-34,yp4+4,xp4-34,yp4+6);
	line(xp4+30,yp4,xp4+30,yp4+10); //connector 2
	line(xp4+31,yp4+1,xp4+31,yp4+9);
	line(xp4+32,yp4+2,xp4+32,yp4+8);
	line(xp4+33,yp4+3,xp4+33,yp4+7);
	line(xp4+34,yp4+4,xp4+34,yp4+6);
	arc(xp4-45,yp4,300,245,7);
	arc(xp4-45,yp4+8,135,40,4);
	line(xp4-34,yp4+11,xp4-52,yp4+25);
	line(xp4-57,yp4+11,xp4-38,yp4+25);
	circle(xp4-47,yp4-1,2);
	circle(xp4-43,yp4-1,2);
	arc(xp4+45,yp4,300,245,7);
	arc(xp4+45,yp4+8,135,40,4);
	line(xp4+34,yp4+11,xp4+52,yp4+25);
	line(xp4+57,yp4+11,xp4+38,yp4+25);
	circle(xp4+47,yp4-1,2);
	circle(xp4+43,yp4-1,2);


	setcolor(0);
	line(xp5-30,yp5,xp5+30,yp5); //upper line of platform
	line(xp5-30,yp5+10,xp5+30,yp5+10); //down line  of platform
	line(xp5-30,yp5,xp5-30,yp5+10); //connector 1
	line(xp5-31,yp5+1,xp5-31,yp5+9);
	line(xp5-32,yp5+2,xp5-32,yp5+8);
	line(xp5-33,yp5+3,xp5-33,yp5+7);
	line(xp5-34,yp5+4,xp5-34,yp5+6);
	line(xp5+30,yp5,xp5+30,yp5+10); //connector 2
	line(xp5+31,yp5+1,xp5+31,yp5+9);
	line(xp5+32,yp5+2,xp5+32,yp5+8);
	line(xp5+33,yp5+3,xp5+33,yp5+7);
	line(xp5+34,yp5+4,xp5+34,yp5+6);
	arc(xp5-40,yp5,0,270,5);
	arc(xp5-40,yp5+10,180,90,5);
	line(xp5-41,yp5-9,xp5-41,yp5+19);
	line(xp5-39,yp5-9,xp5-39,yp5+19);
	arc(xp5+40,yp5,0,270,5);
	arc(xp5+40,yp5+10,180,90,5);
	line(xp5+41,yp5-9,xp5+41,yp5+19);
	line(xp5+39,yp5-9,xp5+39,yp5+19);


	itoa(score,scr,10);
	setcolor(RED);
	settextstyle(3,HORIZ_DIR,1);
	outtextxy(115,30,scr);
	settextstyle(3,HORIZ_DIR,1);
	outtextxy(25,30,sc);
	setcolor(RED);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	outtextxy(430,35,cj);
	}
	getch();
	cleardevice();
	//closegraph();
}
return 0;
}






int high()
{
  char m[30];
int gdriver = DETECT, gmode, errorcode;
 // char m[100];
   clrscr();
    initgraph(&gdriver, &gmode, "C:/TC/bgi");
   FILE *st;
	/* st=fopen("C:\\TC\\stream.txt","rb");
	fread(&re,sizeof(s[1]),50,st);
  char g[30];
  int q=100;
  for(int r=0;r<3;r++)
  {
	sprintf(g,"NO.%d score is-%d",r+1,re[r].i);
	 outtextxy(100,q,g);
	 q+=100;
	 }*/
	 /*  st=fopen("C:\\TC\\stream.txt","wb");

   if (st== NULL)
   {
	printf("Cannot open output file.\n");
	return 1;
   } */

   setcolor(RED);
    settextstyle(1, HORIZ_DIR,4);
   outtextxy(200,0,"---High Scores---");


	setcolor(15);
	 settextstyle(GOTHIC_FONT, HORIZ_DIR,4);

    /*	 s[2].i=a;


	int k,j,t;
	 for(k=1;k<=4;k++){
		for(j=0;j<k-1;j++){
			if(s[j].i<s[j+1].i){
			t=s[j].i;
			s[j].i=s[j+1].i;
			s[j+1].i=t;
			}
		}
	 }

	 fwrite(&s, sizeof(s[1]),50, st);
	 fclose(st);*/
	 st=fopen("C:\\TC\\stream.txt","rb");
	 fread(&re,sizeof(s[1]),50,st);

  int n=100;
  for(int l=0;l<3;l++)
  {
	sprintf(m,"NO.%d score is : %d",l+1,re[l].i);
	settextstyle(3,0,3);
	 outtextxy(225,n,m);
	 n+=100;
	 }
	 getch();
	 cleardevice();

	 return 0;
}

void main()
{
	int gd=DETECT,gm;

	initgraph(&gd,&gm,"C:/TC/bgi");

	int bx=160;
	int a;
	int jump=1;//not changable
	int jump1=0;

	while(1){

	a=0;
	jump1=0;
	//jump=1;

	setcolor(BLUE);
	settextstyle(1,0,1);
	outtextxy(200,60,"C A R T O O N   J U M P");

	setcolor(RED);
	settextstyle(3,HORIZ_DIR,1);
	outtextxy(260,110,"GAME MENU");

	setcolor(GREEN);
	settextstyle(0,HORIZ_DIR,1);
	outtextxy(250,165,"* PLAY NOW");

	setcolor(CYAN);
	settextstyle(0,HORIZ_DIR,1);
	outtextxy(250,185,"* HELP");

	setcolor(GREEN);
	settextstyle(0,HORIZ_DIR,1);
	outtextxy(250,205,"* HIGH SCORES");

	setcolor(BROWN);
	settextstyle(0,HORIZ_DIR,1);
	outtextxy(250,225,"* CREDENTIAL");

	/*setcolor(RED);
	settextstyle(0,HORIZ_DIR,1);
	outtextxy(250,245,"* CREDENTIAL");*/

	setcolor(MAGENTA);
	settextstyle(0,HORIZ_DIR,1);
	outtextxy(250,295,"* EXIT [ ESC ] *");

	setcolor(GREEN);
	rectangle(240,bx,370,bx+15);
	setcolor(RED);
	rectangle(239,bx-1,371,bx+16);

	if(kbhit()){
		a=getch();
		//if(a==13) jump=1;
	}
		//a=getch();

	if(a==80){
		setcolor(BLACK);
		rectangle(240,bx,370,bx+15);
		setcolor(BLACK);
		rectangle(239,bx-1,371,bx+16);

		if(bx<215){
			bx=bx+20;
			//printf("%d\t",jump);
			jump++;
		}
	}

	else if(a==72){
		setcolor(BLACK);
		rectangle(240,bx,370,bx+15);
		setcolor(BLACK);
		rectangle(239,bx-1,371,bx+16);

		if(bx>160){
			bx=bx-20;
			//printf("%d\t",jump);
			jump--;
		}
	}
	else if(a==27){
		exit(0);
	}

	load_mouse_driver();

		//while(1)
		//{
			/*if(kbhit()){
				a=getch();
				break;
			} */

			//load_mouse_driver();
			int x,y,cl;

			in.x.ax=3;
			int86(0x33,&in,&out);

			x=out.x.cx;      // To get x coordinate
			y=out.x.dx;      // To get y coordinate
			cl=out.x.bx;     // 1/0 ; 1 for mouse click



			if(x>=240 && x<=370 && y>=160 && y<=175 && cl==1) //checking if the mouse inside the rectangale and the user click on it...
				{

					unload_mouse_driver();
					jump1=1;
					jump=1;
					//printf("%d\t",jump1);
					//break;
					//a=13;
					//jump1=1;
					//break;
				}

			else if(x>=240 && x<=370 && y>=180 && y<=195 && cl==1) //checking if the mouse inside the rectangale and the user click on it...
				{

					unload_mouse_driver();
					jump1=2;
					jump=2;
				}

			else if(x>=240 && x<=370 && y>=200 && y<=215 && cl==1) //checking if the mouse inside the rectangale and the user click on it...
				{

					unload_mouse_driver();
					jump1=3;
					jump=3;
				}


			else if(x>=240 && x<=370 && y>=220 && y<=235 && cl==1) //checking if the mouse inside the rectangale and the user click on it...
				{

					unload_mouse_driver();
					jump1=4;
					jump=4;
				}

			/*else if(x>=240 && x<=370 && y>=240 && y<=255 && cl==1) //checking if the mouse inside the rectangale and the user click on it...
				{

					unload_mouse_driver();
					jump1=5;
					jump=5;
				}*/
		//}//while loop ends

	if(a==13||jump1==1||jump1==2||jump1==3||jump1==4||jump1==5){

		if(jump==1){	playnow();
		//jump=2;
		//break;
		}
		/*if(jump==2){	display();
		break;
		jump=3;
		}*/
		if(jump==2){	help();
		//jump=4;
		//break;
		}
		if(jump==3)	high();
		//printf("%d\t",jump);
		//jump=5;
		if(jump==4){	credential();
		}
	}

	}

}