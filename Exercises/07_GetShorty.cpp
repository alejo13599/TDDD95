#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>

using namespace std;
vector<vector<pair<int, long double>>> adj;

void dijkstra(int s, vector<long double> & d, vector<int> & p){
    //Vektorerna D och P ska även skickas in.
    int n = adj.size();
    d.assign(n, 0);
    vector<bool> visit(n, false);
    d[0] = 1;
    using pii = pair<long double, int>;
    priority_queue<pii, vector<pii>> queue;
    queue.push({1.0, 0});

    while(!queue.empty()){
        int v = queue.top().second;
        long double d_v = queue.top().first;
        queue.pop();
        if(!visit[v]){
            visit[v] = true;
            
            for(auto edge : adj[v]){
                int to = edge.first;
                long double f = edge.second;
                //cout << f << endl;
                if(!visit[to]){
                    if(d[to] < d_v*f){
                        d[to] = d_v*f;
                    }
                queue.push({d_v*f, to});
                }
            }   
        }
    }
}

int main() 
{
int N; //Number of nodes in graph.
int M; //Number of edges.
int from;
int to;
long double weight;

ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

while(cin >> N >> M){
    if((N == 0) && (M == 0)){
        break;
    }

    adj.assign(N, vector<pair<int, long double>>());

    vector<long double> d;
    vector<int> p;
    //N and Q are only 0 at the terminate row.

    for (int i=0; i < M; i++){
        cin >> from >> to >> weight;
        //cout << from << " " << " " << to << " " << weight << "\n";
        adj[from].push_back(make_pair(to, weight));
        adj[to].push_back(make_pair(from, weight));
    }

    dijkstra(0, d, p);

    //Ska alltid till den sista noden.
    //cout << d[0] << " " << d[1] << " " << d[2] << "\n";
    long double len = d[N-1];

    cout << fixed << setprecision(4) << len << "\n";

}

return 0;
}