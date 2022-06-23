//============================================================================
// Name        : .cpp
// Author      : FAST CS Department
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Rush Hour...
//============================================================================

/*

Name# Zain Ul abideen
21I-0747

*/

#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
#include <fstream>
#include <ctime>

using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
 
 
//global variables
int scores[50];
int const startTime = clock()/CLOCKS_PER_SEC;
string scoreStg = "Score=", score = "0";
int scoreInt = 0;
int dataSet[20][20];
int x_axis=0, y_axis=0;
bool passengerFlag1 = true, passengerFlag2 = true, passengerFlag3 = true, passengerFlag4 = true, pickPassflag=true;
bool pickPassflagInner = true, pickedStatus= false;
int takenCordinates[100][2];
long takenCordinatesCounter = 0;
bool leader_board = false, menu = true, game=false, car_selection = false, redCar = false, yellowCar = false, functionCall = true, oneTime = true;
int passengerLoc[20][20], tree[20][20], boxes[20][20];
int passLocCounter=0;
int timerMin = 2, timerSec = 60, size;
string timerMin_S, timerSec_S;
string userName, ptr;
string *namePtr = new string;

int x_p_1, y_p_1, x_p_2, y_p_2, x_p_3, y_p_3, x_p_4, y_p_4; //passenger one, two and three

//This function is to generate pessenger random locations
void pickPassengersLoc(){
	InitRandomizer();	
	
	
	//passenger one
	while(pickPassflag)
	{
		x_p_1 = GetRandInRange(0,19), y_p_1 = GetRandInRange(0,19);
		for(int i = 0; i < 50 ; i++)
		{
			if(x_p_1 == takenCordinates[i][0] and y_p_1 == takenCordinates[i][1])
			{
				pickPassflagInner = false;
			}
		}
		if(pickPassflagInner)
		{
			pickPassflag = false;
			takenCordinates[takenCordinatesCounter][0] = x_p_1;
			takenCordinates[takenCordinatesCounter][1] = y_p_1;
			++takenCordinatesCounter;
			passengerLoc[x_p_1][y_p_1] = 1;
		}
	}
	
	pickPassflagInner = true;
	pickPassflag = true;
	
	
	//passenger 2
	while(pickPassflag)
	{
		x_p_2 = GetRandInRange(0,19), y_p_2 = GetRandInRange(0,19);
		for(int i = 0; i < 50 ; i++)
		{
			if(x_p_2 == takenCordinates[i][0] and y_p_2 == takenCordinates[i][1])
			{
				pickPassflagInner = false;
			}
		}
		if(pickPassflagInner)
		{
			pickPassflag = false;
			takenCordinates[takenCordinatesCounter][0] = x_p_2;
			takenCordinates[takenCordinatesCounter][1] = y_p_2;
			++takenCordinatesCounter;
			passengerLoc[x_p_2][y_p_2] = 1;
		}
	}
	
	pickPassflagInner = true;
	pickPassflag = true;
	
	
	//passenger 3
	while(pickPassflag)
	{
		x_p_3 = GetRandInRange(0,19), y_p_3 = GetRandInRange(0,19);
		for(int i = 0; i < 50 ; i++)
		{
			if(x_p_3 == takenCordinates[i][0] and y_p_3 == takenCordinates[i][1])
			{
				pickPassflagInner = false;
			}
		}
		if(pickPassflagInner)
		{
			pickPassflag = false;
			takenCordinates[takenCordinatesCounter][0] = x_p_3;
			takenCordinates[takenCordinatesCounter][1] = y_p_3;
			++takenCordinatesCounter;
			passengerLoc[x_p_3][y_p_3] = 1;
		}
	}
	
	pickPassflagInner = true;
	pickPassflag = true;
	
	//passenger 4
	while(pickPassflag)
	{
		x_p_4 = GetRandInRange(0,19), y_p_4 = GetRandInRange(0,19);
		for(int i = 0; i < 50 ; i++)
		{
			if(x_p_4 == takenCordinates[i][0] and y_p_4 == takenCordinates[i][1])
			{
				pickPassflagInner = false;
			}
		}
		if(pickPassflagInner)
		{
			pickPassflag = false;
			takenCordinates[takenCordinatesCounter][0] = x_p_4;
			takenCordinates[takenCordinatesCounter][1] = y_p_4;
			++takenCordinatesCounter;
			passengerLoc[x_p_4][y_p_4] = 1;
		}
	}
	
}


