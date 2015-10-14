#ifndef _EDGE_H_
#define _EDGE_H_

#include "node.h"
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

#endif // _EDGE_H_
