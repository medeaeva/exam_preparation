#ifndef FUNCTIONTOOLS_H
#define FUNCTIONTOOLS_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <utility> //pair-hez

using namespace std;

std::vector<std::vector <unsigned short int> > get_two_dim_vect() { //visszaad teljes ketdimenzios vektort
  return map;
}

string m_int_to_string(int num) { //stringet int-te tevo csoda 
  stringstream stream;
  stream << num;
  string result(stream.str());
  return result;
}

pair<string, string> split_at_comma(string input) { //pair<string, string>-t ad vissza es stringet eszik pl:"9,5" coord szedtszedesere alkalmas
  pair<string, string> temp;
  int index = 0;
  for (int i = 0; input.length(); i++) {
    if (input[i] != ',') {
      temp.first += input[i];
      index++;
    }
    else {
      break;
    }
  }
  for (int i = index + 1; i < input.length(); i++) {
    temp.second += input[i];
  }  
  return temp;
}

pair<int, int> m_string_to_int_pair(string input) { //a fenti string-string coordinatanak hasznalt pairt int-int pair-re alakitja
  pair<string, string> str_pair = split_at_comma(input);
  pair<int, int> num_pair;
  stringstream sf;
  stringstream ss;
  sf << str_pair.first;
  sf >> num_pair.first;
  ss << str_pair.second;
  ss >> num_pair.second;
  return num_pair;
}

string file_to_string_entire(string filename) { // teljes fajlt string-ge alakit
  ifstream my_file;
  string content;
  string line;
  my_file.open(filename.c_str());
  if (!my_file.is_open()) {
      cout << "Cannot open " << filename << '!';
  }
  else {
    while (getline(my_file, line)) {
      content += line + '\n';
    }
    my_file.close();
  }
  return content;
}

int file_line_counter(string filename) { //megszamolja egy fajl sorait es int-kent visszaadja
  ifstream my_file;
  string line;
  int line_counter = 0;
  my_file.open(filename.c_str());
  if (!my_file.is_open()) {
      cout << "Cannot open " << filename << '!';
  }
  else {
    while (getline(my_file, line)) {
      line_counter ++;
    }
    my_file.close();
  }
  return line_counter;
}
string file_to_string_from_to(string filename, int from, int to) { //file-bol stringet keszit from sortol to sorig
  ifstream my_file;
  string content;
  string line;
  int line_counter = 0;
  
  my_file.open(filename.c_str());
  if (!my_file.is_open()) {
      cout << "Cannot open " << filename << '!';
  }
  else {
    while (line_counter != to) {
      if (line_counter >= from - 1) {
        getline(my_file, line);
        content += line + '\n';
        line_counter++;
      }
      else {
        getline(my_file, line);
        line_counter++;
      }
    }
    my_file.close();
  }
  return content;
}


bool is_success_string_to_file(string filename, string input) { //sikermero fuggvenyformula string fajlba irasakor
  ofstream my_file;
  my_file.open(filename.c_str());
  if (!my_file.is_open()) {
    return false;
  }
  else {
    my_file << input;
    my_file.close();
    return true;
  }
}

bool is_empty_file(string filename) { //ures-e a fajlocska
  ofstream my_file;
  my_file.open(filename.c_str(), std::fstream::out | std::fstream::trunc);
  if (!my_file.is_open()) {
    return false;
  }
  else {
    my_file.close();
    return true;
  }
}

string* char_star_array_to_string_array(char** input, int size) { //char**-bol string tomb
  string* temp_array = new string[size];
  int j = 0;
  for (int i = 1; i <= size; i++) {
    temp_array[j++] = input[i];
  }
  return temp_array;
}

bool contains_string_only_number(string input) { //stringben csak szamok vannak e
  int num_checker = 0;
  for (int i = 0; i < input.length(); i++) {
   if ((int)input[i] <= 57 && (int)input[i] >= 48) {
     num_checker++;
   }
  }
  if (num_checker == input.length()) {
    return true;
  }
  else {
    return false;
  }
}

#endif // FUNCTIONTOOLS_H
