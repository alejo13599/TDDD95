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
long idx1;
long idx2;

//Taking index as an input and returning the sum up to that number. Aka caluculating the prefix sum, last index not inclusive.
long long number_sum(long long idx){
    long long summa = 0;
    for(;idx > 0; idx &= idx-1){
        summa += fenwicktree[idx-1];
        
    }
    return summa;
}

//Taking two integer as input. The first represents an index an the secind a number. The function ads the number to every succeding index.
 void add(long long update, long long delta){
    for(; update< N; update|=(update+1)){
        fenwicktree[update] = fenwicktree[update] + delta;

    }
 }
//Range sum operation. (not between 0 and id.)
long long  range_sum(long long idx1, long long idx2){
    return number_sum(idx2+1) - number_sum(idx1);
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
    
    if (oper == 'R'){
        cin >> idx1 >> idx2;
        cout << range_sum(idx1, idx2) << '\n';
    }
}

return 0;
}
