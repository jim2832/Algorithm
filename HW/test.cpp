#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int main(void){
    int rows = 2, cols = 3, rCenter = 1, cCenter = 2;

    vector<vector<int>> result;
    vector<vector<int>> distance(rows, vector(cols, 0));

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            // int dist = abs(rCenter - i) + abs(cCenter - j);
            // distance[i][j] = dist;
            result.push_back({i, j});
        }
        cout << endl;
    }

    for(int i=0; i<rows*cols; i++){
        for(int j=0; j<2; j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}