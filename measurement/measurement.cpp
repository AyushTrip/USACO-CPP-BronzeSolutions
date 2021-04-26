#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const int max_n = 100;

int n, day, operation, c;
string name;

int changes[3][max_n+1];
int rates[3][max_n+1];

//Create a function to determine if a cow is the highest on a certain day
bool is_highest(int c, int d){
  int highest = max(max(rates[0][d], rates[1][d]), rates[2][d]);
  return rates[c][d] == highest;
}

int main(){
  ifstream fin("measurement.in");
  ofstream fout("measurement.out");

  fin >> n;

  //Read in the input and put the milk change on day d in location d of the array

  for (int i=0; i<n; i++){
    fin >> day >> name >> operation;

    if (name == "Bessie") c = 0;
    if (name == "Elsie") c = 1;
    if (name == "Mildred") c =2;

    changes[c][day] = operation;
  }

  //Make the initial value 0 for each cow array
  for (int i=0; i<3; i++){
    rates[i][0] = 7;
  }

  //Make the changes array
  for (int i=0; i<3; i++){
    for (int j=1; j<=100; j++){
      rates[i][j] = rates[i][j-1] + changes[i][j];
    }
  }
  //if (is_highest(0,d-1) != is_highest(0,d) || is_highest(1,d-1) != is_highest(1,d) || is_highest(2,d-1) != is_highest(2,d))
  //Find the new highest for each iteration from 0 to n.
  int num_changes = 0;
  for (int d=1; d<=100; d++){
    if (is_highest(0, d-1) != is_highest(0,d) || is_highest(1,d-1) != is_highest(1, d) || is_highest(2, d-1) != is_highest(2,d)){
      num_changes++;
    }
  }

  fout << num_changes << '\n';


  return 0;
}
