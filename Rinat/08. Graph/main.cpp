#include <iostream>
//#include <bits/stl_vector.h>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include "time.h"
#include "vertex.h"


using namespace std;

template <typename T>
std::string to_string(T value)
{
    std::ostringstream os ;
    os << value ;
    return os.str() ;
}

Vertex::Vertex(int id){
    this->id = id;
}

void Vertex::addEdge(Vertex *vertex, int distance){
    edges.push_back(new Edge(this, vertex, distance));
}

int Vertex::getId(){
    return id;
}

vector<Edge*> Vertex::getEdges(){
    return edges;
}

void Vertex::printEdges() {
    for (std::vector<Edge*>::size_type i = 0; i != edges.size(); i++){
        cout << "\t\t Edge " << i << " to vertex " << to_string(edges[i]->getDestination()->getId()) << " with distance " << to_string(edges[i]->getDistance()) << endl;
    }
}

void Vertex::setCost(int cost) {
    this->cost = cost;
}

void Vertex::setVisited(bool visited) {
    this->visited = visited;
}

bool Vertex::isVisited() {
    return visited;
}

int Vertex::getCost() {
    return cost;
}

int Vertex::getWeightForEdgeTo(int id){
    for (std::vector<Edge*>::size_type i = 0; i != edges.size(); i++){
        if(edges[i]->getDestination()->getId() == id)
            return edges[i]->getDistance();
    }
    return INFINITY;
}

string Vertex::printPath() {
    string result = "";
    for (int i = 0; i< this->path.size(); i++){
        result = result + to_string(this->path[i]->getId()) + " ";
    }
    return result;
}



Edge::Edge(Vertex *org, Vertex *dest, int dist){
    origin = org;
    destination = dest;
    distance = dist;
}

Vertex* Edge::getOrigin() {
    return origin;
}
Vertex* Edge::getDestination() {
    return destination;
}
int Edge::getDistance() {
    return distance;
}

class Graph{
public:
    Graph(bool);
    void findPathDijkstra();
    void findPathGreedy();
    void addVertex(int id);
    vector<Vertex*>::iterator vertIterator;
    int findNextNotVisited(){
        for (int i=0; i<this->vertices.size(); i++)
            if(!this->vertices[i]->isVisited())
                return this->vertices[i]->getId();
        return -1;
    }
    void print();
private:
    vector<Vertex*> vertices;

};

Graph::Graph(bool initWithRandom) {
    if(initWithRandom){
        srand(time(0));

        //for (int i = 0; i < (rand() % 15 + 5); i++){
        //Заполняем вектор вершин
        for (int i = 0; i < 15; i++){
            addVertex(i);
            //cout << "Adding vertex " << i << endl;
        }
        //Для каждой вершины создаем ребра
        for (std::vector<Vertex*>::size_type i=0; i != vertices.size(); i++){
            //int numEdges = rand() % 5 + 1;
            int numEdges = 2;
            //Кол-во ребер будет равно numEdges

                for (int j = 0; j< numEdges; j++ ){
                    if(vertices[i]->getEdges().size()>=numEdges)
                        break;
                    int id;
                    //Создаем случайные связи, но хотим убедиться, что вершина не соединяется сама с собой или с уже соединенной.
                    do{
                        id = rand() % (vertices.size()-1);
                    }
                    while (id == i || hasLink(vertices[i]->getEdges(), id));


                    int weight = rand() % 9 + 1;
                    vertices[i]->addEdge(vertices[id], weight);
                    vertices[id]->addEdge(vertices[i], weight);


                    //cout << "Adding edge from " << vertices[i]->getId() << " to " << id << " with weight " << weight << endl;
                }
        }

    }
}

bool hasLink(vector<Edge*> edges, int id){
    for(std::vector<Edge*>::size_type t = 0; t < edges.size(); t ++){
        if(edges[t]->getDestination()->getId() == id)
            return true;
    }
    return false;
}

void Graph::print() {
    cout << "Graph: \n";
    for (std::vector<Vertex*>::size_type i = 0; i != vertices.size(); i++){
        cout << "\tVertex " << vertices[i]->getId() << ":\n";
        vertices[i]->printEdges();

    }
}

void Graph::addVertex(int id) {

    Vertex* vertex = new Vertex(id);
    vertices.push_back(vertex);
}

