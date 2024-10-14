//Name: tejal patel
// BST.h
//date: 10/30/2023
// This files create a binary search tree class with various functions,
// adding items, removing items, checking if it conatins a specific item,
// counting the number of leaf nodes and also determining its height and
// getting item in pre, in , and post ordertraversals.
#ifndef BST_H
#define BST_H

#include <sstream>
#include <algorithm>

using namespace std;

template<class T>
class BST {

public:

    BST(T);                                   // Constructor
    ~BST();                                   // Destructor
    BST(BST<T> const &);                      // copy constructor

    BST operator=(const BST &ptr);            // overloaded assignment operator

    // To insert data
    void insert(T Data);

    // To check data
    bool contains(T Data);

    // To remove data
    void remove(T Data);

    // To check tree is empty or not
    bool empty();

    // To check the size of tree
    int size();

    // To get the leaf count of tree
    int getLeafCount();

    // To get the height of tree
    int getHeight();

    // To get level
    int getLevel(T data);

    // To getInOrderTraversal of tree
    string getInOrderTraversal();

   // To  getPreOrderTraversal of tree
    string getPreOrderTraversal();

    // To  getPostOrderTraversal of tree
    string getPostOrderTraversal();

    // To getAncestors
    string getAncestors(T target);


private:
    struct Node {
        T data;
        Node *left;
        Node *right;
    };
    Node *root;
    stringstream response;

    void destroyTree(Node *&);

    void insert(Node *&, Node *&);

    bool contains(Node *, T target);

    void remove(Node *&, T item);

    void makeDeletion(Node *&, T item);

    int size(Node *newNode);

    int getLeafCount(Node *);

    int getHeight(Node *);

    int getLevel(Node *, T, int);

    void getInOrderTraversal(Node *);

    void getPreOrderTraversal(Node *);

    void getPostOrderTraversal(Node *);

    bool getAncestors(Node *, T target);

    Node & operator=(const Node& other);


};

template<typename T>
BST<T>::BST(T) {
    root = nullptr;
}

template<typename T>
BST<T>::~BST() {
    destroyTree(root);
}

template<typename T>
void BST<T>::destroyTree(Node *&ptr) {
    if (ptr != nullptr) {
        destroyTree(ptr->left);
        destroyTree(ptr->right);
        delete ptr;
    }
    ptr = nullptr;
}

template<class T>
BST<T>::BST(const BST<T> &) {
    root = nullptr;
}

template<typename T>
void BST<T>::insert(T item) {
    Node *newNode = new Node;
    newNode->data = item;
    newNode->left = newNode->right = nullptr;

    insert(root, newNode);
}

template<typename T>
void BST<T>::insert(Node *&ptr, Node *&newNode) {
    if (ptr == nullptr)
        ptr = newNode;
    else if (ptr->data > newNode->data)
        insert(ptr->left, newNode);
    else
        insert(ptr->right, newNode);
}

template<typename T>
bool BST<T>::contains(T target) {
    return contains(root, target);
}

template<typename T>
bool BST<T>::contains(Node *root, T target) {
    if (root == nullptr) return false;
    if (root->data == target) return true;
    if (root->data > target) return contains(root->left, target);
    return contains(root->right, target);
}

template<typename T>
void BST<T>::remove(T item) {
    remove(root, item);
}

template<typename T>
void BST<T>::remove(Node *&ptr, T item) {
    if (ptr != nullptr) {
        if (ptr->data > item)
            remove(ptr->left, item);
        else if (ptr->data < item)
            remove(ptr->right, item);
        else
            makeDeletion(ptr, item);
    }
}

template<typename T>
void BST<T>::makeDeletion(Node *&ptr, T item) {
    Node *curr = nullptr;
    if (ptr != nullptr) {
        if (ptr->left == nullptr) {
            curr = ptr;
            ptr = ptr->right;
            delete curr;
        } else if (ptr->right == nullptr) {
            curr = ptr;
            ptr = ptr->left;
            delete curr;
        } else {
            curr = ptr->right;
            while (curr->left != nullptr)
                curr = curr->left;
            ptr->data = curr->data;
            remove(ptr->right, curr->data);
        }
    }
}

template<class T>
bool BST<T>::empty() {
    if (root == nullptr)
        return true;
    else
        return false;

}

template<class T>
int BST<T>::size() {
    return size(root);
}

template<class T>
int BST<T>::size(Node *newNode) {

    if (newNode == nullptr)
        return 0;
    else
        return (size(newNode->left) + 1 + size(newNode->right));

}

template<class T>
int BST<T>::getLeafCount() {
    return getLeafCount(root);
}

template<class T>
int BST<T>::getLeafCount(Node *ptr) {
    if (ptr == nullptr)
        return 0;
    if (ptr->left == nullptr && ptr->right == nullptr)
        return 1;
    else
        return getLeafCount(ptr->left) +
               getLeafCount(ptr->right);
}

template<class T>
int BST<T>::getHeight() {
    return getHeight(root);
}

template<class T>
int BST<T>::getHeight(Node *ptr) {
    if (ptr == nullptr)
        return 0;

    return 1 + max(getHeight(ptr->left), getHeight(ptr->right));
}


template<typename T>
int BST<T>::getLevel(T data) {
    return getLevel(root, data, 0);
}

template<class T>
int BST<T>::getLevel(Node *ptr, T data, int level) {

    if (ptr == nullptr)
        return -1;
    if (ptr->data == data)
        return level;

    if (ptr->left == nullptr && ptr->right == nullptr)
        return -1;

    int levelLeft = getLevel(ptr->left, data, level + 1);
    int levelRight = getLevel(ptr->right, data, level + 1);
    if (levelLeft == -1)
        return levelRight;
    else
        return levelLeft;
}


template<typename T>
string BST<T>::getInOrderTraversal() {
    response.str("");
    response.clear();
    getInOrderTraversal(root);
    return response.str();
}

template<typename T>
void BST<T>::getInOrderTraversal(Node *ptr) {
    if (ptr != nullptr) {
        getInOrderTraversal(ptr->left);
        response << ptr->data << " ";
        getInOrderTraversal(ptr->right);
    }
}

template<typename T>
string BST<T>::getPreOrderTraversal() {
    response.str("");
    response.clear();
    getPreOrderTraversal(root);
    return response.str();
}

template<typename T>
void BST<T>::getPreOrderTraversal(Node *ptr) {
    if (ptr != nullptr) {
        response << ptr->data << " ";
        getPreOrderTraversal(ptr->left);
        getPreOrderTraversal(ptr->right);
    }
}

template<class T>
string BST<T>::getPostOrderTraversal() {
    response.str("");
    response.clear();
    getPostOrderTraversal(root);
    return response.str();
}

template<typename T>
void BST<T>::getPostOrderTraversal(Node *ptr) {
    if (ptr != nullptr) {
        getPostOrderTraversal(ptr->left);
        getPostOrderTraversal(ptr->right);
        response << ptr->data << " ";
    }
}

template<typename T>
string BST<T>::getAncestors(T target) {
    response.str("");
    response.clear();
    getAncestors(root, target);
    return response.str();

}

template<typename T>
bool BST<T>::getAncestors(Node *root, T target)
{
    /* base cases */
    if (root == nullptr)
        return false;

    if (root->data == target)
        return true;

    /* here if the target is present in left or right subtree of this
     * node, then append this node in the  sstream */
    if (getAncestors(root->left, target) ||
        getAncestors(root->right, target)) {
        response << root->data << " ";
        return true;
    }
    /* otherwise return false */
    return false;
}

#endif
