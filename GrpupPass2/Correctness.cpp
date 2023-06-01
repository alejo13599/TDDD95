// Author: Alexander Josefsson
// Liuid: Alejo135
// Problem is:
// Time-complexity: 
// Memory-complexity:
// Note: 
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <numeric>

long long power(long long base, long long exp) {
    // if(!exp){
    //     return 1;
    // }
    long long currentval = 1;
    std::vector<long long int> integer(32,0);
    integer[0] = base;
    for(int i=1; i<32; ++i){
        integer[i] = (integer[i-1]*integer[i-1]) % 10000;
    }
    //std::cout << "printar integer:" << std::endl;
    for (long long int elem : integer){
        //std::cout << elem << std::endl;
    }
    for(int i=0; i<32; ++i){
        if((exp>>i & 1) == 1){
            currentval *= integer[i];
            currentval %= 10000;
        }
    }
    return currentval;
}

int main() 
{
long long NumberOfCases, Mod;
long long number1, number2;
char oper;
std::ios_base::sync_with_stdio(false);
std::cin.tie(NULL);
std::cout.tie(NULL);
while(std::cin >> number1 >> oper >> number2){
        if(oper == '+'){
            std::cout << (number1+number2)%10000 << std::endl; 
        }
        else if(oper == '*'){
            number1 = number1%10000;
            std::cout << (number1*number2)%10000 << std::endl;           
        }
        else if(oper == '^'){
            std::cout << power(number1,number2) << std::endl;          
        }

}
return 0;
}