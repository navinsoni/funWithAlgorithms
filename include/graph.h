#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <map>
#include <list>
#include <queue>

using namespace std;

class Node
{
public:
    Node(int lab, int lev=-1, int dist=-1):label(lab), level(lev), distance(dist){}

    int getLevel() { return level; }
    int getLabel() { return label; }
    int getDistance() { return distance; }
	void setLevel(const int l) { level = l;}
	void setDistance(const int d) { distance = d;}

private:
    int label;
    int level;
    int distance;
};

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
    void addEdge(int n1, int n2);
    void printNodes();
    void printEdges();
    State getState() { return state; }

protected:
	map <int, list<int> >& getGraph() { return graph; }
	map <int, Node * >& getMapNode() { return map_node; }

private:
    map <int, list<int> > graph;
    map <int, Node * > map_node;
    Graph::State state;
};

#endif //_GRAPH_H_