#include <stdio.h>

int BinarySearch(int nums[], int target, int length)
{
    int left = 0;
    int right = length - 1;

    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (target == nums[middle])
        {
            printf("middle = %d\n",middle);
            printf("SUCCESS:Middle found.\n");
            return middle;
        }
        else if (target > nums[middle])
        {
            printf("middle = %d\n",middle);
            left = middle + 1;
            printf("NEXT:left=middle+1.\n");
        }
        else
        {
            printf("middle = %d\n",middle);
            right = middle - 1;
            printf("NEXT:right=middle-1.\n");
        }
    }
    return -1;
}

int main(void)
{
    int special[10000000];
    for(int i = 1;i<=10000000;i++){
        special[i-1]=i;
    }
    int test[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int result = BinarySearch(special, 10, 10000000);
    printf("result:%d\n", result);

    return 0;
}