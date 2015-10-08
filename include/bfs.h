#ifndef _BFS_H_
#define _BFS_H_

#include "graph.h"
#include <queue>

class Bfs: public Graph
{
public:
	Bfs(Graph::State s = State::UNORDERED):Graph(s){}
	void breadthFirstSearch(int n);

private:
	queue<Node *> bfsQueue;
};
#endif // _BFS_H_
