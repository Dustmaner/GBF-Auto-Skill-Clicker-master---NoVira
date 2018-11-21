// gw5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <stdlib.h> 
#include <time.h>       

using namespace std;

int randX() {
	return rand() % 30 - 15;
}
int randY() {
	return rand() % 22 - 11;
}
int randCustom(int delta) {
	return rand() % (delta*2) - delta;
}
int randD() {
	return rand() % 80 - 40;
}

void mouseClick(int sleepTime, int variationD, int variationX, int variationY) {
	mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	Sleep(sleepTime + variationD);
	cout << "X:" << variationX << ",\tY:" << variationY << ",\tTime(ms):" << variationD << "\n";
}

void swipeLeft(int offsetX, int variationX, int offsetY, int variationY, int sleepTime, int variantonD) {
	cout << "ID: Swipe Left\n";
	variationY = randCustom(8);
	variationX = randCustom(10);
	SetCursorPos(18 + offsetX + variationX / 2, 633 + offsetY + variationY);//left
	mouseClick(sleepTime, variantonD, variationY, variationX);
}

void swipeRight(int offsetX, int variationX, int offsetY, int variationY, int sleepTime, int variantonD) {
	cout << "ID: Swipe Right\n";
	variationY = randCustom(8);
	variationX = randCustom(10);
	SetCursorPos(460 + offsetX + variationX / 2, 633 + offsetY + variationY);//right
	mouseClick(sleepTime, variantonD, variationY, variationX);
}

