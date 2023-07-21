#include <iostream>
#include <string>
using namespace std;

// Bubble sort time complexity
// Best : O(n)
// Avg : O(n^2)
// Worst : O(n^2)
// Memory : O(n)
// Stable

// 核心概念：不符合規範的時候對進行對調(swap)
// 每輪比較完至少有一筆最大或最小的資料可以排列到正確的位置
// 若沒有進行任何swap，則可以立即中止迴圈(用flag實作)

void Bubble_sort(int data[], int len){
    for(int i=0; i<len-1; i++){
        for(int j=0; j<len-i-1; j++){
            if(data[j] > data[j+1]){
                int temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
}

int main(){
    int arr[10] = {35,52,68,12,47,52,36,52,74,27};
    cout << "Origin data:";
    for(int i=0;i<10;i++)
        cout << arr[i] << " ";
    cout << endl;

    Bubble_sort(arr,10);

    cout << "Sorted data:";
    for(int i=0;i<10;i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}