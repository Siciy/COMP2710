//Thomas Brown trb0057 /home/u1/trb0057/comp/project2_Brown_trb0057.cpp
//How to compile:
//Run the file, press enter to continue when prompted, input number of duels to simulate
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <assert.h>
#include <ctime>
#include <stdexcept>
using namespace std;

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
void test_at_least_two_alive(void);
void Aaron_shoots1(bool &B_alive, bool &C_alive);
void Bob_shoots(bool &A_alive, bool &C_alive);
void Charlie_shoots(bool &A_alive, bool &B_alive);
void Aaron_shoots2(bool &B_alive, bool &C_alive);
bool doesShotHit(bool aaron, bool bob);
int* runner(int totalRuns, int strategy);

void test_Aaron_shoots1() {     
    cout << "Unit Testing 2: Function - Aaron_shoots1(Bob_alive, Charlie_alive)\n";
    cout << "\tCase 1: Bob alive, Charlie alive" << endl;
    bool B_alive = true;
    bool C_alive = true;
    Aaron_shoots1(B_alive, C_alive);
    assert(B_alive == true && C_alive == false);
    cout << "\tCase 2: Bob dead, Charlie alive" << endl;
    B_alive = false;
    C_alive = true;
    Aaron_shoots1(B_alive, C_alive);
    assert(B_alive == false && C_alive == false);
    cout << "\tCase 3: Bob alive, Charlie dead" << endl;
    B_alive = true;
    C_alive = false;
    Aaron_shoots1(B_alive, C_alive);
    assert(B_alive == false && C_alive == false);
}

void test_Bob_shoots() {
    cout << "Unit Testing 3: Function - Bob_shoots(Aaron_alive, Charlie_alive)\n";
    cout << "\tCase 1: Aaron alive, Charlie alive" << endl;
    bool B_alive = true;
    bool C_alive = true;
    Bob_shoots(B_alive, C_alive);
    assert(B_alive == true && C_alive == false);
    cout << "\tCase 2: Aaron dead, Charlie alive" << endl;
    B_alive = false;
    C_alive = true;
    Bob_shoots(B_alive, C_alive);
    assert(B_alive == false && C_alive == false);
    cout << "\tCase 3: Aaron alive, Charlie dead" << endl;
    B_alive = true;
    C_alive = false;
    Bob_shoots(B_alive, C_alive);
    assert(B_alive == false && C_alive == false);
}

void test_Charlie_shoots() {
    cout << "Unit Testing 4: Function - Charlie_shoots(Aaron_alive, Bob_alive)\n";
    cout << "\tCase 1: Aaron alive, Bob alive" << endl;
    bool B_alive = true;
    bool C_alive = true;
    Charlie_shoots(B_alive, C_alive);
    assert(B_alive == true && C_alive == false);
    cout << "\tCase 2: Aaron dead, Bob alive" << endl;
    B_alive = false;
    C_alive = true;
    Charlie_shoots(B_alive, C_alive);
    assert(B_alive == false && C_alive == false);
    cout << "\tCase 3: Aaron alive, Bob dead" << endl;
    B_alive = true;
    C_alive = false;
    Charlie_shoots(B_alive, C_alive);
    assert(B_alive == false && C_alive == false);
}

void test_Aaron_shoots2() {
    cout << "Unit Testing 5: Function - Aaron_shoots2(Bob_alive, Charlie_alive)\n";
    cout << "\tCase 1: Bob alive, Charlie alive" << endl;
    bool B_alive = true;
    bool C_alive = true;
    Aaron_shoots2(B_alive, C_alive);
    assert(B_alive == true && C_alive == true);
    cout << "\tCase 2: Bob dead, Charlie alive" << endl;
    B_alive = false;
    C_alive = true;
    Aaron_shoots2(B_alive, C_alive);
    assert(B_alive == false && C_alive == false);
    cout << "\tCase 3: Bob alive, Charlie dead" << endl;
    B_alive = true;
    C_alive = false;
    Aaron_shoots2(B_alive, C_alive);
    assert(B_alive == false && C_alive == false);
}

void test_at_least_two_alive(void) {
    cout << "Unit Testing 1: Function – at_least_two_alive()" << endl;
    cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive" << endl;
    assert(true == at_least_two_alive(true, true, true));
    cout << "\tCase passed ..." << endl;
    cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive" << endl;
    assert(true == at_least_two_alive(false, true, true));
    cout << "\tCase passed ..." << endl;
    cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive" << endl;
    assert(true == at_least_two_alive(true, false, true));
    cout << "\tCase passed ..." << endl;
    cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead" << endl;
    assert(true == at_least_two_alive(true, true, false));
    cout << "\tCase passed ..." << endl;
    cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive" << endl;
    assert(false == at_least_two_alive(false, false, true));
    cout << "\tCase passed ..." << endl;
    cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead" << endl;
    assert(false == at_least_two_alive(false, true, false));
    cout << "\tCase passed ..." << endl;
    cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead" << endl;
    assert(false == at_least_two_alive(true, false, false));
    cout << "\tCase passed ..." << endl;
    cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead" << endl;
    assert(false == at_least_two_alive(false, false, false));
    cout << "\tCase passed ..." << endl;
}

