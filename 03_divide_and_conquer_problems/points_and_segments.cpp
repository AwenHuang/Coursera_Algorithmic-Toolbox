/* -------------------------------------------------------------- */
/* The goal in this problem is given a set of segments on a line
/* and a set of points on a line, to count, for each point,
/* the number of segments which contain it.
/* 輸出每個point被涵蓋在幾個segment上, 隨機資料量很大, 雙迴圈不可行
/* 這題根據Coursera老師的提示, 把所有位置存一起然後sorting後scan
/* 大幅減少run time, 時間複雜度從O(nm)→O(n*2+m)
/* --------------------------------------------------------------- */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Info{
    int pos;
    char type;
    int pointIndex;
};

bool myCompare(Info i1, Info i2){
    // special case: when segment and point have same pos value
    if(i1.pos == i2.pos){
        // must keep [L, P, R] order
        if((i1.type == 'L' && i2.type == 'P' ) || (i1.type == 'P' && i2.type == 'L'))
            return i1.type < i2.type;
        if((i1.type == 'P' && i2.type == 'R' ) || (i1.type == 'R' && i2.type == 'P'))
            return i1.type < i2.type;
        if((i1.type == 'L' && i2.type == 'R' ) || (i1.type == 'R' && i2.type == 'L'))
            return i1.type < i2.type;
    }
    return i1.pos < i2.pos;
}

vector<int> fast_count_segments(vector<Info> info, int pointNumber){
    vector<int> cnt(pointNumber);
    //write your code here
    int left = 0;
    for(size_t i = 0; i < info.size(); i++){
        //cout << info[i].pos << ", " << info[i].type << endl;
        if(info[i].type == 'P'){
            cnt[info[i].pointIndex] = left;
        }
        if(info[i].type == 'L'){
            left++;
        }
        if(info[i].type == 'R'){
            left--;
        }
    }
    return cnt;
}
/* Naive method
vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}
*/
int main(){
    // n = number of segments, m = number of points
    int n, m;
    cin >> n >> m;
    vector<Info> info(n*2+m);  // store the position information of each segment and point in info structure
    // store segments
    int j = 0;
    for (size_t i = 0; i < n; i++){
        cin >> info[j].pos >> info[j+1].pos;
        info[j].type = 'L'; info[j+1].type = 'R';
        info[j].pointIndex = -1; info[j+1].pointIndex = -1;
        j = j + 2;

    }
    // store points
    for(size_t i = 0; i < m; i++){
        cin >> info[j].pos;
        info[j].type = 'P';
        info[j].pointIndex = i;
        j++;

    }
    // sort the info by pos value
    sort(info.begin(), info.end(), myCompare);
    //use fast_count_segments
    vector<int> cnt = fast_count_segments(info, m);
    for (size_t i = 0; i < cnt.size(); i++){
        cout << cnt[i] << ' ';
    }
}
