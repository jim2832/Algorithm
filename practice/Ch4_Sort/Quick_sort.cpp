#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Quick sort time complexity
// Best : O(n log n)
// Avg : O(n log n)
// Worst : O(n^2)
// Memory : O(n)
// Stable or Unstable

// 核心概念：選一個元素當作 pivot，比他小的放左邊，比他大的放右邊，不斷做直到資料數目為1
// 可以偷懶把坐右邊的元素直接當 pivot
// Partition: 將比 pivot 小的元素放在他左邊，將比 pivot 大的元素放在他右邊
// 如果 data[j] < pivot，則交換 data[i+1] 和 data[j]

// Quick sort 如果 pivot 是選到最左邊或最右邊，效率會很低，遇到這個情況，有以下三種解決方式
// 1. 隨機取 
// 2. 取陣列中第一、中間、最後三個值的中位數
// 3. 長度太短就停止遞迴，改用 insertion sort

int Partition(int data[], int start, int finish){
    int pivot = data[finish]; //取最後一個元素當作pivot
    int p = start;
    for(int i=start; i<finish; i++){
        if(data[i] < pivot){ //如果 i 指向的元素小於 pivot，
            int temp = data[i];
            data[i] = data[p];
            data[p] = temp;
            p++;
        }
    }
    // 最後要將最後一個和 pivot 互換
    int temp = data[finish];
    data[finish] = data[p];
    data[p] = temp;

    return p;
}

void Quick_sort(int data[], int start, int finish){
    if(start < finish){
        int pivot = Partition(data, start, finish);
        // Recursion
        Quick_sort(data, start, pivot - 1);
        Quick_sort(data, pivot + 1, finish);
    }
}

int main(){
    int data[] = {43,12,7,123,7,2,4,45,3,83,32,4};
    for(int i=0;i<12;i++)
        cout << data[i] << " ";
    cout << endl;

    Quick_sort(data,0,11);
    for(int i=0;i<12;i++)
        cout << data[i] << " ";
    cout << endl;

    return 0;
}