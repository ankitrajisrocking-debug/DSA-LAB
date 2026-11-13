#include <stdio.h>

void quickSort(int a[], int low, int high) { if (low < high) { int pivot = a[high]; int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (a[j] < pivot)
        {
            i++;

            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    int temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    int p = i + 1;

    quickSort(a, low, p - 1);
    quickSort(a, p + 1, high);
}


}

int main() { int a[] = {4, 6, 5}; int n = 3;

quickSort(a, 0, n - 1);

printf("Sorted array: ");

for (int i = 0; i < n; i++)
{
    printf("%d ", a[i]);
}

return 0;


}
