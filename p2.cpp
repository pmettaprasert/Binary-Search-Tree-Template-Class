// Phubeth Mettaprasert
// File: p2.cpp
// Date: May 9th, 2022
// Purpose: This program is designed to create a BST with basic
//          functionalities of displaying BST info and manipulating the BST.
// Input: To test the BST, a file of int type and string type is needed to
//        show the BST.
// Process: The files will then be read, inserted into a BST where various
//          methods called from the main driver will display information as
//          well as manipulate the BST.
// Output: User should be able to see information about the file read, the
//         BST and the various modifications done to the BST on the screen.

#include <iostream>
#include <fstream>
#include "BST.h"
using namespace std;

string promptIntFile();
// Prompt the user for the integer filename.
// IN: none
// MODIFY: none.
// OUT: Returns the string of the prompted file name.

string promptStringFile();
// Prompt the user for the string filename.
// IN: none
// MODIFY: none.
// OUT: Returns the string of the prompted file name.

void printIntIntro(BST<int> &);
// Prints the banner for the introduction for the int BST. Calls the
// printBSTStats that will display stats for the intBST.
// IN: none
// MODIFY: none.
// OUT: Prints out banner. Prints out the intBST stats.

void printStringIntro(BST<string> &);
// Prints the banner for the introduction for the string BST. Calls the
// printBSTStats that will display stats for the stringBST.
// IN: none
// MODIFY: none.
// OUT: Prints out banner. Prints out the stringBST stats.


string convertToLower(string);
// A function that will convert a string to lowercase and also eliminate
// whitespace in between words.
// IN: The string line.
// MODIFY: Changes the string to be lowercase and also eliminate whitespace
//         in between the words.
// OUT: Returns the string in lowercase with no whitespace in between words.

void printProgramIntro();
// Prints the introductory text of the program.
// IN: none
// MODIFY: none.
// OUT: Prints out text.

void printProgramOutro();
// Prints the goodbye text of the program.
// IN: none
// MODIFY: none.
// OUT: Prints out text.

template<typename T>
void printBSTStats(BST<T> &);
// Prints out the stats of BST the number of nodes, the number of leaves,
// tree height and whether the tree is empty.
// IN: A BST of datatype T.
// MODIFY: none.
// OUT: Prints out stats of the BST.

void storeIntTree(const string&, BST<int> &);
// Reads the file and stores the data of type int (specific for int BST) into
// the BST.
// IN: String filename and the integer BST.
// MODIFY: Inserts the data read from the file into the BST.
// OUT: Returns nothing as the BST is modified by reference so the original
//      BST is modified automatically.

void storeStringTree(const string&, BST<string> &);
// Reads the file and stores the data of type string (specific for string BST)
// into the BST.
// IN: String filename and the string BST.
// MODIFY: Inserts the data read from the file into the BST.
// OUT: Returns nothing as the BST is modified by reference so the original
//      BST is modified automatically.

template<typename T>
void printTestTraversals(BST<T> &);
// Prints out the different traversals of a BST
// IN: The BST of datatype T (any type)
// MODIFY: none
// OUT: Prints out the string of the preorder, inorder, and postorder
//      traversal of the inputted BST.

template <typename T>
void printTestContain(BST<T> &, T *);
// Prints out whether some hard coded data is in the BST or not. Tests
// whether the contain method works.
// IN: none
// MODIFY: none
// OUT: Prints to console whether the data is contained in the BST or not.


void printLevelAncestorInt(BST<int> &);
// Prints out the level and the ancestors of each node in the tree, only
// applies to the int tree since the read preorder needs to be converted to int.
// IN: none
// MODIFY: none
// OUT: Prints to console the ancestors and the levels of the nodes in the
//      intBST.


void printLevelAncestorString(BST<string> &);
// Prints out the level and the ancestors of each node in the tree
// IN: none
// MODIFY: none
// OUT: Prints to console the ancestors and the levels of the nodes in the
//     stingBST.

