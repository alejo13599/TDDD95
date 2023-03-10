// Author: Alexander Josefsson
// Liuid: Alejo135
// Problem is: A standard fenwick tree to calculate the prefix sum, exclusive the last number.
// Time-complexity: O(NlogN)


#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include<cmath>

using namespace std;
vector<long long> fenwicktree;
long long N;
long long Q;
char oper;
long long  update;
long long  delta;
long long  idx;
long long  idx1;
long long  idx2;

//Taking index as an input and returning the sum up to that number.
//summan ska inte behöva ändras tror jag
long long number_sum(long long idx){
    long long summa = 0;
    for(;idx > 0; idx &= idx-1){
        summa += fenwicktree[idx-1];
        
    }
    return summa;
}
long long  number_sum2(long long idx1){
    return number_sum(idx1+1) - number_sum(idx1);
}

//Taking two integer as input. The first represents an index an the secind a number. The function ads the number to every succeding index.
 void add(long long update, long long delta){
    for(; update< N; update|=(update+1)){
        fenwicktree[update] = fenwicktree[update] + delta;

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
for(long long j=0; j<Q; j++){
    cin >> oper;
    //Lite förändringar behöver göras
    if (oper == 'F'){
        cin >> update;
        long long delta;
        if(number_sum2(update) == 1){
            delta = -1;
        }
        else
        {
            delta = 1;
        }
        add(update, delta);


    }
    if (oper == 'C'){
        cin >> idx1 >> idx2;
        //cout << number_sum(idx2+1) << "\n";
        cout << number_sum(idx2+1)-number_sum(idx1) << '\n';
    }
}

return 0;
}