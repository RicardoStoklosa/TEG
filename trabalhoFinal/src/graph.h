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

struct Flight{
    int node;
    int flow;
    Edge *test;
};


int getCity(string name);

void addEdge(vector<Edge> adj[], int from, int to, int cost, int flow, int departure, int arrival);

void showAdjList(vector<Edge> adj[]);

void readInput(vector<Edge> adj[]);

int hourToMinutes(string hour);

int minDistance(int distancia[], bool previous[]);

int dijkstra(int start, vector< Edge > adj[], int pessoas);

void showSolution(int dist[]);
