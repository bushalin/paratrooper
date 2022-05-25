//in the name of Allah the only one


#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>

void menu();
void game();
void instruction();
void credits();
void exit();
void main()
{

	int gd=DETECT, gm;
	initgraph(&gd,&gm,"C:/TC/BGI");
	menu();


	getch();
	closegraph();

}
void menu()
{
	cleardevice();
	char ch;
	int m_x1=250,m_x2=450;
	int m_y1=190,m_y2=240;
	while(1){
		setcolor(WHITE);
		settextstyle(GOTHIC_FONT,HORIZ_DIR,6);
		setcolor(10);
		outtextxy(115,70,"PARA-COMMANDO");
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
		outtextxy(270,200,"New Game");
		outtextxy(267,250,"Instructions");
		outtextxy(290,300,"Credits");
		outtextxy(310,350,"Exit");
		//outtextxy(308,400,"EXIT");
		setcolor(RED);
		rectangle(250,m_y1,410,m_y2);

	    if(kbhit())
	    {
		ch=getch();

		if(ch==80)
		{
		m_y1=m_y1+50;
		m_y2=m_y2+50;
		sound(400);
		delay(50);
		nosound();
			if(m_y1==390 && m_y2==440)
			{
			cleardevice();
			menu();
			sound(400);
			delay(50);
			nosound();
			}
		cleardevice();
		}
		if(ch==72)
		{
		m_y1=m_y1-50;
		m_y2=m_y2-50;
		sound(400);
		delay(50);
		nosound();
			if(m_y1==140 && m_y2==190)
			{
			cleardevice();
			m_y1=340;
			m_y2=390;
			sound(400);
			delay(50);
			nosound();
			}
		cleardevice();
		}

		if(ch==27)
		{
		exit(1);
		}
		if(ch==13)
		{
			if(m_y1==190 && m_y2==240)
			{
				game();
			}
			if(m_y1==240 && m_y2==290)
			{
				instruction();
			}
			if(m_y1==290 && m_y2==340)
			{
				cleardevice();
				credits();
			}
			if(m_y1==340 && m_y2==390)
			{
				exit(1);
			}
		      /*	if(m_y1==390 && m_y2==440)
			{
				exit(1);
			}   */
		}

	    }
	}
}
void game()
{
	cleardevice();
	randomize();
	int i=0,k=0,j=0,move,r_leg_y1=20,r_leg_y2=30,l_leg_y1=20,l_leg_y2=30;
	int s1x1=120,s1x2=280,s2x1=620,s2x2=780,s3x1=1120,s3x2=1280,s4x1=1620,s4x2=1780;
	int r_leg_x2=330,l_leg_x2=310,nayem1=0,nayem2=0,arc_head=480;
	static int score=0;
	char ch;
	//setcolor(WHITE);
	while(1)
	{
		cleardevice();
		setcolor(WHITE);
		arc(640,470,60,120,50);
		arc(590,470,60,120,50);
		arc(540,470,60,120,50);
		arc(490,470,60,120,50);
		arc(440,470,60,120,50);
		arc(390,470,60,120,50);
		arc(340,470,60,120,50);
		arc(290,470,60,120,50);
		arc(240,470,60,120,50);
		arc(190,470,60,120,50);
		arc(140,470,60,120,50);
		arc(90,470,60,120,50);
		arc(40,470,60,120,50);
		arc(0,470,60,120,50);
		setfillstyle(SOLID_FILL,BLUE);
		floodfill(620,460,WHITE);

		//plane code start
		line(450-i,70,613-i,70);
		arc(arc_head-i,70,90,180,30);
		line(481-i,40,590-i,60);
		line(590-i,30,590-i,60);
		line(590-i,30,613-i,20);
		line(613-i,20,613-i,70);
		line(513-i,45,573-i,15);
		line(573-i,15,583-i,15);
		line(513-i,70,573-i,95);
		line(543-i,70,573-i,85);
		line(573-i,95,573-i,85);
		line(583-i,15,533-i,47);
		rectangle(470-i,55,480-i,65);
		rectangle(490-i,55,500-i,65);
	     /*	k++;
		i=k;  */
		//plane code ends
		delay(15);

		//1st ship
		line(150-i,420,250-i,420);
		line(120-i,390,150-i,420);
		line(280-i,390,250-i,420);
		line(s1x1-i,390,s1x2-i,390);		//ship surface plate
		rectangle(230-i,360,250-i,390);
		line(230-i,370,250-i,370);
		//2nd ship
		line(650-i,420,750-i,420);
		line(620-i,390,650-i,420);
		line(780-i,390,750-i,420);
		line(s2x1-i,390,s2x2-i,390);
		rectangle(730-i,360,750-i,390);
		line(730-i,370,750-i,370);
		//3rd ship
		line(1150-i,420,1250-i,420);
		line(1120-i,390,1150-i,420);
		line(1280-i,390,1250-i,420);
		line(s3x1-i,390,s3x2-i,390);
		rectangle(1230-i,360,1250-i,390);
		line(1230-i,370,1250-i,370);
		//4th ship
		line(1650-i,420,1750-i,420);
		line(1620-i,390,1650-i,420);
		line(1780-i,390,1750-i,420);
		line(s4x1-i,390,s4x2-i,390);
		rectangle(1730-i,360,1750-i,390);
		line(1730-i,370,1750-i,370);
		delay(5);
		if(i>=200)
		{
			j++;
			//commando body
			circle(320+move,0+j,5);
			line(320+move,5+j,320+move,20+j);    //body
			line(320+move,r_leg_y1+j,r_leg_x2+move,r_leg_y2+j);   //right leg
			nayem1=r_leg_x2+move;
			line(320+move,l_leg_y1+j,l_leg_x2+move,l_leg_y2+j);   //left leg
			nayem2=l_leg_x2+move;
			line(310+move,12+j,330+move,12+j);   //hand
			delay(5);
		}
		cleardevice();
		i++;
		if(kbhit())
		{
			ch=getch();
			if(ch==77)
			{
				move=move+5;				//movement
			}
			if(ch==75)
			{
				move=move-5;
			}
			if(ch==27)
			{
				menu();
			}
		}

		if((r_leg_x2+move)>=(s2x1-i) && (r_leg_x2+move)<=(s2x2-i))
		{
			if(j>=359)
			{
				score=score+10;
				game();
				sound(800);
				delay(130);
				nosound();
			}
		}
		if((r_leg_x2+move)>=(s1x1-i) && (r_leg_x2+move)<=(s1x2-i))
		{
			if(j>=359)
			{
				score=score+10;
				game();
				sound(800);
				delay(130);
				nosound();
			}
		}
		if((r_leg_x2+move)>=(s3x1-i) && (r_leg_x2+move)<=(s3x2-i))
		{
			if(j>=359)
			{
				score=score+10;
				game();
				sound(800);
				delay(130);
				nosound();
			}
		}
		if((r_leg_x2+move)>=(s4x1-i) && (r_leg_x2+move)<=(s4x2-i))
		{
			if(j>=359)
			{
				score=score+10;
				game();
				sound(800);
				delay(130);
				nosound();
			}
		}
		if(j>=400)
		{
			break;
		}
	}
	//setcolor(GREEN);
	printf("Score %d",score);
	getch();
	cleardevice();
	menu();
}

