#include <iostream>

using namespace std;

inline int min(int x, int y)
{
    return x < y ? x : y;
}

string getModifiedString(string s)
{
    string modifiedString = "#";
    for (int i = 0; s[i] != '\0'; ++i)
    {
        modifiedString += s[i];
        modifiedString += "#";
    }
    
    return modifiedString;
}

int manacher(string s)
{
    string str = getModifiedString(s);

    size_t len = 2 * s.size() + 1;
    int *p = new int[len];
    int c = 0;
    int r = 0;
    int maxLen = 0;

    for (int i=0; i<len; ++i)
    {
        int mirror = 2 * c - i;

        if (i < r)
        {
            min(r - i, p[mirror]);
        }
        
        int a = i + (1 + p[i]);
        int b = i - (1 + p[i]);
        while (a < len && b >= 0 && str[a] == str[b])
        {
            ++p[i];
            ++a;
            --b;
        }

        if (i + p[i] > r)
        {
            c = i;
            r = i + p[i];

            if (p[i] > maxLen)
            {
                maxLen = p[i];
            }
        }
    }

    return maxLen;
}

int main()
{
    string s;
    cin >> s;
    cout << manacher(s) << endl;

    return 0;
}
