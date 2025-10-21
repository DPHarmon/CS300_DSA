//============================================================================
// Name        : BinarySearchTree.cpp
// Author      : Dylan Harmon
// Version     : 1.0
// Copyright   : Copyright � 2023 SNHU COCE
// Description : Lab 5-2 Binary Search Tree
//============================================================================

#include <iostream>
#include <time.h>

#include "CSVparser.hpp"

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

// forward declarations
double strToDouble(string str, char ch);

// define a structure to hold bid information
struct Bid {
    string bidId; // unique identifier
    string title;
    string fund;
    double amount;
    Bid() {
        amount = 0.0;
    }
};

// Internal structure for tree node
struct Node {
    Bid bid;
    Node *left;
    Node *right;

    // default constructor
    Node() {
        left = nullptr;
        right = nullptr;
    }

    // initialize with a bid
    Node(Bid aBid) :
            Node() {
        bid = aBid;
    }
};

//============================================================================
// Binary Search Tree class definition
//============================================================================

/**
 * Define a class containing data members and methods to
 * implement a binary search tree
 */
class BinarySearchTree {

private:
    Node* root;

    void addNode(Node* node, Bid bid);
    void inOrder(Node* node);
    void postOrder(Node* node);
    void preOrder(Node* node);
    Node* removeNode(Node* node, string bidId);

public:
    BinarySearchTree();
    virtual ~BinarySearchTree();
    void InOrder();
    void PostOrder();
    void PreOrder();
    void Insert(Bid bid);
    void Remove(string bidId);
    Bid Search(string bidId);
};

/**
 * Default constructor
 * Author: Dylan Harmon
 * Date: 7/29/2025
 */
BinarySearchTree::BinarySearchTree() {

	root = nullptr; // initialize root to null pointer
}

/**
 * Destructor
 * Author: Dylan Harmon
 * Date: 7/29/2025
 */
BinarySearchTree::~BinarySearchTree() {

    while (root != nullptr) {

        // remove all nodes from the tree
        removeNode(root, root->bid.bidId);
	}
}

/**
 * Traverse the tree in order
 * Author: Dylan Harmon
 * Date: 7/29/2025
 */
void BinarySearchTree::InOrder() {
   
    // call inOrder fuction and pass root
	this->inOrder(root);
}

/**
 * Traverse the tree in post-order
 * Author: Dylan Harmon
 * Date: 7/29/2025
 */
void BinarySearchTree::PostOrder() {
    
    // postOrder root
	this->postOrder(root);
}

/**
 * Traverse the tree in pre-order
 * Author: Dylan Harmon
 * Date: 7/29/2025
 */
void BinarySearchTree::PreOrder() {
    
    // preOrder root
	this->preOrder(root);
}



/**
 * Insert a bid
 * Author: Dylan Harmon
 * Date: 7/28/2025
 */
void BinarySearchTree::Insert(Bid bid) {
    
    
    if (root == nullptr) {
		root = new Node(bid); // if root is null, create a new node
     
    }
    else {
		addNode(root, bid);
    }
}

/**
 * Remove a bid
 * Author: Dylan Harmon
 * Date: 7/28/2025
 */
void BinarySearchTree::Remove(string bidId) {
    
	this->removeNode(root, bidId); // call removeNode with root and bidId
}

/**
 * Search for a bid
 * Author: Dylan Harmon
 * Date: 7/28/2025
 */
Bid BinarySearchTree::Search(string bidId) {
    
	Node* current = root; // start at root

	/* while current node is not equal to null
        if current node bidId matches bidId return current node bid
        else if bidId is smaller than current node bidId then traverse left
		else traverse right
    */
    while (current != nullptr) {
        if (current->bid.bidId.compare(bidId) == 0) {
            return current->bid;
        }
        else if (bidId.compare(current->bid.bidId) < 0) {
            current = current->left; // traverse left
        } else {
            current = current->right; // traverse right
		}
    }
	// if no match found return empty bid
	std::cout << "Bid ID " << bidId << " not found." << endl;


    Bid bid;
    return bid;
}

/**
 * Add a bid to some node (recursive)
 *
 * @param node Current node in tree
 * @param bid Bid to be added
 * 
 * Author: Dylan Harmon
 * Date: 7/28/2025
 */
void BinarySearchTree::addNode(Node* node, Bid bid) {
    
        if (node->bid.bidId.compare(bid.bidId) > 0) {
            if (node->left == nullptr){ //if no left node
				node->left = new Node(bid); // this node becomes left child node
			}
			else { // recurse down the left node
				this->addNode(node->left, bid);
            }
		}
        else { // add to right subtree
			if (node->right == nullptr) { // if no right node
				node->right = new Node(bid); // this node becomes right child node

			}
			else { // recurse down the right node
				this->addNode(node->right, bid);
            }

        }
}
/*
* Traverse the tree in order
* @param node Current node in tree
* 
* Author: Dylan Harmon
* Date: 7/29/2025
*/
void BinarySearchTree::inOrder(Node* node) {

    if (node != nullptr) {
        inOrder(node->left);

        std::cout << node->bid.bidId << ": " 
            << node->bid.title << " | " 
            << node->bid.amount << " | "
            << node->bid.fund << endl;

        inOrder(node->right);
        }
}
/**
 * Traverse the tree in post-order
 * @param node Current node in tree
 * 
 * Author: Dylan Harmon
 * Date: 7/29/2025
 */
