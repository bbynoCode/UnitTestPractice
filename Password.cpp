#include "Password.h"
#include <string>
#include <cctype>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  int repetition = 0;
  int index = 0;
  if(phrase.length() == 0){
    return repetition;
  }
  repetition = 1;
  while( index < phrase.length()){
    if (phrase[index] == phrase[index+1])
      repetition++;
    index++;
  }
  return repetition;
}

//The function takes a string as input and determines if there are lowercase and uppercase characters in it.
bool Password::has_mixed_case(string phrase){
  if(phrase.length() == 0)
    return false;

  if(phrase.length() == 1)
    return false;

  int index = 0;
  while( index < phrase.length()){
    if(islower(phrase[index]) && isupper(phrase[index+1])) {
      return true;
    }
    index++;
  }
  return false;
}