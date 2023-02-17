#include <iostream>
#include <string>
using namespace std;

class Node {
	public:
		Node();
		Node(string name, int id, string dob, string email, string phone);
		string getName();
		void setName(string name);
		int getId();
		void setId(int id);
		string getDob();			// get va set gtri private
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

};
//
	Node::Node() {}
	Node::Node(string name, int id, string dob, string email, string phone)
	{
		this->name = name;
		this->id = id;									
		this->dob = dob;			// khoi tao 
		this->email = email;
		this->phone = phone;
	}
//
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

int main()
{
	
}
