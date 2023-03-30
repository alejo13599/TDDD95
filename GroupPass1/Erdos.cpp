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
#include <map>
#include <string>
#include <sstream>

using namespace std;
const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;
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
void dijkstra(int s, vector<int> & d, vector<int> & p, int counter){

    int n = counter+1;    //nr nodes
    d.assign(n, INF);
    p.assign(n, -1);
    vector<bool> u(n, false);
    d[s] = 0;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> queue;
    queue.push({0, s});
    //cout << "n: " << n << endl;
    while(!queue.empty()){
        int v = queue.top().second;
        int d_v = queue.top().first;
        queue.pop();
        //cout << "adjsize" << adj[v].size() << endl;
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
    //cout << d[1] << endl;
}

int main() 
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
string readLine{};
int counter{};
map<string, int> nodeNames{};
vector<string> authors;
string currNode;
adj.assign(2000000, vector<pair<int, int>>());
while(getline(cin, readLine)){
    // check if first name in map
    stringstream ss1(readLine);
    ss1 >> currNode;
    authors.push_back(currNode);
    //cout << "currNode" << endl; 
    vector<string> coAuthors;
    if (!(nodeNames.find(currNode) != nodeNames.end()))
        {
            // nyckel existerar inte => lägg till
            nodeNames.insert({currNode, counter});
            counter += 1;

        } 

    string adjNode{};
    //adj.assign(2000, vector<pair<int, int>>());
    //cout << currNode;
    while(ss1 >> adjNode && adjNode != "\n") {
        //cout << adjNode << endl;
        coAuthors.push_back(adjNode);
        if (!(nodeNames.find(adjNode) != nodeNames.end()))
        {
            // nyckel existerar inte => lägg till
            nodeNames.insert({adjNode, counter});
            counter += 1;
        }


    }
    //cout << coAuthors.size();
    for (int i=0; i<coAuthors.size(); i++){
        //cout << "coauth" << nodeNames.find(coAuthors[i])->second << endl;
        int index = nodeNames.find(currNode)->second;
        int toNode = nodeNames.find(coAuthors[i])->second;
        //cout << index << " " << toNode << "\n";
        adj[index].push_back(make_pair(toNode, 1));
        adj[toNode].push_back(make_pair(index, 1));
        // cout << nodeNames.find(coAuthors[i])->first;
    }

 



    // cout << "\n";
    }

    // vector<vector<pair<int, int>>> adj;

    // cout << "printar: " << endl;
    // for(auto edge : adj[0])
    // {
    //     //for (auto edge2 : edge)
    //     //{
    //         cout << "f" << edge.first << endl;
    //         cout << "s" << edge.second << endl;
    //     //}
    // }
    //cout << "adj " << adj[0].size();



    dijkstra(0, d, p, counter);
    //cout << d[4];
    for (auto author : authors){
        int len = d[nodeNames.find(author)->second];
        if(len == INF){
            cout << author << " no-connection" << endl;   
        }
        else{      
            cout << author << " " << d[nodeNames.find(author)->second] << endl;
        } 
}
return 0;
}