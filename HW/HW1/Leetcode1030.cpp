#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        // 距離為: 需要走幾步要那個格子
        // (r1, c1) and (r2, c2) is |r1 - r2| + |c1 - c2|
        vector<vector<int>> result; // (rows * cols, 2)
        map<int, vector<vector<int>>> mp; //紀錄每一個的距離

		for(int i=0; i<rows; i++){
			for(int j=0; j<cols; j++){
				int dist = abs(i - rCenter) + abs(j - cCenter);
				mp[dist].push_back({i,j});
			}
		}

        //將排序好的vector push 進 result
		for(auto m:mp){
			for(auto vec : m.second){
                result.push_back(vec);
            }
		}

        return result;
    }
};