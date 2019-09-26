#include <iostream>
#include <stack>
using namespace std;

void revstrstk(char *line)
{
	stack<char> stk;
	char *p = line;

	while(*p != '\0')
	{
		stk.push(*p);
		++p;
	}

	while(!stk.empty())
	{
		cout << stk.top();
		stk.pop();
	}
	cout << endl;
}

int main()
{
	const size_t LINE_SIZE = 256;
	char line[LINE_SIZE];

	cin.getline(line, LINE_SIZE);

	revstrstk(line);

	return 0;
}