bool passengerDropFlag1 = false, passengerDropFlag2 = false, passengerDropFlag3 = false, passengerDropFlag4 = false;
bool dropPassflag=true, dropPassflagInner = true;
int x_pd_1, y_pd_1, x_pd_2, y_pd_2, x_pd_3, y_pd_3, x_pd_4, y_pd_4;

//This function is to generate pessenger drop off random locations
void dropPassengersLoc(){
	
	
	//passenger one
	while(dropPassflag)
	{
		x_pd_1 = GetRandInRange(0,19), y_pd_1 = GetRandInRange(0,19);
		for(int i = 0; i < 50 ; i++)
		{
			if(x_pd_1 == takenCordinates[i][0] and y_pd_1 == takenCordinates[i][1])
			{
				dropPassflagInner = false;
			}
		}
		if(dropPassflagInner)
		{
			dropPassflag = false;
			//cout << "Ball X: " << x_p_1 << " Ball Y: " << y_p_1 << endl;
			takenCordinates[takenCordinatesCounter][0] = x_pd_1;
			takenCordinates[takenCordinatesCounter][1] = y_pd_1;
			++takenCordinatesCounter;
		}
	}
	
	dropPassflagInner = true;
	dropPassflag = true;
	
	
	//passenger 2
	while(dropPassflag)
	{
		x_pd_2 = GetRandInRange(0,19), y_pd_2 = GetRandInRange(0,19);
		for(int i = 0; i < 50 ; i++)
		{
			if(x_pd_2 == takenCordinates[i][0] and y_pd_2 == takenCordinates[i][1])
			{
				dropPassflagInner = false;
			}
		}
		if(dropPassflagInner)
		{
			dropPassflag = false;
			//cout << "Ball X: " << x_p_2 << " Ball Y: " << y_p_2 << endl;
			takenCordinates[takenCordinatesCounter][0] = x_pd_2;
			takenCordinates[takenCordinatesCounter][1] = y_pd_2;
			++takenCordinatesCounter;
		}
	}
	
	dropPassflagInner = true;
	dropPassflag = true;
	
	
	//passenger 3
	while(dropPassflag)
	{
		x_pd_3 = GetRandInRange(0,19), y_pd_3 = GetRandInRange(0,19);
		for(int i = 0; i < 50 ; i++)
		{
			if(x_pd_3 == takenCordinates[i][0] and y_pd_3 == takenCordinates[i][1])
			{
				dropPassflagInner = false;
			}
		}
		if(dropPassflagInner)
		{
			dropPassflag = false;
			takenCordinates[takenCordinatesCounter][0] = x_pd_3;
			takenCordinates[takenCordinatesCounter][1] = y_pd_3;
			++takenCordinatesCounter;
		}
	}
	
	dropPassflagInner = true;
	dropPassflag = true;
	
	//passenger 4
	while(dropPassflag)
	{
		x_pd_4 = GetRandInRange(0,19), y_pd_4 = GetRandInRange(0,19);
		for(int i = 0; i < 50 ; i++)
		{
			if(x_pd_4 == takenCordinates[i][0] and y_pd_4 == takenCordinates[i][1])
			{
				dropPassflagInner = false;
			}
		}
		if(dropPassflagInner)
		{
			dropPassflag = false;
			takenCordinates[takenCordinatesCounter][0] = x_pd_4;
			takenCordinates[takenCordinatesCounter][1] = y_pd_4;
			++takenCordinatesCounter;
		}
	}
	
}



void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


int carH = 80 ;
int xI = 0, yI = 800-carH;

// this is red car
void drawCar() {
	DrawSquare(xI, yI, carH, colors[RED]);
	glutPostRedisplay();
}

// this is yellow car
void drawCar2() {
	DrawSquare(xI, yI, carH, colors[ORANGE]);
	glutPostRedisplay();
}



bool flag = true;
void moveCar1() {
	
	if (xI > 10 && flag) {
		xI -= 10;
		cout << "going left";
		if(xI < 100)			
			flag = false;

	}
	else if (xI < 1010 && !flag) {
		cout << "go right";
		xI += 10;
		if (xI > 900)
			flag = true;
	}
}

/*
 * Main Canvas drawing function.
 * */

//this function will be responsible for grid lines
void gridLines()
{
	for(int i = 40; i < 800 ; i += 40)
		DrawLine( i , 0 ,  i , 800 , 0 , colors[BLACK] );	
}

//this function convert x-blocks to pixels
int xCordi_to_xPix(int x)
{
	return (x*carH);
	
}

