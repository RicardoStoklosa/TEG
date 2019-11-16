#include<bits/stdc++.h>
#include"graph.h"
#define MAX_PESSOAS 150

using namespace std;

int main(){
    vector< Edge > adj[NUM_CITIES];
    readInput(adj);
    int pessoas=0;
    while(pessoas<=MAX_PESSOAS-1){
        int viagem=dijkstra(getCity("SP"),adj,MAX_PESSOAS-pessoas);

        pessoas+=viagem;
    }
    cout<<"Pessoas"<<pessoas<<endl;
    //showAdjList(adj);
}
