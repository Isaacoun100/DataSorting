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
        cout << "Unable to locate file to read " << endl;
        return text;
    }

    while(!path.eof()){
        getline(path,text);
        cout << "File was read succesfully" << endl;
    }

    path.close();
    return text;
}

void writeFile(string location, string result){

    ofstream path(location);

    if(path.fail()){
        cout << "Unable to locate file to write" << endl;
        return;
    }

    path<<result;
    path.close();

}

int stringArrayLength(string numbers){
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

void makeArray(string stringList, int stringArray[]){

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
            box+=stringList[i];
        }
    }
}

int stringLength(string info){
    int x=0;
    while(info[x]!='\0'){x++;}
    return x;
}

string makeString(string result, int stringArray[], int arraySize){

    for(int i=0; arraySize>=i; i++){
        result+= to_string(stringArray[i]);
        if(arraySize!=i){
            result+=",";
        }
    }
    return result;
}

int main()
{
    string text, readpath, writepath,result;
    cout << "Please enter the file to read";
    cin >> readpath;

    cout << "Please enter the file to write";
    cin >> writepath;

    text=readFile(readpath);

    int stringListLength = stringArrayLength(text);
    int stringArray[ stringListLength ];

    makeArray(text, stringArray);
    insertionSort(stringArray, stringListLength+1);

    result=makeString(result,stringArray,stringListLength );

    cout<<result<<endl;

    writeFile(writepath,result);

    return 0;
}
