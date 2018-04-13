#include "..\include\GuessGame.h"
using namespace std;

int main()
{
    GuessGame game;
    game.setTrial(0);
    game.displayWelcomeMsg();
    game.createGameSet();
    while (game.getTrial()<game.getMaxTrial())
    {
        game.getUserGuess();
        game.analyzeUserGuess();
        game.displayGuessResult();
        if (game.getSuccess())
        {
            game.displaySuccessMsg();
            return 0;
        }
        else
            game.increaseTrial();
    }
    game.displayFailureMsg();
    return 0;
}
