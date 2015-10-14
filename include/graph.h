#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <map>
#include <list>
#include <queue>
#include "edge.h"
#include "node.h"

using namespace std;

class Graph
{
public:

    enum State{
        ORDERED,
        UNORDERED
    };
    Graph(State s = State::UNORDERED):state(s){}

    ~Graph() {
        for (pair<int, Node * > var : map_node)
                delete var.second;
    };

    void addNode(int n);
    void addEdge(int n1, int n2, float dist=-1);
    void printNodes();
    void printEdges();
    State getState() { return state; }

protected:
	map <int, list<Edge> >& getGraph() { return graph; }
	map <int, Node * >& getMapNode() { return map_node; }

private:
    map <int, list<Edge> > graph;
    map <int, Node * > map_node;
    Graph::State state;
};

#endif //_GRAPH_H_
