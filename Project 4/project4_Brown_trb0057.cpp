//Thomas Brown trb0057 /home/u1/trb0057/comp/project4_Brown_trb0057.cpp
//How to compile: Compile in linux terminal: gcc project4_Brown_trb0057.cpp -DUNIT_TESTING -lstdc++
//gcc project4_Brown_trb0057.cpp -DUNIT_TESTING -lstdc++
//gcc project4_Brown_trb0057.cpp -lstdc++
//HAVE TO INCLUDE  -lstdc++ in order to compile

#include <iostream>
#include <stdexcept>
#include <string>
#include <assert.h>
using namespace std;

struct triviaNode {
    string question;
    string answer;
    int points;
    triviaNode* next;
};

void InsertNode(triviaNode*& head, int index, string q, string a, int p);
int quiz(triviaNode* head, int index);
int unitTestQuiz(triviaNode* head, int index, string answer);

#ifdef UNIT_TESTING
void runUnitTests() {
    cout << "***This is a debugging version ***" << endl;
    //Unit test 1
    cout << "Unit Test Case 1: Ask no question. The program should give a warning message." << endl;
    try {
        quiz(NULL, 0);
        assert(false && "Exception not thrown");
    } catch (const invalid_argument& x) {
        assert(string(x.what()) == "Warning - the number of trivia to be asked must equal to or be larger than 1.");
        cout << "Case 1 Passed" << endl << endl;
    }
    //Unit test 2.1
    cout << "Unit Test Case 2.1: Ask 1 question in the linked list. The tester enters an incorrect answer." << endl;
    cout << "Question: What is 2+2?" << endl;
    cout << "Answer: 5" << endl;
    triviaNode* headCaseTwo = NULL;
    InsertNode(headCaseTwo, 0, "What is 2+2?", "4", 100);
    int caseTwoPoints = unitTestQuiz(headCaseTwo, 1, "5");
    assert(caseTwoPoints == 0);
    cout << "Case 2.1 passed" << endl << endl;
    //Unit test 2.2
    cout << "Unit Test Case 2.2: Ask 1 question in the linked list. The tester enters a correct answer." << endl;
    cout << "Question: What is 1+3?" << endl;
    cout << "Answer: 4" << endl;
    triviaNode* headCaseTwoPointTwo = NULL;
    InsertNode(headCaseTwoPointTwo, 0, "What is 1+3?", "4", 100);
    int caseTwoPointTwoPoints = unitTestQuiz(headCaseTwo, 1, "4");
    assert(caseTwoPointTwoPoints == 100);
    cout << "Case 2.2 passed" << endl << endl;
    //Unit test 3
    cout << "Unit Test Case 3: Ask all the questions of the last trivia in the linked list." << endl;
    cout << "Question: What is 2+2?";
    cout << "Answer: 4" << endl;
    int caseThreeOnePoints = unitTestQuiz(headCaseTwo, 1, "4");
    cout << "Question: What is 1+3?" << endl;
    cout << "Answer: 4" << endl;
    int caseThreeTwoPoints = unitTestQuiz(headCaseTwoPointTwo, 1, "4");
    assert(caseThreeOnePoints + caseThreeTwoPoints == 200);
    cout << "Case 3 passed" << endl << endl;
    cout << "Unit Test Case 4: Ask 5 questions in the linked list." << endl;
    int caseFourPoints = unitTestQuiz(headCaseTwo, 5, "4");
    assert(caseFourPoints == -1);
    cout << "Case 4 passed" << endl << endl;
    cout << "*** End of the Debugging Version ***" << endl;
}
#endif


void InsertNode(triviaNode*& head, int index, string q, string a, int p) {
    if (index < 0)
        return;
    int currIndex = 1;
    triviaNode* current = head;
    while (current && index > currIndex) {
        current = current -> next;
        currIndex++;
    }
    if (index > 0 && current == NULL)
        return;
    triviaNode* newNode = new triviaNode;
    newNode -> question = q;
    newNode -> answer = a;
    newNode -> points = p;
    if (index == 0) {
        newNode->next = head;
        head = newNode;
    }
    else {
        newNode -> next = current -> next;
        current -> next = newNode;
    }
}

int quiz(triviaNode* head, int index) {
    if(head == NULL)
        throw invalid_argument("Warning - the number of trivia to be asked must equal to or be larger than 1.");
    triviaNode* current = head;
    string answer;
    int totalPoints = 0;
    for(int x = 0 ; x < index; x++) {
        cout << "Question: " << current -> question << endl;
        cout << "Answer : ";
        cin >> answer;
        if(answer == current -> answer) {
            cout << "Your answer is correct. You recieve " << current -> points << " points." << endl;
            totalPoints += current -> points;
        }
        else
            cout << "Your answer is incorrect. You recieve 0 points." << endl;
        cout << "Your total points: " << totalPoints << endl << endl;
        current = current -> next;
    }
    cout << "*** Thank you for playing the trivia quiz game. Goodbye! ***" << endl;
    cout << "Your total points: " << totalPoints << endl << endl;
    return totalPoints;
}

int unitTestQuiz(triviaNode* head, int index, string answer) {
    if(index > 3) {
        cout << "Warning - There is only 3 trivia in the list." << endl;
        return -1;
    }
    int totalPoints = 0;
    if(head == NULL)
        throw invalid_argument("Warning - the number of trivia to be asked must equal to or be larger than 1.");
    triviaNode* current = head;
    for(int x = 0 ; x < index; x++) {
        if(answer == current -> answer) {
            cout << "Your answer is correct! You receive " << current -> points << " points" << endl;
            totalPoints += current -> points;
        }
        else
            cout << "Your answer is wrong. The correct answer is " << current -> answer << endl;
        current = current -> next;
    }
    return totalPoints;
}

int main() {
    #ifdef UNIT_TESTING
    runUnitTests();
    #else
    cout << "*** Welcome to Thomas' trivia quiz game ***" << endl;
    triviaNode* head = NULL;
    string check = "Yes";
    string question;
    string answer;
    int points;
    int count = 0;
    do {
        cout << "Enter a question: ";
        cin >> question;
        cout << "Enter an answer: ";
        cin >> answer;
        cout << "Enter award points: ";
        cin >> points;
        InsertNode(head, count, question, answer, points);
        cout << "Continue? (Yes/No): ";
        cin >> check;
        count++;
    } while(check == "Yes");
    if (count == 0)
    cout << "***This is a debugging version***" << endl;
    quiz(head, count);
    #endif
    return 0;
}