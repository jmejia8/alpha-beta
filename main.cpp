#include <iostream>
#include "main.hpp"

#define INF 6666666

int min(int v, int b, Node* tree){
	if (b == INF or v == -INF)
		return v;
	if (v == INF or b == -INF)
		return b;


	if (tree[v].getValue() < tree[b].getValue())
		return v;
	return b;
}

int max(int v, int b, Node* tree){
	if (b == INF or v == -INF)
		return b;
	if (v == INF or b == -INF)
		return v;

	if (tree[v].getValue() > tree[b].getValue())
		return v;
	return b;
}

bool prune(int alpha, int beta, Node* tree){
	if (alpha == -INF or beta == INF)
		return false;

	if (tree[beta].getValue() <= tree[alpha].getValue())
		return true;

	return false;

}

int* output;
int output_index = 0;


int alpha_beta(Node* tree, int actual, int alpha, int beta, bool maxx){

	if (tree[actual].getChildren() == NULL) {
		output[output_index++] = actual;
		return actual;
		// return tree[actual].getValue();
	}

	int* children = tree[actual].getChildren();
	int branches = tree[actual].getCounter();
	int v;

	// Si es el turno de max, entonces eleige la mejor juagada
	if (maxx) {
		v = -INF;
		for (int i = 0; i < branches; ++i) {
			v = max(v, alpha_beta(tree, children[i], alpha, beta, not maxx), tree);
			alpha = max(v, alpha, tree);

			// Si se satisface la condición entonces posa.
			if (prune(alpha, beta, tree))
				break;
		}

		return v;
	}

	// Cuando es turno de min, entonces minimiza la jugada
	v = INF;
	for (int i = 0; i < branches; ++i) {
		v = min(v, alpha_beta(tree, children[i], alpha, beta, not maxx), tree);
		beta = min(beta, v, tree);

		// Si se satisface la condición entonces posa.
		if (prune(alpha, beta, tree))
			break;
	}

	return v;

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

	// Crea nodos del árbol con los parámetros
	// establecidos por el usuario
	for (i = 0; tmp > 0; ++i, tmp /= branches)
		for (int j = 0; j < tmp; ++j)
			++tree_len;

	Node tree[tree_len];

	// Arreglo de enteros de los nodos hoja visitados
	output = new int[data_len];

	// Se iniciliza el vector con índices negativos
	for(i = 0; i < data_len;) output[i++] = -1;

	// Crea los arcos de todos los nodos 
	// del árbol
	createTree(tree_len, tree, branches);

	// Lectura del vector de datos
	i = tree_len - data_len;
	while (i < tree_len){	
		cout << endl << i + 1 << ": "; 
		cin >> tmp;

		// Se guardan en las hojas del árbol
		tree[i++].setValue(tmp);
	}

	cout << "\nEl árbol se creó con éxito" << endl;

	// Regresa la mejor elección de la jugada
	int choice = alpha_beta(tree, 0, -INF, INF, true);

	// imprime en valor de los nodos visitados
	i = 0;
	for (int j = 0; j < data_len; ++j) {

		// Si es una hoja la imprime, de otra forma 
		if (output[i] == j + tree_len - data_len ){
			// Si este valor es la mejor elección, la imprime en negritas
			if (output[i] == choice)
				cout <<  "\033[1m(" << tree[output[i++]].getValue() << ")\033[0m, ";
			else
				cout << tree[output[i++]].getValue() << ", ";
		}
		else
			cout << "*, ";
	}

	cout << endl;


	return 0;
}