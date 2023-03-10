// Author: Alexander Josefsson
// Liuid: Alejo135
// Problem is: Interval Cover: To cover a given interval with least intervals from a given set. Return the number of intervals needed and
//index of the intervals needed.
// Time-complexity: O(NlogN). Since we need to sort the time-complexity is O(NlogN) due to the C++ sort()-function having that complexity.
//The rest of the algorithm runs in O(N) due to only iterating over all intervals onces.
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
	double start; //Start for the goal-intervall
	double ending; //End for the goal-intervall
	double X;
	double Y;
	int intervallcount = 0; //Number of intervalls needed
	int N = 0;
	unsigned long long int currindex = 0;

//Solver takes 3 inputs. 
	//double start: The start of the goal interval
	//double end: The end of the goal interval	
	//vector <tuple<double,double, int>> intervall: A vector containg tuples. Where each tuple is: {start of interval, end of intervall, index of intervall)}
	//Returns: A vector with the interval-indexes for intervals creating an optimal cover.
	
vector<int> solver(double start, double end, vector <tuple<double,double, int>> intervall){
	double currentstart = start;
	double currentend = start-1;
	vector<int> intervallvector = {}; //Vector with the correct-intervall indexes

	sort(intervall.begin(), intervall.end());

	//buffer interval
	intervall.push_back(tuple<double, double, unsigned long long int>(numeric_limits<double>::max(), numeric_limits<double>::lowest(), -1.0));
	
	for (int j=0; j < intervall.size(); j++){

		if (get<0>(intervall[j]) <= currentstart&& get<2>(intervall[j]) >= 0){

			if (currentend < get<1>(intervall[j])){
				currindex = get<2>(intervall[j]);
				currentend = get<1>(intervall[j]);
			}		
		}
		else{
			currentstart= currentend;
			intervallcount = intervallcount + 1;
			intervallvector.push_back(currindex);

			if (currentend >=end){
				break;
			}	

			if (get<0>(intervall[j]) <= currentstart){
				currentend = get<1>(intervall[j]);
				currindex = get<2>(intervall[j]);
			}
		}
	}

	//If the whole interval is not covered. We retrun a empty vector.
	if (currentend < ending){
		return {};
	}
	else{
		return intervallvector;
	}
	


}

int main() 
{
	while (cin >> start >> ending){	
		vector <tuple<double,double, int>> intervall;
		cin >> N;

		for (unsigned long long int i=0; i < N; i++){
			cin >> X >> Y;
			intervall.push_back(tuple<double, double, unsigned long long int>(X, Y, i));
		}
		
		vector<int> intervallvector = solver(start, ending, intervall);

		if (intervallvector.size() == 0){
			cout << "impossible" << "\n";
		}
		else{
			cout << intervallvector.size() << "\n";
			
			for (int j = 0; j<intervallvector.size(); j++){
				cout << intervallvector[j] << " ";
			}
				cout << "\n";
		}
	}
	return 0;
}
