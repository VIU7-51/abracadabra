#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
using namespace std;

#define nameOfLink iterLinks->first
#define weightOfLink iterLinks->second
#define firstVertex vertices.begin()
#define lastVertex vertices.end()
#define firstLink (*iterVertex)->link.begin()
#define lastLink (*iterVertex)->link.end()
#define nameOfVertex (*iterVertex)->name

class Vertex {
public:
    Vertex() { createLinks(); }
    char name;
    map<char, int> link;
private:
    void createLinks() {
        int randomWeight;
        char randomVertex;
        for (int randNumOfLinks = 0; randNumOfLinks<(1+rand()%5); randNumOfLinks++) {
            randomWeight = 1+rand()%10;
            randomVertex = 'A' + rand()%10;
            if (randomVertex == name) randomVertex = 'A' + rand()%10;
            link.insert(pair<char, int>(randomVertex,randomWeight));
        }
    }
};
class Graph {
private:
    vector<Vertex*> vertices;
    int cost, step;
    vector<Vertex*>::iterator iterVertex;
    map<char, int>::iterator iterLinks;

    void createVert() {
        Vertex *newVer = new Vertex;
        for (int i = 0; i<10; i++) {
            newVer->name = 'A' + i;
            vertices.push_back(newVer);
            newVer = new Vertex;
        }
    }

public:
    Graph();

    void GreedyAlg(char startOfPath, char endOfPath) {
        step++;
        for (iterVertex = firstVertex; iterVertex != lastVertex; iterVertex++)
            if (nameOfVertex == startOfPath) break;

        int compare;
        for (iterLinks = firstLink; iterLinks != lastLink; iterLinks++) {
            compare = weightOfLink;
            if (endOfPath == nameOfLink) {
                cost += weightOfLink;
                cout<<"Path to "<<endOfPath<<" costs "<<cost;
                return;
            }
            if (weightOfLink <= compare) {
                startOfPath = nameOfLink;
                compare = weightOfLink;
            }
        }

        if (step>10) {
            cout<<"There's no such path";
            step = 0;
        }
        else {
            cost += compare;
            GreedyAlg(startOfPath, endOfPath);
        }
    }

    void printGraph() {
        for( iterVertex = firstVertex; iterVertex != lastVertex; iterVertex++) {
            cout<<nameOfVertex<<endl;
            for (iterLinks = firstLink; iterLinks != lastLink; iterLinks++)
                cout << "linked with: " << nameOfLink
                 << " edge: " << weightOfLink << endl;
        }
    }
};

Graph::Graph() {
    createVert();
    cost = 0;
}


int main()
{
    Graph g;
    g.printGraph();
    g.GreedyAlg('A', 'B');
    return 0;
}
