#include <iostream>
using namespace std;
/* 0 <= n <= 45 */
int calc_fib(int n) {
    int *fibArray = new int[n+1];
    if(n <= 1){
        return n;
    }
    else if(n > 1){
        fibArray[0] = 0;
        fibArray[1] = 1;
        for(int i=2; i<=n; i++){
            fibArray[i] = fibArray[i-1] + fibArray[i-2];
        }
    }
    int result = fibArray[n];
    delete []fibArray;
    return result;
}
int main() {
    int n = 0;
    std::cin >> n;
    std::cout << calc_fib(n) << '\n';
    return 0;
}
