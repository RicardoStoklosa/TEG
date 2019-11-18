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

int dijkstra(int start, vector< Edge > adj[],int pessoas){
    int dist[NUM_CITIES];
    Flight path[NUM_CITIES];
    Edge *pathEdges[NUM_CITIES];
    bool mark[NUM_CITIES];

    for(int i=0; i<NUM_CITIES; i++){
        path[i].node=-1;
        path[i].flow=INF;
        dist[i] =INF;
    }
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

        for(Edge &edge : adj[v]){

            int to = edge.node;
            if((dist[v]+edge.cost)<dist[to] && edge.flow>0 && (edge.departure-pathEdges[v]->arrival)>=60){
                dist[to]=dist[v]+edge.cost;
                path[to]={v,edge.flow};
                pathEdges[to]=&edge;
            }
        }
    }

    vector<int> pathe;
    int minFlow=INF;
    int t=getCity("NA");
    for (int v = t; v != getCity("SP"); v = path[v].node){
        pathe.push_back(v);
        if(path[v].flow<minFlow)
            minFlow=path[v].flow;
    }
    pathe.push_back(getCity("SP"));

    reverse(pathe.begin(), pathe.end());
    if(minFlow>pessoas){
        minFlow=pessoas;
    }
    cout<<">>"<<minFlow<<" pessoas "<<endl;
    for(int p:pathe){
        if(p!=getCity("SP")){
            pathEdges[p]->flow-=minFlow;
            cout<<"[ "<<citiesNames[p]<<" "
                << pathEdges[p]->departure<<" "
                << pathEdges[p]->arrival<<" "
                << pathEdges[p]->cost<<" "
                <<"] "<<endl;
        }
    }
    cout<<"Custo total "<<dist[getCity("NA")]<<endl;
    return minFlow;

}

