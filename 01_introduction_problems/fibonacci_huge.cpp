/*  Pisano period short explantion from Wiki
    In number theory, the nth Pisano period, written π(n),
    is the period with which the sequence of Fibonacci numbers taken modulo n repeats.
    With the exception of π(2) = 3, the Pisano period π(n) is always even.

    Important rule to implement algorithm:
    for any integer m >= 2, the sequence Fn mod m is periodic.
    The period always starts with 01 and is known as Pisano period.
*/
#include <iostream>
#include <cstring>
using namespace std;

long long get_fibonaccihuge(long long n, long long m){
    //write your code here
    if(n == 1)
        return n;
    int i;
    int range;
    bool nSmallthanP;
    // if n is small than possible pisano period then set the range = n.
    if(n < 6*m){
        range = n;
        nSmallthanP = true;
    }
    // if n is bigger than possible pisano peroid then set the range = 6*m (π(m) ≤ 6m)
    else{
        range = 6*m;
        nSmallthanP = false;
    }

    long long *fibRemain = new long long[range+3];
    fibRemain[0] = 0;
    fibRemain[1] = 1;
    /*  f2 = f1 + f0
        r0 = f0 mod n
        r1 = f1 mod n
        r2 = (r1 + r0) mod n
        We can just store the remainder in every fib array.
        This is a way to avoid fibonacci too large cause overflow. */

    // why range+2 ? (because π(10) = 60, its peroid just equals to 6m)
    for(i=2; i<=range+2; i++){

        fibRemain[i] = (fibRemain[i-1] + fibRemain[i-2])%m;
        if(fibRemain[i] == 1 && fibRemain[i-1] == 0)
            break;
        if(nSmallthanP && i == range){
            return fibRemain[i];
        }

    }
    //cout << "Pisano Period: " << i-1 << endl;
    n = n%(i-1);
    return fibRemain[n];
}
int main(){
    long long n, m;
    cin >> n >> m;
    cout << get_fibonaccihuge(n, m) << '\n';
}
