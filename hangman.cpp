#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

#define MAX_ATTEMPTS 6

class HangmanGame{
    string currentWord;
    string secretWord;
    int attemptsLeft;
    vector<char>guessedLetters;

    string getRandomWord(){
        vector<string>words = {
        "abruptly", "absurd", "abyss", "affix", "askew", "avenue", "awkward", "axiom", "azure", 
        "bagpipes", "bandwagon", "banjo", "bayou", "beekeeper", "bikini", "blitz", "blizzard", 
        "boggle", "bookworm", "boxcar", "boxful", "buckaroo", "buffalo", "buffoon", "buxom", 
        "buzzard", "buzzing", "buzzwords", "caliph", "cobweb", "cockiness", "croquet", "crypt", 
        "curacao", "cycle", "daiquiri", "dirndl", "disavow", "dizzying", "duplex", "dwarves", 
        "embezzle", "equip", "espionage", "euouae", "exodus", "faking", "fishhook", "fixable", 
        "fjord", "flapjack", "flopping", "fluffiness", "flyby", "foxglove", "frazzled", "frizzled", 
        "fuchsia", "funny", "gabby", "galaxy", "galvanize", "gazebo", "giaour", "gizmo", "glowworm", 
        "glyph", "gnarly", "gnostic", "gossip", "grogginess", "haiku", "haphazard", "hyphen", 
        "iatrogenic", "icebox", "injury", "ivory", "ivy", "jackpot", "jaundice", "jawbreaker", 
        "jaywalk", "jazziest", "jazzy", "jelly", "jigsaw", "jinx", "jiujitsu", "jockey", "jogging", 
        "joking", "jovial", "joyful", "juicy", "jukebox", "jumbo", "kayak", "kazoo", "keyhole", 
        "khaki", "kilobyte", "kiosk", "kitsch", "kiwifruit", "klutz", "knapsack", "larynx", "lengths", 
        "lucky", "luxury", "lymph", "marquis", "matrix", "megahertz", "microwave", "mnemonic", 
        "mystify", "naphtha", "nightclub", "nowadays", "numbskull", "nymph", "onyx", "ovary", 
        "oxidize", "oxygen", "pajama", "peekaboo", "phlegm", "pixel", "pizazz", "pneumonia", 
        "polka", "pshaw", "psyche", "puppy", "puzzling", "quartz", "queue", "quips", "quixotic", 
        "quiz", "quizzes", "quorum", "razzmatazz", "rhubarb", "rhythm", "rickshaw", "schnapps", 
        "scratch", "shiv", "snazzy", "sphinx", "spritz", "squawk", "staff", "strength", "strengths", 
        "stretch", "stronghold", "stymied", "subway", "swivel", "syndrome", "thriftless", 
        "thumbscrew", "topaz", "transcript", "transgress", "transplant", "triphthong", "twelfth", 
        "twelfths", "unknown", "unworthy", "unzip", "uptown", "vaporize", "vixen", "vodka", 
        "voodoo", "vortex", "voyeurism", "walkway", "waltz", "wave", "wavy", "waxy", "wellspring", 
        "wheezy", "whiskey", "whizzing", "whomever", "wimpy", "witchcraft", "wizard", "woozy", 
        "wristwatch", "wyvern", "xylophone", "yachtsman", "yippee", "yoked", "youthful", "yummy", 
        "zephyr", "zigzag", "zigzagging", "zilch", "zipper", "zodiac", "zombie"
    };
        srand(time(0));
        int index = rand() % words.size();
        return words[index];
    }
    
    void displayInfo(){
        cout<<"Current Word : "<<currentWord<<endl;
        cout<<"Attemps Left : "<<attemptsLeft<<endl;
        cout<<"Guessed Letters : ";
        for(char ch : guessedLetters){
            cout<<ch<<" ";
        }
        cout<<endl;
    }

    bool validGuess(char guess){
        if(guess >= 'A' && guess <= 'Z' || guess >= 'a' && guess <= 'z'){
            return true;
        }
        return false;
    }

    bool alreadyGuessed(char letter){
        return find(guessedLetters.begin(),guessedLetters.end(),letter) != guessedLetters.end();
    }

