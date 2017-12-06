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

// Necessary for file stream operations
// #include <fstream> // Disincluded from the .h - No file stream operations here

// Field and method declarations for the LinkedListContext class
#include "LinkedListContext.h"

using namespace std;

// X---------------------X
// |    #ReaderCorpus    |
// X---------------------X
// Description: Performs corpus-related operations.
class ReaderCorpus {

private:
//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE FIELDS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// X-----------------X
// |    #NAME    |
// X-----------------X
// Description: 
// Invariants:  
string contextWords[11];

// X-----------------X
// |    #NAME    |
// X-----------------X
// Description: 
// Invariants:  
string prevContext;

// X-----------------X
// |    #NAME    |
// X-----------------X
// Description: 
// Invariants:  
string currWord;

// X-----------------X
// |    #NAME    |
// X-----------------X
// Description: 
// Invariants:  
string postContext;

// X-----------------X
// |    #NAME    |
// X-----------------X
// Description: 
// Invariants:  
ifstream fileObj;



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE METHODS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// X------------------X
// |    #NAME    |
// X------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
bool isPrimed();

// X-----------------------------------X
// |    #NAME    |
// X-----------------------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
string trimPreNoise(string aWord);

// X-----------------------------------X
// |    #NAME    |
// X-----------------------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
string trimPostNoise(string aWord);


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

// X------------------X
// |    #advance()    |
// X------------------X
// Description:      Moves the corpus reader forward one word and
//                   updates the prevContext, currWord, and postContext strings
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
bool advance();

// X-----------------------------------X
// |    #NAME    |
// X-----------------------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
bool isFinished();

// X------------------X
// |    #NAME    |
// X------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
bool loadFile(string fileAddy);

// X------------------X
// |    #NAME    |
// X------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
LinkedListContext* makeLinkedListContext();

// X------------------X
// |    #NAME    |
// X------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
string prime();

//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CONSTRUCTORS / DESTRUCTORS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// #ReaderCorpus() - Default constructor
ReaderCorpus();




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
string getContextWords();

// X-----------------------X
// |    #NAME    |
// X-----------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
string getPrevContext();

// X-----------------------X
// |    #NAME    |
// X-----------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
string getCurrWord();

// X-----------------------X
// |    #NAME    |
// X-----------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
string getPostContext();

};
