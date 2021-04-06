#include "header.h"

int main(){
    Matrix matr = {0, NULL};
    struct Vector vm = {0, NULL};
    if(getMatrix(&matr) == 0){
        printf("%s\n", "End of file occured");
        return 1;
    }
    printMatrix("Sourced matrix", matr);
    transform(matr, &vm);
    printVector("Result Vector", vm);
    eraseMatrix(&matr);
    eraseVector(&vm);
    return 0;
}