void Graph::findPathDijkstra() {
    int u, index = 0;
    cout << "Finding path \n";
    //начальной вершине даем вес 0
    this->vertices[0]->setCost(0);
    this->vertices[0]->path.push_back(vertices[0]);

    for (int numVert = 0; numVert < this->vertices.size(); numVert++){
        //Берем вектор всех ребер текущей вершины

        vector<Edge*> thisEdges = this->vertices[index]->getEdges();
        cout << "Analyzing vertex " << to_string(index) << " with " << to_string(thisEdges.size()) << " edges" << endl;
        //Задаем начальное значение минимального расстояния
        int min = INFINITY;

        //Проходимся по всем связанным вершинам и расставляем метки (полные растояния)
        for(int i = 0; i<thisEdges.size(); i++){
            cout << "Analyzing edge " << to_string(i) << " to vertex " << to_string(thisEdges[i]->getDestination()->getId()) << endl;
            if(!thisEdges[i]->getDestination()->isVisited() &&      // Если вершина еще не посещена
                                                                    // и
                                                                    // (Длина ребра + метка текущей исходной вершины) меньше
                                                                    // уже назначенной метки для целевой вершины
                    (thisEdges[i]->getDistance() + thisEdges[i]->getOrigin()->getCost()< thisEdges[i]->getDestination()->getCost() )){
                //Присваеваем этой целевой вершине новую метку
                cout << "This vertex has not been seen yet. Previous cost: " << to_string(thisEdges[i]->getDestination()->getCost()) << endl;
                min = thisEdges[i]->getDistance() + thisEdges[i]->getOrigin()->getCost();
                thisEdges[i]->getDestination()->setCost(min);
                cout << "New cost for this vertex is " << to_string(min) << endl;
                // обновляем путь
                cout << "Previous path was " << thisEdges[i]->getDestination()->printPath();
                thisEdges[i]->getDestination()->path = thisEdges[i]->getOrigin()->path;
                thisEdges[i]->getDestination()->path.push_back(thisEdges[i]->getDestination());
                cout << " new path is " << thisEdges[i]->getDestination()->printPath() << endl;
            } else {
                cout << "This vertex has been seen, and the cost is " << to_string(thisEdges[i]->getDestination()->getCost()) << endl;

            }
        }
        //Отмечаем текущую вершину как пройденную
        vertices[index]->setVisited(true);
        cout << "Vertex " << to_string(vertices[index]->getId()) << " is now visited" << endl;
        // Опять задаем начальное значение минимального расстояния
        min = INFINITY;
        cout << "Finding the next closest vertex" << endl;
        //Проходимся по всем связанным вершинам и находим вершину с минимальным расстоянием
        for(int i = 0; i<thisEdges.size(); i++){
            cout << "Analyzing edge to " << to_string(thisEdges[i]->getDestination()->getId());
            cout << ", its value is " << to_string(thisEdges[i]->getDestination()->getCost()) << endl;
            if (!thisEdges[i]->getDestination()->isVisited() &&             // Если вершина еще не посещена и
                    (thisEdges[i]->getDestination()->getCost()) <= min){    // если метка вершины меньше всех предыдущих
                //обновляем минимум
                cout << "It was not visited and its value is less than current min " << to_string(min)<< endl;
                min = thisEdges[i]->getDistance() + thisEdges[i]->getOrigin()->getCost();
                //сохраняем номер вершины
                index = thisEdges[i]->getDestination()->getId();
                cout << "New min is " << to_string(min) << endl;
            } else {
                cout << "It was visited or its value is more than current min " << to_string(min) << endl;
            }

        }
        if(min < INFINITY)
            cout << "Next vertex would be " << to_string(index) << endl;
        else {
            cout << "This is dead end. Finding next not visited vertex." << endl;
            index = findNextNotVisited();
            if(index!= -1)
                cout << "Next vertex would be " << to_string(index) << endl;
            else
                cout << "All vertices have been visited." << endl;
        }

        //в следующей итерации обрабатываем вершину с минимальной меткой.
    }
    cout << "Finished finding paths"<< endl << endl << "Printing results:" << endl;
    for (int i = 1; i<this->vertices.size(); i++){
        if(this->vertices[i]->getCost() < INFINITY){
            cout << "From start to vertex " << this->vertices[i]->getId() << " cost is " <<this->vertices[i]->getCost() << " via " << this->vertices[i]->printPath() << endl;

        } else {
            cout << "No path from start to vertex " << this->vertices[i]->getId() << endl;
        }

    }

}

void Graph::findPathGreedy() {

}

int main() {

    Graph g(true);
    g.print();
    g.findPathDijkstra();
    system("pause");
    return 0;
}