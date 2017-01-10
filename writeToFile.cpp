#include <fstream>
#include <string>

using namespace std;

int main() {
  string text_to_write = "Some text";
  string text_to_write2 = "Some text\n some text\n some text";

  const char* filename = "text.txt";

  // If filename is a string:
  string string_filename = "text2.txt";
  const char* filename2 = string_filename.c_str();

  // Writes in the first line
  ofstream outfile;
  outfile.open(filename);
  outfile << text_to_write;
  outfile.close();

  // Appends to the text in the file (starts a new line upon enld; or \n)
  ofstream outfile2;
  outfile2.open(filename2, ios::app);
  outfile2 << text_to_write2;
  outfile2.close();

  // ios::ate -> jumps to the end of the opened file
  // ios::trunc -> deletes content of the file, before doing what you specify
  // ios::in, ios::out -> opens file for input or output, should be used if you open file with fstream and not ofstream or ifsream

  return 0;
}