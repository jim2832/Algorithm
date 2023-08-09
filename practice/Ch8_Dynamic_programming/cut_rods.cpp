#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Cut_rod(int* p, int p_len, int n){
    if(n == 0){
        return 0;
    }

    int revenue_array[n+1];

    for(int i=1; i<n; i++){
        int max_revenue = -2147483648;
        for(int j=0; j<p_len; j++){
            if(i <= j){
                break;
            }
            int revenue_j = p[j] + revenue_array[i-j-1];
            max_revenue = max_revenue > revenue_j ? max_revenue : revenue_j;
        }
        revenue_array[i] = max_revenue;
    }

    return revenue_array[n];
}