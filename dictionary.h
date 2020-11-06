/* Declares a dictionary's functionality */

#ifndef DICTIONARY_H
#define DICTIONARY_H

/* Maximum length for a word */
/* (e.g., pneumonoultramicroscopicsilicovolcanoconiosis) */
#define LENGTH 45

/* Prototypes */
int check(const char *word);
unsigned int hash(const char *word);
int load(const char *dictionary);
unsigned int size(void);
void unload(void);

#endif /* DICTIONARY_H */
