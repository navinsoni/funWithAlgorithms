#include<iostream>
#include<map>

using namespace std;

class Fibonacci{
	map<int,long long int> M;
	Fibonacci(){
		M[0] = 0;
		M[1] = 1;
	}

public:
	static Fibonacci getObject(){
		static Fibonacci obj = Fibonacci();
		return obj;
	}

	long long int getvalue(int n){
		map<int,long long int>::iterator it = M.find(n);
		if (it != M.end()){
			return it->second;
		}
		else{
			long long int value = getvalue(n-1) + getvalue(n-2);
			M[n] = value;
			return value;
		}
	}
};

int main(){
	int N;
	Fibonacci obj = Fibonacci::getObject();
	cout<<"Input no: ";
	cin>>N;
	long long int val = obj.getvalue(N);
	cout<<"long long integer is: "<<N<<endl;
	cout<<"val is: "<<val<<endl;

}
