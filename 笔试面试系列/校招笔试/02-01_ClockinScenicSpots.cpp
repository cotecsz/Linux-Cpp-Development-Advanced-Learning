//
// Created by Yang Shuangzhen on 2020/10/13.
//

#include <vector>
#include <iostream>
using namespace std;

/*
 * 给定几个城市，每个城市有多个旅游景点，在朋友圈打卡：要求每个城市的景点必须在一起。至少需要发几个朋友圈
 *
 * 输入示例：[1, 2, 1, 3, 4, 6, 5, 9]
 *          1 1 2 3 3 4 6 8 8 9 9
 * 输出示例：4
 *
 * 基本思路：贪心算法。
 */

int numClock(vector<int>& city){
    sort(city.rbegin(), city.rend());
    if (city.size() == 0)   return 0;

    for (auto c : city)
        cout << c << " ";
    cout << endl;
    vector<bool> visited(city.size(), false);
    int res = 0;
    int total = 0;

    int i = 0;
    while (i < city.size()){
        total = city[i];
        if (visited[i]){
            i++;
            continue;
        }
        visited[i] = true;
        for (int j=city.size()-1; j >= 0 && !visited[j]; j--){
            if (total+city[j] <=  9){
                total += city[j];
                visited[j] = true;
            }
        }
        i++;
        res += 1;
    }

    return res;
}

int main(){
    vector<int> city;
    int nSpots;
    while (true){
        cin >> nSpots;
        city.push_back(nSpots);
        if (getchar() == '\n')    //检测如果是空格，退出循环；
            break;
    }

    for (auto c : city)
        cout << c << " ";
    cout << endl;
    int res = numClock(city);
    cout << res << endl;
    return 0;
}