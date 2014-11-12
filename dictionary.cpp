#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <new>

using namespace std;


const int MAX = 100;


typedef string STRING;
typedef bool BOOL;
typedef string WORD;    


/*

    structure describing a word entry in the dictionary

*/
typedef struct ENTRY ENTRY;

 struct ENTRY {
      int count;                  /* frequency count for a particular word */
      WORD w;                     /* the word itself */
      ENTRY *nextWord;     /* pointer to next entry */
};


/*

    structure describing the dictionary

*/
typedef struct DICT DICT;

struct DICT{
     int maxEntries;	  /* maximum number of entries allowed; this is an artificial limit */
                                   /* link lists can be as big as you want. This limit ensures that   */
                                   /* this code tries to behave like the previous ones */
     int numWords;                 /* number of words in the dictionary */
     ENTRY *Words;                 /* pointer to the entries in the dictionary */
};





/*

  you will have to write code for these 5 functions. 

*/

void sortDict(DICT&);
ENTRY *LocateWord(DICT& , WORD);
BOOL FullDictionary(DICT&);
BOOL InsertWord(DICT&,WORD);
WORD GetNextWord(void);
void DumpDictionary(DICT&);


/*

  note that these are global variables so that they are already initialized to 0

*/


DICT dictionary={MAX,0,0};  /* your dictionary                                                                */
WORD word;                 /*   */



BOOL InsertWord(DICT &dict, WORD word)

{
cout << "attempting to insert word..";
	
	ENTRY *tmp = new ENTRY;
	tmp->count++;
	tmp->w = word;
	tmp->nextWord = NULL;
		
	cout << tmp->w <<endl;
	if (1){
		if(dict.numWords == 0){
			dict.Words = tmp;
			dict.numWords++;
			return true;
		}else{
		
			tmp->nextWord = dict.Words;
			dict.Words = tmp;
			dict.numWords++;
			return true;
		}
		
	}
return false;

}




void DumpDictionary(DICT &dict) {

cout << endl <<  "word \t\t frequency" << endl << "---------------------------" << endl;
	
	sortDict(dict);

	if(!FullDictionary(dict)){
		ENTRY *tmp = dict.Words;
		for(int i = 1; i <= dict.numWords; i++){
			cout << tmp->w <<" \t\t "  << tmp->count << endl;
			tmp = tmp->nextWord;
		}
	}
}


WORD GetNextWord(void){

        WORD tmpword = "";
        char ch;
        int newWord = 0;

        // if the input is not null             
        while(cin.good()){
                ch = tolower(cin.get());
                // check if it is a letter character
                if(isalpha(ch)){

                tmpword += ch;
                newWord = 1;

                }else{
                        if(newWord){

                                 return tmpword;
                        }
                }

        }

return tmpword;
}



BOOL FullDictionary(DICT &dict) {

	if(dict.numWords == dict.maxEntries) return true;
	return false;

}


ENTRY *LocateWord(DICT &dict, WORD word) {

	
	if(dict.numWords == 0) return 0;
	
	int position = 1;
	ENTRY *tmp = dict.Words;
   	for(int i = 1; i <= dict.numWords; i++){
		if(word != tmp->w) {position++; tmp = tmp->nextWord;}
		else return tmp;
	}
	return 0;


}

void sortDict(DICT &dict){
	ENTRY *tmp = dict.Words;
	ENTRY *smallest = tmp;
	ENTRY *anchor = dict.Words;
	WORD tmpWord;
	int tmpCount;
	
	while(anchor != NULL){
		tmp = anchor;
		smallest = anchor;
	
		//find smallest node to swap with anchor
		while (tmp != NULL){
			if(tmp->w < smallest->w) smallest = tmp;
			tmp = tmp->nextWord; 
		}
		
		//swap
		tmpWord = anchor->w;
		tmpCount = anchor->count;
		anchor->w = smallest->w;
		anchor->count = smallest->count;
		smallest->w = tmpWord;
		smallest->count = tmpCount;
		
		//advance anchor
		anchor = anchor->nextWord;			
	}
}


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

           if (!InsertWord(dictionary,word)) cout << "dictionary full " << word <<  " cannot be added\n";

    }

    return 0;

}



