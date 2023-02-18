#include <iostream>
#include <vector>
using namespace std;
void printVector(std::vector<std::vector<int>>& matrix) {
	for(int i=0;i<matrix.size();i++){
 		for(int j=0;j<matrix.size();j++){
 			if(matrix[i][j] != 0)
			{
 				std::cout<< matrix[i][j] <<" ";
 			}
 			else 
			{
				std::cout<< 0 <<" ";
			}
 		}
		std::cout <<"\n";
	}
}
int main() {
    vector<vector<int>> matrix = {{1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12},{1,2,4,0}};
//    std::cout << "Element at row 2, column 3 is " << matrix.at(1).at(2) << std::endl;
    printVector(matrix);
    std::cout << "\n";
	cout << &matrix[1][0];
	matrix[3].erase(&matrix[3][3]);
	for (int i=0;i<matrix.size();i++){
		matrix[i].erase(matrix[i].begin()+1);
	}
	matrix.erase(matrix.begin()+1);
	printVector(matrix);

  return 0;
}

