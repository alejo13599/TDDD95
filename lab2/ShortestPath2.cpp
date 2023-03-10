// Author: Alexander Josefsson
// Liuid: Alejo135
// Problem is: Shortest Path between two edges in a graph where edges only can be traversed at certain times. Shortest in this task
//is shortest time between nodes.
// Time-complexity: The Time-complexity is O(mlogn) where m is the edges and n is the vertices.
// Memory-complexity: O(N) since it saves vectors of length N.
// Note: Can only handle edges with postive weights.

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm> 
#include <queue>

using namespace std;
const int INF = 1000000000;
vector<vector<tuple<int, int, int, int>>> adj;
vector<int> d;
vector<int> p;

int N; //Number of nodes in graph.
int M; //Number of edges.
int Q; //Number of queries
int S; //Starting Node
int from;
int to;
int weight;
int distTo;
int t0;
int openEvery;
int traverseTime;
vector<int> restoredPath = {};

//Function for calculating the wiat time at a specifc node. The function returns the waittime.
//Inputs:
//t: the time arriving att the node.
//t0: The time the edge opens for traversing the first time.
//P: The length of interval in which the the edge is closed for traversing.
int calcWaitTime(int t, int t0, int P){
    if(t <= t0){
        return t0-t;
    }
    else if(P == 0){
        return INF;
    }
    else if((t-t0)%P){
        return P -(t-t0)%P;

    }

    return 0;
}
// Function for the djikstra algortihm.
//Inputs:
//s: The starting node. Djikstra calculate the distance from this node to every other node.
//d: Vector with same length as the number of nodes. At the end of the algorithm the vecor should contain the distance from the choosen starting
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
            int to = get<0>(edge);
            int len = get<1>(edge);
            int waitTime = calcWaitTime(d[v], get<2>(edge), get<3>(edge));

            if(d[v] + waitTime + len < d[to]){
                d[to] = d[v] + waitTime + len;
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

//N and Q are only 0 at the terminate row.
while(cin >> N >> M >> Q >> S){
    adj.assign(N, vector<tuple<int, int, int, int>>());
    
    if((N == 0) && (Q == 0)){
        break;
    }

    for (int i=0; i < M; i++){
        cin >> from >> to >> t0 >> openEvery >> traverseTime;
        adj[from].push_back(make_tuple(to, traverseTime, t0, openEvery));
    }


    dijkstra(S, d, p);
    for (int i=0; i < Q; i++){
        cin >> distTo;
        int len = d[distTo];
        if(len == INF){
            cout << "Impossible" << endl;   
        }
        else{
            cout << len << endl;
            //Code to restore the shortest path
            // restoredPath = restore_path(S,distTo,p);
            // for (int j=0; j < restoredPath.size(); j++){
            // cout << restoredPath [j] << " ";
            //}
        //cout << "\n";
        }
    }
    cout << "\n";
}

return 0;
}