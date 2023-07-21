#include <iostream>
#include <string>
using namespace std;

// Shell sort time complexity
// Best : O(n)
// Avg : O(n^1.25)
// Worst : O(n^2)
// Memory : O(n)
// Unstable

// Shell sort 本身就是一種對 Insertion sort 做改進的排序法
// 核心概念：先做分組，然後在各組裡面自己做排序，接下來每組成員會愈來愈多
// Shell sort 比 Insertion sort 好的地方主要是來自最後一輪其實是排序基本上已經排序好的資料

void Shell_sort(int data[], int len){
    // gap 從 len / 2 開始
    for(int gap = len/2; gap>0; gap/=2){
        // 對各組組內進行Insertion sort
        for(int i=gap; i<len; i++){
            int value = data[i];
            int j;
            for(j=i; j>=gap && data[j-gap] > value; j-= gap){
                data[j] = data[j - gap];
            }
            data[j] = value;
        }
    }
}

int main(void){
 int arr[10] = {35,52,68,12,47,52,36,52,74,27};
    cout << "Origin data:";
    for(int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl;

    Shell_sort(arr,10);

    cout << "Sorted data:";
    for(int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}