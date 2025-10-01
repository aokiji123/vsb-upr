#include <stdio.h>

void filledRectangle(int width, int height);
void hollowRectangle(int width, int height);
void numberedRectangleRows(int width, int height);
void diagonalRight(int size);
void diagonalLeft(int size);
void triangle(int height);
void letterT(int width, int height);
void letterP(int width, int height);
void numberedRectangleCols(int width, int height);

int main() {
    int shape;
    int width;
    int height;
    scanf("%d %d %d", &shape, &width, &height);

    switch (shape) {
        case 0: 
            filledRectangle(width, height); 
            break;
        case 1: 
            hollowRectangle(width, height); 
            break;
        case 2: 
            numberedRectangleRows(width, height); 
            break;
        case 3: 
            diagonalRight(width); 
            break;
        case 4: 
            diagonalLeft(width); 
            break;
        case 5: 
            triangle(width); 
            break;
        case 6: 
            letterT(width, height); 
            break;
        case 7: 
            letterP(width, height); 
            break;
        case 9: 
            numberedRectangleCols(width, height); 
            break;
        default: 
            printf("Neznamy obrazec\n"); 
            break;
    }

    return 0;
}

void filledRectangle(int width, int height) {
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            printf("x");
        }
        printf("\n");
    }
}

void hollowRectangle(int width, int height) {
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++)
            if (row == 0 || row == height - 1 || col == 0 || col == width - 1) {
                printf("x");
            } else {
                printf(" ");
            } 
        printf("\n");
    }
}

void numberedRectangleRows(int width, int height) {
    int number = 0;
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++)
            if (row == 0 || row == height - 1 || col == 0 || col == width - 1) {
                printf("x");
            } else {
                printf("%d", number++ % 10);
            }
        printf("\n");
    }
}

void diagonalRight(int size) {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < row; col++) {
            printf(" ");
        }
        printf("x\n");
    }
}

void diagonalLeft(int size) {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++)
            if (col == size - row - 1) {
                printf("x");
            } else {
                printf(" ");
            } 
        printf("\n");
    }
}

void triangle(int height) {
    int totalWidth = 2 * height - 1;
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < totalWidth; col++) {
            if (row == height - 1) {
                printf("x");
            } else if (col == height - 1 - row || col == height - 1 + row) {
                printf("x");
            } else {
                printf(" ");
            } 
        }
        printf("\n");
    }
}

void letterT(int width, int height) {
    for (int col = 0; col < width; col++) printf("x");
    printf("\n");
    int mid = width / 2;
    for (int row = 1; row < height; row++) {
        for (int col = 0; col < mid; col++) {
            printf(" ");
        }
        printf("x\n");
    }
}

void letterP(int width, int height) {
    int mid = height / 2;
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            if (row == 0 || row == mid) {
                printf("x");
            } else if (col == 0) {
                printf("x");
            } else if (col == width - 1 && row < mid) {
                printf("x");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void numberedRectangleCols(int w, int h) {
    int inner_h = h - 2;
    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            if (r == 0 || r == h - 1 || c == 0 || c == w - 1) {
                printf("x");
            } else {
                int inner_col = c - 1;
                int inner_row = r - 1;
                int value = (inner_col * inner_h + inner_row) % 10;
                printf("%d", value);
            }
        }
        printf("\n");
    }
}