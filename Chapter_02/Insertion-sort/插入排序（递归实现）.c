#include<stdio.h>
int insort(int s[], int tail){
    if (tail>0){
       insort(s, tail-1);
       insort_pro(s, tail);
    }
}
int insort_pro(int s[], int tail){
    int i, k, j;
    for (i=0;i<tail;i++){
        if (s[i]>s[tail]){
           k = s[tail];
           for (j=tail;j>i;j--){
               s[j] = s[j-1];
           }
           s[i] = k;
           break;
        }
    }
}
int main()
{
    int n,i;
    scanf("%d",&n);
    int a[n];
    for (i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    insort(a, n-1);
    for (i=0;i<n;i++){
    	printf("%d ",a[i]);
	}
} 
