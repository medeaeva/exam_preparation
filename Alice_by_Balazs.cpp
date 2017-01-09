#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

// Write a program that creates a text file named alice_words.txt
// containing an alphabetical listing of all the words,
// and the number of times each occurs, in the text version of
// Alice’s Adventures in Wonderland.
// (You can obtain a free plain text version of the book,
// along with many others, from http://www.gutenberg.org.)
//
// The first 10 lines of your output file should look something like this:
//
// Word              Count
// =======================
// a                 631
// a-piece           1
// abide             1
// able              1
// about             94
// above             3
// absence           1
// absurd            2
//
// How many times does the word alice occur in the book?
// What is the longest word in Alice in Wonderland?
// How many characters does it have?

bool is_uppercase(char c);

bool is_letter(char c);

bool is_hyphen(char c);

int main() {
  map<string, int> m;
  ifstream file;
  file.open("alice.txt");
  string buffer;
  while (file >> buffer) {
    string cache = "";
    int ascii_of_char;
    char char_temp;
    for (unsigned int i = 0; i < buffer.length(); i++) {
      ascii_of_char = buffer[i];
      if (is_hyphen(ascii_of_char) || is_letter(ascii_of_char)) {
        
        if (is_uppercase(ascii_of_char)) {
          ascii_of_char += 32;
          char_temp = ascii_of_char;
          cache += char_temp;
          
        } else if (is_hyphen(ascii_of_char)) {
          if (is_letter(buffer[i+1]) && is_letter(buffer[i-1])) {
            char_temp = ascii_of_char;
            cache += char_temp;
          } else {
            if (cache != "") {
              m[cache]++;
            }
            cache = "";
          }
          
        } else {
          char_temp = ascii_of_char;
          cache += char_temp;
          
        }
      }
    }
    if (cache != "") {
      m[cache]++;
    }
  }
  file.close();
  
  for (map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
    cout << it->first << " -> " << it->second << ';';
    cout << endl;
  }
  
  return 0;
}

bool is_uppercase(char c) {
  return (c > 64 && c < 91);
}

bool is_letter(char c) {
  return (is_uppercase(c) || (c > 96 && c < 123));
}

bool is_hyphen(char c) {
  return (c == 45);
}
