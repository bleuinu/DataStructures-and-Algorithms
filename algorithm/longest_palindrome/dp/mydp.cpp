#include <iostream>
#include <string.h>
#include <cstdio>

using namespace std;

void printTable(bool *table, size_t size)
{
    for (int i=0; i<size; ++i)
    {
        for (int j=0; j<size; ++j)
        {
            printf("%d ", table[size*i+j]);
        }
        printf("\n");
    }
    printf("\n");
}

size_t longestPalindrome(string str)
{
    size_t size = str.size();
    size_t maxLength = 1;

    // All string with length 1 is a palindrome
    if (size == 1)
    {
        cout << "palindrome: " << str << endl;
        return maxLength;
    }

    // create a table
    bool table[size][size];
	memset(table, 0, sizeof(table)); 
    for (int i=0; i<size; ++i)
    {
        table[i][i] = true;
    }

    // Check length 2 string
    int start = 0;
    for (int i=0; i<size-1; ++i)
    {
        if (str[i] == str[i+1])
        {
            table[i][i+1] = true;
            start = i;
            maxLength = 2;
        }
    }

    //  k => length of the longest palindrome
    for (int k=3; k<=size; ++k)
    {
        for (int i=0; i<size-k+1; ++i)
        {
            int j = k - 1 + i;

            if (table[i+1][j-1] == true && str[i] == str[j])
            {
                table[i][j] = true;

                if (k > maxLength)
                {
                    maxLength = k;
                    start = i;
                }
            }
        }
    }

    printf("longest substr: ");
    for (int i=start; i<start+maxLength; ++i)
    {
        printf("%c", str[i]);
    }
    printf("\n");
    return maxLength;
}

int main()
{ 
    string str = "1283741982378927819478123892718932139012409901293590182939802089392810953921099042109312398172983218749187298732891473821902719847923092941920389021";

    size_t length = longestPalindrome(str);
    printf("length: %lu\n", length);

    return 0;
}
