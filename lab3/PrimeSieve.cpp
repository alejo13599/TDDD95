// Author: Alexander Josefsson
// Liuid: Alejo135
// Problem is: FInding the number of primes up to a number n.
// Time-complexity:  Sieve of Eratosthenes has a timecomplexity of O(n*log(log(n))).
// Memory-complexity: O(n) due to saving if every number up to n is a prime or not.

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
int upTo;
int queries;
int q;
vector<bool> primeVec;
//Counting the number of primes up to the number n. Using sieve of Eratosthenes.
int countPrimes(int n){
    int count = 0;
    primeVec.assign(n, true);
    primeVec[0,1] = false;
    for(long long i=2; i< n; i++){
        if(primeVec[i]){
            count += 1;
            for(long long j = i*i; j<= n; j+=i){
                primeVec[j] = false;
            }
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> upTo >> queries;
    cout << countPrimes(upTo+1) <<  '\n';
    for(int i=0; i<queries; i++){
        cin >> q;
        if(primeVec[q]){
            cout << 1 << '\n';
        }
        else{
            cout << 0 << '\n';    
        }
    }
    
return 0;
}