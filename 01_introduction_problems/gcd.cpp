#include <iostream>

int gcd(int a, int b) {
    //write your code here
    // compute GCD can use recursive to improve time complexity
    // 其實就是輾轉相除法
    if(b == 0)
        return a;

    gcd(b, a%b);
}

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << gcd(a, b) << std::endl;
    return 0;
}
