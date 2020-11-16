#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

int QuickSort(int nums[],int left,int right){
    //@param: nums[]: numbers
    //@param: left: the number of the [0]
    if(left<right){
        int i=left;
        int j=right;
        int temp_middle=nums[left];//standard number

        while (i<j)
        {
            //from right to left,find a number smaller than standard number
            while (i<j&&nums[j]>=temp_middle)
            {
                j--;
            }
            if(i<j)
            {
                nums[i]=nums[j];
                i++;
            }
            while (i<j&&nums[i]<temp_middle)
            {
                i++;
            }
            if(i<j)
            {
                nums[j]=nums[i];
                j--;
            }           
        }
        nums[i]=temp_middle;
        QuickSort(nums,left,i-1);
        QuickSort(nums,j+1,right);        
    }
}

void bubbleSort(int nums[],int len){
    int i, j, temp;
        for (i = 0; i < len - 1; i++)
                for (j = 0; j < len - 1 - i; j++)
                        if (nums[j] > nums[j + 1]) {
                                temp = nums[j];
                                nums[j] = nums[j + 1];
                                nums[j + 1] = temp;
                        }
}

int random(int max,int min){
    int origin = rand();
    int random_num = origin%(max-min+1)+min;
    return random_num;
}

int main(void){
    srand((unsigned int)time(NULL));
    int nums[100000];
    for(int i=0;i<100000;i++){
        //nums[999-i]=i+1;
        int num = random(100000,1);
        nums[i]=num;
        //printf("%d,%d\n",i,num);
        // sleep(1);
    }
    QuickSort(nums,0,99999);
    //bubbleSort(nums,100000);
    for(int i=0;i<100000;i++){
        if(i%10==0)
            printf("\n");
        printf("%2d,",nums[i]);
    }
}