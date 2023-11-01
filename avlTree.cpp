#include "avlTree.h"
#include <bits/stdc++.h>



/// @brief default constructor creating root
avlTree::avlTree()
{
    root = nullptr;
}

/// @brief destructor
avlTree::~avlTree()
{
    Destroy(root);
}

/// @brief helper function for destructor
/// @param node 
void avlTree::Destroy(AVLNode* p)
{
    if(p)
    {
        Destroy(p->left);
        Destroy(p->right);
        delete p;
    }
}


/// @brief function to insert and store key and values in tree
/// @param key node that points to the value being stored
/// @return function that performs the insert
bool avlTree::insert(int key, string value)
{
    return insertHelper(root, key, value);
}

/// @brief Helper function for insert method
/// @param current node pointer reference 
/// @param key number that holds string value
/// @param value string value
/// @return true if key and value has been inserted or false if key has not been inserted 
bool avlTree::insertHelper(AVLNode*& current, int key, string value)
{
    if(current == nullptr)
    {
        AVLNode* newNode = new AVLNode(key, value);
        current = newNode;
        return true;
    }
    else if(key < current->key)
    {
        insertHelper(current->left, key, value);
        return true;
    }
    else if(key > current->key)
    {
        insertHelper(current->right, key, value);
        return true;
    }
    current->height = nodeHeight(current);
    int balance = calcBalance(current);
    
    if(balance > 1 && key < current->left->key)
    {
        return SRR(current);
        current->height = nodeHeight(current);
    }
    if(balance < -1 && key < current->right->key)
    {
        return SLR(current);
        current->height = nodeHeight(current);
    }
    if(balance > 1 && key > current->left->key)
    {
        current->left = SLR(current->left);
        return SRR(current);
        current->height = nodeHeight(current);
    }
    if(balance < -1 && key > current->right->key)
    {
        current->right = SRR(current->right);
        return SLR(current);
        current->height = nodeHeight(current);
    }
    
    return false;
}


/// @brief Function to gt return the height of the tree
/// @return height
int avlTree::getHeight()
{
  return root->height;
}

/// @brief Function to calculate the height of each node
/// @param p avl node pointer
/// @return node height
int avlTree::nodeHeight(AVLNode* p)
{
    int HL, HR = -1;
    if(p->left!=nullptr)
    {
        HL = p->left->height;
    }
    if(p->right!=nullptr)
    {
        HR = p->right->height;
    }
    return p->height = max(HL, HR) +1;
}

/// @brief Function that returns the number of nodes in a tree
/// @param node pointer to nodes
/// @return number of nodes
int avlTree::getSize(AVLNode* p)
{
    if(p == nullptr)
    {
        return 0;
    }
    return getSize(p->left) + 1 + getSize(p->right);
}


/// @brief Function to calaculate balance of nodes
/// @param p avl node pointer that is passed into method as a parameter
/// @return 's balance result by subtracting height of left and right node
int avlTree::calcBalance(AVLNode* p)
{
    int HL, HR;
    if(p->left != nullptr)
    {
        HL = p->left->height;
    }
    if(p->right != nullptr)
    {
        HR = p->right->height;
    }

    return HL - HR;
}

/// @brief Left rotation method
/// @param prob pointer to key being rotated
/// @return hook
AVLNode* avlTree::SLR(AVLNode*& prob)
{
    AVLNode* hook = prob->right;
    AVLNode* temp = hook->left;
    hook->left = prob;
    prob->right = temp;
    
    return hook;
}

/// @brief Left rotation method
/// @param prob pointer to key being rotated
/// @return hook
AVLNode* avlTree::SRR(AVLNode*& prob)
{
    AVLNode* hook = prob->left;
    AVLNode* temp = hook->right;
    hook->right = prob;
    prob->left = temp;
    
    return hook;
}


/// @brief Function to print the tree in sideways form
/// @param os output stream
/// @param me avl tree
/// @return return output
ostream& operator<<(ostream& os, const avlTree& me)
{
    os << "{";
    me.print(me.root, os, 0);
    os << "}";
    return os;
}


/// @brief Helper Function for ostream& and print
/// @param os output stream
/// @param node AVLNode
ostream& avlTree::print(AVLNode* node, ostream& os, int depth)const
{
    if(node!=NULL)
    {
        print(node->right, os, depth + 1);
        os << """" << depth * 4;
        os << node->key << node << depth;
        print(node->left, os, depth + 1);
    }
    return os;
}


/// @brief copy constructor to make independent copy of avl tree
/// @param cf copy from node that copies the avl tree
/// @param ci copy into node that that the avl tree is being copied into
/// @return true if it worked
bool avlTree::copyNodes(AVLNode* cf, AVLNode*& ci)
{
    if(cf!= NULL)
    {
        ci = cf;
        copyNodes(cf->left, ci->left);
        copyNodes(cf->right, ci->right);
        return true;
    }
    return false;
}

/// @brief creates independent copy of tree
/// @param t refrence pointer for avlTree
/// @return 's independent copy
avlTree& avlTree::operator=(const avlTree& t) 
{
    copyNodes(t.root, root);
    return *this;
}

/// @brief fucntion to return a range of values within two sets of numbers
/// @param lowkey lowest value
/// @param highkey highest value
/// @return helper function that gets the values
vector<string> avlTree::findRange(int lowkey, int highkey)
{
    vector<string> values;
    return findRangeHelper(root, lowkey, highkey, values);
}

/// @brief Helper Function to find range 
/// @param current node pointer
/// @param lowkey lowest key
/// @param highkey highest key
/// @param value vector of values being returned
/// @return value
vector<string> avlTree::findRangeHelper(AVLNode*& current, int lowkey, int highkey, vector<string>& value)
{
    if(current == nullptr)
    {
        cout << "Nothing" << endl;
    }
    else if(current->key >= lowkey && current->key <= highkey)
    {
        value.push_back(current->value);
        findRangeHelper(current->left, lowkey, highkey, value);
        findRangeHelper(current->right, lowkey, highkey, value);
    }
    return value;
}