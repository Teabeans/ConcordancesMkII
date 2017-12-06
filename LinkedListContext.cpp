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

// #pragma once

// Necessary for input-output operations
#include <iostream>

// Necessary for string operations
#include <string>

#include "LinkedListContext.h"
// #include "NodeContext.cpp"

using namespace std;



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE FIELDS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// #formatLength - Variable that informs the output formatting
// X-----------------X
// |    #NAME    |
// X-----------------X
// Description: 
// Invariants:  
int LinkedListContext::formatLength;

// X-----------------X
// |    #NAME    |
// X-----------------X
// Description: 
// Invariants:  
int LinkedListContext::keywordFormatLength;

// Do not reinitialize these variables in the .cpp.
// Included here for reference

// X-----------------X
// |    #NAME    |
// X-----------------X
// Description: 
// Invariants:  
// NodeContext* currPtr;

// X-----------------X
// |    #NAME    |
// X-----------------X
// Description: 
// Invariants:  
// NodeContext* headNodePtr;

// X-----------------X
// |    #NAME    |
// X-----------------X
// Description: 
// Invariants:  
// string keyword;

// X-----------------X
// |    #NAME    |
// X-----------------X
// Description: 
// Invariants:  
// int longestPrev;



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE METHODS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// X------------------X
// |    #advance()    |
// X------------------X
// If currPtr is not the last node, moves currPtr forward one body node per call.
void LinkedListContext::advance() {
   if (isLastNode() == false) {
      currPtr = currPtr->nextPtr;
   }
   else {
      cout << "Error: Cannot advance. This is the last node." << endl;
   }
}

// X-------------------------------X
// |    #append(string, string)    |
// X-------------------------------X
// Adds a new node to the Linked List using the provided contexts and updates the maximum prev context length
void LinkedListContext::append(string prevContext, string postContext){
   // cout << "LLC.append() called." << endl; // DEBUG
   this->reset();
   if (this->headNodePtr == nullptr) {
      // cout << "No head node" << endl; // DEBUG
      this->headNodePtr = new NodeContext(prevContext, postContext);
      this->currPtr = this->headNodePtr;
      // cout << "Append completed on a blank LLC." << endl; // DEBUG
      return;
   }
   // Move to the end of the linked list
   while (!this->isLastNode()) {
      this->advance();
   } // currPtr now points at the last node
   // Append a new node with the provided contexts
   this->currPtr->nextPtr = new NodeContext(prevContext, postContext);
   // Set an updated formatLength
   if ((signed)prevContext.length() > formatLength) {
      formatLength = prevContext.length();
   }
} // End append

// #isLastNode() - Reports whether the currPtr points to the last body node.
// X-----------------------------------X
// |    #NAME    |
// X-----------------------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
bool LinkedListContext::isLastNode() {
   // Test to avoid read access error, currPtr might be null, in which case nextPtr cannot be read
//   if (currPtr == nullptr) {
//      return(true);
//   }
   // If the nextPtr is off the end of the linked list...
   if (currPtr->nextPtr == nullptr) {
      // This is the last node
      return(true);
   }
   // Otherwise, it isn't.
   return(false);
}

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
void LinkedListContext::reset() {
   if (headNodePtr != nullptr) {
      currPtr = headNodePtr; // TODO - Confirm this assignment works
   }
}



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
// Outputs the entire linked list as a string
string LinkedListContext::toString() {
   // cout << "LLC toString() called! formatLength: " << formatLength << endl; // DEBUG
   // #reString - The return string
   string retString = "";
   // #gap - Gap between previous context, keyword, and post context
   string gap = "  ";
   // #pad - Number of spaces needed to pad out the previous context
   string pad = "";
   // #keypad - Number of spaces needed to pad out the previous context
   string keypad = "";

   // Starting at the first node...
   this->reset();
   // cout << "LLC.toString() reset complete. currPtr: " << currPtr << endl; // DEBUG
   // Determine the pad width
   for (int i = 0 ; i < (formatLength - currPtr->lengthOfPrevContext) ; i++) {
      // cout << "Padding."; // DEBUG
      pad = pad + " ";
   }
   // determine the keypad width (only needs to be done once per LinkedListContext, since all keywords should be the same
   for (int i = 0 ; i < (keywordFormatLength - (signed)this->keyword.length()) ; i++) { // keywordFormatLength @ 
      // cout << "Keypadding."; // DEBUG
      keypad = keypad + " ";
   }

   // Append the pad, context, gap, keyword, keyword gap, gap, context, and a line break to the return string
   // cout << "LLC.toString() - Appending..." << endl; // DEBUG
   retString = retString+ pad + currPtr->prevContext + gap + keyword + keypad + gap + currPtr->postContext + "\n";
   // cout << "LLC.toString() - First append completed." << endl; // DEBUG

   // And while we haven't run off the end of the list...
   while (!this->isLastNode()) {
      // retString = retString + "$"; // DEBUG
      // cout << "LLC.toString() while-loop activated." << endl; // DEBUG
      // Move forward one node
      this->advance();
      // And repeat
      // Reset the pads
      pad = "";
      // Redetermine the pad width
      for (int i = 0 ; i < (LinkedListContext::formatLength - currPtr->lengthOfPrevContext) ; i++) {
         pad = pad + " ";
      }
      // Append the pad, context, gap, keyword, keywordgap, gap, context, and a line break to the return string
      retString = retString + pad + currPtr->prevContext + gap + keyword + keypad + gap + currPtr->postContext + "\n";
   }
   // cout << "LLC.toString() successful!" << endl; // DEBUG
   return(retString);
}



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CONSTRUCTORS / DESTRUCTORS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// X---------------------------X
// |    LinkedListContext()    |
// X---------------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
LinkedListContext::LinkedListContext() {
   // cout << "LLC.LLC() - Default constructor called." << endl; // DEBUG
//   keyword = ".";
   // cout << "LLC.LLC() Keyword: " << keyword << endl; // DEBUG
   currPtr = nullptr;
   headNodePtr = nullptr;
}

