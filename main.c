#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {
    // screen s;
    // struct matrix *edges;
    //
    // edges = new_matrix(4, 4);
    //
    // free_matrix(edges);

    printf("TESTING MATRIX FUNCTIONS:\n\n");

    printf("Testing add_edge(m2, 1, 2, 3, 4, 5, 6):\n");
    struct matrix * m2 = new_matrix(4, 1);
    add_edge(m2, 1, 2, 3, 4, 5, 6);
    print_matrix(m2);

    printf("\nTesting ident(m1):\n");
    struct matrix * m1 = new_matrix(4, 4);
    ident(m1);
    print_matrix(m1);

    printf("\nTesting matrix_mult(m1, m2):\n");
    matrix_mult(m1, m2);
    print_matrix(m2);

    free_matrix(m1);
    free_matrix(m2);
}
