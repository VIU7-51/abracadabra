#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <list>
#include <assert.h>
using namespace std;

#define nameOfLink iterLinks->first
#define weightOfLink iterLinks->second
#define firstVertex vertices.begin()
#define lastVertex vertices.end()
#define firstLink (*iterVertex)->link.begin()
#define lastLink (*iterVertex)->link.end()
#define nameOfVertex (*iterVertex)->name
#define numberOfLinks (*iterVertex)->link.size()
#define INFINITY 1000
typedef int Array;

class Vertex {
public:
    Vertex();
    int name;
    map<int, int> link;
private:
    void createLinks();
};

Vertex::Vertex(){
    createLinks();
}

void Vertex::createLinks(){
    int randomWeight;
    int randomVertex;
    for (int randNumOfLinks = 0; randNumOfLinks<(1+rand()%3); randNumOfLinks++) {
        randomVertex = 1+rand()%5;
        randomWeight = 5+rand()%5;
        if (randomVertex == name) randomVertex = 1+rand()%5;
        link.insert(pair<int, int>(randomVertex,randomWeight));
    }
}

class Graph {
private:
    int cost, step, size;
    vector<Vertex*> vertices;
    vector<Vertex*>::iterator iterVertex;
    map<int, int>::iterator iterLinks;
    void createVert();
    inline bool hasVertexBeenSeen(list<int>, int);
    inline void fillArray(int*, int);
    inline void printPathsAndCosts(int, Array*, Array*);
public:
    Graph();
    void GreedyAlg(int startOfPath, int endOfPath);
    void Dijkstra(int start);
    void printGraph();
};

Graph::Graph() {
    createVert();
    size = vertices.size();
    cost = 0;
    step = 0;
}

void Graph::createVert(){
    Vertex *newVer = new Vertex;
    for (int i = 1; i<=5; i++){
        newVer->name = i;
        vertices.push_back(newVer);
        newVer = new Vertex;
    }
}
inline bool Graph::hasVertexBeenSeen(list<int> SV, int name){
    bool flag = false;
    list<int>::iterator iterSeen;
    iterSeen = SV.begin();
    for(int i = 0; i<SV.size(); i++){
        if(*iterSeen == name) flag = true;
        iterSeen++;
    }
    return flag;
}

inline void Graph::fillArray(int *array, int value){
    for(int i = 0; i!= vertices.size();i++) {
        array[i]=value;
    }
}

inline void Graph::printPathsAndCosts(int start, Array *paths, Array *costs){
    for(int i = 0; i<size;i++){
        cout<<"From "<<start<<" to "<<i+1<<": cost: "
        <<costs[i]<<" path through: "<<paths[i]<<endl;
    }
}

void Graph::Dijkstra(int start){
    assert(start<=size);

    list<Vertex*> unseenVertices;
    list<Vertex*>::iterator iterVertex;
    list<int> seenVertices;
    int weight;
    Array costs[size], paths[size];


    fillArray(costs, INFINITY);
    fillArray(paths, 0);
    costs[start-1]=0;
    paths[start-1]=start;

    unseenVertices.push_back(vertices[start-1]);
    iterVertex = unseenVertices.begin();
    while(!unseenVertices.empty()){
        seenVertices.push_back(nameOfVertex);
        weight = costs[nameOfVertex-1];

        iterLinks = firstLink;
        for (int i = 0; i < numberOfLinks; i++){
            if(start == nameOfLink){
                iterLinks++;
                continue;
            }
            if(costs[nameOfLink-1]>weight+weightOfLink){
                costs[nameOfLink-1]=weight+weightOfLink;
                paths[nameOfLink-1]=nameOfVertex;
            }
            if(!hasVertexBeenSeen(seenVertices, nameOfLink)){
                unseenVertices.push_back(vertices[nameOfLink-1]);
            }
            iterLinks++;
        }

        unseenVertices.erase(iterVertex);
        iterVertex = unseenVertices.begin();
    }
    printPathsAndCosts(start, paths, costs);
}

void Graph::GreedyAlg(int startOfPath, int endOfPath){
    assert(startOfPath < size && endOfPath < size);

    step++;
    for (iterVertex = firstVertex; iterVertex != lastVertex; iterVertex++)
        if (nameOfVertex == startOfPath) break;
    int compare;
    for (iterLinks = firstLink; iterLinks != lastLink; iterLinks++) {
        compare = weightOfLink;
        if (endOfPath == nameOfLink) {
            cost += weightOfLink;
            cout<<"Path to "<<endOfPath<<" costs "<<cost<<endl;
            step = 0; cost = 0;
            return;
        }
        if (weightOfLink <= compare) {
            startOfPath = nameOfLink;
            compare = weightOfLink;
        }
    }

    if (step>10) {
        cout<<"There's no such path";
        step = 0; cost = 0;
    }
    else {
       cost += compare;
        GreedyAlg(startOfPath, endOfPath);
    }
}

void Graph::printGraph() {
    for( iterVertex = firstVertex; iterVertex != lastVertex; iterVertex++) {
        cout<<nameOfVertex<<endl;
        for (iterLinks = firstLink; iterLinks != lastLink; iterLinks++)
            cout << "linked with: " << nameOfLink
             << " edge: " << weightOfLink << endl;
    }
}


int main()
{
    Graph g;
    g.printGraph();
    cout<<"\n Greedy Algorithm: \n";
    g.GreedyAlg(1, 2);
    cout<<"\n Dijkstra Algorithm: \n";
    g.Dijkstra(5);
    return 0;
}
