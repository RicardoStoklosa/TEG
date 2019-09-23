#include <bits/stdc++.h>
using namespace std;
struct Graph{
    int vert;
    int ** adj;
};

Graph readGraph();
void showGraph(Graph* graph);
void dijkstra(Graph* graph, int inicio, int  distancias[]);
int minDistance(Graph* graph, int distancia[], int previous[]);

int main(){
    Graph graph = readGraph();
    int inicio;

    showGraph(&graph);
    cin >> inicio;

    int  distancia[graph.vert];
    for (int i = 0; i < graph.vert; i++)
        distancia[i] = INT_MAX;
    dijkstra(&graph, inicio,  distancia);

    cout<<"Distancia ate "<<inicio<<":"<<endl;
    for(int i=0; i< graph.vert; i++){
        cout<<"["<<i<<"] - "<<distancia[i]<<endl;
    }
}

void dijkstra(Graph* graph, int inicio, int  distancia[]){


    int previous[graph->vert];
    memset(previous, 0, sizeof(previous));
    distancia[inicio] = 0;

    for(int i=0; i<graph->vert-1; i++){
        int u = minDistance(graph,distancia,previous);
        previous[u] = 1;
        for(int j=0; j<graph->vert; j++){
            if(previous[j]==0 && graph->adj[u][j]>0 && distancia[u] != INT_MAX && (distancia[u] + graph->adj[u][j]) < distancia[j])
                 distancia[j] =  distancia[u] + graph->adj[u][j];
        }
    }
}

int minDistance(Graph* graph, int distancia[], int previous[]){
        int min = INT_MAX;
        int min_index;

        for(int i=0; i< graph->vert; i++){
            if(previous[i]==0 && distancia[i] <= min){
                min = distancia[i];
                min_index = i;
            }
        }

        return min_index;
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
            cout<< graph->adj[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
