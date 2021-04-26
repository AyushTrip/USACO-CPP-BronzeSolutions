#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int n;
vector<int> sizes;

int main(){
  ifstream fin("triangles.in");
  ofstream fout("triangles.out");

  fin >> n;
  vector<int> X(n, 0);
  vector<int> Y(n, 0);

  //Read in the input
  for(int i=0; i<n; i++){
    fin >> X[i] >> Y[i];
  }

  //Loop through
  int current = 0;
  int greatest = -1;

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      for(int k=0; k<n; k++){
        if(i != j && j != k && i != k){
          if((X[i] == X[j] && Y[i] == Y[k])){
            current = (abs(X[i] - X[k]) * abs(Y[i] - Y[j]));
          }
          if(X[i] == X[k] && Y[i] == Y[j]){
            current = (abs(X[i] - X[j]) * abs(Y[i] - Y[k]));
          }
          if(current > greatest){
            greatest = current;
          }
        }
      }
    }
  }

  fout << greatest;
  return 0;
}
