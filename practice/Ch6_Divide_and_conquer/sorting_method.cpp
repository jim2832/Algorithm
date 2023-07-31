#include <iostream>
#include <vector>
using namespace std;

void Merge_sort(int data[], int start, int finish){
    if(start < finish){
        int middle = (finish + start) / 2;
        Merge_sort(data, start, middle);
        Merge_sort(data, middle+1, finish);
        Merge(data, start, finish, middle);
    }
}

void Quick_sort(int data[], int start, int finish){
    if(start < finish){
        int pivot = Partition(data, start, finish); // O(n)
        Quick_sort(data, start, pivot-1);
        Quick_sort(data, pivot+1, finish);
    }
}