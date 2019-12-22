#ifdef IS_LINUX
	#include <boost/filesystem.hpp>
#else
	#include <boost\filesystem.hpp>
#endif

#include <vector>
#include <string>
#include <sstream>
using namespace std;
using namespace boost::filesystem;

bool fileImportDirectory(vector<path>* lstFile, const string pth, unsigned& count);
bool addFile(vector<path>* lstFile, const string pth);
string fileShow(vector<path>* lstFile, const unsigned& index);
vector<string>* fileShowAll(vector<path>* lstFile);
bool fileRemove(vector<path>* lstFile, vector<path>* lstAbsolutePath, vector<path>* lstResolvedFileName, const unsigned& index);
size_t fileRemoveAll(vector<path>* lstFile, vector<path>* lstAbsolutePath, vector<path>* lstResolvedFileName);
void fileMove(vector<path>& lstFiles, vector<path>& lstAbsolutePath, vector<path>& lstResolvedFileName, unsigned int from, unsigned int to);

void resolveToAbsolute(vector<path>* lstFile, vector<path>* lstAbsolutePath, vector<path>* lstResolvedFileName);
void removeElementFromList(vector<path>* lstFile, vector<path>* lstAbsolutePath, vector<path>* lstResolvedFileName, const int& index = -1);
