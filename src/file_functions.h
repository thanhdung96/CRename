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
bool fileRemove(vector<path>* lstFile, const unsigned& index);
size_t fileRemoveAll(vector<path>* lstFile);
