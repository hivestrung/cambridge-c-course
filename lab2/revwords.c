#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "revwords.h"

void reverse_substring(char str[], int start, int end) {
  /* TODO */
  int len = (end-start+1)/2; // truncation towards zero
  for (int i = 0; i < len; i++)
  {
      char tmp = str[start];
      str[start++] = str[end];
      str[end--] = tmp;
  }
}


int find_next_start(char str[], int len, int i) {
  /* TODO */
  // assume i >= 0
  // check if there is a word starting at i
  if (i >= len) {
      return -1;
  }
  // keep moving forward until you find a letter
  bool spacePrev = (i == 0) ? true : false;
    while (i < len) {
        // if current index is a character
        if (isalpha(str[i])) {
            if (spacePrev) {
                break;
            }
            else {
                spacePrev = false;
                i++;
            }
        }
        else {
            spacePrev = true;
            i++;
        }
    }
    // now i is len or i is start of word
    if (i == len) {
        return -1;
    }
    else {
        return i;
    }
  }

int find_next_end(char str[], int len, int i) {
  /* TODO */
  if (i >= len) {
      return -1;
  }
    while (i < len) {
        // if current index is not a character
        if (!isalpha(str[i])) {
            break;
        }
        else {
            i++;
        }
    }
    // now i is len or i is start of word
    return i;
}

void reverse_words(char s[]) {
  /* TODO */
  // for word in s
    // reverse the word in-place
    int len = strlen(s);
    int i = 0;
    int start, end;
    while (i < len) {
        start = find_next_start(s, len, i);
        if (start == -1) {
            return;
        }
        end = find_next_end(s, len, start);
        reverse_substring(s, start, end-1);
        i = end;
    }
}
