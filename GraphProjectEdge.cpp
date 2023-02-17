#include <iostream>
#include <string>
using namespace std;

// 
class Edges {
  public:
    Edges(int node1, int node2, int weight) {
      this->node1 = node1;
      this->node2 =node2;
      this->weight =weight;
    }
    int getNode1() {return node1;};
    int getNode2() {return node2;};
    int getWeight() {return weight;};
    void setNode1(int node1){
    	this->node1 = node1;
	}
	void setNode2(int node2){
    	this->node2 = node2;
	}
	void setWeight(int weight){
    	this->weight = weight;
	}
	
	void initialize(numNodes){      // hàm tao mot graph trong (graph toan 0)
		edges.resize(numNodes);
		for (int i=0;i<numNodes;i++){
			edges[i].resize(numNodes);
		}
	}
	
	private:
		int node1;
    	int node2;
    	int weight;
    	vector<vector<int>> edges;
    	
};

int main()
{
	
}
