/*
* This demo uses kruskals.h library from include directory
* The graph can be ordered/unordered. It can be specified
* by passing Kruskals::State::ORDERED in Kruskals constructor
* eg: Kruskals(Kruskals::State::ORDERED);
* by default graph is unordered.
* The graph can also have multiple edges connected to same nodes.
*/

#include "kruskals.h"

int main(int argc, char* argv[])
{
	Kruskals graph = Kruskals(Kruskals::State::ORDERED);
	graph.addNode(1);
	graph.addNode(2);
	graph.addNode(3);
	graph.addNode(4);

	graph.addEdge(1,2,5);
	graph.addEdge(1,3,3);
	graph.addEdge(4,1,6);
	graph.addEdge(2,4,7);
	graph.addEdge(3,2,4);
	graph.addEdge(3,4,5);

	graph.printNodes();
	graph.printEdges();

	graph.minimumSpanningTreeWt();

    return 0;
}
