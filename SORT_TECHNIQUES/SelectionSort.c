#include <stdio.h>
int main() {
    int arr[100], n;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    printf("Enter %d Elements : \n", n);
    for (int c = 0; c < n; c++)
        scanf("%d", &arr[c]);

   int i, j, position, swap;
   for (i = 0; i < (n - 1); i++) {
      position = i;
      for (j = i + 1; j < n; j++) {
         if (arr[position] > arr[j])
            position = j;
      }
      if (position != i) {
         swap = arr[i];
         arr[i] = arr[position];
         arr[position] = swap;
      }
   }
   printf("SORTED ARRAY : \n");
   for (i = 0; i < n; i++)
      printf("%d\t", arr[i]);
   return 0;
}