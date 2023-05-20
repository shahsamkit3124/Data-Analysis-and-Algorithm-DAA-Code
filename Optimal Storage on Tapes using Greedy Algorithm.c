// Q8 Greedy Tapes

#include <stdio.h>

int i, j, n, t = 1;
int p[30], l[30], temp, m, tape[10][30];

float mrt[10];

void getval() {
    printf("Enter number of programs: ");
    scanf("%d",&n);

    for (i = 0; i < n; i++) {
        printf("Enter length of program %d: ", i + 1);
        scanf("%d",&l[i]);
        p[i] = i;
    }
    printf("\n");
}

void sort() {
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            if (l[j] > l[j + 1]) {
                temp = l[j];
                l[j] = l[j + 1];
                l[j + 1] = temp;

                m = p[j];
                p[j] = p[j + 1];
                p[j + 1] = m;
            }
        }
    }

    for (i = 0; i < n; i++) {
        printf("program %d\tlength %d\n", (p[i]+1), l[i]);
    }
}

void arrange() {
    int count = 0;
    int r = 0;
    for (i = 0; i < n; i++) {
        tape[t][r] = l[i];
        r++;
    }
}

void printtape() {
    int r = 0;
    printf("\ntape %d: ", t);
    while (tape[t][r] != 0) {
        printf("%d\t", tape[t][r]);
        r++;
    }
    printf("\n");
}

void calmrt() {
    int r, k;
    float sum = 0;
    r = 0;
    for (j = 0; j < n; j++) {
        for (k = 0; k <= j; k++) {
            sum += tape[t][k];
        }
        r++;
    }
    printf("Minimum storage length is: %.0f\n",sum);
}

int main() {
    getval();
    sort();
    arrange();
    printtape();
    calmrt();

    return 0;
}

