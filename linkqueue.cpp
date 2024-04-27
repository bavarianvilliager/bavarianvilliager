#include <iostream>
using namespace std;

#ifndef QUEUE_H_
#define QUEUE_H_

template <typename T>
class Node
{
    public:
        T data;
        Node * next;
};

template <typename T>
class LinkQueue
{
    private:
        Node<T>* front,*rear;
    public:
        LinkQueue();
        ~LinkQueue();
        bool Isempty() const;
        void LinkQueueClear();
        int LinkQueueLength()const;
        T Getfront();
        void Inqueue(T e);
        T Outqueue();
        void Print();
};

#endif

template <typename T>
LinkQueue<T>::LinkQueue()
{
    front=rear=NULL;
}

template <typename T>
LinkQueue<T>::~LinkQueue()
{
    Node<T>* temp1,*temp2;
    temp1=front;
    while (temp1!=NULL)
    {
        temp2=temp1;
        temp1=temp1->next;
        delete temp2;
    }
}

template <typename T>
bool LinkQueue<T>::Isempty()const
{
    if(front==NULL)
        return true;
    else
        return false;
}

template <typename T>
void LinkQueue<T>::LinkQueueClear()
{
    Node<T>* temp1,*temp2;
    temp1=front;
    while (temp1!=NULL)
    {
        temp2=temp1;
        temp1=temp1->next;
        delete temp2;
    }
    front=rear=NULL;
}

template <typename T>
int LinkQueue<T>::LinkQueueLength()const
{
    int num=0;
    Node<T>* curr;
    curr=front;
    while(curr!=NULL)
    {
        num+=1;
        curr=curr->next;
    }
    return num;
}

template <typename T>
T LinkQueue<T>::Getfront()
{
    return front->data;
}

template <typename T>
void LinkQueue<T>::Inqueue(T e)
{
    Node<T>* temp=new Node<T>;
    temp->data=e;
    temp->next=NULL;
    if (rear==front&&rear==NULL)
    {
        front=rear=temp;
    }
    else
    {
        rear->next=temp;
        rear=temp;
    }
}

template <typename T>
T LinkQueue<T>::Outqueue()
{
    Node<T>* temp;
    temp=front;
    T val=temp->data;
    if (front==NULL)
        cout<<"The queue is empty already"<<endl;
    else
    {
        front=front->next;
        delete temp;
    }
    if(front==NULL)
    {
        rear=NULL;
    }
    return val;
}

template <typename T>
void LinkQueue<T>::Print()
{
    Node<T>* temp;
    temp=front;
    if (front==NULL)
    {
        cout<<"Already empty"<<endl;
        return;
    }
    while(temp!=NULL)
    {
        cout<<temp->data<<' ';
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    LinkQueue<int> queue1;

    if (queue1.Isempty())
    {
        cout<<"The queue is empty now"<<endl;
    }

    for(int i=0;i<3;i++)
    {
        int element;
        cout<<"Please input the value:";
        cin>>element;
        queue1.Inqueue(element);
    }

    cout<<"The first element is "<<queue1.Getfront()<<endl;
    
    queue1.Print();
    
    cout<<"Now delete one element: "<<queue1.Outqueue()<<endl;
    queue1.Print();
    cout<<"Now delete one element: "<<queue1.Outqueue()<<endl;
    queue1.Print();
    cout<<"Now delete one element: "<<queue1.Outqueue()<<endl;
    queue1.Print();
    
    cout<<"The length of it is: "<<queue1.LinkQueueLength()<<endl;
    
    if (queue1.Isempty())
    {
        cout<<"The queue is empty now"<<endl;
    }
    else
    {
        cout<<"The queue is not empty!"<<endl;
    }
    
    queue1.LinkQueueClear();
    if (queue1.Isempty())
    {
        cout<<"The queue is empty now"<<endl;
    }
    else
    {
        cout<<"The queue is not empty!"<<endl;
    }
    return 0;
}
