//
// Created by gaosiqi on 2025/2/19.
//
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define LEN 21
bool is_palindrome(char string[]); //可以没有长度参数
int main() {
    char string[LEN] = "";
    printf("Input a string containing at most 20 characters.\n");
    scanf("%20s", string);
    //TODO:to test the palindrome
    bool Ispalindrome = is_palindrome(string);
    if (Ispalindrome) {
        printf("The string is palindrome.\n");
    } else {
        printf("The string is not palindrome.\n");
    }
    return 0;
}

bool is_palindrome(char string[]) {
    int len = strlen(string);
    /*int len = 0;
    while (string[len] != '\0') {//'\0'is the end of string.
        len++;
    }
    */
    //TODO:the while version
    /*int i = 0, j = len - 1;
    while(i < j) {
        if(string[i] != string[j]) {
            is_palindrome = false;
            break;
        }
        i++;
        j--;
    }*/
    //not for(int i = 0, int j = len - 1; i < len / 2; i++)
    //',':comma operator
    //TODO:the for version
    for (int i = 0, j = len - 1; i < len / 2; i++, j--) {
        if (string[i] != string[j]) {
            return false;
            break;
        }
    }
    return true;
}