int main() {
    cout << "\n***Welcome to Thomas' Duel Simulator***" << endl;
    test_at_least_two_alive();
    cout << "Press Enter to continue..." << endl;
    cin.ignore();
    test_Aaron_shoots1();
    cout << "Press Enter to continue..." << endl;
    cin.ignore();
    test_Bob_shoots();
    cout << "Press Enter to continue..." << endl;
    cin.ignore();
    test_Charlie_shoots();
    cout << "Press Enter to continue..." << endl;
    cin.ignore();
    test_Aaron_shoots2();
    cout << "Press Enter to continue..." << endl;
    cin.ignore();
    cout << "Input total number of duels to simulate:" << endl;
    int totalRuns;
    cin >> totalRuns;
    //Checks if the number of duels simulated is valid
    if(totalRuns < 1) {
        throw invalid_argument("Invalid Number");
    }
    cout << "Ready to test strategy 1 (run " << totalRuns << " times):" << endl;
    cout << "Press Enter to continue..." << endl;
    cin.ignore().get();
    //I needed to use dynamic memory allocation in order to make different references to the pointer that is returned
    //If you are grading this could you add a comment or something to let me know if I allocated my memory correctly
    //Or if there was a better way to go about this I would appreciate input, I'm new to cpp
    int* ptr1;
    ptr1 = runner(totalRuns, 1);
    int strategyOneWins = ptr1[0];
    cout << setprecision(2) << endl;
    cout << "Aaron won " << ptr1[0] << "/" << totalRuns << " duels or " << (double) ptr1[0]/totalRuns*100 << "%" << endl;
    cout << "Bob won " << ptr1[1] << "/" << totalRuns << " duels or " << (double) ptr1[1]/totalRuns*100 << "%" << endl;
    cout << "Charlie won " << ptr1[2] << "/" << totalRuns << " duels or " << (double) ptr1[2]/totalRuns*100 << "%\n" << endl;
    delete[] ptr1;
    cout << "Ready to test strategy 2 (run " << totalRuns << " times):" << endl;
    cout << "Press Enter to continue..." << endl;
    cin.ignore();
    int* ptr2;
    ptr2 = runner(totalRuns, 2);
    int strategyTwoWins = ptr2[0];
    cout << "Aaron won " << ptr2[0] << "/" << totalRuns << " duels or " << (double) ptr2[0]/totalRuns*100 << "%" << endl;
    cout << "Bob won " << ptr2[1] << "/" << totalRuns << " duels or " << (double) ptr2[1]/totalRuns*100 << "%" << endl;
    cout << "Charlie won " << ptr2[2] << "/" << totalRuns << " duels or " << (double) ptr2[2]/totalRuns*100 << "%\n" << endl;
    delete[] ptr2;
    if(strategyOneWins > strategyTwoWins)
        cout << "Strategy 1 is better than strategy 2." << endl;
    else
        cout << "Strategy 2 is better than strategy 1." << endl;
}

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
    return A_alive + B_alive + C_alive > 1;
}

void Aaron_shoots1(bool &B_alive, bool &C_alive) {
    if(C_alive) { 
        cout << "\t\tAaron is shooting at Charlie" << endl;
        C_alive = false;
    }
    else if(B_alive) {
        cout << "\t\tAaron is shooting at Bob" << endl;
        B_alive = false;
    }
}
void Bob_shoots(bool &A_alive, bool &C_alive) {
    if(C_alive) {
        cout << "\t\tBob is shooting at Charlie" << endl;
        C_alive = false;
    }
    else if(A_alive) {
        cout << "\t\tBob is shooting at Aaron" << endl;
        A_alive = false;
    }
}
void Charlie_shoots(bool &A_alive, bool &B_alive) {
    if(B_alive) {
        cout << "\t\tCharlie is shooting at Bob" << endl;
        B_alive = false;
    }
    else if(A_alive) {
        cout << "\t\tCharlie is shooting at Aaron" << endl;
        A_alive = false;
    }
}
void Aaron_shoots2(bool &B_alive, bool &C_alive) {
    if(B_alive && C_alive) {
        cout << "\t\tAaron intentionally misses his first shot" << endl;
        cout << "\t\tBoth Bob and Charlie are alive" << endl;
    }
    else if (C_alive) {
        cout << "\t\tAaron is shooting at Charlie" << endl;
        C_alive = false;
    }
    else if(B_alive) {
        cout << "\t\tAaron is shooting at Bob" << endl;
        B_alive = false;
    }
}

//takes input of who is shooting, uses rand num generator to return integer 1,2,3 or 1,2
bool doesShotHit(bool aaron, bool bob) {
    if(aaron) {
        int random = rand() % 3 + 1;
        if(random == 1)
            return true;
    }
    else if(bob) {
        int random = rand() % 2 + 1;
        if(random == 1)
            return true;
    }
    return false;
}

//runs the simulation totalRuns ammount of times, and takes an imput of what strategy Aaron is using
int* runner(int totalRuns, int strategy) {
    //I tried to initialize it with |int* totalWins = new int[3] {0};|
    //But extended initializer lists are only available with -std=c++11 or -std=gnu++11
    int* totalWins = new int[3];
    for(int x = 0; x < 3; x++) {
        totalWins[x] = 0;
    }
    for(int x = 0; x < totalRuns; x++) {
        bool a = true;
        bool b = true;
        bool c = true;
        //Game logic, iteratively goes through shot progression
        while (at_least_two_alive(a, b, c)) {
            if(a && doesShotHit(a, false) == 1) {
                    if(strategy == 2 && b && c) {}
                    else if(c)
                        c = false;
                    else if(b)
                        b = false;
            }
            if(b && doesShotHit(false, b) == 1) {
                if(c)
                    c = false;
                else if(a)
                    a = false;
            }
            if(c) {
                if(b)
                    b = false;
                else if(a)
                    a = false;
            }
        }
        if(a)
            totalWins[0] += 1;
        else if(b)
            totalWins[1] += 1;
        else if(c)
            totalWins[2] += 1;
    }
    return totalWins;
}