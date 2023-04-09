#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;
int upTo;
int queries;
int q;
vector<bool> primeVec;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> upTo >> queries;
    upTo += 1;
    primeVec.assign(upTo, true);
    primeVec[0] = false;
    primeVec[1] = false;
    int numberofPrimes = 0;
    for(long long i=2; i< upTo; i++){
        if(primeVec[i]){
            numberofPrimes += 1;
            for(long long j = i*i; j<= upTo; j+=i){
                primeVec[j] = false;
            }
        }
    }

    cout << numberofPrimes << endl;
    for(int i=0; i<queries; i++){
        cin >> q;
        if(primeVec[q]){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;      
        }
    }
    
return 0;
}