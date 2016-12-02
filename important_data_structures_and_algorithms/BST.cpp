#include <iostream>

using namespace std;

struct treeNode{
  int data;
  treeNode* left;
  treeNode* right;
  treeNode(int x):data(x),left(NULL),right(NULL);
}

template <class T>
class BST{
private:
  Node<T> * root;
public:
  //search
  //minima
  //maxima
}
