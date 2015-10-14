#include "graph.h"

void Graph::addNode(int n) {
    map<int, Node * >::iterator it = map_node.find(n);
    if (it == map_node.end())
    {
        map_node.insert(pair<int, Node * >(n, new Node(n)));
    }

	map<int, list<Edge> >::iterator it1 = graph.find(n);
	if (it1 == graph.end())
	{
		graph.insert(pair<int, list<Edge> >(n, list<Edge>()));
	}
}

void Graph::addEdge(int n1, int n2, float dist) {

	map<int, Node * >::iterator it_node1 = map_node.find(n1);
	if (it_node1 == map_node.end())
	{
		map_node.insert(pair<int, Node * >(n1, new Node(n1)));
	}

	map<int, Node * >::iterator it_node2 = map_node.find(n2);
	if (it_node2 == map_node.end())
	{
		map_node.insert(pair<int, Node * >(n2, new Node(n2)));
	}

    map<int, list<Edge> >::iterator it = graph.find(n1);
    if (it == graph.end())
    {
        graph.insert(pair<int, list<Edge> >(n1, list<Edge>(1,Edge(it_node1->second,it_node2->second,dist))));
    }
    else {
        (it->second).push_back(Edge(it_node1->second,it_node2->second,dist));
    }

	if ( getState() == Graph::UNORDERED ) {
	    map<int, list<Edge> >::iterator it = graph.find(n2);
	    if (it == graph.end())
	    {
	        graph.insert(pair<int, list<Edge> >(n1, list<Edge>(1,Edge(it_node2->second,it_node1->second,dist))));
	    }
	    else {
	        (it->second).push_back(Edge(it_node2->second,it_node1->second,dist));
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
    for (pair<int, list<Edge> > var : graph)
	{
		std::cout << var.first << ": ";
		for ( Edge var1 : var.second)
		{
			std::cout << var1.getNode2()->getLabel() << " ";
		}
    	cout << endl;
	}
	cout << endl;
}
