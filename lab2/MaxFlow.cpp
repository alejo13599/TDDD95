// Author: Alexander Josefsson
// Liuid: Alejo135
// Problem is: 
// Time-complexity: 
// Memory-complexity:
// Note: 


#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm> 
#include <queue>

using namespace std;
int N; //Number of nodes in graph.
int M; //Number of edges.
int S; //Source Node
int T; //Sink
int from;
int to;
int capacity;
vector<vector<int>> capacityVector;
vector<vector<int>> adj;
vector<tuple<int, int, int>> edges;

int main() 
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
cin >> N >> M >> S >> T;
    for(int i=0; i<M;i++){
    cin >> from >> to >> capacity;
    edges.push_back({from,to,capacity});
    }
return 0;
}