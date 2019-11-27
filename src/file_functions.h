#include <boost\filesystem.hpp>
#include <vector>
#include <string>
using namespace std;
using namespace boost::filesystem;

bool fileImportDirectory(vector<path>* lstFile, const string pth, unsigned& count);
bool addFile(vector<path>* lstFile, const string pth);
string* fileShow(vector<path>* lstFile, const unsigned& index);
vector<string>* fileShowAll(vector<path>* lstFile);
bool fileRemove(vector<path>* lstFile, const unsigned& index);
bool fileRemoveAll(vector<path>* lstFile);