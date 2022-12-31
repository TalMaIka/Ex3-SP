#include <stdio.h>
#include <stdlib.h>

void shift_element(int* arr, int i){
    int counter = 0;
    int temp1  = 0;
    int temp2  = 0;
    while(counter<i){
        int temp1 = *(arr+counter);
        int temp2 = *(arr+counter+1);
        *(arr+1+counter) = *(arr+counter);
        *(arr+1+counter) = *(arr+counter);
        counter++;
    }
}

int main(){
int a[11] = {1,2,3,4,6,5,7,8,9,10};
shift_element(a,2);
for (int i = 0; i < 11; i++)
{
    printf("%d\n",a[i]);
}
}