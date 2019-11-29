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

string fileShow(vector<path>* lstFile, const unsigned& index){
	if (index < 0 || index >= lstFile->size()){
		return "";
	}

	return lstFile->at(index).string();
}

vector<string>* fileShowAll(vector<path>* lstFile){
	if (lstFile->size() == 0){
		return nullptr;
	}

	vector<string>* lstFileString = new vector<string>();
	for (unsigned i = 0; i < lstFile->size(); i++){
		lstFileString->push_back(lstFile->at(i).string());
	}

	return lstFileString;
}

bool fileRemove(vector<path>* lstFile, const unsigned& index){
	if (index < 0 || index >= lstFile->size()){
		return false;
	}
	lstFile->erase(lstFile->begin() + index);
	lstFile->shrink_to_fit();
	return true;
}

size_t fileRemoveAll(vector<path>* lstFile){
	size_t totalRemoved = lstFile->size();
	lstFile->clear();
	lstFile->shrink_to_fit();

	return totalRemoved;
}