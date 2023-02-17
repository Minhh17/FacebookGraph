#include <bits/stdc++.h>

using namespace std;


int main()
{
	vector<vector<int>> A ;
	int x, y, nodes, edges, trongso;
	
	cout << "Nhap so node: ";
	cin >> nodes;
	cout << "Nhap so canh: ";
	cin >> edges;
	A.resize(nodes);
	for (int i=0; i<nodes; i++){
		A[i].resize(nodes);
	}
 	for(int i = 0; i < edges; ++i)
 	{
 		cout << "Nhap 2 dinh co canh o giua va trong so: ";
 		cin >> x >> y >> trongso;
 		A[x][y] = trongso;
 	}
 	for(int i=0;i<nodes;i++){
 		for(int j=0;j<nodes;j++){
 			if(A[i][j] != 0)
			{
 				cout<< A[i][j] <<" ";
 			}
 			else 
			{
				cout<< 0 <<" ";
			}
 		}
 		cout<<"\n";
	}
}
