#include <string>
using std::string;

#include <iostream>

#include <cctype> // for isalpha

#include "algebraic_expressions.hpp"

bool isoperator(char ch) {
  return ((ch == '+') || (ch == '-') || (ch == '/') || (ch == '*'));
}

int endPost(string s, int last) {
  int first = 0;

  if ((first > last)) {
    return -1;
  }

  char ch = s[last];
  if (isalpha(ch)) {
    return last;
  } else {
    if (isoperator(ch)) {
      int lastEnd = endPost(s, last - 1);
      if (lastEnd > -1) {
        return endPost(s, lastEnd - 1);
      } else {
        return -1;
      }
    } else {
      return -1;
    }
  }
}

bool isPost(string s) {
  int firstChar = endPost(s, s.size() - 1);

  return (firstChar == 0);
}

void convert(string &postfix, string &prefix) { //postfix and prefix already valid

  // TODO
  size_t sizePost = postfix.length();
  size_t sizePre = prefix.length();

  //putting postfix operators in front of prefix
  prefix.append(1, postfix[sizePost - 1]);

  if(isoperator(postfix[sizePost-1])){ //if last value is an operator, base case for recursion
    int start = endPost(postfix, sizePost-2); //index to last valid postfix expression in string

    string temp;
    temp = postfix.substr(0, start); //temp holds all values up to the last valid postfix expression
    convert(temp, prefix); // recursion

    string temp2;
    size_t sizeTemp2 = sizePost - start - 1;
    temp2 = postfix.substr(start, sizeTemp2);
    convert(temp2, prefix); 
  }
  return;
  
}
