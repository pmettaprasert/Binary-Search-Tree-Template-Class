// Name: Phubeth Mettaprasert
// File: BST.cpp
// Date: May 9, 2022
//The header file and the implementation of the BST class. Contains the
// framework to create a BST and methods for BST functionalities.
//Purpose: A class that will read an input from a file and store the data in
//         BST. The data will be displayed in different traversal orders,
//         provide information on the BST, and allow other methods of
//         modifying the BST.

#ifndef P2_BST_H
#define P2_BST_H

#include <sstream>
#include <string>
using namespace std;

template <typename T>
class BST {

public:
    BST();
    // Constructor that initializes the BST class.
    // preconditions: none
    // postconditions: Sets the root node to point to nullptr.

    ~BST();
    // Destructor for the BST class
    // preconditions: none
    // postconditions: The stored BST will be destroyed and deallocate all
    //                 memory created by the nodes.


    BST(const BST&);
    // Copy constructor. Creates a new BST based on another BST and copying
    // all the information from the previous BST to the new BST. Returns a
    // pointer to the new BST.
    // preconditions: A BST object needs to exist before calling this
    //                copy constructor to be used as the argument.
    // postconditions: Creates a new BST object based on the previous
    //                 BST object.

    BST<T>& operator=(const BST&);
    // Overloaded operator method. In this case used to set one BST
    // object equal to another created BST. Difference between copy
    // constructor and this is that this requires that a BST object be
    // created before copying from the other BST object.
    // preconditions: At least two BST objects needed to exist in order
    //                copy from one BST to the other
    // postconditions: Copies or replaces one BST object information to the
    //                 other BST object and returns the reference to the
    //                 copied BST object.

    void insert(T);
    // Allows a node containing data of type T to be inserted into the BST.
    // preconditions: none
    // postconditions: Creates a new node with data type T to be inserted
    //                 into the BST. Each time insert is called, the function
    //                 will compare values from the input data and insert it
    //                 into the BST in the correct position.

    bool contains(T);
    // Checks if the BST contains a specific node containing data of type T.
    // preconditions: none
    // postconditions: Returns a boolean where true means the data of type T
    //                 is in the BST and false otherwise.

    void remove(T);
    // Removes the specific node that contains the specific data of type T
    // inputted as the argument.
    // preconditions: none
    // postconditions: Deletes the node if the inputted argument data is
    //                 found, otherwise ignore remove function call.
    //                 Deallocates the node memory as well.

    bool empty();
    // A method to return whether the BST is empty or not.
    // preconditions: none
    // postconditions: Returns a boolean where true is when the BST is empty
    //                 and false otherwise.

    int size();
    // Goes through the BST and sees how many nodes were created.
    // preconditions: none
    // postconditions: Returns an int of how many nodes in the BST were created.

    int getLeafCount();
    // Goes through the BST and sees how many leaf nodes are in the BST.
    // preconditions: none
    // postconditions: Returns an int of how many leaf nodes are in the BST.

    int getHeight();
    // Determines the height of the BST.
    // preconditions: none
    // postconditions: Returns an int of the height of the BST.

    int getLevel(T);
    // Gets the level of a specific node of type T in the BST
    // preconditions: none
    // postconditions: Returns an int of the level of the node.

    string getInOrderTraversal();
    // Returns a string of the in order traversal of the nodes in the BST.
    // preconditions: none
    // postconditions: none

    string getPreOrderTraversal();
    // Returns a string of the pre order traversal of the nodes in the BST.
    // preconditions: none
    // postconditions: none

    string getPostOrderTraversal();
    // Returns a string of the post order traversal of the nodes in the BST.
    // preconditions: none
    // postconditions: none

    string getAncestors(T);
    // Returns a string of the ancestors of particular node. If the node
    // doesn't exist returns and empty string.
    // preconditions: none
    // postconditions: none

private:

    //Struct node that will be the basis for the nodes to be inserted in the
    // BST.
    struct Node {
        T data;
        Node * left;
        Node * right;
    };
    Node * root;


    void insert(Node *&, Node *&);
    // Allows a node containing data of type T to be inserted into the BST.
    // This is a helper function that is called recursively where it will
    // compare the item to be inserted in the BST in the correct branch.
    // preconditions: Assumed there are no repeated input data.
    // postconditions: Inserts the node in the correct spot in the BST.

    void remove(Node*&, T);
    // Removes the specific node that contains the specific data of type T
    // inputted as the argument. This is a helper function that is called
    // recursively to remove the node. This will call the makeDeletion method
    // if the node with the specific data is found.
    // preconditions: none
    // postconditions: Deletes the node if the inputted argument data is
    //                 found, otherwise ignore remove function call.
    //                 Deallocates the node memory as well.

