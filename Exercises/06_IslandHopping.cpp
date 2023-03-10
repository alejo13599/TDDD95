#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <iomanip>

using namespace std;

int NumberOfCases;
int NumberOfIslands;
double x;
double y;
unsigned int set1;
unsigned int set2;
unsigned int setind1;
unsigned int setind2;
char oper;
vector<int> parent;
vector<int> rankvec;
vector<pair<double,double>> IslandVector = {};
vector<tuple<double, int, int>> edges = {};

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


int main() {
//To make the input faster
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

cin >> NumberOfCases;

for(long long int i=0; i<NumberOfCases; i++){
    double total = 0;
    vector<pair<double,double>> IslandVector = {};
    vector<tuple<double, int, int>> edges = {};

    cin >> NumberOfIslands;
    rankvec, parent = DisjointSet(NumberOfIslands);
    for(long long int j=0; j<NumberOfIslands; j++){
        cin >> x >> y;
        IslandVector.push_back(make_pair(x,y));
    }

    for(int m=0; m< IslandVector.size(); m++){
        for(int n=m+1; n< IslandVector.size(); n++){
            double distx = IslandVector[m].first-IslandVector[n].first;
            double disty = IslandVector[m].second-IslandVector[n].second;
            double dist = sqrt(distx*distx + disty*disty);
            edges.push_back(make_tuple(dist, m, n));        
        }
    }
    sort(edges.begin(), edges.end());
    //Starting Kruskal
    
    for(int j=0; j<edges.size(); j++){

        if (find(get<1>(edges[j])) != find(get<2>(edges[j]))){
            combine(get<1>(edges[j]), get<2>(edges[j]));
            total = total + get<0>(edges[j]);
        }
    }
    cout << setprecision(9) << total << endl; 
}
return 0;
}