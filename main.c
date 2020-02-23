#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

#define PI 3.14159265;

void cc(color * c, int r, int g, int b) { // change color
    c->red = r;
    c->green = g;
    c->blue = b;
}

void add(struct matrix *points,
              double x0, double y0,
              double x1, double y1) { // shorten
    add_edge(points, x0, y0, 0, x1, y1, 0);
}

int main() {
    // Testing
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

    printf("\nUpdating m1:\n");
    free_matrix(m1);
    m1 = new_matrix(4, 4);
    add_edge(m1, 1, 2, 3, 4, 5, 6);
    add_edge(m1, 7, 8, 9, 10, 11, 12);
    print_matrix(m1);

    printf("\nTesting matrix_mult(m1, m2):\n");
    matrix_mult(m1, m2);
    print_matrix(m2);

    free_matrix(m1);
    free_matrix(m2);

    // Drawing
    screen s;
    color c;
    clear_screen(s);

    struct matrix * face = new_matrix(4, 2);
    int r = 250;
    int xcent = 250;
    int ycent = 250;
    for (int i = ycent + r; i > ycent - r; i--) {
        int y = i - ycent;
        double x = sqrt(pow(r, 2) - pow(y, 2));
        int x0 = (int) (xcent - x);
        int x1 = (int) (xcent + x);
        add(face, x0, i, x1, i);
    }
    cc(&c, 255, 230, 180);
    draw_lines(face, s, c);

    struct matrix * eyes = new_matrix(4, 2);
    r = 50;
    xcent = 150;
    ycent = 300;
    for (int i = ycent + r; i > ycent - r; i--) {
        int y = i - ycent;
        double x = sqrt(pow(r, 2) - pow(y, 2));
        int x0 = (int) (xcent - x);
        int x1 = (int) (xcent + x);
        add(eyes, x0, i, x1, i);
    }
    xcent = 350;
    ycent = 300;
    for (int i = ycent + r; i > ycent - r; i--) {
        int y = i - ycent;
        double x = sqrt(pow(r, 2) - pow(y, 2));
        int x0 = (int) (xcent - x);
        int x1 = (int) (xcent + x);
        add(eyes, x0, i, x1, i);
    }
    cc(&c, 185, 160, 110);
    draw_lines(eyes, s, c);

    struct matrix * mouth = new_matrix(4, 2);
    int xco = pow(110, 2);
    int yco = pow(125, 2);
    int right = xco * yco;
    xcent = 250;
    ycent = 85;
    for (int i = ycent + 109; i > ycent; i--) {
        int y = i - ycent;
        double y2 = pow(y, 2);
        double eq = yco * (1 - y2 / xco);
        double x = sqrt(eq);
        int x0 = (int) (xcent - x);
        int x1 = (int) (xcent + x);
        add(mouth, x0, i, x1, i);
    }
    draw_lines(mouth, s, c);

    struct matrix * mouth2 = new_matrix(4, 2);
    xco = pow(35, 2);
    yco = pow(130, 2);
    right = xco * yco;
    xcent = 250;
    ycent = 75;
    for (int i = ycent + 34; i > ycent; i--) {
        int y = i - ycent;
        double y2 = pow(y, 2);
        double eq = yco * (1 - y2 / xco);
        double x = sqrt(eq);
        int x0 = (int) (xcent - x);
        int x1 = (int) (xcent + x);
        add(mouth2, x0, i, x1, i);
    }
    cc(&c, 255, 230, 180);
    draw_lines(mouth2, s, c);

    struct matrix * brows = new_matrix(4, 2);
    int browmax = 400;
    for (int i = browmax; i > browmax - 30; i--) {
        add(brows, 90, i, 225, browmax - 85);
    }
    for (int i = browmax; i > browmax - 30; i--) {
        add(brows, 410, i, 275, browmax - 85);
    }
    cc(&c, 185, 160, 110);
    draw_lines(brows, s, c);

    char * name = "pic.png";
    save_extension(s, name);
    save_ppm_ascii(s, "ascii.ppm");
    printf("\nSaved as %s\n", name);
    display(s);
}
