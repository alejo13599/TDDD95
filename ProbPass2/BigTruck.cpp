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
vector<pair<int, int>> edges = {};
vector<vector<pair<int, int>>> adj;
int N; //Number of nodes in graph.
int M; //Number of edges.
int Q; //Number of queries
int S; //Starting Node
int from;
int to;
int weight;
int distTo;
int itemsAt;
int totitems;
vector<int> d;
vector<int> p;
vector<int> itemsTo;
vector<int> restoredPath = {};
vector<int> items;



void dijkstra(int s, vector<int> & d, vector<int> & p){
    //Vektorerna D och P ska även skickas in.
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    itemsTo.assign(n,0);

    vector<bool> u(n, false);
    d[s] = 0;
    itemsTo[0] = items[0];
    using pii = tuple<int, int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> queue;
    queue.push({0, 0, items[0]});
    
    while(!queue.empty()){
        int v = get<1>(queue.top());
        queue.pop();
        if(u[v]){
            continue;
        }
        u[v] = true;

        for(auto edge : adj[v]){
            int to = edge.first;
            int len = edge.second;

            if(d[v] + len < d[to]){
                d[to] = d[v] + len;
                itemsTo[to] = items[to] + itemsTo[v];
                //cout << items[v] << " " << v << endl;
                p[to] = v;
                queue.push({d[to], to, itemsTo[to]});
            }
            else if(d[v] + len == d[to]){
                //cout << itemsTo[to] << " ";
                itemsTo[to] = max(itemsTo[to], items[to] + itemsTo[v]);
                queue.push({d[to], to, itemsTo[to]});
            }
        }
    }
}

int main() 
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

while(cin >> N){
    items.assign(0,N);
    edges.clear();
    for (int i=0; i < N; i++){
        cin >> itemsAt;
        items.push_back(itemsAt);
        //cout << items[i] << " ";
    }
    //cout << endl;
    cin >> M;
    if (M == 0){
        cout << "impossible" << endl;
        continue;
    }
    //cout << M << endl; 
    adj.assign(2*M, vector<pair<int, int>>());
    for (int i=0; i < M; i++){
        cin >> from >> to >> weight;
        //cout << "F: " << from << "T:" << to << "W: " << weight << endl;
        from = from-1;
        to = to-1;
        //cout << "hej" << endl; 
        adj[from].push_back(make_pair(to, weight));
        //cout << "he2" << endl; 
        adj[to].push_back(make_pair(from, weight));
        //cout << "he3" << endl; 
    }


    dijkstra(0, d, p);
    //cout << "hej" << endl; 
    //cout << "TO: " << N-1 << " " << itemsTo[N-1]  << endl;
        int len = d[N-1];
        if(len == INF){
            cout << "impossible" << endl;   
        }
        else{      
            cout << len << " " << itemsTo[N-1] <<  endl;
        } 
}

return 0;
}