// #LinkedListContext(string, string, string) - Makes a context linked list with a keyword and head node
// X-----------------------X
// |    #NAME    |
// X-----------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
LinkedListContext::LinkedListContext(string prevContext, string someKeyword, string postContext) {
   keyword = someKeyword;
   // Update the maximum observed keyword length
   if ((signed)keyword.length() > keywordFormatLength) {
      keywordFormatLength = keyword.length();
   }
   headNodePtr = new NodeContext(prevContext, postContext);
   currPtr = headNodePtr;
   if (headNodePtr->lengthOfPrevContext > LinkedListContext::formatLength) {
      LinkedListContext::formatLength = headNodePtr->lengthOfPrevContext;
   } // Ensures that the formatLength will be equal to the longest observed prevContext length
}

// #~LinkedListContext() - Destructor
// X-----------------------X
// |    #NAME    |
// X-----------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
LinkedListContext::~LinkedListContext() {
   // cout << "Destructo Presto!" << endl; // DEBUG
   if (this->headNodePtr == nullptr) {
      // cout << "Nothing to see here. Exiting!" << endl;
      return;
   }
   NodeContext* prevNodePtr = this->headNodePtr;
   // While a body node still exists...
   this->currPtr = this->headNodePtr;
   if (this->currPtr == nullptr) {
      // cout << "Nothing to see here either" << endl;
   }
   // cout << "Attempting to advance to end: " << headNodePtr << ":" << currPtr << endl;

   while (this->headNodePtr->nextPtr != nullptr) {
      // cout << "headNode.nextPtr != nullptr" << endl;
      // Advance to the end
      // TODO: Need a test here: What if currPtr is nullptr because the head node was also nullptr when it was assigned on 194? There's no nextPtr to dereference.
      while (this->currPtr->nextPtr != nullptr) { // Read Access Violation
         prevNodePtr = this->currPtr;
         this->advance();
         //cout << "Crossing over " << this->currPtr->prevContext << ":" << this->currPtr->postContext << endl; // DEBUG
      } // Closing while loop, curr points to last node, prev points to second to last
      // And delete it
      delete this->currPtr;
      // And remove the previous pointer
      prevNodePtr->nextPtr = nullptr;
      this->currPtr = this->headNodePtr;
      prevNodePtr = this->headNodePtr;
   } // Body nodes are all deleted

   // cout << "Deleting Head Node: " << endl; // DEBUG
   // cout << "Deallocating " << this->headNodePtr->prevContext << ":" << this->headNodePtr->postContext << endl; // DEBUG
   delete this->headNodePtr;
}



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       GETTERS / SETTERS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// #getPrevContext() - Returns the previous context of the current node
// X-----------------------X
// |    #NAME    |
// X-----------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
string LinkedListContext::getPrevContext(const NodeContext* currNodePtr) const {
   return(currNodePtr->prevContext);
}

// X-----------------------X
// |    #NAME    |
// X-----------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
string LinkedListContext::getKeyword() const {
   return (keyword);
}

