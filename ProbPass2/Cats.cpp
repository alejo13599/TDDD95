// Author: Alexander Josefsson
// Liuid: Alejo135
// Problem is: Minimum spanning tree for a graph.
// Time-complexity: The Union Find part of pf the algoritm has a time complexity of O(N). Sorting in C++ is done in O(NlogN) and
//therefor time-complexity i O(NlogN).
// Memory-complexity: O(N)

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <iomanip>

using namespace std;

unsigned int set1;
unsigned int set2;
unsigned int setind1;
unsigned int setind2;
long int milk;
long int cats;
long int u;
long int v;
long int w;
int cost = 0;
int NumberOfCases = 0;
vector<int> parent;
vector<int> rankvec;
vector<tuple<long int, long int, long int>> edges = {};


//The find, combine, same and DisjointSet function togeter make the union-find problem. Im reusing the code here to search for
//cycles and determine if i should add the edges or not.
//Taking an int as input reoresenting a node and returning the parent to that node.
int find(int index){
    if(index == parent[index]){
        return index;
    }
    return parent[index] = find(parent[index]);
}

//Set the sets of ind1 and ind2 to the same union.3
void combine(int ind1, int ind2){
    setind1 = find(ind1);
    setind2 = find(ind2);
    if(setind1 != setind2){
        if (rankvec[setind1] < rankvec[setind2]){
            parent[setind1] = ind2;
            rankvec[ind2] = rankvec[ind1] + 1;
        }
        else{
            parent[setind2] = ind1;
            rankvec[ind1] = rankvec[ind2] + 1;
        }
    }
}

//Testing wheter to nodes are int same set/union.
bool same(int set1, int set2){
    return find(set1) == find(set2);
}

//Taking the number of Nodes as input and returns 2 intialised vectors. One with the rank of the nodes(is 1 at the start) and one
//with their parent(themselves as they have no parents att the start).
vector<int> DisjointSet(int N){
    rankvec.assign(N,1);
    parent.assign(N,0);

    for(long long int i=0; i<N; i++){
    parent[i] = i;  
    }
    return rankvec, parent;
}

//Takes a vector of tuples as input. The tuple is in the formaat <from edge, to edge, weight>
//Runs the kruskal algortihm and returns a vector of pairs with the edges used. The last pair
//in the vector is reserved for the total cost of the minimum spannining tree.
vector<pair<long int, long int>> Kruskal(vector<tuple<long int, long int, long int>> edges){
    vector<pair<long int, long int>> edgesUsed = {};
    cost = 0;
    sort(edges.begin(), edges.end());
    for(int j=0; j< edges.size(); j++){
        //cout << "HEJ";       
        if (find(get<1>(edges[j])) != find(get<2>(edges[j]))){
            combine(get<1>(edges[j]), get<2>(edges[j]));
            cost = cost + get<0>(edges[j]) +1;
            //cout << get<1>(edges[j]) << " " << get<2>(edges[j]) << endl;
            edgesUsed.push_back(make_pair(get<1>(edges[j]) , get<2>(edges[j])));
        }
    }
    sort(edgesUsed.begin(), edgesUsed.end());
    return edgesUsed;
}
int main() {
//To make the input faster
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
cin >> NumberOfCases;
//cout << "Cases: " << NumberOfCases << endl;
for(int i = 0; i<NumberOfCases; i++){
    cin >> milk >> cats;
    //cout << "Milk:" << milk << "Cats:" << cats << endl;
    vector<tuple<long int, long int, long int>> edges = {};
    rankvec, parent = DisjointSet(milk);

    for(long long int j=0; j<(cats*(cats-1))/2; j++){
        cin >> u >> v >> w;
        edges.push_back(make_tuple(w, min(u, v), max(u,v)));
    }
    vector<pair<long int, long int>> edgesInTree = Kruskal(edges);
    if ((edgesInTree.size() == (cats-1)) && cost < milk){
        cout << "yes " << "\n";
    }
    else{
        cout << "no" << "\n";  
    }
}
return 0;
}