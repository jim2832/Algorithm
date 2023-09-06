#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <stack>
#include <algorithm>
using namespace std;

//印出stack內的所有內容
void print_stack(stack<int> s){
    if(s.empty()){
        return;
    }

    int cur = s.top();
    s.pop();
    print_stack(s); //把剩下的n-1筆資料放到stack內繼續做
    cout << cur + 1 << " ";
    s.push(cur);
}

// 確認 stack 內的內容是否合法
bool availible(stack<int> s, int row, int col){
    //確認(row, col)是否可以放
    if(s.empty()){
        return true;
    }
    int col_queen = s.top();
    s.pop();

    bool result = true;

    int diff_c = col - col_queen; //行的座標差
    int diff_r = row - s.size(); //列的座標差

    //如果在同一個行
    if(col == col_queen){
        result = false;
    }
    //如果在對角線上(行座標差=列座標差)
    if(diff_c == diff_r){
        result = false;
    }
    if(diff_c == -diff_r){
        result = false;
    }

    if(result){
        result = availible(s, row, col);
    }

    return result;
}

// 放 queen 的方式
int KQueens(stack<int>& s, int N){
    //滿了 -> 代表結束了
    if(s.size() == N){
        print_stack(s);
        cout << endl;
        return 1;
    }

    int count = 0;
    for(int i=0; i<N; i++){
        if(availible(s, s.size(), i)){ //代表在s這個stack，如果想放第i列，是否合法
            s.push(i);
            count += KQueens(s, N);
            s.pop();
        }
    }

    return count;
}

int main(void){
    int N;
    cout << "Please input a number: ";
    cin >> N;
    stack<int> Positions; //用來存 queen 的位置

    cout << "A total of " << KQueens(Positions, N) << " for N-Queen problem." << endl;

    return 0;
}