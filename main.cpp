// C++ program for insertion sort
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

string readFile(string location){

    string text;
    ifstream path(location);

    if(path.fail()){
        cout << "File was not found" << endl;
        return text;
    }

    while(!path.eof()){
        getline(path,text);
        cout << "File was found" << endl;
    }

    return text;
}

int arrayLength(string numbers){
    int result=0;
    for(int i = 0; numbers[i] != '\0' ; i++){
        if (numbers[i]==','){
            result++;
        }
    }
    return result;
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void makeArray(string stringList, int stringArray[], int stringListLenght){

    string box;
    for(int i=0, j=0; stringList.length()>=i;i++){
        if(stringList[i]==',' or i==stringList.length()){
            if (!box.empty()){
                stringstream item(box);
                int x = 0;
                item >> x;
                stringArray[j]=x;
                box="";
            }
            j++;
        }
        else{
            box=box + stringList[i];
        }
    }
}

int main()
{
    string text, path;
    cout << "Please enter the file path";
    cin>>path;

    text=readFile(path);

    int stringListLength = arrayLength(text);
    int stringArray[ stringListLength ];

    makeArray(text, stringArray, stringListLength);
    insertionSort(stringArray, stringListLength+1);

    printArray(stringArray, stringListLength+1 );
    return 0;
}
