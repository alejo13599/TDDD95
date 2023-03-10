// Author: Alexander Josefsson
// Liuid: Alejo135
// Problem is: Shortest Path between two edges in a graph.
// Time-complexity: The Time-complexity is O(mlogn) where m is the edges and n is the vertices.
// Memory-complexity: O(N) since it saves vectors of length N.
// Note: Can only handle edges with postive weights where all edges can be traversed all the time.


#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm> 
#include <queue>

using namespace std;
const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;
int N; //Number of nodes in graph.
int M; //Number of edges.
int Q; //Number of queries
int S; //Starting Node
int from;
int to;
int weight;
int distTo;
vector<int> d;
vector<int> p;
vector<int> restoredPath = {};

// Function for the djikstra algortihm.
//Inputs:
//s: The starting node. Djikstra calculate the distance from this node to every other node.
//d: Vector with same length as the number of nodes. At the end of the algorithm the vector should contain the distance from the choosen starting
//node to node i in the vector. If there is no route the value will be INF.
//p: At the end of the algorithm the vector should contain at index i, the node which is the previous in the shortest path including that node.
void dijkstra(int s, vector<int> & d, vector<int> & p){

    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    vector<bool> u(n, false);
    d[s] = 0;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> queue;
    queue.push({0, s});

    while(!queue.empty()){
        int v = queue.top().second;
        int d_v = queue.top().first;
        queue.pop();

        if(d_v != d[v]){
            continue;
        }

        for(auto edge : adj[v]){
            int to = edge.first;
            int len = edge.second;

            if(d[v] + len < d[to]){
                d[to] = d[v] + len;
                p[to] = v;
                queue.push({d[to], to});
            }
        }
    }
}

//Function to restore the shortest path. Takes 3 inputs.
//int s: The starting node
//int t The goal node
//vector<int> const& p.
//Returns a vector of ints containing the shortest path from s to t. 
vector<int> restore_path(int s, int t, vector<int> const& p){
    vector<int> path;
    for (int v = t; v != s; v=p[v]){
        path.push_back(v);
    }
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
}

int main() 
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
cin >> N >> M >> Q >> S;

while((N != 0) && (Q != 0)){
    //N and Q are only 0 at the terminate row.
    adj.assign(N, vector<pair<int, int>>());
    for (int i=0; i < M; i++){
        cin >> from >> to >> weight;
        adj[from].push_back(make_pair(to, weight));
    }

    dijkstra(S, d, p);
    for (int i=0; i < Q; i++){
        cin >> distTo;
        int len = d[distTo];
        if(len == INF){
            cout << "impossible" << endl;   
        }
        else{      
            cout << len << endl;
            //Code to restore the shortest path
            // restoredPath = restore_path(S,distTo,p);
            // for (int j=0; j < restoredPath.size(); j++){
            // cout << restoredPath [j] << " ";
            // }
        } 
    // cout << "\n";
    }
    cout << "\n";
    cin >> N >> M >> Q >> S;
}
return 0;
}