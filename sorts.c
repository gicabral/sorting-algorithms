#include <stdio.h>

void bubble_sort(int v[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int swapped = 0;

        for (int j = 0; j < i; j++) {
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                swapped = 1;
            }
        }

        if (!swapped) {
            break;
        }

        printf("[");
        for (int i = 0; i < n; i++) {
            if (i == n - 1) printf("%d]\n", v[i]);
            else printf("%d, ", v[i]);
        }
    }
}

void selection_sort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int m = i;

        for (int j = i + 1; j < n; j++) {
            if (v[m] > v[j]) {
                m = j;
            }
        }

        if (m != i) {
            int temp = v[m];
            v[m] = v[i];
            v[i] = temp;
        }

        printf("[");
        for (int i = 0; i < n; i++) {
            if (i == n - 1) printf("%d]\n", v[i]);
            else printf("%d, ", v[i]);
        }
    }
}

void insertion_sort(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int temp = v[i];

        int h = i;
        while (h > 0 && temp < v[h - 1]) {
            v[h] = v[h - 1];
            h--;
        }

        v[h] = temp;

        printf("[");
        for (int i = 0; i < n; i++) {
            if (i == n - 1) printf("%d]\n", v[i]);
            else printf("%d, ", v[i]);
        }
    }
}

void combine(int v[], int temp[], int l, int m, int r) {
    int i = l;
    int j = m + 1;
    int k;

    for (k = l; k <= r; k++) {
        if (i > m) {
            temp[k] = v[j];
            j++;
        } else if (j > r) {
            temp[k] = v[i];
            i++;
        } else if (v[i] > v[j]) {
            temp[k] = v[j];
            j++;
        } else {
            temp[k] = v[i];
            i++;
        }

        // Printa o i, j e temp de acordo com as informações dadas no
        // enunciado da questão.
        if (l == 0 && m == 2 && r == 5) {
            printf("i = %d; j = %d; temp = [", i , j);
            for (int index = 0; index <= k; index++) {
                if (index == k) {
                    printf("%d]\n", temp[index]);
                } else {
                    printf("%d, ", temp[index]);
                }
            }
        }
    }

    for (k = l; k <= r; k++) {
        v[k] = temp[k];
    }
}

void merge_sort_r(int v[], int temp[], int l, int r) {
    if (l == r) {
        return;
    }
    int m = (l + r) / 2;
    merge_sort_r(v, temp, l, m);
    merge_sort_r(v, temp, m + 1, r);
    combine(v, temp, l, m, r);
}

void merge_sort(int v[], int n) {
    int temp[n];
    merge_sort_r(v, temp, 0, n - 1);
}

int partition(int v[], int l, int r) {
    int p = l;

    for (int i = l; i < r; i++) {
        if (v[i] < v[r]) {
            if (p != i) {
                int temp = v[p];
                v[p] = v[i];
                v[i] = temp;
            }
            p++;
        }

        // Printa o p, i e o v de acordo com as informações dadas no
        // enunciado da questão.
        if (l == 0 && r == 5) {
            printf("p = %d; i = %d; v = [", p , i + 1);
            for (int index = l; index <= r; index++) {
                if (index == r) {
                    printf("%d]\n", v[index]);
                } else {
                    printf("%d, ", v[index]);
                }
            }
        }
    }

    if (p != r) {
        int temp = v[p];
        v[p] = v[r];
        v[r] = temp;
    }

    return p;
}

void quick_sort_r(int v[], int l, int r) {
    if (l >= r) {
        return;
    }
    int p = partition(v, l, r);
    quick_sort_r(v, l, p - 1);
    quick_sort_r(v, p + 1, r);
}

void quick_sort(int v[], int n) {
    quick_sort_r(v, 0, n - 1);
}

void printArray(int* arr, int n) {
    printf("Array: [");
    for (int i = 0; i < n; i++) {
        if (i < n - 1) printf("%d, ", arr[i]);
        if (i == n - 1) printf("%d]\n", arr[i]);
    }
}

int main() {
    // BUBBLE SORT
    // Não esqueça de colocar os tamanhos corretamente!
    int array_bubble_sort[5] = {5, 2, 4, 6, 3};
    
    printf("\nBubble Sort:\n");
    printArray(array_bubble_sort, 5);
    bubble_sort(array_bubble_sort, 5);
    printArray(array_bubble_sort, 5);

    // SELECTION SORT
    // Não esqueça de colocar os tamanhos corretamente!
    int array_selection_sort[5] = {5, 2, 4, 6, 3};
    
    printf("\nSelection Sort:\n");
    printArray(array_selection_sort, 5);
    selection_sort(array_selection_sort, 5);
    printArray(array_selection_sort, 5);

    // INSERTION SORT
    // Não esqueça de colocar os tamanhos corretamente!
    int array_insertion_sort[5] = {5, 2, 4, 6, 3};
    
    printf("\nInsertion Sort:\n");
    printArray(array_insertion_sort, 5);
    insertion_sort(array_insertion_sort, 5);
    printArray(array_insertion_sort, 5);

    // MERGE SORT
    // Não esqueça de colocar os tamanhos corretamente!
    int array_merge_sort[6] = {2, 4, 6, 3, 5, 7};

    printf("\nMerge Sort:\n");
    printArray(array_merge_sort, 6);
    merge_sort(array_merge_sort, 6);
    printArray(array_merge_sort, 6);

    // QUICK SORT
    // Não esqueça de colocar os tamanhos corretamente!
    int array_quick_sort[6] = {7, 2, 5, 3, 6, 4};

    printf("\nQuick Sort Sort:\n");
    printArray(array_quick_sort, 6);
    quick_sort(array_quick_sort, 6);
    printArray(array_quick_sort, 6);
}
