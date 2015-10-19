#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int main(int argc, char* argv[])
{
	map<string, string> dict;
	std::ifstream infile("/usr/share/dict/words");
	string word;
	while (infile >> word) {
		string sorted_word = word;
		sort(sorted_word.begin(), sorted_word.end());
		map<string, string>::iterator it = dict.find(sorted_word);
		if(it == dict.end())
			dict.insert(pair<string, string>(sorted_word, word));
	}
	cout<<"Enter word: ";
	string temp_str;
	while ((cin>>temp_str) && temp_str != "*e*") {
		sort(temp_str.begin(), temp_str.end());
		map<string, string>::iterator it = dict.find(temp_str);
		if(it != dict.end()) cout<<"Word is: "<<it->second<<endl;
		else cout<<"Word not found."<<endl;
		cout<<"Enter word: ";
	}
	return 0;
}
