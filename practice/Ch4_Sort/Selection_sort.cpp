#include <iostream>
#include <string>
using namespace std;

// Selection sort time complexity
// Best : O(n^2)
// Avg : O(n^2)
// Worst : O(n^2)
// Memory : O(n)
// Unstable (如果把swap的方法換成用鍊結串列做insert，則會是Stable)

// 核心概念：不斷挑出為排列中，最大或最小那個數字
// 作法：把陣列分成以排序，未排序兩組，依序從未排序那組抓最大或最小的資料插到已排序的組別

void Selection_sort(int data[], int len){
    for(int i=0; i<len-1; i++){
        int min_index = i;

        //找到 data[i] ~ data[len-1] 中的最小值
        for(int j=i+1; j<len; j++){
            if(data[j] < data[min_index]){
                min_index = j;
            }
        }
        
        //將最小值和 data[i] 互換
        int temp = data[min_index];
        data[min_index] = data[i];
        data[i] = temp;
    }
}

int main(void){
    int arr[10] = {35,52,68,12,47,52,36,52,74,27};
    cout << "Origin data:";
    for(int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl;

    Selection_sort(arr,10);

    cout << "Sorted data:";
    for(int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}