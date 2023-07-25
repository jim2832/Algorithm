// 讓使用者輸入一個大於1的數字 x 與可容許誤差 E ，透過 Binary search 來求出 sqrt(x, 2) 的值，誤差範圍需在 E 以內

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

double Square(double x, double lower, double upper, double error){ //error代表可以容忍的誤差
    double middle = (lower + upper) / 2;

    if(abs(pow(middle, 2) - x) < error){
        return middle;
    }
    else if(pow(middle, 2) > x){
        return Square(x, lower, middle, error);
    }
    else if(pow(middle, 2) < x){
        return Square(x, middle, upper, error);
    }
}

int main(void){
    double x, error;
    cout << "Please enter x(>1) and the error: " << endl;
    cin >> x >> error;

    cout << Square(x, 1, x, error);

    return 0;
}