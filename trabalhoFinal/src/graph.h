#include<bits/stdc++.h>
#define NUM_CITIES 14
using namespace std;



struct Edge{
    int node;
    int cost;
    int flow;
    int departure;
    int arrival;
};


int getCity(string name);

void addEdge(vector<Edge> adj[], int from, int to, int cost, int flow, int departure, int arrival);

void showAdjList(vector<Edge> adj[]);

void readInput(vector<Edge> adj[]);

int hourToMinutes(string hour);

int minDistance(int distancia[], bool previous[]);

void dijkstra(int start, vector< Edge > adj[]);

void showSolution(int dist[]);