void main()
{
	int sleepTime = 10;
	double refreshDelay = 0;
	ifstream inFile;
	int counter = 0;
	//int x;
	string x;
	char ch = 'A';
	int offsetX = 0;
	int offsetY = 0;
	string go = "y";
	string fileChoose = "1.txt";
	/* initialize random seed: */
	srand(time(NULL));
	int variationX;
	int variationY;
	int variantonD;
	bool zoom = 0;
	int currentChar = 0;

	inFile.open("Settings.txt");
	if (!inFile) {
		cerr << "Unable to open file " << "Settings.txt" << endl;
		exit(1);   // call system to stop
	}

	inFile >> offsetX;
	inFile >> offsetY;
	inFile >> sleepTime;

	//Load a file
	while (go != "`" || '\0') {
		cout << "--- --- --- --- ---\n";
		cout << "Loop #: " << counter << endl;
			
		
		counter++;
		cout << "choose your skill file: \n(no \".txt\" needed)" << endl;
		getline(cin, go);
		fileChoose = go + ".txt";

		inFile.close();
		inFile.open(fileChoose);
		if (!inFile) {
			cerr << "Unable to open file "<< fileChoose << endl;
			exit(1);   // call system to stop
		}
		
		//Run all lines of such file
		while (inFile >> x) {

			cout << "ID: x=" << x << endl;
			ch = x[0];
			variationX = randX();
			variationY = randY();
			variantonD = randD();

			//Zoomed out
			if (x == ("11") || x == ("12") || x == ("13") || x == ("14"))
			{
				if (zoom == 0) {
					SetCursorPos(50 + offsetX + variationX * 2, 609 + offsetY + variationY * 3);

					cout << "ID: Zooomed Out 1\n";

					mouseClick(sleepTime, variantonD, variationY, variationX);
					zoom = 1;
					currentChar = 1;
					variationX = randX();
					variationY = randY();
					variantonD = randD();
				}
				
			}
			if (x == ("21") || x == ("22") || x == ("23") || x == ("24"))
			{
				if (zoom == 0) {
					SetCursorPos(130 + offsetX + variationX * 2, 609 + offsetY + variationY * 3);

					cout << "ID: Zooomed Out 2\n";

					mouseClick(sleepTime, variantonD, variationY, variationX);
					zoom = 1;
					currentChar = 2;
					variationX = randX();
					variationY = randY();
					variantonD = randD();
				}
				
			}
			if (x == ("31") || x == ("32") || x == ("33") || x == ("34"))
			{
				if (zoom == 0) {
					SetCursorPos(212 + offsetX + variationX * 2, 609 + offsetY + variationY * 3);

					cout << "ID: Zooomed Out 3\n";

					mouseClick(sleepTime, variantonD, variationY, variationX);
					zoom = 1;
					currentChar = 3;
					variationX = randX();
					variationY = randY();
					variantonD = randD();
				}
				
			}
			if (x == ("41") || x == ("42") || x == ("43") || x == ("44"))
			{
				if (zoom == 0) {
					SetCursorPos(293 + offsetX + variationX * 2, 609 + offsetY + variationY * 3);

					cout << "ID: Zooomed Out 4\n";

					mouseClick(sleepTime, variantonD, variationY, variationX);
					zoom = 1;
					currentChar = 4;
					variationX = randX();
					variationY = randY();
					variantonD = randD();
				}
				
			}

			//Zoomed in and skills are in another character
			if ((x == ("11") || x == ("12") || x == ("13") || x == ("14")) && currentChar != 1)//Next skill is MC
			{
				if ((currentChar == 2)) {
					//cout << "\t2->1\n";
					swipeLeft(offsetX, variationX, offsetY, variationY, sleepTime, variantonD);
					

					variationX = randX();
					variationY = randY();
					variantonD = randD();
				}
				if ((currentChar == 3)) {
					//cout << "\t3->1\n";
					swipeLeft(offsetX, variationX, offsetY, variationY, sleepTime, variantonD);
					//cout << "\t3->1\n";
					Sleep(75 + randCustom(15));
					variationX = randX();
					variationY = randY();
					variantonD = randD();
					swipeLeft(offsetX, variationX, offsetY, variationY, sleepTime, variantonD);
					

					variationX = randX();
					variationY = randY();
					variantonD = randD();
				}
				if ((currentChar == 4)) {
					//cout << "\t4->1\n";
					swipeRight(offsetX, variationX, offsetY, variationY, sleepTime, variantonD);
					

					variationX = randX();
					variationY = randY();
					variantonD = randD();
				}
				currentChar = 1;
			}
			if ((x == ("21") || x == ("22") || x == ("23") || x == ("24")) && currentChar != 2)//Next skill is Char2
			{
				if ((currentChar == 3)) {
					//cout << "\t3->2\n";
					swipeLeft(offsetX, variationX, offsetY, variationY, sleepTime, variantonD);
					

					variationX = randX();
					variationY = randY();
					variantonD = randD();
				}
				if ((currentChar == 4)) {
					//cout << "\t4->2\n";
					swipeLeft(offsetX, variationX, offsetY, variationY, sleepTime, variantonD);
					//cout << "\t4->2\n";
					Sleep(75 + randCustom(15));
					variationX = randX();
					variationY = randY();
					variantonD = randD();
					swipeLeft(offsetX, variationX, offsetY, variationY, sleepTime, variantonD);
					

					variationX = randX();
					variationY = randY();
					variantonD = randD();
				}
				if ((currentChar == 1)) {	
					//cout << "\t1->2\n";
					swipeRight(offsetX, variationX, offsetY, variationY, sleepTime, variantonD);
					

					variationX = randX();
					variationY = randY();
					variantonD = randD();
				}
				currentChar = 2;
			}
			if ((x == ("31") || x == ("32") || x == ("33") || x == ("34")) && currentChar != 3)//Next skill is Char3
			{
				if ((currentChar == 4)) {
					//cout << "\t4->3\n";
					swipeLeft(offsetX, variationX, offsetY, variationY, sleepTime, variantonD);
					

					variationX = randX();
					variationY = randY();
					variantonD = randD();
				}
				if ((currentChar == 1)) {
					//cout << "\t1->3\n";
					swipeLeft(offsetX, variationX, offsetY, variationY, sleepTime, variantonD);
					Sleep(75 + randCustom(15));
					variationX = randX();
					variationY = randY();
					variantonD = randD();
					//cout << "\t1->3\n";
					swipeLeft(offsetX, variationX, offsetY, variationY, sleepTime, variantonD);
					

					variationX = randX();
					variationY = randY();
					variantonD = randD();
				}
				if ((currentChar == 2)) {	
					//cout << "\t2->3\n";
					swipeRight(offsetX, variationX, offsetY, variationY, sleepTime, variantonD);
					

					variationX = randX();
					variationY = randY();
					variantonD = randD();
				}
				currentChar = 3;
			}
			if ((x == ("41") || x == ("42") || x == ("43") || x == ("44")) && currentChar != 4)//Next skill is Char4
			{
				if ((currentChar == 1)) {	
					//cout << "\t1->4\n";
					swipeLeft(offsetX, variationX, offsetY, variationY, sleepTime, variantonD);
					

					variationX = randX();
					variationY = randY();
					variantonD = randD();
				}
				if ((currentChar == 2)) {
					//cout << "\t2->4\n";
					swipeRight(offsetX, variationX, offsetY, variationY, sleepTime, variantonD);
					Sleep(75 + randCustom(15));
					variationX = randX();
					variationY = randY();
					variantonD = randD();
					//cout << "\t2->4\n";
					swipeRight(offsetX, variationX, offsetY, variationY, sleepTime, variantonD);
					

					variationX = randX();
					variationY = randY();
					variantonD = randD();
				}
				if ((currentChar == 3)) {	
					//cout << "\t3->4\n";
					swipeRight(offsetX, variationX, offsetY, variationY, sleepTime, variantonD);
					

					variationX = randX();
					variationY = randY();
					variantonD = randD();
				}
				currentChar = 4;
			}
			
			//Summon
			if ((x == ("51") || x == ("52") || x == ("53") || x == ("54") || x == ("55") || x == ("56")) && zoom == 1) {

				variationX = randCustom(20);
				SetCursorPos(48 + offsetX + variationX *2, 477 + offsetY + variationY);//Back
				mouseClick(sleepTime, variantonD, variationY, variationX);

				variationX = randX();
				variationY = randCustom(15);
				variantonD = randD();
				SetCursorPos(387 + offsetX + variationX * 2, 607 + offsetY + variationY * 3);//Open Summons
				mouseClick(sleepTime, variantonD, variationY, variationX);

				variationX = randX();
				variationY = randCustom(15);
				variantonD = randD();
				if (x == ("56")) {
					SetCursorPos(429 + offsetX + variationX, 607 + offsetY + variationY * 3);//Shiva 
					mouseClick(sleepTime, variantonD, variationY, variationX);

					variationY = randY();
					SetCursorPos(346 + offsetX + variationX * 3, 613 + offsetY + variationY / 3);//OK
					//mouseClick(sleepTime, variantonD, variationY, variationX);
					variationX = randX();
					variationY = randY();
					variantonD = randD();
				}
				Sleep(100 + variantonD);
			}

			

			//Character skills
			if (x == ("11") || x == ("21") || x == ("31") || x == ("41")) {

				//cout << "ID: Character 1 Skill\n";

				SetCursorPos(155 + offsetX + variationX, 642 + offsetY + variationY);
			}//1
			if (x == ("12") || x == ("22") || x == ("32") || x == ("42")) {

				//cout << "ID: Character 2 Skill\n";

				SetCursorPos(240 + offsetX + variationX, 642 + offsetY + variationY);
			}//2
			if (x == ("13") || x == ("23") || x == ("33") || x == ("43")) {

				//cout << "ID: Character 3 Skill\n";

				SetCursorPos(324 + offsetX + variationX, 642 + offsetY + variationY);
			}//3
			if (x == ("14") || x == ("24") || x == ("34") || x == ("44")) {

				//cout << "ID: Character 4 Skill\n";

				SetCursorPos(407 + offsetX + variationX, 642 + offsetY + variationY);
			}//4

			//Skills for 1 Char
			if (x == ("1")) {
				SetCursorPos(146 + offsetX + variationX, 399 + offsetY + variationY);
				Sleep(100 + randCustom(25));
			}//1
			if (x == ("2")) {
				SetCursorPos(240 + offsetX + variationX, 399 + offsetY + variationY);
				Sleep(100 + randCustom(25));
			}//2
			if (x == ("3")) {
				SetCursorPos(338 + offsetX + variationX, 399 + offsetY + variationY);
				Sleep(100 + randCustom(25));
			}//3
			if (x == ("4")) {
				SetCursorPos(146 + offsetX + variationX, 559 + offsetY + variationY);
				Sleep(100 + randCustom(25));
			}//4
			if (x == ("5")) {
				SetCursorPos(240 + offsetX + variationX, 559 + offsetY + variationY);
				Sleep(100 + randCustom(25));
			}//5
			if (x == ("6")) {
				SetCursorPos(338 + offsetX + variationX, 559 + offsetY + variationY);
				Sleep(100 + randCustom(25));
			}//6

			
			if (ch  != 'r') {
				mouseClick(sleepTime, variantonD, variationY, variationX);
			}
			
		}
		variationX = rand() % 30 - 15;
		variationY = rand() % 20 - 10;
		variantonD = rand() % 80 - 40;
		SetCursorPos(368 + offsetX + variationX*3, 473 + variationY);//Attack
		mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		Sleep(sleepTime + variantonD);

		variationX = rand() % 30 - 15;
		variationY = rand() % 20 - 10;
		variantonD = rand() % 80 - 40;
		SetCursorPos(42 + offsetX + variationX*2, 502 + variationY/2);//AUTO
		mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

		//Refresh after delay
		//ch = x[0];
		if (ch == 'r') {
			refreshDelay = (stod(x.substr(1)) * 1000);
			Sleep(refreshDelay + variantonD);
			SetCursorPos(352 + offsetX + variationX, 1001 + offsetY + variationY);
			mouseClick(sleepTime, variantonD, variationY, variationX);
		}

		inFile.close();
		zoom = 0;

		//system("pause");

	}
}