ll merge(int a[], int L, int R){
    ll cnt = 0;

    int mid = (L + R) >> 1;
    int n1 = (mid - L + 1), n2 = (R - mid);

    // int* lft = new int[n1 + 1];  // Dynamic Allocation
    // int* rght = new int[n2 + 1];

    int lft[n1 + 1], rght[n2 + 1];

    for(int i = 1; i <= n1 ; i++){
        lft[i] = a[L + i - 1];
    }
    for(int i = 1; i <= n2; i++){
        rght[i] = a[mid + i];
    }

    int i = 1, j = 1, k = L;

    while(i <= n1 and j <= n2){
        if(lft[i] <= rght[j]){
            a[k++] = lft[i++];
        }else{
            a[k++] = rght[j++];
            cnt += (n1 - i + 1);
        }
    }

    while(i <= n1) a[k++] = lft[i++];

    while(j <= n2) a[k++] = rght[j++];

    // delete[] lft;
    // delete[] rght;

    return cnt;
}

ll mergesort(int a[], int L, int R){
    ll cnt = 0;
    if(R <= L) return 0LL;
    
    int mid = (L + R) >> 1;
    cnt += mergesort(a, L, mid);
    cnt += mergesort(a, mid + 1, R);
    cnt += merge(a, L, R);

    return cnt;
}
