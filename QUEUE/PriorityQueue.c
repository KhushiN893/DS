#include <stdio.h>
#include <limits.h>
#define MAX 100
int idx = -1, pqVal[MAX], pqPriority[MAX];

int isEmpty()
{
    return idx == -1;
}
int isFull()
{
    return idx == MAX - 1;
}
void enqueue(int data, int priority)
{
    if (!isFull())
    {
        if (idx == -1)
        {
            idx++;
            pqVal[idx] = data;
            pqPriority[idx] = priority;
            return;
        }
        else
        {
            idx++;
            for (int i = idx - 1; i >= 0; i--)
            {
                // shift all items rightwards with higher priority
                // than the element we trying to insert
                if (pqPriority[i] >= priority)
                {
                    pqVal[i + 1] = pqVal[i];
                    pqPriority[i + 1] = pqPriority[i];
                }
                else
                {
                    // insert item just before where
                    // lower priority index was found
                    pqVal[i + 1] = data;
                    pqPriority[i + 1] = priority;
                    break;
                }
            }
        }
    }
}
// returns item with highest priority
int peek()
{
    return idx;
}
void dequeue()
{
    idx--;
}
void display()
{
    for (int i = 0; i <= idx; i++)
    {
        printf("[%d, %d]\t ", pqVal[i], pqPriority[i]);
    }
}
int main()
{
    enqueue(15, 3);
    enqueue(10, 2);
    enqueue(15, 5);
    enqueue(20, 1);
    enqueue(30, 4);

    printf("Before Dequeue : \n");
    display();
    dequeue(); // 20 dequeued
    dequeue(); // 15 dequeued
    printf("\nAfter Dequeue : \n");
    display();

    return 0;
}
