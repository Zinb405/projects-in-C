#include <stdio.h>
#include <stdlib.h>
long count = 0;

int partition(int array[], int len);

int partition(int array[], int len)
{
    // base case
    if (len <= 1)
    {
        return count;
    }
    int j, k, p, tmp;
    int i = 1;

    int length;
    // pick up the first element as a pivot
    int pivot = array[0];
    // comparison
    for (j = 1; j < len; j++)
    {

        if (array[j] < pivot)
        {
            tmp = array[j];
            array[j] = array[i];
            array[i] = tmp;
            i++;
        }
        count++;
    }
    // swap pivot
    tmp = array[i - 1];
    array[i - 1] = pivot;
    array[0] = tmp;
    length = i - 1;
    int *less_pivot = (int *) malloc(length * sizeof(int));
    if (less_pivot == NULL)
    {

        exit(1);
    }
    int *great_pivot = (int *) malloc((len - length - 1) * sizeof(int));
    if (great_pivot == NULL)
    {

        exit(1);
    }
    // copy elements into the left partition
    for (k = 0; k < length; k++)
    {
        less_pivot[k] = array[k];
    }
    // copy elements into the right partition
    for (k = 0, p = length + 1; k < len - length - 1; k++, p++)
    {

        great_pivot[k] = array[p];
    }
    // recursive calls
    partition(less_pivot, length);
    partition(great_pivot, len - length - 1);
    // free allocated memory
    free(less_pivot);
    free(great_pivot);

    return count;
}

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Enter please the text file\n");
    }
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {

        printf("File coudn't be open!\n");
        return 1;
    }
    int len = 10000;
    int array[len];

    for (int i = 0; i < len; i++)
    {
        fscanf(input, "%d", &array[i]);
    }
    partition(array, len);

    printf("%ld\n", count);

    fclose(input);
    return 0;
}
