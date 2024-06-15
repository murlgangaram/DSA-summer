#include <stdio.h>
#include <string.h>
#define MAX 20

typedef struct {
    char Fname[20];
    char Lname[20];
} studName;

typedef struct {
    int month;
    int year;
} bday;

typedef struct {
    studName name;
    bday birthdate;
    int age;
    int idNum;
} studentInfo;

typedef struct {
    studentInfo studList[MAX];
    int studCount;
} classRecord;

void initialize(classRecord *L);
void insertFirst(classRecord *L, studentInfo LL);
void insertLast(classRecord *L, studentInfo LL);
void insertAtIndex(classRecord *L, studentInfo LL, int post);
void insertSortedByAge(classRecord *L, studentInfo LL);

void deleteFirst(classRecord *L, studentInfo LL);
void deleteLast(classRecord *L, studentInfo LL);

void displayNames(classRecord L);

int main() {
    classRecord L;
    studentInfo LL;

    initialize(&L);

    studentInfo data[5] = {
        {{"Murliwani", "Gangaram"}, {12, 17}, 25, 18103367},
        {{"Luke", "Balisacan"}, {1, 1}, 23, 18103668},
        {{"CJ", "Balisacan"}, {2, 2}, 25, 18103660},
        {{"Arden", "Rica"}, {2, 2}, 22, 18103669}
    };

    for (int i = 0; i < 4; i++) {
        insertFirst(&L, data[i]);
    }

    insertFirst(&L, data[0]);
    insertLast(&L, data[3]);
    insertAtIndex(&L, LL ,2);
    
    deleteFirst(&L, data[0]);
    deleteLast(&L, data[3]);
    
    insertSortedByAge(&L, data[2]);
    displayNames(L);

    return 0;
}

void initialize(classRecord *L) {
    L->studCount = 0;
}

void insertFirst(classRecord *L, studentInfo LL) {

        if (L->studCount < MAX) {
            for (int i = L->studCount; i > 0; i--) {
                L->studList[i] = L->studList[i - 1];
            }
            L->studList[0] = LL;
            L->studCount++;
        
    }
}

void insertLast(classRecord *L, studentInfo LL) {

        if (L->studCount < MAX) {
            L->studList[L->studCount] = LL;
            L->studCount++;
    }
}
void insertAtIndex(classRecord *L, studentInfo LL, int post){
  if(post >= 0 && post <= L->studCount && L->studCount < MAX){
      
      for(int i = L->studCount; i > 0; i--){
          L->studList[i] = L->studList[i-1];
      }
      L->studList[0] = LL;
      L->studCount++;
  }

}
void insertSortedByAge(classRecord *L, studentInfo LL) {
    if (L->studCount < MAX) {
        int i;
        for (i = 0; i < L->studCount; i++) {
            if (LL.age < L->studList[i].age) {
                break;
            }
        }
        insertAtIndex(L, LL, i);
    }
}

void displayNames(classRecord L) {
    for (int i = 0; i < L.studCount; i++) {
        printf("Student Name: %s %s\n", L.studList[i].name.Fname, L.studList[i].name.Lname);
        printf("Birthdate: %d/%d\n", L.studList[i].birthdate.month, L.studList[i].birthdate.year);
        printf("Age: %d\n", L.studList[i].age);
        printf("Student ID: %d\n", L.studList[i].idNum);
        printf("\n");
    }
}

void deleteFirst(classRecord *L, studentInfo LL){
    
    if(L->studCount < MAX){
        L->studList[0] = LL;
        L->studCount--;
    }
}

void deleteLast(classRecord *L, studentInfo LL){
    
    if(L->studCount < MAX){
        L->studList[L->studCount] = LL;
        L->studCount--;
    }
}