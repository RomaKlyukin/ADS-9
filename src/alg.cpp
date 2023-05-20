// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include <cctype>
#include <string>
#include  "bst.h"
BST<std::string> makeTree(const char* filename) {
  BST<std::string> A;
  std::ifstream file(filename);
  if (!file) {
    std::cout << "File error!" << std::endl;
    return A;
  }
  std::string slovo = "";
  while (!file.eof()) {
    int ch = tolower(file.get());
    if ((ch > 96 && ch < 123)) {
      slovo += ch;
    } else {
      if (slovo != "")
        A.add(slovo);
      slovo = "";
    }
    if (ch == ' ') {
      A.add(slovo);
      slovo = "";
    }
  }
  file.close();
  return A;
}
