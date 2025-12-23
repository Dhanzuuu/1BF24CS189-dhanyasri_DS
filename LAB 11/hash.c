#include <stdio.h>
#define MAX 20

int hashtable[MAX];
int m;

void insert(int key) {
    int index = key % m;

    for (int i = 0; i < m; i++) {
        int probe = (index + i) % m;
        if (hashtable[index] == -1) {
            hashtable[index] = key;
            return;
        }
    }
}

void display() {
    printf("\nHash table:\n");
    for (int i = 0; i < m; i++) {
        if (hashtable[i] != -1)
            printf("Address %d: %d\n", i, hashtable[i]);
        else
            printf("Address %d: empty\n", i);
    }
}

int main() {
    int n, key;

    printf("Enter the size of hash table (max %d): ", MAX);
    scanf("%d", &m);

    if (m > MAX) {
        printf("Size exceeds maximum limit.\n");
        return 1;
    }

    for (int i = 0; i < m; i++) {
        hashtable[i] = -1;
    }

    printf("Enter the number of employee records: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter key: ");
        scanf("%d", &key);
        insert(key);
    }

    display();
    return 0;
}
