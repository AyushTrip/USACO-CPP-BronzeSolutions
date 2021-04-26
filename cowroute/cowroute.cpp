#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int a, b, n;
vector <int> costs;
int answer = -1;

int main(){

  // Read input numbers
  ifstream fin("cowroute.in");
  ofstream fout("cowroute.out");

  fin >> a >> b >> n;

  //Iterate through every single combination
  for(int i=0; i<n;i++){
    int cost, routes;
    fin >> cost >> routes;
    int routes_array[routes];

    for (int i=0; i<routes; i++){
      fin >> routes_array[i];
    }

    //Check to see if both a and b are present in the route
    bool a_present = false;
    bool b_present = false;
    int a_index, b_index = 0;

    for (int i=0; i < routes; i++){
      if (routes_array[i] == a){
        a_present = true;
        a_index = i;
      }
      if (routes_array[i] == b){
        b_present = true;
        b_index = i;
      }
    }

    if (a_present == true && b_present == true){
      if (a_index < b_index){
        costs.push_back(cost);
      }
    }
  }

  if (costs.size() > 0){
    answer = *min_element(costs.begin(), costs.end());
  }
  else{
    answer = -1;
  }

  fout << answer;

  return 0;
}
