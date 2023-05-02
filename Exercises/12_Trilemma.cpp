#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <algorithm> 

using namespace std;
int NumberOfCases;
int x1, x2, x3, y_1, y_2, y_3 = 0;
double edge1;
double edge2;
double edge3;
vector<double> edges;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> NumberOfCases;
    for(int i=0; i<NumberOfCases; i++){
        edges.clear();
        cin >> x1 >> y_1 >> x2 >> y_2 >> x3 >> y_3;
        if((y_2-y_1)*(x3-x2) == (y_3-y_2)*(x2-x1)){
            cout << "Case #" << i+1 << ": " << "not a triangle" << endl;
            continue;
        }
        edge1 = (x1-x2)*(x1-x2)+(y_1-y_2)*(y_1-y_2);
        edges.push_back(edge1);
        edge2 = (x1-x3)*(x1-x3)+(y_1-y_3)*(y_1-y_3);
        edges.push_back(edge2);
        edge3 = (x2-x3)*(x2-x3)+(y_2-y_3)*(y_2-y_3);
        edges.push_back(edge3);
        if(edge1 == 0 || edge2 == 0 || edge3 == 0){
            cout << "Case #" << i+1 << ": " << "not a triangle" << endl;
            continue;           
        }
        sort(edges.begin(), edges.end());
        if((edge1 == edge2) || (edge1 == edge3) || (edge2 == edge3)){
            cout << "Case #" << i+1 << ": " << "isosceles ";
        }
        else{
            cout << "Case #" << i+1 << ": " << "scalene ";
        }
        if((edges[2] == edges[0]+edges[1])){
            cout << "right triangle";

        }else if((edges[2] < (edges[0]+edges[1]))){
            cout << "acute triangle";            
        }
        else{
             cout << "obtuse triangle";              
        }
        cout << "\n";
    }
return 0;
}