/* Print all Permutations
 *
 * Name: Jii Myoui
 * Date: July 27, 2018
 * */

#include <stdio.h>

#define SWAP(x,y,z) {(z) = (x); (x) = (y); (y) = (z);}

typedef int elem;

void perm(elem list[], int d, int n)
{
	if (d == n)
	{
		for (int i = 0; i <= n; ++i)
			printf("%d ", list[i]);
		printf("\n");
	}
	else
	{
		int temp;
		for (int i = d; i <= n; ++i)
		{
			SWAP(list[i], list[d], temp);
			perm(list, d + 1, n);
			SWAP(list[i], list[d], temp);
		}
	}
}

int main(void)
{
	elem list[] = {1,2,3};
	int n = sizeof(list) / sizeof(list[0]);
	perm(list, 0, n - 1);

	return 0;
}
