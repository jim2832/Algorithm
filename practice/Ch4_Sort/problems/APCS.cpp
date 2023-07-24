#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    return a.first * b.second < a.second * b.first;
}

int main(){
    int n;
    vector<pair<int, int>> objects;
    long long int total_cost = 0;
    long long int sum = 0;

    cin >> n;
    objects.resize(n);

    for(int i=0; i<n; i++){
        // weight
        cin >> objects[i].first;
    }
    for(int i=0; i<n; i++){
        // frequency
        cin >> objects[i].second;
    }

    sort(objects.begin(), objects.end(), compare);

    for(int i=0; i<n-1; i++){
        sum += objects[i].first;
        total_cost += sum * objects[i+1].second;
    }
    cout << total_cost << endl;

    return 0;
}