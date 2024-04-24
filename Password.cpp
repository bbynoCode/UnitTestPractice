#include "Password.h"
#include <string>
#include <cctype>
#include <vector>

using std::string;
using std::vector;

int MIN_PASSWORD_LENGTH = 8;
int MAX_PASSWORD_LENGTH = 20;
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

  bool has_lower = false;
  bool has_upper = false;

  int index = 0;
  while(index < phrase.length()){
    if (islower(phrase[index])){
      has_lower = true;
    } else if (isupper(phrase[index])) {
      has_upper = true;
    }
    index++;
  }
  return has_lower && has_upper;
}


  /*
  receives a password and sets the latest in pass_history to it if and only
  if it meets all criteria:
    1. The password is at least 8 letters long, but no longer than 20
    2. It has no more than 3 of the same leading characters
    3. It has mixed case (at least one upper case and at least one lower case)
    4. It was not a previous password in the history
  */
void Password::set(string phrase){

  if ((phrase.length() >= MIN_PASSWORD_LENGTH) && (phrase.length() <= MAX_PASSWORD_LENGTH) ){
    if ((count_leading_characters(phrase) <= 3) && has_mixed_case(phrase)){
      pass_history.push_back(phrase);
    }
  }

}


  /*
  receives a string and authenticates it against the latest password in the
  pass_history, returning true for an exact match or false when it does not match
  or if a password has not been set.
  */
bool Password::authenticate(string phrase){
  if(phrase == pass_history.back()){
    return true;
  }
  return false;
}
