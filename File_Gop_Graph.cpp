//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cstdlib>

using namespace std;

class Node {                  // class tao node luu thong tin cua tung nguoi
	public:
		Node();
		Node(string name, int id, string dob, string email, string mssv);
		string getName();
		void setName(string name);
		int getId();
		void setId(int id);
		string getDob();			
		void setDob(string dob);
		string getEmail();
		void setEmail(string email);
		string getMssv();
		void setMssv(string mssv);
		vector<int> getFriendList();
		void setFriendList(vector<int> friendList);
		int getNum();
		void setNum(int numFriend);

	private:
		string name;
		int id;
		string dob;
		string email;
		string mssv;
		vector<int> friendList; // them mang friendlist bang cach cat tu bang 
		int numFriend;							

};

	Node::Node() {}
	Node::Node(string name, int id, string dob, string email, string mssv)
	{
		this->name = name;
		this->id = id;									
		this->dob = dob;			
		this->email = email;
		this->mssv = mssv;
	}

	string Node::getName() {return name;}
	int Node::getId() {return id;}
	string Node::getDob() {return dob;}
	string Node::getEmail() {return email;}
	string Node::getMssv() {return mssv;}
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
	void Node::setMssv(string mssv) {
		this->mssv = mssv;
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
			FriendList(node.getId());
		}
		
		void addEdge(int fromId, int toId, int weight){
			edges[getIndex(fromId)][getIndex(toId)] = weight;                 // ham them canh giua 2 node
			FriendList(fromId);
		}
		
		void deleteNode(int id){
			nodes.erase(nodes.begin()+getIndex(id));                      // ham xoa mot node (tim theo id) ; di kem voi phuong thuc xoa canh 
			for (int i=0;i<edges.size();i++){
			 	edges[i].erase(edges[i].begin()+getIndex(id));                          // phuong thuc xoa canh trong do thi
			}  
			edges.erase(edges.begin()+getIndex(id));		
		}
		
		void deleteEdge(int fromId, int toId){
			edges[getIndex(fromId)][getIndex(toId)] = 0;
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
		
		void printEdges(){  // phuong thuc in ra ma tran canh ke
			for (int i=0;i<edges.size();i++){
				for (int j=0;j<edges.size();j++){
					cout << edges[i][j] <<" ";
				}
				cout << "\n";
			}
		}
		
		void FriendList(int id){        // ham them danh sach ban va dem so ban luon
			int index = getIndex(id);
			nodes[index].setFriendList(edges[index]);
			int count = 0;
			for(int i=0;i<edges.size()-1;i++){
				if (edges[index][i] != 0){                     
					count++;
				}
			}
			nodes[index].setNum(count);  // dat gia tri so ban
		}

		
		vector <Node> mostFriend(){    // phuong thuc tim nguoi nhieu ban nhat   
			Node max = nodes[0];	// dat max la node dau tien
			vector <Node> maxFriends;
			for (int index=0; index<nodes.size();index++){
				if (max.getNum() < nodes[index].getNum()){
					max = nodes[index];	// dat max la node hien tai
					maxFriends.clear();	// xoa vector
				}
				
				if (max.getNum() == nodes[index].getNum())
				{
					maxFriends.push_back(nodes[index]);	// neu node hien tai = max thi them vao vector
				}
			}
			return maxFriends; // tra ve vector chua cac node nhieu ban nhat
		}
		
		vector <Node> leastFriend(){       // phuong thuc tim nguoi it ban nhat
			Node min = nodes[0];	// dat min la node dau tien
			vector <Node> minFriends;
			for (int index=0; index<nodes.size();index++){
				if (min.getNum() > nodes[index].getNum()){
					min = nodes[index];	// dat min la node hien tai
					minFriends.clear();	// xoa vector
				}
				
				if (min.getNum() == nodes[index].getNum())
				{
					minFriends.push_back(nodes[index]);	// neu node hien tai = min thi them vao vector
				}
			}
			return minFriends;	// tra ve vector chua cac node it ban nhat
		}
		
		
		vector<Node> maxWeight(int id){         // ham tim nguoi tuong tac voi minh nhieu nhat (Tim kiem theo chieu doc)
			int index = getIndex(id);	// lay index tu id
			int max = edges[0][index];	// dat max la hang dau tien cua edges
			vector<Node> maxWeightNode; // khoi tao node vector
			for (int i=0; i<edges[index].size(); i++){
				if (edges[i][index] > max && index != i){                 
					max = edges[i][index];	// dat max la edges hien tai
					maxWeightNode.clear();	// xoa vector
				}
				if (edges[i][index] == max && index != i)
				{
					maxWeightNode.push_back(nodes[i]); // neu max = edges hien tai thi them vao vector
				}
			}
			return maxWeightNode; // tra ve vector chua cac node tuong tac voi id nhieu nhat
		}
		
		vector<Node> minWeight(int id){    // ham tim nguoi tuong tac voi minh it nhat
			int index = getIndex(id);	// lay index tu id
			int min = edges[0][index];	// dat min la hang dau tien cua edges
			vector<Node> minWeightNode;	// khoi tao node vector
			for (int i=0; i<edges[index].size(); i++){
				if (edges[i][index] < min && index != i){                    
					min = edges[i][index];	// dat min la edges hien tai        
					minWeightNode.clear();	// xoa vector
				}
				if (edges[i][index] == min && index != i)
				{
					minWeightNode.push_back(nodes[i]);	// neu min = edges hien tai thi them vao vector
				}
			}
			return minWeightNode;  // tra ve vector chua cac node tuong tac voi id it nhat
		}
		
		void bfs1(int id) {            // ham tim cac node co lien ket den node chinh
//    		vector<Node> suggestFriend;
    		int index = getIndex(id);
			bool visited[nodes.size()] = {false};  // Mang bool danh dau nhung dinh da duoc tham
    		queue<int> q;    // queue luu cac dinh da duoc duyet
    		q.push(index);    // Ðua dinh bat dau vao hang doi va danh dau la da tham
    		visited[index] = true;

    		while (!q.empty()) {
        		int currentNodeIndex = q.front();   // lay dinh dau hang doi
        		q.pop();
				if (edges[index][currentNodeIndex] == 0 && currentNodeIndex != index){
					cout <<nodes[currentNodeIndex].getName() << " co id la " << nodes[currentNodeIndex].getId() << "\n";
				}
				
		
        		for (int i = 0; i < nodes.size(); i++) {     // Duyet cac dinh ke cua dinh hien tai va dua vao hang doi
            		if (edges[currentNodeIndex][i] && !visited[i]) {
                		q.push(i);
                		visited[i] = true;
            		}
        		}
    		}
		}
		
		void MsuggestFriend(int id){
			int index = getIndex(id);
			for (int i=0; i < nodes[index].getFriendList().size();i++){
				if (getFriendList()[i] != 0){
					bfs1(i);
				}
			}		
		}

		vector<Node> getNodes()
		{
			return nodes;
		}
		
		vector<vector<int>> getEdges()
		{
			return edges;
		}
		
		
	private:
		vector<Node> nodes;
		vector<vector<int>> edges;		
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
	int optint;
	string optstr;
	do
	{
		cout << "                  GRAPH FACEBOOK                   " << endl << endl;
		cout << " __________________________________________________" << endl;
		cout << "|                    < MENU >                      |" << endl;
		cout << "| 1. Nap du lieu nguoi dung                        |" << endl;
		cout << "| 2. Tra thong tin user theo id                    |" << endl;
		cout << "| 3. Tim user co so ban nhieu nhat                 |" << endl;
		cout << "| 4. Tim user co so ban it nhat                    |" << endl;
		cout << "| 5. Tim user tuong tac voi ban nhieu nhat theo id |" << endl;
		cout << "| 6. Tim user tuong tac voi ban it nhat theo id    |" << endl;
		cout << "| 7. De xuat ban moi cho user theo id              |" << endl;
		cout << "| 8. Thoat                                         |" << endl;
		cout << "|__________________________________________________|" << endl << endl;
		cout << "Moi ban lua chon (1-8): ";
		
		cin >> optstr;
		fflush(stdin);
		
//		Xu ly neu nguoi dung nhap vao string
		try
		{
			optint = stoi(optstr);
		}
		catch (...)
		{
			optint = 10;
		}

//		Xu ly tung optint				
		switch (optint)
		{
			case 1:
			{
				// input node
				string inputnodes,inputedges;
				cout << "Moi ban nhap ten file input user: ";
				cin >> inputnodes;
				ifstream file(inputnodes);
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
					cout << "[+] Import Nodes thành công..." << endl;
				}
				file.close();
				
				// input edges
				cout << "Moi ban nhap ten file input edges: ";
				cin >> inputedges;
				ifstream fileEdges(inputedges);
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
					cout << "[+] Import Edges thành công..." << endl;
				}
				fileEdges.close();
				break;
			}
			case 2:
			{
				int seachId;
				Node seachNode;
				cout << "Moi ban nhap id user can tra: ";
				cin >> seachId;
				seachNode = graph.getNodes()[graph.getIndex(seachId)];
				cout << endl << endl;
				cout << "[+] Ho Va Ten: " << seachNode.getName() << endl;
				cout << "[+] Id: " << seachNode.getId() << endl;
				cout << "[+] Ngay sinh: " << seachNode.getDob() << endl;
				cout << "[+] Email: " << seachNode.getEmail() << endl;
				cout << "[+] MSSV: " << seachNode.getMssv() << endl;
				cout << "[+] So luong ban be: " << seachNode.getNum() << endl;
				cout << endl;
				break;	
			}
//			case 3:
//			{
//				graph.printEdges();
//				break;
//			}
			case 3:
			{
				vector<Node> maxFriends = graph.mostFriend();
				cout << endl;
				cout << "[+] So ban be nhieu nhat: " << maxFriends[0].getNum() << endl;
				cout << "[+] So luong user co so ban be nhieu nhat: " << maxFriends.size() << endl;
				cout << "----------------------------------------" << endl;
				for (int i = 0; i < maxFriends.size(); i++)
				{
					cout << "STT: " << i+1 << endl;
					cout << "Ho Va Ten: " << maxFriends[i].getName() << endl;
					cout << "Id: " << maxFriends[i].getId() << endl;
					cout << "----------------------------------------" << endl;
				}
				break;
			}
			case 4:
			{
				vector<Node> minFriends = graph.leastFriend();
				cout << endl;
				cout << "[+] So ban be it nhat: " << minFriends[0].getNum() << endl;
				cout << "[+] So luong user co so ban be it nhat: " << minFriends.size() << endl;
				cout << "----------------------------------------" << endl;
				for (int i = 0; i < minFriends.size(); i++)
				{
					cout << "STT: " << i+1 << endl;
					cout << "Ho Va Ten: " << minFriends[i].getName() << endl;
					cout << "Id: " << minFriends[i].getId() << endl;
					cout << "----------------------------------------" << endl;
				}
				break;
			}
			case 5:
			{
				int maxWeightId;
				cout << "Moi ban nhap id cua user can tim: ";
				cin >> maxWeightId;
				vector<Node> maxWeightNode = graph.maxWeight(maxWeightId);
				cout << endl;
				// lay edges ra va tro vao chi so index cua node dau tien trong vector va chi so index cua id can tim
				cout << "[+] So luot tuong tac nhieu nhat voi id tren: " << graph.getEdges()[graph.getIndex(maxWeightNode[0].getId())][graph.getIndex(maxWeightId)] << endl;
				cout << "[+] So luong user co so luot tuong nhieu nhat voi id tren: " << maxWeightNode.size() << endl;
				cout << "----------------------------------------" << endl;
				for (int i = 0; i < maxWeightNode.size(); i++)
				{
					cout << "STT: " << i+1 << endl;
					cout << "Ho Va Ten: " << maxWeightNode[i].getName() << endl;
					cout << "Id: " << maxWeightNode[i].getId() << endl;
					cout << "----------------------------------------" << endl;
				}
				break;
			}
			case 6:
			{
				int minWeightId;
				cout << "Moi ban nhap id cua user can tim: ";
				cin >> minWeightId;
				vector<Node> minWeightNode = graph.minWeight(minWeightId);
				cout << endl;
				// lay edges ra va tro vao chi so index cua node dau tien trong vector va chi so index cua id can tim
				cout << "[+] So luot tuong tac it nhat voi id tren: " << graph.getEdges()[graph.getIndex(minWeightNode[0].getId())][graph.getIndex(minWeightId)] << endl;
				cout << "[+] So luong user co so luot tuong it nhat voi id tren: " << minWeightNode.size() << endl;
				cout << "----------------------------------------" << endl;
				for (int i = 0; i < minWeightNode.size(); i++)
				{
					cout << "STT: " << i+1 << endl;
					cout << "Ho Va Ten: " << minWeightNode[i].getName() << endl;
					cout << "Id: " << minWeightNode[i].getId() << endl;
					cout << "----------------------------------------" << endl;
				}
				break;
			}
			
			case 7:
			{
				int id;
				cout << "Moi ban nhap id cua ban";
				cin >> id;
				cout << "Goi y ket ban voi cac user sau:\n";
				graph.bfs1(id);
				break;
			}
			
			case 8:
			{
				return 0;
			}
			
			case 1710:
			{
				graph.printEdges();
				break;
			}
			case 123457:
			{
				cout << "Nghia cho";
				break;
			}
			
			default:
			{
				cout << "Phim nhap vao khong hop le\n";
			}
		}
		fflush(stdin);
		cout<<"\nNhap phim bat ky de tiep tuc!";
		getchar();
		fflush(stdin);
		system("cls");
	}
	while (true);
	
	return 0;
}






