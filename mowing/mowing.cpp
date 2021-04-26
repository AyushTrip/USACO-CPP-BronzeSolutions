#include <iostream>
#include <fstream>
#include <vector>

using namespace std; // namespace

int n, current_x, current_y, dist, array_size;

vector<int> x_coordinates;
vector<int> y_coordinates;
vector<int> duplicates;


char direction;

int main(){
  ifstream fin("mowing.in");
  ofstream fout("mowing.out");

  fin >> n;

  //Step One - Create an array log of all coordinates farmer john moved to
  current_x = 0;
  current_y = 0;

  array_size = 0;

  //Iterate through all N logs
  for(int i=0; i<n; i++){
    fin >> direction >> dist;
    array_size += dist;

    //Make changes if the direction is N
    if (direction == 'N'){
      for (int j=0; j<dist; j++){
        current_y++;
        x_coordinates.push_back(current_x);
        y_coordinates.push_back(current_y);
      }
    }

    //Make changes if the direction is E
    if (direction == 'E'){
      for (int j=0; j<dist; j++){
        current_x++;
        x_coordinates.push_back(current_x);
        y_coordinates.push_back(current_y);
      }
    }

    //Make changes if the direction is W
    if (direction == 'W'){
      for (int j=0; j<dist; j++){
        current_x--;
        x_coordinates.push_back(current_x);
        y_coordinates.push_back(current_y);
      }
    }

    //Make changes if the direction is S
    if (direction == 'S'){
      for (int j=0; j<dist; j++){
        current_y--;
        x_coordinates.push_back(current_x);
        y_coordinates.push_back(current_y);
      }
    }
  }

  //Find duplicates
  for (int i=1; i<array_size; i++){
    for (int j=i-1; j>= 0; j--){
      if (x_coordinates[i] == x_coordinates[j] && y_coordinates[j] == y_coordinates[i]){
        //cout << i << " DUPLICATE " << j <<  " Coordinate: " <<  x_coordinates[i] << ' ' << y_coordinates[i] << endl;
        duplicates.push_back(abs(i-j));
      }
    }
  }


  if (duplicates.size() == 0){
    fout << -1;
  }
  else{
    int smallest_element = duplicates[0];
    for(int i=0; i<duplicates.size(); i++){
      if (duplicates[i] < smallest_element){
        smallest_element = duplicates[i];
      }
    }
    fout << smallest_element;
  }


  return 0;
}
