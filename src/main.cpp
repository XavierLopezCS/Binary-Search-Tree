// 136 - Lab8 - BST BinarySearchTree

using namespace std;
#include <iostream>

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {} // Constructor
};


class BinarySearchTree {
public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int v) {
        root = insertR(root, v); // Insert Recursively
    }

    void remove(int v) {
        root = removeR(root, v); // Remove Recursively
    }

    bool search(int v) {
        return searchR(root, v); // Search Recursively
    }

    void inOrder() {
        inOrderR(root); // Left-Root-Right
        cout << endl;
    }

    void preOrder() {
        preOrderR(root); // Root-Left-Right
        cout << endl;
    }

    void postOrder() {
        postOrderR(root); // Left-Right-Root
        cout << endl;
    }

    //=========// Lab 8 //=========//
    void getHeight() {
        cout << getHeightR(root);
        cout << endl;
    }

    void countLeaves() {
		cout << countLeavesR(root);
		cout << endl;
    }

private:
    Node* root;

    Node* insertR(Node* c, int v) {
        if (c == nullptr) {
            return new Node(v);
        }
        if (v < c->data) {
            c->left = insertR(c->left, v);
        }
        else if (v > c->data) {
            c->right = insertR(c->right, v);
        }
        return c;
    }

    bool searchR(Node* c, int v) {
        if (c == nullptr) {
            return false;
        }
        if (c->data == v) {
            return true;
        }
        if (v < c->data) {
            return searchR(c->left, v);
        }
        else {
            return searchR(c->right, v);
        }

    }

    void inOrderR(Node* c) { // Left-Root-Right
        if (c != nullptr) {
            inOrderR(c->left); // Traverse left subtree
            cout << c->data; // Visit node
            inOrderR(c->right); // Traverse right subtree
        }
    }

    void preOrderR(Node* c) { // Root-Left-Right
        if (c != nullptr) {
            cout << c->data; // Visit node
            preOrderR(c->left); // Traverse left subtree
            preOrderR(c->right); // Traverse right subtree
        }
    }

    void postOrderR(Node* c) { // Left-Right-Root
        if (c != nullptr) {
            postOrderR(c->left); // Traverse left subtree
            postOrderR(c->right); // Traverse right subtree
            cout << c->data << " "; // Visit node
        }
    }

    Node* findMinNode(Node* node) {
        Node* c = node;
        while (c->left != nullptr) {
            c = c->left;
        }
        return c;
    }

    Node* removeR(Node* c, int v) {
        if (c == nullptr) {
            return c;
        }
        if (v < c->data) {
            c->left = removeR(c->left, v);
        }
        else if (v > c->data) {
            c->right = removeR(c->right, v);
        }
        else {
            if (c->left == nullptr) {
                Node* temp = c->right;
                delete c;
                return temp;
            }
            else if (c->right == nullptr) {
                Node* temp = c->left;
                delete c;
                return temp;
            }
            Node* temp = findMinNode(c->right);
            c->data = temp->data;
            c->right = removeR(c->right, temp->data);
        }
        return c;
    }

	int getHeightR(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        int leftHeight = getHeightR(node->left);
		int rightHeight = getHeightR(node->right);

		return 1 + max(getHeightR(node->left), getHeightR(node->right));

	}

    int countLeavesR(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        if (node->left == nullptr && node->right == nullptr) {
            return 1;
        }
        else {
            return countLeavesR(node->left) + countLeavesR(node->right);
        }
    }

};


int main()
{
    BinarySearchTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(2);
    tree.insert(4);
    tree.insert(7);
    tree.insert(6);
    tree.insert(8);

    cout << "In-Order: ";
    tree.inOrder();

    cout << "Pre-Order: ";
    tree.preOrder();

    cout << "Post-Order: ";
    tree.postOrder();


    if (tree.search(5) == true) {
        cout << "Found 5" << endl;
    }
    else {
        cout << "5 not found" << endl;
    }


    tree.remove(4);
    cout << "In-Order after removing 4: ";
    tree.inOrder();

    cout << "Height of the tree: ";
    tree.getHeight();

    cout << "Number of leaves in the tree: ";
    tree.countLeaves();


    return 0;


}
