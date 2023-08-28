#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

// BFS solution

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        queue<int> q;
        int total = 0;
        q.push(id); //第一個要找的人

        //BFS
        while(!q.empty()){
            int current = q.front(); //取出q第一個
            q.pop(); //dequeue
            
            //走訪所有員工，找到第一個要找的人
            for(int i=0; i<employees.size(); i++){
                Employee *emp = employees[i];
                //找到
                if(emp->id == current){
                    total += emp->importance; //累加importance
                    //走訪他所有的員工
                    vector<int> sub = emp->subordinates;
                    for(int j=0; j<sub.size(); j++){
                        q.push(sub[j]);
                    }
                }
            }
        }

        return total;
    }
};