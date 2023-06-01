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
double checkarea(vector<Pointclass::point> Pointvec){
  Pointclass inst;
  double area = 0;
  for(int i=0; i<Pointvec.size()-1; i++){
      area += inst.crossproduct(Pointvec[i],Pointvec[i+1]);
  }
  area += inst.crossproduct(Pointvec[Pointvec.size()-1],Pointvec[0]);
  area = area/2;
  return area;
}

int main() 
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int NumberOfVertices;
double x,y;
cin >> NumberOfVertices;
vector<Pointclass::point> Pointvec;
while(NumberOfVertices){
  Pointvec = {};
  for(int i=0; i<NumberOfVertices; i++){
      cin >> x >> y;
      Pointvec.push_back({x,y});
  }
    double area = checkarea(Pointvec);
    cout << fixed;
    if(area < 0){
        cout << "CW " << setprecision(1) << -area << "\n";
    }
    else{
          cout << "CCW " << setprecision(1) << area << "\n";      
    }
    cin >> NumberOfVertices;
}

return 0;
}