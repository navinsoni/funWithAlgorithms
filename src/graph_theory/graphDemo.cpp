/*
* This demo uses graph.h library from include directory
* The Graph can be ordered/unordered. It can be specified
* by passing Graph::State::ORDERED in Graph constructor
* eg: Graph(Graph::State::ORDERED);
* by default graph is unordered.
*/

#include "graph.h"

int main(int argc, char* argv[])
{
	Graph graph = Graph();
	graph.addNode(1);
	graph.addNode(2);
	graph.addNode(3);
	graph.addNode(4);
	graph.addNode(5);
	graph.addNode(6);
	graph.addNode(16);

	graph.addEdge(1,2);
	graph.addEdge(1,3);
	graph.addEdge(1,4);
	graph.addEdge(1,5);
	graph.addEdge(1,16);
	graph.addEdge(1,6);
	graph.addEdge(2,4);
	graph.addEdge(2,5);
	graph.addEdge(2,16);
	graph.addEdge(2,6);

	graph.printNodes();
	graph.printEdges();

return 0;
}
