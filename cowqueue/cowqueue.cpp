#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int n;

int main(){
  ifstream fin("cowqueue.in");
  ofstream fout("cowqueue.out");

  fin >> n;
  int cows[n][3];

  for (int i=0; i<n; i++){
    fin >> cows[i][0] >> cows[i][1];
    cows[i][2] = cows[i][0] + cows[i][1];
  }

  //Sort the cows
  int temp[3];
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      if (cows[i][0] < cows[j][0]){
        for(int k=0; k<3; k++){
          temp[k] = cows[j][k];
        }
        for(int k=0; k<3; k++){
          cows[j][k] = cows[i][k];
        }
        for(int k=0; k<3; k++){
          cows[i][k] = temp[k];
        }
      }
    }
  }

  //Iterate through and change the values
  for (int i=0; i<n-1; i++){
    if(cows[i][2] > cows[i+1][0]){
      cows[i+1][0] = cows[i][2];
      cows[i+1][2] = cows[i+1][0] + cows[i+1][1];
    }
  }

  fout << cows[n-1][2];
  return 0;
}
