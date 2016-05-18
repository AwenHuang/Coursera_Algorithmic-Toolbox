/* ------------------------------------------------ */
/*  1 <= n <= 10^3, -10^5 <= a,b <= 10^5
/*  n = number of integers in the sequences
/*  first line = a sequence, second line = b sequence
/*  Output the minimum possible dot product.
/*  Note: It is important to use right data type.
/* ------------------------------------------------ */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
long long min_dot_product(vector<long long> a, vector<long long> b){
    // write your code here
    long long result = 0;
    // sorting a and b, smaller to bigger
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    /* The biggest integer can not multiply with another biggerst integer,
       So I choose the samllest interger in a multiply with biggest integer in b
    */
    size_t sequence_n = a.size();
    for (size_t i = 0; i < sequence_n; i++){
        result = result + a[i]*b[sequence_n-1-i];
    }
    return result;s
}

int main(){
    size_t n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (size_t i = 0; i < n; i++){
        cin >> a[i];
    }
    for (size_t i = 0; i < n; i++){
        cin >> b[i];
    }
    cout << min_dot_product(a, b) << endl;
}
