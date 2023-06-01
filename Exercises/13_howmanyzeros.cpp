#include <iostream>
#include <iomanip>
#include <algorithm> 
#include <stdio.h>

using namespace std;
long int Lower, Upper;

long int zeros(long int upTo){
    long int total = 0;
    long int i = 1;
    while(true){
        long int b = upTo/i;
        long int c = upTo%i;

        long int a = b/10;
        b = b%10;

        if(a == 0){return total;}

        if(b == 0){
            total += (a - 1) * i + c + 1;
        }
        else{
                total += a * i;
        }
    i *= 10;
    }
}

int main() {
    cin >> Lower >> Upper;
    while((Lower != -1) && (Upper != -1)){
        if(Lower == 0){
            long int z = zeros(Upper)+1;
            //printf("%lu\n", z);
            cout << z << "\n";
        }
        else{
            //printf("%lu\n", zeros(Upper)-zeros(Lower-1)); 
            cout << zeros(Upper)-zeros(Lower-1) << "\n";
        }
        cin >> Lower >> Upper;
    }

return 0;
}