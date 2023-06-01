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
#include <algorithm>
#include <stack>

using namespace std;
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
  double angle(Pointclass::point point1, Pointclass::point &point2){
      double ang = 0;

        ang = atan2(point1.y - point2.y, point1.x - point2.x);
      return ang;
  }

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
        direction = 1;
    }else if(checkarea(checkdirectionvector) == 0) {
        direction = 0;
    }
    else{
        direction = 2;
    }
    return direction;
}
Pointclass::point nextToTop(stack<Pointclass::point> &S)
{
    Pointclass::point p = S.top();
    S.pop();
    Pointclass::point res = S.top();
    S.push(p);
    return res;
}
vector<Pointclass::point> FindConvexHull(vector<Pointclass::point> Pointvec){
    
}
int main() 
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int NumberOfPoints;
double x, y;
cin >> NumberOfPoints;
while(NumberOfPoints){
    vector<Pointclass::point> Pointvec;
    Pointvec = {};
    for(int k=0; k<NumberOfPoints; k++){
        double area = 0;
        cin >> x >> y;
        Pointvec.push_back({x,y});
 
    }
    int n = Pointvec.size();
    int ymin = Pointvec[0].y;
    int min = 0;
    for (int i = 1; i < n; i++)
    {
        int y = Pointvec[i].y;
        if ((y < ymin) || (ymin == y && Pointvec[i].x < Pointvec[min].x)){
            ymin = Pointvec[i].y;
            min = i;
        }
    }
    swap(Pointvec[0], Pointvec[min]);
    Pointclass::point p0 = {0,0};
    p0 = Pointvec[0];

    vector <pair<double,int>> RotationFromLowest;
    for(int i=0; i<Pointvec.size(); i++){
        RotationFromLowest.push_back(make_pair(angle(Pointvec[0], Pointvec[i]), i));
    }
    sort(RotationFromLowest.begin()+1, RotationFromLowest.end());

    vector<Pointclass::point> Pointvec2;
    for(int i=0; i<Pointvec.size(); i++){
        Pointvec2.push_back(Pointvec[RotationFromLowest[i].second]);
    }
    Pointvec = Pointvec2;
    int m = 1;

    for (int i=1; i<n; i++)
    {
        while (i < n-1 && checkdirection(p0, Pointvec[i], Pointvec[i+1]) == 0)
            i++;
        Pointvec[m] = Pointvec[i];
        m++;
    }
    if (m < 3) continue;
   stack<Pointclass::point> S;
   S.push(Pointvec[0]);
   S.push(Pointvec[1]);
   S.push(Pointvec[2]);

   for (int i = 3; i < m; i++)
   {
      while (S.size()>1 && checkdirection(nextToTop(S), S.top(), Pointvec[i]) != 2)
         S.pop();
      S.push(Pointvec[i]);
   }
    while (!S.empty())
   {
       Pointclass::point p = S.top();
    cout << p.x << " " << p.y << endl;
       S.pop();
   }
    cout << endl;
    cin >> NumberOfPoints;   
}
return 0;
}
