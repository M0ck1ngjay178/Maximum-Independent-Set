//========LIBRARIES===============
#include <iomanip>
#include "graph.h"
#include <string>
#include <fstream>
#include <iostream>
#include <chrono>
//constexpr int V = 5;
using namespace std;
//================================

//========================WELCOME BANNER===================================
void header(void){
	cout <<"--------------------------------------------------------\n";
	cout <<"----Welcome to The Maximum Independent Graph Program ---\n";
	cout <<"--------------------------------------------------------\n\n";
}
//=========================================================================

//======================MENU BANNER=======================================
void menu(void){
	cout <<"--------------------------------------------------------\n";
	cout <<"- 1. INSERT VALUE 				        -\n";
	cout <<"- 2. PRINT MATRIX 				        -\n";
	cout <<"- 3. BRUTE FORCE ALGORITHM 				-\n";
	cout <<"- 4. GREEDY ALGORITHM 					-\n";
	cout <<"- 5. CLEAR SCREEN 				        -\n";
	cout <<"- 6. QUIT 						-\n";
	cout <<"--------------------------------------------------------\n\n";
}
//========================================================================

//===================CLEAR MATRIX========================
void Matrix :: clrMaxSet(){
	// Clear maxSet
	for (int i = 0; i < V; i++)
    {
        maxSet[i] = -1;
		included[i]= false;
		degree[i] = 0;
    }
}
//=======================================================

//================BUILD ADJACENCY MATRIX==================
Matrix::Matrix()
{
	for(int i = 0; i < V; i++)
	{
		for(int j = 0; j < V; j++)
		{
			adjMatrix[i][j] = 0;
		}
	}

	for (int z = 0; z<V; z++)
	{
		maxSet[z] = -1; //CHANGEDfrom 0 to -1 using -1 to show none intilized slots
		included[z] = false; 
        degree[z] = 0;       
	}
}
//========================================================

//================INSERT VALUES INTO MATRIX===================
void Matrix::insert(int u, int v)
{
	if(u < V && v < V)
	{
		adjMatrix[u][v] = 1;
		adjMatrix[v][u] = 1;
	}
}
//=========================================================


//========GENERATE MULUPLE INSERT INSTANCES==================
//NOT exactly working rn
void Matrix :: generateInserts() {
    int numInserts;
    cout << "How many insert statements? ";
    cin >> numInserts;

    for (int i = 0; i < numInserts; ++i) {
        int row, col;
        cout << "Enter values for insert " << i + 1 << " (row col): ";
        cin >> row >> col;
        insert(row, col);
    }
}
//===============================================================

//==============REMOVE VALUES FROM MATRIX========================
void Matrix::remove(int u, int v)
{
	if(u < V && v < V)
	{
		adjMatrix[u][v] = 0;
		adjMatrix[v][u] = 0;
	}
}
//=============================================================

