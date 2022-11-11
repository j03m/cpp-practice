#include <cstdio>
#define MACRO1(value) \
    printf("the value is: %s\n", value); \
    printf("the address is: %ld\n", (intptr_t) value);

static const char theString[] = "hello world";
static const char* thePointer = "hello world";
extern const char theExtern[];
#define MACRO2 \
printf("the string:\n") ;              \
MACRO1(theString);

#define MACRO3 \
printf("the pointer:\n");                            \
MACRO1(thePointer);

#define MACRO4 \
printf("the extern:\n") ;                           \
MACRO1(theExtern);

#define MACRO5 \
printf("the literal:\n") ;                           \
MACRO1("hello world");

void printsomething();