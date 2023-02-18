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
			//
		}
		void addEdge(int fromId, int toId, int weight){
			edges[fromId][toId] = weight;
		}
		void deleteNode(int id){
			nodes.erase(nodes.begin()+getIndex(id));
		}
		void deleteEdge(int id){
			for (int i=0;i<edges.size();i++){
				edges[i].erase(edges[i].begin()+getIndex(id));
			}
			edges.erase(edges.begin()+getIndex(id));
		}
		int getIndex(int id){
			for (int i=0;i<nodes.size();i++){
				if (id == nodes[i].id){
					return i;
				}
			}
		}


	private:
		vector<Node> nodes;
		
};


int main() {
	
}
