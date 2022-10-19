//1st Question
#include <stdio.h>
#include <string.h>

struct stud
{
    int id;
    char name[50];
    int age;
} s[100];

int main()
{
    struct stud t;
    int i = 0, j = 0, n;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &s[i].id);
        scanf("%s", s[i].name);
        scanf("%d", &s[i].age);
    }
    printf("Unsorted Student Records\n");
    for (i = 0; i < n; i++)
    {
        printf("Id = %d, Name = %s, Age = %d \n", s[i].id, s[i].name, s[i].age);
    }

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(s[i].name, s[j].name) > 0)
            {
                t = s[i];
                s[i] = s[j];
                s[j] = t;
            }
        }
    }
    printf("After Sorting\n");
    for (i = 0; i < n; i++)
    {
        printf("Id = %d, Name = %s, Age = %d \n", s[i].id, s[i].name, s[i].age);
    }
    return 0;
}

//2nd Question
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    int k = 5;

    for (int i = k; i < n; i++)
    {
        printf("%d ", array[i]);
    }

    for (int i = 0; i < k; i++)
    {
        printf("%d ", array[i]);
    }
}