template <typename T>
void printPreOrderOnly(BST<T> &);
// Prints out the pre-order traversal of a BST and prints out the banner for
// TEST INSERT section
// IN: A BST of datatype T.
// MODIFY: none
// OUT: The pre-order traversal of a BST.

template<typename T>
void printRemove(BST<T> &, T *);
// Prints out an array of data hardcoded to test the remove function on the BST.
// IN: The hardcoded array of type T in the main driver function and the BST
//     of type T.
// MODIFY: Removes the nodes that are found in the array from the BST.
// OUT: Prints BST stats and the new traversals for the BST.

template <typename T>
void printInsert(BST<T> &, T *);
// Prints out an array of data hardcoded to test the insert function on the BST.
// IN: The hardcoded array of type T in the main driver function and the BST
//     of type T.
// MODIFY: Insert the nodes that are found in the array from the BST.
// OUT: Prints BST stats and the new traversals for the BST.


template <typename T>
void combinedIntBSTFunctions(BST<T> & intBST, T *);
// Combines the all the different functions for the intBST into one function.
// IN: The hardcoded array of type T in the main driver function and the BST
//     of type T.
// MODIFY: Functions called in this function will modify the Tree in various
//         ways.
// OUT: Prints out different BST stats and what is done to the BST

template <typename T>
void combinedStringBSTFunctions(BST<T> & stringBST, T *);
// Combines the all the different functions for the stringBST into one function.
// IN: The hardcoded array of type T in the main driver function and the BST
//     of type T.
// MODIFY: Functions called in this function will modify the Tree in various
//         ways.
// OUT: Prints out different BST stats and what is done to the BST

int main() {

    //Print the introduction string
    printProgramIntro();

    //Hard coded int array to test
    int arrInt[8] = {20, 40, 10, 70, 99, -2, 59, 43};

    //Create the int BST
    BST<int> intBST;

    //Print out the int BST intro
    printIntIntro(intBST);

    //Prompt for file name
    string intFile = promptIntFile();

    //Store the data read into the BST
    storeIntTree(intFile, intBST);

    //A function that combines multiple functions that will print out various
    // information as well as modifies the BST.
    combinedIntBSTFunctions(intBST, arrInt);

    //Hard coded string array to test
    string arrString[8] = {"gene", "mary", "bea", "uma",
                           "yan", "amy", "ron", "opal"};

    //Create the string BST
    BST<string> stringBST;

    //Print out the string BST intro
    printStringIntro(stringBST);

    //Prompt for file name
    string stringFile = promptStringFile();

    //Store the data read into the BST
    storeStringTree(stringFile, stringBST);

    //A function that combines multiple functions that will print out various
    // information as well as modifies the BST.
    combinedStringBSTFunctions(stringBST, arrString);

    //Prints the goodbye message
    printProgramOutro();

}

void printProgramIntro() {

    //Prints out the welcome message
    cout << "\nWelcome. This program will read a file with a certain data type."
        << "\nEach line of that data will then be stored in a binary "
           "search tree."
        << "\nOperations will be performed on the binary search tree.\n" <<
        endl;
}

void printProgramOutro(){

    //Prints out goodbye message
    cout << "\nGoodbye.";
}

string promptIntFile() {

    //Prompts for the integer file name
    string intFile;
    cout << "\nEnter integer file:";
    cin >> intFile;
    return intFile;
}

string promptStringFile() {

    //Prompts for the string file name
    string stringFile;
    cout << "\nEnter string file:";
    cin >> stringFile;
    return stringFile;
}

