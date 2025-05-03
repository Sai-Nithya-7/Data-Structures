// Menu-driven program in C++ to check if a number is a palindrome, armstrong, or perfect numbers using DMA and pointers

#include<cstdio>
#include<cstdlib>
#include<cmath>

//Function prototypes
int palindrome(int *);
int armstrong(int *);
int perfect(int *);

int reverse(int *);

// Main function
int main() {
    int *num = (int *)malloc(sizeof(int));
    int *choice = (int *)malloc(sizeof(int));
    int *result = (int *)malloc(sizeof(int));
    
    while (true) {
        printf("\n1.Check if a number is a Palindrome \n2.Check if a number is an Armstrong Number \n3.Check if a number is a Perfect Number \n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", choice);
        
        if ((*choice) == 4) {
            printf("Exiting program...\n");
            break;
        }
        
        if ((*choice) == 1) {
            printf("Enter number to check: ");
            scanf("%d", num);
            *result = palindrome(num);
            if ((*result) == 0) {
                printf("The number %d is a palindrome\n", *num);
            } else {
                printf("The number %d is not a palindrome\n", *num);
            }
        } else if ((*choice) == 2) {
            printf("Enter number to check: ");
            scanf("%d", num);
            *result = armstrong(num);
            if ((*result) == 0) {
                printf("The number %d is an Armstrong Number\n", *num);
            } else {
                printf("The number %d is not an Armstrong Number\n", *num);
            }
        } else if ((*choice) == 3) {
            printf("Enter number to check: ");
            scanf("%d", num);
            *result = perfect(num);
            if ((*result) == 0) {
                printf("The number %d is a perfect number\n", *num);
            } else {
                printf("The number %d is not a perfect number\n", *num);
            }
        } else {
            printf("Enter a valid choice from 1-4 only\n");
        }
    }
    
    free(num);
    free(choice);
    free(result);
    
    return 0;
}

// Function to reverse a number
int reverse(int *temp) {
    int *rev = (int *)malloc(sizeof(int));
    *rev = 0;
    int num = *temp;
    while (num > 0) {
        *rev = (*rev) * 10 + (num % 10);
        num /= 10;
    }
    int result = *rev;
    free(rev);
    return result;
}

// Function to check if a number is a palindrome
int palindrome(int *num) {
    int reversed = reverse(num);
    return (*num == reversed) ? 0 : 1;
}

// Function to check if a is an Armstrong number
int armstrong(int *num) {
    int *sum = (int *)malloc(sizeof(int));
    *sum = 0;
    int *temp = (int *)malloc(sizeof(int));
    *temp = *num;
    int *n = (int *)malloc(sizeof(int));
    *n = 0;
    int t = *num;
    
    while (t > 0) {
        (*n)++;
        t /= 10;
    }
    
    while ((*temp) > 0) {
        int digit = (*temp) % 10;
        *sum += pow(digit, *n);
        *temp /= 10;
    }
    
    int result = (*sum == *num) ? 0 : 1;
    free(sum);
    free(temp);
    free(n);
    return result;
}

// Function to check if a number is a perfect number
int perfect(int *num) {
    int *sum = (int *)malloc(sizeof(int));
    *sum = 0;
    for (int i = 1; i < *num; i++) {
        if ((*num) % i == 0) {
            *sum += i;
        }
    }
    int result = (*sum == *num) ? 0 : 1;
    free(sum);
    return result;
}
