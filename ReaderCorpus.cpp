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

// Necessary for input-output operations
#include <iostream>

// Necessary for string operations
#include <string>

// Necessary for file stream operations
#include <fstream>

// Necessary for string lowercasing operations
#include <algorithm>

// Field and method declarations for the ReaderCorpus class
#include "ReaderCorpus.h"

// Field and method declarations for the LinkedListContext class
#include "LinkedListContext.h"

using namespace std;



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE FIELDS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// Do not reinitialize these variables in the .cpp.
// Included here for reference

// X-----------------X
// |    #NAME    |
// X-----------------X
// Description: 
// Invariants:  
// string contextWords[11];

// X-----------------X
// |    #NAME    |
// X-----------------X
// Description: 
// Invariants:  
// string prevContext;

// X-----------------X
// |    #NAME    |
// X-----------------X
// Description: 
// Invariants:  
// string currWord;

// X-----------------X
// |    #NAME    |
// X-----------------X
// Description: 
// Invariants:  
// string postContext;

// X-----------------X
// |    #NAME    |
// X-----------------X
// Description: 
// Invariants:  
// ifstream fileObj;



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE METHODS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// #isFinished() - 
// X-----------------------------------X
// |    #NAME    |
// X-----------------------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
bool ReaderCorpus::isFinished() {
   // If the fileObj is empty and the current word is empty...
   if (currWord == " ") {
      // Then this Corpus Reader cannot return any further valid concordance values
      return(true);
   }
   else {
      return(false);
   }
}

// #trimPreNoise(string) - 
// X-----------------------------------X
// |    #NAME    |
// X-----------------------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
string ReaderCorpus::trimPreNoise(string aWord) {
   bool firstLetter = false;
   // Load the first character of the string
   int currIndex = 0;
   char currLetter = aWord[currIndex];
   // Fencepost check. If it's the first actual letter, do nothing
   if ( 'a' <= currLetter && currLetter <= 'z') {
      // cout << "This is the first letter! " << currLetter << endl; // DEBUG
      firstLetter = true;
   }
   // Otherwise, the first character is noisy, so proceed forward...
   else {
      // While we haven't found the first letter of the word...
      while (firstLetter == false) {
         // Increment the index
         currIndex++;
         // And check for a valid letter
         currLetter = aWord[currIndex];
         if ( 'a' <= currLetter && currLetter <= 'z') {
            // If we found it, set the exit flag
            firstLetter = true;
         } // Closing if
      } // Closing while loop. First character found and currIndex points to it
   // Delete the substring from the start to the first index
   aWord.erase(0, (currIndex));
   }
   return(aWord);
}

// #trimPostNoise(string) - 
// X-----------------------------------X
// |    #NAME    |
// X-----------------------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
string ReaderCorpus::trimPostNoise(string aWord) {
   bool lastLetter = false;
   // Load the last character of the string
   int currIndex = aWord.length();
   char currLetter = aWord[currIndex];
   // Fencepost check. If it's the last actual letter, do nothing
   if ( 'a' <= currLetter && currLetter <= 'z') {
      // cout << "This is the last letter! " << currLetter << endl; // DEBUG
      lastLetter = true;
   }
   // Otherwise, the last character is noisy, so proceed backward...
   else {
      // While we haven't found the last letter of the word...
      while (lastLetter == false) {
         // Decrement the index
         currIndex--;
         // And check for a valid letter
         currLetter = aWord[currIndex];
         if ( 'a' <= currLetter && currLetter <= 'z') {
            // If we found it, set the exit flag
            lastLetter = true;
         } // Closing if
      } // Closing while loop. Last character found and currIndex points to it
   // Delete the substring from the currIndex to the end
   aWord.erase((currIndex+1), (aWord.length()));
   }
   return(aWord);
}


