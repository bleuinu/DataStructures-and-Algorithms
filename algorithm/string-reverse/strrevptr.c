#include <stdio.h>
#include <string.h>

/* String Reverse with Pointer */
void strrevptr(char *line)
{
	char *p = line;
	char *q = line + strlen(line) - 1;

	while(p < q)
	{
		char temp = *p;
		*p = *q;
		*q = temp;

		++p;
		--q;
	}
}

int main(void)
{
	const int LINE_SIZE = 256;
	char line[LINE_SIZE];

	fgets(line, LINE_SIZE, stdin);
	line[strcspn(line, "\n")] = 0;

	strrevptr(line);
	printf("%s\n", line);

	return 0;
}
