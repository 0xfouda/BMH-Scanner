#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct FiletoScan 
{
	char* FilePath;
	streamoff FileSize;
	char* buffer;
	int BufferSize;
};
struct FileChunk
{
	struct FiletoScan* ParentFile;
	unsigned int ChunkLength;
};

void fprep_FileHexProcess(struct FiletoScan* file);
struct FileChunk* fprep_ChunkProcess(struct FiletoScan* file);
void BufferDisplay(char* Buffer, int BufferSize);