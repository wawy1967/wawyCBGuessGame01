
    #include "GuessGame.h"
    #include <iostream>
    #include <ctime>
    GuessGame::GuessGame()
    {   //constructor
        //Set the vector size to SET_NUM
        guessSet.resize(SET_NUM);
        gameSet.resize(SET_NUM);
        resultSet.resize(SET_NUM);
    }
    void GuessGame::displayWelcomeMsg()
    {   //Welcome message
        cout << "Welcome to Guess Game\n";
        cout << "Prof WAWY\n";
        cout << "FKP, UMP\n";
    }
    void GuessGame::displayFailureMsg()
    {   //failure message
        cout << "You are not successful!\n";
        cout << "Please try again.\n";
    }
    void GuessGame::displaySuccessMsg()
    {   //Successful message
        cout << "You are successful!\n";
        cout << "After " << trial+1 << " trials\n";
        cout << "Please play again.\n";
    }

    void GuessGame::displayGuessResult()
    {
        cout << "\t\t\t\t\t" << resultSet[0] << " "
        << resultSet[1] << " " << resultSet[2] << " "
        << resultSet[3] << endl;
    }
    void GuessGame::setTrial(int a)
    {   //Initialize the trial
        trial = a;
    }
    int GuessGame::getTrial() const
    {   //get the current trial number
        return trial;
    }
    void GuessGame::increaseTrial()
    {   //increase trial by 1
        trial++;
    }

    int GuessGame::getMaxTrial() const
    {   //return the maximum loop to try
        return MAX_TRIAL;
    }


    void GuessGame::createGameSet()
    {
        //Use random number function
        //Set number between 0 to 9
        //Save to gameSet[]
        srand((unsigned)time(0));
        for (int i=0;i<SET_NUM;++i)
        {
            gameSet[i]= rand()% 9;
            //We display now for development purpose
            cout << gameSet[i] << "\t";
        }
        cout << endl;
    }
    void GuessGame::getUserGuess()
    {
        //get the user guess and save to guessSet[]
        cout << "Trial " << trial+1 << " Please enter your "
        << SET_NUM << " guess:\t";
        cin >> guessSet[0] >> guessSet[1]
        >> guessSet[2] >> guessSet[3];
    }
    bool GuessGame::getSuccess() const
    {
        //return the status of success
        return success;
    }


    void GuessGame::analyzeUserGuess()
    {   /*
        We save the result as:
        (1) wrong number and wrong place = x
        (2) right number but wrong place = *
        (3) right number and right place = $
        */
        //Step 1: Reset to wrong first;
        for (int i=0; i<SET_NUM; ++i)
            resultSet[i] = 'x';
        //Step 2: Check for the right guess
        //number regardless of position
        for (int i=0; i<SET_NUM; ++i)
        {
            for (int j=0; j<SET_NUM; ++j)
            {
                if (guessSet[i]== gameSet[j])
                    resultSet[i] = '*';
            }
        }


        //Step 3: Check for correct
        //guess number and position
        for (int i=0; i<SET_NUM; ++i)
        {
            if (gameSet[i] == guessSet[i])
                resultSet[i] = '$';
        }
        //Step 4: Check for success i.e.
        //all guesses are correct
        int numCorrect = 0;
        for (int i=0; i<SET_NUM; i++)
        {
            if (resultSet[i] == '$')
                numCorrect++;
        }
        if (numCorrect == SET_NUM)
            success = true;
    }