//=================PRINT MATRIX==============================
void Matrix::printMatrix(void) const
{
	cout <<"-------------Adjacency Matrix-------------\n";
	// Print the adjacency matrix
    for (int i = 0; i < V; i++) 
	{
        for (int j = 0; j < V; j++) 
		{
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
	cout <<"------------------------------------------\n";
}
//=============================================================

//===================INDEPENDENT CHECK=============================================
// new independent
bool Matrix::isIndependent(int v, const int currentSet[], int currentSize) const {
    for (int i = 0; i < currentSize; i++) {
        if (adjMatrix[currentSet[i]][v] == 1) { // Check if vertex `v` is connected
            return false; // Not independent
        }
    }
    return true; // Vertex is independent
}
//==================================================================================

//================APPEND MATRIX========================================
//new append
void Matrix::appendMax(int n) {
    for (int i = 0; i < V; i++) {
        if (maxSet[i] == -1) { // Find the first empty spot in maxSet
            maxSet[i] = n; // Add vertex `n` (adjust indexing if necessary)
            return;
        }
    }
}
//====================================================================

bool Matrix:: check24hrs(chrono::time_point<chrono::high_resolution_clock> start, double limitSeconds) {
    auto now = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = now - start;
    return elapsed.count() > limitSeconds;
}




//==========================BRUTE FORCE===============================
//brute recursion
void Matrix::bruteForceRecursive(int index) {
    
	//Check if algorithm exeeds 24hrs
	if (check24hrs(start, 86400)) { // Check if 24 hours have passed
        cout << "Brute force terminated: Exceeded 24-hour limit.\n";
        return;
    }
	
	
	if (index == V) {
        // If current set is larger than best set so far, update best set
        if (currentSize > maxSize) {
            maxSize = currentSize;
            for (int i = 0; i < V; i++) {
                bestSet[i] = currentSet[i];
            }
        }
        return;
    }

    // Skip current vertex and move to the next
    bruteForceRecursive(index + 1);

    // Include the current vertex if it is independent
    if (isIndependent(index, currentSet, currentSize)) {
        currentSet[currentSize] = index; // Add vertex to current set
        currentSize++; // Increase size of the current set
        bruteForceRecursive(index + 1);
        currentSize--; // Backtrack
    }
}

//brute main funct
void Matrix::bruteMax() {
    // Reset the data members
    for (int i = 0; i < V; i++) {
        currentSet[i] = 0;
        bestSet[i] = 0;
    }
    currentSize = 0;
    maxSize = 0;
	//start timer
	start = chrono::high_resolution_clock::now();
    // Start recursive brute force process
    bruteForceRecursive(0);

    // Print maximum independent set
    cout << "--Maximum Independent Set: ---\n";
    for (int i = 0; i < maxSize; i++) {
        cout << bestSet[i] << " ";
    }
    cout << "\nSize: " << maxSize << endl;
}

// timer for brute 
double Matrix::timeBruteForce() {
    cout << "Timing Brute Force...\n";
    auto start = chrono::high_resolution_clock::now();
    bruteMax(); // Call brute force function
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Brute Force Time: " << elapsed.count() << " sec\n";
    return elapsed.count(); // Return elapsed time 
}
//=========================================================================


//==========================GREEDY APPROACH===============================

void Matrix :: greedy(){

	clrMaxSet();
	//start timer
	start = chrono::high_resolution_clock::now();
	
	//calculate degree of verticies
	for(int i = 0; i < V; i++)
	{
		degree[i] = 0;
		for(int j = 0; j < V; j++)
		{
			if(adjMatrix[i][j] == 1)
			{
				degree[i] ++; //increment deg of vertex i
			}
		}
		//Check if algorithm exeeds 24hrs
		if (check24hrs(start, 86400)) { // Check if 24 hours have passed
			cout << "Brute force terminated: Exceeded 24-hour limit.\n";
			return;
		}
	}


	//implement greedy algorithm approach
	for( int i = 0; i < V; i++){
		int minDegV = -1;
		int minDeg = V+1;

		for(int j = 0; j< V; j++){
			if(!included[j] && degree[j] < minDeg){
				minDeg = degree[j];
				minDegV = j;
			}
		}

		//Check if algorithm exeeds 24hrs
		if (check24hrs(start, 86400)) { // Check if 24 hours have passed
			cout << "Brute force terminated: Exceeded 24-hour limit.\n";
			return;
		}



		// if no vertex, break
		if(minDegV == -1){
			break;
		}

		appendMax(minDegV); //mod??

		//track selected v to independent
		included[minDegV] = true;

		for(int j = 0; j < V; j++){
			if(adjMatrix[minDegV][j] == 1){
				included[j] = true;
			}
		}
	}
		//-----Print Out Greedy------
		cout << "--Greedy Maximum Independent Set: --- \n";
		for (int i = 0; i < V; i++)
		{
			if (maxSet[i] != -1) // changed from 0 to -1
			{
				cout << maxSet[i] << " "; //removed -1 was maxset[i]-1
			}
		}
		cout << endl;


}


// timer for greedy 
double Matrix::timeGreedy() {
	clrMaxSet();
    cout << "Timing Greedy Algorithm...\n";
    auto start = chrono::high_resolution_clock::now();
    greedy(); // Call greedy function
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Greedy Algorithm Time: " << elapsed.count() << " seconds\n";
    return elapsed.count(); // Return elapsed time for further use
}

//============================================================================