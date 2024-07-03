#ifndef HASH_H
#define HASH_H

#define MAX 10

typedef struct {
    char LN[24];
    char FN[16];
    char MI;
} studentName;

typedef struct {
    studentName name;
    char year[24];
    char course[16];
} studentInfo;

typedef struct node {
    studentInfo info;
    struct node *next;
} *student;

typedef student Dictionary[MAX];

void initDictionary(Dictionary D);
void insertSortedByName(Dictionary D, studentInfo info);
void deleteStudentInfo(Dictionary D, studentInfo info);
void visualize(Dictionary D);

#endif
