#include <iostream>
#include <cctype>
#include <cstring>
#include "piglatin.h"

using namespace std;


void translateStream(std::istream &in, std::ostream &out) {
  // strings for each word and it's translation
  char word[80]; 
  char translated[80];

  // Go through the text line by line
  for (std::string line; getline(in, line) ;) {
    const char *line_ptr = line.c_str();
    
    // go through each line and find words
    while (*line_ptr!= '\0') {
      // If it is not alpha, print the character
      if (!isalpha(*line_ptr)) {
	out << *line_ptr;
	line_ptr++;
      }
      // Else, store the word
      else {
	int index = 0;
	while (isalpha(*line_ptr)){
	  word[index] = *line_ptr;
	  index++;
	  line_ptr++;
	}
	word[index] = '\0';
	translateWord(word, translated);
	out << translated;
	out << *line_ptr;
	line_ptr++;
      }
    }
    // Print new line
    cout << endl;
  }
}


void translateWord(const char *word, char *translation){
  strcpy(translation, "");
  int length = strlen(word);
  int first_vowel = findFirstVowel(word);
  // if number, don't add anything
  if (isdigit(word[0]))
    strcpy(translation, word);
  else if (first_vowel == 0) {
    strcat(translation, word);
    strcat(translation, "way");
  }
  else if (first_vowel == -1) {
    strcat(translation, word);
    strcat(translation, "ay");
  }
  else {
    char beginning[20];
    char ending[20];
    for (int i = 0; i < first_vowel; i++) {
      ending[i] = tolower(word[i]);
    }
    ending[first_vowel] = '\0';
    int index = 0;
    for (int i = first_vowel; i < length && index < 20; i++) {
      beginning[index++] = word[i];
    }
    beginning[index] = '\0';
    strcat(translation, beginning);
    strcat(translation, ending);
    strcat(translation, "ay");
    
    if (isupper(word[0])){
      translation[0] = toupper(translation[0]);
    }
  }
}

int findFirstVowel(const char *word){
  int length = strlen(word);
  for (int i = 0; i < length; i++) {
    if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' ||
	word[i] == 'o' || word[i] == 'u')
      return i;
    if (word[i] == 'y' && i != 0 && i != length -1 )
      return i;	
  }
  return -1;
}
