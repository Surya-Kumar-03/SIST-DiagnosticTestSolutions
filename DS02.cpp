#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int top;
    unsigned capacity;
    int *array;
};


Stack *createStack(unsigned capacity)
{
    Stack *stack = new Stack();

    if (!stack)
        return NULL;

    stack->top = -1;
    stack->capacity = capacity;
    stack->array = new int[(stack->capacity * sizeof(int))];

    if (!stack->array)
        return NULL;

    return stack;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

int peek(Stack *stack)
{
    return stack->array[stack->top];
}

int pop(Stack *stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}

void push(Stack *stack, int op)
{
    stack->array[++stack->top] = op;
}


int evaluatePostfix(string exp)
{
    Stack *stack = createStack(exp.length());
    int i;

    for (i = 0; exp[i]; ++i)
    {
        if (exp[i] == ' ')
            continue;

        else if (isdigit(exp[i]))
        {
            int num = 0;

            while (isdigit(exp[i]))
            {
                num = num * 10 + (int)(exp[i] - '0');
                i++;
            }
            i--;

            push(stack, num);
        }

        else
        {
            int val1 = pop(stack);
            int val2 = pop(stack);

            switch (exp[i])
            {
            case '+':
                push(stack, val2 + val1);
                break;
            case '-':
                push(stack, val2 - val1);
                break;
            case '*':
                push(stack, val2 * val1);
                break;
            case '/':
                push(stack, val2 / val1);
                break;
            }
        }
    }
    return pop(stack);
}

int main()
{
    string exp;
    getline(cin, exp);
    cout << evaluatePostfix(exp);
    return 0;
}


//2nd qn
// C++ program to find sum of
// all paths from root to leaves
#include <bits/stdc++.h>
using namespace std;

class node
{
	public:
	int data;
	node *left, *right;
};

// function to allocate new node with given data
node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = Node->right = NULL;
	return (Node);
}

// Returns sum of all root to leaf paths.
// The first parameter is root
// of current subtree, the second
// parameter is value of the number formed
// by nodes from root to this node
int treePathsSumUtil(node *root, int val)
{
	// Base case
	if (root == NULL) return 0;

	// Update val
	val = (val + root->data);

	// if current node is leaf, return the current value of val
	if (root->left==NULL && root->right==NULL)
	return val;

	// recur sum of values for left and right subtree
	return treePathsSumUtil(root->left, val) +
		treePathsSumUtil(root->right, val);
}

// A wrapper function over treePathsSumUtil()
int treePathsSum(node *root)
{
	// Pass the initial value as 0
	// as there is nothing above root
	return treePathsSumUtil(root, 0);
}

int main()
{
	node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	cout<<"Sum of all paths is "<<treePathsSum(root);
	return 0;
}


