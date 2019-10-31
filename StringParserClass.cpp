/*
 * StringParserClass.cpp
 *
 *  Created on: Oct 29, 2019
 *      Author: Max Wayne
 */

#include <string>
#include <string.h>
#include "../327_proj3_test/includes/FileIO.h"
#include "../327_proj3_test/includes/constants.h"
#include "../327_proj3_test/includes/StringParserClass.h"



#include <iostream>

using namespace KP_StringParserClass;

StringParserClass::StringParserClass(void):pStartTag(NULL), pEndTag(NULL), areTagsSet(false){}

StringParserClass::~StringParserClass(void){

	cleanup();

}

int StringParserClass::setTags(const char *pStart, const char *pEnd){
	if (!pStart || !pEnd){
		return ERROR_TAGS_NULL;
	}

	char start = *pStart;
	char end = *pEnd;

	this->pStartTag = &start;
	this->pEndTag = &end;

	return SUCCESS;
}

int StringParserClass::getDataBetweenTags(char *pDataToSearchThru, std::vector<std::string> &myVector){

	if (!this->pStartTag || !this->pEndTag){
		return ERROR_TAGS_NULL;
	}
	if (!pDataToSearchThru){
		return ERROR_DATA_NULL;
	}

	myVector.clear();



	return SUCCESS;
}


void StringParserClass::cleanup(){
	if (pStartTag){
		delete[] pStartTag;
	}
	if (pEndTag){
		delete[] pEndTag;
	}
}

int StringParserClass::findTag(char *pTagToLookFor, char *&pStart, char *&pEnd){

	if (pStart == NULL|| pEnd == NULL){
		return ERROR_TAGS_NULL;
	}

	std::string stringToSearch(pStart);
	std::string tagToFind(pTagToLookFor);

	//for loop to compare strings
	bool endCharFound = false;
	for (int i = 0; i < stringToSearch.size() && !endCharFound; i++){

		//found starting character in string
		if (stringToSearch[i] == tagToFind[0]){

			int tracker = i;
			bool tagIsNotEqual = false;
			//check for valid substring
			for (int j = 0; j < tagToFind.size() && !tagIsNotEqual; j++){
				//checking if tag is not equal
				if (stringToSearch[tracker] != tagToFind[j]){
					//break out of inner for loop
					tagIsNotEqual = true;
				}
				else{
					tracker ++;
				}
			}

			//tags failed
			if (tagIsNotEqual){
				return FAIL;
			}

			*pStart = stringToSearch[i];
		}
	}



	return SUCCESS;
}







