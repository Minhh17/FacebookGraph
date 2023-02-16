#include <bits/stdc++.h>
using namespace std;

int A[10][10];
void initialize()
{
 	for(int i = 0; i < 10; ++i)
	for(int j = 0; j < 10; ++j)
 	A[i][j] = 0;
}
int main()
{
	int x, y, nodes, edges, trongso;
	initialize();
	cout << "Nhap so node: ";
	cin >> nodes;
	cout << "Nhap so canh: ";
	cin >> edges;
 	for(int i = 0; i < edges; ++i)
 	{
 		cout << "Nhap 2 dinh co canh o giua va trong so: ";
 		cin >> x >> y >> trongso;
 		A[x][y] = trongso;
 	}
 	for(int i=1;i<=nodes;++i){
 		for(int j=1;j<=nodes;++j){
 			if(A[i][j])
			{
 				cout<< A[i][j] <<" ";
 			}
 			else 
			{
				cout<<0<<" ";
			}
 		}
 		cout<<"\n";
	}
}
