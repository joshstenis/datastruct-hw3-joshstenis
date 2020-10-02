#include <iostream>
#include <vector>
using namespace std;

/**
 * Converts a string number into an integer -- (ex. "-140" == -140)
 * @param str The string number
 */
int strToInt(string str) {
    int val = 0;
    for(int i=0 ;i < str.length(); i++) {
        if(str[i] != '-')
            val += power(10, str.length()-i) * (str[i] - 48);
    } if(str[0] == '-') val *= -1;
    
    return val/10;
}

void selectionSort() {

}

/**
 * Merge sorts the given vector
 * @param v The vector to be sorted
 * @param start The starting index
 * @param stop The ending index
 */
void mergeSort(vector<int> v, int start, int stop) {
    if(stop - start > 1) {
        int mid = v.size() / 2;
        mergeSort(v, start, mid);           // Recursive first half
        mergeSort(v, mid+1, stop);          // Recursive second half
    } else
        if(v[start] < v[stop]) swap(v[start], v[stop]);             // List is now 2 elements long
}

/**
 * Bubble sorts a given vector into descending order
 * @param v The vector to be bubble sorted
 */
void bubbleSort(vector<int> v) {
    for(int i=0; i < v.size(); i++) {
        for(int j=i; j < v.size(); j++) {
            if(v[i] < v[j])
                swap(v[i], v[j]);
        }
    }
}

int main() {
    vector<int> input;

    int task;
    string val;
    cin >> task;

    cin.ignore(1, '\n');
    while(!cin.fail()) {                // Populates input vector
        cin >> val;
        input.push_back(strToInt(val));
    }

    switch(task) {                      // Conduct the proper sort
        case 0:
        {
            // Code
        } break;

        case 1:
        {
            // Code
        } break;
    }
}