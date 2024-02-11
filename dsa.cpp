#include <iostream>
#include<math.h>
#include<queue>
#include<climits>
using namespace std;

struct node{
    int data;
    node *left,*right;
};
 class heap
 {
     int *a,n,top;
 public:
    heap(int n)
    {
        a=new int[n];
        this->n=n;
        top=0;
    }
    void buildHeap(int b)
    {
        if(top==0)
            a[top++]=b;
        else
        {
             a[top++]=b;
            int j=top-1;
            while(a[j]>a[(j-1)/2] && j!=0)
            {
                int tmp=a[(j-1)/2];
                a[(j-1)/2]=a[j]; a[j]=tmp;
                j=(j-1)/2;
            }

        }
        display();
    }

        void heapsort()
        {
            int currentSize=top-1;
            while(currentSize!=2)
            {
            int tmp=a[0];
            a[0]=a[currentSize];
            a[currentSize--]=tmp;
            int i=0;

            while((a[i]<a[2*i+1] || a[i]<a[2*i+2]) && 2*i+1<currentSize)
            {
                if(a[2*i+2]<a[2*i+1])
                {
                     tmp=a[2*i+1];
                     a[2*i+1]=a[i];
                     a[i]=tmp;
                     i=2*i+1;
                }
                else
                {
                     tmp=a[2*i+2];
                     a[2*i+2]=a[i];
                     a[i]=tmp;
                     i=2*i+2;
                }
            }
            if(a[0]>a[1])
            {
                int tmp=a[1];
                a[1]=a[0];
                a[0]=tmp;
            }
        }
        void display()
        {
            for(int i=0;i<top;i++)
                cout<<a[i]<<" ";
            cout<<endl;

        }

 };
