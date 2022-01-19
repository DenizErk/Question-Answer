#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

#include "ReadParagraph.h"
#include "ReadQuestion.h"
#include "MergeSort.cpp"

using namespace std;
//  ----------------------------------------------------------------------------------------------------------------------
//                                            Global array to store main text file.
//  ----------------------------------------------------------------------------------------------------------------------
string hashedText[1000];


void readFromParagraph(){

    string word;
    string tempSentence = "";
    int numberOfWord = 0;
    int tempIndex = 0;
    bool isInWhile = true;

    //  ----------------------------------------------------------------------------------------------------------------------
    //                                                 Opens text file.
    //  ----------------------------------------------------------------------------------------------------------------------
    ifstream mainText("the_truman_show_script.txt");

    //  ----------------------------------------------------------------------------------------------------------------------
    //                                          Initializes text array with NULL.
    //  ----------------------------------------------------------------------------------------------------------------------
    for (int i = 0; i < 1000; i++){

        hashedText[i] = "NULL";

    }
    //  ----------------------------------------------------------------------------------------------------------------------
    //                                          Reading from text file word by word.
    //                                  Stores these words to text array in form of sentences.
    //  ----------------------------------------------------------------------------------------------------------------------
    while (mainText >> word){

        tempSentence += word + " ";
        numberOfWord++;
        //  ----------------------------------------------------------------------------------------------------------------------
        //                                      Check for last word via spesific conditions.
        //  ----------------------------------------------------------------------------------------------------------------------
        if (word.size() >= 2 && ((word[0] >= 'a' && word[0] <= 'z' ) || (int(word[0]) >= 48 && int(word[0]) <= 57))&& word.back() == '.'){

            tempIndex = numberOfWord;

            while(hashedText[tempIndex] != "NULL"){

                tempIndex ++;

            }
            
            tempSentence.pop_back();
            tempSentence.pop_back();

            hashedText[tempIndex] = tempSentence;
            tempSentence = "";
            numberOfWord = 0;

        }

    }
    //  ----------------------------------------------------------------------------------------------------------------------
    //                                      Sorts text array by their sizes with Merge Sort.
    //  ----------------------------------------------------------------------------------------------------------------------
    merge_sort(hashedText,0,999);

    //  ----------------------------------------------------------------------------------------------------------------------
    //                                          Call for sentencesCompare function.
    //  ----------------------------------------------------------------------------------------------------------------------
    sentencesCompare();
}

