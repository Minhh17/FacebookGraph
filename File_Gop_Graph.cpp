#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<vector<int>> edges;

class Node {
	public:
		Node();
		Node(string name, int id, string dob, string email, string phone);
		string getName();
		void setName(string name);
		int getId();
		void setId(int id);
		string getDob();			
		void setDob(string dob);
		string getEmail();
		void setEmail(string email);
		string getPhone();
		void setPhone(string phone);

		
	private:
		string name;
		int id;
		string dob;
		string email;
		string phone;
		vector<Node> friendList; 
		

};

	Node::Node() {}
	Node::Node(string name, int id, string dob, string email, string phone)
	{
		this->name = name;
		this->id = id;									
		this->dob = dob;			
		this->email = email;
		this->phone = phone;
	}

	string Node::getName() {return name;}
	int Node::getId() {return id;}
	string Node::getDob() {return dob;}
	string Node::getEmail() {return email;}
	string Node::getPhone() {return phone;}
	void Node::setName(string name) {
		this->name = name;
	}
	void Node::setId(int id) {
		this->id = id;
	}
	void Node::setDob(string Dob) {
		this->dob = dob;
	}
	void Node::setEmail(string email) {
		this->email = email;
	}
	void Node::setPhone(string phone) {
		this->phone = phone;
	}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	
	void initialize(int numNodes){      // hàm tao mot graph trong (graph toan 0)
		edges.resize(numNodes);
		for (int i=0;i<numNodes;i++){
			edges[i].resize(numNodes);
		}
		
	}

	
	private:
		int node1;
    	int node2;
    	int weight;
    	
    	
};
/////////////////////////////////////////////////////////////////////////////////////////////////
class Graph:Node {
	public:
		void addNode(string name,int id, string dob, string email, string phone) {
			Node *node = new Node(name, id, dob, email, phone);
			nodes.push_back(*node);
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
				if (id == nodes[i].getId()){
					return i;
				}
			}
		}
	private:
		vector<Node> nodes;
	};	
int main()
{
	return 0;
}
