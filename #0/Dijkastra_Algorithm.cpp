#include <iostream>
#include <limits.h>
using namespace std;

class GraphRep {
public:
    int v;
    int **mat;

    GraphRep(int v1) {
        v = v1;
        mat = new int*[v];
        for (int i = 0; i < v; i++) {
            mat[i] = new int[v];
            for (int j = 0; j < v; j++)
                mat[i][j] = 0;
        }
    }

    // Weighted edge, but taking 1-based input
    void addEdge(int s, int d, int w) {
        mat[s-1][d-1] = w; // 1-based to 0-based
    }

    void display() {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    void dijkstra(int src) {
        int *dist = new int[v];
        bool *visited = new bool[v];

        for (int i = 0; i < v; i++) {
            dist[i] = INT_MAX;
            visited[i] = false;
        }

        dist[src - 1] = 0;  // Convert source to 0-based

        for (int i = 0; i < v - 1; i++) {
            int u = -1;
            for (int j = 0; j < v; j++) {
                if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                    u = j;
                }
            }

            visited[u] = true;

            for (int k = 0; k < v; k++) {
                if (mat[u][k] != 0 && !visited[k] && dist[u] != INT_MAX && dist[u] + mat[u][k] < dist[k]) {
                    dist[k] = dist[u] + mat[u][k];
                }
            }
        }

        cout << "\nShortest distances from source " << src << ":\n";
        for (int i = 0; i < v; i++) {
            cout << "Node " << (i + 1) << ": ";
            if (dist[i] == INT_MAX) cout << "INF\n";
            else cout << dist[i] << endl;
        }
    }
};

int main() {
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;

    GraphRep obj(v);

    for (int i = 0; i < e; i++) {
        int s, d, w;
        cout << "Enter source, destination, and weight: ";
        cin >> s >> d >> w;
        obj.addEdge(s, d, w);
    }

    obj.display();

    int src;
    cout << "\nEnter source vertex for Dijkstra: ";
    cin >> src;

    obj.dijkstra(src);

    return 0;
}