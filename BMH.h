#include <iostream>

#define MAX_ALPHABET 256
#define NOT_FOUND 0
#define FOUND 10

//unsigned static char BadMatchTable[MAX_ALPHABET];
void BMH_CreateBadMatchTable(char *pattern,int PatternSize,unsigned char * BadMatchTable);
int BMH_Search(char *text,int TextSize, char *pattern,int PatternSize);

