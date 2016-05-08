#include <iostream>
using namespace std;
int gcd(int a, int b){
    if(b == 0)
        return a;

    gcd(b, a%b);
}
long long lcm(int a, int b){
    //write your code here
    /* LCM(a, b)*GCD(a, b) = a*b
       So, LCM(a, b) = (a*b)/GCD(a, b)
       But in order to avoid too large integer,
       we can seperate calculation to a*(b/GCD(a,b))
    */
    int div = b/(gcd(a, b));
    return (long long)a*div;
}

int main(){
    int a, b;
    cin >> a >> b;
    cout << lcm(a, b) << endl;
    return 0;
}
