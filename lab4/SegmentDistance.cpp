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
double delta;
bool online = false;
class Pointclass{
public:
  struct point {
    double x, y;

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
    }else if(checkarea(checkdirectionvector) == 0) {
        direction = 0;
    }
    else{
        direction = 1;
    }
    return direction;
}
bool checkonline(Pointclass::point a, Pointclass::point b, Pointclass::point c){
  if(b.x <= max(a.x, c.x) && b.x >= min(a.x, c.x) && b.y <= max(a.y, c.y) && b.y >= min(a.y, c.y)){
    return true;
  }
  else{return false;}
}
int checkintersection(Pointclass::point a, Pointclass::point b, Pointclass::point c, Pointclass::point d){
    vector<Pointclass::point> Pointvec = {};
    int intersect = 0;
    int direction1 = checkdirection(a, b, c);
    int direction2 = checkdirection(a, b, d);
    int direction3 = checkdirection(c, d, a);
    int direction4 = checkdirection(c, d, b);

    if(direction1 != direction2 && direction3 != direction4){
        return intersect;
    }
    if (direction1 == 0 && checkonline(a, c, b)){
        return intersect;
    }
    if (direction2 == 0 && checkonline(a, d, b)){
        return intersect;
    } 
    if (direction3 == 0 && checkonline(c, a, d)){
        return intersect;
    }
    if (direction4 == 0 && checkonline(c, b, d)){ 
        return intersect;
    }
    intersect = -1;
    return intersect;
}
double pointtoline(Pointclass::point a, Pointclass::point b, Pointclass::point c){    
    double A = c.x - a.x;
    double B = c.y - a.y;
    double C = b.x - a.x;
    double D = b.y - a.y;

    double dot = A * C + B * D;
    double len_sq = C * C + D * D;
    double param = -1;
    if (len_sq != 0){
        param = dot / len_sq;
    }
    double xx, yy;

    if (param < 0) {
        xx = a.x;
        yy = a.y;
    }
    else if (param > 1) {
        xx = b.x;
        yy = b.y;
    }
    else {
        xx = a.x + param * C;
        yy = a.y + param * D;
    }

    double dx = c.x - xx;
    double dy = c.y - yy;

    double result = sqrt(dx * dx + dy * dy);
    return result;

}
void linetoline(Pointclass::point a, Pointclass::point b, Pointclass::point c, Pointclass::point d){
    //a och b är en linje. c och d är en linje
    //linje a till b från punkt c
    double lowest = pointtoline(a,b,c);
    lowest = min(lowest,pointtoline(a,b,d));
    lowest = min(lowest,pointtoline(c,d,a));
    lowest = min(lowest,pointtoline(c,d,b));
    cout << fixed << setprecision(2);
    cout << lowest << endl;
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
    if(intersections == 0){
        cout << "0.00" << endl; 
    }
    else{
        linetoline(point1, point2, point3, point4);
    }       
}
return 0;
}