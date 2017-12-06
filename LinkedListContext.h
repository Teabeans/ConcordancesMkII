// Tim Lum
// twhlum@gmail.com
// 2017.12.04
// For the University of Washington Bothell CSS 501A
// Autumn 2017, Graduate Certificate in Software Design & Development (GCSDD)
//
// File Description:
// This file is the driver file for the Concordance Assignment. This program shall accept a list of
// stopwords (stopwords.txt) as well as a command argument corpus location. From these bodies of data
// it will generate a concordance in KeyWord In Context (KWIC) format.
//
// Package files:
// Driver.cpp
// BSTGeneric.h
// BSTGeneric.cpp
// NodeGeneric.cpp
// ReaderCorpus.h
// ReaderCorpus.cpp
// LinkedListContext.h
// LinkedListContext.cpp
// NodeContext.cpp
// stopwords.txt (recommended)
// Corpus (not named, name must be passed as a command argument)
//
// Acknowledgements:
// Source material from:
// University of Washington Bothell
// CSS 501A Data Structures And Object-Oriented Programming I
// "Design and Coding Standards"
// Michael Stiber
//
// Template author:
// Tim Lum (twhlum@gmail.com)
//
// License:
// This software is published under the GNU general license which guarantees
// end users the freedom to run, study, share and modify the software.
// https://www.gnu.org/licenses/gpl.html
//
// Code Standards:
// I. Comment at beginning of file (above) stating (at a minimum):
//    A. File Name
//    B. Author Name
//    C. Date
//    D. Description of code purpose 
// II. Indentation:
//    A. 3 whitespaces ("   ")
//    B. May vary depending on language and instructor
// III. Variables:
//    A. Descriptive, legible name
//    B. Comment over any variable declaration describing:
//       0. Its use in the algorithm
//       1. Invariant information such as legal ranges of values
// IV. Class Files:
//    A. Separate *.cpp and *.h files should be used for each class.
//    B. Files names must exactly match class names (case-sensitive)
// V. Includes:
//    A. Calls for content ("#include") from the Standard Template Library (STL) should be formatted as follows:
//       0. DO type:     #include <vector>
//       1. Do NOT type: #include <vector.h>
//    B. You may use the directive "using namespace std;"
//       0. ??? (?CONFIRM?)
// VI. Classes:
//    A. Return values:
//       0. Do NOT return references to internal class structures.
//       1. Do NOT return pointers to internal class structures.
//    B. Do NOT expose any details of the internal implementation.
// VII. Functions + Methods:
//    A. Functions should be used for appropriate operations.
//    B. Reference arguments should be used only when necessary.
//    C. The (return?CONFIRM?) type of each function must be declared
//       0. Use 'void' when necessary
//    D. Declare as 'const' (unalterable) when no modification is made to the object state
//       0. UML 'query' property (?CONFIRM?)
// VIII. Function Comments:
//    A. DO include a comment prior to each function which includes the function's:
//       0. Purpose - Why does the function exist?
//       1. Parameters - What fields does the function contain?
//       2. Preconditions - What conditions must be true prior to the function call?
//       3. Postconditions - What conditions must be true after the function call?
//       4. Return value - What is the nature and range of the value returned by the function?
//       5. Functions called - What other functions are called by this function?
// IX. Loop invariants
//    A. Each loop should be commented with 'invariant' information (?CONFIRM?)
// X. Assertions:
//    A. May be comments or the 'assert()' feature.
//    B. Insert where useful to explain important features or subtle logic.
//    C. What, exactly, is an assertion (?CONFIRM?)
// XI. Prohibited (unless justified):
//    A. Global variables
//    B. "Gotos" (?CONFIRM?)
//
// Special instructions:
// To install G++:
// sudo apt install g++
// 
// To update Linux:
// sudo apt-get update && sudo apt-get install
// sudo apt-get update
//
// To make a new .cpp file in Linux:
// nano <file name>.cpp
//
// To make a new .h file in Linux:
// nano <file name>.h
//
// To make a new .txt file in Linux:
// nano <file name>.txt
//
// To compile in g++:
// g++ -std=c++11 *.cpp
//
// To run with test input:
// ./a.out < TestInput.txt
//
// To run Valgrind:
// Install Valgrind:
// sudo apt install valgrind
//
// Run with:
// valgrind --leak-check=full <file folder path>/<file name, usually a.out>
// OR
// valgrind --leak-check=full --show-leak-kinds=all <file path>/a.out
//
// ie.
// valgrind --leak-check=full /home/Teabean/a.out
// OR
// valgrind --leak-check=full --show-leak-kinds=all /home/Teabean/a.out
// OR
// valgrind --leak-check=full --show-leak-kinds=all /home/Teabean/a.out < /Sudoku.txt
//
// To load a text file as cin input in Visual Studios:
// 1. Go to the top menu bar => Debug => <ProjectName> Properties => Debugging => Command Arguments =>
// 2. "< <Filepath>/<Filename>.txt" ie. "< /Sudoku.txt"
// ie. < /Sudoku.txt
//
// To pass a command argument:
// 1. Go to the top menu bar => Debug => <ProjectName> Properties => Debugging => Command Arguments =>
// 2. Enter the file address and name
// ie. corpus.txt
// 3. Alter main() method signature as follows: main( int argc, char* argv[] ) {
// 4. The variable "argv[1]" now refers to the first command argument passed
//
// To run in Linux with Valgrind and a command argument
// valgrind --leak-check=full --show-leak-kinds=all /home/Teabean/a.out Sudoku.txt
//
// ---- BEGIN STUDENT CODE ----



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       INCLUDE STATEMENTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

