//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Node {                  // class tao node luu thong tin cua tung nguoi
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
		vector<int> getFriendList();
		void setFriendList(vector<int> friendList);
		int getNum();
		void setNum(int numFriend);

	private:
		string name;
		int id;
		string dob;
		string email;
		string phone;
		vector<int> friendList; // them mang friendlist bang cach cat tu bang 
		int numFriend;							

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
	vector<int> Node::getFriendList() {return friendList;}
	int Node::getNum() {return numFriend;}
	
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
	void Node::setFriendList(vector<int> friendList){
		this->friendList = friendList;
	}
	void Node::setNum(int numFriend){
		this->numFriend = numFriend;
	}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Edges {                     // da thoi khong dung
  public:
  	Edges();
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
	


	private:
		int node1;
    	int node2;
    	int weight;
};
/////////////////////////////////////////////////////////////////////////////////////////////////
class Graph:Node {
	public:
		Graph() {}
// Khong can dung nhung cu thich cho vo
		Graph(vector<Node> nodes){
			this->nodes = nodes;
		}
		void addNode(Node node) {
			nodes.push_back(node);                           // ham them 1 node moi ( tao moi 1 node + them node do vao vector nodes + mo rong do thi len 1 )
//			edges.resize(nodes.size()+1);
			initialize(nodes.size()); // oki cx dc
		}
		void addEdge(int fromId, int toId, int weight){
			edges[getIndex(fromId)][getIndex(toId)] = weight;                 // ham them canh giua 2 node
		}
		void deleteNode(int id){
			nodes.erase(nodes.begin()+getIndex(id));                      // ham xoa mot node (tim theo id) ; di kem voi phuong thuc xoa canh 
		}
		void deleteEdge(int id){
			for (int i=0;i<edges.size();i++){
			 	edges[i].erase(edges[i].begin()+getIndex(id));                          // phuong thuc xoa canh trong do thi
			}  
			edges.erase(edges.begin()+getIndex(id));
		}
		int getIndex(int id){
			for (int i=0;i<nodes.size();i++){
				if (id == nodes[i].getId()){                                // ham lay index cua nguoi theo id trong vector nodes
					return i;
				}
			}
		}
		
		void initialize(int numNodes){      // hàm tao mot do thi trong khong (graph toan 0)
			edges.resize(numNodes);
			for (int i=0;i<numNodes;i++){
				edges[i].resize(numNodes);
			}	
		}	
		
		void printEdges(){
			for (int i=0;i<edges.size();i++){
				for (int j=0;j<edges.size();j++){
					cout << edges[i][j] <<" ";
				}
				cout << "\n";
			}
		}
		
		void FriendList(int id){
			int index = Graph::getIndex(id);
			Node::setFriendList(edges[index]);
			int count = 0;
			for(int i=0;i<nodes.size();i++){
				if (nodes[index].getFriendList()[i] != 0){                     // ham them danh sach ban va dem so ban luon
					count++;
				}
			}
			Node::setNum(count);
		}
		int mostFriend(){
			int max = nodes[0].getNum();
			int maxFriend = 0;
			for (int index=0; index<nodes.size();index++){
				if (max < nodes[index].getNum()){
					max = nodes[index].getNum();
					maxFriend = index;
				}
			}
			return maxFriend;
		}
		
		int leastFriend(){
			int min = nodes[0].getNum();
			int minFriend = 0;
			for (int index=0; index<nodes.size();index++){
				if (min > nodes[index].getNum()){
					min = nodes[index].getNum();
					minFriend = index;
				}
			}
			return minFriend;
		}
		
		
		Node maxWeight(int id){
			int index = Graph::getIndex(id);
			int max = nodes[index].getFriendList()[0];
			int maxIndex = 0;
			for (int i=0; i<nodes.size(); i++){
				if (max < nodes[index].getFriendList()[i]){                    // ham tim nguoi tuong tac voi minh nhieu nhat
					max = nodes[index].getFriendList()[i];                    
					maxIndex = i;
				}
			}
			return nodes[maxIndex];
		}
		
		Node minWeight(int id){
			int index = Graph::getIndex(id);
			int min = nodes[index].getFriendList()[0];
			int minIndex = 0;
			for (int i=0; i<nodes.size(); i++){
				if (min > nodes[index].getFriendList()[i]){                    // ham tim nguoi tuong tac voi minh it nhat
					min = nodes[index].getFriendList()[i];                    
					minIndex = i;
				}
			}
			return nodes[minIndex];
		}
		
		vector<Node> suggestFriend(int id) {
			// co gang ap dung BFS 
		}
		vector<Node> nodes;
		vector<vector<int>> edges;
	private:
		
	};
// ham tach string thanh vector
vector<string> splitString(string input) 
{
	vector<string> result;
	string delimiter = ";";
	size_t pos = 0;
	string token;
	while ((pos = input.find(delimiter)) != string::npos) 
	{
		token = input.substr(0, pos);
		result.push_back(token);
		input.erase(0, pos + delimiter.length());
	}
	result.push_back(input);
	return result;
}
	
int main()
{
	// Tao class dieu khien
	Graph graph;
	
	// input node
	ifstream file("input.txt");
	if (!file) 
	{
		cout << "Could not open file!\n";
	}
	else
	{
		string line;
		while (getline(file, line)) 
		{
			vector<string> vectorData = splitString(line);
			graph.addNode(Node(vectorData[0],stoi(vectorData[1]),vectorData[2],vectorData[3],vectorData[4]));
		}
	}

	// input edges
	ifstream fileEdges("inputEdges.txt");
	if (!fileEdges) 
	{
		cout << "Could not open file!\n";
	}
	else
	{
		string line;
		while (getline(fileEdges, line)) 
		{
			vector<string> dataEdges = splitString(line);
			graph.addEdge(stoi(dataEdges[0]),stoi(dataEdges[1]),stoi(dataEdges[2]));
		}
	}
	cout << graph.nodes.size() << "\n";
	graph.printEdges();
	return 0;
}






