#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
private:
    stack<int> Positions;
    vector<vector<string>> result;

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
            vector<string> temp = add_solution(s, N);
            result.push_back(temp);
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

    // 把stack轉成題目要的形式:
    // [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
    vector<string> add_solution(stack<int>& s, int n){
        if(s.empty()){
            return {};
        }
        int col = s.top();
        s.pop();
        vector<string> temp = add_solution(s, n);
        string result;

        //新增 '.' 和 'Q'
        for(int i=0; i<col; i++){
            result += '.';
        }
        result += 'Q';
        for(int i=col+1; i<n; i++){
            result += '.';
        }

        s.push(col);
        temp.push_back(result);

        return temp;
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        KQueens(Positions, n);
        return result;
    }
};