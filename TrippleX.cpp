#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty){
    std::cout << std::endl;
    std::cout << "The terminal flickers with a faint glow...\n";
    std::cout << "A set of instructions appears on screen...\n\n";
    std::cout << "Enter the correct code, security level: " << Difficulty;
}

bool PlayGame(int Difficulty){

    PrintIntroduction(Difficulty);

    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "\n- There are 3 numbers in the code\n";


    std::cout << "- The sum of the code is: " << CodeSum;
    
    
    std::cout << "\n- The product of the code is: " << CodeProduct;
    std::cout << std::endl;
    std::cout << std::endl;

    int PlayerGuessA, PlayerGuessB, PlayerGuessC;
    std::cin >> PlayerGuessA >> PlayerGuessB >> PlayerGuessC;
    
    int PlayerGuessSum = PlayerGuessA + PlayerGuessB + PlayerGuessC;
    int PlayerGuessProduct = PlayerGuessA * PlayerGuessB * PlayerGuessC;

    if(PlayerGuessSum == CodeSum && PlayerGuessProduct == CodeProduct){
        std::cout << "\nCorrect entries, moving to next security level...\n\n";
        return true;
    }
    else{
        std::cout << "\nIncorrect entries, try again!\n\n";
        return false;
    }
}

int main(){
    srand(time(NULL));
    int LevelDifficulty = 1;
    int MaxDifficulty = 10;
    while(LevelDifficulty <= MaxDifficulty){

        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete){
            ++LevelDifficulty;
        }
        
    }
    std::cout << "\n Security bypassed, door is now open!\n";
    return 0;
}
