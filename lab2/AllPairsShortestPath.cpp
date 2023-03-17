// Author: Alexander Josefsson
// Liuid: Alejo135
// Problem is: All pairs shortest path. To find the shortest path betwwen all pairs of nodes in a grapp.
// Time-complexity: O(N^3) since we have a triple nested for-loop which each is iterated through N-times.S
// Memory-complexity: O(N*N) since we save a vector of N vectors where each vector is N long.

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm> 
#include <queue>

using namespace std;
const int INF = 1000000000;
int N; //Number of nodes in graph.
int M; //Number of edges.
int Q; //Number of queries
int S; //Starting Node
int from;
int to;
int weight;
int distFrom;
int distTo;
vector<int> p;
vector<vector<int>> d;

//Takes a vector of vectors of size N*N as input. 
//After the algorithm has been run, vector i contains the distances from vector i to every other node, the diagonal will by default be 0.
void floydWarshall(vector<vector<int>> &d){
    //cout << "HEJ" << endl;
    //int n = d.size();
    for(int i=0; i<N; ++i){
            d[i][i] = 0;
    }

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (d[i][k] < INF && d[k][j] < INF){
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (d[j][i] != INF && d[j][j] < 0 && d[k][j] != INF){
                    d[k][i] = -INF;
                }   
            }
        }
    }
}

int main() 
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

while(cin >> N >> M >> Q){
    if(N == 0 && M == 0 && Q == 0){
        break;
    }
    vector<vector<int> > d(N, vector<int>(N, INF));
    //N and Q are only 0 at the terminate row.

    for (int i=0; i < M; i++){
        cin >> from >> to >> weight;
        d[from][to] = min(d[from][to],weight);
    }
    floydWarshall(d);
    for (int i=0; i < Q; i++){
        cin >> distFrom >> distTo;
        int len = d[distFrom][distTo];

        if(len == INF){
            cout << "Impossible" << endl;   
        }
        else if(len == -INF){    
            cout << "-Infinity" << endl;   
        }
        else{  
            cout << len << endl;
        } 
    }
    cout << "\n";
}

return 0;
}