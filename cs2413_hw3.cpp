#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/**
 * Converts a string number into an integer -- (ex. "-140" == -140)
 * @param str The string number
 */
int strToInt(string str) {
    int val = 0;
    for(int i=0 ;i < str.length(); i++) {
        if(str[i] != '-')
            val += pow(10, str.length()-i) * (str[i] - 48);
    } if(str[0] == '-') val *= -1;
    
    return val/10;
}

/**
 * Outputs the given vector
 * @param v The vector to be cout'd, element by element
 */
void outputVector(vector<int> v) {
    cout << v[0];
    for(int i=1; i < v.size(); i++)
        cout << " " << v[i];
}

/**
 * Selections sort the entire given vector into descending order
 * @param v The vector to be sorted
 * @return The sorted vector
 */
vector<int> selectionSort(vector<int> v) {
    int unsorted = v.size();
    int biggest;

    for(int i=0; i < v.size(); i++) {
        for(int j=v.size()-unsorted; j < unsorted; j++)
            if(v[j] > biggest) biggest = v[j];
        v[i] = biggest;
        unsorted--;
    } return v;
}

/**
 * Selection sorts a sub vector of the given vector into descending order
 * @param v The vector to be sorted
 * @param start The beginning  index of the sub vector
 * @param stop The end index of the sub vector
 * @return The sorted sub vector
 */
vector<int> selectionSort(vector<int> v, int start, int stop) {
    int unsorted = stop;
    int biggest;

    for(int i=start; i < stop; i++) {
        for(int j=stop-unsorted; j < unsorted; j++)
            if(v[j] > biggest) biggest = v[j];
        v[i] = biggest;
        unsorted--;
    } return v;
}

/**
 * Merges two given vectors in descending element order
 * @param v A sub vector
 * @param w A sub vector
 * @return The vector containing v and w
 */
vector<int> merge(vector<int> v, vector<int> w) {
    v.insert(v.end(), w.begin(), w.end());
    return selectionSort(v);
}

/**
 * Merge sorts the given vector
 * @param v The vector to be sorted
 * @param start The starting index
 * @param stop The ending index
 * @return The decending sorted vector
 */
vector<int> mergeSort(vector<int> v) {
    int mid = v.size() / 2;

    vector<int> firstHalf = selectionSort(v, 0, mid);               // Splits given vector in half
    vector<int> secondHalf = selectionSort(v, mid+1, v.size());

    return merge(firstHalf, secondHalf);
}

/**
 * Bubble sorts a given vector into descending order
 * @param v The vector to be bubble sorted
 * @return The decending sorted vector
 */
vector<int> bubbleSort(vector<int> v) {
    for(int i=0; i < v.size(); i++) {
        for(int j=i+1; j < v.size(); j++) {
            if(v[i] < v[j])
                v[i] = v[i] ^ v[j] ^ (v[j] = v[i]);             // Bitwise value swap, instead of using 'swap' function
        }
    } return v;
}

int main() {
    vector<int> input;

    int task;
    string val;
    cin >> task;

    cin.ignore(1, '\n');
    while(!cin.fail()) {                // Populates input vector
        cin >> val;
        if(val == "s") break;
        input.push_back(strToInt(val));
    }

    switch(task) {                      // Conduct the proper sort
        case 0:
        {
            outputVector(bubbleSort(input));
        } break;

        case 1:
        {
            outputVector(mergeSort(input));
        } break;
    }
}