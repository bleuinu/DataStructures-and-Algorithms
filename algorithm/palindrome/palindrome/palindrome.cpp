#include <iostream>
#include <string>

using namespace std;

#define LOWERCASE true
#define UPPERCASE false

void setCases(string &str, bool lowercase)
{
    const int SIZE = str.end() - str.begin();

    for (int i=0; i<SIZE; ++i)
    {
        str[i] = (lowercase) ? tolower(str[i]) : toupper(str[i]);
    }
}

void ignoreSpaces(string &str)
{
    const int SIZE = str.end() - str.begin();
    string ret = "";

    for (int i=0; i<SIZE; ++i)
    {
        if (str[i] !=  ' ')
        {
            ret += str[i];
        }
    }

    str = ret;
}

bool isPalindrome(string str)
{
    setCases(str, LOWERCASE);
    ignoreSpaces(str);

    const int SIZE = str.end() - str.begin();
    const int HALF = SIZE >> 1;

    for (int i=0; i<HALF; ++i)
    {
        if (str[i] != str[SIZE - 1 - i])
        {
            return false;
        }
    }

