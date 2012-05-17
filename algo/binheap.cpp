#include<stdio.h>

#define MAX 100
int n;      // input size
int a[MAX]; // input array
int s;      // heap size
int h[MAX]; // heap

void swap(int &a, int &b) {
    int c = a; a = b; b = c;
}

void heapify(int i) {
    if (0 < i and h[i] < h[(i-1)/2]) {
        swap(h[i], h[(i-1)/2]);
        heapify((i-1)/2);
    }
    else if (2*i+2 < s and h[2*i+2] < h[i] and h[2*i+2] < h[2*i+1])  {
        swap(h[i], h[2*i+2]);
        heapify(2*i+2);
    }
    else if (2*i+1 < s and h[2*i+1] < h[i]) {
        swap(h[i], h[2*i+1]);
        heapify(2*i+1);
    }
}

void insert_heap(int b) {
    if (MAX <= s+1) return;
    s++;
    h[s-1] = b;
    heapify(s-1);
}

int delete_heap() {
    if (s <= 0) return -1;
    int ret = h[0];
    h[0] = h[s-1];
    s--;
    heapify(0);
    return ret;
}

void heapsort() {
    for (int i=0;i<n;i++) insert_heap(a[i]);
    for (int i=0;i<n;i++) a[i] = delete_heap();
}

int main () {
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%d", &a[i]);
    for (int i=0;i<n;i++) h[i] = -1;

    heapsort();

    for (int i=0;i<n;i++) printf(" %d", a[i]);
    printf("\n");

    return 0;
}
