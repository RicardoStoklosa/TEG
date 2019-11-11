#include<bits/stdc++.h>
#include"graph.h"

using namespace std;

int main(){
    vector< Edge > adj[NUM_CITIES];
    readInput(adj);
    //addEdge(adj,getCity("SP"),getCity("POA"),2,4,hourToMinutes("1000"),hourToMinutes("1100"));
    //addEdge(adj,getCity("SP"),getCity("MAN"),4,8,hourToMinutes("1100"),hourToMinutes("1920"));
    showAdjList(adj);
    dijkstra(getCity("SP"),adj);
}
