#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;
struct Graph{
    int vert;
    int ** adj;
};

Graph readGraph();
void showGraph(Graph* graph);
void Floyd(Graph* graph);


int main(){
    Graph graph = readGraph();

    Floyd(&graph);

    showGraph(&graph);

}

void Floyd(Graph* graph){
    for (int k = 0; k < graph->vert; ++k) {
        for (int i = 0; i < graph->vert; ++i) {
            for (int j = 0; j < graph->vert; ++j) {
                if (graph->adj[i][k] < INF && graph->adj[k][j] < INF)
                    graph->adj[i][j] = min(graph->adj[i][j], graph->adj[i][k] + graph->adj[k][j]);
            }
        }
    }
}


Graph readGraph(){
    Graph graph;
    int vert;
    int aux;
    scanf("%d",&vert);
    int ** matrix =new int*[vert];
    for(int i=0; i<vert; i++){
        matrix[i] = new int[vert];
    }
    for(int i=0; i<vert; i++){
        for(int j=0; j<vert; j++){
            scanf("%d", &aux);
            if( aux==9999 )
                matrix[i][j] = INF;
            else
                matrix[i][j] = aux;
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
            if (graph->adj[i][j] == INF)
                cout<<"INF"<<"     ";
            else
                cout<<graph->adj[i][j]<<"       ";
        }
        cout<<endl;
    }
    cout<<endl;
}
