#include<bits/stdc++.h>
#include"graph.h"

using namespace std;

string citiesNames[NUM_CITIES] = {"SP","GOI","FOR","CUR","MAN","BEL","REC","POA","BRA","RJ","VI","SAL","MAC","NA"};

int getCity(string name){
    for(int i=0;i<NUM_CITIES;i++){
        if(citiesNames[i].compare(name)==0)
            return i;
    }
    cout<<"Cidade \""<<name<<"\" nao existe"<<endl;
    exit(0);
}

void addEdge(vector<Edge> adj[], int from, int to, int cost, int flow, int departure, int arrival){
    Edge edge = {
        to,
        cost,
        flow,
        departure,
        arrival,
    };

    adj[from].push_back(edge);
}

void showAdjList(vector<Edge> adj[]){
    for(int i=0; i<NUM_CITIES; i++){
        for(Edge edge:adj[i]){
            cout<<citiesNames[i]<<"->"<<citiesNames[edge.node]
                <<" [cost:"<<edge.cost<<"]"
                <<" [flow:"<<edge.flow<<"]"
                <<" ["<<edge.departure<<" "<<edge.arrival<<"]"
                <<endl;
        }
    }
}

void readInput(vector<Edge> adj[]){
    string from, to, departure, arrival;
    int cost, flow;
    while(cin>>from>>to>>departure>>arrival>>cost>>flow){
        if(getCity(from)==8 || getCity(to)==8)
            cost = cost/2;
        addEdge(adj,getCity(from),getCity(to),cost,200-flow,hourToMinutes(departure),hourToMinutes(arrival));
    }
}

int hourToMinutes(string h){
    int hour = stoi(h.substr(0,2));
    int minu = stoi(h.substr(2,3));
    return (hour*60)+minu;
}

int minDistance(int distancia[], bool previous[]){
        int mini = INT_MAX;
        int min_index=0;

        for(int i=0; i< NUM_CITIES; i++){
            if(previous[i]==false && distancia[i] <= mini){
                mini = distancia[i];
                min_index = i;
            }
        }
        cout<<"min:"<<min_index<<endl;
        return min_index;
}

void dijkstra(int start, vector< Edge > adj[]){
    int dist[NUM_CITIES];
    bool previous[NUM_CITIES];

    memset(dist,INT_MAX,sizeof(dist));
    memset(previous,true,sizeof(previous));

    dist[start] = 0;

    for(int i=0; i<NUM_CITIES-1;i++){
        int u = minDistance(dist,previous);
        previous[u]=true;
        for(int j=0; j<NUM_CITIES; j++){
            for(Edge edge:adj[u]){
                if(previous[j]==0 && edge.node==j && dist[u] != INT_MAX && (dist[u] + edge.cost) < dist[j])
                    dist[j] =  dist[u] + edge.cost;
            }
        }
    }
    //cout<<endl<<dist[getCity("NA")]<<endl;;
}

