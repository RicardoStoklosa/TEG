#include <bits/stdc++.h>
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
    int inicio;

    showGraph(&graph);
    cin >> inicio;

    Floyd(&graph);

}

void Floyd(Graph* graph){

    int i, j, k;

    int previous[graph->vert];
    memset(previous, 0, sizeof(previous));
    int distancia[inicio][inicio] = 0;

    for (i = 0; i < graph->vert-1; i++)
        for (j = 0; j < graph->vert-1; j++)
            distancia[i][j] = graph->adj[i][j];

    for (k = 0; k < graph->vert-1; k ++)
        {
            for ( i = 0; i < graph->vert-1; i ++)
            {
                for ( j = 0; j < graph->vert-1; j ++)
                {
                    if (distancia [i][k] + distancia [k][j] < distancia [i][j])
                        distancia [i][j] = distancia [i][k] + distancia [k][j];
                }
            }
        }
        
    cout<<"Distancia até "<<inicio<<":"<<endl;
    for(int i=0; i< graph.vert; i++){
        cout<<"["<<i<<"] - "<<distancia[i]<<endl;
    }
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
            if (dist[i][j] == 999)
            cout <<
            cout<< graph->adj[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
