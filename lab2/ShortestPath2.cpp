#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>

using namespace std;
const int INF = 1000000000;
vector<pair<int, int>> edges = {};
vector<vector<tuple<int, int, int, int>>> adj;

//Function for calculating time from one node to another.
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

void dijkstra(int s, vector<int> & d, vector<int> & p){
    //Vektorerna D och P ska även skickas in.
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


int main() 
{
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

ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

while(cin >> N >> M >> Q >> S){
    adj.assign(N, vector<tuple<int, int, int, int>>());
    edges.clear();
    vector<int> d;
    vector<int> p;

    //N and Q are only 0 at the terminate row.
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
        }
    }
    cout << "\n";
}

return 0;
}