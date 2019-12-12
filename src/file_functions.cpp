#include "file_functions.h"

bool fileImportDirectory(vector<path>* lstFile, const string pth, unsigned& count){
	if (exists(pth)){
		if (is_directory(pth)){
			path p;
			for (directory_entry& entry : directory_iterator(pth)){
				p = entry.path();
				if (is_regular_file(p)){
					lstFile->push_back(entry.path());
					count += 1;
				}
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

bool fileRemove(vector<path>* lstFile, vector<path>* lstAbsolutePath, vector<path>* lstResolvedFileName, const unsigned& index){
	if (index < 0 || index >= lstFile->size()){
		return false;
	}
	removeElementFromList(lstFile, lstAbsolutePath, lstResolvedFileName, index);

	return true;
}

size_t fileRemoveAll(vector<path>* lstFile, vector<path>* lstAbsolutePath, vector<path>* lstResolvedFileName){
	size_t totalRemoved = lstFile->size();
	removeElementFromList(lstFile, lstAbsolutePath, lstResolvedFileName);

	return totalRemoved;
}

void resolveToAbsolute(vector<path>* lstFile, vector<path>* lstAbsolutePath, vector<path>* lstResolvedFileName){
	removeElementFromList(nullptr, lstAbsolutePath, lstResolvedFileName);

	path tempPath;
	for (unsigned i = 0; i < lstFile->size(); i++){
		tempPath = absolute(lstFile->at(i));
		lstAbsolutePath->push_back(tempPath.parent_path());
		lstResolvedFileName->push_back(tempPath.filename());
	}
}

void removeElementFromList(vector<path>* lstFile, vector<path>* lstAbsolutePath, vector<path>* lstResolvedFileName, const int& index){
	if (index == -1){	//if index = -1 then remove all
		if (lstFile != nullptr){
			lstFile->clear();
			lstFile->shrink_to_fit();
		}
		lstAbsolutePath->clear();
		lstAbsolutePath->shrink_to_fit();
		lstResolvedFileName->clear();
		lstResolvedFileName->shrink_to_fit();
	}
	else{
		if (lstFile != nullptr){
			lstFile->erase(lstFile->begin() + index);
			lstFile->shrink_to_fit();
		}
		lstAbsolutePath->erase(lstAbsolutePath->begin() + index);
		lstAbsolutePath->shrink_to_fit();
		lstResolvedFileName->erase(lstResolvedFileName->begin() + index);
		lstResolvedFileName->shrink_to_fit();
	}
}
