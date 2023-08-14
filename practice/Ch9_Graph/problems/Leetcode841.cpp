#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

//要記錄哪些房間已經走過，而哪些沒有

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int num_room = rooms.size();
        vector<bool> visited(num_room, false); //紀錄房間的走訪與否
        visit(rooms, visited, 0); //先走訪第一間

        for(int i=0; i<num_room; i++){
            //若已經走訪完，但還有房間沒被走訪過
            if(!visited[i]){
                return false;
            }
        }

        return true;
    }

    // 用來走訪之 function
    void visit(vector<vector<int>>& rooms, vector<bool>& visited, int current){
        visited[current] = true; //先把現在走訪的房間設為「已走訪」

        //取出某個房間內的所有鑰匙
        for(auto key:rooms[current]){
            //若這個 key 可以到達的房間已經拜訪過，直接繼續
            if(visited[key]){
                continue;
            }
            else{
                visit(rooms, visited, key); //透過DFS繼續拜訪下去
            }
        }
    }
};