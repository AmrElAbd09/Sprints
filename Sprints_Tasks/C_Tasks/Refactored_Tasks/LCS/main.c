#include"LCS.h"

int main()
{
    uint8_t size;
    int32_t array[10];

  int CaseCounter = 1;
    while (1) {

    printf("Test Case %d:\n",CaseCounter);
    uint8_t  LCS = 1;

    printf("Please enter array size: ");
    scanf("%d", &size);
     array[size];

    printf("Please enter array elements\n");
    for (int i = 0; i < size; i++) {
        scanf(" %d", &array[i]);
    }

    insertionSort(array, size);


    int8_t state = lcsGetSize(array, size, &LCS);

    if (state == -1)
    {
        printf("Array is empty!\n");
    }
    else if (state == -2)
    {
        printf("Array size is 0 or >10!\n");
    }
    else if (state == -3)
    {
        printf("All array elements are not consecutive at all!\n");
    }
    else
    {
        printArray(array, size);
        printf("Longest number for Consecutive array elements is : %d \n",LCS);
    }
    CaseCounter++;
    }

    return 0;
}
