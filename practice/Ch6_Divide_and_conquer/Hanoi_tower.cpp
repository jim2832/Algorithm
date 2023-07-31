#include <iostream>
#include <vector>
using namespace std;

int Hanoi(int N, char from, char to, char other){
    if(N == 1){
        cout << "Move " << N << " from " << from << " to " << to << endl;
        return 1;
    }
    else{
        int step1 = Hanoi(N-1, from, other, to);
        int step2 = 1;
        cout << "Move " << N << " from " << from << " to " << to << endl;
        int step3 = Hanoi(N-1, other, to, from);
        return step1 + step2 + step3;
    }
}

int main(void){
    int N;
    cout << "Please enter an input N: ";
    cin >> N;

    cout << "The steps are as followed: " << endl;

    int steps = Hanoi(N, 'A', 'C', 'B');
    cout << "Steps needed: " << steps << endl;

    return 0;
}