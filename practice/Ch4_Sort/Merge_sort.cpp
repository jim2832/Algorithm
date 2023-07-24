#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Merge sort time complexity
// Best : O(n log n)
// Avg : O(n log n)
// Worst : O(n log n)
// Memory : O(n)
// Stable

// 核心概念：將資料分成兩組，分別排序，再把以排序好的兩組資料融合在一起
// 合併時有可能發生其中一組已經耗盡的情況，因此我們會在兩組結尾加上一個「無限大」
// 會需要額外的O(n)空間，但如果用 linked list 則不用

void merge_to(int data[], int start, int finish, int middle){
    int size_left = middle - start + 1; //左邊的長度
    int size_right = finish - middle; //右邊的長度
    int* left = (int*)malloc(sizeof(int) * (size_left + 1)); //存左邊資料的 dynamic array
    int* right = (int*)malloc(sizeof(int) * (size_right)); //存右邊資料的 dynamic array

    memcpy(left, data+start, sizeof(int) * size_left);
    memcpy(right, data+middle+1, sizeof(int) * size_right);

    left[size_left] = 2147483647; //Inf
    right[size_right] = 2147483647; //Inf

    int left_index = 0, right_index = 0;

    for(int i=start; i<=finish; i++){
        if(left[left_index] <= right[right_index]){
            data[i] = left[left_index];
            left_index++;
        }
        else{
            data[i] = right[right_index];
            right_index++;
        }
    }

    free(left);
    free(right);
}

void merge_sort(int data[], int start, int finish){
    if(finish > start){
        int middle = (finish + start) / 2;
        merge_sort(data, start, middle);
        merge_sort(data, middle+1, finish);
        merge_to(data, start, finish, middle);
    }
}

int main(){
    int data[10] = {35,52,68,12,47,52,36,52,74,27};
    merge_sort(data,0,9);

    for(int i=0;i<10;i++)
        cout << data[i] << " ";
    cout << endl;

    return 0;
}