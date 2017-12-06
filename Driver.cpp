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

// X---------X
// |  INDEX  |
// X---------X
// Include Statements
// Global Variables
// Control Variables (omitted for submission)
// Unit Tests (omitted for submission)
// Program Body



// X--------------------------X
// |                          |
// |    INCLUDE STATEMENTS    |
// |                          |
// X--------------------------X

// Necessary for input-output operations
#include <iostream>

// Necessary for string operations
#include <string>

// The NodeGeneric used in a BSTGeneric class
// #include "NodeGeneric.cpp"

// The BSTGeneric class - Used to create a stopword list and a concordance tree.
// #include "BSTGeneric.h"
// #include "BSTGeneric.cpp" // .cpp required here due to generic/template functionality of this class

// The Corpus Reader class - Packages the corpus into valid data modules for the BSTGeneric class to handle
// #include "ReaderCorpus.h"

// The LinkedListContext class - Used as a data field in a Concordance Node
#include "LinkedListContext.h"

// Methods not found in the current namespace are directed to check the 'std' namespace
using namespace std;



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       GLOBAL VARIABLES
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// None (prohibited for this course)



int main( int argc, char* argv[] ) {  // Array of command-line arguments strings

//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CONTROL VARIABLES
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// Omitted for assignment submission



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       UNIT TESTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// Omitted for assignment submission
/*   if (true) {
   cout << "UnitTest07: Linked list instantiation test" << endl;
      // Headnode constructor test
      LinkedListContext testList1("prevContext1", "keyword1!", "postContext1");
      cout << "TestList1 keyword  : " << testList1.getKeyword() << endl;
      cout << testList1.toString() << endl;

      LinkedListContext testList2("prevContext2", "keyword2!", "postContext2");
      cout << "TestList2 keyword  : " << testList2.getKeyword() << endl;
      cout << testList2.toString() << endl;
 
      // Linked List assignment (amalgamation) test
      cout << "Combining 2 lists..." << endl;
      testList1 = testList2;
      cout << testList1.toString();
      cout << endl;

      // 3rd list assignment test
      cout << "Combining 3 lists..." << endl;
      LinkedListContext testList3("prevContext3", "keyword3!", "postContext3");
      cout << "TestList3 keyword  : " << testList3.getKeyword() << endl;
      cout << testList3.toString() << endl;
      testList1 = testList3;
      cout << testList1.toString();
      cout << endl;
   }
*/

//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       ASSIGNMENT DRIVER
//
//-------|---------|---------|---------|---------|---------|---------|---------|

/*   if (true) { // Note to grader: This switch decoupled from control variables for assignment submission



// X-----------------------X
// |    Make a Stoplist    |
// X-----------------------X
      BSTGeneric<string> stopListBST("stopwords.txt");



// X-----------------------------X
// |    Make a ConcordanceBST    |
// X-----------------------------X
      BSTGeneric<LinkedListContext> concordanceBST;



// X----------------------------X
// |    Make a Corpus Reader    |
// X----------------------------X
      ReaderCorpus theScribe;

      // Load the corpus to the reader
      theScribe.loadFile(argv[1]);

      // Prime the reader so that its current word is the first word of the corpus
      theScribe.prime();



// X-----------------------X
// |    Read the corpus    |
// X-----------------------X
      // While the reader has not reached the end...
      while (!theScribe.isFinished()) {
         // Check to see if the current word appears on the stoplist. If not...
         if (!stopListBST.find(theScribe.getCurrWord())) {
            // attempt to insert the current LinkedListContext output
            concordanceBST.insert(*theScribe.makeLinkedListContext());
         }
         // And move the reader up one word
         theScribe.advance();
      } // Closing while-loop. Reader has parsed the entire corpus.


// X-------------------------------X
// |    Display the Concordance    |
// X-------------------------------X
      concordanceBST.printout();

   }
   */


   cout << "This compiles and runs." << endl;
   cin.get();
   return(0);
}

// ---- END STUDENT CODE ----
