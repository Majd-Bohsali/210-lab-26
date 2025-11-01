// COMSC210 | lab 25 | Majd Bohsali
// IDE useD: Visual Studio Code
#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <vector>
#include <list>
#include <set> 
#include <string>
#include <algorithm>
using namespace std;
using namespace std::chrono;

double timeVectorRead(vector<string>& codesVector);
double timeListRead(list<string>& codesList);
double timeSetRead(set<string>& codesSet);
double timeVectorSort(vector<string>& codesVector);
double timeListSort(list<string>& codesList);
double timeVectorInsert(vector<string>& codesVector);
double timeListInsert(list<string>& codesList);
double timeSetInsert(set<string>& codesSet);
double timeVectorDelete(vector<string>& codesVector);
double timeListDelete(list<string>& codesList);
double timeSetDelete(set<string>& codesSet);
const int W = 10;
const int NUM_OPERATIONS = 4; 
const int NUM_DATASETS = 3;
const int ARRAY_DEPTH = 2;  
const int NUM_RUNS = 15; 
int main() {    
    double results[NUM_OPERATIONS][NUM_DATASETS][ARRAY_DEPTH]; // creates 3D array to hold data
                                                               // first level is run times for specific run
                                                               // second level if sum of all previous and current runs
    int avgResults[NUM_OPERATIONS][NUM_DATASETS];
    for(int i = 0; i < NUM_RUNS; i++) { 
        // creates datasets
        vector<string> codesVector;
        list<string> codesList;
        set<string> codesSet;
            
        // Calculates time for reading
        results[0][0][0] = timeVectorRead(codesVector);
        results[0][1][0] = timeListRead(codesList);
        results[0][2][0] = timeSetRead(codesSet);

        // Calculates time for sorting
        results[1][0][0] = timeVectorSort(codesVector);
        results[1][1][0] = timeListSort(codesList);
        results[1][2][0] =  -1; // set is already sorted

        // Calculates time for inserting
        results[2][0][0] = timeVectorInsert(codesVector);
        results[2][1][0] = timeListInsert(codesList);
        results[2][2][0] = timeSetInsert(codesSet);

        // Calculates time for deleting
        results[3][0][0] = timeVectorDelete(codesVector);
        results[3][1][0] = timeListDelete(codesList);
        results[3][2][0] = timeSetDelete(codesSet);

        // sums values to update second level 
        for(int i = 0; i < NUM_OPERATIONS; i++) { 
            for(int j = 0; j < NUM_DATASETS; j++) { 
                results[i][j][1] += results[i][j][0]; 
            }
        }

        // print results to console
        cout << endl << "Iteration: " << i + 1 << endl; 
        cout << right << setw(W) << "Operation" << setw(W) << "Vector" << setw(W) << "List" << setw(W) << "Set" << endl;
        cout << right << setw(W) << "Read" << setw(W) << results[0][0][i] << setw(W) <<  results[0][1][i]  << setw(W) <<  results[0][2][i]  << endl;
        cout << right << setw(W) << "Sort" << setw(W) << results[1][0][i] << setw(W) << results[1][1][i] << setw(W) << results[1][2][i] << endl;
        cout << right << setw(W) << "Insert" << setw(W) << results[2][0][i] << setw(W) << results[2][1][i] << setw(W) << results[2][2][i] << endl;
        cout << right << setw(W) << "Delete" << setw(W) << results[3][0][i] << setw(W) << results[3][1][i] << setw(W) << results[3][2][i] << endl;
    }

    cout << "Number of simulations: " << NUM_RUNS; 
    return 0;
}
 
double timeVectorRead(vector<string>& codesVector) { 
    ifstream fin("codes.txt");
    string code; 
    auto start = high_resolution_clock::now();
    while (fin >> code) {
        codesVector.push_back(code); 
    }
    fin.close();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    return duration;
}

double timeListRead(list<string>& codesList) { 
    ifstream fin("codes.txt");
    string code; 
    auto start = high_resolution_clock::now();
    while (fin >> code) {
        codesList.push_back(code); 
    }
    fin.close();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    return duration;
}

double timeSetRead(set<string>& codesSet) { 
    ifstream fin("codes.txt");
    string code; 
    auto start = high_resolution_clock::now();
    while (fin >> code) {
        codesSet.insert(code); 
    }
    fin.close();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    return duration;
}

double timeVectorSort(vector<string>& codesVector) {
    auto start = high_resolution_clock::now();
    sort(codesVector.begin(), codesVector.end());
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    return duration;
}

double timeListSort(list<string>& codesList) {
    auto start = high_resolution_clock::now();
    codesList.sort();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    return duration;
}

double timeVectorInsert(vector<string>& codesVector) {
    auto start = high_resolution_clock::now();
    auto it = codesVector.begin(); 
    int middleElement = codesVector.size()/2; 
    codesVector.insert(it + middleElement, "TESTCODE");
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    return duration;
}

double timeListInsert(list<string>& codesList) {
    auto start = high_resolution_clock::now();
    auto it = codesList.begin(); 
    int middleElement = codesList.size()/2; 
    advance(it, middleElement); 
    codesList.insert(it, "TESTCODE");  
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    return duration;
}

double timeSetInsert(set<string>& codesSet) {
    auto start = high_resolution_clock::now();
    codesSet.insert("TESTCODE");
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    return duration;
}


double timeVectorDelete(vector<string>& codesVector) {
    auto start = high_resolution_clock::now();
    auto it = codesVector.begin(); 
    int middleElement = codesVector.size()/2; 
    codesVector.erase(it + middleElement);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    return duration;
}

double timeListDelete(list<string>& codesList) {
    auto start = high_resolution_clock::now();
    auto it = codesList.begin(); 
    int middleElement = codesList.size()/2; 
    advance(it, middleElement); 
    codesList.erase(it);  
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    return duration;
} 

double timeSetDelete(set<string>& codesSet){
    auto start = high_resolution_clock::now();
    codesSet.erase("TESTCODE");
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    return duration;
}
