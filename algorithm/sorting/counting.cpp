#include <stdio.h>
int main()
{
  int arr[10001] = {0};
  int n;
  scanf("%d", &n);
  for (int i=0; i<n; ++i)
  {
    int temp;
    scanf("%d", &temp);
    arr[temp] += 1;
  }

  for (int i=0; i<10001; ++i)
  {
    if (arr[i] > 0)
    {
      for (int j=0; j<arr[i]; ++j)
        printf("%d\n", i);
    }
  }
  return 0;
}
