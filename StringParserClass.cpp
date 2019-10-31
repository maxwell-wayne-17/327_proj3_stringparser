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



	return SUCCESS;
}







