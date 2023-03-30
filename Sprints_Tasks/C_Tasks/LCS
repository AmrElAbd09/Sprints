#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* Description:
 * - This function takes a reference to an array of integers
 * - Sorts the array in ascending order
 * - Using the insertion sort algorithm
 * Return:
 * - returns -1 if the array is empty
 * - returns -2 if the array size is 0 or >10
 * - returns 0 if sorting is done without errors
 */
int8_t insertionSort(int32_t* array, uint8_t arraySize)
{
    int32_t key, i, j;

    if (arraySize == 0 || arraySize > 10)
    {
        return -2;
    }
    if (array == NULL)
    {
        return -1;
    }
    for (i = 1; i < arraySize; i++)
    {
        j = i - 1;
        key = array[i];
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
    return 0;
}

/* Description:
 * - This function takes a reference to an array of integers
 * - Prints all array elements
 * Return:
 * - Nothing to return
 */
void printArray(int32_t* array, uint8_t arraySize)
{

    for (int i = 0; i < arraySize; i++)
    {
        printf(" %d ", array[i]);
    }
    printf("\n");
}

/* Description:
 * - This function takes a reference to an array,
 * - array size, and
 * - reference to store the size of the LCS
 * - Using the insertion sort algorithm
 * - The function will search for the LCS in the array and
 * - stores its size
 * Return:
 * - returns -1 if the array is empty
 * - returns -2 if the array size is 0 or >10
 * - returns -3 if there is no LCS,
 * (i.e all array elements are not consecutive at all)
 * - returns 0 otherwise
 */
int8_t lcsGetSize(int32_t* array, uint8_t arraySize, uint8_t* sizeofLCS) {

    uint8_t longest = 1;

    if (arraySize == 0 || arraySize > 10)
    {
        return -2;
    }
    if (array == NULL)
    {
        return -1;
    }
    *sizeofLCS = 0;
    for (int i = 0; i < arraySize -1; i++) {
        if (array[i + 1] - array[i] == 1) {
            longest++;
        }
        else {
            longest = 1;
        }
        if (longest > *sizeofLCS) {
            *sizeofLCS = longest;
        }
        
    }

    if (longest == 1) {
        return -3;
    }    

    return 0;
}

int main()
{
    uint8_t size;
    int32_t array[10];

  /*  printf("Test Case 1:\n");
    size = 10;
    int32_t test1[] = { 9, 0, 7, 5, 3, 8, -10, 4, 2, 1 };
    for (int i = 0; i < size; i++)
    {
        array[i] = test1[i];
    }
    int8_t state = insertionSort(array, size);

    if (state == -1)
    {
        printf("Array is empty!\n");
    }
    else if (state == -2)
    {
        printf("Array size is 0 or >10\n");
    }
    else
    {
        printf("Array is : ");
        printArray(array, size);
    }
    printf("Test Case 2:\n");
    size = 0;
    state = insertionSort(array, size);

    if (state == -1)
    {
        printf("Array is empty!\n");
    }
    else if (state == -2)
    {
        printf("Array size is 0 or >10\n");
    }
    else
    {
        printf("Array is : ");
        printArray(array, size);
    }
    printf("Test Case 3:\n");
    size = 12;
    int32_t test3[] = { 9, 0, 7, 5, 3, 8, -10, 4, 2, 1, 6, 12 };
    for (int i = 0; i < size; i++)
    {
        array[i] = test3[i];
    }
    state = insertionSort(array, size);

    if (state == -1)
    {
        printf("Array is empty!\n");
    }
    else if (state == -2)
    {
        printf("Array size is 0 or >10\n");
    }
    else
    {
        printf("Array is : ");
        printArray(array, size);
    }

    printf("Test Case 4:\n");
    size = 10;
    int32_t test4[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (int i = 0; i < size; i++) {
        array[i] = test4[i];
    }
    state = insertionSort(array, size);

    if (state == -1)
    {
        printf("Array is empty!\n");
    }
    else if (state == -2)
    {
        printf("Array size is 0 or >10\n");
    }
    else
    {
        printf("Array is : ");
        printArray(array, size);
    }
    */
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
