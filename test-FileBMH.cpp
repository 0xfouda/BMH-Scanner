#include "BMH.h"
#include "FilePrep.h"
#include "SigPrep.h"

using namespace std;

int main()
{
	struct FiletoScan file;
	string Hex_Signature = "16C802D37DCC309D32431FA7044F1E";
	int Signature_Length = Hex_Signature.length()/2;
	char* ASCII_Signature = new char();
	//char* ASCII_Signature = "\x75\x3A\x00\x00\x90\x43\x00\x00\x80\x3A\x00\x00\x9C\x3A\x00\x00\x88\x43\x00\x00\xD0\x3A\x00\x00\x85\x3B\x00\x00\xB8\x43\x00\x00\x90\x3B";
	HEXtoCHAR(Hex_Signature,ASCII_Signature);
	cout << "Comparing Signature --> '" << Hex_Signature<< "'" << endl;
	file.FilePath = "test.iso";
	fprep_FileHexProcess(&file);
	int test = BMH_Search(file.buffer,file.FileSize,ASCII_Signature,Signature_Length);
	if(test == NOT_FOUND)
			cout<<"Pattern NOT FOUND !!"<<endl;
		else
			cout<<"\a Pattern FOUND in Offset : "<< test <<endl;
	cin.ignore();
	return 0;
}
