//列出圖裡所有SCC的組合

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <stack>
#include <algorithm>
using namespace std;

class Graph{
    private:
        int vertex;
        vector<list<int>> edges;
        vector<list<int>> edges_reverse; //反向邊的圖
        vector<int> color;
        stack<int> topological_sort;
        void DFS_visit(int);
        void DFS_visit_topological(int);
        void DFS_SCC(int);

    public:
        Graph(int);
        void print_edges();
        void add_edge(int, int);
        void DFS(int);
        void get_topological_sort(int=1);
        void print_SCC();
};

Graph::Graph(int v){
    vertex = v;
    edges.resize(vertex);
    edges_reverse.resize(vertex);
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
        for(; iter!=edges[i].end(); iter++){
            cout << "->" << (*iter)+1;
        }
        cout << endl;
    }
}

void Graph::add_edge(int from, int to){
    edges[from-1].push_back(to-1);
    edges_reverse[to-1].push_back(from-1);
    //edges[to-1].push_back(new edge{from-1,weight}); // Undirected graph
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

//拓樸排序
void Graph::get_topological_sort(int start){
    start--;
    fill(color.begin(), color.end(), 0); //將所有節點都設成白色
    DFS_visit_topological(start);
    
    for(int i=0;i<vertex;i++){
        if(color[i]==0){
            DFS_visit_topological(i);
        }
    }
}

//拓樸走訪函式
void Graph::DFS_visit_topological(int vertex){
    color[vertex] = 1; //將目前走訪的點設成灰色
    
    // edges[vertex]
    for(auto iter=edges[vertex].begin(); iter!=edges[vertex].end(); iter++){
        int current = *iter;
        if(color[current] == 0){ //如果有點是白色的，表示可以繼續尋訪下去
            DFS_visit_topological(current);
        }
    }
    color[vertex] = 2; //都尋訪完了，將此點設為黑色
    topological_sort.push(vertex);
}

//找出圖中所有的SCC
void Graph::print_SCC(){
    get_topological_sort(); //依照離開的順序，依序放到stack內
    fill(color.begin(), color.end(), 0); //將所有節點都設成白色

    // topological_sort
    // 根據這個順序，在反向圖上做DFS
    int SCC = 1;

    while(!topological_sort.empty()){
        int current = topological_sort.top();
        topological_sort.pop();
        if(color[current] == 0){
            cout << "SCC #" << SCC << ": ";
            DFS_SCC(current);
            SCC++;
            cout << endl;
        }
    }
}

//對SCC的所有點做DFS
void Graph::DFS_SCC(int vertex){
    color[vertex] = 1; //將目前走訪的點設成灰色
    cout << char(vertex + 65) << " ";
    
    // edges_reverse[vertex]
    for(auto iter=edges_reverse[vertex].begin(); iter!=edges_reverse[vertex].end(); iter++){
        int current = *iter;
        if(color[current] == 0){ //如果有點是白色的，表示可以繼續尋訪下去
            DFS_SCC(current);
        }
    }
    color[vertex] = 2; //都尋訪完了，將此點設為黑色
}

int main(void){
    Graph graph(7);
    graph.add_edge(1,2);
    graph.add_edge(1,3);
    graph.add_edge(2,1);
    graph.add_edge(3,2);
    graph.add_edge(3,5);
    graph.add_edge(3,6);
    graph.add_edge(4,6);
    graph.add_edge(4,7);
    graph.add_edge(5,7);
    graph.add_edge(6,4);
    graph.add_edge(7,6);

    // graph.DFS(1);
    // graph.get_topological_sort(1);
    // g.print_edges();
    graph.print_SCC();

    return 0;
}