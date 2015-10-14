#ifndef _NODE_H_
#define _NODE_H_

class Node
{
public:
    Node(int lab, int lev=-1, float dist=-1):label(lab), level(lev), distance(dist){}

    int getLevel() { return level; }
    int getLabel() { return label; }
    float getDistance() { return distance; }
	void setLevel(const int l) { level = l;}
	void setDistance(const float d) { distance = d;}

private:
    int label;
    int level;
    float distance;
};

#endif //_NODE_H_
