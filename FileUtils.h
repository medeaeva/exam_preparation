#ifndef FILEUTILS_H_
#define FILEUTILS_H_

#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <iomanip>
#include <ctype.h>
#include <algorithm>

using namespace std;

class FileUtils {
public:
  string readFromFileToStringLineByLine(string fileName);

  template<typename A>
  vector<A> readFromFileToVector(string fileName, vector<A> &inputVector);
  template<typename A>
  void writeToFileFromVector(string fileName, vector<A> &inputVector);
  template<typename A>
  void writeToFileFromVectorReverse(string fileName, vector<A> &inputVector);

  template<typename A, typename B>
  map<A, B> readFromFileToMap(string fileName, map<A, B> &inputMap, B initialValue);
  template<typename A, typename B>
  void writeToFileFromMap(string fileName, map<A, B> &inputMap);
  template<typename A, typename B>
  void writeToFileFromMapReverse(string fileName, map<A, B> &inputMap);

  template<typename A>
  map<A, unsigned int> readFromFileToMapValueAsElementCount(string fileName, map<A, unsigned int> &inputMap);

  template<typename A, typename B>
  std::multimap<B, A> flipMap(const std::map<A, B> &src);
  template<typename A, typename B>
  std::pair<B, A> flipPair(const std::pair<A, B> &p);
};

string FileUtils::readFromFileToStringLineByLine(string fileName) {
  std::ifstream source_file(fileName.c_str());
  std::string buffer;
  std::string lines = "";
  while (getline(source_file, buffer)) {
    lines += buffer + "\n";
  }
  source_file.close();
  return lines;
}

template<typename A>
vector<A> FileUtils::readFromFileToVector(string fileName, vector<A> &inputVector) {
  A actualElement;
  ifstream sourceFile(fileName.c_str());
  if (sourceFile.is_open()) {
    while (sourceFile >> actualElement) {
      inputVector.push_back(actualElement);
    }
  }
  sourceFile.close();
  return inputVector;
}

template<typename A>
void FileUtils::writeToFileFromVector(string fileName, vector<A> &inputVector) {
  ofstream newFile;
  newFile.open(fileName.c_str());
  for (unsigned int i = 0; i < inputVector.size(); i++) {
    newFile << inputVector[i] << '\n';
  }
  newFile.close();
}

template<typename A>
void FileUtils::writeToFileFromVectorReverse(string fileName, vector<A> &inputVector) {
  ofstream newFile;
  newFile.open(fileName.c_str());
  for (unsigned int i = inputVector.size(); i > 0; i--) {
    newFile << inputVector[i - 1] << '\n';
  }
  newFile.close();
}

template<typename A, typename B>
map<A, B> FileUtils::readFromFileToMap(string fileName, map<A, B> &inputMap, B initialValue) {
  A actualElement;
  ifstream sourceFile(fileName.c_str());
  if (sourceFile.is_open()) {
    while (sourceFile >> actualElement) {
      inputMap.insert(make_pair(actualElement, initialValue));
    }
  }
  sourceFile.close();
  return inputMap;
}

template<typename A, typename B>
void FileUtils::writeToFileFromMap(string fileName, map<A, B> &inputMap) {
  ofstream newFile;
  newFile.open(fileName.c_str());
  for (typename map<A, B>::iterator it = inputMap.begin(); it != inputMap.end(); it++) {
    newFile << it->first << " " << it->second << '\n';
  }
  newFile.close();
}

template<typename A, typename B>
void FileUtils::writeToFileFromMapReverse(string fileName, map<A, B> &inputMap) {
  ofstream newFile;
  newFile.open(fileName.c_str());
  for (typename map<A, B>::reverse_iterator rit = inputMap.begin(); rit != inputMap.end(); rit++) {
    newFile << rit->first << " " << rit->second << '\n';
  }
  newFile.close();
}

template<typename A>
map<A, unsigned int> FileUtils::readFromFileToMapValueAsElementCount(string fileName, map<A, unsigned int> &inputMap) {
  A actualElement;
  ifstream sourceFile(fileName.c_str());
  if (sourceFile.is_open()) {
    while (sourceFile >> actualElement) {
      inputMap.insert(make_pair(actualElement, inputMap[actualElement]++));
    }
  }
  sourceFile.close();
  return inputMap;
}

template<typename A, typename B>
std::pair<B, A> FileUtils::flipPair(const std::pair<A, B> &p) {
  return std::pair<B, A>(p.second, p.first);
}

template<typename A, typename B>
std::multimap<B, A> FileUtils::flipMap(const std::map<A, B> &src) {
  std::multimap<B, A> sorted_map;
  std::transform(src.begin(), src.end(), std::inserter(sorted_map, sorted_map.begin()), flipPair<A, B>);
  return sorted_map;
}

#endif /* FILEUTILS_H_ */
