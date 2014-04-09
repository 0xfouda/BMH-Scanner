#include "SigPrep.h"
#include <iostream>

using namespace std;

void HEXtoCHAR (string str,char* ASCII_Sig)
{
	char* ASCII_Sig_Beg = ASCII_Sig;
	int len = str.length()/2;
    const char *c = str.c_str();
    unsigned int x;
    while(len > 0) {
        sscanf_s(c, "%2X", &x);
        //tmp += x;
		*(ASCII_Sig) = (unsigned char)x;
		ASCII_Sig++;
        c += 2;
		len--;
    }
	ASCII_Sig = ASCII_Sig_Beg;
}
