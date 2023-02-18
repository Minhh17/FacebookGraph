#include <iostream>
#include <vector>
using namespace std;

/////


/////

class Graph {
	public:
		void addNode(string name, string dob, string email, string phone) {
			node = new Node(name, id, dob, email, phone);
			nodes.push_back(node);
		}
		void addEdge(int fromId, int toId, int weight){
			edges[fromId][toId] = weight;
		}
		void deleteNode(int id){
			
		}


	private:
		vector<Node> nodes;
		
};


int main() {
	
}