#pragma once

// Necessary for input-output operations
#include <iostream>

// Necessary for string operations
#include <string>

// Node definition for a context node (holding data1, data2, next)
// #include "NodeContext.cpp"

using namespace std;

// X--------------------------X
// |    #LinkedListContext    |
// X--------------------------X
// Description: Performs corpus-related operations.
class LinkedListContext {
protected:
struct NodeContext {
   string prevContext;
   string postContext;
   NodeContext* nextPtr;
   int lengthOfPrevContext;

   NodeContext() {
      prevContext = "Default NodeContext()";
      postContext = "For Test Purpose Only";
      nextPtr = nullptr;
      lengthOfPrevContext = 0;
   }

   NodeContext(string wordsBefore, string wordsAfter) {
      prevContext = wordsBefore;
      postContext = wordsAfter;
      lengthOfPrevContext = wordsBefore.length();
      nextPtr = nullptr;
   }
};


private:
//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE FIELDS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// X-----------------------------------X
// |    #NAME    |
// X-----------------------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
NodeContext* currPtr;

// X-----------------------------------X
// |    #NAME    |
// X-----------------------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
NodeContext* headNodePtr;

// X-----------------------------------X
// |    #NAME    |
// X-----------------------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
static int formatLength;

// X-----------------------------------X
// |    #NAME    |
// X-----------------------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
static int keywordFormatLength;

// X-----------------------------------X
// |    #NAME    |
// X-----------------------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
string keyword; // Inherited from the BSTConcordance node



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE METHODS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// #advance() - If currPtr is not the last node, moves currPtr forward one body node per call
// X----------------X
// |    #NAME    |
// X----------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
void advance();

// #append(string, string) - Adds a new node to the Linked List using the provided contexts
// X----------------X
// |    #NAME    |
// X----------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
void append(string prevContext, string postContext);

// #isLastNode() - Reports whether the currPtr points to the last body node.
// X----------------X
// |    #NAME    |
// X----------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
bool isLastNode();

// #reset() - Sets the currPtr back to the head node
// X----------------X
// |    #reset()    |
// X----------------X
// #reset() - Sets the current node pointer to the head node
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
void reset();



public:
//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PUBLIC FIELDS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// None for this class



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PUBLIC METHODS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// X-------------------X
// |    #toString()    |
// X-------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
string toString();



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CONSTRUCTORS / DESTRUCTORS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// Default constructor
// X-----------------------X
// |    #NAME    |
// X-----------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
LinkedListContext();

// Constructor for a head node's keyword and context
// X-----------------------X
// |    #NAME    |
// X-----------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
LinkedListContext(string someKeyword, string prevContext, string postContext);

// #~LinkedListContext() - Destructor for a LinkedListContext
// X-----------------------X
// |    #NAME    |
// X-----------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
~LinkedListContext();



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       GETTERS / SETTERS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// X-----------------------X
// |    #NAME    |
// X-----------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
string getPrevContext(const NodeContext* currNodePtr) const;

// X-----------------------X
// |    #NAME    |
// X-----------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
string getPostContext(const NodeContext* currNodePtr) const;


//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       OPERATOR OVERLOADS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// #operator< - Custom behavior for the less-than operator
// X-----------------------X
// |    #NAME    |
// X-----------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
bool operator<(const LinkedListContext& someLinkedList) const;

// #operator> - Custom behavior for the less-than operator
// X-----------------------X
// |    #NAME    |
// X-----------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
bool operator>(const LinkedListContext& someLinkedList) const;

// #operator== - Custom behavior for the equality operator
// X-----------------------X
// |    #NAME    |
// X-----------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
bool operator==(const LinkedListContext& someLinkedList) const;

// #operator= - Custom behavior for the assignment operator
// X-----------------------X
// |    #NAME    |
// X-----------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
LinkedListContext& operator=(LinkedListContext& someLinkedList);

// #operator<< - 
// X-----------------------X
// |    #NAME    |
// X-----------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
friend ostream& operator<<(ostream& coutStream, LinkedListContext& someLinkedList);

}; // Closing class LinkedListContext
