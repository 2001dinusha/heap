#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
  
void traverseInOrder(struct node *root) {
  if (root != NULL) {
    traverseInOrder(root->left);
    cout << root->key << " ";
    traverseInOrder(root->right);
  }
}

// Insert a node
struct node *insertNode(struct node *node, int key) {

      // If the tree is empty, return a new node
  if (node == NULL) {
    // Create a new node with the given key
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
  }

  // Otherwise, traverse down the tree to find the appropriate position to insert the new node
  struct node *curr = node;
  struct node *prev = NULL;
  while (curr != NULL) {
    prev = curr;
    if (key < curr->key)
      curr = curr->left;
    else if (key > curr->key)
      curr = curr->right;
    else // Key already exists in the tree, do not insert again
      return node;

}}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
   // Base case
  if (root == NULL)
    return root;

  // If the key to be deleted is smaller than the root's key, then it lies in the left subtree
  if (key < root->key)
    root->left = deleteNode(root->left, key);

  // If the key to be deleted is greater than the root's key, then it lies in the right subtree
  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  // If key is same as root's key, then This is the node to be deleted
  else {
    // node with only one child or no child
    if (root->left == NULL) {
      struct node *temp = root->right;
      delete(root);
      return temp;
    }
    else if (root->right == NULL) {
      struct node *temp = root->left;
      delete(root);
      return temp;
    }

    // node with two children: Get the inorder successor (smallest in the right subtree)
    struct node *temp = root->right;
    while (temp->left != NULL)
      temp = temp->left;

    // Copy the inorder successor's content to this node
    root->key = temp->key;

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->key);
  }

  return root;
 
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}