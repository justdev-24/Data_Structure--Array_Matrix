#include "header.h"

int getInt(int *a){
    int n;
    do{
        n = scanf("%d", a);
        if(n<0)
            return 0;
        else if(n==0){
            printf("%s\n", "Error input, please repeat!");
            scanf("%*c");
        }
    }while(n==0);
    return 1;
}

int getMatrix(Matrix *rm){
    int m, *p;
    const char *msg = "";

    do{
        printf("%s\n", msg);
        printf("Enter number of lines in Matrix: ");
        msg = "Error input, please repeat!";
        if(getInt(&m) == 0)
            return 0;
    }while(m < 0);
    rm->lines = m;
    rm->ptr = (Line *) calloc (m, sizeof(Line));
    for(int i = 0; i < rm->lines; ++i){
        msg = "";
        do{
            printf("%s\n", msg);
            printf("Enter number of items in the %d - Line: ", i+1);
            msg = "Error input, please repeat!";
            if(getInt(&m) == 0)
                return 0;
        }while(m < 0);
        rm->ptr[i].items = m;
        p = (int *) calloc (m, sizeof(int));
        rm->ptr[i].data = p;
        printf("Enter elements of %d-line:\n", i+1);
        for(int j = 0; j < ptr[i].items; ++j, ++p){
            printf("%d-item: ");
            if(getInt(p) == 0){
                rm->lines = i+1;
                erase(rm);
                return 0;
            }}}
    return 1;
}

void printMatrix(const char *msg, Matrix rm){
    int *p;
    printf("%s\n", msg);
    for(int i = 0; i < rm.lines; ++i){
        p = rm.ptr[i].data;
        for(int j = 0; j < rm.ptr[i].items; ++j, ++p){
            printf("%d\t", *p);
        }
        printf("\n");
    }
}

void transform(Matrix rm, struct Vector *vm){
    int S1 = 0;
    int S2 = 0;
    int *p, *m;
    vm->size = rm.lines;
    p = (int *) calloc (vm->size, sizeof(int));
    vm->res = p;
    for(int i = 0; i < rm.lines; ++i){
        m = rm.ptr[i].data;
        for(int j = 0; j < rm.ptr[i].items; ++j, ++m){
            if(rm.ptr[i].data[j] % 2 == 0)
                S1 = S1 + *m;
            else
                S2 = S2 + *m;
        }
        p[i] = S1-S2;
        S1 = 0;
        S2 = 0;
    }
}

void printVector(const char *msg, struct Vector vm){
    int *p;
    printf("%s\n", msg);
    p = vm.res;
    for(int i = 0; i < vm.size; ++i, ++p)
        printf("%d\t", *p);
    printf("\n");
}

void eraseMatrix(Matrix *rm){
    for(int i = 0; i < rm->lines; ++i)
        free(rm->ptr[i].data);
    free(rm->ptr);
    rm->lines = 0;
    rm->ptr = NULL;
}

void eraseVector(struct Vector *vm){
    free(vm->res);
    vm->size = 0;
}
