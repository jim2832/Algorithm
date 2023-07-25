#include <iostream>
#include <string>
#include <vector>
using namespace std;

int Sequential_search(int data[], int len, int target){
    for(int i=0; i<len; i++){
        // found
        if(data[i] == target){
            return i;
        }
        // not found
        else if(i == len - 1){
            return -1;
        }
    }
}

int main(void){

    return 0;
}