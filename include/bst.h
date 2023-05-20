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
 int searchD(Node*, T);
 void depthTree(Node*, int, int&);

public:
 BST();
 void add(T);
 void print();
 int search(T);
 int depth();
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
int BST<T> :: searchD(Node *root, T value) {
  if (root == nullptr) {
    return 0;
  } else if(root->value == value) {
    return root->count;
  } else if (value <= root->value) {
    if (root->left != nullptr) {
      return searchD(root->left, value);
    } else {
      return 0;
    }
  } else {
    if (root->right) {
      return searchD(root->right, value);
    } else {
      return 0;
    }
  }
}
template <typename T>
int BST<T> :: search(T value) {
  return searchD(root, value);
}
template <typename T>
void BST<T> :: depthTree(Node* root, int lev, int& dep) {
  if (root == nullptr)
    return;
  if (lev>dep)
    dep=lev;
  depthTree(root->left, lev+1, dep);
  depthTree(root->right, lev+1, dep);
}
template <typename T>
int BST<T> :: depth() {
  int dep=0;
  depthTree(root, -1, dep);
  return dep;
}
#endif  // INCLUDE_BST_H_
