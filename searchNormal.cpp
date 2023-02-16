#include <iostream>
using namespace std;

int searchAlgo(int x, int arr[], int n) {
	for (int i=0; i<n; i++){
		if (arr[i] == x){
			return i;
		}
//		cout << arr[i] << " ";
	}
	return -1;
}

int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i=0;i<n;i++){
		cin >> arr[i];
//		cout << arr[i] << " ";
	}
	cout << "index: " << searchAlgo(5, arr, n) ;
	
	return 0;
}
