// Author: Alexander Josefsson
// Liuid: Alejo135
// Problem is: A standard fenwick tree to calculate the prefix sum, exclusive the last number.
// Time-complexity: Normally it takes O(N) calculate the sum of of a array but a fenwick tree improves this to 
//O(logN) by representing the numbers in the array as a tree where each node in the tree stores the prefix sum of 
//the sequence up to the index of that node.
// Memory-complexity: O(N) since we store a tree that has the number of nodes as the array has elements.

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include<cmath>

using namespace std;
vector<long> fenwicktree;
long N;
long Q;
char oper;
long update;
long delta;
long idx;

//Taking index as an input and returning the sum up to that number. Aka caluculating the prefix sum, last index not inclusive.
long number_sum(long idx){
    long summa = 0;
    while(idx > 0){
        summa += fenwicktree[idx];
        idx -= idx & (-idx);
    }
    return summa;
}

//Taking two integer as input. The first represents an index an the secind a number. The function ads the number to every succeding index.
 void add(long update, long delta){
    update = update + 1;
    while(update <= N){
        fenwicktree[update] = fenwicktree[update] + delta;
        update += update & (-update);

    }
 }

int main() 
{
//To make the input faster(The algortihm is approximately 75% faster with these 3 lines)
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

cin >> N; //Length of Array
cin >> Q; //Number of operations
N = N+1;
fenwicktree.assign(N,0);

//Reading the input
for(long long int j=0; j<Q; j++){
    cin >> oper;
    
    if (oper == '+'){
        cin >> update;
        cin >> delta;
        add(update, delta);


    }
    if (oper == '?'){
        cin >> idx;
        cout << number_sum(idx) << '\n';
    }
}

return 0;
}
