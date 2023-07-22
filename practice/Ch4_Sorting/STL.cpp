#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// C++ 中 STL 是使用 sort() 函式
// 1. 原則上是使用 Quick sort
// 2. 監控遞迴的深度，太深的話改用 Heap sort
// 3. 長度下降到一定程度，則改用 Insertion sort
// 4. 總結來說，C++ STL 裡面用的是混合的排序法

bool compare(int a, int b){
    return a>b;
}

int main(){
    vector<int> data = {8, -5, -1, 4, -3, 6, 2, -2, 3, 4};

    sort(data.begin(), data.end(), greater<int>());
    // sort(data.begin(), data.end(), compare);
    
    for(int i=0; i<data.size(); i++){
        cout << data[i] << " ";
    }

    return 0;
}