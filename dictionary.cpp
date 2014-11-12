//function source code for linked list dictionary program
//Frankie Gauthier
//CS2010 Assign3


#include "dictionary.h"


// -inserts a word at the next available location in the dictionary
// -takes the dictionary to insert the word into and the word to be inserted as params
// -returns a bool indicating the success of the insert

BOOL InsertWord(DICT &dict, WORD word)
{

	
	ENTRY *tmp = new ENTRY;
	tmp->count++;
	tmp->w = word;
	tmp->nextWord = NULL;
		
	
	if (FullDictionary){
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



// -prints the words in the dictionary and prints the frequency at which they occur 
// -takes the dictionary to print as a param
// -returns nothing

void DumpDictionary(DICT &dict) {

cout << endl <<  "Word \t\t Frequency" << endl << "---------------------------" << endl;
	
	sortDict(dict);

	if(!FullDictionary(dict)){
		ENTRY *tmp = dict.Words;
		for(int i = 1; i <= dict.numWords; i++){
			cout << tmp->w <<" \t\t "  << tmp->count << endl;
			tmp = tmp->nextWord;
		}
	}
	
	
	// free memory used by dictionary
	while(dict.Words != NULL){
		ENTRY *tmp = dict.Words;
		dict.Words = dict.Words->nextWord;
		delete tmp;
	}
	delete dict.Words;
 	cout << endl << "deleted memory used by the dictionary.." << endl;	
}




// -reads characters from the input stream until a non-letter character is read
// -returns the characters read as a word value

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





// -returns if the last entry in the dictionary is occupied (aka its full)
// -takes the dictionary as a parameter
// -takes an array of words as a parameter and returns a boolean

BOOL FullDictionary(DICT &dict) {

	if(dict.numWords >= dict.maxEntries) return true;
	return false;

}





// -searches the dictionary passed to it for the word that is passed to it and returns
// -returns an int (the words index in the dict) or -1 if not

ENTRY *LocateWord(DICT &dict, WORD word) {

	
	if(dict.numWords == 0) return 0;
	
	int position = 1;
	ENTRY *tmp = dict.Words;
   	for(int i = 1; i <= dict.numWords; i++){
		if(word != tmp->w) {position++; tmp = tmp->nextWord;}
		else return tmp;
	}
	delete tmp;
	return 0;


}






// -performs a dirty selection sort on the dictionary sorting from least to greatest
// takes a reference to the dictionary as a param
// returns nothing

void sortDict(DICT &dict){
	ENTRY *tmp = dict.Words; // for iterating through to find smallest
	ENTRY *smallest = tmp;	 // marks smallest node
	ENTRY *anchor = dict.Words;// marks the position to swap with smallest
	WORD tmpWord;
	int tmpCount;
	
	while(anchor != NULL){
		
		// set tmp and smallest to the new anchor
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
 	delete tmp,smallest,anchor;
}




