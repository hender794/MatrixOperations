/*
* Auth: Jake Henderson
* Date: 05-02-24 (Due: 05-12-24)
* Course: CSCI-2240 (Sec: 850)
* Desc: PROG-07, Matrix Operations
*/
#define ROWS 3
#define COLS 3
#include <stdio.h>

void scalar_mult3x3(float k, float A[ROWS][COLS], float R[ROWS][COLS]);
void matrix_add3x3(float A[ROWS][COLS], float B[ROWS][COLS], float R[ROWS][COLS]);
void matrix_sub3x3(float A[ROWS][COLS], float B[ROWS][COLS], float R[ROWS][COLS]);
void ask_matrix3x3(const char *msg, float M[ROWS][COLS]);
void ask_scalar(const char *msg, float *k);
int print_menu_and_get_choice(void);
void print_matrix3x3(const char *msg, float M[ROWS][COLS]);
void flush_linebuffer(void);

int main(void) {
    float A[ROWS][COLS], B[ROWS][COLS], R[ROWS][COLS];
    float k;
    int choice;

    printf("*** Matrix Ops, ver. 0.1 ***\n");

    while ((choice = print_menu_and_get_choice()) != 4) {
        switch (choice) {
            case 1:
                ask_scalar("Please enter a scalar: ", &k);
                ask_matrix3x3("Please enter 9 numbers "
                    "separated by a space for Matrix A:", A);
                scalar_mult3x3(k, A, R);
                print_matrix3x3("Result =", R);
                break;
            case 2:
                ask_matrix3x3("Please enter 9 numbers "
                    "separated by a space for Matrix A:", A);
                ask_matrix3x3("Please enter 9 numbers "
                    "separated by a space for Matrix B:", B);
                matrix_add3x3(A, B, R);
                print_matrix3x3("Result =", R);
                break;
            case 3:
                ask_matrix3x3("Please enter 9 numbers "
                    "separated by a space for Matrix A:", A);
                ask_matrix3x3("Please enter 9 numbers "
                    "separated by a space for Matrix B:", B);
                matrix_sub3x3(A, B, R);
                print_matrix3x3("Result =", R);
                break;
            default:
                printf("ERROR: Unrecognized choice.\n\n");
        }
    }

    printf("\nThank you for using Matrix Ops.\n\n");
    return 0;
}

void scalar_mult3x3(float k, float A[ROWS][COLS], float R[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            R[i][j] = A[i][j] * k;
        }
    }
}

void matrix_add3x3(float A[ROWS][COLS], float B[ROWS][COLS], float R[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            R[i][j] = A[i][j] + B[i][j];
        }
    }
}

void matrix_sub3x3(float A[ROWS][COLS], float B[ROWS][COLS], float R[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            R[i][j] = A[i][j] - B[i][j];
        }
    }
}

void ask_matrix3x3(const char *msg, float M[ROWS][COLS]) {
    int i, j;
    printf("%s\n", msg);
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (scanf("%f", &M[i][j]) != 1) {
                printf("ERROR: Invalid matrix entry. Try again!\n");
                flush_linebuffer();
                j--; 
            }
        }
    }
}

void ask_scalar(const char *msg, float *k) {
    printf("%s", msg);
    while (scanf("%f", k) != 1) {
        printf("ERROR: Invalid scalar entry. Try a number!\n");
        flush_linebuffer();
        printf("Please enter a scalar: ");
    }
}

int print_menu_and_get_choice(void) {
    int choice;
    printf("\nMatrix Operations Menu:\n");
    printf("\t[1] Scalar Multiplication\n");
    printf("\t[2] Matrix Addition\n");
    printf("\t[3] Matrix Subtraction\n");
    printf("\t[4] Exit\n\n");
    printf("Please make a selection and press [Enter]: ");

    while (scanf("%d", &choice) != 1 || (choice < 1 || choice > 4)) {
        printf("Invalid Selection. Try 1, 2, 3, or 4!\n");
        flush_linebuffer();
        printf("Please make a selection and press [Enter]: ");
    }
    return choice;
}

void print_matrix3x3(const char *msg, float M[ROWS][COLS]) {
    int i; 
    int j;
    printf("%s\n", msg);

    for (i = 0; i < ROWS; i++) {
        printf("\t");
        for (j = 0; j < COLS; j++) {
            printf("%0.2f\t", M[i][j]);
        }
        printf("\n");
    }
}

void flush_linebuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}