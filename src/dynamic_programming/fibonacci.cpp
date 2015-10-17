#include<iostream>
#include<map>

using namespace std;

class Febonacci{
	map<int,long long int> M;
	Febonacci(){
		M[0] = 0;
		M[1] = 1;
	}

public:
	static Febonacci getObject(){
		static Febonacci obj = Febonacci();
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
	Febonacci obj = Febonacci::getObject();
	cout<<"Input no: ";
	cin>>N;
	long long int val = obj.getvalue(N);
	cout<<"long long integer is: "<<N<<endl;
	cout<<"val is: "<<val<<endl;

}
