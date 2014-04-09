#include "FilePrep.h"
using namespace std;


void fprep_FileHexProcess(struct FiletoScan* file)
{
	ifstream input_file(file->FilePath, ios::in | ios::binary);	
	input_file.seekg(0,ios::beg);
	input_file.seekg(0,ios::end);
	file->FileSize = input_file.tellg();
	input_file.seekg(0,ios::beg);
	if(file->BufferSize > 0)
		input_file.readsome(file->buffer,file->BufferSize);
	else
	{
		file->BufferSize = file->FileSize;
		file->buffer = new char[file->FileSize];
		input_file.read(file->buffer,file->BufferSize);
	}
	//char *converted = new char [file->BufferSize*2+1];
	//for(int i = 0; i < file->FileSize; i++)
	//	sprintf(&converted[i*2], "%02X", (unsigned char)file->buffer[i]);
	//free(file->buffer);
	//file->buffer = converted;
	input_file.close();
}

void BufferDisplay(char* Buffer, int BufferSize)
{
	int WidthDisplay=20, HeightDisplay=15;
	for(int i = 0; i < BufferSize ;  i++)
	{
		cout<<Buffer[i]<<" ";
		WidthDisplay--;

		if(WidthDisplay < 0)
		{
			cout<<endl;
			WidthDisplay = 20;
			HeightDisplay--;
			if(HeightDisplay < 0)
			{
				cout <<endl<<"Press Enter to Continue ..."<<endl;;
				cin.ignore();
				HeightDisplay=15;
			}
		}
		
		
	}
}