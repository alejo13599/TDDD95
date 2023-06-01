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
int NumberOfCases;
string operation;
int count = 0;
cin >> NumberOfCases;
vector<string> Routines;
for(int i=0; i<NumberOfCases; i++){
    cin >> operation;
    Routines.push_back(operation);
}
vector<vector<int>> QuickchangeVec(NumberOfCases, vector<int>(NumberOfCases, 0));
//Jämför element 1 i or ett med allt i ord . Osv
for(int k=0; k<Routines.size(); k++){
    for(int l=k+1; l<Routines.size(); l++){    
        count = 0;
        for(int i=0; i<Routines[k].length(); i++){
            for(int j=0; j<Routines[l].length(); j++){
                if(Routines[k][i] == Routines[l][j]){
                    count += 1;

                }

            }

        }
        //cout << k << " " << l << endl;
        QuickchangeVec[k][l] = count;
        QuickchangeVec[l][k] = count;
    }
}
vector<int> PermutationsVector(Routines.size(), 0);
for(int i = 0; i<Routines.size(); i++){
    PermutationsVector[i] = i;
}
int newtotal = 10000;
while(next_permutation(PermutationsVector.begin(),PermutationsVector.end())){
    int changes = 0;
    int total = 0;
    for(int i = 1; i<Routines.size(); i++)
    {
        total +=  QuickchangeVec[PermutationsVector[i]][PermutationsVector[i-1]];
        //cout << QuickchangeVec[PermutationsVector[i]][PermutationsVector[i-1]] << endl;
    }
    //cout << total << endl;
    newtotal = min(total, newtotal);
    //cout << endl;
}
cout << newtotal << endl;

return 0;
}