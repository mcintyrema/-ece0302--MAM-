// Project 3 -- XML Parsing Project

/** XML parsing class implementation.
    @file XMLParser.cpp */

#include <string>
#include <assert.h>
#include "XMLParser.hpp"

// TODO: Implement the constructor here
XMLParser::XMLParser()
{
	//initialize bool
	result = true;
	//holds elements while parsing
	parseStack = new Stack<std::string>;  
    elementNameBag = new Bag<std::string>; 
}  // end default constructor

// TODO: Implement the destructor here
XMLParser::~XMLParser()
{
	//clear values from stack and vector
	clear();
	//deallocate memory
	delete parseStack;
	delete elementNameBag;
}  // end destructor

// TODO: Implement the tokenizeInputString method
bool XMLParser::tokenizeInputString(const std::string &inputString)
{
	//initialize bool
	result = 0;  
    unsigned headNext;

	//base case for recursion is when inputString is clear
    if (inputString.length() == 0) { 
        return false;
    }  
	//tag does not start and end with <>
    else if (inputString[0] != '<' || inputString[inputString.length() - 1] != '>') {
        this->clear();
        return false;
    } 

    else {
		//return false if cant fine >
        if (inputString.find('>', 1) == -1) {
            this->clear();
            return false;
        }  
		//find next > in string
        unsigned tailNext = inputString.find('>', 1); 
        unsigned startIndex = 0;                   
        unsigned endIndex = 0;  

		//temporary token holder
        TokenStruct tempToken;  
        std::string elementStr;

		//next tag is not an end tag and no head subtag found
        if (inputString.find('<', tailNext) == -1) {
            headNext = tailNext + 1;
        }  
        else {
            headNext = inputString.find('<', tailNext);
        }

		//search for end > before next start <
        if (inputString.find('>', tailNext + 1) < headNext) {
            this->clear();
            return false;
        }  

		//search for < tag start before next >
        if (inputString.find('<', 1) < tailNext + 1) {
            this->clear();
            return false;
        }  
		
        // checking char ? is before > for declaration
        if (inputString[1] == '?') {  
            if (inputString[tailNext - 1] == '?') {
                tempToken.tokenType = DECLARATION;  
            } 
			else {  
				//declaration is invalid
                this->clear();
                return false;
            }

			//add char from declaration to string holder
            for (unsigned i = 2; i < tailNext - 1; i++) {
                elementStr += inputString[i];  
                                               
            }

			//pushing token onto vector of tokens
            tempToken.tokenString = elementStr;         
            tokenizedInputVector.push_back(tempToken);  

           //pass substring intp recursive call
            if (inputString.substr(headNext) == "")
                return true;
            else
                return tokenizeInputString(inputString.substr(headNext));  
       		}
			// indicates closing tag
			else if (inputString[1] == '/') {          
				tempToken.tokenType = END_TAG;           
				startIndex = 1;                         
			} 
        	// / indicating empty tag
			else if (inputString[tailNext - 1] == '/') {  
				tempToken.tokenType = EMPTY_TAG;         
				endIndex = 1;                          
			}
			//if tag is none of the above, set as a start tag
			else {
				tempToken.tokenType = START_TAG;  
			}

        // searching for next end tag
        unsigned tempEnd = inputString.find(' ', 1);
		//check for invalid space in end tag
        if (tempEnd == -1 || tempEnd > tailNext)
            tempEnd = tailNext;
        else if (tempToken.tokenType == END_TAG && tempEnd != -1) {
            this->clear();  
            return false;   
        }

        // adding chars as tokens if valid
        for (unsigned i = 1 + startIndex; i < tempEnd - endIndex; i++) {
            elementStr += inputString[i];  
        }

		//add tokens to token holder while not at end tag
        if (tempToken.tokenType != END_TAG)
            elementNameBag->add(elementStr);  
        tempToken.tokenString = elementStr;   
        tokenizedInputVector.push_back(tempToken);  
        elementStr.clear();  

        // read content and check for blanks
        elementStr = inputString.substr(tailNext + 1, headNext - tailNext - 1);
        if (elementStr.find_first_not_of(" ") == -1)
            elementStr.clear();  

        // adding content to token
        if (elementStr.length() > 0) {
            tokenizedInputVector.push_back(
                TokenStruct{StringTokenType::CONTENT, std::string(elementStr)});
        }

		//pass substring to recursive call
        if (inputString.substr(headNext) == "")
            return true;
        else
            return tokenizeInputString(inputString.substr(headNext));
    }

}  // end

// TODO: Implement a helper function to delete attributes from a START_TAG
// or EMPTY_TAG string (you can change this...)
static std::string deleteAttributes(std::string input)
{
	return input;
}

// TODO: Implement the parseTokenizedInput method here
bool XMLParser::parseTokenizedInput() const
{
	for(int  i = 0; i < tokenizedInputVector.size(); i++){
		StringTokenType tempType = tokenizedInputVector[i].tokenType;

		switch(tempType){
			case START_TAG:
				parseStack->push(tokenizedInputVector[i].tokenString);
				break;
			case END_TAG:
				if(parseStack->isEmpty())
					return false;

				std::string headStack = parseStack->peek();
				if(tokenizedInputVector[i].tokenString != headStack)
					return false;

				parseStack->pop();
				break;	
		}
	}

	if(!parseStack->isEmpty()){
		return false;
	}

	result;
	return true;
}

// TODO: Implement the clear method here
void XMLParser::clear()
{
	elementNameBag->clear();
	parseStack->clear();
	tokenizedInputVector.clear();
}

vector<TokenStruct> XMLParser::returnTokenizedInput() const
{
	return tokenizedInputVector;
}

// TODO: Implement the containsElementName method
bool XMLParser::containsElementName(const std::string &inputString) const
{
	if(parseTokenizedInput() == false || result == true)
		return false;
	else if(elementNameBag->contains(inputString))	
		return true;
	else
		return false;	
}

// TODO: Implement the frequencyElementName method
int XMLParser::frequencyElementName(const std::string &inputString) const
{
	if (!tokenizedInputVector.size() && result)
        return false;  // if tokenized vector does not exist or xml string has
                       // not been parsed or is not valid, do not search for
                       // element name

    return elementNameBag->getFrequencyOf(
        inputString);  // use elementNameBag built in member function to get
                       // frequency


}

