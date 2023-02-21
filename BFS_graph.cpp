#include <iostream>
#include <queue>
using namespace std;

// Khai báo m?t d? th? b?ng m?ng k?
const int V = 5;
int edges[V][V] = {{0, 1, 1, 0, 0},
                 {1, 0, 1, 1, 0},
                 {1, 1, 0, 1, 1},
                 {0, 1, 1, 0, 1},
                 {0, 0, 1, 1, 0}};

// Phuong th?c d? th?c hi?n BFS
void bfs1(int start) {
    // Mang bool danh dau nhung dinh da duoc tham
    bool visited[V] = {false};
    // queue luu cac dinh da duoc duyet
    queue<int> q;
    // Ðua dinh bat dau vao hang doi va danh dau la da tham
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        // lay dinh dau hang doi
        int currentNode = q.front();
        q.pop();
        
		cout << currentNode << " "; // xu ly o day
		
        // Duyet cac dinh ke cua dinh hien tai va dua vao hang doi
        for (int i = 0; i < V; i++) {
            if (edges[currentNode][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}
int main() {
    // In ra ket qua bfs
    cout << "BFS starting from vertex 3: ";
    bfs1(3);
//    cout << edges[3][2];
    return 0;
}
