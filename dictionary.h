// header file for dictionary program using a linked list
// Frankie Gauthier
// CS2010 Assign3

#ifndef dictionary_h
#define dictionary_h

#include "dictionary.cpp"
#include <stdio.h>
#include <stdlib.h>
#include <string>

// function prototypes
ENTRY *LocateWord(DICT& , WORD);
BOOL FullDictionary(DICT&);
BOOL InsertWord(DICT&,WORD);
WORD GetNextWord(void);
void DumpDictionary(DICT&);


using namespace std;


const int MAX = 100;


typedef string STRING;
typedef bool BOOL;
typedef string WORD; 



typedef struct entry {

      int count;                  /* frequency count for a particular word */

      WORD w;                     /* the word itself */

      struct entry *nextWord;     /* pointer to next entry */

} ENTRY;



typedef  dict {

     int maxEntries;	  /* maximum number of entries allowed; this is an artificial limit */

                                   /* link lists can be as big as you want. This limit ensures that   */

                                   /* this code tries to behave like the previous ones */

     int numWords;                 /* number of words in the dictionary */

     ENTRY *Words;                 /* pointer to the entries in the dictionary */

} DICT;

#endif