    bool checkGuess(char guess){
        bool correctGuess = false;
        for(int i=0;i<secretWord.length();i++){
            if(secretWord[i] == guess){
                //update current word
                currentWord[i] = guess;
                correctGuess = true;
            }
        }
        //update in guessedLetters
        guessedLetters.push_back(guess);
        return correctGuess;
    }

    void drawHangman(int attemptsLeft){
        if (attemptsLeft == 5) {
            cout << "   _____" << endl;
            cout << "  |     |" << endl;
            cout << "  |     O" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
        }
        else if (attemptsLeft == 4) {
            cout << "   _____" << endl;
            cout << "  |     |" << endl;
            cout << "  |     O" << endl;
            cout << "  |     |" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
        }
        else if (attemptsLeft == 3) {
            cout << "   _____" << endl;
            cout << "  |     |" << endl;
            cout << "  |     O" << endl;
            cout << "  |    /|" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
        }
        else if (attemptsLeft == 2) {
            cout << "   _____" << endl;
            cout << "  |     |" << endl;
            cout << "  |     O" << endl;
            cout << "  |    /|\\" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
        }
        else if (attemptsLeft == 1) {
            cout << "   _____" << endl;
            cout << "  |     |" << endl;
            cout << "  |     O" << endl;
            cout << "  |    /|\\" << endl;
            cout << "  |    /" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
        }
        else if (attemptsLeft == 0) {
            cout << "   _____" << endl;
            cout << "  |     |" << endl;
            cout << "  |     O" << endl;
            cout << "  |    /|\\" << endl;
            cout << "  |    / \\" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
        }
    }

    public:
        //constructor
        HangmanGame(){
            secretWord = getRandomWord();
            currentWord = string(secretWord.length(),'_');
            attemptsLeft = MAX_ATTEMPTS;
        }
        void greet(){
            cout<<"================="<<endl;
            cout<<"Hangman: The Game"<<endl;
            cout<<"================="<<endl;
            cout<<"Instructions : Save your friend From being hanged by guesing the correct letter in codeword"<<endl;
        }
        void rules(){
            cout <<"Here are the rules of playing Hangman: The Game"<<endl;
            cout <<"==============================================="<<endl;
            cout <<"1. The player needs to guess the word which is picked randomly by the computer one letter at a time."<<endl;
            cout <<"2. If the letter guessed is correct, then the computer will reveal the position of that letter on the word."<<endl;
            cout <<"3. If the letter guessed is incorrect then, the number of attempts will be decreased."<<endl;
            cout <<"4. The Player will win if he writes the entire word correctly within the given number of attempts."<<endl;
            cout <<"5. If the player is unable to guess the word, he will lose."<<endl;
            cout <<"You have 6 attemps after each miss a body part of hangman will get displayed."<<endl;
            cout <<"================================================"<<endl;
        }

        void play(){
            while(attemptsLeft > 0){
                //display the starting info
                displayInfo();
                char guess;
                cout<<"Please guess a word : ";
                cin>>guess;
                cout<<endl;

                if(validGuess(guess)){
                    if(isalpha(guess)){
                        tolower(guess);
                    }
                    if(alreadyGuessed(guess)){
                        cout<<"You have already guessed that letter, please guess another alphabet"<<endl;
                    }
                    else{
                        //in this we check guess if correct update in currentword
                        //also updated guessedLetters list
                        bool correctGuess = checkGuess(guess);
                        //now check if the word is correct or not
                        if(correctGuess){
                            //if correct check we are able to guess the secretWord
                            if(currentWord == secretWord){
                                cout<<"Congratulations! you are a Genius. The secretWord is : " << secretWord <<endl;
                                return;
                            }
                            else{
                                cout<<"Wooho ! you are on the right path of win"<<endl;
                            }
                        }
                        else{
                            //if guess is wrong draw a part of the hangman and decrement attemps
                            cout<<"Oops! Incorrect Guess"<<endl;
                            attemptsLeft--;
                            drawHangman(attemptsLeft);
                        }
                    }
                }
                else{
                    cout<<"Guess should be an alphabet, please enter a valid character"<<endl;
                }
            }
            if(attemptsLeft == 0){
                displayInfo();
                cout<<"You've ran out of attempts, The word was : "<<secretWord<<endl;
            }
        }
};

int main(){
    HangmanGame game;
    game.greet();
    game.rules();
    game.play();
    return 0;
}