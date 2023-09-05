#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

using namespace std;

class Graph{
    private:
        int vertex;
        vector<list<int>> edges;
        vector<int> color;
        void DFS_visit(int);
    public:
        Graph(int);
        void print_edges();
        void add_edge(int,int);
        void DFS(int);
};

Graph::Graph(int v){
    vertex = v;
    edges.resize(vertex);
    // 0: white
    // 1: gray
    // 2: black
    color.resize(vertex);
}

void Graph::print_edges(){
    for(int i=0;i<vertex;i++){
        cout << i+1 << "\t";
        auto iter = edges[i].begin();
        // list<edge*>::iterator
        for(;iter!=edges[i].end();iter++){
            cout << "->" << (*iter)+1 ;
        }
        cout << endl;
    }
}

void Graph::add_edge(int from,int to){
    edges[from-1].push_back(to-1);
    // edges[to-1].push_back(new edge{from-1,weight}); // Undirected graph
}

//DFS函式
void Graph::DFS(int start){
    fill(color.begin(), color.end(), 0); //將所有節點都設成白色
    DFS_visit(start-1);
}

//DFS走訪函式
void Graph::DFS_visit(int vertex){
    cout << vertex + 1 << "->";
    color[vertex] = 1; //將目前走訪的點設成灰色
    
    // edges[vertex]
    for(auto iter=edges[vertex].begin(); iter!=edges[vertex].end(); iter++){
        int current = *iter;
        if(color[current] == 0){ //如果有點是白色的，表示可以繼續尋訪下去
            DFS_visit(current);
        }
    }
    color[vertex] = 2; //都尋訪完了，將此點設為黑色
}

int main(void){
    Graph graph(7);
    graph.add_edge(1,3);
    graph.add_edge(1,2);
    graph.add_edge(1,6);
    graph.add_edge(2,4);
    graph.add_edge(2,7);
    graph.add_edge(3,4);
    graph.add_edge(4,5);
    graph.add_edge(6,5);
    graph.add_edge(7,6);
    graph.add_edge(7,5);
    graph.DFS(1);
    // g.print_edges();

    return 0;
}