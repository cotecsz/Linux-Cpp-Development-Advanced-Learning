//
// Created by Yang Shuangzhen on 2020/10/18.
//

#include <iostream>
#include <vector>
using namespace std;

int coun = 0;

/*
 * tn: traversed n，即已经遍历过的物品；
 * rw: reserved w，即背包还能容量的重量。
 */

int DP(const std::vector<int>& w, const std::vector<int>& v, int N, int W) {
    int dp[N+1][W+1]; memset(dp, 0, sizeof(dp)); // 创建备忘录

    // 初始化状态
    for (int i = 0; i < N + 1; i++) { dp[i][0] = 0; }
    for (int j = 0; j < W + 1; j++) { dp[0][j] = 0; }

    for (int tn = 1; tn < N + 1; tn++) { // 遍历每一件物品
        for (int rw = 1; rw < W + 1; rw++) { // 背包容量有多大就还要计算多少次
            if (rw < w[tn]) {
                // 当背包容量小于第tn件物品重量时，只能放入前tn-1件
                dp[tn][rw] = dp[tn-1][rw];
            } else {
                // 当背包容量还大于第tn件物品重量时，进一步作出决策
                dp[tn][rw] = max(dp[tn-1][rw], dp[tn-1][rw-w[tn]] + v[tn]);
            }
        }
    }

    return dp[N][W];
}

int DPSol() {
    int N = 3, W = 5; // 物品的总数，背包能容纳的总重量
    std::vector<int> w = {0, 3, 2, 1}; // 物品的重量
    std::vector<int> v = {0, 5, 2, 3}; // 物品的价值

    return DP(w, v, N, W); // 输出答案
}



int main(){
    cout << 5 /3 << endl;
    traversal()
    return 0;
}
