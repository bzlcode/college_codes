#include <stdio.h>

int A1[10][10], A2[10][10];
int T1[20][3], T2[20][3], C[20][3];
int m1, n1, m2, n2;

// Read a matrix
void read(int M[10][10], int *m, int *n) {
    printf("Enter number of rows and columns: ");
    scanf("%d %d", m, n);
    printf("Enter the elements:\n");
    for (int i = 0; i < *m; i++) {
        for (int j = 0; j < *n; j++) {
            scanf("%d", &M[i][j]);
        }
    }
}

// Display a matrix
void disp(int M[10][10], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

// Create tuple form (sparse matrix representation)
void create_tuple(int M[10][10], int T[20][3], int m, int n) {
    int k = 1;
    T[0][0] = m;
    T[0][1] = n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (M[i][j] != 0) {
                T[k][0] = i;
                T[k][1] = j;
                T[k][2] = M[i][j];
                k++;
            }
        }
    }
    T[0][2] = k - 1;
}

// Display tuple
void disp_tuple(int T[20][3]) {
    int total = T[0][2];
    printf("Tuple representation:\n");
    for (int i = 0; i <= total; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", T[i][j]);
        }
        printf("\n");
    }
}

// Transpose a sparse matrix
void transpose(int S[20][3], int S2[20][3]) {
    S2[0][0] = S[0][1];
    S2[0][1] = S[0][0];
    S2[0][2] = S[0][2];
    int k = 1;
    for (int col = 0; col < S[0][1]; col++) {
        for (int i = 1; i <= S[0][2]; i++) {
            if (S[i][1] == col) {
                S2[k][0] = S[i][1];
                S2[k][1] = S[i][0];
                S2[k][2] = S[i][2];
                k++;
            }
        }
    }
    printf("The transposed tuple is:\n");
    disp_tuple(S2);
}

// Add two sparse matrices
void add_sparse(int A[20][3], int B[20][3], int C[20][3]) {
    if (A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
        printf("Addition not possible. Dimensions do not match.\n");
        return;
    }

    int i = 1, j = 1, k = 1;
    C[0][0] = A[0][0];
    C[0][1] = A[0][1];

    while (i <= A[0][2] && j <= B[0][2]) {
        if (A[i][0] == B[j][0] && A[i][1] == B[j][1]) {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2] + B[j][2];
            i++; j++; k++;
        } else if ((A[i][0] < B[j][0]) || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++; k++;
        } else {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++; k++;
        }
    }

    while (i <= A[0][2]) {
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];
        i++; k++;
    }

    while (j <= B[0][2]) {
        C[k][0] = B[j][0];
        C[k][1] = B[j][1];
        C[k][2] = B[j][2];
        j++; k++;
    }

    C[0][2] = k - 1;
}

int main() {
    int choice;

    printf("Select:\n1 - Transpose a matrix\n2 - Add two matrices\n");
    scanf("%d", &choice);

    if (choice == 1) {
        int M[10][10], T[20][3], T2[20][3], m, n;

        read(M, &m, &n);
        printf("Original Matrix:\n");
        disp(M, m, n);
        create_tuple(M, T, m, n);
        disp_tuple(T);
        transpose(T, T2);

    } else if (choice == 2) {
        printf("Enter Matrix A:\n");
        read(A1, &m1, &n1);
        create_tuple(A1, T1, m1, n1);

        printf("Enter Matrix B:\n");
        read(A2, &m2, &n2);
        create_tuple(A2, T2, m2, n2);

        printf("Matrix A (tuple):\n");
        disp_tuple(T1);
        printf("Matrix B (tuple):\n");
        disp_tuple(T2);

        add_sparse(T1, T2, C);

        printf("Resultant Matrix (tuple after addition):\n");
        disp_tuple(C);
    }

    return 0;
}