void instruction()
{
	int ch1;
	cleardevice();
	settextstyle(1,0,1);
	setcolor(4);

	outtextxy(50,50,"This is PARA-COMMANDO");
	outtextxy(50,70,"Use the left, right keys to control the commando");
	outtextxy(50,100,"Use the left arrow to move the commando left");
	outtextxy(50,120,"Use the rigth arrow to move the commando right");
	outtextxy(50,140,"If the commando cannot reach the ship then game over");
	outtextxy(50,180,"When you score 500 you will win");
	outtextxy(50,200,"Best of Luck");

	setcolor(2);
	{
		outtextxy(50,400,"Press any key to return to main menu");
	}
	setcolor(5);
	{
		outtextxy(450,330,"Created by: ");
		outtextxy(450,350,"Bushalin");
		outtextxy(450,370,"Joydip");
		outtextxy(450,390,"Shethi");
	}
    /*	if(kbhit())
	{
		ch1=getch();
		if(ch1==77)
		{
			menu();
		}
		else
		{
			menu();
		}
	}      */
	getch();
	menu();
	closegraph();
       //	menu();
}

void credits()
{
	cleardevice();

	setcolor(5);
	{
		outtextxy(450,330,"Created by: ");
		outtextxy(450,350,"Bushalin");
		outtextxy(450,370,"Joydip");
		outtextxy(450,390,"Shethi");
	}
}