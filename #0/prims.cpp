#include <iostream>
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
                mat[i][j] = INT_MAX;
        }
    }

    void addEdge(int s, int d,int weight) {
        mat[s-1][d-1] = weight;
        mat[d-1][s-1] = weight; 
    }

    void display() {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
    void prims(){
        int w[100], p[100], visited[100];
        for(int i=0;i<v;i++){
            w[i] = INT_MAX;
            p[i] = -1;
            visited[i] = 0;
        }

        w[0] = 0; // start from vertex 0

        for(int count = 0; count < v - 1; count++){
            int u = -1;
            int minWeight = INT_MAX;
            for(int i=0;i<v;i++){
                if(!visited[i] && w[i] < minWeight){
                    minWeight = w[i];
                    u = i;
                }
            }

            visited[u] = 1;

            for(int i=0;i<v;i++){
                if(mat[u][i] < INT_MAX && !visited[i] && mat[u][i] < w[i]){
                    p[i] = u;
                    w[i] = mat[u][i];
                }
            }
        }

        cout << "Edges in MST:\n";
        for(int i=1; i<v; i++){
            cout << p[i]+1 << " - " << i+1 << " : " << w[i] << endl;
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
        int s, d,w;
        cout << "Enter source, destination and weight: ";
        cin >> s >> d>>w;
        obj.addEdge(s, d,w);
    }

    obj.display();
    obj.prims();
    return 0;
}