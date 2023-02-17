#include <iostream>
#include <vector>

int main() {
  std::vector<std::vector<int> > matrix = {{1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12}};

  
  std::cout << "Element at row 2, column 3 is " << matrix.at(1).at(2) << std::endl;

  return 0;
}

