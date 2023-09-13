#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <limits>

using namespace std;

typedef struct{
    int index;
    int predecessor;
    float distance;
}vertex;

typedef struct{
    int to;
    int weight;
}edge;

class graph{
    private:
        int number_vertex;
        unordered_map<int,int> color;
        unordered_map<int,float> distance;
        unordered_map<int,int> predecessor;
        stack<int> topological_sort;
        vector< list<edge*> > edges;
        void DFS_visit(int);
        bool relax(int,int,float);
        void initialize_shortest_path(int);
        
    public:
        graph(int);
        void Dijkstra(int);
        void DAG(int);
        bool Bellman_Ford(int);
        bool SPFA(int);
        void print_edges();
        void print_path(int);
        void add_edge(int,int,int=1);
        void BFS(int);
        void DFS(int);
        vector<int> shortest_path_BFS(int);
        void print_shortest_path();
};

class compare{
    public:
        bool operator()(vertex* n1,vertex* n2){
            return n1->distance > n2->distance;
        }
};

void graph::print_shortest_path(){
    cout << endl;
    for(auto data:distance){
        cout << "Point #" << data.first;
        cout << ", Distance:" << data.second << endl;
    }
}

void graph::DAG(int initial){
    initialize_shortest_path(initial);
    DFS(initial);
    cout << "Topological sort:";
    while(!topological_sort.empty()){
        int index_now = topological_sort.top();
        cout << index_now << " ";
        topological_sort.pop();
        list<edge*>::iterator it=edges[index_now].begin();
        for(it;it!=edges[index_now].end();it++){
            relax(index_now,(*it)->to,(*it)->weight);
        }
    }
    cout << endl;
}

void graph::Dijkstra(int initial){
    priority_queue<vertex*, vector<vertex*>, compare> candidates;
    unordered_set<int> already_shortest;
    vertex* vertex_now;
    initialize_shortest_path(initial);

    candidates.push(new vertex{initial,-1,0});
    while(!candidates.empty()){
        int index_now = candidates.top()->index;
        if(already_shortest.find(index_now)!=already_shortest.end()){
            candidates.pop();
            continue;
        }
        already_shortest.insert(index_now);
        list<edge*>::iterator it=edges[index_now].begin();
        for(it;it!=edges[index_now].end();it++){
            bool relaxed = relax(index_now,(*it)->to,(*it)->weight);
            if(relaxed)
                candidates.push(new vertex{(*it)->to,predecessor[(*it)->to],distance[(*it)->to]});
        }
        candidates.pop();
    }
}


bool graph::SPFA(int initial){
    initialize_shortest_path(initial);
    queue<int> candidate;
    unordered_map<int,int> update;
    for(int i=0;i<number_vertex;i++)
        update[i] = 0;
    candidate.push(initial);
    while(!candidate.empty()){
        int vertex_now = candidate.front();
        candidate.pop();
        list<edge*>::iterator it=edges[vertex_now].begin();
        for(;it!=edges[vertex_now].end();it++){
            bool relaxed = relax(vertex_now,(*it)->to,(*it)->weight);
            if(relaxed && (*it)->to!=candidate.back()){
                update[(*it)->to] += 1;
                if(update[(*it)->to]==number_vertex)
                    return false;
                candidate.push((*it)->to);
            }
        }
    }
    return true;
}

bool graph::Bellman_Ford(int initial){
    initialize_shortest_path(initial);
    list<edge*>::iterator it;
    for(int i=0;i<number_vertex-1;i++){
        for(int j=0;j<number_vertex;j++){
            // all edges of edges[j]
            for(it=edges[j].begin();it!=edges[j].end();it++){
                relax(j,(*it)->to,(*it)->weight);
            }
        }
    }
    // Determine there is negative cycle or not.
    // all edges
    for(int j=0;j<number_vertex;j++){
        for(it=edges[j].begin();it!=edges[j].end();it++){
            if(distance[(*it)->to]>distance[j]+(*it)->weight)
                return false;
        }
    }
    return true;
}

void graph::print_path(int v){
    if(distance.find(v)!=distance.end()){
        cout << "Distance:" << distance[v] << endl;
        stack<int> path;
        path.push(v);
        while(predecessor[v]!=-1){
            path.push(predecessor[v]);
            v = predecessor[v];
        }
        cout << "Path:";
        while(!path.empty()){
            int vertex_now = path.top();
            path.pop();
            cout << vertex_now << " ";
        }
        cout << endl;
    }
}

