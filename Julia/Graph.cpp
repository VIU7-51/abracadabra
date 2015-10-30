#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
using namespace std;

#define nameOfLink iterLinks->first
#define weightOfLink iterLinks->second
#define firstVertice vertices.begin()
#define lastVertice vertices.end()
#define firstLink (*iterVertice)->link.begin()
#define lastLink (*iterVertice)->link.end()
#define nameOfVertice (*iterVertice)->name

class Vertice {
public:
    Vertice() { createLinks(); }
    char name;
    map<char, int> link;
private:
    void createLinks() {
        int randomWeight;
        char randomVertice;
        for (int randNumOfLinks = 0; randNumOfLinks<(1+rand()%5); randNumOfLinks++) {
            randomWeight = 1+rand()%10;
            randomVertice = 'A' + rand()%10;
            if (randomVertice == name) randomVertice = 'A' + rand()%10;
            link.insert(pair<char, int>(randomVertice,randomWeight));
        }
    }
};
class Graph {
private:
    vector<Vertice*> vertices;
    int cost, step;
    vector<Vertice*>::iterator iterVertice;
    map<char, int>::iterator iterLinks;

    void createVert() {
        Vertice *newVer = new Vertice;
        for (int i = 0; i<10; i++) {
            newVer->name = 'A' + i;
            vertices.push_back(newVer);
            newVer = new Vertice;
        }
    }

public:
    Graph();

    void GreedyAlg(char startOfPath, char endOfPath) {
        step++;
        for (iterVertice = firstVertice; iterVertice != lastVertice; iterVertice++)
            if (nameOfVertice == startOfPath) break;

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
        for( iterVertice = firstVertice; iterVertice != lastVertice; iterVertice++) {
            cout<<nameOfVertice<<endl;
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
