class MyCircularDeque {
public:
    int *arr;
    int front;
    int rear;
    int size;
    MyCircularDeque(int k) {
        size=k;
        front=-1;
        rear=-1;
        arr=new int[size];
    }
    
    bool insertFront(int value) {
        if(isFull())
        return false;
        if(front==-1)
        {
            front=rear=0;
            arr[rear]=value;
        }
        else if(front==0)
        {
            front=size-1;
            arr[front]=value;
        }
        else{
            front=front-1;
            arr[front]=value;
        }
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull())
        return false;
        else if(front==-1)
        {
            front=rear=0;
            arr[rear]=value;
        }
        else if(rear==size-1)
        {
            rear=0;
            arr[rear]=value;
        }
        else
        {
            rear++;
            arr[rear]=value;
        }
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty())
        return false;

        arr[front]=-1;
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else if(front==size-1)
        {
            front=0;
        }
        else
        {
            front++;
        }
        return true;
    }
    
    bool deleteLast() {
         if(isEmpty())
        return false;

        arr[rear]=-1;
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else if(rear==0)
        {
            rear=size-1;
        }
        else{
            rear--;
        }
        return true;
    }
    
    int getFront() {
        if(!isEmpty())
        return arr[front];
        else
        return -1;
    }
    
    int getRear() {
         if(!isEmpty())
        return arr[rear];
        else
        return -1;
    }
    
    bool isEmpty() {
        if(front==-1)
        return true;
        else
        return false;
    }
    
    bool isFull() {
        if(front==0 && rear==size-1 || rear==front-1)
        return true;
        else
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */