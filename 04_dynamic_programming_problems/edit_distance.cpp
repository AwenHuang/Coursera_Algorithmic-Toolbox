/* --------------------- Compute Edit Distance ----------------------------- */
/* minimum number of insertions, deletions, and mismatches in an alignment of two strings.
/* 比對兩個字串時, 新增, 刪除, 修改一個字元算做一步, 最小需要幾步
/* Input format: lower case latin letters (length is >=1 <=100)
/* Output format: edit distance between the given two strings/* ex: short ports = 3, ab ab = 0
/* ------------------------------------------------------------------------ */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int edit_distance(const string &str1, const string &str2){
    int n = str1.size();
    int m = str2.size();
    // declare (n+1) x (m+1) 2D vector array
    vector <vector<int> > D(n+1, vector<int>(m+1));
    // fill fist row and first column
    for(int i = 0; i <= n; i++)
        D[i][0] = i;
    for(int j = 0; j <= m; j++)
        D[0][j] = j;
    // put 1~n loop inner because the edit distance algorithm fills column not row
    for(int j = 1; j <= m; j++){
        for(int i = 1; i <= n; i++){
            int insertion = D[i][j-1] + 1;
            int deletion = D[i-1][j] + 1;
            int match = D[i-1][j-1];
            int notmatch = D[i-1][j-1] + 1;
            // match
            if(str1.at(i-1) == str2.at(j-1))
                D[i][j] = min(insertion, min(deletion, match));
            // not match
            else
                D[i][j] = min(insertion, min(deletion, notmatch));
        }
    }
    return D[n][m];
}

int main(){
    string str1;
    string str2;
    cin >> str1 >> str2;
    cout << edit_distance(str1, str2) << endl;
    return 0;
}
