
    #ifndef GUESSGAME_H
    #define GUESSGAME_H
    #include <vector>
    using namespace std;
    class GuessGame
    {
        public:
            GuessGame();
            void displayWelcomeMsg();
            void displaySuccessMsg();
            void displayFailureMsg();
            void displayGuessResult();
            void setTrial(int);
            int getTrial() const;
            void increaseTrial();
            int getMaxTrial() const;
            void createGameSet();
            void getUserGuess();
            void analyzeUserGuess();
            bool getSuccess() const;
        private:
            int trial = 0;
            const int MAX_TRIAL = 10;
            const int SET_NUM = 4;
            bool success = false;
            vector<int> gameSet;
            vector<int> guessSet;
            vector<char> resultSet;
            void setUserGuess(vector<int>);
    };
    #endif // GUESSGAME_H
