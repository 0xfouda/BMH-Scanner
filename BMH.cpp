#include "BMH.h"
#include <string.h>
using namespace std;

unsigned char BadMatchTable[MAX_ALPHABET];

void BMH_CreateBadMatchTable(char *pattern,int PatternSize,unsigned char * BadMatchTable)
{
	int pattern_length = PatternSize;
	for(int i=0;i<MAX_ALPHABET;i++)
	{
		BadMatchTable[i] =  pattern_length;
	}
	for(int i = 0; i < pattern_length - 1; i++)
	{
		BadMatchTable[pattern[i]] = pattern_length - 1 - i;
	}
}
int BMH_Search(char *text,int TextSize, char *pattern,int PatternSize)
{
	
	BMH_CreateBadMatchTable(pattern,PatternSize,BadMatchTable);
	int pattern_length = PatternSize;
	int text_length = TextSize;
	int scan_pos = 0;
	int pat_pos = pattern_length - 1;
	while(text_length >= pattern_length)
	{
		pat_pos = pattern_length - 1;
		for(scan_pos = pat_pos; (unsigned char)text[scan_pos] == (unsigned char)pattern[pat_pos] ; scan_pos--,pat_pos--)
		{
			if(pat_pos == 0)
			{
				return (TextSize - text_length);
			}
		}
		text_length -= BadMatchTable[(unsigned char)text[scan_pos]];
		text += BadMatchTable[(unsigned char)text[scan_pos]];
	}

	return NOT_FOUND;
}