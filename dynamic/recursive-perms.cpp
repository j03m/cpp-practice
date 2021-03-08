#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

unordered_set<string> getPermutations(const string& inputString){
    unordered_set<string> permutations;
    cout << "input: " << inputString << "\n";
    if (inputString.length() <= 1){
        //when our algo break down strings, eventually we get to 1 length
        //which is a valid permutation so return it
        permutations.insert(inputString);
        return permutations;
    }

    //chunk everything but last and last, we'll permute this char and this chunk
    string allCharsExceptLast = inputString.substr(0, inputString.length() -1);
    char lastChar = inputString[inputString.length() - 1];

    // recursive call: do this a gain for a chunk of string, here we build up a call stack pre loop of
    // cats
    //  cat
    //   ca
    //    c
    const auto permutationsOfAllCharsExceptLast = getPermutations(allCharsExceptLast);

    //create permutations for the chunk we have using the last character
    // cat
    //  tca
    //  cta
    cout << "permute: " << allCharsExceptLast << " and " << lastChar << "\n";
    for(const string& permutationOfAllCharsExceptLast : permutationsOfAllCharsExceptLast){
        cout << permutationOfAllCharsExceptLast << ": " << "\n";
        for (size_t position=0; position <= allCharsExceptLast.length(); ++position){
            string chunk = permutationOfAllCharsExceptLast.substr(0, position);
            string chunk2 = permutationOfAllCharsExceptLast.substr(position);
            string permutation = chunk
                + lastChar + chunk2;

            cout << chunk << " + " << lastChar << " + " << chunk2 << " = " << permutation << "\n";
            permutations.insert(permutation);
        }
    }

    return permutations;
}
//TODO AGAIN
int main(){
    getPermutations("cats");

}