#include <iostream>
#include <fstream>
#include "graph.h" //"graph.h" contains the Graph class declaration.
using namespace std;

int main(){
    int teams;
     // Reading the number of teams from an input file.
    ifstream in("input.txt");
    in>>teams;
    // Calculating the number of nodes in our graph (teams x teams).
    int n=teams*teams;
    // Creating a graph object.
    Graph g(n,teams);
    //adjacency list creation
    for(int i=0; i<n; i++){
        int x = i/teams;    
        int y = i%teams;
        if(x==y)
                continue;  
        for(int j=i+1; j<n;j++){
            int a = j/teams;
            int b = j%teams;
            if(a==b) 
                continue;
            if(x==a || x==b || y==a || y==b)// Skip self-loop edges and edges involving the same teams.
                g.addEdge(i,j);  //adding edge if games cannot be scheduled together    
        }
    }
    //printing adjacency list 
    // g.printAdj();
    //calling our greedy method to color the graph
    g.greedy();
    return 0;
}