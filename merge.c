#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void insertsort(int* array, int count)
{
    int* tmp = (int*)malloc(count * sizeof(int));
    int i = 0,j = 0;
    tmp[0] = array[0];
    for ( i = 1; i< count; i++ ) {
        for( j = 0; j< i; j++) {
           if(array[i] < tmp[j]) {
               break;
           } 
        }
        memmove(&tmp[j+1], &tmp[j], sizeof(int)*(i-j));
        tmp[j] = array[i];
    }

    memcpy(array, tmp, sizeof(int)*count);
    free(tmp);
}

void merge(int* array, int start, int mid, int end)
{
    int i = 0;
    int l = 0, r = 0;
    int* left = (int*)malloc(sizeof(int)*(mid-start + 1));
    int* right = (int*)malloc(sizeof(int)*(end-mid));

    memcpy(left, &array[start],sizeof(int)*(mid-start+1));
    memcpy(right, &array[mid+1],sizeof(int)*(end-mid));
    
    for(i=0; i < (end-start + 1); i++){
        if(left[l] < right[r]) {
            array[start+i] = left[l];
            l++;
        }
        else {
            array[start+i]=right[r];
            r++;
        }
        if(l == (mid-start+1)) {
            memcpy(&array[start+i+1],&right[r], sizeof(int)*(end - mid -r));
            break;
        }else if(r == (end-mid)) {
            memcpy(&array[start+i+1], &left[l], sizeof(int)*(mid - start -l +1));
            break;
        }
    }
    free(left);
    free(right);
}
void mergesort(int* array, int start, int end)
{
    int mid;
    if (start >= end)
        return;
    mid = (end + start)/2;
    mergesort(array, start, mid);
    mergesort(array, mid+1, end);
    merge(array,start, mid, end);    
}

void bubble(int* array, int count)
{
    int tmp;
    int i,j,k;
    for( i = 0; i < count; i++){
        for(j=0; j < count-i-1; j++) {
            if ( array[j] > array[j+1]) {
                tmp = array[j];
                array[j] = array[j+1];
                array[j+1]=tmp;
            } 
        }
    }
}


int main()
{
    int array[] = {1,3,7, 5, 5, 6, 9,7,0};
    int count = sizeof(array)/sizeof(array[0]);
    //insertsort(array, count);
    //mergesort(array, 0, count);
    bubble(array,count);
    printf("array:");
    while(count--)
        printf(" %d", array[count]);
    printf("\n");
    return 0;
}
