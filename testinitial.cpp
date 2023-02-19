#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector<vector<int>> edges;
void initialize(int numNodes){      // hàm tao mot graph trong (graph toan 0)
	edges.resize(numNodes);
	for (int i=0;i<numNodes;i++){
		edges[i].resize(numNodes);
		}	
	}
int main() {
	initialize(3);
	for (int i=0;i<edges.size();i++){
		for (int j=0;j<edges.size();j++){
			cout << edges[i][j] <<" ";
		}
		cout << "\n";
	}
	return 0;	
}
