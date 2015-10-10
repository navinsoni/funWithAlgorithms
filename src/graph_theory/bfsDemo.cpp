/*
* This demo uses bfs.h library from include directory
* The Bfs can be ordered/unordered. It can be specified
* by passing Bfs::State::ORDERED in Bfs constructor
* eg: Bfs(Bfs::State::ORDERED);
* by default graph is unordered.
* The value is -1 if the node cannot be reached from given node.
*/

#include "bfs.h"

int main(int argc, char* argv[])
{
	Bfs bfs = Bfs(Bfs::State::ORDERED);
	bfs.addNode(1);
	bfs.addNode(2);
	bfs.addNode(3);
	bfs.addNode(4);
	bfs.addNode(5);
	bfs.addNode(6);
	bfs.addNode(16);
	bfs.addNode(20);

	bfs.addEdge(1,2);
	bfs.addEdge(2,3);
	bfs.addEdge(3,4);
	bfs.addEdge(4,5);
	bfs.addEdge(5,6);
	bfs.addEdge(5,16);

	bfs.printNodes();
	bfs.printEdges();

	bfs.breadthFirstSearch(2);

    return 0;
}
