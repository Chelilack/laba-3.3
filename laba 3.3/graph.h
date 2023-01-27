#pragma once
#include "ArraySequence.h"
#include "Sequence.h"
#include "Errors.h"
#include <typeinfo>
template <typename T>
class Vertex;
template <typename T>
class Edge
{
private:
    Vertex<T>* start;
    Vertex<T>* destination;
    double weight;

public:
    Edge() : start(start), destination(destination), weight(weight) {}
    Edge(Vertex<T>* start, Vertex<T>* destination, double weight) : start(start), destination(destination), weight(weight) {}

public:
    Vertex<T>* GetStart()
    {
        return this->start;
    }

    Vertex<T>* GetDestination()
    {
        return this->destination;
    }

    double GetWeight()
    {
        return this->weight;
    }
};
template <typename T>
class Vertex 
{
private:
    T value;
    Sequence<Edge<T>>* edges;

public:
    Vertex(T value, Sequence<Edge<T>>* edges) : value(value), edges(edges) {}
    Vertex(T value) : value(value), edges(new ArraySequence<Edge<T>>()) {}
    Sequence<Edge<T>>* GetEdges()
    {
        return this->edges;
    }

    T GetValue()
    {
        return this->value;
    }

    void SetValue(T value)
    {
        this->value = value;
    }

    void AddConnectedVertex(Vertex<T>* vert, double weight = -1)
    {
        this->edges->Append(*(new Edge<T>(vert, this, weight)));
    }
};

template <typename T>
struct InfoVertex
{
    T value;
    Sequence<T>* connectedVerts;
};
template <typename T>
struct ConnectedVerts
{
    T value;
    double weight;
};
template <typename T>
struct InfoVertexWeight
{
    T value;
    Sequence<ConnectedVerts<T>>* connectedVerts;
};


template <class T>
class Graph
{
private:
    Sequence<Vertex<T>*>* vertexes;
    bool oriented;
    bool weighted;

public:
    Graph()
    {
        this->vertexes = new ArraySequence<Vertex<T>*>();
    }
    Graph(Sequence<InfoVertex<T>>* graph, bool oriented) : oriented(oriented), weighted(false)
    {
        vertexes = new ArraySequence<Vertex<T>*>();
        for (size_t i = 0; i < graph->GetLength(); i++)
            this->AddVertex(graph->Get(i).value, graph->Get(i).connectedVerts);
    }
    Graph(Sequence<InfoVertexWeight<T>>* graph, bool oriented) : oriented(oriented), weighted(true)
    {
        vertexes = new ArraySequence<Vertex<T>*>();
        for (int i = 0; i < graph->GetLength(); i++) {
            this->AddVertexWeighted(graph->Get(i).value, graph->Get(i).connectedVerts);
        }
    }
    ~Graph()
    {
        delete vertexes;
    }

public:
    Sequence<Vertex<T>*>* GetVertexes() const
    {
        return this->vertexes;
    }

    bool IsWeighted() const
    {
        return this->weighted;
    } 
    bool IsOriented() const
    {
        return this->oriented;
    }
    void AddVertex(T value, Sequence<T>* connectedVerts);
    void AddVertexWeighted(T value, Sequence<ConnectedVerts<T>>* connectedVerts);
    void AddEdge(T value1, T value2, int weight=-1);
    void DeleteVertex(T value);
    void DeleteEdge(T value1, T value2);
    Vertex<T>* GetVertexByValue(T value);
    void PrintOut();
private:
    bool IsNewVertex(Vertex<T>* v, Vertex<T>* newV, int indexInGraph = -1)
    {
        int i = 0;
        if (indexInGraph != -1) i = indexInGraph;
        for (i; i < this->vertexes->GetLength(); i++)
            if (this->vertexes->Get(i)->GetValue() == v->GetValue())
                for (int j = 0; j < this->vertexes->Get(i)->GetEdges()->GetLength(); j++)
                    if (this->vertexes->Get(i)->GetEdges()->Get(j).GetStart()->GetValue() == newV->GetValue())
                        return false;
        return true;
    }

};
template<typename T>
void Graph<T>:: AddVertex(T value, Sequence<T>* connectedVerts)
{
    Vertex<T>* newVertex = 0;
    bool findVertex = false;
    for (int k = 0; k < this->vertexes->GetLength(); k++) {
        if (this->vertexes->Get(k)->GetValue() == value) {
            newVertex = this->vertexes->Get(k);
            findVertex = true;
        }
    }
    if (!findVertex) {
        newVertex = new Vertex<T>(value);
        this->vertexes->Append(newVertex);
    }
    for (int i = 0; i < connectedVerts->GetLength(); i++) {
        bool addVertex = false;
        for (int j = 0; j < this->vertexes->GetLength(); j++) {
            if (this->vertexes->Get(j)->GetValue() == connectedVerts->Get(i)) {
                if (!this->oriented and IsNewVertex(this->vertexes->Get(j), newVertex, j)) {
                    this->vertexes->Get(j)->AddConnectedVertex(newVertex);
                }
                if (IsNewVertex(newVertex, this->vertexes->Get(j), j)) {
                    newVertex->AddConnectedVertex(this->vertexes->Get(j));
                }
                addVertex = true;
                break;
            }
        }
        if (!addVertex) {
            auto vertexes = new Vertex<T>(connectedVerts->Get(i));
            this->vertexes->Append(vertexes);
            if (!this->oriented) {
                vertexes->AddConnectedVertex(newVertex);
            }
            newVertex->AddConnectedVertex(vertexes);
        }

    }
}

