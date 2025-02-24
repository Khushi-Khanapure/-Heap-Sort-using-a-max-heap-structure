#include<iostream>
#include<stdlib.h>
using namespace std;
#define SIZE 10

class HeapSort
{
    private:
        int Heap[SIZE],n;
    public:
        void getN();
        void get();
        void put();
        void sort();
        void create();
        void downAdj(int i);
};
void HeapSort::getN()
{
    cout<<"\n\t Enter the value of n :";
    cin>>n;
}
void HeapSort::get()
{
    for(int i=1;i<=n;i++)
    {
        cout<<"\n\t Enter the Array Element :";
        cin>>Heap[i];
    }
}
void HeapSort::put()
{
    cout<<"\n\t Array Element Are :";
    for(int i=1;i<=n;i++)
    {
        cout<<" "<<Heap[i];
    }
}
void HeapSort::sort()
{
    Heap[0]=n;
    create();
    while(Heap[0]>1)
    {
        int last=Heap[0];
        int temp=Heap[1];
        Heap[1]=Heap[last];
        Heap[last]=temp;
        Heap[0]--;
        downAdj(1);
    }
}
void HeapSort::create()
{
    int x=Heap[0];
    for(int i=x/2;i>1;i--)
    {
        downAdj(i);
    }
}
void HeapSort::downAdj(int i)
{
    int x=Heap[0];
    int flag=1,j;
    while(2*i<=x && flag==1)
    {
        j=2*i;
        if(j+1<=x && Heap[j+1]>=Heap[j])
        {
            j=j+1;
        }
        if(Heap[i]>Heap[j])
        {
            flag=0;
        }
        else
        {
            int temp=Heap[i];
            Heap[i]=Heap[j];
            Heap[j]=temp;
            i=j;
        }
    }
}
int main()
{
    HeapSort obj;
    system("cls");
    obj.getN();
    obj.get();
    cout<<"\n\t Unsorted Array :";
    obj.put();
    obj.sort();
    cout<<"\n\t Sorted Array :";
    obj.put();
    return 0;
}