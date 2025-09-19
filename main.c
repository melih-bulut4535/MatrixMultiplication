/*
 * Name & Surname: Melih BULUT.
 * Date: 15.03.2022
 * The purpose of the program: Matrix Multiplication.
 * Matrix Multiplication:
 * In linear algebra, or more generally in mathematics,
 * matrix multiplication is the binary operation done on a pair of matrices and producing another matrix.
 * Numbers such as real or complex numbers can be multiplied in accordance with basic arithmetic.
 * In other words, matrices are strings of numbers.
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
//Matrix multiplication part
void matrixMultiplication(int first[][10],int second[][10],int result[][10], int line1, int column1, int column2){
    for (int i = 0; i < line1; ++i) {
        for (int j = 0; j < column2; ++j) {
            result[i][j] = 0;
        }
    }
    for(int i = 0; i < line1; i++){
        for(int j = 0; j< column2; j++){
            for (int x = 0; x < column1; x++){
                result [i][j] += first[i][x] * second[x][j];
            }
        }
    }
}
//The part that prints the matrix multiplication
void matrixPrinting(int result [][10],int lineInput, int columnInput){
    printf("Matrix multiplication result:\n");
    for(int i = 0; i < lineInput; i++){
        for(int j = 0; j < columnInput; j++){
            printf(" %d ",result[i][j]);
            if (j == columnInput - 1)
                printf("\n");
        }
        printf("\n");
    }
}
void matrixPrinting2(int matrix [][10],int lineInput, int columnInput){
    for(int i = 0; i < lineInput; i++){
        for(int j = 0; j < columnInput; j++){
            printf("%d ",matrix[i][j]);
            if (j == columnInput - 1)
                printf("\n");
        }
    }
}
void rowTotal (int result [][10],int lineInput, int columnInput){
    int total;
    for(int i = 0 ; i < lineInput; i++){
        total = 0;
        for(int j = 0; j < columnInput; j++){
            total += result[i][j];
        }
        printf("%d. row total: %d\n",i+1,total);
    }

}
void columnTotal (int result [][10],int lineInput, int columnInput){
    int total;
    for(int j = 0 ; j < columnInput; j++){
        total = 0;
        for(int i = 0; i < lineInput; i++){
            total += result[i][j];
        }
        printf("%d. column total: %d\n",j+1,total);
    }
}
void diagonalSum(int result [][10],int lineInput, int columnInput){
    int total;
    for (int x = 0; x < columnInput-1; x++) {
        total = 0;
        for (int i = 0; i < lineInput && i < columnInput; i++) {
            total += result[i][i+x];
        }
        printf("%d. diagonal total: %d\n", x+1, total);
    }
}

void transpose (int result [][10],int lineInput, int columnInput){
    printf("Matrix multiplication result:\n");
    for(int i = 0; i < columnInput; i++){
        for(int j = 0; j < lineInput; j++){
            printf("%d ",result[j][i]);
            if (j == columnInput - 1)
                printf("\n");
        }
        printf("\n");
    }
}
int NumberControl(){                                                                 //Only positive number selection
    int num;
    char buf[1024];
    int success;                                                                     // flag for successful conversion

    do
    {
        printf("");
        if (!fgets(buf, 1024, stdin))
        {

            return 1;                                                                // reading input failed:
        }
        char *endptr;                                                                // have some input, convert it to integer:

        errno = 0;                                                                   // reset error number
        num = strtol(buf, &endptr, 10);
        if (errno == ERANGE)
        {
            printf("Sorry, this number is too small or too large.\n");
            success = 0;
        }
        else if (endptr == buf)
        {
            printf("You entered a character. Please enter number\n");               // no character was read
            fflush(stdout);
            success = 0;
        }
        else if (num < 0)
        {
            printf("You entered negative number. Please try again!\n");              //No negative numbers
            success = 0;
        }
        else if (*endptr && *endptr != '\n')
        {
            printf("You entered invalid number. Please try again!\n");               // *endptr is neither end of string nor newline,
            success = 0;                                                              // so we didn't convert the whole input
        }
        else
        {
            success = 1;
        }
    } while (!success);                                                              // repeat until we got a valid number

    return num;
}
int NumControl(){                                                                 //Only positive number selection
    int num;
    char buf[1024];
    int success;                                                                     // flag for successful conversion

    do
    {
        printf("");
        if (!fgets(buf, 1024, stdin))
        {

            return 1;                                                                // reading input failed:
        }
        char *endptr;                                                                // have some input, convert it to integer:

        errno = 0;                                                                   // reset error number
        num = strtol(buf, &endptr, 10);
        if (errno == ERANGE)
        {
            printf("Sorry, this number is too small or too large.\n");
            success = 0;
        }
        else if (endptr == buf)
        {
            printf("You entered a character. Please enter number\n");               // no character was read
            fflush(stdout);
            success = 0;
        }
        else if (*endptr && *endptr != '\n')
        {
            printf("You entered invalid number. Please try again!\n");               // *endptr is neither end of string nor newline,
            success = 0;                                                              // so we didn't convert the whole input
        }
        else
        {
            success = 1;
        }

    } while (!success);                                                              // repeat until we got a valid number

    return num;
}
void matrixInput(int matrix[][10],int lineInput, int columnInput){
        printf("\nEnter the values of the matrix:\n" );
        for (int i = 0; i < lineInput; i++) {
            for (int j = 0; j < columnInput; j++) {
                printf("%dx%d)-> ",i+1,j+1);
                matrix[i][j] = NumControl();
            }
        }
}
double det(int result[10][10],int m, int n) {
    int row_size = m;
    int column_size = n;

    if (row_size != column_size) {
        printf("DimensionError: Operation Not Permitted \n");
        exit(1);
    }

    else if (row_size == 1)
        return (result[0][0]);

    else if (row_size == 2)
        return (result[0][0]*result[1][1] - result[1][0]*result[0][1]);

    else {
        int minor[row_size-1][column_size-1];
        int row_minor, column_minor;
        int firstrow_columnindex;
        double sum = 0;

        register int row,column;

        // exclude first row and current column
        for(firstrow_columnindex = 0; firstrow_columnindex < row_size;
            firstrow_columnindex++) {

            row_minor = 0;

            for(row = 1; row < row_size; row++) {

                column_minor = 0;

                for(column = 0; column < column_size; column++) {
                    if (column == firstrow_columnindex)
                        continue;
                    else
                        minor[row_minor][column_minor] = result[row][column];

                    column_minor++;
                }

                row_minor++;
            }

            m = row_minor;
            n = column_minor;

            if (firstrow_columnindex % 2 == 0)
                sum += result[0][firstrow_columnindex] * det(minor,n,m);
            else
                sum -= result[0][firstrow_columnindex] * det(minor,n,m);

        }

        return sum;

    }
}
int main() {
    while(1) {
            char runAgain;
            int first[10][10], second[10][10], result[10][10];
            int line1, column1;
            int line2, column2;
            double determinant;
            int caseSelection;
            //int smallValue,largeValue;
        printf("WELCOME TO THE MATRIX MULTIPLICATION PROGRAM\n");
        printf("----------------------------------------------\n");
            printf("Enter the size of the matrix 1 :\n"
                   "Row:");
            line1 = NumberControl();
            printf("Column:");
            column1 = NumberControl();
            printf("Enter the size of the matrix 2 :\n"
                   "Row:");
            line2 = NumberControl();
            printf("Column:");
            column2 = NumberControl();
        if (line2 == column1) {
        printf("How would you like to generate the matrix 1 values:\n"
               "1) Special Matrix\n"
               "2) Manually\n");
        caseSelection = NumberControl();
        if(caseSelection == 1){

                printf("Select the custom matrix you want:\n"
                       "1) Zero Matrix\n"
                       "2) Diagonal Matrix\n"
                       "3) Unit Matrix\n");
                int customMatrix;
                customMatrix = NumberControl();
                switch (customMatrix) {
                    case 1:
                        for (int i = 0; i < line1; i++) {
                            for (int j = 0; j < column1; j++) {
                                first[i][j] = 0;
                            }
                        }
                        matrixPrinting2(first, line1, column1);
                        matrixInput(second, line2, column2);
                        matrixPrinting2(second, line2, column2);
                        break;
                    case 2:
                        for (int i = 0; i < line1; ++i) {
                            for (int j = 0; j < column1; ++j) {
                                first[i][j] = 0;
                            }
                        }
                        for (int i = 0; i < line1 && i < column1; i++) {
                            printf("%dx%d)-> ",i+1,i+1);
                            first[i][i] = NumControl();
                        }
                        matrixPrinting2(first, line1, column1);
                        matrixInput(second, line2, column2);
                        matrixPrinting2(second, line2, column2);
                        break;
                    case 3:
                        for (int i = 0; i < line1; ++i) {
                            for (int j = 0; j < column1; ++j) {
                                first[i][j] = 0;
                            }
                        }
                        for (int i = 0; i < line1 && i < column1; i++) {
                            first[i][i] = 1;
                        }
                        matrixPrinting2(first, line1, column1);
                        matrixInput(second, line2, column2);
                        matrixPrinting2(second, line2, column2);
                        break;
                    default:
                        printf("You entered an invalid value!\n");
                        break;
                }
            }
        }
            if (line2 == column1) {
                if(caseSelection==2) {
                    matrixInput(first, line1, column1);
                    matrixPrinting2(first, line1, column1);
                    matrixInput(second, line2, column2);
                    matrixPrinting2(second, line2, column2);
                }

                matrixMultiplication(first, second, result, line1, column1, column2);
                matrixPrinting(result, line1, column2);

                int process;
                char choice;
                int counter = 0;
                int counter2 = 0;
                while (1) {
                    printf("\n Would you like to perform mathematical operations with the result you found?(N:No, Y:Yes)\n");
                    scanf("%s", &choice);
                    if (choice != 'y' && choice != 'Y') {
                        if (choice != 'n' && choice != 'N') {
                            printf("You entered indefinite value!\n");
                            counter++;
                        } else {
                            break;
                        }
                        if (counter == 3) {
                            printf("You have made more than 3 incorrect entries, your transaction has been terminated!\n");
                            break;
                        }
                    } else {
                        fflush(stdin);
                        counter2++;
                        printf("Select the type of transaction you want to do:\n"
                               "1) row sum\n"
                               "2) column sum\n"
                               "3) diagonal sum\n"
                               "4) determinant\n"
                               "5) transpose\n");
                        process = NumberControl();
                        switch (process) {
                            case 1:
                                rowTotal(result, line1, column2);
                                break;
                            case 2:
                                columnTotal(result, line1, column2);
                                break;
                            case 3:
                                diagonalSum(result,line1,column2);
                                break;
                            case 4:
                                determinant = det(result, line1, column2);
                                printf("determinant = %.1f \n", determinant);
                                break;
                            case 5:
                                transpose(result,line1,column2);
                                break;
                            default:
                                printf("You entered an invalid value!\n");
                                break;

                        }
                    }
                    if (counter2 == 5) {
                        printf("You have used your two processing rights.");
                        break;
                    }
                }
            } else if (line2 != column1) {
                printf("For you to do matrix multiplication,\n"
                       "the number of columns in the first matrix must be equal to the number of rows in the second matrix!\n");
                printf("Please try again!\n");
            }


            printf("\nWould you like to restart the program from the beginning?(N:No, Y:Yes)\n");
            scanf("%s",&runAgain);
            if (runAgain != 'y' && runAgain != 'Y') {
                if (runAgain != 'n' && runAgain != 'N') {
                    printf("You entered indefinite value!");
                    break;
                } else {
                    printf("Thank you using the program.");
                    break;
                }
            }
        fflush(stdin);

    }

    return 0;
}
