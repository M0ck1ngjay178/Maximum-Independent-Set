#ifndef GRAPH_H
#define GRAPH_H
    #include <string>
    #include <fstream>
    #include <iostream>
    #include <chrono>
    constexpr int V = 5; // change v value here
    constexpr int X = 10;
    using namespace std;

    /*********************MATRIX************************************/
    class Matrix
    {
        public:
            Matrix();

            // BruteForce Functions
            void insert(const int, const int);
            void remove(const int, const int);
            void printMatrix(void) const;
            void bruteMax(void); // take off const, max set needs to be able to change, causing errors
            void appendMax(int);
            //bool isIndependent(int) const;//helper function to check if unique vertex
            bool isIndependent(int v, const int currentSet[], int currentSize) const;
            void bruteForceRecursive(int);
            void clrMaxSet();
            void generateInserts(void);
            
            //Greedy Functions
            void greedy(void);

            //timing
            double timeBruteForce();
            double timeGreedy();
            bool check24hrs(chrono::time_point<chrono::high_resolution_clock> start, double limitSeconds);
            
        private:
            int adjMatrix[V][V];
            int maxSet[V] = {0};
            chrono::time_point<chrono::high_resolution_clock> start;
            
            //for greedy
            bool included[V] = {false};
	        int degree[V] = {0};

            //for brute force
            int currentSet[V] = {0}; // Temp array for current independent set
            int bestSet[V] = {0};    // Array to store best independent set found
            int currentSize = 0;     // Size of current independent set
            int maxSize = 0;         // Size of maximum independent set

    };
    /*********************************************************************/

    //======Non-Class Functions=========
    void header(void);
    void menu(void);
    //=================================
#endif