/*
Kennedy Eziolise
CS3100
Indexing with AVL Trees
03/22/2023
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class AVLNode
{
public:
    AVLNode* left;
    AVLNode* right;
    int key;
    string value;
    int height;

    /// @brief constructor for avl node
    /// @param newKey new key being created
    /// @param newValue new value being created
    AVLNode(int newKey, string newValue): left(nullptr), right(nullptr), key(newKey), value(newValue), height(0) {};
};


class avlTree{
public:
    /// @brief root pointer
    AVLNode* root;

    /// @brief left rotation method
    /// @param  avlnode reference pointer
    /// @return 
    AVLNode* SLR(AVLNode*&);

    /// @brief right rotation method
    /// @param  avlnode reference pointer
    /// @return 
    AVLNode* SRR(AVLNode*&);

    /// @brief constructor for avlTree
    avlTree();

    /// Destructor for avl Tree
    ~avlTree();

    /// @brief Helper method for destructor
    /// @param  avlnode pointer for root
    void Destroy(AVLNode*);

    /// @brief insert method 
    /// @param  key 
    /// @param  value
    /// @return helper method
    bool insert(int, string);

    /// @brief Helper method for insert
    /// @param  node
    /// @param  key
    /// @param  value
    /// @return true if key has been inserted or false if otherwise
    bool insertHelper(AVLNode*&, int, string);

    /// @brief gets height of tree with root node
    /// @return root height
    int getHeight();

    /// @brief calculates height of each node
    /// @param  node pointer
    /// @return returns height of a node by subtracting height of left and right subtree
    int nodeHeight(AVLNode*);

    /// @brief gets szie fo avl tree
    /// @param  node pointer
    /// @return size of tree
    int getSize(AVLNode*);

    /// @brief calculates balance of the node and tree
    /// @param  node pointer
    /// @return returns balance of node
    int calcBalance(AVLNode*);

    /// @brief method to print tree sideways 
    /// @param os output stream
    /// @param me avltree reference
    /// @return output
    friend ostream& operator<<(ostream& os, const avlTree& me);

    /// @brief print helper method
    /// @param  node
    /// @param  os output stream
    /// @param  depth
    /// @return output
    ostream& print(AVLNode*,ostream& , int)const;

    /// @brief operator equals method
    /// @param t avltree reference
    /// @return true if nodes have been copied or false if they haven't
    avlTree& operator=(const avlTree& t);

    /// @brief deep copy of nodes
    /// @param cf copyfrom
    /// @param ci copyinto
    /// @return object pointer
    bool copyNodes(AVLNode* cf, AVLNode*& ci);

    /// @brief returns method to find range of values
    /// @param lowkey 
    /// @param highkey 
    /// @return findrange helper
    vector<string> findRange(int lowkey, int highkey);

    /// @brief helper function for find range method
    /// @param  node
    /// @param  low
    /// @param  high
    /// @param  value
    /// @return value
    vector<string> findRangeHelper(AVLNode*&, int, int, vector<string>&);
};