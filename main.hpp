using namespace std;

// Nodo del árbol
class Node
{
private:
	// Valor del nodo
	int value;

	// Cantidad de hijos
	int children;

	// total de Nodos agragados
	int children_counter = 0;

	// Arreglo de los índices de los hijos
	int* children_nodes = NULL;
public:
	// Contructores
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

// Crea árbol usando lista de adyacencia
void createTree(int tree_len, Node* tree, int branches){
	int k = 0;
	// Crea la topología con la enumeración de los nodos
	for (int i = 0; k < tree_len - branches; ++i) {
		tree[i].setChildren(branches);

		for (int j = 0; j <  branches; ++j) {
			tree[i].inserChild(++k);
		}
	}

	cout << endl;
}