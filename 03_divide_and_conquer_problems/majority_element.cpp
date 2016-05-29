/* -----------Majority Element(²³¼Æ)----------- */
/* check whether an input sequence contains a majority element
/* input format:
/* fitst line is number of integers
/* second line is a sequence of integers
/* output format:
/* 1 or 0
/* -------------------------------------------- */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int get_majority_element(vector<int> &a){
    //write your code here
    /* according to problem 2 description, this problem can also be solved in O(n) time by a more advanced
       (non-divide and conquer) algorithm that just scans the given sequence twice.
       Use a count to record integer appear times.
       if majority element exist then count must >= 1.
    */
    int Count = 1, majorityIndex = 0;
    // because Count has already assigned 1, for loop start from index 1
    for(int i = 1; i < a.size(); i++){
        // if a[left] not equal to current majority candidate, then Count--
        if(a[i] != a[majorityIndex])
            Count--;
        // if equal, Count++
        else
            Count++;
        // if Count = 0, change candidate, set Count = 1
        if(Count == 0){
            majorityIndex = i;
            Count = 1;
        }
    }
    int checkCount = 0;
    // After counting we need to check the existence of majority.
    for(int i = 0; i < a.size(); i++){
        if(a[i] == a[majorityIndex])
            checkCount++;
    }
    if(checkCount > a.size()/2)
        return 1;
    else
        return 0;
}
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i){
        cin >> a[i];
    }
    cout << get_majority_element(a) << '\n';
}
