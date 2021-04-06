#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Line{
    int items;
    int *data; 
}Line;

typedef struct Matrix{
    int lines;
    struct Line *ptr;
}Matrix;

typedef struct Vector{
    int size;
    int *res;
}Vector;

int getInt(int *);
int getMatrix(Matrix *);
void printMatrix(const char *, Matrix);
void transform(Matrix, struct Vector *);
void printVector(const char *, struct Vector);
void eraseMatrix(Matrix *);
void eraseVector(struct Vector *);
