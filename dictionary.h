// header file for dictionary program using a linked list
// Frankie Gauthier
// CS2010 Assign3

#ifndef dictionary_h
#define dictionary_h


#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>


using namespace std;


const int MAX = 100;


typedef string STRING;
typedef bool BOOL;
typedef string WORD; 


typedef struct ENTRY ENTRY;
struct ENTRY {

      int count;                  /* frequency count for a particular word */

      WORD w;                     /* the word itself */

      struct ENTRY *nextWord;     /* pointer to next entry */

};


typedef struct DICT DICT;
struct  DICT {

     int maxEntries;	  /* maximum number of entries allowed; this is an artificial limit */

                                   /* link lists can be as big as you want. This limit ensures that   */

                                   /* this code tries to behave like the previous ones */

     int numWords;                 /* number of words in the dictionary */

     ENTRY *Words;                 /* pointer to the entries in the dictionary */

};


// function prototypes
ENTRY *LocateWord(DICT& , WORD);
BOOL FullDictionary(DICT&);
BOOL InsertWord(DICT&,WORD);
WORD GetNextWord(void);
void DumpDictionary(DICT&);
void sortDict(DICT&);

#endif