//this function convert y-blocks to pixels
int yCordi_to_yPix(int y)
{
	return (800 - (y*(carH))-40 );
}

//this function convert x-blocks to pixels for passenger
int xCord_to_xPx(int x)
{
	return (x*(carH)+20);
	
}

//this function convert y-blocks to pixels for passenger
int yCord_to_yPx(int y)
{
	return (800 - (y*(carH))-25);
}


// this will display Menu Window
void MenuDisplay()
{

	
	DrawString( xCordi_to_xPix(8) , yCordi_to_yPix(4), "Rush Hour Game", colors[BLACK]);
	DrawRoundRect(xCordi_to_xPix(7) , yCordi_to_yPix(8),280,80,colors[LIME_GREEN],20);
	DrawString( xCordi_to_xPix(9) , yCordi_to_yPix(7)-8, "LeaderBoard", colors[BLACK]);
	
	DrawRoundRect(xCordi_to_xPix(7) , yCordi_to_yPix(12),280,80,colors[LIME_GREEN],20);
	DrawString( xCordi_to_xPix(9) , yCordi_to_yPix(11)-8, "Choose Car", colors[BLACK]);

}

// this will display car selection window
void carSelection(){	
	DrawString( xCordi_to_xPix(7)+5 , yCordi_to_yPix(1)+10, "Please Select your car!", colors[BLACK]);
	
	DrawRoundRect(xCordi_to_xPix(7) , yCordi_to_yPix(3),280,80,colors[RED],20);
	DrawString( xCordi_to_xPix(9)+10 , yCordi_to_yPix(2)-8, "Red Car", colors[BLACK]);
	
	DrawRoundRect(xCordi_to_xPix(7) , yCordi_to_yPix(6),280,80,colors[ORANGE],20);
	DrawString( xCordi_to_xPix(9)+7 , yCordi_to_yPix(5)-8, " Yellow Car", colors[BLACK]);
}


// this will display leaderboard window
void leaderboard()
{
	DrawString( xCordi_to_xPix(8) , yCordi_to_yPix(1), "LeaderBoard", colors[BLACK]);
	
	ptr = to_string(scores[0]);
	DrawString( xCordi_to_xPix(9) , yCordi_to_yPix(2), ptr, colors[BLACK]);

	ptr = to_string(scores[1]);
	DrawString( xCordi_to_xPix(9) , yCordi_to_yPix(3), ptr, colors[BLACK]);
	
	ptr = to_string(scores[2]);
	DrawString( xCordi_to_xPix(9) , yCordi_to_yPix(4), ptr, colors[BLACK]);
	
	ptr = to_string(scores[3]);
	DrawString( xCordi_to_xPix(9) , yCordi_to_yPix(5), ptr, colors[BLACK]);
	
	ptr = to_string(scores[4]);
	DrawString( xCordi_to_xPix(9) , yCordi_to_yPix(6), ptr, colors[BLACK]);
	
	ptr = to_string(scores[5]);
	DrawString( xCordi_to_xPix(9) , yCordi_to_yPix(7), ptr, colors[BLACK]);
	
	ptr = to_string(scores[6]);
	DrawString( xCordi_to_xPix(9) , yCordi_to_yPix(8), ptr, colors[BLACK]);
	
	ptr = to_string(scores[7]);
	DrawString( xCordi_to_xPix(9) , yCordi_to_yPix(9), ptr, colors[BLACK]);
	
	ptr = to_string(scores[8]);
	DrawString( xCordi_to_xPix(9) , yCordi_to_yPix(10), ptr, colors[BLACK]);
	
	ptr = to_string(scores[9]);
	DrawString( xCordi_to_xPix(9) , yCordi_to_yPix(11), ptr, colors[BLACK]);
	
}