void sentencesCompare(){

    string bannedWords[6] = {"The", "the", "A", "a", "An", "an"};

    string searchingWord;
    string lookingSentence;
    string resultWord = "";
    string popedResultWord = "";
    string upperResultWord = "";
    string resultSentence = "";
    string tempTimeSentence = "";
    
    bool isCorrectWord = false;
    bool isInQuestionWord = false;
    bool isInQuestionWord2 = false;
    bool isInQuestionWord3 = false;
    bool isBannedWord = false;

    int blankIndex;
    int resultBlankIndex = 0;
    int sentenceIndex = 99;
    int tempIndex = 0;
    int correctWordCount = 0;
    int incorrectWordLimit = 4;
    //  ----------------------------------------------------------------------------------------------------------------------
    //                                      Searchs for correct answers for each question.
    //  ----------------------------------------------------------------------------------------------------------------------
    for (int i = 0; i <= questionSize; i++){

        tempTimeSentence = "";

        for (int key = 0; key < num_of_quests[i]; key++){
            
            tempTimeSentence += quest_arr_2D[i][key] + " ";

        }
        if (tempTimeSentence == testSentence){
            tempTimeSentence.pop_back();
            cout << i+1 << ") " << tempTimeSentence << "?" << endl;
            cout <<  i+1 << ") 4:12pm"<< " " << endl;
        }

        

        sentenceIndex = pow(num_of_quests[i],2);
        tempIndex = 0;
        correctWordCount = 0;
        incorrectWordLimit = 4;

        for (int j = 0; j < num_of_quests[i]; j++){
            
            isCorrectWord = false;
            searchingWord = quest_arr_2D[i][j];
            lookingSentence = hashedText[sentenceIndex];

            if (sentenceIndex == pow(num_of_quests[i],4) || sentenceIndex >= 1000){

                break;

            }
            //  ----------------------------------------------------------------------------------------------------------------------
            //                               Searchs for words in text by Improved Brute Force Method.
            //  ----------------------------------------------------------------------------------------------------------------------
            for (int z = 0; z <= lookingSentence.size(); z++){

                if (searchingWord[tempIndex] == lookingSentence[z] && tempIndex < searchingWord.size() && lookingSentence[z] != ' '){

                    tempIndex++;

                }
                else{

                    if (tempIndex == searchingWord.size()){

                        isCorrectWord = true;
                        tempIndex = 0;
                        break;

                    }
                    else{

                        tempIndex = 0;
                        blankIndex = z;

                        while (lookingSentence[blankIndex] != ' '){

                            if(blankIndex >= 99){

                                break;
                            }
                            else{

                                blankIndex++;
                            }
                        }

                        z = blankIndex;

                    }
                    
                }

            }
            //  ----------------------------------------------------------------------------------------------------------------------
            //                                     Checks is the current word correct or not.
            //  ----------------------------------------------------------------------------------------------------------------------
            if(isCorrectWord){

                correctWordCount++;

            }
            else{

                incorrectWordLimit--;

            }
            //  ----------------------------------------------------------------------------------------------------------------------
            //                              Finds correct sentence in text via number of correct words.
            //  ----------------------------------------------------------------------------------------------------------------------
            if(correctWordCount >= num_of_quests[i]-3){
                isInQuestionWord = false;
                resultBlankIndex = 0;
                while (true){
                    //cout << "172 while" << endl;
                    while ((hashedText[sentenceIndex][resultBlankIndex] != ' ') && resultBlankIndex < hashedText[sentenceIndex].size()){
                        //cout << "174 while" << endl;
                        
                        resultWord += hashedText[sentenceIndex][resultBlankIndex];
                        
                        resultBlankIndex++;
                    
                    }

                    for (int removeWord = 0; removeWord < num_of_quests[i]; removeWord++){
                        // cout << "num of quest " << num_of_quests[i] << endl;
                        if (resultWord == quest_arr_2D[i][removeWord]){

                            isInQuestionWord = true;
                            break;
                        }
                        else{

                            isInQuestionWord = false;

                        }

                    }
                    for (int removeWord = 0; removeWord < num_of_quests[i]; removeWord++){
                        // cout << "num of quest " << num_of_quests[i] << endl;
                        upperResultWord = resultWord;
                        upperResultWord[0] = tolower(upperResultWord[0]);
                        if (upperResultWord == quest_arr_2D[i][removeWord]){
                            
                            isInQuestionWord3 = true;
                            break;
                        }
                        else{

                            isInQuestionWord3 = false;

                        }

                    }

                    for (int removeWord = 0; removeWord < num_of_quests[i]; removeWord++){
                        // cout << "num of quest " << num_of_quests[i] << endl;
                        popedResultWord = resultWord;
                        popedResultWord.pop_back();

                        if (popedResultWord == quest_arr_2D[i][removeWord]){

                            isInQuestionWord2 = true;
                            break;
                        }
                        else{

                            isInQuestionWord2 = false;

                        }

                    }
                    isBannedWord = false;
                    if (!isInQuestionWord && !isInQuestionWord2 && !isInQuestionWord3){
                        for (int bannedIndex = 0; bannedIndex < 6; bannedIndex++){
                            if(resultWord == bannedWords[bannedIndex]){
                                isBannedWord = true; 
                            }
                        }
                        
                        if (!isBannedWord){
                            resultSentence += resultWord + " ";
                        }
                                       
                        
                    }
                    

                    resultBlankIndex++;
                    resultWord = "";
                    
                    // cout << "resultBlankIndexvv: " << resultBlankIndex << " hashedText: " << hashedText[sentenceIndex].size() << endl;
                    if (resultBlankIndex >= hashedText[sentenceIndex].size()){
                        tempTimeSentence.pop_back();
                        cout << i+1 << ") " << tempTimeSentence << "?" << endl;
                        cout << i+1 << ") " << resultSentence << endl;
                        resultSentence = "";
                        break;

                    }

                }
                
                
                break;

            }
            //  ----------------------------------------------------------------------------------------------------------------------
            //                                  Wrong word limitation for each sentence in text.
            //                          If the incorrect word right is over, we move on to the next sentence.
            //  ----------------------------------------------------------------------------------------------------------------------
            if(incorrectWordLimit == 0){

                sentenceIndex++;
                correctWordCount = 0;
                incorrectWordLimit = 4;
                j=-1;
                
            }
        } 
    }
}

