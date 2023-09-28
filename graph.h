#include <iostream>
#include "list.h" //"list.h" contains the List class declaration.
using namespace std;

class Graph{
private:
    int nodes; // Number of vertices
    List<int> *l; // Adjacency list
    int teams;  // Number of teams

public:
    // Constructor: Initialize the graph with the specified number of nodes and teams.
    Graph(int n,int teams) : nodes(n), teams(teams){
        l = new List<int>[nodes];
    }

    // Adding an edge between node i and node j
    void addEdge(int i, int j){
        l[i].push_back(j);
        l[j].push_back(i);    
    }
    // Printing the adjacency matrix
    void printAdj(){
        for(int i=0;i<nodes;i++){
            cout<< i <<" ->";
            l[i].print();
            cout<<endl;
        }
    }
    // Greedy method to color the graph
    void greedy(){
        List<int> color(nodes); // List containing color assigned to each node
        for(int i=1; i<nodes;i++){
            color.set(i,-1);// Initially setting all colors to -1, i.e., no color is assigned
        }

    // Temporary list to keep track of available colors for assignment.
    // It will be reset for every vertex.
    List<bool> temp(nodes);  
       
    for(int u=1; u<nodes;u++){
    // Loop for all vertices except the first.
        int s=l[u].getSize();
        for(int i=0; i<s; i++){
            int nbr = l[u].get(i);// Check neighbors
            if(color.get(nbr) != -1){
                // If color[i] != -1, that means that vertex is colored.
                temp.set(color.get(nbr),true);// Temp will be set to 1 for already used color. 
            }
        }
        int clr = -1;
        //find first avaliable color
        for(int i=0; i< nodes; i++){
            if(temp.get(i) == false){
                clr =i; //Color not yet used
                break;
            }
        }
        color.set(u,clr);// Assign color to the vertex which was unused

        // Reset the temp list which is temporary for the next vertex/vertices
        // for(int i=0; i<nodes;i++){
        //     temp.set(i,false);
        // }

         //reset the temp list for next vertix
            for(int i=0; i<nodes;i++){
                temp.set(i,false);
            }
    }

    //Printing which color is assigned to which vertex
    // for(int i=0; i<nodes;i++){
    //     cout << "Vertex " << i << " ->  Color "<< color.get(i) << endl;;
    // }
        
    //After assignment of colors to all the vertices,
    //Finding the total number of distinct colors used
    int numColors = 0;
    for (int i = 0; i < nodes; i++) {
        if (color.get(i) > numColors) {
            numColors = color.get(i);
        }
    }
    numColors++;//Increment by 1 since colors are 0-based
    // cout << "Number of colors used: " << numColors << endl;

    bool check;
    int c=1;
    for(int i = 0; i < numColors; i++){
        int targetcolour=i;
        check=false;
    for (int j=1;j<nodes;j++) {
        if(j==((teams*c)+c)){//since graph is of size teams*teams, we dont have to consider 
            c++;//games played between same team being the home team and away team. 
            continue;    
        }
        if (color.get(j) == targetcolour) {
            // cout<<j<<" ";
            int x=j/teams;
            int y=j%teams;
            if(check){
            cout<<"; "<<"("<<x+1<<" "<<y+1<<")";
            check=true;
            }
            else{
            cout<<"("<<x+1<<" "<<y+1<<")";
            check=true;    
            }
        }
    }
    if(i==numColors-1)
        break;
    else
        cout<<endl<<endl;
} 

}

// Destructor: Free dynamically allocated memory.
~Graph(){
    delete[] l;
}        
};

    