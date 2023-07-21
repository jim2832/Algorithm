#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Selection sort time complexity
// Best : O(n)
// Avg : O(n^2)
// Worst : O(n^2)
// Memory : O(n)
// Stable

vector<int> Shaker_sort(vector<int> &nums){
    int left = 0, right = nums.size() - 1;
    int shift;
    
    while(left != right){
        for(int i=left; i<right; i++){
            if(nums[i] > nums[i+1]){
                int temp = nums[i];
                nums[i] = nums[i+1];
                nums[i+1] = temp;
                shift = i;
            }
        }
        right = shift;
        for(int i=right-1; i>=left; i--){
            int temp = nums[i];
            nums[i] = nums[i+1];
            nums[i+1] = temp;
            shift = i+1;
        }
        left = right;
    }
    return nums;
}

int main(){
    vector<int> data = {35,52,68,12,47,52,36,52,74,27};
    Shaker_sort(data);

    for(int i=0;i<10;i++)
        cout << data[i] << " ";
    cout << endl;

    return 0;
}