#include <iostream>
#include <unordered_map>

using namespace std;

class CustomDs{
public:
	CustomDs():data(), set(-1), curr_ver(0){}

	int getIdx(int idx) {
		unordered_map<int,pair<int,int> >::iterator it = data.find(idx);
		if (it != data.end()){
			if ((it->second).first == curr_ver)
				return (it->second).second;
			else
				return set;
		}
		return -1;
	}

	void setIdx(int idx, int val) {
		unordered_map<int,pair<int,int> >::iterator it = data.find(idx);
		if (it != data.end()) {
			(it->second).first = curr_ver;
			(it->second).second = val;
		}
		else {
			data.insert(make_pair(idx,make_pair(curr_ver, val)));
		}
	}

	void setAll(int val) {
		set = val;
		curr_ver++;
	}
private:
	unordered_map<int,pair<int,int> > data;
	int set;
	int curr_ver;
};

int main(int argc, char const *argv[])
{
	CustomDs d;
	d.setIdx(3,2);
	d.setIdx(4,3);
	d.setIdx(6,4);
	cout<<d.getIdx(3)<<endl;
	cout<<d.getIdx(4)<<endl;
	cout<<d.getIdx(6)<<endl;
	d.setAll(1);
	cout<<d.getIdx(3)<<endl;
	cout<<d.getIdx(4)<<endl;
	cout<<d.getIdx(6)<<endl;
	d.setIdx(4,10);
	cout<<d.getIdx(3)<<endl;
	cout<<d.getIdx(4)<<endl;
	cout<<d.getIdx(6)<<endl;
	d.setAll(10);
	cout<<d.getIdx(3)<<endl;
	cout<<d.getIdx(4)<<endl;
	cout<<d.getIdx(6)<<endl;
	return 0;
}