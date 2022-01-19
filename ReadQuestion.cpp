#include <iostream>
#include <fstream>
#include <string>

#include "ReadQuestion.h"


using namespace std;


string quest_arr_2D[62][62];
int num_of_quests[62];
int questionSize = 0;
//  Test for getting questions from text file.
string testSentence = "What time is read on a clock on the wall ";
// don't forget to look this part.

void readFromQuestion(){

    string word;
    string tempSentence = "";
    string reCreateLastWord = "";

    int questionNumber = 0;
    int questionWord = 0;
    int wordCounter = 0;


    ifstream question("questions.txt");
    //  ----------------------------------------------------------------------------------------------------------------------
    //                              Initializes "quest_add_2D" and "num_of_quests" arrays
    //  ----------------------------------------------------------------------------------------------------------------------
    for (int i = 0; i < 62; i++){

        num_of_quests[i] = 0;
        
        for (int j = 0; j < 62; j++){

            quest_arr_2D[i][j] = "0";

        }

    }
    //  ----------------------------------------------------------------------------------------------------------------------
    //              Reads questions from question.txt file and stores these questions to array word by word. 
    //  ----------------------------------------------------------------------------------------------------------------------
    if(question.is_open()){

        while(question >> word){

            wordCounter++;
            
            if(word.back() != '?'){

                quest_arr_2D[questionNumber][questionWord] = word;
                questionWord++;
                tempSentence += word + " ";

            }
            else{

                word.pop_back();
                quest_arr_2D[questionNumber][questionWord] = word;
                num_of_quests[questionNumber] = wordCounter;

                questionWord++;
                tempSentence += word + " ";
                tempSentence = "";
                questionNumber++;
                questionWord = 0;
                wordCounter = 0;

                questionSize++;

            }

        }

    }

    question.close();

}
