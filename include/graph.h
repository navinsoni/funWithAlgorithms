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
    Node(int lab, int lev=-1, float dist=-1):label(lab), level(lev), distance(dist){}

    int getLevel() { return level; }
    int getLabel() { return label; }
    float getDistance() { return distance; }
	void setLevel(const int l) { level = l;}
	void setDistance(const float d) { distance = d;}

private:
    int label;
    int level;
    float distance;
};

class Edge
{
public:
	Edge(Node *n1, Node *n2, long long int wt = -1):nodes{n1,n2},weight(wt){}
	Node* getNode1() {return nodes[0];}
	Node* getNode2() {return nodes[1];}
	long long int getWeight() const {return weight;}

	bool operator< (Edge const &temp){
		if(getWeight() < temp.getWeight()) return true;
		return false;
	}
private:
	Node *nodes[2];
	long long int weight;
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
