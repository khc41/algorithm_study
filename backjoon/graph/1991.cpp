#include <iostream>

using namespace std;

struct node {
public:
	char left = NULL;
	char right = NULL;
};

node tree[100];

void preorder(char root) {
	if (root == NULL) return;
	cout << root;
	if (tree[root].left != '.') preorder(tree[root].left);
	if (tree[root].right != '.') preorder(tree[root].right);
}

void inorder(char root) {
	if (root == NULL) return;
	if (tree[root].left != '.') inorder(tree[root].left);
	cout << root;
	if (tree[root].right != '.') inorder(tree[root].right);
}

void postorder(char root) {
	if (root == NULL) return;
	if (tree[root].left != '.') postorder(tree[root].left);
	if (tree[root].right != '.') postorder(tree[root].right);
	cout << root;

}

int main() {
	int n, i, j;
	cin >> n;
	char data, left, right;
	for (i = 1; i < n; i++) {
		cin >> data >> left >> right;
		if (left != '.')
			tree[data].left = left;
		if (right != '.')
			tree[data].right = right;
	}
	preorder('A');
	cout << "\n";
	inorder('A');
	cout << "\n";
	postorder('A');
}