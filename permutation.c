#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int swap(int *x, int *y){
    int temp=*y;
    *y=*x;
    *x=temp;
}

int first_step(int arr[],int length){
    int exceptions=0;
    
    for (int x=0;x<length;x++){
        if(arr[x]>arr[x+1]){
            exceptions++;
        }
    }
    
    if(exceptions==length){
        return -1;
    }
    
    int exception_length=length-exceptions;
    int *indexes = (int*)malloc(length * sizeof(int));
    int greatest_index=0;
    int j=0;
    
    for(int i=0;i<length;i++){
        if(arr[i]<arr[i+1]){
            indexes[j]=i;
            j++;
        }
    }
    
    for(int i=0;i<exception_length;i++){
        if(indexes[i]>indexes[i+1]){
            greatest_index=indexes[i];
        }
    }
    free(indexes);
    return greatest_index;
}

int display_sequence(int arr[], int length){
    for(int i=0;i<length;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[]={1,2,3,4};
    int length=sizeof(arr)/sizeof(arr[0]);
    int copy[length];
    int permutation=0;
    
    for(int i=0;i<length;i++){
        copy[i]=arr[i];
    }
    
    do{
        permutation++;
        int pivot=first_step(arr,length);
        
        if (pivot==-1){
            for(int i=0;i<length;i++){
                for(int j=i+1;j<length;j++){
                    if(arr[i]>arr[j]){
                        swap(&arr[j],&arr[i]);
                    }
                }
            }
            display_sequence(arr,length);
            continue;
        }
        
        // printf("%d",arr[pivot]);
        // Second step
        int greater_than_pivot=0;
        for(int i=length-1;i>-1;i--){
            if(arr[i]>arr[pivot]){
                greater_than_pivot=i;
                break;
            }
        }
        // Now we need to swap them
        swap(&arr[pivot],&arr[greater_than_pivot]);
        
        // printf("%d\n",arr[3]);
        
        // Third Step
        // printf("%d\n",pivot+1);
        if(pivot+1!=length-1){
            for(int i=pivot+1;i<length;i++){
                for(int j=i+1;j<length;j++){
                    swap(&arr[i],&arr[j]);
                }
            }
        }
        display_sequence(arr,length);
    }while(memcmp(arr,copy,sizeof(copy))!=0);
    printf("\n\nTotal Permutation: %d",permutation);
}
