#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// recursion version
int triple_fibo_recurrsion(int n){
    if(n <= 3){
        return 1;
    }
    else{
        return triple_fibo_recurrsion(n-1) + triple_fibo_recurrsion(n-2) + triple_fibo_recurrsion(n-3);
    }
}

// DP version
int main(void){
    long long int N;
    cout << "Please enter a number: ";
    cin >> N;
    long long int triple_fibo[N];

    for(int i=0; i<N; i++){
        if(i < 3){
            triple_fibo[i] = 1;
        }
        else{
            triple_fibo[i] = triple_fibo[i-1] + triple_fibo[i-2] + triple_fibo[i-3];
        }
    }

    cout << "fibo[" << N << "] is " << triple_fibo[N-1] << endl;

    return 0;
}