#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class Graph{
    public:
        Graph(int); //建構式
        void print_matrix(); //印出 adjacency matrix
        bool add_edge(int, int, int=1); //新增一條邊(from, to, weight)

    private:
        int vertex; //紀錄節點
        int **matrix; //二維的矩陣(用指標實作)
        //也可以將 **matrix 設定成 vector<vector<int>> matrix
};

//建構式
Graph::Graph(int v){
    vertex = v;

    //初始化二維陣列(是一個 v*v 的二維矩陣)
    matrix = (int**) malloc(sizeof(int*) * vertex);

    //初始化每個一維陣列
    for(int i=0; i<vertex; i++){
        *(matrix + i) = (int*) calloc(vertex, sizeof(int));
    }

    // matrix.resize(vertex, vector<int> (vertex, 0));
}

//印出 adjacency matrix
void Graph::print_matrix(){
    cout << "Vertex\t";
    for(int i=0; i<vertex; i++){
        cout << i+1 << "\t";
    }
    cout << endl;

    for(int i=0; i<vertex; i++){
        cout << i+1 << "\t";
        for(int j=0; j<vertex; j++){
            cout << *((*(matrix + i) + j)) << "\t";
            // cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

//新增一條邊(from, to, weight) -> 若新增成功回傳true，否則回傳false
bool Graph::add_edge(int from, int to, int weight){
    //不能新增已存在的邊
    if(matrix[from-1][to-1]){
        cout << "Error! This edge has already existed!" << endl;
        return false;
    }
    else{
        matrix[from-1][to-1] = weight;
        matrix[to-1][from-1] = weight; // undirected graph
        return true;
    }
}

int main(void){
    Graph graph(10);
    graph.add_edge(1, 5);
    graph.add_edge(2, 6);
    graph.add_edge(5, 5);
    graph.add_edge(3, 5);
    graph.add_edge(10, 10);

    graph.print_matrix();

    return 0;
}