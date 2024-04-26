#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<conio.h>
#include <windows.h>
#include"CC212SGL.h"
#pragma comment(lib,"CC212SGL.lib")

CC212SGL  x;

void print(char a[3][3])
{
	system("cls");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			printf("  %c  ", a[i][j]);
		printf("\n");
	}
}

void play(char *p, char a[3][3])
{
	
	char pos;
	int x;
	printf("choose your position player %c : ", *p);
	
	scanf_s("%d", &x);
	pos = x+'0';
	

	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3; j++)
		{
			if (a[i][j] == pos)
				a[i][j] = *p;
		}
	}


	if (*p == 'x')
		*p = 'o';
	else
		*p = 'x';

	
}

int whowin(char a[3][3])
{
					
	int c = 0 , Xc = 0 , Oc = 0; // counter for x amd o for each row

	//rows
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (a[i][j] == 'x')
				Xc++;
			else if (a[i][j] == 'o')
				Oc++;
			if (Xc == 3)
				return 1;
			else if (Oc == 3)
				return 2;
		}
		Xc = 0; Oc = 0;
	}


	int Xc1 = 0, Oc1 = 0; // counter for x amd o for each coloumn

	//coloumns
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (a[i][j] == 'x')
				Xc1++;
			else if (a[i][j] == 'o')
				Oc1++;
			if (Xc1 == 3)
				return 1;
			else if (Oc1 == 3)
				return 2;
		}
		Xc1 = 0; Oc1 = 0;
	}

	//diagonal
	if (a[0][0] == 'x' && a[1][1] == 'x' && a[2][2] == 'x')
		return 1;
	else if (a[0][0] == 'o' && a[1][1] == 'o' && a[2][2] == 'o')
		return 2;

	//reverese diagonal
	if (a[0][2] == 'x' && a[1][1] == 'x' && a[2][0] == 'x')
		return 1;
	else if (a[0][2] == 'o' && a[1][1] == 'o' && a[2][0] == 'o')
		return 2;

	//end
	for (int j = 0; j < 3; j++)
		for (int i = 0; i < 3; i++)
			if (a[i][j] != 'x' && a[i][j] != 'o')
				c++;
	if (c == 0)
		return 3;

	//continue
	return 0;

	
}

void main()
{

	

	char a[3][3] = { '1','2','3','4','5','6','7','8','9' };
	char player = 'x';
	char name1[50], name2[50];

	printf("Enter name of player 1 : \n");
	gets_s(name1);
	printf("Enter name of player 2 : ");
	gets_s(name2);
	printf("\n");
	
	x.setup();
	x.setFullScreenMode();
	x.hideCursor();


	
	while (1)
	{
		x.beginDraw();

		x.setDrawingColor(YELLOW);
		x.setDrawingThickness(50);
		x.setFontSizeAndBoldness(75,60);
		x.fillScreen(GREEN);
		x.drawCircle(800, 200, 200);
		x.drawLine(700,200,500,400);
		x.drawText(900,500,"TIC TAC TOE");
		x.drawLine(700,400,500,200);
		
				
			x.drawText(100, 720, "Press SPACE to start");
			if (GetAsyncKeyState(32))
				break;
		

		x.endDraw();
	}

	

	
		

		while (whowin(a) == 0)
		{
			print(a);
			play(&player, a);

		}

		print(a);
		

		
		if (whowin(a) == 1)
		{
			printf("The winner is %s \n CONGRATULATIONSSS!!!!!\n ", name1);
		}
		else if (whowin(a) == 2)
			printf("The winner is %s \n CONGRATULATIONSSS!!!!!\n ",name2);
		else if (whowin(a) == 3)
			printf(" It's a tie \n\n");

		


		



		
	
}