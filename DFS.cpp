#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

struct treenode {
	string data;
	treenode *left;
	treenode *right;
	treenode(string val) : data(val), left(NULL), right(NULL) {}
};

treenode* build_tree(string tree_data[], int size) {
	vector <treenode*> node_vector;
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			treenode *root = new treenode(tree_data[i]);
			root->left = new treenode(tree_data[i * 2 + 1]);
			root->right = new treenode(tree_data[i * 2 + 2]);
			node_vector.push_back(root);
			node_vector.push_back(root->left);
			node_vector.push_back(root->right);
		}else{
			if ((i * 2 + 1) >= size) { break; }
			node_vector[i]->left = new treenode(tree_data[i * 2 + 1]);
			node_vector.push_back(node_vector[i]->left);
			if ((i * 2 + 2) >= size) { break; }
			node_vector[i]->right = new treenode(tree_data[i * 2 + 2]);
			node_vector.push_back(node_vector[i]->right);
		}
	}
	return node_vector[0];
}

// 用 遞迴 實作 DFS
// preorder, inorder, postorder traversal
void dfs(treenode* root) {
	if (root == NULL) { return; }
	// preorder traversal
	cout << "data : " << root->data << endl;
	dfs(root->left);
	dfs(root->right);
	
	/*
	// inorder traversal
	dfs(root->left);
	cout << "data : " << root->data << endl;
	dfs(root->right);

	// postorder traversal
	dfs(root->left);
	dfs(root->right);
	cout << "data : " << root->data << endl;
	*/
}

// 用 stack 實作 DFS
void dfs_stack(treenode* root) {
	stack<treenode*> node_stack;
	node_stack.push(root);
	treenode* tmp;
	while (!node_stack.empty()) {
		tmp = node_stack.top();
		cout << "data : " << tmp->data << endl;
		node_stack.pop();
		// stack 先進後出
		if (tmp->right) { node_stack.push(tmp->right); }
		if (tmp->left) { node_stack.push(tmp->left); }
	}
}

// 用 queue 實作 BFS 
void bfs_queue(treenode* root) {
	queue<treenode*> node_queue;
	node_queue.push(root);
	treenode* tmp;
	while (!node_queue.empty()) {
		tmp = node_queue.front();
		cout << "data : " << tmp->data << endl;
		node_queue.pop();
		// queue 先進先出
		if (tmp->left) { node_queue.push(tmp->left); }
		if (tmp->right) { node_queue.push(tmp->right); }
	}
}

// DFS for graph

// BFS for graph

int main() {
	string tree_data[8] = { "A","B","C","D","E","F","G","H"};
	treenode *root = build_tree(tree_data, 8);
	cout << "dfs result : " << endl;
	dfs(root);
	cout << "dfs_stack result : " << endl;
	dfs_stack(root);
	cout << "bfs_queue result : " << endl;
	bfs_queue(root);
	system("pause");
	return 0;
}

