#ifndef _KRUSKALS_H_
#define _KRUSKALS_H_

#include "graph.h"
#include <queue>
#include <set>

class Kruskals: public Graph
{
public:
	Kruskals(Graph::State s = State::UNORDERED):Graph(s){}
	void minimumSpanningTreeWt();

private:
	queue<Node *> bfsQueue;
};
#endif // _KRUSKALS_H_
