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
                mat[i][j] = 1e9;
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
        int w[100];
        int p[100]={-1};
        int visited[100]={0};
        int min=mat[0][0];
        int a;
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(mat[i][j]<min){
                    min=mat[i][j];
                    a=i;
                }
            }
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
    return 0;
}