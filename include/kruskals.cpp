#include "kruskals.h"

void Kruskals::minimumSpanningTreeWt(){
	map <int, list<Edge> > graph = getGraph();
	map <int, Node * > map_node = getMapNode();
	list<Edge> edges;

	int N = map_node.size();
	for (pair<int, list<Edge> > var : graph)
		for (Edge edge : var.second)
			edges.push_front(edge);

	// edges.sort();
	vector<int> node(N+1, 0);

	int count = N;
	long long int weight = 0;
	list<set<int> > forest;
	while(count>0 || forest.size()!=1){
		Edge temp = edges.front();
		edges.pop_front();
		int arr[2];
		arr[0] = temp.getNode1()->getLabel();
		arr[1] = temp.getNode2()->getLabel();
		int t = 2-node[arr[0]]-node[arr[1]];
		count -= t;

		switch (t){
		case 0:
			{
				list<set<int> >::iterator it1=forest.end();
				list<set<int> >::iterator it2=forest.end();
				for (list<set<int> >::iterator iter = forest.begin(); iter != forest.end(); ++iter)
				{
					set<int>::iterator it;
					it = iter->find(arr[0]);
					if (it != iter->end()) it1 = iter;
					it = iter->find(arr[1]);
					if (it != iter->end()) it2 = iter;
				}
				if (it1 != it2){
					it1->insert(it2->begin(), it2->end());
					forest.erase(it2);
					weight += temp.getWeight();
				}
				break;
			}
		case 1:
			{
				int temp_no;
				if (node[arr[0]]) temp_no = 0;
				else temp_no = 1;
				node[arr[1-temp_no]] = 1;
				for (list<set<int> >::iterator iter = forest.begin(); iter != forest.end(); ++iter)
				{
					set<int>::iterator it;
					it = iter->find(arr[temp_no]);
					if (it != iter->end()) iter->insert(arr[1-temp_no]);
				}
				weight += temp.getWeight();
				break;
			}
		case 2:
			{
				node[arr[0]] = 1;
				node[arr[1]] = 1;
				set<int> s;
				s.insert(arr[0]);
				s.insert(arr[1]);
				forest.push_front(s);
				weight += temp.getWeight();
				break;
			}
		}
	}
	cout<<"Weight of tree is: "<<weight<<endl;
}
