#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//^ nem hatványozás, XOR

void func(char* p, int x){
    printf("p is \"%s\" and x is %i\n",p,x);
}

int main(){
    
    printf("Hello World!\n");

    char* f = "Hello";
    char* s = "World";

    func("Belus",18);
}
