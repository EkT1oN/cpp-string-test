
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>

std::vector<std::string> words;

void getWordsFromString(std::string enterString) {
	std::string word;
	std::stringstream stringStream(enterString);
	while (stringStream >> word) {
		words.push_back(word);
	}
}

void insertingNewFieldByIndex(int index, std::string newString) {
	words.insert(words.begin() + index, 1, newString);
}

void editFieldByIndex(int index, std::string newString) {
	words[index] = newString;
}

void deleteFieldByIndex(int index) {
	words.erase(words.begin() + index);
}

std::string convertVectorToString() {
	std::ostringstream oStringStream;
	if (!words.empty()) {
		std::copy(words.begin(), 
			words.end() - 1, 
			std::ostream_iterator<std::string>(oStringStream, "\t"));
		oStringStream << words.back();
	}
	return oStringStream.str();
}

void insertNewField() {
	int newIndex;
	std::cin >> newIndex;	//	index for inserting
	int diff = newIndex - words.size();
	if (diff <= 0) {
		std::string newString;	//	data for new field
		std::cin >> newString;
		insertingNewFieldByIndex(newIndex, newString);
	}
	else {
		std::cout << "Wrong index" << std::endl;
	}
	std::string newElemString = convertVectorToString();
	std::cout << newElemString << std::endl;
}

void editField() {
	int editingIndex;	//	index to edit field
	std::cin >> editingIndex;
	if ((editingIndex >= 0) || (editingIndex <= words.size())) {
		std::string editingString;	//	new data for editing field
		std::cin >> editingString;
		editFieldByIndex(editingIndex, editingString);
	}
	else {
		std::cout << "Wrong index" << std::endl;
	}
	std::string editElemString = convertVectorToString();
	std::cout << editElemString << std::endl;
}

void deleteField() {
	int deleteIndex;	//	index to delete field
	std::cin >> deleteIndex;
	if ((deleteIndex >= 0) || (deleteIndex <= words.size())) {
		deleteFieldByIndex(deleteIndex);
	}
	else {
		std::cout << "Wrong index" << std::endl;
	}
	std::string deleteElemString = convertVectorToString();
	std::cout << deleteElemString << std::endl;
}

void newString() {
	std::string enterStrings;
	std::getline(std::cin, enterStrings);
	getWordsFromString(enterStrings);
}



int main() {
	//	Enter a new string with which to interact
	newString();

	//	Block of inserting new field in vector by index
	insertNewField();
	
	//	Block of editing field in vector by index
	editField();

	//	Block of deleting field in vector by index 
	deleteField();

	return 0;
}