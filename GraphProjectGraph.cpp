#include <iostream>
#include <vector>
using namespace std;

class Graph {
	public:
		void addNode(string name, string dob, string email, string phone) {
			node = new Node(name, id, dob, email, phone);
			nodes.push_back(node);
			node.id = nodes.size();
		}
		void addEdge(int fromId, int toId, weight){
			edges[fromId][toId] = weight;
		}
//		void removeNode(int id)
//      void removeEdge(int id)
	private:
		vector<Node> nodes;
		int edges[100][100];
};


int main() {
	
}
