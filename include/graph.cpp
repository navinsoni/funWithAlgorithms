#include "graph.h"

void Graph::addNode(int n) {
    map<int, Node * >::iterator it = map_node.find(n);
    if (it == map_node.end())
    {
        map_node.insert(pair<int, Node * >(n, new Node(n)));
    }

	map<int, list<Node *> >::iterator it1 = graph.find(n);
	if (it1 == graph.end())
	{
		graph.insert(pair<int, list<Node *> >(n, list<Node *>()));
	}
}

void Graph::addEdge(int n1, int n2, float dist) {

	map<int, Node * >::iterator it_node = map_node.find(n1);
	if (it_node == map_node.end())
	{
		map_node.insert(pair<int, Node * >(n1, new Node(n1)));
	}

	it_node = map_node.find(n2);
	if (it_node == map_node.end())
	{
		map_node.insert(pair<int, Node * >(n2, new Node(n2)));
	}

    map<int, list<Node *> >::iterator it = graph.find(n1);
    if (it == graph.end())
    {
        graph.insert(pair<int, list<Node*> >(n1, list<Node*>(1,new Node(n2,dist))));
    }
    else {
        (it->second).push_back(new Node(n2,dist));
    }

	if ( getState() == Graph::UNORDERED ) {
	    map<int, list<Node *> >::iterator it = graph.find(n2);
	    if (it == graph.end())
	    {
	        graph.insert(pair<int, list<Node *> >(n1, list<Node*>(1,new Node(n1,dist))));
	    }
	    else {
	        (it->second).push_back(new Node(n1,dist));
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
    for (pair<int, list<Node *> > var : graph)
	{
		std::cout << var.first << ": ";
		for ( Node *var1 : var.second)
		{
			std::cout << var1->getLabel() << " ";
		}
    	cout << endl;
	}
}
