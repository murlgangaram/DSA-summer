#include <stdio.h>
#include <stdlib.h>
#include "Hash.h"

int main() {
    Dictionary D;
    initDictionary(D);

     studentInfo info1 = {{"Balisacan", "Luke", 'G'}, "4thYear", "BSIS"};
    studentInfo info2 = {{"Rica", "Arden", 'L'}, "3rdYear", "BSMED"};
    studentInfo info3 = {{"Gudgad", "CJ", 'B'}, "4thYear", "BSIS"};
    studentInfo info4 = {{"Tan", "Philip", 'A'}, "4thYear", "BSIS"};
    studentInfo info5 = {{"Velasquez", "Van", 'B'}, "4thYear", "BSIS"};

    insertSortedByName(D, info1);
    insertSortedByName(D, info2);
    insertSortedByName(D, info3);
    insertSortedByName(D, info4);
    insertSortedByName(D, info5);
    
    deleteStudentInfo(D, info2);
    
    visualize(D);

    return 0;
}
