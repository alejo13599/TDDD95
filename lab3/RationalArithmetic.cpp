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

//using namespace std;
class Arithmetic{

    public:
    struct Frac{
        long long num, denom;
        Frac(long long _num, long long _denom) : num(_num), denom(_denom) {}

        Frac operator+(const Frac &other){
            Arithmetic inst;
            Arithmetic::Frac newfrac = Frac(num*other.denom + denom*other.num, denom*other.denom);
            newfrac = inst.normal(newfrac);
            return newfrac;
        }

        Frac operator-(const Frac &other){
            Arithmetic inst;
            Arithmetic::Frac newfrac = Frac(num*other.denom - denom*other.num, denom*other.denom);
            newfrac = inst.normal(newfrac);
            return newfrac;
        }

        Frac operator*(const Frac &other){
            Arithmetic inst;
            Arithmetic::Frac newfrac = Frac(num*other.num, denom*other.denom);
            newfrac = inst.normal(newfrac);
            return newfrac;
        }

        Frac operator/(const Frac &other){
            Arithmetic inst;
            Arithmetic::Frac newfrac =  Frac(num*other.denom, denom*other.num);
            newfrac = inst.normal(newfrac);
            return newfrac;
        }
        
    };
    private:
    Frac normal(Frac newfrac){
            //std::cout << "Test: " << newfrac.num << " / " << newfrac.denom << std::endl;
            long long gcdval = gcdfunc(llabs(newfrac.num), llabs(newfrac.denom));
            //std::cout << "GCD: " << gcdval << std::endl;
            //std::cout << "Test: " << newfrac.num << " / " << newfrac.denom << std::endl;
            newfrac = Frac(newfrac.num/gcdval,newfrac.denom/gcdval);
            // if(newfrac.num  == newfrac.denom){
            //    newfrac.num = 
            // }
            if(newfrac.denom < 0){
                newfrac.num = -newfrac.num;
                newfrac.denom = -newfrac.denom;
            }

            return Frac(newfrac);
    }
};

int main() 
{
long long NumberOfCases;
long long frac1num, frac1denom, frac2num, frac2denom;
char oper;
std::ios_base::sync_with_stdio(false);
std::cin.tie(NULL);
std::cout.tie(NULL);
std::cin >> NumberOfCases;
for(long long i=0; i<NumberOfCases; i++)
{
    std::cin >> frac1num >> frac1denom >> oper >> frac2num >> frac2denom;
    Arithmetic::Frac frac1 = {frac1num, frac1denom};
    Arithmetic::Frac frac2 = {frac2num, frac2denom};
    Arithmetic::Frac frac3 = {0, 0};
    std::cout << std::fixed;
    std::cout << std::setprecision(0);
    if(oper == '+'){
        frac3 = frac1 + frac2;   
    }
    else if(oper == '-'){
        frac3 = frac1 - frac2;         
    }
    else if(oper == '*'){
        frac3 = frac1 * frac2;         
    }
    else if(oper == '/'){
        frac3 = frac1 / frac2; 
    }
    std::cout << frac3.num << " / " << frac3.denom << std::endl;
}
return 0;
}