//差補搜尋 -> 是二分逼近法的改良版，用內插法來找出資料

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int Interpolation_search(int data[], int lower, int upper, int target){
    if(upper < lower){
        return -1;
    }

    int upper_data = data[upper];
    int lower_data = data[lower];
    int index = lower + (target - lower_data) * (upper - lower) / (upper_data - lower_data);

    if(data[index] == target){
        return index;
    }

    else if(data[index] > target){
        return Interpolation_search(data, lower, index-1, target);
    }

    else if(data[index] < target){
        return Interpolation_search(data, index+1, upper, target);
    }
}

int main(){
    int target;
    int arr[10] = {12, 27, 35, 36, 47, 52, 52, 52, 68, 74};
    cout << "Please enter the target you want would like to search: " << endl;
    cin >> target;

    cout << "Index of " << target << "is " << Interpolation_search(arr, 0, 9, target);

    return 0;
}