void storeIntTree(const string& filename, BST<int> & intBST) {

    //Read the string to the value variable
    string value;

    //Store the converted string to int variable
    int valueInt;

    //Create ifstream to read the file and open the file
    ifstream infile;
    infile.open(filename);

    //Read the file and store the data into the BST
    if(infile) {
        while(getline(infile, value, '\n' )) {
            valueInt = stoi(value);
            intBST.insert(valueInt);
        }
    } else {
        cout << "Error opening the file\n";
    }

    //Close the file
    infile.close();

}
string convertToLower(string readLine) {

    //Storage for the new modified string
    string lowerString;

    //Length of the string.
    int length = readLine.length();

    //For loop that converts each character into lowercase and eliminate the
    // space in between the words.
    for(int i = 0; i < length; i++) {
        if (readLine[i] != ' ') {
            lowerString += tolower(readLine[i]);
        }
    }
    //Returns the modified string.
    return lowerString;
}

void storeStringTree(const string& filename, BST<string> & stringBST) {

    //Read the string to the value variable
    string value;

    //Create ifstream to read the file and open the file
    ifstream infile;
    infile.open(filename);

    //Read the file and store the data into the BST
    if(infile) {
        while(getline(infile, value, '\n' )) {
            value = convertToLower(value);
            stringBST.insert(value);
        }
    } else {
        cout << "Error opening the file\n";
    }

    //Close the file
    infile.close();

}

void printIntIntro(BST<int> & intBST) {

    //Print the banners
    cout << "******************************" << endl
         << "* INTEGER BINARY SEARCH TREE *" << endl
         << "******************************\n" << endl;

    cout << "** CREATE BST **" << endl;

    //Print initial stats for the intBST.
    printBSTStats(intBST);
}

void printStringIntro(BST<string> & stringBST) {

    //Print the banners
    cout << endl
         << "******************************" << endl
         << "* STRING BINARY SEARCH TREE *" << endl
         << "******************************\n" << endl;

    cout << "** CREATE BST **" << endl;

    //Print initial stats for the intBST.
    printBSTStats(stringBST);
}

template<typename T>
void printBSTStats(BST<T> & BSTAny) {


    //Print out the number of nodes
    cout << "# of nodes:" << " " << BSTAny.size() << endl;

    //Print out the number of leaves
    cout << "# of leaves:" << " " << BSTAny.getLeafCount() << endl;

    //Print out the height of tree
    cout << "tree height:" << " " <<BSTAny.getHeight() << endl;

    //Print out if the BST is empty, returns one hence the boolalpha
    cout << "tree empty?" << " " << std::boolalpha << BSTAny.empty() << endl;

}

template<typename T>
void printTestTraversals(BST<T> & BSTAny) {

    //Print the different traversals
    cout << "\n** TEST TRAVERSALS **" << endl;
    cout << "pre-order:" << "   " << BSTAny.getPreOrderTraversal() << endl;
    cout << "in-order:" << "    " << BSTAny.getInOrderTraversal() << endl;
    cout << "post-order:" << "  " << BSTAny.getPostOrderTraversal() << endl;
}





void printLevelAncestorInt(BST<int> & intBST) {

    //Prints out the banner
    cout << endl << "** TEST LEVEL & ANCESTORS **" << endl;

    //Read the preorder traversal and store it in an int
    string preOrderString = intBST.getPreOrderTraversal();
    string storedInt;
    istringstream stringStream(preOrderString);
    int correctInt;

    //Read each int from the preorder string
    while((stringStream >> storedInt)) {
        correctInt = stoi(storedInt);
        cout << "level(" << correctInt << "):" << " " <<
        intBST.getLevel(correctInt) << ",     "   <<
        "ancestor(" << correctInt << "):" << intBST.getAncestors(correctInt)
        << endl;
    }

}

void printLevelAncestorString(BST<string> & stringBST) {

    //Prints out the banner
    cout << endl << "** TEST LEVEL & ANCESTORS **" << endl;
    string preOrderString = stringBST.getPreOrderTraversal();

    //Read the preorder traversal and store it in an string
    string storedString;
    istringstream stringStream(preOrderString);

    //Read each string line from the preorder string
    while((stringStream >> storedString)) {
        cout << "level(" << storedString << "):" << " " << stringBST.getLevel
        (storedString)        << ",     "   <<
        "ancestor(" << storedString<< "):" <<
        stringBST.getAncestors(storedString) << endl;
    }

}

