//Thomas Brown trb0057 /home/u1/trb0057/comp/project3_Brown_trb0057.cpp
//How to compile:
//Prompts the user to input 2 file names (such as input1.txt)
//Inputed files are required to be in same directory
//Prompts the user to input an output file name, then outpuits file
#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <string>
using namespace std;

const int maxSize = 100;

void printFile(int inputArray[], int size);
int readFile(int inputArray[], ifstream& instream);
int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]);
void selectionSort(int arr[], int size);
void writeFile(string filename, int outputArray[], int outputArray_size);

int main() {
    cout << "*** Welcome to Thomas' sorting program ***" << endl;

    //Handles prompting for file1, opening, reading, closing, and printing the file
    cout << "Enter the first input file name: ";
    string fileName1;
    cin >> fileName1;
    ifstream inStream1;
    int iArray1[maxSize];
    int iArray1_size;
    inStream1.open(fileName1.c_str());
    if(!inStream1) throw invalid_argument("ERROR NO FILE");
    iArray1_size = readFile(iArray1, inStream1);
    inStream1.close( );
    cout << "The list of " << iArray1_size << " numbers in file " << fileName1 << " is:" << endl; 
    printFile(iArray1, iArray1_size);

    //Handles prompting for file2, opening, reading, closing, and printing the file
    cout << "Enter the second input file name: ";
    string fileName2;
    cin >> fileName2;
    ifstream inStream2;
    int iArray2[maxSize];
    int iArray2_size;
    inStream2.open(fileName2.c_str());
    if(!inStream2) throw invalid_argument("ERROR NO FILE");
    iArray2_size = readFile(iArray2, inStream2);
    inStream2.close( );
    cout << "The list of " << iArray2_size << " numbers in file " << fileName2 << " is:" << endl; 
    printFile(iArray2, iArray2_size);

    //Merges files and copies to new file
    int outputArray[maxSize*2];
    int outputArray_size = sort(iArray1, iArray1_size, iArray2, iArray2_size, outputArray);
    cout << "The sorted list of " << outputArray_size << " numbers is: ";
    for(int x = 0; x < outputArray_size; x++)
        cout << outputArray[x] << " ";
    cout << endl << "Enter the output file name: ";
    string outputFileName;
    cin >> outputFileName;
    writeFile(outputFileName, outputArray, outputArray_size);
    cout << "*** Please check the new file - " << outputFileName << " ***" << endl;
    cout << "*** Goodbye. ***" << endl;
    return 0;
}

//Prints out all contents of file
void printFile(int inputArray[], int size) {
    for(int x = 0; x < size; x++)
        cout << inputArray[x] << endl;
    cout << endl;
}

int readFile(int inputArray[], ifstream& inStream){
    int index = 0;
    while (inStream >> inputArray[index]) {
        index++;
    }
    return index;
}

int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]) {
    for (int x = 0; x < inputArray1_size; x++)
        outputArray[x] = inputArray1[x];
    for (int y = 0; y < inputArray2_size; y++)
        outputArray[y + inputArray1_size] = inputArray2[y];
    int outputArray_size = inputArray1_size + inputArray2_size;
    selectionSort(outputArray, outputArray_size);
    return outputArray_size;
}

void selectionSort(int arr[], int size) { 
    int len = size;
    int index; 
    for (int x = 0; x < size - 1; x++) { 
        index = x; 
        for (int y = x + 1; y < len; y++) { 
            if (arr[y] < arr[index]) 
                index = y;
        } 
        if (index != x) {
            int val1 = arr[x];
            arr[x] = arr[index];
            arr[index] = val1;
        }
    } 
} 

void writeFile(string filename, int outputArray[], int outputArray_size) {
    ofstream outStream(filename.c_str());
    if (!outStream) throw invalid_argument("ERROR WRITING FILE");
    for (int i = 0; i < outputArray_size; i++) {
        outStream << outputArray[i] << endl;
    }
    outStream.close();
}