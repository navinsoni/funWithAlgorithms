#include <iostream>
#include <fstream>
#include <map>
#include <list>
using namespace std;
int main(int argc, char* argv[])
{
	map<string, list<string> > dict;
	std::ifstream infile("/usr/share/dict/words");
	string word;
	while (infile >> word) {
		string sorted_word = word;
		sort(sorted_word.begin(), sorted_word.end());
		map<string, list<string> >::iterator it = dict.find(sorted_word);
		if(it == dict.end())
			dict.insert(pair<string, list<string> >(sorted_word, list<string>(1,word)));
		else
			(it->second).push_back(word);
	}
	cout<<"Enter word: ";
	string temp_str;
	while ((cin>>temp_str) && temp_str != "*e*") {
		sort(temp_str.begin(), temp_str.end());
		map<string, list<string> >::iterator it = dict.find(temp_str);
		if(it != dict.end()){
			(it->second).size()==1?cout<<"Word is ":cout<<"Words are : ";
			for (string var : it->second) cout<<var<<" ";
			cout<<endl;
		}
		else cout<<"Word not found."<<endl;
		cout<<"Enter word: ";
	}
	return 0;
}
