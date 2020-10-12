#include <stdio.h>
#include <string.h>

void strrevindex(char *line)
{
	int size = strlen(line);
	int bound = size >> 1;

	for(int i=0; i<bound; ++i)
	{
		char temp = line[i];
		line[i] = line[size-(1+i)];
		line[size-(1+i)] = temp;
	}
}

int main(void)
{
	const int LINE_SIZE = 256;
	char line[LINE_SIZE];

	fgets(line, LINE_SIZE, stdin);
	line[strcspn(line, "\n")] = 0;

	strrevindex(line);
	printf("%s\n", line);

	return 0;
}
