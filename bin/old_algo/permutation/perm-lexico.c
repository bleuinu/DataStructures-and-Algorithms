/* Print Permutations in lexicographic order 
 * Code revised from: https://www.geeksforgeeks.org/lexicographic-permutations-of-string
 *
 * Name: Jii Myoui
 * Date: July 27, 2018
 * */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SWAP(x, y) {int temp = (x); (x) = (y); (y) = temp;}

int compare(const void *a, const void *b)
{
	return (*(char *)a - *(char *)b);
}

void sortedPermutations(char str[], int n)
{
	qsort(str, n, sizeof(str[0]), compare);

	bool isFinished = false;
	while (!isFinished)
	{
		printf("%s\n", str);

		int index;
		for (index = n - 2; index >= 0; --index)
		{
			if (str[index] < str[index + 1])
				break;
		}

		if (index == -1)
		{
			isFinished = true;
		}
		else
		{
			int low = index + 1;
			int high = n - 1;
			for (int i = low; i <= high; ++i)
			{
				if (str[i] > str[index] && str[i] < str[low])
				{
					low = i;
				}
			}

			SWAP(str[index], str[low]);

			low = index + 1;
			high = n - 1;
			while (low < high)
			{
				SWAP(str[low], str[high]);
				++low;
				--high;
			}
		}
	}
}

int main(void)
{
	char str[] = "cbaz";
	sortedPermutations(str, strlen(str));

	return 0;
}