// #getPostContext() - Returns the post context of the current node
// X-----------------------X
// |    #NAME    |
// X-----------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
string LinkedListContext::getPostContext(const NodeContext* currNodePtr) const {
      return(currNodePtr->postContext);
}



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       OPERATOR OVERLOADS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// #operator< - Custom behavior for the less-than operator for this (RHarg) and another LinkedListContext (LHarg)
// X-----------------------X
// |    #NAME    |
// X-----------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
bool LinkedListContext::operator<(const LinkedListContext& someLinkedList) const {
   if (this->keyword < someLinkedList.keyword) {
      return(true);
   }
   else {
      return(false);
   }
}

// #operator> - Custom behavior for the less-than operator for this (RHarg) and another LinkedListContext (LHarg)
// X-----------------------X
// |    #NAME    |
// X-----------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
bool LinkedListContext::operator>(const LinkedListContext& someLinkedList) const {
   if (this->keyword > someLinkedList.keyword) {
      return(true);
   }
   else {
      return(false);
   }
}

// X--------------------------------------X
// |    #operator=(LinkedListContext&)    |
// X--------------------------------------X
// Description:      Custom behavior for the assignment operator. Appends the RH context list to the receiving context list
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
LinkedListContext& LinkedListContext::operator=(LinkedListContext& RHarg) {
   // Check to see if "this" and "RHarg" are the same thing
   if (this == &RHarg) { // Compares reference addresses
      // cout << "LLC assignment attempted on self. Returning." << endl; // DEBUG
      return *this; // If the same, bail.
   }
   // The two linked lists are different...
   if (this != &RHarg) {
      // cout << "This LLC keyword: " << this->keyword << endl;
      // cout << "That LLC keyword: " << RHarg.keyword << endl;
      this->keyword = RHarg.keyword;
      // If they aren't... target the first Linked List Node of the RH argument
      NodeContext* targetNodePtr = RHarg.headNodePtr;
      // cout << "TargetNodePtr: " << targetNodePtr->prevContext << targetNodePtr->postContext;
      // And while the target isn't nullptr...
      while(targetNodePtr != nullptr) {
         // cout << "LLC.operator= appending..." << endl;
         // cout << "AppendingPrev: " << this->getPrevContext(this->headNodePtr) << endl; // BUG - Attempting to access a nullptr
         // cout << "AppendingPost: " << this->getPostContext(this->headNodePtr) << endl; // BUG - Attempting to access a nullptr
         // cout << "AppendingPrev: " << RHarg.getPrevContext(targetNodePtr) << endl;
         // cout << "AppendingPost: " << RHarg.getPostContext(targetNodePtr) << endl;
         // Append RHarg context to LHS (this)
         this->append(RHarg.getPrevContext(targetNodePtr), RHarg.getPostContext(targetNodePtr));
         // cout << "LLC.operator= Append() complete! Advancing target..." << endl;
         // Advance the target
         targetNodePtr = targetNodePtr->nextPtr;
      } // Closing while loop - All RHarg contexts have been appended to the LHarg
   }
   // cout << "Closing LLC.operator=()" << endl << endl;
   return *this;
}

// X---------------------------------------X
// |    #operator==(LinkedListContext&)    |
// X---------------------------------------X
// Custom behavior for the equality operator for this (RHarg) and another LinkedListContext (LHarg)
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
bool LinkedListContext::operator==(const LinkedListContext& RHarg) const {
   // Determine incoming context
   string appPreCont = RHarg.getPrevContext(RHarg.headNodePtr);
   string appPostCont = RHarg.getPostContext(RHarg.headNodePtr);
   if (this->keyword == RHarg.keyword) {
      // cout << "LLC.op== : Keywords equal. " << this->keyword << " vs " << RHarg.keyword << endl; // DEBUG
      return(true);
   }
   else {
      // cout << "LLC.op== : Keywords inequal." << this->keyword << " vs " << RHarg.keyword << endl; // DEBUG;
      return(false);
   }
}

// #operator<< - Custom behavior for the stream insertion operator for this (RHarg) and another LinkedListContext (LHarg)
ostream& operator<<(ostream& coutStream, LinkedListContext& someLinkedList) {
   // cout << "LLC.op<<() called"; // DEBUG
   string thisLinkedList = "";
   // <Implement all string appending here>
   thisLinkedList = thisLinkedList + someLinkedList.toString();
   coutStream << thisLinkedList;
   // cout << "LLC.op<<() successful"; // DEBUG
   return coutStream;
}
