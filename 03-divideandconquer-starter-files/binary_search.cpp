/* -----------------binary search algorithm----------------------- */
/* input format:
/* first line, number of integers(sorted in increasing order) + integers
/* second line, number of search keys + integers
/* output format:
/* index of search key, if not found in input array, output -1
/* ---------------------------------------------------------------- */
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int binary_search(const vector<int> &a, int x){
    int left = 0, right = (int)a.size();
    //write your code here
    // binary search會不斷將搜尋區域切一半, key每次只會和中間的值做比較
    while(left <= right){
        int mid = (left+right)/2;
        if(x == a[mid])
            return mid;
        // if key < a[mid], update index right bound to mid-1
        else if(x < a[mid])
            right = mid - 1;
        // if key > a[mod], update index left bound to mid+1
        else if(x > a[mid])
            left = mid + 1;
    }
    // not found the key
    return -1;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++){
        cin >> a[i];
    }
    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i){
        cin >> b[i];
    }
    for (int i = 0; i < m; ++i){
        //replace with the call to binary_search when implemented
        cout << binary_search(a, b[i]) << ' ';
    }
}
