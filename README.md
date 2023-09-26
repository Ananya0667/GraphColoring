
# Project Title

The Cricket Tournament problem can be transformed into a graph coloring problem such that the nodes of the graph correspond to games to be played, and an edge between two nodes represents the games that cannot be scheduled together.
 Here, each color represents the set of games that can be scheduled together in a two-day span.


## Requirements

1. C++ compiler (C++11 or later)
2. Input file input.txt containing the number of teams (integer)
## Deployment

To deploy this project,
1. Compile the program:
a. for Windows:
    g++ software_final.cpp -o graph_coloring
    
b. For MAC: 
    clang++ --std=c++17 software_final.cpp -o graph_coloring
2. Run the program:
    ./graph_coloring

3. The program reads the number of teams from the input.txt file.

4. Returns a schedule for the tournament.


## Input Format
The program expects the number of teams to be provided in the input.txt file. 
The input file should contain a single integer representing the number of teams. 

## Input.txt file
4




## Output

The program returns a schedule for the cricket tournament.
1. Each line contains a list of pairs of teams with the first team being the home team and the
second team being the away team. 

2. If no games are scheduled on a given day, the corresponding line is kept blank.

## Sample Output
```plaintext
(1 2); (3 4)

(1 3); (2 4)

(1 4); (2 3)

(2 1); (4 3)

(3 1); (4 2)

(3 2); (4 1)