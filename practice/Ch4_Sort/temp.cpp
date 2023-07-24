#include <iostream>

using namespace std;

int Partition(int data[], int start, int finish){
    int pivot = data[finish];
    int p = start;
    for(int i=start;i<finish;i++){
        if(data[i]<pivot){
            int tmp = data[i];
            data[i]= data[p];
            data[p] = tmp;
            p++;
        }
    }
    int tmp = data[finish];
    data[finish]= data[p];
    data[p] = tmp;
    return p;
}


void Quick_Sort(int data[], int start, int finish){
    if (start < finish) {
        int pivot = Partition(data, start, finish);
        Quick_Sort(data, start, pivot - 1);
        Quick_Sort(data, pivot + 1, finish);
    }
}

int main()
{
    int data[] = {43,12,7,123,7,2,4,45,3,83,32,4};
    for(int i=0;i<12;i++)
        cout << data[i] << " ";
    cout << endl;

    Quick_Sort(data,0,11);
    for(int i=0;i<12;i++)
        cout << data[i] << " ";
    cout << endl;

    return 0;
}