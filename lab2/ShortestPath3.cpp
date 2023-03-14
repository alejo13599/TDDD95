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

struct edge{
    int a, b, cost;

};

vector<edge> edges;

void bellman_ford(){ 
    d.assign(N, INF);
    p.assign(N, - 1);
    d[S] = 0;
    int x;
    for(int i=0; i<N; ++i){
        x = -1;
        for(int j=0; j<M; ++j) {
            //cout << edges[j].a << " " << edges[j].b << " " << edges[j].cost << endl;
            if(d[edges[j].a] < INF){
                if(d[edges[j].b] > d[edges[j].a] + edges[j].cost){
                    d[edges[j].b] = max(-INF, d[edges[j].a] + edges[j].cost); 
                    p[edges[j].b] = edges[j].a;
                    x = edges[j].b;
                }
            }
        }

    }

    if(x == -1){

    }
    else{
        int y = x;
        for(int i=0; i<N; ++i){
            y = p[y];
        }
        vector<int> path;
        for(int cur =y;; cur=p[cur]){
            path.push_back(cur);
            if(cur == y && path.size() > 1){
                break;
            }

        }
        reverse(path.begin(),path.end());
        for (size_t i=0; i<path.size(); ++i){
            d[i] = -INF;
            //cout << path[i] << ' ';
        }

    }
    edges.clear();
}

int main() 
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
cin >> N >> M >> Q >> S;

while((N != 0) && (Q != 0)){
    //N and Q are only 0 at the terminate row.
    for (int i=0; i < M; i++){
        cin >> from >> to >> weight;
        struct edge aEdge = {from, to, weight};
        edges.push_back(aEdge);
    }

    bellman_ford();
    for (int i=0; i < Q; i++){
        cin >> distTo;
        int len = d[distTo];
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
            // cout << restoredPath [j] << " ";
            // }
        } 
    }
    cout << "\n";
    cin >> N >> M >> Q >> S;
}
return 0;
}