    void makeDeletion(Node*&, T);
    // Removes the specific node that contains the specific data of type T
    // inputted as the argument. Another helper function that is used to
    // delete the actual node itself. When remove method is called it call
    // both the private remove method and this method to help aid in the
    // removal of the node.
    // preconditions: none
    // postconditions: Deletes the node if the inputted argument data is
    //                 found, otherwise ignore remove function call.
    //                 Deallocates the node memory as well.

    void destroyTree(Node *&);
    // A method that will delete the entire tree and deallocate the memory
    // used by the nodes. A helper function used in the overloaded operator
    // method and the destructor method
    // preconditions: none
    // postconditions: Deletes the whole entire BST and deallocates the
    //                 memory used by the nodes.

    bool contains(T item, Node *&);
    // Checks if the BST contains a specific node containing data of type T.
    // This is a helper function called recursively.
    // preconditions: none
    // postconditions: Returns a boolean where true means the data of type T
    //                 is in the BST and false otherwise.


    int getLeafCount(Node *&);
    // Goes through the BST and sees how many leaf nodes are in the BST. This
    // is a helper function called recursively.
    // preconditions: none
    // postconditions: Returns an int of how many leaf nodes are in the BST.

    string getPreOrderTraversal(Node *, stringstream &);
    // Returns a string of the pre order traversal of the nodes in the BST.
    // This is a helper function called recursively.
    // preconditions: none
    // postconditions: none

    string getInOrderTraversal(Node *, stringstream &);
    // Returns a string of the in order traversal of the nodes in the BST.
    // This is a helper function called recursively.
    // preconditions: none
    // postconditions: none

    string getPostOrderTraversal(Node*, stringstream&);
    // Returns a string of the post order traversal of the nodes in the BST.
    // This is a helper function called recursively.
    // preconditions: none
    // postconditions: none

    int getHeight(Node *&);
    // Determines the height of the BST. This is a helper function called
    // recursively.
    // preconditions: none
    // postconditions: Returns an int of the height of the BST.

    int getLevel(Node *&, T, int);
    // Gets the level of a specific node of type T in the BST. This is a
    // helper function called recursively.
    // preconditions: none
    // postconditions: Returns an int of the level of the node.

    string getAncestors(Node *&, T, stringstream &);
    // Returns a string of the ancestors of particular node. If the node
    // doesn't exist returns and empty string. This is a helper function
    // called recursively.
    // preconditions: none
    // postconditions: none

    int size(int&, Node*);
    // Goes through the BST and sees how many nodes were created. This is a
    // helper function called recursively.
    // preconditions: none
    // postconditions: Returns an int of how many nodes in the BST were created.

    void copyTree(Node* &, const Node*);
    // A method used to copy a tree and create another tree. It is called
    // recursively. It is used to created a copied called by the copy
    // constructor and the overloaded assignement operator.
    // preconditions: none
    // postconditions: Creates a new tree based of an old tree.

};

template <typename T>
BST<T>::BST() {

    //Set the root node to nullptr.
    root = nullptr;

}

template <typename T>
BST<T>::~BST() {

    //Calls the destroyTree method to destroy the whole entire tree.
    destroyTree(root);
}

template <typename T>
BST<T>::BST(const BST<T> &obj) {

    //Set the new tree root to nullptr
    root = nullptr;

    //Copy the information from one to this new tree
    copyTree(root, obj.root);

}

template <typename T>
BST<T>& BST<T>::operator=(const BST &obj){

    //Checks if this object is the same as the other object that is on the
    // other side of the operator
    if(this != &obj) {

        //If it is delete the current tree
        destroyTree(root);

        //Then create a new tree and point the root pointer at the new copied
        // tree
        copyTree(root, obj.root);
    }

    //Return the pointer of the now copied tree
    return * this;
}

template <typename T>
void BST<T>::copyTree(Node*& nodeThisTree, const Node * nodeThatTree ) {

    //Checks if the current node of the other tree is null or not
    if (nodeThatTree != nullptr) {

        //If the node is not null create a new node with the same data as the
        // node we are trying to copy
        nodeThisTree = new Node;
        nodeThisTree->data = nodeThatTree->data;
        nodeThisTree->right = nullptr;
        nodeThisTree->left = nullptr;

        //Recursively go through the tree until we copy all the nodes
        copyTree(nodeThisTree->left, nodeThatTree->left);
        copyTree(nodeThisTree->right, nodeThatTree->right);
    }
}

