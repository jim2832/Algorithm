#include <iostream>
#include <limits>
#include <stdlib.h>

using namespace std;

class graph{
    private:
        int vertex;
        int **distance_matrix;
        int **predecessor_matrix;
    public:
        graph(int);
        void print_distance_matrix();
        void print_predecessor_matrix();
        void floyd_warshall();
        bool add_edge(int,int,int=1);
};

void graph::floyd_warshall(){
    for(int k=0;k<vertex;k++){
        for(int i=0;i<vertex;i++){
            for(int j=0;j<vertex;j++){
                if(distance_matrix[i][k]==numeric_limits<int>::max())
                    continue;
                else if(distance_matrix[k][j]==numeric_limits<int>::max())
                    continue;
                else if(distance_matrix[i][j]>distance_matrix[i][k]+distance_matrix[k][j]){
                    distance_matrix[i][j] = distance_matrix[i][k]+distance_matrix[k][j];
                    predecessor_matrix[i][j] = k;
                }
            }
        }
    }
}

graph::graph(int v){
    vertex = v;
    distance_matrix = (int**) malloc(sizeof(int*)*vertex);
    for(int i=0;i<vertex;i++)
        *(distance_matrix+i) = (int*) malloc(sizeof(int)*vertex);
    for(int i=0;i<vertex;i++){
        for(int j=0;j<vertex;j++){
            *(*(distance_matrix+i)+j) = (i==j)?0:numeric_limits<int>::max();
        }
    }
    predecessor_matrix = (int**) malloc(sizeof(int*)*vertex);
    for(int i=0;i<vertex;i++)
        *(predecessor_matrix+i) = (int*) malloc(sizeof(int)*vertex);
    for(int i=0;i<vertex;i++){
        for(int j=0;j<vertex;j++){
            *(*(predecessor_matrix+i)+j) = (i==j)?i:-1;
        }
    }
}

bool graph::add_edge(int i,int j,int weight){
    if(distance_matrix[i][j]==numeric_limits<int>::max()){
        *(*(distance_matrix+i)+j) = weight;
        *(*(predecessor_matrix+i)+j) = i;
    }
    else
        return false;
    return true;
}

void graph::print_distance_matrix(){
    for(int i=0;i<vertex;i++){
        for(int j=0;j<vertex;j++){
            if(*(*(distance_matrix+i)+j)==numeric_limits<int>::max())
                cout << "Inf\t";
            else
                cout << *(*(distance_matrix+i)+j) << "\t";
        }
        cout << endl;
    }
}

void graph::print_predecessor_matrix(){
    for(int i=0;i<vertex;i++){
        for(int j=0;j<vertex;j++){
            cout << *(*(predecessor_matrix+i)+j) << "\t";
        }
        cout << endl;
    }
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

    cout << "Distance Matrix......" << endl;
    g.print_distance_matrix();
    cout << "Predecessor Matrix......" << endl;
    g.print_predecessor_matrix();
    cout << "Floyd Warshall Algorithm......" << endl;
    g.floyd_warshall();
    cout << "Distance Matrix......" << endl;
    g.print_distance_matrix();
    cout << "Predecessor Matrix......" << endl;
    g.print_predecessor_matrix();

    return 0;
}