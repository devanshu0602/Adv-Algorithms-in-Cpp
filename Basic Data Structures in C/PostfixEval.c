#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int Stack[20];
int top = -1;

void Push(int num)
{
    Stack[++top] = num;
}

int Pop()
{
    return Stack[top--];
}

int main()
{
    char Postfix[20];
    char *ch;
    int op1, op2, n, num;

    printf("Enter the Postfix expression -> ");
    scanf("%s", Postfix);
    
    ch = Postfix;

    while (*ch != '\0')
    {
        if (isdigit(*ch))
        {
            num = *ch - 48;
            Push(num);
        }
        else
        {
            op1 = Pop();
            op2 = Pop();
            switch (*ch)
            {
                case '+':
                    n = op1 + op2;
                    break;
                case '-':
                    n = op2 - op1;
                    break;
                case '*':
                    n = op1 * op2;
                    break;
                case '/':
                    n = op2 / op1;
                    break;
            }
            Push(n);
        }
        ch++;
    }
    printf("\nEvaluated answer =  %d\n", Pop());

    printf("\n");
    printf("Devanshu Gupta 21BCE0597");
    return 0;
}