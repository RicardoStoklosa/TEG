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
    while(cin>>from>>to>>cost>>flow>>departure>>arrival){
        if(getCity(from)==8 || getCity(to)==8)
            cost = cost/2;
        addEdge(adj,getCity(from),getCity(to),cost,flow,hourToMinutes(departure),hourToMinutes(arrival));
    }
}

int hourToMinutes(string h){
    int hour = stoi(h.substr(0,2));
    int minu = stoi(h.substr(2,3));
    return (hour*60)+minu;
}

