#include "modele.h"

/** DOCUMENTATION
 * tests are grouped in categories based on similarities in functions
 * each test is declared in a function of type void containing three parts
 * PART_1 : variables declaration
 * PART_2 : boolean values declaration named test_${i}
 * PART_3 : asserting the boolean variables
 * 
 * NOTE : used assert function from "cassert" library (included in "modele.h")
 */

/* TEST_GROUP_01 : plateau declaration */
void test_plateauVide() {
    Plateau nullPlateau = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

    bool test_1 = plateauVide() == nullPlateau;

    assert(test_1);
}

void test_plateauInitial() {
    Plateau initPlateau = plateauInitial();
    int zeroCounter = 0, twoCounter = 0, fourCounter = 0;
    
    for (auto line : initPlateau) {
        for (auto elm : line) {
            if (not elm) {
                zeroCounter++;
                continue;
            }
            if (elm == 2) {
                twoCounter++;
                continue;
            }
            if (elm == 4) {
                fourCounter++;
                continue;
            }
        }
    }

    bool test_1 = (fourCounter + twoCounter == 2);
    bool test_2 = (zeroCounter == 14);

    assert(test_1);
    assert(test_2);
}

/* TEST_GROUP_02 : random selection */
void test_randomPosition() {
    Plateau emptyPlateau = plateauVide();
    Plateau allPlateau = {{2, 2, 2, 2}, {2, 2, 2, 0}, {2, 2, 2, 2}, {2, 2, 2, 2}};
    vector<int> emptyPosition = {1, 3};

    bool test_1 = 0 <= randomPosition(emptyPlateau)[0] <= 3 && 0 <= randomPosition(emptyPlateau)[1] <= 3;
    bool test_2 = randomPosition(allPlateau) == emptyPosition;

    assert(test_1);
    assert(test_2);
}

void test_tireDeuxOuQuatre() {
    int fetchedValue1 = tireDeuxOuQuatre();
    int fetchedValue2 = tireDeuxOuQuatre();
    int fetchedValue3 = tireDeuxOuQuatre();
    int fetchedValue4 = tireDeuxOuQuatre();
    int fetchedValue5 = tireDeuxOuQuatre();
    int fetchedValue6 = tireDeuxOuQuatre();
    int fetchedValue7 = tireDeuxOuQuatre();

    bool test_1 = fetchedValue1 == 2 || fetchedValue1 == 4;
    bool test_2 = fetchedValue2 == 2 || fetchedValue2 == 4;
    bool test_3 = fetchedValue3 == 2 || fetchedValue3 == 4;
    bool test_4 = fetchedValue4 == 2 || fetchedValue4 == 4;
    bool test_5 = fetchedValue5 == 2 || fetchedValue5 == 4;
    bool test_6 = fetchedValue6 == 2 || fetchedValue6 == 4;
    bool test_7 = fetchedValue7 == 2 || fetchedValue7 == 4;

    assert(test_1);
    assert(test_2);
    assert(test_3);
    assert(test_4);
    assert(test_5);
    assert(test_6);
    assert(test_7);
}

/* TEST_GROUP_03 : mouvement functions */
/** NOTE : the function deplacement() call all other mouvement functions thus
 * one test would be enough
 */
void test_deplacement() {
    Plateau mvPlateau = {{2, 4, 0, 4},
                         {2, 2, 2, 2},
                         {2, 0, 0, 0},
                         {2, 4, 0, 2}};
    
    Plateau UP_plateau = {{4, 4, 2, 4},
                          {4, 2, 0, 4},
                          {0, 4, 0, 0},
                          {0, 0, 0, 0}};

    Plateau DOWN_plateau = {{0, 0, 0, 0},
                            {0, 4, 0, 0},
                            {4, 2, 0, 4},
                            {4, 4, 2, 4}};

    Plateau LEFT_plateau = {{2, 8, 0, 0},
                            {4, 4, 0, 0},
                            {2, 0, 0, 0},
                            {2, 4, 2, 0}};

    Plateau RIGHT_plateau = {{0, 0, 2, 8},
                             {0, 0, 4, 4},
                             {0, 0, 0, 2},
                             {0, 2, 4, 2}};

    bool test_1 = deplacementHaut(mvPlateau) == UP_plateau;
    bool test_2 = deplacementBas(mvPlateau) == DOWN_plateau;
    bool test_3 = deplacementGauche(mvPlateau) == LEFT_plateau;
    bool test_4 = deplacementDroite(mvPlateau) == RIGHT_plateau;

    assert(test_1);
    assert(test_2);
    assert(test_3);
    assert(test_4);
}

void test_sumX() {}
void test_sumY() {}
void test_organizeLeft() {}
void test_organizeRight() {}
void test_organizeUp() {}
void test_organizeDown() {}

/* TEST_GROUP_04 : console display functions */
/**
 * NOTE : as the function dessine() provides direct feedback through
 * console, it shall not be tested traditionally
 */
void test_starsDrawer() {
    string stars = starsDrawer();
    int starsCounter = (displayWidth + 1) * 4 + 2;

    for (char i : stars)
        starsCounter--;
    
    bool test_1 = not starsCounter;

    assert(test_1);
}

/* TEST_GROUP_05 : plateau properties functions */
void test_estTermine() {}
void test_estGagnant() {}

/* TEST_GROUP_06 : mid-functions */
void test_lenInt() {
    int len_1 = lenInt(1);
    int len_2 = lenInt(10);
    int len_3 = lenInt(100);
    int len_4 = lenInt(1000);

    bool test_1 = len_1 == 1;
    bool test_2 = len_2 == 2;
    bool test_3 = len_3 == 3;
    bool test_4 = len_4 == 4;
}

int main() {
    
    /* TEST_GROUP_01 */
    test_plateauVide();
    test_plateauInitial();

    /* TEST_GROUP_02 */
    test_randomPosition();
    test_tireDeuxOuQuatre();

    /* TEST_GROUP_03 */
    test_deplacement();

    /* TEST_GROUP_04 */
    test_starsDrawer();

    /* TEST_GROUP_05 */

    /* TEST_GROUP_06 */
    test_lenInt();

    return 0;
}