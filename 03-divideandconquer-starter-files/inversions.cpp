/* -------------------- Counting Inversions -------------------- */
/* Output the number of inversions in the sequence
/* Use MergeSort to count the movement of all integers in sorting
/* sorted(non-descending order),
/* 1 2 3 -> inversion is 0; 3 2 1 -> inversion is 3
/* ------------------------------------------------------------- */
#include <iostream>
#include <vector>

using namespace std;

long long MergeAndCount(vector<int> &a, vector<int> &left, vector<int> &right){
    int i = 0, j = 0, k = 0;
    long long Count = 0;
    while(i < left.size() && j < right.size()){
        if(left[i] <= right[j]){
            a[k] = left[i];
            i++;
        }
        // right[j] > left[i] -> inversion happens
        else{
            // base on left index, compute the movement of right[j] after merging
            Count = Count + (left.size() - i);
            a[k] = right[j];
            j++;
        }
        k++;
    }
    // if left or right array have number not be sorted
    while(i < left.size()){
        a[k] = left[i];
        i++; k++;
    }
    while(j < right.size()){
        a[k] = right[j];
        j++; k++;
    }
    return Count;
}
long long MergeSort(vector<int> &a){
    int n = a.size();
    if(n == 1)
        return 0;

    int leftSize = n/2;
    int rightSize = n-leftSize;
    vector<int> left(leftSize);
    vector<int> right(rightSize);
    for(int i = 0; i < leftSize; i++)
        left[i] = a[i];
    for(int i = 0; i < rightSize; i++)
        right[i] = a[leftSize+i];

    long long rA=0, rB=0, r=0;
    rA = MergeSort(left);
    rB = MergeSort(right);
    r = MergeAndCount(a, left, right);

    r = r + rA + rB;
    return r;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++){
        cin >> a[i];
    }
    cout << MergeSort(a) << endl;;
    /*for (size_t i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }*/
}
