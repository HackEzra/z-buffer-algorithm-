#include <iostream>
#define MAX 100

using namespace std;

int queue[MAX];
int front = -1;
int rear = -1;
int zBuffer[MAX];

void enqueueAtRear(int data)
{
    if((rear + 1) % MAX == front)
    {
        cout<<"Error: Queue is full"<<endl;
        return;
    }
    if(front == -1)
        front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = data;
    cout<<data<<" added to the queue"<<endl;
}

void dequeueAtFront(int &front)
{
    if(front == -1)
    {
        cout<<"Error: No element in the queue"<<endl;
        return;
    }
    int data = queue[front];
    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
        front = (front + 1) % MAX;
    cout<<data<<" dequeued from queue"<<endl;
}

void initZBuffer()
{
    for (int i = 0; i < MAX; i++)
        zBuffer[i] = -1;
}

void updateZBuffer(int data, int position)
{
    if (position >= MAX)
    {
        cout << "Error: Position exceeds the size of the Z-buffer" << endl;
        return;
    }
    if (zBuffer[position] != -1)
        cout << "Warning: Overwriting existing value in the Z-buffer" << endl;
    zBuffer[position] = data;
    cout << data << " added to the Z-buffer at position " << position << endl;
}

void removeFromZBuffer(int position)
{
    if (position >= MAX)
    {
        cout << "Error: Position exceeds the size of the Z-buffer" << endl;
        return;
    }
    if (zBuffer[position] == -1)
    {
        cout << "Error: No element found in the Z-buffer at position " << position << endl;
        return;
    }
    zBuffer[position] = -1;
    cout << "Removed element from the Z-buffer at position " << position << endl;
}

int main()
{
    initZBuffer();
    int option, data, position;

    while (true)
    {
        cout << "1. Add car to the garage" << endl;
        cout << "2. Remove car from the garage" << endl;
        cout << "3. View Z-buffer" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your option: ";
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Enter the data: ";
            cin >> data;
            enqueueAtRear(data);
            cout << "Enter the position in the Z-buffer: ";
            cin >> position;
            updateZBuffer(data, position);
            break;
        case 2:
            dequeueAtFront(front);
            cout << "Enter the position in the Z-buffer: ";
            cin >> position;
            removeFromZBuffer(position);
            break;
        case 3:
            cout << "Z-buffer: [ ";
            for (int i = 0; i < MAX; i++)
                cout << zBuffer[i] << " ";
            cout << "]" << endl;
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid option, try again." << endl;
            break;
        }
    }
    return 0;
}