void BinarySearchTree::postOrder(Node* node) {
     
    if (node != nullptr) {
        postOrder(node->left);
        postOrder(node->right);
        std::cout << node->bid.bidId << ": "
            << node->bid.title << " | "
            << node->bid.amount << " | "
            << node->bid.fund << endl;
    }
}
/*
*
* Traverse the tree in pre-order
* @param node Current node in tree
* Author: Dylan Harmon
* Date: 7/29/2025
* 
*/
void BinarySearchTree::preOrder(Node * node) {

    if (node != nullptr) {
        std::cout << node->bid.bidId << ": "
                    << node->bid.title << " | "
                    << node->bid.amount << " | " 
                    << node->bid.fund << endl;

            preOrder(node->left);
            preOrder(node->right);
        }
 }

/**
 * Remove a bid from some node (recursive)
 * 
 * Author: Dylan Harmon
 * Date: 7/29/2025
 */
Node* BinarySearchTree::removeNode(Node* node, string bidId) {
    // FIXME (7b) Implement removing a bid from the tree
    // if this node is null then return
    if (node == nullptr) {
		return node; // return null pointer
    }

	//recurse down the left subtree
    if (bidId.compare(node->bid.bidId) < 0) {
		node->left = removeNode(node->left, bidId); // check left node
    }
    else if (bidId.compare(node->bid.bidId) > 0) { // recurse down the right subtree
		node->right = removeNode(node->right, bidId); // check right node
    }
    else {
        // leaf node (no children)
        if (node->left == nullptr && node->right == nullptr) {
            delete node; // delete node
            node = nullptr;
		}
        // one child (left)
        else if (node->left != nullptr && node->right == nullptr) {
			Node* temp = node; // create a temp node
            node = node->left;
			delete temp; // delete temp node
        }
        // one child (right)
        else if (node->left == nullptr && node->right != nullptr) {
            Node* temp = node; // create a temp node
            node = node->right;
            delete temp; // delete temp node
        }
        // two children
        else {
            Node* temp = node->right; // create a temp node to right
            while (temp->left != nullptr) { // while left node is not null
                temp = temp->left; // keep moving left
            }
            node->bid = temp->bid; // make node bid equal to temp bid
            node->right = removeNode(node->right, temp->bid.bidId); // remove right node using recursive call
		}
    }
    return node;
}



//============================================================================
// Static methods used for testing
//============================================================================

/**
 * Display the bid information to the console (std::out)
 *
 * @param bid struct containing the bid info
 */
void displayBid(Bid bid) {
    cout << bid.bidId << ": " << bid.title << " | " << bid.amount << " | "
            << bid.fund << endl;
    return;
}

/**
 * Load a CSV file containing bids into a container
 *
 * @param csvPath the path to the CSV file to load
 * @return a container holding all the bids read
 */
void loadBids(string csvPath, BinarySearchTree* bst) {
    cout << "Loading CSV file " << csvPath << endl;

    // initialize the CSV Parser using the given path
    csv::Parser file = csv::Parser(csvPath);

    // read and display header row - optional
    vector<string> header = file.getHeader();
    for (auto const& c : header) {
        cout << c << " | ";
    }
    cout << "" << endl;

    try {
        // loop to read rows of a CSV file
        for (unsigned int i = 0; i < file.rowCount(); i++) {

            // Create a data structure and add to the collection of bids
            Bid bid;
            bid.bidId = file[i][1];
            bid.title = file[i][0];
            bid.fund = file[i][8];
            bid.amount = strToDouble(file[i][4], '$');

            //cout << "Item: " << bid.title << ", Fund: " << bid.fund << ", Amount: " << bid.amount << endl;

            // push this bid to the end
            bst->Insert(bid);
        }
    } catch (csv::Error &e) {
        std::cerr << e.what() << std::endl;
    }
}

/**
 * Simple C function to convert a string to a double
 * after stripping out unwanted char
 *
 * credit: http://stackoverflow.com/a/24875936
 *
 * @param ch The character to strip out
 */
double strToDouble(string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());
    return atof(str.c_str());
}

/**
 * The one and only main() method
 */
int main(int argc, char* argv[]) {

    // process command line arguments
    string csvPath, bidKey;
    switch (argc) {
    case 2:
        csvPath = argv[1];
        bidKey = "98223";
        break;
    case 3:
        csvPath = argv[1];
        bidKey = argv[2];
        break;
    default:
        csvPath = "eBid_Monthly_Sales.csv";
        bidKey = "98223";
    }

    // Define a timer variable
    clock_t ticks;

    // Define a binary search tree to hold all bids
    BinarySearchTree* bst;
    bst = new BinarySearchTree();
    Bid bid;

    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Load Bids" << endl;
        cout << "  2. Display All Bids" << endl;
        cout << "  3. Find Bid" << endl;
        cout << "  4. Remove Bid" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            
            // Initialize a timer variable before loading bids
            ticks = clock();

            // Complete the method call to load the bids
            loadBids(csvPath, bst);

            //cout << bst->Size() << " bids read" << endl;

            // Calculate elapsed time and display result
            ticks = clock() - ticks; // current clock ticks minus starting clock ticks
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
            break;

        case 2:
            bst->InOrder();
            break;

        case 3:
            ticks = clock();

            bid = bst->Search(bidKey);

            ticks = clock() - ticks; // current clock ticks minus starting clock ticks

            if (!bid.bidId.empty()) {
                displayBid(bid);
            } else {
            	cout << "Bid Id " << bidKey << " not found." << endl;
            }

            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

            break;

        case 4:
            bst->Remove(bidKey);
            break;
        }
    }

    cout << "Good bye." << endl;

	return 0;
}
