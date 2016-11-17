using namespace std;

class Node
{
private:
	int value;
	int children;
	int children_counter = 0;
	int* children_nodes;
public:
	Node(int val, int children) : value(val), children_counter(children) {};
	Node() {};

	void setValue(int v){
		value = v;
	}

	void setChildren(int n){
		children = n;
		children_nodes = new int[children];
	}

	int getValue() { return value; }

	int* getChildren () { return children_nodes; }
	
	int inserChild (int index) {
		children_nodes[children_counter++] = index;
	}

	int getCounter(){
		return children_counter;
	}

};