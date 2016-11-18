#include <iostream>
#include "main.hpp"

#define INF 6666666

int min(int a, int b){
	if (a < b)
		return a;
	return b;
}

int max(int a, int b){
	if (a > b)
		return a;
	return b;
}

int* output;
int output_index = 0;


int alpha_beta(Node* tree, int actual, int alpha, int beta, bool maxx){

	if (tree[actual].getChildren() == NULL) {
		output[output_index++] = actual;
		return tree[actual].getValue();
	}

	int* children = tree[actual].getChildren();
	int branches = tree[actual].getCounter();
	int v;

	if (maxx) {
		v = -INF;
		for (int i = 0; i < branches; ++i) {
			v = max(v, alpha_beta(tree, children[i], alpha, beta, not maxx));
			alpha = max(alpha, v);

			if (beta <= alpha)
				break;
		}

		return v;
	}

	v = INF;
	for (int i = 0; i < branches; ++i) {
		v = min(v, alpha_beta(tree, children[i], alpha, beta, not maxx));
		beta = min(beta, v);

		if (beta <= alpha)
			break;
	}

	return v;

}


int main(int argc, char const *argv[])
{

	int data_len, branches, i = 0, tree_len = 0;

	// cout << "Cantidad de ramas por nodo: ";
	cin >> branches;

	// cout << "Cantidad de datos: ";
	cin >> data_len;

	// cout << "Introduce los valores:";

	int data[data_len], tmp = data_len;

	for (i = 0; tmp > 0; ++i, tmp /= branches)
		for (int j = 0; j < tmp; ++j)
			++tree_len;

	Node tree[tree_len];
	output = new int[data_len];

	for(i = 0; i < data_len;) output[i++] = -1;

	createTree(tree_len, tree, branches);

	// Lectura del vector de datos
	i = tree_len - data_len;
	while (i < tree_len){	
		// cout << endl << i << ": "; 
		cin >> tmp; 
		tree[i++].setValue(tmp);
	}

	// cout << "\nEl árbol se creó con éxito" << endl;

	int winner = alpha_beta(tree, 0, -INF, INF, true);

	i = 0;
	for (int j = 0; j < data_len; ++j) {

		// if (output[i] == choice){
		// 	cout <<  "(" << tree[output[i++]].getValue() << "), ";
		// }

		if (output[i] == j + tree_len - data_len )
			cout << "\033[1m" << tree[output[i++]].getValue() << "\033[0m, ";
		else
			cout << "*, ";
	}

	cout << endl;


	return 0;
}