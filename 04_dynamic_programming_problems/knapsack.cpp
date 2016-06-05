/* ------------------- knapsack without repetitions ----------------------- */
/* take as much gold as possible into your bag.
/* just one of each you can either take it or not (cannot take a fraction of a bar).
/* 1 <= W <= 10^4, 1 <= n <= 300, 0 <= w0,...,wn-1 <= 10^5
/* input format: capacity W and number n of bars of gold
/* output format: maximum weight of gold that fits W
/* ------------------------------------------------------------------------ */

/* 0/1 knapsack problem, c(n, w) = max(c(n-1, w), c(n-1, w-weight[n]) + cost[n])
   ��Y�@�󪫫~�ӻ�, ��ܩ�Τ���, �@�󪫫~��i�I�], cost�W��, �@���U��, ����N�O�즳��cost��@��������
   �W�z���l���N��O����or����᪺c(n)�̤j��, �O�I�]���D�����䪺���l */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int optimal_weight(int W, const vector<int> &w){
    // use 1-D array from n to (n - weight) to fill the array
    vector<int> c(W+1);
    // �i�Τ@���}�C�ѫ᭱���e��Ʀr, �`�٨ϥ�DP���Ŷ�
    for(int i = 0; i < w.size(); ++i){
        // ��ܩ�P�����ر��p��, c[j]���̤j��
        // �ݭn�`�N���Oj���i��Ѥ��i�Ӫ��~�����٤p���a���Ʀr
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