//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PUBLIC FIELDS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// None declared in the .cpp



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
bool ReaderCorpus::advance() {
   // Test to see if advance() can even be called
   if (this->isFinished()) {
      cout << "ACHTUNG! This Corpus Reader is finished." << endl; // DEBUG
      return(false);
   }
   // Shuffle context words down one index
   for (int i = 0 ; i < 11 ; i++) {
      contextWords[i] = contextWords[i+1];
   }
   string nextWord = "foobarbaz";
   bool validWord = false;
   // While we haven't confirmed possession of a valid word...
   while (validWord == false) {
      // Attempt to assign the next whitespace delimited chars to nextWord
      fileObj >> nextWord;
      // cout << "The word just pulled was: " << nextWord << endl; // DEBUG
      // Lowercase the word pulled
      // From https://notfaq.wordpress.com/2007/08/04/cc-convert-string-to-upperlower-case/
      transform(nextWord.begin(), nextWord.end(), nextWord.begin(), ::tolower);
      // Check to see if valid chars are in the word
      bool validChars = false;
      for (unsigned int i = 0 ; i < nextWord.length() ; i++) {
         if (nextWord[i] >= 'a' && nextWord[i] <= 'z') {
            validChars = true;
         }
      } // Word scanned. Is it valid?
      validWord = validChars;
   } // Closing while loop, a valid word has been identified OR we've run off the end of the document.
   // Omit pre-noisy characters
   nextWord = this->trimPreNoise(nextWord);
   // Omit post-noisy characters
   nextWord = this->trimPostNoise(nextWord);
   // If no change was made by the fileObj extraction operator...
   if (nextWord == "foobarbaz") {
      // Default to a whitespace
      nextWord = " ";
   }
   // Load the next word to the end of the context array
   contextWords[10] = nextWord;
   // cout << "The current word is: " << contextWords[5] << endl; // DEBUG
   // Update the context strings
   string update = "";
   for (int i = 0 ; i < 5 ; i++) {
      update = update + contextWords[i] + " ";
   }
   // Update the previous context string
   prevContext = update;
   update = "";
   for (int i = 6 ; i < 11 ; i++) {
      update = update + " " + contextWords[i];
   }
   // Update the previous context string
   postContext = update;
   // Update the current keyword
   currWord = contextWords[5];
   return(true);
}

// X------------------X
// |    #NAME    |
// X------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
bool ReaderCorpus::isPrimed() {
   if (contextWords[5] != "") {
      return (true);
   }
   return (false);
} // Closing isLoaded()

// X------------------X
// |    #NAME    |
// X------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
bool ReaderCorpus::loadFile(string fileAddy) {
   fileObj.open(fileAddy);
   // Confirm that file was opened. Report otherwise if not.
   if (!fileObj) {
      cout << "Unable to open Corpus. Closing program...";
      return(false);
   }
   // cout << "File loaded successfully to ReaderCorpus object!" << endl; // DEBUG
   return(true);
}

// X------------------X
// |    #NAME    |
// X------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
LinkedListContext* ReaderCorpus::makeLinkedListContext() {
   LinkedListContext* retList = new LinkedListContext(prevContext, contextWords[5], postContext);
   return(retList);
}

// #prime() - Advances the reader to the first valid keyword-context state.
// X------------------X
// |    #NAME    |
// X------------------X
// Description:      
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
string ReaderCorpus::prime() {
   while (!isPrimed()) {
      this->advance();
   }
   return(contextWords[5]);
}



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CONSTRUCTORS / DESTRUCTORS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// X---------------------X
// |    #ReaderCorpus()    |
// X---------------------X
// Description:      Default constructor for the ReaderCorpus class
// Parameters:       
// Preconditions:    
// Postconditions:   
// Return value:     
// Functions called: 
ReaderCorpus::ReaderCorpus() {
   // cout << "ReaderCorpus() default constructor called" << endl; // DEBUG
   prevContext = "Nothing to see here!";
   currWord = "De nada";
   postContext = "Nor here!";
   for (int i = 0 ; i < 11 ; i++) {
      contextWords[i] = "";
   }
}



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
string ReaderCorpus::getContextWords() {
   string retString;
   for (int i = 0 ; i < 11 ; i++) {
      retString = retString +  " " + contextWords[i];
   }
   return(retString);
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
string ReaderCorpus::getPrevContext() {
   return(prevContext);
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
string ReaderCorpus::getCurrWord() {
   return(currWord);
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
string ReaderCorpus::getPostContext() {
   return(postContext);
}
