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


using namespace std;
class Pointclass{
public:
  struct point {
    double x, y;

    // constructor
    point(double _x, double _y) : x(_x), y(_y) {}

    // add and subtract vectors
    point operator+(const point &other) const {
      return point(x + other.x, y + other.y);
    }

    point operator-(const point &other) const {
      return point(x - other.x, y - other.y);
    }

    point operator*(double K) const { //Scalar multiplication
      return point(K*x, K*y);
    }

    point operator/(double K) const { //Scalar division
      return point(x/K, y/K);
    }

  };
  double dotproduct(point &point1, point &point2){
      return point1.x*point2.x + point1.y*point2.y;
    }
  double point_distance(point &point1, point &point2){
      return sqrt((point1.x-point2.x)*(point1.x-point2.x)+(point1.y-point2.y)*(point1.y-point2.y));
  }
  double crossproduct(point &point1, point &point2){
      return point1.x*point2.y - point1.y*point2.x;
    }
  
};

int main() 
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
Pointclass::point point1 = {2,2};
Pointclass::point point2 = {1,1};

Pointclass::point a = point1+point2;
Pointclass::point b = point1-point2;
Pointclass::point c = point1*5;
Pointclass::point d = point2/2;
Pointclass inst;
cout << a.x << " " << a.y << "\n";
cout << b.x << " " << b.y << "\n";
cout << c.x << " " << c.y << "\n";
cout << d.x << " " << d.y << "\n";
cout << inst.dotproduct(point1, point2) << endl;
cout << inst.point_distance(point1, point2) << endl;

return 0;
}