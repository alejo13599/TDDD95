#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>


using namespace std;
int main() 
{
int H;
int W;
char currcord;
vector<vector<char>> coordvec = {};
vector<char> currow = {};
int numgold = 0;

queue<pair<int,int>> nodequeue;

ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

cin >> W >> H;
bool been[H][W];
for (int i=0; i < H; i++){
    currow = {};
	for (int j=0; j < W; j++){
        cin.clear();
        cin >> currcord;
        been[i][j] = false;
        currow.push_back(currcord);	
        if(currcord == 'P'){
            nodequeue.push({i,j});
        }

        //cout << currow[j] << " Pushed into vector " << j << "\n";
	}


    coordvec.push_back(currow);	
	}
    while (!nodequeue.empty()){
    pair<int,int>test = nodequeue.front();
    
    //cout << test.first << " y coord" << endl;
    //cout << test.second << " x coord"  << endl;
    //cout << coordvec[test.first][test.second] << " current element" << endl;
    if(coordvec[test.first][test.second] != '#'){
        char up = coordvec[test.first-1][test.second];
        char down = coordvec[test.first+1][test.second];
        char left = coordvec[test.first][test.second-1];
        char right = coordvec[test.first][test.second+1];
    //cout << up << " " << right << " " << down << " " << left << " ";
        if(coordvec[test.first][test.second] == 'G'){
            numgold = numgold+1;
            //cout << "Hej: " ;
        }
        if(up != 'T' && down != 'T' && right != 'T' && left != 'T'){
            //cout << "hej"<< '\n';
           //cout << been[test.first-1][test.second] << "\n";
            if((been[test.first-1][test.second]) == false){
                //cout << "hej1";
                nodequeue.push({test.first-1,test.second});
                been[test.first-1][test.second] = true;
                //cout << "Been " << been[test.first-1][test.second] << "\n";
            }
            if((been[test.first+1][test.second]) == false){
                //cout << "hej2";
                nodequeue.push({test.first+1,test.second});
                been[test.first+1][test.second] = true;
            }
            if((been[test.first][test.second-1]) == false){
                //cout << "hej3";
                nodequeue.push({test.first,test.second-1});
                been[test.first][test.second-1] = true;
            }
            if((been[test.first][test.second+1]) == false){
                //cout << "hej4";
                nodequeue.push({test.first,test.second+1});
                been[test.first][test.second+1] = true;
            }
        }
    }
    nodequeue.pop();
    


}
cout << numgold;
return 0;
}