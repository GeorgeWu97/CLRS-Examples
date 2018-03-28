#include<stdio.h>
int merge_sort(int s[], int l, int r);
int merge(int s[], int l, int q, int r);
int main()
{
    int n,i;
    scanf("%d",&n);
    int a[n];
    for (i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    merge_sort(a, 0, n-1);
    for (i=0;i<n;i++){
        printf("%d ",a[i]);
    }
} 

int merge_sort(int s[], int l, int r)
{
    int q;
    if (l<r){
       q = (l+r)/2;
       merge_sort(s, l, q);
       merge_sort(s, q+1, r);
       merge(s, l, q, r);
    }
    return 0;
}

int merge(int s[], int l, int q, int r)
{
    int i,j,k;
    int L[q-l+2], R[r-q+1];
    i = 0;
    j = 0;
    for (k=l;k<=q;k++){
        L[i] = s[k];
        i++;
    }
    L[i] = 32767;
    j = 0;
    for (k=q+1;k<=r;k++){
        R[j] = s[k];
        j++;
    }
    R[j] = 32767;
    i = 0;
    j = 0;
    while ((i+j)<(r-l+1)){
          if (L[i] > R[j] && j<=r-q){
             s[l+i+j] = R[j];
             j++;
          }
          else if (L[i] <= R[j] && i<=q-l){
               s[l+i+j] = L[i];
               i++;
          }
    }
}
