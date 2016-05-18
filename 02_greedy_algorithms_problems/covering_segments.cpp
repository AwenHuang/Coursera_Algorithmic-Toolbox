/*--------------------------------------------------------------------*/
/* 輸出能cover到所有區間的最小點數, 並印出每點的值
/* first line of input : number n of segments
/* following n lines : start and end point
/* Output the minimum number m of points on the frst line
/* and the integer coordinates of m points (separated by spaces) on the second line.
/*---------------------------------------------------------------------*/
#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

struct Segment{
    int startP, endP;
};
bool myCompare(Segment i1, Segment i2){
    return i1.endP < i2.endP;
}
vector<int> optimal_points(vector<Segment> &segments){
    vector<int> points;
    //write your code here
    size_t segments_n = segments.size();
    int foremost = 0;

    // because segments has been sorted by endP value, we can use for loop to evalue endP of foremost segments.
    for(size_t i = 0; i < segments_n; i++){
        // if the segments[foremost].endP is in segments[i]'s range
        // push segments[foremost].endP to points
        if(segments[foremost].endP >= segments[i].startP
           && segments[foremost].endP <= segments[i].endP){
            // check the points status to avoid storing the duplicate point
           if(!points.empty() && points.back()==segments[foremost].endP)
                continue;
           points.push_back(segments[foremost].endP);
        }
        // if not then update foremost, foremost = i
        else{
            foremost = i;
            // i need to minus 1 because back to the for loop, i will plus 1
            // we must compare segments in its range first (special situation: [1, 1] [2, 2] ...)
            i = i-1;
        }
        // if last segments can't be coverd
        if(foremost == segments_n-1)
            points.push_back(segments[foremost].endP);
       //cout << "foremost: " << foremost << endl;
    }
    return points;
}
int main(){
    int n;
    cin >> n;
    vector<Segment> segments(n);

    for (size_t i = 0; i < segments.size(); ++i){
        cin >> segments[i].startP >> segments[i].endP;
    }

    // sort segments by endP value
    sort(segments.begin(), segments.end(), myCompare);

    vector<int> points = optimal_points(segments);

    cout << points.size() << endl;
    for (size_t i = 0; i < points.size(); ++i){
        cout << points[i] << " ";
    }
}
