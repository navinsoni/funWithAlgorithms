#include "bfs.h"

void Bfs::breadthFirstSearch(int n){
	map <int, list<Edge> > graph = getGraph();
	map <int, Node * > map_node = getMapNode();

	map<int, Node* >::iterator it = map_node.find(n);
	if (it != map_node.end())
	{
		bfsQueue.push(it->second);
		bfsQueue.front()->setLevel(0);

		while (! bfsQueue.empty()) {
			Node *temp = bfsQueue.front();
			bfsQueue.pop();
			int level = temp->getLevel() + 1;
			map <int, list<Edge> >::iterator it_graph = graph.find(temp->getLabel());
			if (it_graph != graph.end()){
				for (Edge var : it_graph->second)
				{
					map<int, Node* >::iterator it_node = map_node.find(var.getNode2()->getLabel());
					if (it_node != map_node.end())
					{
						if(it_node->second->getLevel() == -1 || level < it_node->second->getLevel()){
							it_node->second->setLevel(level);
							bfsQueue.push(it_node->second);
						}
					}
				}
			}
		}

		cout << "\nDistance of other nodes from " << n <<endl;
		for (pair<int, Node*> var : map_node)
		{
			if (it->second != var.second)
				cout<<var.second->getLabel()<<": "<<var.second->getLevel()<<endl;
		}
	}
	else
	{
		std::cout << "Input node " << n << " not present" << endl;
		exit(0);
	}
}
