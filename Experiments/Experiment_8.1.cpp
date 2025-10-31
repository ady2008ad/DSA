#include <iostream>
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
        int *q=new int[max];
        int front,rear;
        front=rear=-1;
        visited[s]=1;
        q[++rear]=s;
        front=0;
        cout<<"BFS(Adjacency Matrix):";
        while(front<=rear){
            int current=q[front];
            front++;
            cout<<current+1<<" ";
            for(int i=0;i<v;i++){
                if(mat[current][i]==1 && visited[i]!=1){
                    visited[i]=1;
                    q[++rear]=i;
                }
            }
        }
        cout<<endl;
    }
};
class GraphList{
    int v;
    vector<vector<int>> adjList;
    public:
    GraphList(int vertices){
        v=vertices;
        adjList.resize(v+1);
    }
    void addEdge(int s, int d){
        adjList[s].push_back(d);
        adjList[d].push_back(s);   //undirected
    }
    void display(){
        for(int i=1;i<=v;i++){
            cout<<i<<"->";
            for(int j=0;j<adjList[i].size();j++){
                cout<<adjList[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void BFS(int start) {
        vector<int> visited(v+1, 0);
        queue<int> q;

        visited[start] = 1;
        q.push(start);

        cout << "BFS(Adjacency List):";

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";
            for (int i=0;i<adjList[node].size();i++) {
                if (!visited[adjList[node][i]]) {
                    visited[adjList[node][i]] = 1;
                    q.push(adjList[node][i]);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    GraphMatrix obj1(4);
    GraphList obj2(4);
    obj1.addEdge(1,2);
    obj1.addEdge(2,3);
    obj1.addEdge(3,4);
    obj1.addEdge(4,1);
    obj2.addEdge(1,2);
    obj2.addEdge(2,3);
    obj2.addEdge(3,4);
    obj2.addEdge(4,1);

    obj1.bfs(1,4);
    obj2.BFS(1);

    return 0;
}