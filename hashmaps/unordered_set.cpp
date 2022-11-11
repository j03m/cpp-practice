#include<unordered_set>
#include<string>
#include<iostream>
using namespace std;


int main() {
static const unordered_set<string> classes = {
"ibig",
"mlbig",
"tsbig",
"cmobig",
"pbig",
"tbig",
"nbig",
"aebig",
"mubig",
"jrun",
"msgbig",
"prsbig",
"msbig",
"btbig",
"hlpbig",
"htbig",
"gtbig",
"faxbig",
"pwrbig",
"fxsbig",
"futbig",
"chtbig",
"ioibig",
"tcpbig",
"ssebig",
"ombig",
"cppbig",
"jbig",
"jvabig",
"otbig",
"lmbig",
"ftbig",
"fxxbig",
"tcabig",
"gisbig",
"dembig",
"cabig",
"lpbig",
"fitbig",
"zsbig",
"jsnxt"};
cout << (classes.find("fsdfsdfoo") == classes.end()) << "\n";
cout << (classes.find("ibig") == classes.end()) << "\n";
}
