#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    //code
    //allow watching in debuging
    setbuf(stdout, NULL);
    //int arr[]={1,2,4,5,4,2,1,3};
    int arr2[] = {7,8,7,1,2,9,2,1,9,9,9,10};

    int size=sizeof(arr2)/sizeof(arr2[0]);

    int count;
    int count_max=0;
    int place=0,steps;

    for(int i=1;i<size;i++){
        count=0;
        
        for(int j=1;j<=i;j++){
            
            if (arr2[i-j]!=arr2[i+j]){
                break;
            } 
            if (arr2[i-j]==arr2[i+j]){
                count++;
                
            }
            if (count>count_max){
                    count_max=count;
                    place=i;
                    steps=j;
            }
            
        }
    }
    if(count_max>0){

        for(int i=(place-steps);i<(place+steps+1);i++){
            printf("%d ",arr2[i]);
        }
    }

    return 0;
}