#include <stdio.h>
#include <stdbool.h>

void triangle(int height){
    for(int i = 1; i <= height ; i++){
        for(int column = 0; column < i ; column++){
            printf("*");
        }
        printf("\n");
    }
}

void inverse_triangle(int height){
    for(int i = 1 ; i <= height ; i++){
        for(int column = 0; column <= height-i; column++){
            printf("*");
        }
        printf("\n");
    }
}

void pyramid(int height){
    for(int i = 1; i <= height ; i++){
        for(int space = 0; space <= height-i-1; space++){
            printf(" ");
        }
        for(int star = 0; star < i; star++){
            printf("* ");
        }
        printf("\n");
    }
}

void inverse_pyramid(int height){
    for(int i = 1; i <= height; i++){
        for(int space = 0; space < i; space++){
            printf(" ");
        }
        for(int star = 0; star <= height-i; star++){
            printf("* ");
        }
        printf("\n");
    }
}

bool IsIn(int FunctionIndex , int* IndexList){
    for(int i = 0; i < 5; i++){
            if(IndexList[i] == FunctionIndex){
                return true;
            }
    }
    return false;
}

int main(){
//use one of the function from above
    void (*functions[])(int) = {triangle,inverse_triangle,pyramid,inverse_pyramid};
    
    int IndexList[] = {1,2,3,4};
    int InputHeight = 0;
    int FunctionIndex;

    while(IsIn(FunctionIndex,IndexList) == false){
        printf("Triangle/Inverser Triangle/Pyramid/Inverser Pyramid(Enter 1 / 2 / 3 / 4 ): ");
        scanf("%d",&FunctionIndex);
        
        if (IsIn(FunctionIndex,IndexList) == false){
            printf("Error: Unrecognized Value.\n");
	    while (getchar() != '\n');
	    FunctionIndex = 0;
        }
    }
    while(InputHeight == 0){
	printf("Enter height: ");
	scanf("%d",&InputHeight);
	if (!(InputHeight > 0) | (InputHeight > 43)){
	    if (InputHeight > 43){
		printf("Input number too high.\n");
	    }
	    else {
	    printf("Invalid input.\n");
	    while (getchar() != '\n');
	    }
	    InputHeight = 0;
	}
    }
    functions[FunctionIndex-1](InputHeight);   
    
    return 0;
}
