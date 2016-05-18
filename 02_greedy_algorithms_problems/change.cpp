/* ------------------------------------------------------- */
/*  1 <= m <= 10^3,
/*   Output the minimum number of coins with denominations
/*   1, 5, 10 that changes m.
/* ------------------------------------------------------- */
#include <iostream>
using namespace std;
int get_change(int n){
    //write your code here
    int coin[3] = {10, 5, 1};
    // use maxmize value of coin first util n is not enough for the value
    // and then keep doing same thing on second maxmize value
    int i=0, useNumber=0;
    while(i < 3){
        if(coin[i] <= n){
            int N = n/coin[i];
            n = n - coin[i]*N;
            useNumber = useNumber + N;
        }
        i++;
    }
    return useNumber;
}
int main(){
    int n;
    cin >> n;
    cout << get_change(n) << '\n';
}
