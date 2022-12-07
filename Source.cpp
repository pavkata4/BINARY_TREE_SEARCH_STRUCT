#include<iostream>
using namespace std;
typedef struct Node* ptr;
ptr root = NULL;
int COUNT = 10;
struct Node {
	int Data;
	ptr left;
	ptr right;
};
void BST(int x) {
	ptr loc = root, insert = root;
	int checks = 0;
	if (root == NULL) {
		checks++;
		root = new Node;
		root->Data = x;
		root->left = NULL;
		root->right = NULL;
		cout << "there isn't! checks -> " << checks << endl;
	}
	else {
		while (loc != NULL && loc->Data != x) {
			checks++;
			insert = loc;
			if (x > loc->Data) {
				loc = loc->right;
			}
			else {
				loc = loc->left;
			}
		}
		if (loc != NULL) {
			checks++;
			cout << "there is! " << "checks -> " << checks << endl;
		}
		else {
			cout << "ther isn't! checks-> " << checks << endl;
			loc = new Node;
			loc->Data = x;
			loc->left = NULL;
			loc->right = NULL;
			if (x > insert->Data) {
				insert->right = loc;
			}
			else {
				insert->left = loc;
			}
		}
	}
}
void infix(ptr help) {
	if (help) {
		infix(help->left);
		cout << help->Data << " ";
		infix(help->right);
	}
}
void print(ptr root, int space) {
	if (root == NULL)
		return;
	space += COUNT;
	print(root->right, space);
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << root->Data << "\n";
	print(root->left, space);
}
int main() {
	setlocale(LC_ALL, "BULGARIAN");
	int x;
	cin >> x;
	while (x != 10000)
	{
		BST(x);
		cin >> x;
	}
	cout << "infix: " << endl;
	print(root, 10);
	return 0;
}

