#include<bits/stdc++.h>
using namespace std;
class sorting_time
{    int size=10000;
     int arr[10000];
     public:  void bubble();
              void selection();
              void insertion();
                                          
};
void sorting_time::bubble()
{  for(int i=0 ; i<size ; i++)
      arr[i]=rand()%1000;
   clock_t start=clock();
   for(int i=1 ; i<size-1 ; i++)
   {  int flag=0;
      for(int j=0 ; j<size-1-i ; j++)
      {  if(arr[j]<arr[j+1])
           swap(arr[j],arr[j+1]);
         flag=1;
      }
      if(flag==0)
        break;
   }
   clock_t end=clock();
   cout<<"time taken to sort a data of 10000 entries using optimized bubble sort is:- "<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
}
void sorting_time::selection()
{  for(int i=0 ; i<size ; i++)
      arr[i]=rand()%1000;
   clock_t start=clock();
   for(int i=0 ; i<size-1 ; i++)
   {  int min_index=i;
      for(int j=i+1 ; j<size ; j++)
      {  if(arr[j]<arr[min_index])
           min_index=j;
      }
      if(min_index!=i)
        swap(arr[i],arr[min_index]);
    }
   clock_t end=clock();
   cout<<"time taken to sort a data of 10000 entries using selection sort is:- "<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
}
void sorting_time::insertion()
{  for(int i=0 ; i<size ; i++)
      arr[i]=rand()%1000;
   clock_t start=clock();
   int i=1;
   while(i<size)
   {  int ele=arr[i];
      for(int j=i-1 ; j>=0 ; j--)
      {  if(arr[j]>arr[j+1])
         {  arr[j+1]=arr[j]; 
            arr[j]=ele;
         }
      }
      i++;
   }
   clock_t end=clock();
   cout<<"time taken to sort a data of 10000 entries using insertion sort is:- "<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
}
void merge(int arr[],int beg,int mid,int end)
{  int l1=mid-beg+1,l2=end-mid;
   int left[l1],right[l2];
   for(int m=0 ; m<l1 ; m++)  left[m]=arr[beg+m];
   for(int m=0 ; m<l2 ; m++)  right[m]=arr[mid+m+1];
   int m=0,n=0,k=beg;
   while(m<l1 && n<l2)
   {  if(left[m]<right[n])
        arr[k++]=left[m++];
      else
        arr[k++]=right[n++];
   }
   while(m<l1) {arr[k++]=left[m++];}
   while(n<l2) {arr[k++]=right[n++];}
}
void mergesort(int arr[],int i,int j)
{  if(i<j){
    int mid=(i+j)/2;
    mergesort(arr,i,mid);
    mergesort(arr,mid+1,j);
    merge(arr,i,mid,j);
   }
   else 
    return;
}
int partition(int arr[],int beg,int end)
{  int i=beg-1,j=beg,pivot;
   pivot=arr[end];
   while(j<end)
   {  if(arr[j]<pivot)
      { i++;
        swap(arr[i],arr[j]);
      }
      j++;
   }
   swap(arr[i+1],arr[end]);
   return (i+1);
}
void quicksort(int arr[],int beg,int end)
{  if(beg<end)
   {  int q=partition(arr,beg,end);
      quicksort(arr,beg,q-1);
      quicksort(arr,q+1,end);
   }
}
int main()
{   srand(time(0));
    int a[10000],len=10000;
    for(int i=0 ; i<len ; i++)
       a[i]=rand()%1000;
    sorting_time st;
    st.bubble();
    st.insertion();
    st.selection();
    clock_t start=clock();
    quicksort(a,0,len-1);
    clock_t end=clock();
    cout<<"time taken to sort a data of 10000 entries using quicksort is:- "<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
    start=clock();
    mergesort(a,0,len-1);
    end=clock();
    cout<<"time taken to sort a data of 10000 entries using mergesort is:- "<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}