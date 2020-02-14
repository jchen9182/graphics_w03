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

    printf("Testing ident(m1)\n");
    struct matrix * m1 = new_matrix(4, 4);
    ident(m1);
    print_matrix(m1);

    printf("\nTesting matrix_mult(m1, m2)\n");

    free_matrix(m1);


}
