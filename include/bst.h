// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <iostream>
template <typename T>
class BST {
public:
 struct Node {
   T value;
   int count;
   Node* left;
   Node* right;
 };

private:
 Node* root;
 Node* addNode(Node*, T);
 void printTree(Node*);

public:
 BST();
 void add(T);
 void print();
 int find(Node*, T);
 void findD(T, int&);
};
template <typename T>
BST<T> :: BST():root(nullptr) {}
template <typename T>
typename BST<T> :: Node* BST<T> :: addNode(Node* root, T value) {
  if (root == nullptr) {
    root = new Node;
    root->value = value;
    root->count = 1;
    root->left = root->right = nullptr;
  } else if (root->value > value) {
    root->left = addNode(root->left, value);
  } else if (root->value < value) {
    root->right = addNode(root->right, value);
  } else {
    root->count++;
  }
  return root;
}
template <typename T>
void BST<T> :: add(T value) {
  root = addNode(root, value);
}
template <typename T>
void BST<T> :: printTree(Node* root) {
  if (root == nullptr)
    return;
  printTree(root->left);
  for (int i = 0; i < root->count; i++)
    std::cout << root->value << " ";
  printTree(root->right);
}
template <typename T>
void BST<T> :: print() {
  printTree(root);
}
template <typename T>
int BST<T> :: find(Node *root, T value) {
  if (root == nullptr) {
    return 0;
  } else if(root->value == value) {
    return root->count;
  } else if (value <= root->value) {
    if (root->left != nullptr) {
      return find(root->left, value);
    } else {
      return 0;
    }
  } else {
    if (root->right) {
      return find(root->right, value);
    } else {
      return 0;
    }
  }
}
template <typename T>
void BST<T> :: findD(T value, int& t) {
  t = find(root, value);
}
#endif  // INCLUDE_BST_H_