// this will display game map window
void GameDisplay()/**/{

	score = to_string(scoreInt);
	DrawString( xCordi_to_xPix(1)+5 , yCordi_to_yPix(0)+10, scoreStg + score, colors[BLACK]);
	
	if(pickedStatus)
		DrawString( xCordi_to_xPix(5) , yCordi_to_yPix(0)+10, "PICKED", colors[GREEN]);
	
		
	timerMin_S = to_string(timerMin);
	timerSec_S = to_string(timerSec);
	DrawString( xCordi_to_xPix(11)+5 , yCordi_to_yPix(0)+10, timerMin_S + " : " + timerSec_S, colors[BLACK]);
		
	if(passengerFlag1){
		DrawCircle(xCord_to_xPx(y_p_1), yCord_to_yPx(x_p_1),15,colors[BLACK]);		
	}
	
	if(passengerFlag2){
		DrawCircle(xCord_to_xPx(y_p_2), yCord_to_yPx(x_p_2),15,colors[BLACK]);
	}
	
	if(passengerFlag3){
		DrawCircle(xCord_to_xPx(y_p_3), yCord_to_yPx(x_p_3),15,colors[BLACK]);
	}
	
	if(passengerFlag4){
		DrawCircle(xCord_to_xPx(y_p_4), yCord_to_yPx(x_p_4),15,colors[BLACK]);
	}
	
	
	//for passenger drop location
	if(passengerDropFlag1){
		DrawCircle(xCord_to_xPx(y_pd_1), yCord_to_yPx(x_pd_1),15,colors[GREEN]);		
	}
	
	if(passengerDropFlag2){
		DrawCircle(xCord_to_xPx(y_pd_2), yCord_to_yPx(x_pd_2),15,colors[GREEN]);
	}
	
	if(passengerDropFlag3){
		DrawCircle(xCord_to_xPx(y_pd_3), yCord_to_yPx(x_pd_3),15,colors[GREEN]);
	}
	
	if(passengerDropFlag4){
		DrawCircle(xCord_to_xPx(y_pd_4), yCord_to_yPx(x_pd_4),15,colors[GREEN]);
	}
	
	
	for(int i = 6; i <= 10 ; i++)
		dataSet[9][i] = 1;
	for(int i = 6; i <= 10 ; i++)
		dataSet[i][6] = 1;
	for(int i = 3; i <= 7 ; i++)
		dataSet[2][i] = 1;
	for(int i = 3; i <= 7 ; i++)
		dataSet[i][15] = 1;
	for(int i = 3; i <= 7 ; i++)
		dataSet[15][i] = 1;
	for(int i = 13; i <= 19 ; i++)
		dataSet[12][i] = 1;
	for(int i = 12; i <= 17 ; i++)
		dataSet[i][13] = 1;
	dataSet[15][17] = 1;
	for(int i = 2; i <= 4 ; i++)
		dataSet[i][11] = 1;
	dataSet[2][12] = 1;
	//dataSet[0][2] = 1;
	
	//for trees
	tree[3][2] = 1;
	tree[4][18] = 1;
	tree[11][1] = 1;
	
	//for boxes
	boxes[7][8] = 1;
	boxes[11][9] = 1;
	boxes[18][15] = 1;

	
	for(int i=0; i < 20; i++)
	{
		for(int j = 0; j < 20; j++)
		{
			
			if(dataSet[i][j] == 1)
			{
				DrawSquare(xCordi_to_xPix(j), yCordi_to_yPix(i), 41, colors[BLACK]);
				
			}
			
			if(tree[i][j] == 1)
			{
				DrawSquare(xCordi_to_xPix(j), yCordi_to_yPix(i), 41, colors[GREEN]);
				
			}
			
			if(boxes[i][j] == 1)
			{
				DrawSquare(xCordi_to_xPix(j), yCordi_to_yPix(i), 41, colors[YELLOW]);
				
			}
		}
	}
	
	if(oneTime)
	{
		for(int i=0; i < 20; i++)
		{
			for(int j = 0; j < 20; j++)
			{
				if(dataSet[i][j] == 1)
				{	
					takenCordinates[takenCordinatesCounter][0] = i;
					takenCordinates[takenCordinatesCounter][1] = j;
					++takenCordinatesCounter;
				}
			}
		}
	}
	oneTime = false;


	gridLines();
	if(redCar)
		drawCar();
	if(yellowCar)
		drawCar2();

}



/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */
 

