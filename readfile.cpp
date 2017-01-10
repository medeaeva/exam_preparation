#include <fstream>

//read file into string by line

std::string read_file() {
  std::ifstream source_file("file.txt");
  std::string buffer;
  std::string content = "";
  while (getline(source_file, buffer)) {
    content += buffer + "\n";
  }
  source_file.close();
  return content;
}
