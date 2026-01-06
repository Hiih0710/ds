#include <stdio.h>
#include <conio.h>
#define size 5

int top = -1;
int stack[size];

void push()
{
    if (top == size - 1)
    {
        printf("stack overflow\n");
    }
    else
    {
        int e;
        printf("enter the element to be added \n ");
        scanf("%d", &e);
        top++;
        stack[top] = e;
        printf("element added success =%d \n", stack[top]);
        printf("top now is %d \n", top);
    }
} // push closed

void pop()
{
    if (top == -1)
    {
        printf("stack underflow\n");
    }
    else
    {
        printf("element poped is %d \n", stack[top]);
        stack[top] = 0;
        top--;
    }
}

void display()
{
    printf("------------- \n");
    int i;

    for (i = 0; i <= top; i++)
    {
        printf("%d \n", stack[i]);
    }
}

int main()
{
    int c;
    int running = 1;

    while (running)
    {
        printf("\n1.pop the element\n2.Push the element\n3.Show\n4.End\n");
        printf("enter what do you want to perform \n");
        scanf("%d", &c);

        switch (c)
        {
        case 1:
            pop();
            break;

        case 2:
            push();
            break;

        case 3:
            display();
            break;

        case 4:
            running = 0;   /* loop se bahar nikal jaayega */
            break;

        default:
            printf("invalid \n");
            break;
        }
    }

    return 0;
}
