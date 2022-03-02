#include <iostream>


int length(char input[]){
    int count = 0;
    while(input[count] != '\0'){
        count++;
    }
    return count;
}

int main (){

    char array[100];
    std::cin.getline(array, 100);
    int start = 0;
    int end = length(array) - 1;
    while(start < end){
       char temp = array[end];
       array[end] = array[start];
       array[start] = temp;
       start++;
       end--;
    }
    std::cout << array;
}