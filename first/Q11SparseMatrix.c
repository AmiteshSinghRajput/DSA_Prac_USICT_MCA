#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

// Function to check if a matrix is sparse
int isMatrixSparse(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    int zeroCount = 0;
    int sparsityThreshold = rows * cols / 2; // Set a threshold for sparsity (adjustable)
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                zeroCount++;
            }
        }
    }

    return zeroCount > sparsityThreshold ? 1 : 0; // Matrix is sparse if zeroCount is greater than threshold
}

// Function to convert matrix to sparse triplet representation
void convertToSparseTripletForm(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols, int sparseTriplet[3][MAX_ROWS * MAX_COLS], int *count) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparseTriplet[0][*count] = i;        // Row index
                sparseTriplet[1][*count] = j;        // Column index
                sparseTriplet[2][*count] = matrix[i][j]; // Value
                (*count)++;
            }
        }
    }
}

// Function to display the sparse triplet representation
void printSparseTripletForm(int sparseTriplet[3][MAX_ROWS * MAX_COLS], int count, int rows, int cols) {
    printf("\nSparse triplet representation:\n");
    printf("Row\tColumn\tValue\n");
    printf("%d\t%d\t%d\n", rows, cols, count);
    
    for (int i = 0; i < count; i++) {
        printf("%d\t%d\t%d\n", sparseTriplet[0][i], sparseTriplet[1][i], sparseTriplet[2][i]);
    }
}

int main() {
    int numRows, numCols;

    // Get the number of rows and columns from the user
    printf("Enter the number of rows in the matrix: ");
    scanf("%d", &numRows);
    printf("Enter the number of columns in the matrix: ");
    scanf("%d", &numCols);

    if (numRows > MAX_ROWS || numCols > MAX_COLS) {
        printf("Error: Matrix size exceeds the maximum allowed size.\n");
        return 1;
    }

    int inputMatrix[MAX_ROWS][MAX_COLS];

    // Input matrix elements from the user
    printf("\nEnter the elements of the matrix:\n");
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            printf("Enter element at position [%d][%d]: ", i, j);
            scanf("%d", &inputMatrix[i][j]);
        }
    }

    // Display the input matrix in a different format
    printf("\nThe input matrix is:\n");
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            printf("%4d", inputMatrix[i][j]); // Adjust the width for alignment
        }
        printf("\n");
    }

    // Check if the matrix is sparse or not
    if (isMatrixSparse(inputMatrix, numRows, numCols)) {
        printf("\nThe matrix is sparse.\n");

        // Convert the matrix to sparse triplet representation
        int sparseTriplet[3][MAX_ROWS * MAX_COLS];
        int nonZeroCount = 0;
        convertToSparseTripletForm(inputMatrix, numRows, numCols, sparseTriplet, &nonZeroCount);

        // Display the sparse triplet representation
        printSparseTripletForm(sparseTriplet, nonZeroCount, numRows, numCols);
    } else {
        printf("\nThe matrix is not sparse.\n");
    }

    return 0;
}
