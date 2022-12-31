#include <stdio.h>
#include <stdlib.h>
#define FIFTY 5

void shift_element(int *arr, int i){
int counter = 0;
int *lastE = arr+i;
int *Beforelast = lastE -1;

while(counter != i){
    *lastE = *Beforelast;
    lastE--;
    Beforelast--;
    counter++;
}
}

void insertion_sort(int* arr , int len) {
    int *ptr1 = arr;
    int *ptr2 = (arr+1);
    int save = 0;
    for (int i = 0; i < FIFTY; i++)
    {
        int counter = 0;
        if(*ptr2 < *ptr1){
            while(*ptr2 < *ptr1){
                counter++;
                ptr2--;
            }
            save = *(ptr2+counter);
            shift_element(ptr1,counter);
            *ptr1 = save;
        }
        ptr1++;
        ptr2++;
    }
    
}
int nums[FIFTY];
void getNumbers(){
for (int i = 0; i < FIFTY; i++)
{
    scanf("%d",nums+i);
}
return;
}

int main(){
int arr[5] = {7,5,3,2,1};
insertion_sort(arr,FIFTY);
for (int i = 0; i < FIFTY; i++)
{
   printf("%d",arr[i]);
}

return 0;
}