template <typename T>
void BST<T>::destroyTree(Node *& ptr) {

    //Traverses through the node and delete the node.
    if(ptr != nullptr) {
        destroyTree(ptr->left);
        destroyTree(ptr->right);
        delete ptr;
    }

    //Set the pointer to nullptr
    ptr = nullptr;
}



template <typename T>
bool BST<T>::contains(T item) {

    //Calls the helper function
    return contains(item, root);

}


template <typename T>
bool BST<T>::contains(T item, Node *& ptr) {

    //This helper function will be used to check if the item inputted as an
    // argument is contained in the tree or not
    if(ptr == nullptr) {

        //Return false if ptr reaches null which means the BST doesn't
        // contain the specified item.
        return false;
    }

    //If the requested node item is found return true. Traverse through the
    // tree until the item is found or returns false if not found.
    if(ptr-> data == item) {
        return true;
    } else if (ptr -> data > item) {
        return contains(item, ptr->left);
    } else if (ptr -> data < item){
        return contains(item, ptr->right);
    }

    //Catch all statement
    return false;

}


template <typename T>
bool BST<T>::empty() {

    //If the root points to nullptr it means the tree is empty.
    if(root == nullptr) {
        return true;
    }
    return false;
}

template <typename T>
int BST<T>::size() {

    //Initialize an int variable to be passed onto the helper function.
    int nodeCount = 0;

    //Calls the helper size method.
    return size(nodeCount, root);
}

template <typename T>
int BST<T>::size(int& nodeCount, Node * ptr) {

    //As long as the ptr does not equal nullptr count each time a node is
    // traversed and recursively call the size function to traverse through
    // the tree.
    if(ptr !=nullptr) {
        nodeCount += 1;
        size(nodeCount, ptr->left);
        size(nodeCount, ptr->right);
    }

    //Return the amount of nodes in the tree.
    return nodeCount;
}

template <typename T>
int BST<T>::getLeafCount() {

    //Call the helper getLeafCount method
    return getLeafCount(root);
}

template <typename T>
int BST<T>::getLeafCount(Node *& ptr){

    //If the ptr is now pointing to nullptr return zero.
    if(ptr == nullptr) {
        return 0;
    }

    //If both the left and the right are pointing at nullptr that means it is
    // a leaf node and return one. Traverse through the tree on the left side
    // and the right side and add up all the leaf nodes.
    if(ptr -> left == nullptr && ptr ->right == nullptr) {
        return 1;
    } else {
        return getLeafCount(ptr->left) + getLeafCount(ptr -> right);
    }
}


template <typename T>
int BST<T>::getHeight() {

    //Call the helper getHeight method
    return getHeight(root);
}

template <typename T>
int BST<T>::getHeight(Node *& ptr) {

    //If the ptr is pointing to nullptr returns 0.
    if (ptr == nullptr) {
        return 0;
    } else {

        //Traverse through the tree recursively calling this function.
        int heightLeft = getHeight(ptr->left);
        int heightRight = getHeight(ptr->right);

        //If one side of the tree is higher than the other side return the
        // higher side of the tree.
        if (heightLeft > heightRight) {
            return (heightLeft + 1);
        } else {
            return (heightRight + 1);
        }
    }
}

template <typename T>
int BST<T>::getLevel(T item){

    //Check first if the tree contains the item to get the level
    if(contains(item)) {

        //Call the helper getLevel method
        return getLevel(root, item, 0);
    }

    //Catch all for if the node is not present
    return -1;

}

template <typename T>
int BST<T>::getLevel(Node *& ptr, T item, int level) {

    //If the ptr is null ptr that means that
    if (ptr == nullptr) {
        return -1;
    }

    //Goes through the tree until the item is found and returns the level.
    // Each time it goes down it will increment a level.
    if (ptr->data == item) {
        return level;
    } else if (ptr->data > item) {
        return getLevel(ptr->left, item, level + 1);
    } else if (ptr->data < item) {
        return getLevel(ptr->right, item, level + 1);
    }

    //Catch all to return the level
    return level;
}

template <typename T>
void BST<T>::insert(T item) {

    //Creates a new node
    Node * newNode = new Node;

    //Stores the data as the inputted item
    newNode -> data = item;

    //Sets the left and right to nullptr
    newNode->left = newNode ->right = nullptr;

    //Calls the helper insert method
    insert(root, newNode);
}


template <typename T>
void BST<T>::insert(Node *& ptr, Node *& newNode) {

    //Anytime a ptr reaches a point where it is pointing to nothing, insert
    // the node there. Traverses the tree by comparing the data value and the
    // value of the new node to be inserted. If new node is less than
    // current ptr, then move to the left, otherwise, right.
    if (ptr == nullptr) {
        ptr = newNode;
    } else if (ptr->data > newNode->data) {
        insert(ptr->left, newNode);
    } else {
        insert(ptr->right, newNode);
    }
}


