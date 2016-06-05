/* ------------------- knapsack without repetitions ----------------------- */
/* take as much gold as possible into your bag.
/* just one of each you can either take it or not (cannot take a fraction of a bar).
/* 1 <= W <= 10^4, 1 <= n <= 300, 0 <= w0,...,wn-1 <= 10^5
/* input format: capacity W and number n of bars of gold
/* output format: maximum weight of gold that fits W
/* ------------------------------------------------------------------------ */

/* 0/1 knapsack problem, c(n, w) = max(c(n-1, w), c(n-1, w-weight[n]) + cost[n])
   對某一件物品來說, 選擇放或不放, 一件物品放進背包, cost上升, 耐重下降, 不放就是原有的cost跟耐重都不變
   上述式子的意思是取放or不放後的c(n)最大值, 是背包問題中關鍵的式子 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int optimal_weight(int W, const vector<int> &w){
    // use 1-D array from n to (n - weight) to fill the array
    vector<int> c(W+1);
    // 可用一維陣列由後面往前填數字, 節省使用DP的空間
    for(int i = 0; i < w.size(); ++i){
        // 選擇放與不放兩種情況中, c[j]的最大值
        // 需要注意的是j不可能由比第i個物品價值還小的地方填數字
        for(int j = W; j >= w[i]; --j){
            // in this problem, cost and weight is equal
            c[j] = max(c[j], c[j-w[i]] + w[i]);
        }
    }
    // c[W] is the maximum value of knapsack with W weight
    return c[W];
}

int main(){
    int n, W;
    cin >> W >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++){
        cin >> w[i];
    }
    cout << optimal_weight(W, w) << '\n';
}
