/*

題目說明：

有一段距離為d的旅途需要行駛，油箱的容量每次只能連續走c
給定一連串的加油站位置gi，每次加油後都能夠繼續行走c
則該如何安排加油的地點可以讓停下來的次數最少?

-> 本題使用貪婪演算法(greedy)
-> 會選擇每次耗盡油量前的最後一個加油站

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    // c 代表每次加滿油能開的距離
    // d 代表總距離
    // n 代表加油站的個數
    int c, d, n;
    cout << "Please enter c, d and n: ";
    cin >> c >> d >> n;
    vector<int> gas_station(n); //加油站之vector

    //輸入每個加油站的位置
    for(int i=0; i<n; i++){
        cin >> gas_station[i];
    }

    sort(gas_station.begin(), gas_station.end()); //將加油站的位置由小到大排序好
    int stops = 0; //紀錄停下來了幾次

    gas_station.push_back(d); //在終點也放一個加油站，來避開檢查邊界條件

    int last_stop_index = -1; //紀錄上一個停靠加油站的index
    int last_stop_position = 0; //紀錄上一個停靠的加油站位置

    for(int i=0; i<n+1; i++){
        if(gas_station[i] - last_stop_position > c){ //若移動之間的距離差超過c，則代表會走不到
            if(last_stop_index == i-1){ //上一個停的加油站是第i-1個，也就是說中間沒有加油站可以停了
                cout << "There is no solution" << endl;
                stops = -1;
                break;
            }
            last_stop_index = i-1; //若第i個到不了，則停在第i-1個
            last_stop_position = gas_station[i-1];
            stops++;
            cout << "Stop at " << last_stop_position << endl;
            i--;
        }
    }

    cout << "Total stops: " << stops << endl;
    
    return 0;
}