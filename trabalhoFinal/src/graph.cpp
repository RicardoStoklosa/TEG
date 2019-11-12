#include<bits/stdc++.h>
#include"graph.h"

using namespace std;
const int INF = 1000000000;

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
    //cout<<hour<<":"<<minu<<"="<<((hour*60)+minu)<<endl;
    return (hour*60)+minu;
}

int minDistance(int distancia[], bool path[]){
        int mini = INT_MAX;
        int min_index=0;

        for(int i=0; i< NUM_CITIES; i++){
            // cout<<endl<<path[i]<<"-"<<distancia[i]<<mini<<"-"<<endl;
            if(path[i]==false && distancia[i] <= mini){
                mini = distancia[i];
                min_index = i;
            }
        }
        //cout<<"min:"<<min_index<<endl;
        return min_index;
}

void dijkstra(int start, vector< Edge > adj[]){
    int dist[NUM_CITIES];
    int path[NUM_CITIES];
    int time[NUM_CITIES];
    bool mark[NUM_CITIES];

    for(int i=0; i<NUM_CITIES; i++){
        dist[i] = INF;
    }
    memset(path,-1,sizeof(path));
    memset(time,0,sizeof(path));
    memset(mark,false,sizeof(mark));

    dist[start] = 0;
    string city = "";
    for(int i=0; i<NUM_CITIES; i++){
        int v = -1;
        for(int j=0; j<NUM_CITIES; j++){
            if(!mark[j] && (v==-1 || dist[j]<dist[v]))
                v=j;
        }

        if(dist[v]==INF)
            break;

        mark[v]=true;
        if(path[v]!=-1)
            cout<<citiesNames[path[v]]<<"=>"<<time[v]<<" "<<citiesNames[v]<<endl;
        for(Edge edge : adj[v]){

            int to = edge.node;
            int cost = edge.cost;
            int arrival = edge.arrival;
            int departure = edge.departure;
            cout<<"Calc "<<citiesNames[v]<<"=>"<<citiesNames[to]<<" "<<departure<<"-"<<time[v]<<"="<<(departure-time[v])<<endl;
            if((dist[v]+cost)<dist[to] && (departure-time[v])>=60){
                dist[to]=dist[v]+cost;
                path[to]=v;
                time[to]=arrival;
                city=citiesNames[v];
            }
        }
    }

    vector<int> pathe;
    int t=getCity("NA");
    for (int v = t; v != getCity("SP"); v = path[v])
        pathe.push_back(v);
    pathe.push_back(getCity("SP"));

    reverse(pathe.begin(), pathe.end());
    cout<<"[ ";
    for(int p:pathe){
        if(p!=-1)
            cout<<citiesNames[p]<<" ";
    }
    cout<<"]"<<endl;
    cout<<"Distancia "<<dist[getCity("NA")]<<endl;

}

