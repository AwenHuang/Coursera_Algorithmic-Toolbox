/* ----------------------- Easier Knapsack Problem ----------------- */
/* first line of input(n, W) = numbers of items, capacity of a knapsack
/* next n lines (v, w) define the values and weights of the items.
/* Output the maximal value of fractions of items that fit into the knapsack.
/* ----------------------------------------------------------------- */
#include <iostream>
#include <vector>
#include <functional>   // std::greater
#include <algorithm>    // std::sort
#include <iomanip>   // setprecision
using namespace std;
struct Item{
    int value;
    int weight;
    double ValuePerWeight;
};
bool myCompare(Item i1, Item i2){
    return i1.ValuePerWeight > i2.ValuePerWeight;
}
double get_optimal_value(int capacity, vector<Item> items){
    double value = 0.0;

    // write your code here
    /* choose the maximize ValuePerWeight item first
       because we alreay sorting the items array by ValuePerWeight
       we can do for loop to test one by one
    */
    vector<Item>::iterator it;
    for(it = items.begin(); it!=items.end(); ++it){
        // if items full weight smaller than current capacity, put all items.
        if(it->weight <= capacity){
            value = value + it->value;
            capacity = capacity - it->weight;
        }
        // if items full weight greater than current capacity, put fractional items to fill the capacity.
        else{
            value = value + capacity*(it->ValuePerWeight);
            capacity = capacity - capacity;
        }
    }
    return value;
}

int main(){
    int n;
    int capacity;
    cin >> n >> capacity;
    vector<Item> items(n);

    for (int i = 0; i < n; i++){
        cin >> items[i].value >> items[i].weight;
        items[i].ValuePerWeight = (double)items[i].value/(double)items[i].weight;
    }
    // sorting the items by ValuePerWeight
    sort(items.begin(), items.end(), myCompare);
    double optimal_value = get_optimal_value(capacity, items);

    // answer with at least four digits after the decimal point
    cout << fixed << setprecision(4) << optimal_value << endl;
    return 0;
}
