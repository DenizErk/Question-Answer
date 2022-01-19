#include <iostream>
#include <chrono>

#include "ReadQuestion.cpp"
#include "ReadParagraph.cpp"

int main() {
    
    auto start = chrono::steady_clock::now();

    //  ----------------------------------------------------------------------------------------------------------------------
    //                      First reads questions from txt file then searchs answer for each question.
    //  ----------------------------------------------------------------------------------------------------------------------
    readFromQuestion();
    readFromParagraph();

    auto end = chrono::steady_clock::now();

    cout << chrono::duration_cast<chrono::microseconds>(end - start).count()
        << " microseconds" << endl;

    return 0;
}
