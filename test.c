#include <stdio.h>

void ft(int *i)
{
    (*i)++;

}

int main ()
{
    int *i = 0;
    ft(i);
    printf("%d",*i);
    return 0;
}

#include <stdio.h>

// Function to increment the value pointed to by i
void ft(int *i)
{
    (*i)++; // Correctly increment the value pointed to by i
}

int main()
{
    int value = 0; // Declare an integer variable
    int *i = &value; // Point i to the address of value

    ft(i); // Pass the pointer to the function
    printf("%d", *i); // Print the updated value

    return 0;
}