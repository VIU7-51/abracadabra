//
// Created by rinat.maksutov on 08.12.2015.
//


#include <vector>
#include <string>

#ifndef INC_08_GRAPH_VERTEXT_H
#define INC_08_GRAPH_VERTEXT_H

#endif //INC_08_GRAPH_VERTEXT_H

#define INFINITY 1000
using namespace std;
class Edge;
class Vertex{
public:
    Vertex(int id);
    void addEdge(Vertex *vertex, int distance);
    void printEdges();
    int getId();
    void setVisited(bool);
    void setCost(int);
    bool isVisited();
    int getCost();
    int getWeightForEdgeTo(int id);

    vector<Edge*> getEdges();
    vector<Vertex*> path;
    string printPath();

private:
    int id;
    bool visited = false;
    int cost = INFINITY;
    vector<Edge*> edges;

};

class Edge{
public:
    Edge(Vertex *org, Vertex *dest, int dist);
    Vertex* getOrigin();
    Vertex* getDestination();
    int getDistance();
private:
    Vertex* origin;
    Vertex* destination;
    int distance;
};

bool hasLink(vector<Edge*> edges, int id);