void graph::initialize_shortest_path(int inititial){
    distance.clear();
    predecessor.clear();
    for(int i=0;i<number_vertex;i++){
        distance[i] = numeric_limits<float>::max();
        predecessor[i] = -1;
    }
    distance[inititial] = 0;
}

bool graph::relax(int from,int to,float weight){
    if(distance[to]>distance[from]+weight){
        distance[to] = distance[from]+weight;
        predecessor[to] = from;
        return true;
    }
    return false;
}

void graph::DFS(int N){
    topological_sort = stack<int>();
    cout << "DFS path:";
    // 0:white, 1:gray, 2:black
    for(int i=0;i<number_vertex;i++)
        color[i] = 0;
    DFS_visit(N);
    cout << endl;
}

void graph::DFS_visit(int N){
    cout << N << " ";
    color[N] = 1;
    list<edge*>::iterator it=edges[N].begin();
    for(it;it!=edges[N].end();it++){
        if(color[(*it)->to]==0) // White
            DFS_visit((*it)->to);
    }
    topological_sort.push(N);
    color[N] = 2;
}

// It is not true, if it is weighted edge!!!
vector<int> graph::shortest_path_BFS(int N){
    vector<int> shortest_distance;
    shortest_distance.resize(number_vertex);
    for(int i=0;i<number_vertex;i++)
        shortest_distance[i] = numeric_limits<int>::max();

    cout << "BFS path:";
    // 0:white, 1:gray, 2:black
    for(int i=0;i<number_vertex;i++)
        color[i] = 0;

    queue<int> path;
    path.push(N);
    color[N] = 1;
    shortest_distance[N] = 0;
    while(!path.empty()){
        int vertex_now = path.front();
        cout << vertex_now << " ";
        path.pop();
        list<edge*>::iterator it=edges[vertex_now].begin();
        for(it;it!=edges[vertex_now].end();it++){
            if(color[(*it)->to]==0){
                // White
                path.push((*it)->to);
                int minimal_distance = min(shortest_distance[(*it)->to],shortest_distance[vertex_now]+(*it)->weight);
                shortest_distance[(*it)->to] = minimal_distance;
            }
            color[(*it)->to] = 1;
        }
        color[vertex_now] = 2;
    }
    return shortest_distance;
}

void graph::BFS(int N){
    cout << "BFS path:";
    // 0:white, 1:gray, 2:black
    for(int i=0;i<number_vertex;i++)
        color[i] = 0;

    queue<int> path;
    path.push(N);
    color[N] = 1;
    while(!path.empty()){
        int vertex_now = path.front();
        cout << vertex_now << " ";
        path.pop();
        list<edge*>::iterator it=edges[vertex_now].begin();
        for(it;it!=edges[vertex_now].end();it++){
            if(color[(*it)->to]==0) // White
                path.push((*it)->to);
            color[(*it)->to] = 1;
        }
        color[vertex_now] = 2;
    }
}

graph::graph(int N){
    number_vertex = N;
    edges.resize(number_vertex);
}

void graph::print_edges(){
    for(int i=0;i<number_vertex;i++){
        cout << i << ":";
        list<edge*>::iterator it=edges[i].begin();
        for(it;it!=edges[i].end();it++)
            cout << (*it)->to << "\t";
        cout << endl;
    }
}

void graph::add_edge(int i,int j,int weight){
    edges[i].push_back(new edge{j,weight});
    edges[j].push_back(new edge{i,weight});
}

int main(){
    graph g(7);
    g.add_edge(0,1,20);
    g.add_edge(0,2,10);
    g.add_edge(0,3,15);
    g.add_edge(1,4,10);
    g.add_edge(2,4,10);
    g.add_edge(2,3,10);
    g.add_edge(2,5,5);
    g.add_edge(3,6,25);
    g.add_edge(5,6,10);
    g.add_edge(4,6,20);
    // g.Dijkstra(0);
    g.SPFA(0);
    g.print_path(6);

    // g.print_edges();
    // g.BFS(0);
    // g.DFS(0);
    bool negative_cycle = !g.Bellman_Ford(0);
    if(negative_cycle)
        cout << "\nError! Negative cycle";
    else
        g.print_shortest_path();
    /*
    vector<int> shortest_path = g.shortest_path(0);
    cout << "\nShortest distance: " << endl;
    for(int i=0;i<shortest_path.size();i++)
        cout << shortest_path_BFS[i] << " ";
    */
    return 0;
}