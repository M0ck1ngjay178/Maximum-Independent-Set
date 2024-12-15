/*================HEADER========================*/
/*= CMSC-3140-ANALYSIS OF ALGORITHMS           =*/
/*= FALL 2024-GROUP ASSIGNMENT 3, DUE: DEC.5th =*/
/*= GROUP 1: BONAL, GEREGA, RUFFING            =*/
/*==============================================*/

/*********LIBRARIES***************/
#include <iostream>
#include "graph.h"
#include <string>
#include <fstream>
#include <iostream>
#include <chrono>
#include <conio.h>
#include <ctime>
/********************************/

int main(int argc, char** argv) {

	/*********INITIALIZATION*****************/
	Matrix testing;
	bool flag = true;
	bool insert_flag = false;
	int decision;
	double B_Time;
	double G_Time;

	header();
	menu();
	/****************************************/

	/********************************WHILE LOOP FOR MAIN PROCESS**********************************************/
	while(flag)
	{

		/*********************Invalid Character Check*********************************/
         while(!(cin >> decision) || cin.peek() != '\n')
	   {
	     cout << "Please enter a number 1-4: ";
	     cin.clear();
	     cin.ignore(30000, '\n');            
	   }//end while
	   cin.get();
	   /******************************************************************************/

	   /****************************SWITCH CASE FOR MENU OPERATION**************************************************/
		switch (decision)
		{

			/******************Case1: INSERT****************/
			case 1:

				//ADDED TO RANDOMIZE THE ADDING OF VERTEXES
				if (insert_flag != true)
				{
						srand(time(0));
						int ran1;
						int ran2;

							for (int t = 0; t < V; t++) {

									ran1 = t; 
								ran2 = rand() % V; 


									while (ran1 == ran2) {
									ran2 = rand() % V; 
									}

									testing.insert(ran1, ran2); 
							}

						cout <<"Values Inserted" << endl;/**/
						insert_flag = true;
				}
				else
				{
					cout << "Already inserted values" << endl;
				}

					break;
			/************************************************/	

			/******************Case2: PRINT*****************/
			case 2:
				testing.printMatrix();
				break;
			/************************************************/

			/******************Case3: BRUTE FORCE*************/
			case 3:
				testing.bruteMax();
				testing.timeBruteForce();

				break;
			/************************************************/

			/******************Case4: GREEDY****************/
			case 4:
				testing.greedy();
				testing.timeGreedy();
				break;
			/************************************************/

			/******************Case5: CLEAR SCREEN***********/   	
			case 5:
				std::cout << "\033[2J\033[H";
				header();
	
				menu();
				break;
			/************************************************/

			/******************Case6: QUIT***********************/   	
			case 6:
				cout <<"Quitting...";
				flag = false;
				break;
			/****************************************************/

			
			/******************DEFAULT*************************/
			default:
				system("CLS");
				cout << "Invalid choice!!!"<< endl;
			/*************************************************/
		}//end switch
		/*****************************END SWITCH CASE*************************************************/

	}//end while
	/******************************** END WHILE LOOP **********************************************/
	return 0; //finish program
}//end main


	