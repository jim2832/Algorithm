#include <iostream>
#include <string>
using namespace std;

// Insertion sort time complexity
// Best : O(n)
// Avg : O(n^2)
// Worst : O(n^2)
// Memory : O(n)
// Stable

void Insertion_Sort(int data[], int len){
    // i is the index of X
    for(int i=1; i<len; i++){
        int value = data[i];
        int j = i - 1; // j is the index of Y

        //shift elements > X to right
        while(value < data[j] && j >= 0){
            data[j+1] = data[j];
            j--;
        }
        //insert X to its position
        data[j+1] = value;
    }
}

int main(void){
    int arr[10] = {35,52,68,12,47,52,36,52,74,27};
    cout << "Origin data: ";
    for(int i=0; i<10; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    Insertion_Sort(arr, 10);
    for(int i=0; i<10; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}