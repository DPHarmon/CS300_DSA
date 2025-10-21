//============================================================================
// Name        : VectorSorting.cpp
// Author      : Dylan Harmon; CS300; July 13, 2025
// Version     : 1.0
// Copyright   : Copyright © 2023 SNHU COCE
// Description : Vector Sorting Algorithms
//============================================================================

#include <algorithm>
#include <iostream>
#include <time.h>
#include <utility>

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
 * Prompt user for bid information using console (std::in)
 *
 * @return Bid struct containing the bid info
 */
Bid getBid() {
    Bid bid;

    cout << "Enter Id: ";
    cin.ignore();
    getline(cin, bid.bidId);

    cout << "Enter title: ";
    getline(cin, bid.title);

    cout << "Enter fund: ";
    cin >> bid.fund;

    cout << "Enter amount: ";
    cin.ignore();
    string strAmount;
    getline(cin, strAmount);
    bid.amount = strToDouble(strAmount, '$');

    return bid;
}

/**
 * Load a CSV file containing bids into a container
 *
 * @param csvPath the path to the CSV file to load
 * @return a container holding all the bids read
 */
vector<Bid> loadBids(string csvPath) {
    cout << "Loading CSV file " << csvPath << endl;

    // Define a vector data structure to hold a collection of bids.
    vector<Bid> bids;

    // initialize the CSV Parser using the given path
    csv::Parser file = csv::Parser(csvPath);

    try {
        // loop to read rows of a CSV file
        for (int i = 0; i < file.rowCount(); i++) {

            // Create a data structure and add to the collection of bids
            Bid bid;
            bid.bidId = file[i][1];
            bid.title = file[i][0];
            bid.fund = file[i][8];
            bid.amount = strToDouble(file[i][4], '$');

            //cout << "Item: " << bid.title << ", Fund: " << bid.fund << ", Amount: " << bid.amount << endl;

            // push this bid to the end
            bids.push_back(bid);
        }
    }
    catch (csv::Error& e) {
        std::cerr << e.what() << std::endl;
    }
    return bids;
}

// FIXME (2a): Implement the quick sort logic over bid.title

/**
 * Partition the vector of bids into two parts, low and high
 *
 * @param bids Address of the vector<Bid> instance to be partitioned
 * @param begin Beginning index to partition
 * @param end Ending index to partition
 */
/*
 *Date: 7/13/2025
 * Author: Dylan Harmon
 */
int partition(vector<Bid>& bids, int begin, int end) {

	// set the pivot index to the middle of the vector
    int pivot = end;
	int i = (begin - 1); // index for the smaller element

    for (int j = begin; j <= end - 1; j++) {

		// if the current element's title is less than the pivot's title
        if (bids[j].title < bids[pivot].title) {

            i++; // increment index for smaller element
            swap(bids[i], bids[j]); // swap the smaller element with the current element
        }
    }
	swap(bids[i + 1], bids[pivot]); // place the pivot element in the correct position
    
    
    return i + 1;
}

/**
 * Perform a quick sort on bid title
 * Average performance: O(n log(n))
 * Worst case performance O(n^2))
 *
 * @param bids address of the vector<Bid> instance to be sorted
 * @param begin the beginning index to sort on
 * @param end the ending index to sort on
 */
/*
 * Date: 7/13/2025
 * Author: Dylan Harmon
 */
void quickSort(vector<Bid>& bids, int begin, int end) {
    
    if (begin < end) {
		// call the partition function to define the pivot
		int pivot = partition(bids, begin, end);

		// recursively sort low partition (begin to pivot - 1)
		quickSort(bids, begin, pivot - 1);
		quickSort(bids, pivot + 1, end); // recursively sort high partition (pivot + 1 to end)

    }
    

}

// FIXME (1a): Implement the selection sort logic over bid.title

/**
 * Perform a selection sort on bid title
 * Average performance: O(n^2))
 * Worst case performance O(n^2))
 *
 * @param bid address of the vector<Bid>
 *            instance to be sorted
 */
/*
* Date: 7/13/2025
* Author: Dylan Harmon 
*/
void selectionSort(vector<Bid>& bids) {
 
	// for loop where i denotes the dividing point where elements to the left are sorted.
	// elements including I and to the right are unsorted.
    for (int i = 0; i < bids.size() - 1; ++i) {
        // set minIndex to i
        int minIndex = i;

		// search the unsorted elements to the right of i
		// for the smallest element: minIndex stores the index of the smallest element found.
        
        for (int j = i + 1; j < bids.size(); ++j) {

            // if this element's title is less than minimum title
                // this element becomes the minimum
            if (bids[j].title < bids[minIndex].title) {
                minIndex = j;
            }
        }

        // Indeces for the sorted and unsorted parts are updated

        std::swap(bids[i], bids[minIndex]);
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
    string csvPath;
    switch (argc) {
    case 2:
        csvPath = argv[1];
        break;
    default:
        csvPath = "eBid_Monthly_Sales.csv";
    }

    // Define a vector to hold all the bids
    vector<Bid> bids;

    // Define a timer variable
    clock_t ticks;

    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Load Bids" << endl;
        cout << "  2. Display All Bids" << endl;
        cout << "  3. Selection Sort All Bids" << endl;
        cout << "  4. Quick Sort All Bids" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            // Initialize a timer variable before loading bids
            ticks = clock();

            // Complete the method call to load the bids
            bids = loadBids(csvPath);

            cout << bids.size() << " bids read" << endl;

            // Calculate elapsed time and display result
            ticks = clock() - ticks; // current clock ticks minus starting clock ticks
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

            break;

        case 2:
            // Loop and display the bids read
            for (int i = 0; i < bids.size(); ++i) {
                displayBid(bids[i]);
            }
            cout << endl;

            break;

        case 3:
            // switch for selection sort
            // start clock with ticks, then invoke selection sort
            ticks = clock();

            selectionSort(bids);

            // after sort; end clock and calculate time elapsed
            ticks = clock() - ticks; // current clock ticks minus starting clock ticks gives time elapsed

			cout << bids.size() << " bids sorted" << endl;
            // display time in ticks and in seconds
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;


            break;
        case 4:
            // switch for quick sort
            

            // start clock with ticks, then invoke quick sort
            ticks = clock();
            quickSort(bids, 0, bids.size() - 1);

            // after sort; end clock and calculate time elapsed
			ticks = clock() - ticks; // current clock ticks minus starting clock ticks gives time elapsed

            cout << bids.size() << " bids sorted" << endl;

            // display time in ticks and in seconds
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

            break;
        
		case 9:
			// Exit the program
			cout << "Exiting program..." << endl;
            break;

        default:
			cout << "Invalid choice, please try again." << endl;
			


        }
    }

    cout << "Good bye." << endl;

    return 0;
}
