/* Print all Permutations using dfs
 * This codes was used for BOJ Problem# 10974
 *
 * Name: Jii Myoui
 * Date: July 27, 2018
 * */

#include <stdio.h>
#include <stdbool.h>

bool v[10];
int tmp[10];

void permutation(int num, int d, int n)
{
	tmp[d] = num;

	if (d == n)
	{
		for(int i=1; i<=n; ++i) 
			printf("%d ", tmp[i]);	
		printf("\n");
	}

	for (int i = 1; i <= n; ++i)
	{
		if (v[i]) continue;
		v[i] = true;
		permutation(i, d + 1, n);
		v[i] = false;
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		v[i] = true;
		permutation(i, 1, n);
		v[i] = false;
	}
	return 0;
}
