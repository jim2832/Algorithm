#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
    public:
        Node* cloneGraph(Node* node) {
            // exception
            if(node == 0){
                return 0;
            }

            // 檢查是否已經複製過
            if(Copied.find(node) == Copied.end()){ //若還沒複製過
                Copied[node] = new Node(node->val); //開一個新的node，並assign給他點的值

                //將所有鄰居都複製過去
                for(Node* neighbor:node->neighbors){
                    (Copied[node]->neighbors).push_back(cloneGraph(neighbor));
                }
            }

            return Copied[node];
        }
    
    private:
        // node -> clone
        map<Node*, Node*> Copied; //紀錄複製的進度
};