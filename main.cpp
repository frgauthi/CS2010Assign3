// main function for the dictionary program
// Frankie Gauthier
// CS2010Assign3

#include "dictionary.h"


DICT dictionary={MAX,0,0};  /* your dictionary                                                                */
WORD word;

int main (void) {

    ENTRY *pos;

    while (1) {
       word = GetNextWord();
       if ( word.empty() )  {
           DumpDictionary(dictionary);
           break;
       }
       if ((pos = LocateWord(dictionary,word)) >  0 ) 
           pos->count++;
       else
           if (!InsertWord(dictionary,word)) cout << "dictionary full" << word <<  "cannot be added\n";
    }
    delete pos;
    return 0;
}

