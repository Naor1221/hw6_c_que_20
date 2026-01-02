#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    //code
    //allow watching in debuging
    setbuf(stdout, NULL);
    //int arr[]={1,2,4,5,4,2,1,3};
    //int arr[] = {1, 2, 3, 2, 1};
    //int arr[] = {4, 7, 7, 4};bug
    //int arr[] = {9, 1, 2, 3, 2, 1, 8};
    //int arr[] = {5, 8, 6, 6, 8, 3};
    //int arr[] = {1, 2, 3, 2, 1, 9, 4, 4, 7};
    //int arr[] = {1, 1, 2, 3, 3, 2, 4, 4};
    //int arr[] = {1, 2, 3, 4, 5, 6};
    int arr[] = {9, 8, 7, 6, 7, 8, 9};

    //int arr[] = {7,8,7,1,2,2,1,9,9,9,10};
    //int arr[] = {1,2,1,3,4,4,3,5,6,7,6,5};


    int size=sizeof(arr)/sizeof(arr[0]);
    
    int len_max=0;
    int place=0,steps,len_even,len_odd;
    int even=0;
    for(int i=1;i<size;i++){
        len_even=0;
        len_odd=1;
        for(int j=1;j<=i;j++){
            //it should be added condition that 
            if( (arr[i-j]!=arr[i+j]) && (arr[i]!=arr[i+1]) ){
                break;
            } 
            if( (arr[i-j]==arr[i+j]) || ((arr[i-(len_even/2)])==arr[i+(len_even/2)+1]) ){
                // we can set even_count to work only
                //for even palindroms
                if ((arr[i-j]==arr[i+j])){
                    len_odd+=2;
                }
                else if(!(arr[i-j]==arr[i+j])){
                    len_even+=2;
                }
                
            }
            if ((len_odd>len_max) || (len_even)>len_max){
                if(!(arr[i-j]==arr[i+j])){
                    even=1;
                    len_max=len_even;
                }
                else if((arr[i-j]==arr[i+j])){
                    even=0;
                    len_max=len_odd;
                }
                //count_max=count;
                place=i;
                steps=j;
            }
        }
    }
    if(len_max>0){
        int i=(place-steps);
        if(even){   
            i++;
        }
        //correct way to start a loop from i
        // that is setted before the loop.
        
        
        //this will work, but may cause problams. 
        /*for(i;i<(place+steps+1);i++){
            printf("%d ",arr[i]);
        }*/

        //this the right one!        
        for(;i<(place+steps+1);i++){
            printf("%d ",arr[i]);
        }
        exit(EXIT_SUCCESS);
    }
    printf("%s\n","No palindrom found");
    return 0;
}