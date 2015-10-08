#include "graph.h"

void Graph::addNode(int n) {
    map<int, Node * >::iterator it = map_node.find(n);
    if (it == map_node.end())
    {
        map_node.insert(pair<int, Node * >(n, new Node(n)));
    }

	map<int, list<int> >::iterator it1 = graph.find(n);
	if (it1 == graph.end())
	{
		graph.insert(pair<int, list<int> >(n, list<int>()));
	}
}

void Graph::addEdge(int n1, int n2) {
    map<int, list<int> >::iterator it = graph.find(n1);
    if (it == graph.end())
    {
        graph.insert(pair<int, list<int> >(n1, list<int>(1,n2)));
    }
    else {
        (it->second).push_back(n2);
    }

	if ( getState() == Graph::UNORDERED ) {
	    map<int, list<int> >::iterator it = graph.find(n2);
	    if (it == graph.end())
	    {
	        graph.insert(pair<int, list<int> >(n1, list<int>(1,n1)));
	    }
	    else {
	        (it->second).push_back(n1);
	    }
	}
}

void Graph::printNodes() {
	std::cout << "\nThe nodes present are :" << "\n";
    for (pair<int, Node* > var : map_node)
        cout << var.second->getLabel() << " ";
    cout << endl;
}

void Graph::printEdges() {
	std::cout << "\nThe edges present between nodes are :" << "\n";
    for (pair<int, list<int> > var : graph)
	{
		std::cout << var.first << ": ";
		for ( int var1 : var.second)
		{
			std::cout << var1 << " ";
		}
    	cout << endl;
	}
}