void NonPrintableKeys(int key, int x, int y) {
	if (
		key == GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		//xI -= 10;
		if(xI >= 0+carH-20) //checking boundries
		{	
			
			if(dataSet[x_axis][y_axis-1] != 1)//check walls
			{
				xI -= carH;
				if(redCar)
				{
					if(tree[x_axis][y_axis-1] == 1 || boxes[x_axis][y_axis-1] == 1) //checking trees
					{
						scoreInt -= 2;
					}
					if(passengerLoc[x_axis][y_axis-1] == 1 && pickedStatus) //check passengers locations
					{
						scoreInt -= 5;
					}
				}
				if(yellowCar)
				{
					if(tree[x_axis][y_axis-1] == 1 || boxes[x_axis][y_axis-1] == 1) //checking trees
					{
						scoreInt -= 4;
					}
					if(passengerLoc[x_axis][y_axis-1] == 1 && pickedStatus)//check passengers locations
					{
						scoreInt -= 5;
					}
				}
				
				y_axis -= 1;
				
			}
			
			
		}
		

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		
		if(xI <= 800-carH-20)
		{
			if(dataSet[x_axis][y_axis+1] != 1)
			{
				xI += carH;
				if(redCar)
				{
					if(tree[x_axis][y_axis+1] == 1 || boxes[x_axis][y_axis+1] == 1)
					{
						scoreInt -= 2;
					}
					if(passengerLoc[x_axis][y_axis+1] == 1 && pickedStatus)
					{
						scoreInt -= 5;
					}	
				}
				if(yellowCar)
				{
					if(tree[x_axis][y_axis+1] == 1 || boxes[x_axis][y_axis+1] == 1)
					{
						scoreInt -= 4;
					}
					if(passengerLoc[x_axis][y_axis+1] == 1 && pickedStatus)
					{
						scoreInt -= 5;
					}
				}
				y_axis += 1;
			}
		}
	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		//yI += 10;
		
		if(yI < 800-carH)
		{	
			cout << dataSet[x_axis][y_axis+1] << endl;
			if(dataSet[x_axis-1][y_axis] != 1)
			{
				yI += (carH);
				//for trees
				if(redCar)
				{
					if(tree[x_axis-1][y_axis] == 1 || boxes[x_axis-1][y_axis] == 1)
					{
						scoreInt -= 2;
					}
					if(passengerLoc[x_axis-1][y_axis] == 1 && pickedStatus)
					{
						scoreInt -= 5;
					}	
				}
				if(yellowCar)
				{
					if(tree[x_axis-1][y_axis] == 1 || boxes[x_axis-1][y_axis] == 1)
					{
						scoreInt -= 4;
					}
					if(passengerLoc[x_axis-1][y_axis] == 1 && pickedStatus)
					{
						scoreInt -= 5;
					}
				}
				x_axis -= 1;
			}
		}
	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		//yI -= 10;
		if(yI > 0)
		{
			cout << dataSet[x_axis][y_axis+1] << endl;
			if(dataSet[x_axis+1][y_axis] != 1)
			{
				yI -= (carH);
				if(redCar)
				{
					if(tree[x_axis+1][y_axis] == 1 || boxes[x_axis+1][y_axis] == 1)
					{
						scoreInt -= 2;
					}
					if(passengerLoc[x_axis+1][y_axis] == 1 && pickedStatus)
					{
						scoreInt -= 5;
					}	
				}
				if(yellowCar)
				{
					if(tree[x_axis+1][y_axis] == 1 || boxes[x_axis+1][y_axis] == 1)
					{
						scoreInt -= 4;
					}
					if(passengerLoc[x_axis+1][y_axis] == 1 && pickedStatus)
					{
						scoreInt -= 5;
					}
				}
				x_axis += 1;

			}
		}
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}




/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}
	
	if (key == 32 /* Escape key ASCII*/) {
		cout << "y_p_1: " << y_p_1 << " " << "x_p_1: " << x_p_1 << endl;
		//for pick passenger location
		if(y_axis == (y_p_1) and x_axis == x_p_1 and !pickedStatus)
		{
			passengerFlag1 = false;
			passengerDropFlag1 = true;
			pickedStatus= true;
		}
		
		if(y_axis == (y_p_2) and x_axis == x_p_2 and !pickedStatus)
		{
			passengerFlag2 = false;
			passengerDropFlag2 = true;
			pickedStatus= true;
		}
		
		if(y_axis == (y_p_3) and x_axis == x_p_3 and !pickedStatus)
		{
			passengerFlag3 = false;
			passengerDropFlag3 = true;
			pickedStatus= true;
		}
		
		if(y_axis == (y_p_4) and x_axis == x_p_4 and !pickedStatus)
		{
			passengerFlag4 = false;
			passengerDropFlag4 = true;
			pickedStatus= true;
		}
		
		
		//for drop passenger location
		if(y_axis == (y_pd_1) and x_axis == x_pd_1)
		{
			passengerDropFlag1 = false;
			passengerFlag1 = true;
			scoreInt += 10;
			pickedStatus= false;
		}
		
		if(y_axis == (y_pd_2) and x_axis == x_pd_2)
		{
			passengerDropFlag2 = false;
			passengerFlag2 = true;
			scoreInt += 10;
			pickedStatus= false;
		}
		
		if(y_axis == (y_pd_3) and x_axis == x_pd_3)
		{
			passengerDropFlag3 = false;
			passengerFlag3 = true;
			scoreInt += 10;
			pickedStatus= false;
		}
		
		if(y_axis == (y_pd_4) and x_axis == x_pd_4)
		{
			passengerDropFlag4 = false;
			passengerFlag4 = true;
			scoreInt += 10;
			pickedStatus= false;
		}
		
		
	 // exit the program when escape key is pressed.
		
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
			{
		//do something if b is pressed
		cout << "b pressed" << endl;

	}
	
	
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	timerSec -= 1;
	if(timerMin == 0 && timerSec == 0)
	{
		glutDestroyWindow(glutGetWindow());
		if(scoreInt >= 100)
		{
			cout << "Congrates " << *namePtr << "! You won.";
		}
		else
		{
			cout << "Oops " << *namePtr << "! You lost.";
		}
		
		fstream putData;
	
		putData.open("highScores.txt", ios:: app);
		{
			putData << scoreInt;
		}
		
		putData.close();
	}
	
	if(timerSec == 0)
	{
		timerMin -= 1;
		timerSec = 59;
	}
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
	{
		
		//leaderboard btn
		if(x >= 280 && y >= 250 && x <= 550 && (y <= 315) && menu)
		{
			menu = false;
			leader_board = true;
		}
		
		
		//choose car button
		if(x >= 280 && y >= 390 && x <= 550 && (y <= 460) && menu)
		{
			//cout << "Pressed";
			menu = false;
			car_selection = true;
		}
		
		//car color selection
		
		//if red Car
		if(x >= 280 && y >= 70 && x <= 550 && (y <= 140) && car_selection)
		{
			redCar = true;
			car_selection = false;
			game = true;
			cout << "Red";
			
		}
		
		
		//if yellow car
		if(x >= 280 && y >= 180 && x <= 550 && (y <= 245) && car_selection)
		{
			yellowCar = true;
			car_selection = false;
			game = true;
			cout << "Yellow";
		}

	}
	else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			cout<<"Right Button Pressed"<<endl;

	}
	glutPostRedisplay();
}







