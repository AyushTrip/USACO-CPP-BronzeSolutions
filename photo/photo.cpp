#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;

int N;
int current;


int main() {

  //Read input
  ifstream fin("photo.in");
  ofstream fout("photo.out");

  fin >> N;
  int cows[N];

  //Loop to add to the array
  for(int i=0; i<N-1; i++){
    fin >> cows[i];
  }

  //Main loop through combinations
  //Loop from 1...cows[0]-1 (first term minus one)
  for(int i=1; i<cows[0];i++){
    vector<int> tested;
    tested.push_back(i);
    current = i;

    for(int j=0; j<N-1;j++){
      //cout << j << " " << cows[j] << endl;
      current = abs(cows[j] - current);
      if (count(tested.begin(), tested.end(), current)){
        break;
      }
      else{
        tested.push_back(current);
      }
    }

    //Print out the vector
    if(tested.size() == N){
      fout << tested[0];
      for (int i=1; i<tested.size();i++){
        fout << ' ' << tested[i];
      }
      break;
    }

    //Construct a sequence
  }



  return 0;
}
