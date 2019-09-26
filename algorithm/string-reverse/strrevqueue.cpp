#include <iostream>
#include <queue>
using namespace std;

void revstrstk(char *line)
{
	queue<char> q;
	queue<char> q2;
	char *p = line;

	while(*p != '\0')
	{
		q.push(*p);
		
		while(!q2.empty())
		{
			q.push(q2.front());
			q2.pop();
		}

		while(!q.empty())
		{
			q2.push(q.front());
			q.pop();
		}

		++p;
	}

	p = line;
	while(!q2.empty())
	{
		*p = q2.front();
		q2.pop();
		++p;
	}
}

int main()
{
	const size_t LINE_SIZE = 256;
	char line[LINE_SIZE];

	cin.getline(line, LINE_SIZE);

	revstrstk(line);

	cout << line << endl;

	return 0;
}
