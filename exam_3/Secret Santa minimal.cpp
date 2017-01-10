#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

// Write a simple program that creates secret santa pairs
// It should read names till the character q is typed to the standard output, 
// than it should print the names as secret santa pairs like:
// Clair - Mike
// Joe - Ron
// Cloe - Clair
// Ron - Cloe
// Mike - Joe

void calculate_santa(vector<string>& my_vector, vector<string>& my_vector2);
void print_map(vector<string>&, vector<string>&);
bool is_shuffle_right(vector<string>& my_vector, vector<string>& my_vector2);
void make_shuffle(vector<string>& my_vector, vector<string>& my_vector2);

int main() {
  vector<string> my_vector;
  vector<string> my_vector2;
  srand(unsigned(time(0)));
  calculate_santa(my_vector, my_vector2);
  return 0;
}

void calculate_santa(vector<string>& my_vector, vector<string>& my_vector2) {
  string text;
  cout << "Please enter names! In case, you type 'q', the computer makes santa pairs!" << endl;
  cin >> text;
  if (text == "q") {
    make_shuffle(my_vector, my_vector2);
    return;
  }
  my_vector.push_back(text);
  my_vector2.push_back(text);
  return calculate_santa(my_vector, my_vector2);
}

void print_map(vector<string>& my_vector, vector<string>& my_vector2) {
  map<string, string> my_map;
  for (int i = 0; i < my_vector.size(); i++) {
    my_map[my_vector[i]] = my_vector2[i];
  }
  for (map<string, string>::iterator it = my_map.begin(); it != my_map.end(); it++) {
    cout << it->first << "; " << it->second << endl;
  }
}

bool is_shuffle_right(vector<string>& my_vector, vector<string>& my_vector2) {
  for (int i = 0; i < my_vector.size(); i++) {
    if (my_vector[i] == my_vector2[i]) {
      return false;
    }
  }
  return true;
}

void make_shuffle(vector<string>& my_vector, vector<string>& my_vector2) {
  random_shuffle(my_vector.begin(), my_vector.end());
  if (is_shuffle_right(my_vector, my_vector2)) {
    print_map(my_vector, my_vector2);
    return;
  }
  make_shuffle(my_vector, my_vector2);
}