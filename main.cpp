#include <iostream>
#include <cmath>
#include "main.hpp"


void createTree(int tree_len, Node* tree, int branches){
	int k = 0;
	for (int i = 0; k < tree_len - branches; ++i) {
		tree[i].setChildren(branches);

		for (int j = 0; j <  branches; ++j) {
			tree[i].inserChild(++k);
		}
	}

	cout << endl;
}


int main(int argc, char const *argv[])
{

	int data_len, branches, i = 0, tree_len = 0;

	cout << "Cantidad de ramas por nodo: ";
	cin >> branches;

	cout << "Cantidad de datos: ";
	cin >> data_len;

	cout << "Introduce los valores:";

	int data[data_len], tmp = data_len;

	for (i = 0; tmp > 0; ++i, tmp /= branches)
		for (int j = 0; j < tmp; ++j)
			++tree_len;

	Node tree[tree_len];

	createTree(tree_len, tree, branches);

	// Lectura del vector de datos
	i = tree_len - data_len;
	while (i < tree_len){	
		cout << endl << i << ": "; 
		cin >> tmp; 
		tree[i++].setValue(tmp);
	}

	cout << "\nEl árbol se creó con éxito" << endl;


	return 0;
}