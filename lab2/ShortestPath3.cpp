// Author: Alexander Josefsson
// Liuid: Alejo135
// Problem is: Shortest Path between two edges in a graph usin the Bellman-Ford algortitm
// Time-complexity: The Time-complexity is O(M*N) where M is the edges and N is the vertices. This due to the 
                //algorithm going through every edge number of node times.
// Memory-complexity: O(N) since it saves vectors of length N.
// Note: Can handle edges with postive and negative weights but only where all edges can be traversed all the time.

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
int distTo;
vector<int> distances;
vector<int> p;
vector<int> restoredPath = {}; //Vector containg the restored shortest path betwee 2 nodes.
queue<int> negativeCycles = {}; //A queue for saving which nodes in negative cycles.

struct edge{
    int from, to, weight;
};

vector<edge> edges;

//The function runs the Bellman Ford algoritm on a graph to find the shortest path from a node to every other node.
void bellman_ford(){ 
    distances.assign(N, INF);
    p.assign(N, -1);
    distances[S] = 0;

    //The for loops below go through the edges a totaal of N(number of nodes times). It is divided in two for loops so we see which nodes 
    //are changed in the last step since we know these are in a negative cycle.
    for(int i=0; i<N-1; ++i){
        for(int j=0; j<M; ++j) {
            if(distances[edges[j].from] < INF){
                if(distances[edges[j].to] > distances[edges[j].from] + edges[j].weight){
                    distances[edges[j].to] = max(-INF, distances[edges[j].from] + edges[j].weight); 
                    p[edges[j].to] = edges[j].from;
                }
            }
        }
    }
    for(int i=0; i<M; i++){
        if(distances[edges[i].to] > distances[edges[i].from] + edges[i].weight && (distances[edges[i].from] < INF)){
            negativeCycles.emplace(edges[i].from);
            negativeCycles.emplace(edges[i].to);
            distances[edges[i].from] = -INF;
            distances[edges[i].to] = -INF;
        }
    }
    //Goes through a queue consisting of nodes in negative cycles and sets every node affected by them to -INF.
    while(!negativeCycles.empty()){
        int negative = negativeCycles.front();
        negativeCycles.pop();

        for(int i=0; i<edges.size(); ++i){
            if(negative == edges[i].from && distances[edges[i].to] != -INF){
                distances[edges[i].to] = -INF;
                negativeCycles.emplace(edges[i].to);   
           } 
        }
    }
    edges.clear();
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

while(cin >> N >> M >> Q >> S){
    int from, to, weight;

    if((N+M+Q+S) == 0){break;}

    //N and Q are only 0 at the terminate row.
    for (int i=0; i < M; i++){
        cin >> from >> to >> weight;
        struct edge aEdge = {from, to, weight};
        edges.push_back(aEdge);
    }
    
    bellman_ford();
    for (int i=0; i < Q; i++){
        cin >> distTo;
        int len = distances[distTo];
        if(len == INF){
            cout << "Impossible" << endl;   
        }
        else if(len == -INF){
            cout << "-Infinity" << endl;
        }
        else{      
            cout << len << endl;
            //Code to restore the shortest path
            // restoredPath = restore_path(S,distTo,p);
            // for (int j=0; j < restoredPath.size(); j++){
            //     cout << restoredPath [j] << " ";
            // }
            //cout << "\n";
        } 
    }
    cout << "\n";
}
return 0;
}