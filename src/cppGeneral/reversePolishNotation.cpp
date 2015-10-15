/*
* Reverse Polish Notation:
* https://en.wikipedia.org/wiki/Reverse_Polish_notation
*/

/*
* In this code function rpn_calculate() takes the input of tokens
* and calculates the value.
* Whenever it finds '+', '-', '*', and '/' it pops two values from
* list and perform the reqd. operation.
* Here list 'stack' acts as a stack.
* All the inputs are integers but result can be float as division
* is involved.
* If the input is wrong the funtion prints error and returns -1.
*/

#include <list>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

float rpn_calculate(vector < string > tokens) {
	list<float> stack;
	for (string var : tokens)
	{
		if(var == "+")
		{
			if (stack.size()<2) {
				cout<<"Error in input"<<endl;
				return -1;
			}
			float no1 = stack.front();
			stack.pop_front();
			float no2 = stack.front();
			stack.pop_front();
			float temp = no2 + no1;
			stack.push_front(temp);
		}
		else if(var == "-")
		{
			if (stack.size()<2) {
				cout<<"Error in input"<<endl;
				return -1;
			}
			float no1 = stack.front();
			stack.pop_front();
			float no2 = stack.front();
			stack.pop_front();
			float temp = no2 - no1;
			stack.push_front(temp);
		}
		else if(var == "*")
		{
			if (stack.size()<2) {
				cout<<"Error in input"<<endl;
				return -1;
			}
			float no1 = stack.front();
			stack.pop_front();
			float no2 = stack.front();
			stack.pop_front();
			float temp = no2 * no1;
			stack.push_front(temp);
		}
		else if(var == "/")
		{
			if (stack.size()<2) {
				cout<<"Error in input"<<endl;
				return -1;
			}
			float no1 = stack.front();
			stack.pop_front();
			float no2 = stack.front();
			stack.pop_front();
			float temp = no2 / no1;
			stack.push_front(temp);
		}
		else
		{
			float temp;
			istringstream(var) >> temp;
			stack.push_front(temp);
		}
	}
	if (stack.size()!=1) {
		cout<<"Error in input"<<endl;
		return -1;
	}
	return stack.front();
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
