/* ------------------------------------------------------------------------------------------------------------------- */
/* primitive calculator: *2 or*3 or +1
/* Given an integer n, compute the minimum number of operations needed to obtain the number n starting from the number 1.
/* Ex: input 5, output 3, 1 2 4 5 (1+1, 2*2, 4+1)
/* 1 <= n <= 10^6.
/* output format:
/* first line is the minimum number of operation
/* second line is sequence of integers that reach to n (maybe not just one, but only need to output one of them)
/* ------------------------------------------------------------------------------------------------------------------- */
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
// greedy algorithm from starter files (incorrect)
vector<int> greedyCalculator(int n){
    vector<int> sequence;
    /* at each step we replace n by min{n/3, n/2, n-1)
    (the terms n=3 and n=2 are used only when n is divisible by 3 and 2, respectively)*/
    while (n >= 1){
        sequence.push_back(n);
        if (n % 3 == 0){
            n /= 3;
        }
        else if (n % 2 == 0){
            n /= 2;
        }
        else{
            n = n - 1;
        }
    }
    reverse(sequence.begin(), sequence.end());
    return sequence;
}

// use Dynamic Programming method to reach the optimal
vector<int> optimal_sequence(int n){
    vector<int> sequence;
    // store minmum operation of 1~n
    vector<int> CostRecord(n+1);
    CostRecord[0] = 0;
    CostRecord[1] = 0;
    int div2, div3, minus1, prevStep;
    // record minmum operation from 1~n, bottom-up
    for(int i = 2; i < CostRecord.size(); i++){
        div2 = -1; div3 = -1; minus1 = -1, prevStep = 0;
        if(i%2 == 0)
            div2 = i/2;
        if(i%3 == 0)
            div3 = i/3;
        minus1 = i - 1;

        // find minimum cost from previous possible index
        if(div2 == -1 && div3 != -1)
            prevStep = min(CostRecord[minus1], CostRecord[div3]);
        else if(div3 == -1 && div2 != -1)
            prevStep = min(CostRecord[minus1], CostRecord[div2]);
        else if(div2 == -1 && div3 == -1)
            prevStep = CostRecord[minus1];
        else
            prevStep = min(CostRecord[minus1], min(CostRecord[div2], CostRecord[div3]));

        // store minimum cost of i
        CostRecord[i] = prevStep + 1;
    }

    int lastIndex = CostRecord.size()-1;
    int temp = lastIndex;
    sequence.push_back(lastIndex);

    // back tracking from CostRecord[n-1] to find sequence reach to n
    for(int i = lastIndex-1; i >= 1; i--){
        // if CostRecord[i] is possible prevous step (cost is current cost minus 1)
        if(CostRecord[i] == CostRecord[temp]-1){
            // then check the i value is possible or not
            if(temp%i == 0 || i == (temp-1)){
                sequence.push_back(i);
                temp = i;
            }
            else
                continue;
        }
    }
    reverse(sequence.begin(), sequence.end());
    return sequence;
}
int main(){
    int n;
    cin >> n;
    vector<int> sequence = optimal_sequence(n);
    cout << sequence.size() - 1 << endl;
    for (size_t i = 0; i < sequence.size(); ++i){
        cout << sequence[i] << " ";
    }
}
