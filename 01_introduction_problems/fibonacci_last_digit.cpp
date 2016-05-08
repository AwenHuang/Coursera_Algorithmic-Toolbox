#include <iostream>

int get_fibonacci_last_digit(int n){
    //write your code here
    /* Finding last digit of a integer can use mod 10.
    /  ex: 1103 mod 10 = 3
    /  When finding last digit of fibonacci,
    /  it is not necessary to store the result if F[i].
    /  We can just store last digit in F[i] and avoid overflow.*/

    int *fibArray = new int[n+1];
    if(n <= 1){
        return n;
    }
    else{
        fibArray[0] = 0;
        fibArray[1] = 1;
        // i from 2 to n
        for(int i=2; i<=n; i++){
            // F[i] = (F[i-1] + F[i-2]) mod 10
            fibArray[i] = (fibArray[i-1] + fibArray[i-2]) % 10;
        }
    }
    int result = fibArray[n];
    delete []fibArray;
    return result;
}

int main(){
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit(n);
    std::cout << c << '\n';
}
