#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

#include <vector>

//find all positive integers x, y such that
//a^x = y^b + c
//10^x = y^17 + 1107



int main(){
    unsigned int left_remainder, right_remainder, x, y, a, b, c;
    unsigned long long int test_range;
    bool if_same_remainder = 0;
    printf("please enter the positive integers a, b, and c to find if there's positive integers x, y such that\na^x = y^b + c\n");
   
    printf("please enter a\n");
    scanf("%u",&a);
    printf("please enter b\n");
    scanf("%u",&b);
    printf("please enter c\n");
    scanf("%u",&c);

    printf("please enter the number of integers that you wanna test\n");
    scanf("%llu",&test_range);

    for(int i = 2; i <= test_range; i++){

        std::vector<unsigned int> left_remainder_list(i);
    
        x = 1;
        left_remainder = a % i;
        left_remainder_list[x-1] = left_remainder;

        for(x = 2; x <= i; x++){
            left_remainder = (left_remainder * a) % i;
            left_remainder_list[x-1] = left_remainder;

            if(left_remainder == 0 || left_remainder_list[x-2] == left_remainder_list[x-1]){
                x++;
                for(; x <= i; x++){
                    left_remainder_list[x-1] = left_remainder_list[x-2];
                }
                break;
            }
        }



        y = 1;

        do{
            right_remainder = y % i;
            for(unsigned int j = 2; j <= b; j++){
                right_remainder = (right_remainder*y)%i;
                if(right_remainder == 0)
                    break;
            }
            right_remainder = ((right_remainder + c) % i);


            for(x = 1; x <= i; x++){
                if_same_remainder = (right_remainder == left_remainder_list[x-1]);
                if(if_same_remainder){
                    break;
                }
            }

            y++;
        }while((y <= i) && !if_same_remainder);

        if(!if_same_remainder){
            printf("no same remainder of %u\n", i);
            printf("no such integers x and y\n");
            system("pause");
            return 0;
        }

    }
    printf("test inconclusive\n");
    system("pause");
    return 0;

}
