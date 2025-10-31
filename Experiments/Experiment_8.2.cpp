#include <iostream>
#include <vector>
using namespace std;

class GraphMatrix {
public:
    int v;
    int **mat;

    GraphMatrix(int v1) {
        v = v1;
        mat = new int*[v];
        for (int i = 0; i < v; i++) {
            mat[i] = new int[v];
            for (int j = 0; j < v; j++)
                mat[i][j] = 0;
        }
    }

    void addEdge(int s, int d) {
        mat[s - 1][d - 1] = 1;
        mat[d - 1][s - 1] = 1; // undirected
    }

    void display() {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
    void dfs(int s, int max) {
        s = s - 1;
        int *visited = new int[max]();
        int *st = new int[max];
        int top = -1;

        visited[s] = 1;
        st[++top] = s;

        cout << "DFS (Adjacency Matrix): ";

        while (top != -1) {
            int current = st[top--];
            cout << current + 1 << " ";

            for (int i = v - 1; i >= 0; i--) {
                if (mat[current][i] == 1 && visited[i] != 1) {
                    visited[i] = 1;
                    st[++top] = i;
                }
            }
        }
        cout << endl;
    }
};

class GraphList {
    int v;
    vector<vector<int>> adjList;

public:
    GraphList(int vertices) {
        v = vertices;
        adjList.resize(v + 1);
    }

    void addEdge(int s, int d) {
        adjList[s].push_back(d);
        adjList[d].push_back(s); // undirected
    }

    void display() {
        for (int i = 1; i <= v; i++) {
            cout << i << " -> ";
            for (int j = 0; j < adjList[i].size(); j++) {
                cout << adjList[i][j] << " ";
            }
            cout << endl;
        }
    }

    void DFS(int start) {
        int *visited = new int[v + 1]();
        int *st = new int[v + 1];
        int top = -1;

        visited[start] = 1;
        st[++top] = start;

        cout << "DFS (Adjacency List): ";

        while (top != -1) {
            int node = st[top--];
            cout << node << " ";

            // Traverse neighbors in reverse for correct DFS order
            for (int i = adjList[node].size() - 1; i >= 0; i--) {
                int neighbor = adjList[node][i];
                if (!visited[neighbor]) {
                    visited[neighbor] = 1;
                    st[++top] = neighbor;
                }
            }
        }
        cout << endl;
    }
};

int main() {
    GraphMatrix obj1(4);
    GraphList obj2(4);

    obj1.addEdge(1, 2);
    obj1.addEdge(2, 3);
    obj1.addEdge(3, 4);
    obj1.addEdge(4, 1);

    obj2.addEdge(1, 2);
    obj2.addEdge(2, 3);
    obj2.addEdge(3, 4);
    obj2.addEdge(4, 1);

    obj1.dfs(1, 4);
    obj2.DFS(1);

    return 0;
}