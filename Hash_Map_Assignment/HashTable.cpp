//============================================================================
// Name        : HashTable.cpp
// Author      : Dylan Harmon
// Version     : 1.0
// Copyright   : Copyright © 2023 SNHU COCE
// Description : Lab 4-2 Hash Table
//============================================================================

#include <algorithm>
#include <climits>
#include <iostream>
#include <string> // atoi
#include <time.h>

#include "CSVparser.hpp"

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

// Default size of the hash table
const unsigned int DEFAULT_SIZE = 179;

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

//============================================================================
// Hash Table class definition
//============================================================================

/**
 * Define a class containing data members and methods to
 * implement a hash table with chaining.
 */
class HashTable {

private:
    // Define structures to hold bids
    struct Node {
        Bid bid;
        unsigned int key;
        Node* next;

        // default constructor
        Node() {
            key = UINT_MAX;
            next = nullptr;
        }

        // initialize with a bid
        Node(Bid aBid) : Node() {
            bid = aBid;
        }

        // initialize with a bid and a key
        Node(Bid aBid, unsigned int aKey) : Node(aBid) {
            key = aKey;
        }
    };

    vector<Node> nodes;

    unsigned int tableSize = DEFAULT_SIZE;

    unsigned int hash(int key);

public:
    HashTable();
    HashTable(unsigned int size);
    virtual ~HashTable();
    void Insert(Bid bid);
    void PrintAll();
    void Remove(string bidId);
    Bid Search(string bidId);
    size_t Size();
};

// def size_t Size() to count bids in hash table
/*
* Author: Dylan Harmon
* Date: 7/27/2025
* 
* @param None
* @return size_t The number of bids in the hash table
*/
size_t HashTable::Size() {
    size_t count = 0;

	//Iterate through each bucket in the hash table
    for (unsigned int i = 0; i < tableSize; ++i) {
		Node* currNode = &nodes[i];

        //count nodes in current bucket
        while (currNode != nullptr) {
			++count; // increment count
			currNode = currNode->next; // move to next node
        }
    }
	return count; // return total count of bids
}


/**
 * Default constructor
 * Author: Dylan Harmon
 * Date: 7/27/2025
 */
HashTable::HashTable() {
    // Initalize node structure by resizing tableSize
    nodes.resize(tableSize);
}

/**
 * Constructor for specifying size of the table
 * Use to improve efficiency of hashing algorithm
 * by reducing collisions without wasting memory.
 * Author: Dylan Harmon
 * Date: 7/27/2025
 */
HashTable::HashTable(unsigned int size) {
    // invoke local tableSize to size with this->
	this->tableSize = size;
    // resize nodes size
	nodes.resize(tableSize);
}


/**
 * Destructor
 * Author: Dylan Harmon
 * Date: 7/27/2025
 */
HashTable::~HashTable() {
    
    for (unsigned int i = 0; i < tableSize; ++i) {
        // Start at head of list for bucket
		Node* currNode = nodes[i].next;

        // Iterate through linked list
        while (currNode != nullptr) {
			Node* tempNode = currNode;
            currNode = currNode->next;
			// Delete the current node
			delete tempNode;
        }

		//Set pointer to nullptr
		nodes[i].next = nullptr;
	}
    //	Only delete dynamically allocated nodes in the chain when removing a bid
}

/**
 * Calculate the hash value of a given key.
 * Note that key is specifically defined as
 * unsigned int to prevent undefined results
 * of a negative list index.
 *
 * @param key The key to hash
 * @return The calculated hash
 * 
 * Author: Dylan Harmon
 * Date: 7/27/2025
 */
unsigned int HashTable::hash(int key) {
    
    // return key tableSize
	return key % tableSize;
}

/**
 * Insert a bid
 *
 * @param bid The bid to insert
 * 
 * Author: Dylan Harmon
 * Date: 7/27/2025
 */
void HashTable::Insert(Bid bid) {
	unsigned int bucket = hash(atoi(bid.bidId.c_str()));
	Node* node = &nodes[bucket];

	// Insert if bucket is empty
    if (node->key == UINT_MAX) {
		node->key = bucket; // set key to bucket
		node->bid = bid; // set bid to node
		node->next = nullptr; // set next to nullptr
		return; // exit method after inserting
	}

	// traverse list, check for duplicates, insert at end
	Node* currNode = node;
    while (currNode->next != nullptr) {
        if (currNode->bid.bidId == bid.bidId) {
			// Duplicate found, no insertion
            return;
        }
		currNode = currNode->next; // move to next node
    }

    // check last node for duplicate
    if (currNode->bid.bidId == bid.bidId) {
        // Duplicate found, no insertion
        return;
	}
    // Insert new node at the end 
    currNode->next = new Node(bid, bucket);

}

