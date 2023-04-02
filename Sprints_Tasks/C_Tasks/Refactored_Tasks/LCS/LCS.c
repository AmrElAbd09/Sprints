#include"LCS.h"

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
