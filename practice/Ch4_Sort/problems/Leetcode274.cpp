#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int hIndex(vector<int>& citations){
            sort(citations.begin(), citations.end(), greater<int>());
            for(int i=0; i<citations.size(); i++){
                // i+1 -> papers
                // citation[i] -> citations
                if(i+1 > citations[i]){
                    return i;
                }
            }
            return citations.size();
        }
};