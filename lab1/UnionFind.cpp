// Author: Alexander Josefsson
// Liuid: Alejo135
// Problem is: The Union-Find problem
// Time-complexity: Due to search-path compression the time-complexity for find, combine and same is almost constan
//The function disjoint_set has a time-complexity of O(N) due to iterating over every element once.
// Memory-complexity O(N) since we save vectors with length N for borh rank and parents in the memory.

#include <iostream>
#include <vector>
using namespace std;

int AntalElement;
int AntalOper;
unsigned int set1;
unsigned int set2;
unsigned int setind1;
unsigned int setind2;
char oper;
vector<int> parent;
vector<int> rankvec;

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

cin >> AntalElement >> AntalOper;
rankvec, parent = DisjointSet(AntalElement);

for(long long int i=0; i<AntalOper; i++){
    cin >> oper;

    //Are they union?
    if (oper == '?'){
        cin >> set1 >> set2;
        if(same(set1, set2)){
            cout << "yes" << '\n';
        }
        else{
            cout << "no" << '\n';
        }
    }
    //Combine indices to union
    if (oper == '='){
        //cout << "yes=" << '\n';
        cin >> set1 >> set2;
        combine(set1, set2);
    }
}
return 0;
}