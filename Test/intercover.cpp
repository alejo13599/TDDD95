#include <bits/stdc++.h>
using namespace std;
 
// Function to find the minimum number
// of intervals in the array A[] to
// cover the entire target interval
int minimizeSegment(vector<pair<int, int> > A,
                    pair<int, int> X)
{
    // Sort the array A[] in increasing
    // order of starting point
    sort(A.begin(), A.end());
    vector<int> intervallvector = {};
    // Insert a pair of INT_MAX to
    // prevent going out of bounds
    A.push_back({ INT_MAX, INT_MAX });
 
    // Stores start of current interval
    int start = X.first;
 
    // Stores end of current interval
    int end = X.first - 1;
 
    // Stores the count of intervals
    int cnt = 0;
 
    // Iterate over all the intervals
    for (int i = 0; i < A.size();) {
        cout << i << "iterating " << A[i].first << '\n';
        // If starting point of current
        // index <= start
        if (A[i].first <= start) {
            end = max(A[i++].second, end);
        }
        else {
 
            // Update the value of start
            //cout << "start:" << start << " ";
            start = end;
            //cout << "start:" << start << " ";
            //cout << "end:" << end << " i"<< i;
 
            // Increment the value
            // of count
            ++cnt;
            cout << "hej" << '\n';
            intervallvector.push_back(i-1);
 
            // If the target interval is
            // already covered or it is
            // not possible to move
            // then break the loop
            if (A[i].first > end
                || end >= X.second) {
                break;
            }
        }
    }
 
    // If the entire target interval
    // is not covered
    if (end < X.second) {
        return -1;
    }
 
    // Return Answer
    //cout << "Intervallvektor " << intervallvector[0];
    return cnt;
}
 
// Driver Code
int main()
{
    vector<pair<int, int> > A = {
        { 0, 25 }, { 25, 75 }, { 75, 100}
    };
    // vector<pair<int, int> > A = {
    //     { -9, -1 }, { -2, 20 }, { -7, 10}
    // };    
    pair<int, int> X = {0, 100};
    cout << minimizeSegment(A, X);
 
    return 0;
}