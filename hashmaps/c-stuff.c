#include "stdio.h"
int main(){
    static char classname[32] = "other";
    //snprintf(classname, sizeof classname, "%s", "other");
   // classname = "other";
    printf("hi %s", classname);
}