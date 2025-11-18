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
                mat[i][j] = 0;
        }
    }

    void addEdge(int s, int d) {
        mat[s-1][d-1] = 1;
        mat[d-1][s-1] = 1; 
    }

    void display() {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
    void bfs(int s,int max){
        s=s-1;
        int *visited=new int[max]();
        queue <int> q;
        visited[s]=1;
        q.push(s);
        cout<<"BFS:"<<endl;
        while(!q.empty()){
            int current=q.front();
            q.pop();
            cout<<current+1<<" ";
            for(int i=0;i<v;i++){
                if(mat[current][i]==1 && visited[i]!=1){
                    visited[i]=1;
                    q.push(i);
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
        int s, d;
        cout << "Enter source and destination: ";
        cin >> s >> d;
        obj.addEdge(s, d);
    }

    obj.display();
    obj.bfs(1,v);
    return 0;
}