/**
 * Print all bids
 * 
 * Author: Dylan Harmon
 * Date: 7/27/2025
 */
void HashTable::PrintAll() {

    for (unsigned int i = 0; i < tableSize; ++i) {
        Node* currNode = &nodes[i];
        // Only print node if in use
        /*
		* Bid Format: Key #: bidId | title | amount | fund
        */
        if (currNode->key != UINT_MAX) {
            cout<< "Key " << currNode->key << ": " << currNode->bid.bidId << " | "
                << currNode->bid.title << " | "
                << currNode->bid.amount << " | "
		        << currNode->bid.fund << endl;

            // Traverse cahined nodes
            while (currNode != nullptr) {
                cout << currNode->key << ": " << currNode->bid.bidId << " | "
                    << currNode->bid.title << " | "
                    << currNode->bid.amount << " | "
					<< currNode->bid.fund << endl;
				currNode = currNode->next; // move to next node
            }
        }
    }
}

/**
 * Remove a bid
 *
 * @param bidId The bid id to search for
 * 
 * Author: Dylan Harmon
 * Date: 7/27/2025
 */
void HashTable::Remove(string bidId) {

	unsigned int bucket = hash(atoi(bidId.c_str()));
	Node* node = &nodes[bucket];

	// If the bucket is empty, return
    if (node->key == UINT_MAX) {
		return; // nothing to remove
    }

    // If head node matches, remove head node
    if (node->bid.bidId == bidId) {
        if (node->next != nullptr) {
			// Move head to next node and delete current head
            Node* tempNode = node->next;
            node->bid = tempNode->bid;
            node->key = tempNode->key;
            node->next = tempNode->next;
            delete tempNode;
        }
        else {
            // If no next node, just reset head node
            node->key = UINT_MAX; // reset key
            node->bid = Bid(); // reset bid
			node->next = nullptr; // reset next pointer
        }
        return;
    }

    // If not the head node, search the chain
	Node* prevNode = node;
	Node* currNode = node->next;
    while (currNode != nullptr) {
        if (currNode->bid.bidId == bidId) {
            prevNode->next = currNode->next; // unlink current node
            delete currNode; // remove desired node
            return;
        }
		prevNode = currNode; // move to next node
        currNode = currNode->next;
    }
}

/**
 * Search for the specified bidId
 *
 * @param bidId The bid id to search for
 * 
 * Author: Dylan Harmon
 * Date: 7/27/2025
 */
Bid HashTable::Search(string bidId) {

    // use bidId to find bucket
	unsigned int bucket = hash(atoi(bidId.c_str()));
    Node* node = &nodes[bucket];

	// IF bucket is empty, return empty bid
    if (node->key == UINT_MAX) {
        return Bid();
    }

    // Iterate through chain to find the bid
    Node* currNode = node;
    while (currNode != nullptr) {
        if (currNode->bid.bidId == bidId) {
			return currNode->bid; //return matching bid
        }
		currNode = currNode->next; // move to next node
    }

	// If no match found, return empty bid
    return Bid();
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
    std::cout << bid.bidId << ": " << bid.title << " | " << bid.amount << " | "
        << bid.fund << endl;
    return;
}

/**
 * Load a CSV file containing bids into a container
 *
 * @param csvPath the path to the CSV file to load
 * @return a container holding all the bids read
 */
void loadBids(string csvPath, HashTable* hashTable) {
    std::cout << "Loading CSV file " << csvPath << endl;

    // initialize the CSV Parser using the given path
    csv::Parser file = csv::Parser(csvPath);

    /*  DH
    // read and display header row - optional
    vector<string> header = file.getHeader();
    for (auto const& c : header) {
        std::cout << c << " | ";    
	}*/
    std::cout << "" << endl;

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
            hashTable->Insert(bid);
        }
    }
    catch (csv::Error& e) {
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

    // Define a hash table to hold all the bids
    HashTable* bidTable;

    Bid bid;
    bidTable = new HashTable();

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
            loadBids(csvPath, bidTable);

            // Calculate elapsed time and display result
            ticks = clock() - ticks; // current clock ticks minus starting clock ticks

            cout << bidTable->Size() << " bids read" << endl;//DH
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
            break;

        case 2:
            bidTable->PrintAll();
            break;

        case 3:
            ticks = clock();

            bid = bidTable->Search(bidKey);

            ticks = clock() - ticks; // current clock ticks minus starting clock ticks

            if (!bid.bidId.empty()) {
                displayBid(bid);
            }
            else {
                cout << "Bid Id " << bidKey << " not found." << endl;
            }

            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
            break;

        case 4:
            bidTable->Remove(bidKey);
            break;
        }
    }

    cout << "Good bye." << endl;

    return 0;
}