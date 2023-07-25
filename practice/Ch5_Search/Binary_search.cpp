#include <iostream>
#include <string>
using namespace std;

int Binary_search(int data[], int lower, int upper, int target){
    //沒找到
    if(upper < lower){
        return -1;
    }

    //直接找到
    int middle = (lower + upper) / 2;
    if(data[middle] == target){
        return middle;
    }
    //要找到的數比中位數小
    else if(data[middle] > target){
        return Binary_search(data, lower, middle-1, target);
    }
    //要找到的數比中位數大
    else if(data[middle] < target){
        return Binary_search(data, middle+1, upper, target);
    }
}

int main(){
    int target;
    int arr[10] = {12, 27, 35, 36, 47, 52, 52, 52, 68, 74};
    cout << "Please enter the target you want would like to search: " << endl;
    cin >> target;

    cout << "Index of " << target << "is " << Binary_search(arr, 0, 9, target);

    return 0;
}