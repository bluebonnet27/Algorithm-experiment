#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>


// Swap the district
void Swap(int a,int b){
    int temp=a;
    a=b;
    b=temp;
}


int Partition(int nums[],int left,int right,int x){
    int i=left,j=right+1;
    //int x=nums[left];
    while (1)
    {
        while (nums[++i]<x&&i<right);
        while (nums[--j]>x);
        if(i>=j)
            break;
        Swap(nums[i],nums[j]);
    }
    nums[left]=nums[j];
    nums[j]=x;
    return j;
}

int random(int max,int min){
    int origin = rand();
    int random_num = origin%(max-min+1)+min;
    return random_num;
}

// int RandomizedPartition(int a[],int p,int r){
//     srand((unsigned int)time(NULL));
//     int i=random(p,r);
//     Swap(a[i],a[p]);
//     return Partition(a,p,r);
// }

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

int Select(int nums[],int left,int right,int target){
    //judge by 75
    if(right-left<75){
        QuickSort(nums,left,right);
        return nums[left+target-1];
    }
    //NOT 75
    for(int i=0;i<=(right-left-4)/5;i++){
        //right-left-4 是一个划分组号的公式。比如组内有34个元素，
        //i的值就是(33-0-4)/5=29/5=5
        //找中位数的中位数，r-p-4即上面所说的n-5
        int s=left+5*i,t=s+4;
		for(int j=0; j<3; j++) //冒泡排序，从后开始排，结果使得后三个数是排好顺序的（递增）
		{
			for(int n=s; n<t-j; n++)
			{
				if(nums[n]>nums[n+1])
                Swap(nums[n],nums[n-1]);
			}
		}
        Swap(nums[left+1],nums[s+2]);
    }

    int x=Select(nums,left,left+(right-left-4)/5,(right-left-4)/10);
    int i=Partition(nums,left,right,x),j=i-left+1;
    if(target<=j){
        // printf("target<=j,j=%d\n",j);
        // printf("##left=%d\n",left);
        // printf("##right=%d\n",right);
        return Select(nums,left,i,target);
    }
    else
    {
        // printf("target>j,j=%d\n",j);
        // printf("##left=%d\n",left);
        // printf("##right=%d\n",right);
        return Select(nums,i+1,right,target-j);
    }
    
}

int main(void){
    int target=4;

    //int nums[100]={3,1,7,6,5,9,8,2,0,4,13,11,17,16,15,19,18,12,10,14,23,21,27,26,25,29,28,22,20,24,33,31,37,36,35,39,38,32,30,34,43,41,47,46,45,49,48,42,40,44,53,51,57,56,55,59,58,52,50,54,63,61,67,66,65,69,68,62,60,64,73,71,77,76,75,79,78,72,70,74,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100};
    int max_num=100;
    int nums[max_num];
    for(int i=0;i<max_num;i++){        
        nums[i]=i+1;        
        // printf("%2d,",nums[i]);
        // if(nums[i]%10==0) printf("\n");
    }

    //计时
    clock_t stime = clock();
    if(target>max_num||target<=0){
        printf("越界了！");
        printf("越界结果：第%d大的数是%d\n",target,Select(nums,0,max_num,target));
    }else
    {
        printf("第%d大的数是%d\n",target,Select(nums,0,max_num,target));
    }
    clock_t etime = clock();
    printf("time is %d ms",etime-stime);
    
    return 0;
}