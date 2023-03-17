// Author: Alexander Josefsson
// Liuid: Alejo135
// Problem is: 
// Time-complexity:
// Memory-complexity:
// Note:
#include <iostream>
#include <vector>
#include <complex>
#include <algorithm> 
using namespace std;
const double EPS = 1e-9;
const double INF = 2;
vector<vector<double>> matrix;
vector<double> ans;
int MatrixDimension;
double number;



//a är matrisen, b är en vektor med svar till ekvationen
int gauss(vector<vector<double>> a, vector<double> & ans){
    int n = a.size();
    int m = a[0].size()-1;

    vector<int> notzeros (m, -1); //Stores non-zero elements of the row.
    for(int col=0, row=0; col<m && row<n; ++col){
        int sel = row;
        // Går igenom varje rad i ekvationen. Letar efter det minsta elementet i kolumnen.
        for(int i=row; i<n; ++i){
            if(abs(a[i][col]) > abs(a[sel][col])){
                sel = i;
            }
        }
        //Om talet är mindre än flyttalsprecision antar vi att det är 0.
        if (abs (a[sel][col]) < EPS){
            continue;
        }
        //Change rows.
        for(int i=col; i<=m; ++i){
            swap(a[sel][i], a[row][i]);
        }
        notzeros[col]= row;   
        //cout << "nonz: " << notzeros[col] << endl;
        for(int i=0; i<n; ++i){
            if(i != row){
                double c = a[i][col]/ a[row][col];
                for(int j=col; j<=m; ++j){
                    a[i][j] -= a[row][j] * c;
                }
            }
        }
        ++row;
    }
    ans.assign(m,0);
    for(int i=0; i<m; i++){
        if(notzeros[i] != -1){
            ans[i] = a[notzeros[i]][m]/ a[notzeros[i]][i];
        }
    }

    for(int i=0; i<m; ++i){
        double sum = 0;
        for(int j=0; j<m; ++j){
            sum += ans[j] * a[i][j];
        }
        if(abs(sum - a[i][m]) > EPS){
            return 0;
        }
    }

    for(int i=0; i<m; ++i){
        if(notzeros[i] == -1){
            //cout << "hey" << i << " "  << notzeros[i] << endl;
            return INF;
        }
    }
    return 1;
}



int main() 
{
//To make the input faster
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

cin >> MatrixDimension;

while(MatrixDimension){
    vector<vector<double> > matrix(MatrixDimension, vector<double>(MatrixDimension, -1));
    vector<double> ans;

    for(int n=0; n<MatrixDimension; ++n){
        for(int m=0; m<MatrixDimension; ++m){
            cin >> number;
            matrix[n][m] = number;
        }
    }

    for(int i=0; i<MatrixDimension; ++i){
        cin >> number;
        //cout << number << endl;
        matrix[i].push_back(number);
    }

    int ok = gauss(matrix,ans);

    //Testar att printa
    if(ok == 1)
        for(int n=0; n<MatrixDimension; ++n){
            cout << ans[n] << " ";
        }
        else if(ok == INF){
            cout << "multiple"; 
            // for(int n=0; n<MatrixDimension; ++n){
            //     cout << ans[n] << " ";
            // }            
        }
        else{
            cout << "inconsistent";
        }
    cout << endl;
    cin >> MatrixDimension;
}
return 0;
}