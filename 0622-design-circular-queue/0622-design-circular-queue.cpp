class MyCircularQueue {
    int *arr;
    int size;
    int front;
    int rear;
public:
    MyCircularQueue(int k) {
        size=k;
        front=-1;
        rear=-1;
        arr=new int[size];
    }
    
    bool enQueue(int value) {

        if(isFull())
        return false;
        else if(front==-1)
        {
            front=0;
            arr[front]=value;
            rear=0;
        }
        else if(rear==size-1 && front!=0)
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
    
    bool deQueue() {

        
        if(isEmpty())
        return false;
        arr[front]=-1;
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else if(front==(size-1))
        {
            front=0;
        }
        else{
            front++;
        }
        // arr[front]=-1;
        return true;
    }
    
    int Front() {
        if(!isEmpty())
        return arr[front];
        else
        return -1;
    }
    
    int Rear() {
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
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */