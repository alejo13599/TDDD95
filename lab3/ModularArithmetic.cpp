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



long long gcdfunc(long long a, long long b) {
    //std::cout << "Test2: " << a << " / " << b << std::endl;
   if (b == 0){
   return a;
   }

   return gcdfunc(b, a % b);
}
long long modulo(long long number, long long mod){
    if(number < 0){
        return number+mod;
    }
    else{
        return number%mod;
    }

}
void exeuclid(long long a, long long b, long long *x ,long long *y) {
    
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return;
    }
    long long x1, y1; 
    exeuclid(modulo(b,a), a, &x1, &y1);
 
    *x = y1 - (b/a) * x1;
    *y = x1;
 
}

int main() 
{
long long NumberOfCases, Mod;
long long number1, number2;
char oper;
std::ios_base::sync_with_stdio(false);
std::cin.tie(NULL);
std::cout.tie(NULL);
std::cin >> Mod >> NumberOfCases;
while(Mod != 0 && NumberOfCases != 0){
    for(long long i=0; i<NumberOfCases; i++)
    {
        std::cin >> number1 >> oper >> number2;
        if(oper == '+'){
            std::cout << modulo(number1+number2, Mod) << std::endl; 
        }
        else if(oper == '-'){
            std::cout << modulo(number1-number2, Mod) << std::endl;         
        }
        else if(oper == '*'){
            std::cout << modulo(number1*number2, Mod) << std::endl;         
        }
        else if(oper == '/'){
            
            if(gcdfunc(number2, Mod) != 1){
                std::cout << -1 << std::endl;    
            }
            else{
                //long long x,y; 
                long long a = 1;
                long long b = 0;
                exeuclid(number2, Mod, &a, &b);
                //std::cout << "a: " << a << std::endl;
                std::cout << modulo(number1*modulo(a, Mod), Mod)  << std::endl;   
                //std::cout << y*(y^(-1)) + Mod*x << std::endl;  
            }
              
        }
    //     std::cout << frac3.num << " / " << frac3.denom << std::endl;
    }
    std::cin >> Mod >> NumberOfCases;
}
return 0;
}