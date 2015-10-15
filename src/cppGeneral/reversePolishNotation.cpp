/*
* Reverse Polish Notation: 
* https://en.wikipedia.org/wiki/Reverse_Polish_notation
*/

#include <list>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

float rpn_calculate(vector < string > tokens) {
	list<float> Q;
	for (string var : tokens)
	{
		if(var == "+")
		{
			if (Q.size()<2) {
				cout<<"Error in input"<<endl;
				return -1;
			}
			float no1 = Q.front();
			Q.pop_front();
			float no2 = Q.front();
			Q.pop_front();
			float temp = no2 + no1;
			Q.push_front(temp);
		}
		else if(var == "-")
		{
			if (Q.size()<2) {
				cout<<"Error in input"<<endl;
				return -1;
			}
			float no1 = Q.front();
			Q.pop_front();
			float no2 = Q.front();
			Q.pop_front();
			float temp = no2 - no1;
			Q.push_front(temp);
		}
		else if(var == "*")
		{
			if (Q.size()<2) {
				cout<<"Error in input"<<endl;
				return -1;
			}
			float no1 = Q.front();
			Q.pop_front();
			float no2 = Q.front();
			Q.pop_front();
			float temp = no2 * no1;
			Q.push_front(temp);
		}
		else if(var == "/")
		{
			if (Q.size()<2) {
				cout<<"Error in input"<<endl;
				return -1;
			}
			float no1 = Q.front();
			Q.pop_front();
			float no2 = Q.front();
			Q.pop_front();
			float temp = no2 / no1;
			Q.push_front(temp);
		}
		else
		{
			float temp;
			istringstream(var) >> temp;
			Q.push_front(temp);
		}
	}
	if (Q.size()!=1) {
		cout<<"Error in input"<<endl;
		return -1;
	}
	return Q.front();
}

int main(int argc, char* argv[])
{
	vector<string> str;
	str.push_back("5");
	str.push_back("1");
	str.push_back("2");
	str.push_back("+");
	str.push_back("4");
	str.push_back("*");
	str.push_back("+");
	str.push_back("3");
	str.push_back("-");
	float res = rpn_calculate(str);
	cout << "result is: "<<res<<endl;
	return 0;
}
