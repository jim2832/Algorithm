#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Heap sort time complexity
// Best : O(n log n)
// Avg : O(n log n)
// Worst : O(n log n)
// Memory : O(n)
// Stable

// 核心概念：利用 heap 這個資料結構來知道何者為最大值和最小值，接著做互換和刪除來做排序
// 操作：
// 1. 把最末端和第一個末端元素交換位置
// 2. 交換後最後一個元素消失(已排序)
// 3. 交換後對根節點和其子節點做 heapify
// 4. 重複步驟1~3，直到陣列為空
// 如果要由小排到大，則要用 max-heap，反之，大排到小則要用 min-heap
// 時間複雜度：每次 heapify 需要 O(log n)，而需要 O(n)次 heapify，因此總共為 O(n log n)

void Max_heapify(int *data, int root, int len){
    int left =  2 * root + 1;
    int right = 2 * root + 2;

    int largest = root;

    //左節點為最大值
    if(left < len && data[left] > data[largest]){
        largest = left;
    }

    //右節點為最大值
    if(right < len && data[right] > data[largest]){
        largest = right;
    }

    //把最大值和根節點做互換
    if(largest != root){
        //swap data[root] and data[largest]
        int temp = data[root];
        data[root] = data[largest];
        data[largest] = temp;
        Max_heapify(data, largest, len);
    }
}

void Min_Heapify(int *data, int root, int len){
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    int smallest = root;

    if(left < len && data[left] < data[smallest]){
        smallest = left;
    }

    if(right < len && data[right] < data[smallest]){
        smallest = right;
    }

    if(smallest != root){
        // Swap data[root] and data[smallest]
        int temp = data[root];
        data[root] = data[smallest];
        data[smallest] = temp;
        Min_Heapify(data, smallest, len);
    }
}

void Build_max_heap(int *data, int len){
    for(int i=len/2-1; i>=0; i--){
        Max_heapify(data, i, len);
    }
}

void Build_min_heap(int *data, int len){
    for(int i=len/2-1; i>=0; i--){
        Min_Heapify(data, i, len);
    }
}

void Print_array(int *data, int len){
    cout << "Array: ";
    for(int i=0; i<len; i++){
        cout << data[i] << " ";
    }
    cout << endl;
}

void Heap_sort(int *data, int len){
    // step1: make max-heap
    Build_max_heap(data, len);

    for(int i=len-1; i>0; i--){
        // step2: swap data[i] and data[0]
        int temp = data[0];
        data[0] = data[i];
        data[i] = temp;

        // step3: Max heapify again
        Max_heapify(data, 0, i);
    }
    
}

int main(){
    int arr[10] = {35,52,68,12,47,52,36,52,74,27};
    cout << "Origin data:";
    for(int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl;

    Heap_sort(arr,10);

    cout << "Sorted data:";
    for(int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}