#include <bits/stdc++.h>
using namespace std;
struct Graph{
    int vert;
    int ** adj;
};
Graph readGraph();
void showGraph(Graph* graph);
int findStartVert(Graph* graph);
void fleury(Graph* graph);
void eulerPath(Graph* graph, int start);
int isValidNextEdge(Graph* graph, int u,int v);
void removeEdge(Graph* graph, int u,int v);
void addEdge(Graph* graph, int u,int v);
int dfsCount(Graph* graph,int u, int visited[]);
void showPath();
vector<int> caminho;

int main(){
    Graph graph = readGraph();
    showGraph(&graph);
    fleury(&graph);
    showPath();
}

Graph readGraph(){
    Graph graph;
    int vert;
    scanf("%d",&vert);
    int ** matrix =new int*[vert];
    for(int i=0; i<vert; i++){
        matrix[i] = new int[vert];
    }
    for(int i=0; i<vert; i++){
        for(int j=0; j<vert; j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    graph.vert = vert;
    graph.adj = matrix;
    return graph;
}

void showGraph(Graph* graph){
    cout<< graph->vert<<endl;
    for(int i=0; i<graph->vert; i++){
        for(int j=0; j<graph->vert; j++){
            cout<< graph->adj[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}
void showPath(){
    for(int i=0; i< caminho.size(); i++){
        cout<<caminho[i];
        if(i!=caminho.size()-1)
            cout<<"=>";
    }
    cout<<endl;
}

void fleury(Graph* graph){
    caminho.clear();
    int start = findStartVert(graph);
    caminho.push_back(start);
    eulerPath(graph, start);
}

void eulerPath(Graph* graph, int vert){
    for(int i=0; i<graph->vert ;i++){
        if(graph->adj[vert][i]!=0 && isValidNextEdge(graph,vert,i)==1){
            caminho.push_back(i);
            removeEdge(graph,vert,i);
            eulerPath(graph,i);
        }
    }
}

int isValidNextEdge(Graph* graph, int u,int v){
    int degree=0;
    for(int i=0; i< graph->vert; i++){
        if(graph->adj[u][i]==1)
            degree++;
    }
    if(degree == 1)
        return 1;

    int visited[graph->vert];
    memset(visited,0,sizeof(visited));
    for(int j=0;j<5;j++){
    }
    int count1 = dfsCount(graph,u,visited);

    removeEdge(graph,u,v);
    memset(visited,0,sizeof(visited));
    int count2 = dfsCount(graph,u,visited);
    addEdge(graph,u,v);

    if(count1 > count2)
        return 0;
    return 1;

}

int findStartVert(Graph* graph){
    int cur = 0;
    for(int i=0; i< graph->vert; i++){
        int degree=0;
        for(int j=0; j< graph->vert; j++){
            if(graph->adj[i][j]==1)
                degree++;
        }
        if(degree%2!=0)
            return i;
    }
    return 0;
}

void removeEdge(Graph* graph, int u,int v){
    graph->adj[u][v] = 0;
    graph->adj[v][u] = 0;
}

void addEdge(Graph* graph, int u,int v){
    graph->adj[u][v] = 1;
    graph->adj[v][u] = 1;
}

int dfsCount(Graph* graph, int u, int visited[]){
    visited[u] = 1;
    int count =1;
    for(int j=0;j<5;j++){
    }
    for(int i=0; i< graph->vert; i++){
        if(graph->adj[i][u]==1 && visited[i]==0)
            count += dfsCount(graph, i, visited);
    }
    return count;

}
