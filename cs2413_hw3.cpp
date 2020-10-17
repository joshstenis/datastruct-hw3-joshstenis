#include <iostream>
#include <vector>
#include <algorithm>
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
    int max;

    for(int i=0; i < v.size(); i++) {
        max = i;
        for(int j=i; j < unsorted; j++) {
            if(v[j] > v[max])
                max = j;
        }

        v[i] = v[i] ^ v[max] ^ (v[max] = v[i]);
        unsorted--;
    } return v;
}

/**
 * Splits given vector into two equal sized subvectors
 * @param v The vector to be split
 * @return A vector of the subvectors
 */
vector<vector<int>> splitVector(vector<int> v) {
    vector<int> firstHalf, secondHalf;

    for(int i=0; i < v.size(); i++) {
        if(i < v.size()/2) firstHalf.push_back(v[i]);
        else secondHalf.push_back(v[i]);
    } return {firstHalf, secondHalf};
}

/**
 * Merges two given vectors in descending element order
 * @param v A sub vector
 * @param w A sub vector
 * @return The vector containing v and w
 */
vector<int> merge(vector<int> v, vector<int> w) {
    vector<int> result;
    result.insert(result.end(), v.begin(), v.end());
    result.insert(result.end(), w.begin(), w.end());

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
    vector<vector<int>> halves = splitVector(v);

    halves[0] = selectionSort(halves[0]);
    halves[1] = selectionSort(halves[1]);

    return merge(halves[0], halves[1]);
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

    int task, val;
    cin >> task;

    cin.ignore(1, '\n');
    while(cin >> val)                   // Populates input vector
        input.push_back(val);

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