template<typename T>
void Graph<T>:: AddVertexWeighted(T value, Sequence<ConnectedVerts<T>>* connectedVerts)
{
    Vertex<T>* newVertex = 0;
    bool findVertex = false;
    for (int k = 0; k < this->vertexes->GetLength(); k++) {
        if (this->vertexes->Get(k)->GetValue() == value) {
            newVertex = this->vertexes->Get(k);
            findVertex = true;
        }
    }
    if (!findVertex) {
        newVertex = new Vertex<T>(value);
        vertexes->Append(newVertex);
    }
    for (int i = 0; i < connectedVerts->GetLength(); i++) {
        bool addVertex = false;
        for (int j = 0; j < this->vertexes->GetLength(); j++) {
            if (this->vertexes->Get(j)->GetValue() == connectedVerts->Get(i).value) {
                if (!this->oriented and IsNewVertex(vertexes->Get(j), newVertex, j)) vertexes->Get(j)->AddConnectedVertex(newVertex, connectedVerts->Get(i).weight);
                if (IsNewVertex(newVertex, vertexes->Get(j), j)) newVertex->AddConnectedVertex(vertexes->Get(j), connectedVerts->Get(i).weight);
                addVertex = true;
                break;
            }
        }
        if (!addVertex) {
            auto vert = new Vertex<T>(connectedVerts->Get(i).value);
            vertexes->Append(vert);
            if (!this->oriented) vert->AddConnectedVertex(newVertex, connectedVerts->Get(i).weight);
            newVertex->AddConnectedVertex(vert, connectedVerts->Get(i).weight);
        }

    }
}

template<typename T>
void Graph<T>::AddEdge(T value1, T value2, int weight)
{
    if (this->oriented) {
        for (int i = 0; i < this->vertexes->GetLength(); i++) {
            if (this->vertexes->Get(i)->GetValue() == value1) {
                this->vertexes->Get(i)->GetEdges()->Append(Edge<T>(this->GetVertexByValue(value2), this->vertexes->Get(i), weight));
                return;
            }
        }
    }
    else {
        for (int i = 0; i < this->vertexes->GetLength(); i++) {
            if (this->vertexes->Get(i)->GetValue() == value1) this->vertexes->Get(i)->GetEdges()->Append(Edge<T>(this->GetVertexByValue(value2), this->vertexes->Get(i), weight));
            if (this->vertexes->Get(i)->GetValue() == value2) this->vertexes->Get(i)->GetEdges()->Append(Edge<T>(this->GetVertexByValue(value1), this->vertexes->Get(i), weight));
        }
    }
}

template<typename T>
void Graph<T>::DeleteVertex(T value)
{
    auto vert = this->GetVertexByValue(value);
    for (int i = 0; i < vertexes->GetLength(); i++) {
        for (int j = 0; j < vertexes->Get(i)->GetEdges()->GetLength(); j++) {
            if (vertexes->Get(i)->GetEdges()->Get(j).GetStart() == vert || vertexes->Get(i)->GetEdges()->Get(j).GetDestination() == vert) {
                vertexes->Get(i)->GetEdges()->Remove(j);
                j--;
            }
        }
    }
    for (int i = 0; i < vertexes->GetLength(); i++) {
        if (vertexes->Get(i) == vert) {
            this->vertexes->Remove(i);
            return;
        }
    }
}
template<typename T>
void Graph<T>::DeleteEdge(T value1, T value2)
{
    auto vert1 = this->GetVertexByValue(value1);
    auto vert2 = this->GetVertexByValue(value2);
    for (int i = 0; i < vertexes->GetLength(); i++) {
        for (int j = 0; j < vertexes->Get(i)->GetEdges()->GetLength(); j++) {
            if (oriented) {
                if (vertexes->Get(i)->GetEdges()->Get(j).GetDestination() == vert1 and vertexes->Get(i)->GetEdges()->Get(j).GetStart() == vert2) {
                    vertexes->Get(i)->GetEdges()->Remove(j);
                    j--;
                }
            }
            else {
                if ((vertexes->Get(i)->GetEdges()->Get(j).GetStart() == vert1 and vertexes->Get(i)->GetEdges()->Get(j).GetDestination() == vert2) or (vertexes->Get(i)->GetEdges()->Get(j).GetDestination() == vert1 and vertexes->Get(i)->GetEdges()->Get(j).GetStart() == vert2)) {
                    vertexes->Get(i)->GetEdges()->Remove(j);
                    j--;
                }
            }
        }
    }
}
template<typename T>
 Vertex<T>* Graph<T>:: GetVertexByValue(T value)
{
    for (int i = 0; i < vertexes->GetLength(); i++)
        if (value == vertexes->Get(i)->GetValue())
            return vertexes->Get(i);
     throw "No value";
}

 template<typename T>
 void Graph<T>::PrintOut() {
    for (int i = 0; i < this->vertexes->GetLength(); i++) {
        cout << this->vertexes->Get(i)->GetValue() << ": ";
        for (int j = 0; j < this->vertexes->Get(i)->GetEdges()->GetLength(); j++) {
            cout << this->vertexes->Get(i)->GetEdges()->Get(j).GetStart()->GetValue();
            if (1) {
                cout << "(" << this->vertexes->Get(i)->GetEdges()->Get(j).GetWeight() << ")";
            }
            cout << " ";
        }
        cout << endl;
    }
}