template <typename T>
void BST<T>::remove(T item) {

    //Checks to see if the item is in the tree
    if(contains(item)) {

        //If the item is in the tree, call the helper remove method
        remove(root, item);
    }
}

template <typename T>
void BST<T>::remove(Node *& ptr, T item) {

    //Check if the ptr is not a null pointer, traverse through the tree by
    // comparing the current ptr data to that of the item. If it matches call
    // the make deletion method.
    if (ptr != nullptr) {
        if (ptr->data > item)
            remove(ptr->left, item);
        else if (ptr->data < item)
            remove(ptr->right, item);
        else
            makeDeletion(ptr, item);
    }
}

template <typename T>
void BST<T>::makeDeletion(Node *& ptr, T item) {

    //initialize a curr pointer
    Node *curr = nullptr;
    if (ptr != nullptr) {

        //Case where the left is null, one child set the node on the right as
        // the new node to join. Same thing applies for the right side when
        // null.
        if (ptr->left == nullptr) {
            curr = ptr;
            ptr = ptr->right;
            delete curr;
        } else if (ptr->right == nullptr) {
            curr = ptr;
            ptr = ptr->left;
            delete curr;
        } else {

            //This is the case where there are two children
            curr = ptr->right;
            while (curr->left != nullptr) {
                curr = curr->left;
            }

            //Slowly inch down to the next inorder successor
            ptr->data = curr->data;
            remove(ptr->right, curr->data);
        }
    }
}


template <typename T>
string BST<T>::getPreOrderTraversal() {

    //Create a stringstream
    stringstream ss;

    //Call the helper method getPreOrderTraversal
    return getPreOrderTraversal(root, ss);
}


template <typename T>
string BST<T>::getPreOrderTraversal(Node * ptr, stringstream& ss) {

    //Traverse down the tree using the preorder of root, left, right,
    // recursively
    if(ptr !=nullptr) {
        ss << ptr->data << " ";
        getPreOrderTraversal(ptr->left, ss);
        getPreOrderTraversal(ptr->right, ss);
    }

    //return the string
    return ss.str();
}

template <typename T>
string BST<T>::getInOrderTraversal() {

    //Create a stringstream
    stringstream ss;

    //Call the helper method getInOrderTraversal
    return getInOrderTraversal(root,ss);
}

template <typename T>
string BST<T>::getInOrderTraversal(Node* ptr, stringstream& ss) {

    //Traverse down the tree using the inorder of left, root, right,
    // recursively
    if (ptr != nullptr) {
        getInOrderTraversal(ptr->left, ss);
        ss << ptr->data<<" ";
        getInOrderTraversal(ptr->right, ss);
    }

    //return the string
    return ss.str();
}


template <typename T>
string BST<T>::getPostOrderTraversal() {

    //Create a stringstream
    stringstream ss;

    //Call the helper method getPostOrderTraversal
    return getPostOrderTraversal(root, ss);
}

template <typename T>
string BST<T>::getPostOrderTraversal(Node*ptr, stringstream& ss) {

    //Traverse down the tree using the inorder of left, right, root,
    // recursively
    if(ptr != nullptr) {
        getPostOrderTraversal(ptr->left, ss);
        getPostOrderTraversal(ptr->right, ss);
        ss << ptr->data <<" ";

    }
    //return the string
    return ss.str();
}



template <typename T>
string BST<T>::getAncestors(T item) {

    //Create a stringstream
    stringstream ancestorString;

    //Call the helper method getAncestors
    return getAncestors(root, item, ancestorString);
}


template <typename T>
string BST<T>::getAncestors(Node *& ptr, T item, stringstream &
    ancestorString) {

    //Check if the item is in the tree before trying to get the ancestor
    if(contains(item)) {

        //Return the string of where it currently is. If it is the first
        // node, it is an empty string. Add the ancestorString as more and
        // more nodes are traversed. getAncestors is called recursively.
        if (ptr->data == item) {
            return ancestorString.str();
        } else if (ptr->data < item) {
            getAncestors(ptr->right, item, ancestorString);
            ancestorString << ptr->data << " ";
            return ancestorString.str();

        } else if (ptr->data > item) {
            getAncestors(ptr->left, item, ancestorString);
            ancestorString << ptr->data << " ";
            return ancestorString.str();
        }
    }

    //Catch all that will return empty string if the node doesn't exist
    return "";


}


#endif //P2_BST_H
