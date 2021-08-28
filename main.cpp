#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
/** @brief Function to sort the elements
 * The function insertionSort receives the array that's going to be insertion sorted and an integer that is the number
 * of elements in the array that we are going to sort. The algorithm works by taking and element and compare it to it's
 * adjacent elements of the array, until that element is sorted, then proceeds to do the same with the second element
 * but in this case we don't need to test the first element since it's already sorted.
 * @param arr
 * @param n
 */
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

/** @brief Function to read the files
 * The function readFile receives an string containing the path of the file that we are going to use to receive the
 * numbers for the sorting algorithm, this function takes the contents of the file we specified and then inserts it into
 * an string called text, this will contain the contents of the file identically as in the file.
 * @param location
 * @return The contents of the file we're looking for, it will return and empty string if it doesn't find any matching
 * file in the specified location.
 */
string readFile(string location){

    string text;
    ifstream path(location);

    if(path.fail()){
        cout << "Unable to locate file to read " << endl;
        return text;
    }

    while(!path.eof()){getline(path,text);}

    path.close();
    return text;
}

/** @brief Function to write on the file
 * The function writeFile receives an string containing the path of the file that we are going to write to, it also
 * receives the string containing the text that we're going to write on the file location.
 * @param location
 * @param result
 */
void writeFile(string location, string result){

    ofstream path(location);

    if(path.fail()){
        cout << "Unable to locate file to write" << endl;
        return;
    }

    path<<result;
    path.close();

}

/** @brief Function to get the string array length
 *  The stringArrayLength function receives the an string that contains numbers separated by comae and will count how
 *  many numbers are they and returns the number of elements.
 * @param numbers
 * @return the number of elements in the sting that contains numbers separated by coma
 */
int stringArrayLength(string numbers){
    int result=0;
    for(int i = 0; numbers[i] != '\0' ; i++){
        if (numbers[i]==','){
            result++;
        }
    }
    return result;
}

/** @brief Function to make an array from a text file
 * The function makeArray will take the string that readFile generates and will separate the numbers that are separated by
 * coma and will add it as new integer array element in the stingArray array.
 * @param stringList
 * @param stringArray
 */
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

/** @brief Function to convert an array into a string with its contents
 * The makeString function reads the contents of an int array and writes it on a string and separates it by a coma,
 * resulting on a pretty similar string as the one we had in the beginning.
 * @param result
 * @param stringArray
 * @param arraySize
 * @return a string containing the numbers of the stringArray[] array separated by a coma
 */
string makeString(string result, int stringArray[], int arraySize){

    for(int i=0; arraySize>=i; i++){
        result+= to_string(stringArray[i]);
        if(arraySize!=i){
            result+=",";
        }
    }
    return result;
}

/** @brief Main function
 * The main function is the first function that runs when the project is executed
 * @return an integer value o 0 indicating that the code ran successfully
 */
int main()
{
    string text, readpath, writepath,result;
    int stringListLength;

    cout << "Please enter the file to read";
    cin >> readpath;
    cout << "Please enter the file to write";
    cin >> writepath;

    text=readFile(readpath);
    stringListLength = stringArrayLength(text);

    int stringArray[ stringListLength ];

    makeArray(text, stringArray);
    insertionSort(stringArray, stringListLength+1);
    result=makeString(result,stringArray,stringListLength );
    writeFile(writepath,result);

    return 0;
}