//for changing the windows (All of that function which we want to display is called in this function)
void Main()
{
		glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			1/*Blue Component*/, 1 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT);
	if(menu)
		MenuDisplay();
	if(car_selection)
		carSelection();
	if(leader_board)
		leaderboard();
	if(game)
		GameDisplay();
	
	
	if(functionCall)
	{

		GameDisplay();
		pickPassengersLoc();
		dropPassengersLoc();
		
	}
	
	functionCall = false;
	
	glutSwapBuffers();
	

}


/*
 * our gateway main function
 * */

//This is main function
int main(int argc, char*argv[]) {

	//variables
	//bool 
	cout << endl << "Enter your Name: ";
	getline(cin, userName);
	
	namePtr = &userName;
	cout << *namePtr;
	
	
	int width = 800, height = 800; // i have set my window size to be 800 x 600

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Rush Hour by Zain"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...
	//file handling
	string line;
	int lineNum = 1;
	fstream getData;
	
	scores[50];
	
	getData.open("highScores.txt", ios::in);
	
	while(!getData.eof())
	{
		getData >> scores[size];
		++size;
	}
	
	--size;
	getData.close();
	for(int i = 0; i < size;i++)
	{
		for(int j = i+1; j <  size; j++)
		{
			if(scores[i] < scores[j])
			{
				int temp = scores[i];
				scores[i] = scores[j];
				scores[j] = temp;
			}
		}
	}
	
	
	
	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
	
//bool leaderboard = false, menu = false, game=false, carSelection = false;
	//if(game)
	//	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	
	//if(menu)
	//	glutDisplayFunc(MenuDisplay);
	glutDisplayFunc(Main);
	/*if(car_selection)
		glutDisplayFunc(carSelection);
		
	if(leader_board)
		glutDisplayFunc(leaderboard);*/
		
		
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);
	//GameDisplay();
	//random values
	
	
	for(int i=0; i < 20; i++)
			{
				for(int j = 0; j < 20; j++)
				{
					if(dataSet[i][j] == 1)
					{	
						cout << "i--: " << i << " j--: " << j << endl;
					}
				}
			}

	//for user car start cordinates
	takenCordinates[takenCordinatesCounter][0] = 0;
	takenCordinates[takenCordinatesCounter][1] = 1;
	takenCordinatesCounter++;
	

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	
	


	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* RushHour_CPP_ */
