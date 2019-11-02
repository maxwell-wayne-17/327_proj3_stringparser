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

	cleanup();

	pStartTag = new char[strlen(pStart) + 1];
	pEndTag = new char[strlen(pEnd) + 1];

	strcpy(pStartTag, pStart);
	strcpy(pEndTag, pEnd);


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
	std::string word = "";


	for (int i = 0; i < strlen(pDataToSearchThru); i++){

		char starter = pStartTag[0];
		char check = pDataToSearchThru[i];
		if (check == starter){

			char *dataStart = &pDataToSearchThru[i];
			if (strncmp(dataStart, pStartTag, strlen(pStartTag)) == 0){

				i += strlen(pStartTag); //tag is equal,skip over tag

				char endTagStart = pEndTag[0];
				check = pDataToSearchThru[i];
				bool foundEndTagStart = false;
				while (check != endTagStart && i < strlen(pDataToSearchThru)){

					word += check;
					i++;
					check = pDataToSearchThru[i];


					}
				if (check == endTagStart){
					foundEndTagStart = true;
					char* dataEnd = &pDataToSearchThru[i];
					if (strncmp(dataEnd, pEndTag, strlen(pEndTag)) == 0){

						myVector.push_back(word);
						word = "";
						i += strlen(pEndTag) - 1;
					}
				}

			} //end of actually finding full start tag

		} //end of checking for first char of pStartTag

	} // outer most for loop



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







