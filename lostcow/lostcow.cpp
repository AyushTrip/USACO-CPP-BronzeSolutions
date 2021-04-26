#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

int x, y;
int dist = 1;
int answer = 0;

vector <int> locations;

int main(){
  ifstream fin("lostcow.in");
  ofstream fout("lostcow.out");

  fin >> x >> y;

  locations.push_back(x);

  if (x > y){
    while ((x+dist) > y){
      locations.push_back(x+dist);
      dist *= -2;
    }
  }

  if (x < y){
    while ((x+dist) < y){
      locations.push_back(x+dist);
      dist *= -2;
    }
  }



  locations.push_back(y);

  for (int i=0; i<locations.size()-1; i++){
    answer += abs(locations[i+1] - locations[i]);
    cout << locations[i] << endl;
  }

  fout << answer << '\n';

  return 0;
}
