void QuickSort(int a[],int start,int end) { 
  int q; 
  if (end-start<2) return; 
  q=HoarePartition(a,start,end); 
  QuickSort(a,start,q); 
  QuickSort(a,q,end); 

 }
int HoarePartition (int a[],int p, int r) { 
  int x=a[p],i=p-1,j=r; 
  while (1) { 
  do  j--; while (a[j] > x); 
  do  i++; while (a[i] < x); 
  if  (i < j) swap(&a[i],&a[j]); 
  else return j+1; 
  } 
 }