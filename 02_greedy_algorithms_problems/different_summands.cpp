/* ----------------------Pairwise Distinct Summands----------------------- */
/* 輸出最多且不一樣的整數，相加起來等於n
/* input format: single integer n, 1<=n<=10^9
/* output format:
/* first line: the maximum number k, second line: distinct positive integers
/* ex: 8 = 1+2+5
/* ----------------------------------------------------------------------- */
#include <iostream>
#include <vector>

using namespace std;

vector<int> optimal_summands(int n){
    vector<int> summands;
    //write your code here
    /* Accroding to problem description:
       assume k=n, l=1
       if(k<=2l)
         push k in summands;
       else
         push l in summands; k = k - l; l = l + 1;
    */
    int l = 1;
    while(n > l*2){
        summands.push_back(l);
        n = n - l;
        l++;
    }
    summands.push_back(n);
    return summands;
}
int main(){
    int n;
    cin >> n;
    vector<int> summands = optimal_summands(n);
    cout << summands.size() << '\n';
    for (size_t i = 0; i < summands.size(); ++i){
        cout << summands[i] << ' ';
    }
}
