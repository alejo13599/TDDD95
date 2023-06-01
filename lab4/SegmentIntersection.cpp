// Author: Alexander Josefsson
// Liuid: Alejo135
// Problem is: Checking wheter two given lines intersect and where they intersect.
// Time-complexity: O(N) since it goes through the points once.
// Memory-complexity:
// Note: 
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;
double delta;
bool online = false;
class Pointclass{
public:
  struct point {
    double x, y;

    point(double _x, double _y) : x(_x), y(_y) {}

    // add and subtract vectors
    point operator+(const point &other) const { //Addition
      return point(x + other.x, y + other.y);
    }
    point operator-(const point &other) const { //Subtraction
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
  // Computes the distance between two points.
  double point_distance(point &point1, point &point2){
      return (point1.x-point2.x)*(point1.x-point2.x)+(point1.y-point2.y)*(point1.y-point2.y);
  }
  //Computes the 2-dimensional cross product(detrimnant) of two points.
  double crossproduct(point &point1, point &point2){
      return point1.x*point2.y - point1.y*point2.x;
    }
};
//Takes of vector of points as input and computes the area using the crossproduct, then returns the area.
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
//Takes 3 points as input. Calculate wheter they are colinear, clockwise or counterclockwise. Returns a int depending on which case it is.
int checkdirection(Pointclass::point a, Pointclass::point b, Pointclass::point c){
    int direction;
    vector<Pointclass::point> checkdirectionvector;
    checkdirectionvector.push_back(a);
    checkdirectionvector.push_back(b);
    checkdirectionvector.push_back(c);
    if(checkarea(checkdirectionvector) < 0){ //Counter Clockwise
        direction = -1;
    }else if(checkarea(checkdirectionvector) == 0) { //Colinear
        direction = 0;
    }
    else{ //Clockwise
        direction = 1;
    }
    return direction;
}
//Takes 4 points as input. a and b are start and end of the first line, c and d are start and end of the second line. Calculates where the two lines
//intersect and returns the coordinates as a point.
Pointclass::point findintersection(Pointclass::point a, Pointclass::point b, Pointclass::point c, Pointclass::point d){
  double eq1 = b.y - a.y;
  double eq2 = a.x - b.x;
  double eq3 = eq1*(a.x) + eq2*(a.y);

  double eq4 = d.y - c.y;
  double eq5 = c.x - d.x;
  double eq6 = eq4*(c.x) + eq5*(c.y);

  double det = eq1*eq5 - eq4*eq2;

  double coord_x = (eq5*eq3 - eq2*eq6)/det;
  double coord_y = (eq1*eq6 - eq4*eq3)/det;
  return {coord_x,coord_y};

}
//Given 3 points. Checks wheter b lies on the line between a and c
bool checkonline(Pointclass::point a, Pointclass::point b, Pointclass::point c){
  if(b.x <= max(a.x, c.x) && b.x >= min(a.x, c.x) && b.y <= max(a.y, c.y) && b.y >= min(a.y, c.y)){
    return true;
  }
  else{return false;}
}
double checksign(double NumberToCheck){
  if(abs(NumberToCheck) <= delta){
    NumberToCheck = abs(NumberToCheck);
  }
  cout << fixed << setprecision(2);
  return NumberToCheck;
}
//If the lines intersect as a segment. Makes sure the lowest x-point is print first.
void findleftandright(Pointclass::point a, Pointclass::point b){
  if(a.x == b.x && a.y == b.y){
    cout << a.x << " " << a.y << endl;
    return; 
  }
  if(a.x < b.x || ((a.x == b.x) && (a.y < b.y))){
    cout << a.x << " " << a.y << " " << b.x << " " << b.y << endl;
  }
  else{
    cout << b.x << " " << b.y << " " << a.x << " " << a.y << endl;         
  }
}
//Checks if the lines intersect. Push the points where it intersect into a vector. If there is more one element in the vector, the lines intersect as a segment.
int checkintersection(Pointclass::point a, Pointclass::point b, Pointclass::point c, Pointclass::point d){
    vector<Pointclass::point> Pointvec = {};
    int intersect = 0;
    int direction1 = checkdirection(a, b, c);
    int direction2 = checkdirection(a, b, d);
    int direction3 = checkdirection(c, d, a);
    int direction4 = checkdirection(c, d, b);

    if(direction1 != direction2 && direction3 != direction4){
        intersect = 1;
        return intersect;
    }
    Pointclass::point minpoint={0,0}, maxpoint={0,0};
    if (direction1 == 0 && checkonline(a, c, b)){
      Pointvec.push_back({c.x,c.y});
      online = true;
    }
    if (direction2 == 0 && checkonline(a, d, b)){
      Pointvec.push_back({d.x,d.y});
      online = true;
    } 
    if (direction3 == 0 && checkonline(c, a, d)){
      Pointvec.push_back({a.x,a.y});
      online = true;
    }
    if (direction4 == 0 && checkonline(c, b, d)){ 
      Pointvec.push_back({b.x,b.y});
      online = true;
    }
    if(online){
      if(Pointvec.size() == 2){
        findleftandright(Pointvec[0], Pointvec[1]);
      }
      if(Pointvec.size() == 3){
        Pointclass inst;
        double longestdist = inst.point_distance(Pointvec[0], Pointvec[1]);
        minpoint={Pointvec[0]}, maxpoint={Pointvec[1]};
        if(longestdist < inst.point_distance(Pointvec[0], Pointvec[2])){
            longestdist = inst.point_distance(Pointvec[0], Pointvec[2]);
            minpoint={Pointvec[0]}, maxpoint={Pointvec[2]};
        }   
        if(longestdist < inst.point_distance(Pointvec[1], Pointvec[2])){
            longestdist = inst.point_distance(Pointvec[1], Pointvec[2]);
            minpoint={Pointvec[1]}, maxpoint={Pointvec[2]};
        }
        findleftandright(minpoint, maxpoint);                      
      }

      if(Pointvec.size() == 4){ 
        Pointclass inst;
        double longestdist = inst.point_distance(Pointvec[0], Pointvec[1]);
        minpoint={Pointvec[0]}, maxpoint={Pointvec[1]};
        if(longestdist < inst.point_distance(Pointvec[0], Pointvec[2])){
            longestdist = inst.point_distance(Pointvec[0], Pointvec[2]);
            minpoint={Pointvec[0]}, maxpoint={Pointvec[2]};
        }
        if(longestdist < inst.point_distance(Pointvec[0], Pointvec[3])){
            longestdist = inst.point_distance(Pointvec[0], Pointvec[3]);
            minpoint={Pointvec[0]}, maxpoint={Pointvec[3]};
        }   
        if(longestdist < inst.point_distance(Pointvec[1], Pointvec[2])){
            longestdist = inst.point_distance(Pointvec[1], Pointvec[2]);
            minpoint={Pointvec[1]}, maxpoint={Pointvec[2]};
        }       
        if(longestdist < inst.point_distance(Pointvec[1], Pointvec[3])){
            longestdist = inst.point_distance(Pointvec[1], Pointvec[3]);
            minpoint={Pointvec[1]}, maxpoint={Pointvec[3]};
        }
        if(longestdist < inst.point_distance(Pointvec[2], Pointvec[3])){
            longestdist = inst.point_distance(Pointvec[2], Pointvec[3]);
            minpoint={Pointvec[2]}, maxpoint={Pointvec[3]};
        }
        findleftandright(minpoint, maxpoint);          
      }
      return intersect;
    }
    intersect = -1;
    return intersect;
}

int main() 
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int NumberOfCases;
double x1, y1, x2, y2, x3, y3, x4, y4;
cin >> NumberOfCases;

for(int k=0; k<NumberOfCases; k++){
    double area = 0;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    Pointclass::point point1 = {x1,y1}, point2 = {x2,y2}, point3 = {x3,y3}, point4 = {x4,y4};
    online = false;
    int intersections = checkintersection(point1, point2, point3, point4);
    if(online){continue;}
    if(intersections == 1){
        Pointclass::point PointOfIntersection = findintersection(point1,point2,point3,point4);
        cout << checksign(PointOfIntersection.x) << " " << checksign(PointOfIntersection.y) << endl; 
    }
    else{cout << "none\n";}       
}
return 0;
}