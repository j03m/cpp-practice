// const fisherYatesShuffle = (deck) => {
//     for (var i = deck.length - 1; i > 0; i--) {
//         const swapIndex = Math.floor(Math.random() * (i + 1))
//         console.log(`swapping: ${i} and ${swapIndex}`);
//         const currentCard = deck[i]
//         const cardToSwap = deck[swapIndex]
//         deck[i] = cardToSwap
//         deck[swapIndex] = currentCard
//     }
//     return deck
// }
//
//
// fisherYatesShuffle(['a', 'b', 'c', 'd'])


function findRotationPoint(words) {
    const firstWord = words[0];

    let floorIndex = 0;
    let ceilingIndex = words.length - 1;

    while (floorIndex < ceilingIndex) {


        // Guess a point halfway between floor and ceiling
        const guessIndex = Math.floor(floorIndex + ((ceilingIndex - floorIndex) / 2));
        console.log("pos: ", floorIndex, ", ", ceilingIndex, ", mid:", guessIndex);
        console.log("words: ", words[floorIndex], ", ", words[ceilingIndex], ", mid:", words[guessIndex]);

        // If guess comes after first word or is the first word
        if (words[guessIndex] >= firstWord) {
            // Go right
            floorIndex = guessIndex;
        } else {
            // Go left
            ceilingIndex = guessIndex;
        }

        // If floor and ceiling have converged
        if (floorIndex + 1 === ceilingIndex) {

            // Between floor and ceiling is where we flipped to the beginning
            // so ceiling is alphabetically first
            break;
        }
    }
    return ceilingIndex;
}
findRotationPoint([ "k","v","a","b","c","d","e","g","i" ]);