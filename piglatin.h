#ifndef PIGLATIN_H
#define PIGLATIN_H

#include <fstream>

int findFirstVowel(const char *word);
void translateWord(const char *word, char *translation);
void translateStream(std::istream &in, std::ostream &out);

#endif
