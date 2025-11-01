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
const int NUM_RUNS = 15; 
int main() {    
    double results[NUM_OPERATIONS][NUM_DATASETS][NUM_RUNS]; 
    // collects file data with vector
    vector<string> codesVector;
    double vectorReadTime = timeVectorRead(codesVector);
    // collects file data with list
    list<string> codesList;
    double listReadTime = timeListRead(codesList);
    // collects file data with set
    set<string> codesSet;
    double setReadTime = timeSetRead(codesSet);

    // sorts vector
    double vectorSortTime = timeVectorSort(codesVector);
    // sorts list
    double listSortTime = timeListSort(codesList);
    // sort set
    double setSortTime = -1; // set is already sorted

    // insert to vector
    double vectorInsertTime = timeVectorInsert(codesVector);
    // insert to list
    double listInsertTime = timeListInsert(codesList);
    // insert to set
    double setInsertTime = timeSetInsert(codesSet);

    // delete middle element from vector
    double vectorDeleteTime = timeVectorDelete(codesVector);
    // delete middle element from list
    double listDeleteTime = timeListDelete(codesList);
    // delete middle element from set
    double setDeleteTime = timeSetDelete(codesSet);

    // print results to console
    cout << right << setw(W) << "Operation" << setw(W) << "Vector" << setw(W) << "List" << setw(W) << "Set" << endl;
    cout << right << setw(W) << "Read" << setw(W) << vectorReadTime << setw(W) << listReadTime << setw(W) << setReadTime << endl;
    cout << right << setw(W) << "Sort" << setw(W) << vectorSortTime << setw(W) << listSortTime << setw(W) << setSortTime << endl;
    cout << right << setw(W) << "Insert" << setw(W) << vectorInsertTime << setw(W) << listInsertTime << setw(W) << setInsertTime << endl;
    cout << right << setw(W) << "Delete" << setw(W) << vectorDeleteTime << setw(W) << listDeleteTime << setw(W) << setDeleteTime << endl;
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
