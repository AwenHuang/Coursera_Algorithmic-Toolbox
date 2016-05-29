/* ------------------ Quick Sort--------------------- */
/* replace a 2-way partition with a 3-way partition.
/* works fast even on sequences containing many equal elements
/* partition the array into three parts: < x part, = x part, and > x part.
/* (m1, m2) ← Partition3(a, l, r)
/* for all l <= k <= m1-1, a[k] < x
/* for all m1 <= k <= m2, a[k] = x
/* for all m1+1 <= k <=r, a[k] > x
/* RandQuickSort(a, l, m1-1), RandQuickSort(a, m2+1, r)
/* -------------------------------------------------- */
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
/* original 2-way partition
int partition2(vector<int> &a, int l, int r){
    // x = pivot
    int x = a[l];
    int j = l;
    for (int i = l + 1; i <= r; i++){
        // pivot先不動, 比它小的數堆在它右手邊
        if (a[i] <= x){
            j++;
            swap(a[i], a[j]);
        }
    }
    // 最後pivot跟j的數值做交換, pivot會在它該在的位置
    // 右邊都比它大, 左邊都比它小
    swap(a[l], a[j]);
    return j;
}*/
/* 3-way partition */
vector<int> partition3(vector<int> &a, int l, int r){
    // x = pivot
    int x = a[l];
    int gt = r;
    int lt = l;
    for(int i = l; i <= gt; i++){
        // a[i] = pivot, i++
        // a[i] < pivot, 堆在pivot的左邊
        if(a[i] < x){
            swap(a[i], a[lt]);
            lt++;
        }
        // a[i] > pivot, 先放在右邊
        else if(a[i] > x){
            // 因為是拿未知的右邊數字根目前的a[i]交換
            // 交換完後的a[i]要再檢查一次, 這裡不能讓i++
            swap(a[i], a[gt]);
            i--;
            gt--;
        }
    }
    vector<int> pos(2);
    pos[0] = lt; pos[1] = gt;
    return pos;
}
void randomized_quick_sort(vector<int> &a, int l, int r){
    if (l >= r){
        return;
    }
    // choose pivot randomly
    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);
    //int m = partition2(a, l, r);
    vector<int> pivotFinalPos(2);
    pivotFinalPos = partition3(a, l, r);

    randomized_quick_sort(a, l, pivotFinalPos[0] - 1);
    randomized_quick_sort(a, pivotFinalPos[1] + 1, r);
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i){
        cin >> a[i];
    }
    randomized_quick_sort(a, 0, a.size() - 1);
    for (size_t i = 0; i < a.size(); ++i){
        cout << a[i] << ' ';
    }
}
