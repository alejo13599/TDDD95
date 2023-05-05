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
      return (point1.x-point2.x)*(point1.x-point2.x)+(point1.y-point2.y)*(point1.y-point2.y);
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
int checkdirection(Pointclass::point a, Pointclass::point b, Pointclass::point c){
    int direction;
    vector<Pointclass::point> checkdirectionvector;
    checkdirectionvector.push_back(a);
    checkdirectionvector.push_back(b);
    checkdirectionvector.push_back(c);
    if(checkarea(checkdirectionvector) < 0){
        direction = -1;
    }else{
        direction = 1;
    }
    return direction;
}
bool checkonline(Pointclass::point a, Pointclass::point b, Pointclass::point c){
  Pointclass inst;
  //cout << inst.point_distance(a,c) << " " << inst.point_distance(c,b) << " " << inst.point_distance(a,b) << "\n";
  if(inst.point_distance(a,c)+inst.point_distance(c,b) == inst.point_distance(a,b)){
    return true;
  }
  else{
    return false;
  }

}



int main() 
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int NumberOfVertices, NumberOfPoints;
double x,y;
Pointclass::point testpoint = {0,0};
cin >> NumberOfVertices;
vector<Pointclass::point> Pointvec;
Pointclass inst;
bool online = false;
while(NumberOfVertices){
    double area = 0;
    Pointvec = {};
    for(int i=0; i<NumberOfVertices; i++){
        cin >> x >> y;
        Pointvec.push_back({x,y});
    }

    cin >> NumberOfPoints;
    for(int j=0; j<NumberOfPoints; j++){
        online = false;
        int intersections = 0;
        cin >> testpoint.x >> testpoint.y;        
        for(int i=0; i <NumberOfVertices-1; i++){
            //cout << "line " << i << endl;
            int direction1 = checkdirection(Pointvec[i], Pointvec[i+1], testpoint);
            int direction2 = checkdirection(Pointvec[i], Pointvec[i+1], {40000, testpoint.y});
            int direction3 = checkdirection(testpoint, {40000, testpoint.y}, Pointvec[i]);
            int direction4 = checkdirection(testpoint, {40000, testpoint.y}, Pointvec[i+1]);
            if(checkonline(Pointvec[i], Pointvec[i+1], testpoint)){
              online = true;

            }
            if(direction1 != direction2 && direction3 != direction4){
                intersections += 1;
                //cout << "intersection " << i+1 << "\n" ;
            }


        }
        int direction1 = checkdirection(Pointvec[NumberOfVertices-1], Pointvec[0], testpoint);
        int direction2 = checkdirection(Pointvec[NumberOfVertices-1], Pointvec[0], {40000, testpoint.y});
        int direction3 = checkdirection(testpoint, {40000, testpoint.y}, Pointvec[NumberOfVertices-1]);
        int direction4 = checkdirection(testpoint, {40000, testpoint.y}, Pointvec[0]);
        if(checkonline(Pointvec[NumberOfVertices-1], Pointvec[0], testpoint)){
          online = true;
        }
        if(online){
          cout << "on\n";
          continue;  
        }
        if(direction1 != direction2 && direction3 != direction4){    
            intersections += 1;
           //cout << "intersection " << NumberOfVertices << "\n" ;
        }
        if(intersections%2 == 1){
            cout << "in\n";
        }
        else{
            cout << "out\n";
        }        
    }
    cin >> NumberOfVertices;
}
return 0;
}