template <typename T>
void printPreOrderOnly(BST<T> & BSTAny) {

    //Print strings about the insert method and the preorder traversal string.
    cout << endl << "** TEST INSERT **" << endl;
    cout << "Inserting in this order:" << "  " <<
    BSTAny.getPreOrderTraversal() << endl;
}


template <typename T>
void printRemove(BST<T> & anyBST, T * arr) {

    //Print strings about the remove method while removing the nodes (if
    // found inside the BST)
    cout << "\n** TEST REMOVE **" << endl;
    cout << "Removing in this order:" << "  ";

    int sizeOfArr = sizeof(arr);

    for(int i = 0; i < sizeOfArr; i++) {
        cout << arr[i] << " ";
        anyBST.remove(arr[i]);
    }
    cout << endl;

    //Print the BST basic stats
    printBSTStats(anyBST);

    //Prints out the traversals.
    cout << "pre-order:" << "   " << anyBST.getPreOrderTraversal() << endl;
    cout << "in-order:" << "    " << anyBST.getInOrderTraversal() << endl;
    cout << "post-order:" << "  " << anyBST.getPostOrderTraversal() << endl;

}

template <typename T>
void printInsert(BST<T> & anyBST, T * arr) {

    //Print strings about the insert method while inserting the nodes (from
    // the hard coded array in main)
    cout << "\n** TEST INSERT (again) **" << endl;
    cout << "Inserting in this order:" << "  ";

    int sizeOfArr = sizeof(arr);

    for(int i = 0; i < sizeOfArr; i++) {
        cout << arr[i] << " ";
        anyBST.insert(arr[i]);
    }
    cout << endl;

    //Print the BST basic stats
    printBSTStats(anyBST);

    //Prints out the traversals.
    cout << "pre-order:" << "   " << anyBST.getPreOrderTraversal() << endl;
    cout << "in-order:" << "    " << anyBST.getInOrderTraversal() << endl;
    cout << "post-order:" << "  " << anyBST.getPostOrderTraversal() << endl;
}

template<typename T>
void printTestContain(BST<T> &anyBST, T *arr) {

    //Print out if a particular node is included in the BST or not
    cout << endl << "** TEST CONTAINS **" << endl;

    int sizeOfArr = sizeof(arr);

    //Runs through the hard-coded array to check if it is included in the
    // anyBST
    for(int i = 0; i < sizeOfArr; i++) {
        cout << "contains(" << arr[i] << "):" << " " <<
             anyBST.contains(arr[i]) << endl;
    }
}

template <typename T>
void combinedIntBSTFunctions(BST<T> & intBST, T * arr) {

    //Prints the test insert banner and the preorder
    printPreOrderOnly(intBST);

    //Prints out the BST stats
    printBSTStats(intBST);

    //Prints out the different traversals
    printTestTraversals(intBST);

    //Prints out the levels and ancestors
    printLevelAncestorInt(intBST);

    //Prints out the contain test
    printTestContain(intBST, arr);

    //Prints out the remove test
    printRemove(intBST, arr);

    //Prints out the insert test
    printInsert(intBST, arr);
}

template <typename T>
void combinedStringBSTFunctions(BST<T> & stringBST, T * arr) {

    //Prints the test insert banner and the preorder
    printPreOrderOnly(stringBST);

    //Prints out the BST stats
    printBSTStats(stringBST);

    //Prints out the different traversals
    printTestTraversals(stringBST);

    //Prints out the levels and ancestors
    printLevelAncestorString(stringBST);

    //Prints out the test contain test
    printTestContain(stringBST, arr);

    //Prints out the remove test
    printRemove(stringBST, arr);

    //Prints out the insert test
    printInsert(stringBST, arr);
}


