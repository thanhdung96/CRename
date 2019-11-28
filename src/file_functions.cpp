#include "file_functions.h"

bool fileImportDirectory(vector<path>* lstFile, const string pth, unsigned& count){
	if (exists(pth)){
		if (is_directory(pth)){
			for (directory_entry& entry : directory_iterator(pth)){
				lstFile->push_back(entry.path());
				count += 1;
			}
			return true;
		}
		return false;
	}
	return false;
}

bool addFile(vector<path>* lstFile, const string pth){
	if (exists(pth)){
		if (!is_directory(pth)){
			path p(pth);
			lstFile->push_back(p);
			return true;
		}
		return false;
	}
	return false;
}

string* fileShow(vector<path>* lstFile, const unsigned& index){
	return nullptr;
}

vector<string>* fileShowAll(vector<path>* lstFile){
	return nullptr;
}

bool fileRemove(vector<path>* lstFile, const unsigned& index){
	if (index < 0 || index >= lstFile->size()){
		return false;
	}
	lstFile->erase(lstFile->begin() + index);
	return true;
}

bool fileRemoveAll(vector<path>* lstFile){
	lstFile->clear();
	lstFile->shrink_to_fit();
	return true;
}