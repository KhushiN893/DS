#include <stdio.h>
#include <stdlib.h>

struct term
{
    int coefficient;
    int exponent;
    struct term *next;
};

struct term *create_term(int coefficient, int exponent)
{
    struct term *new_term = (struct term *)malloc(sizeof(struct term));
    new_term->coefficient = coefficient;
    new_term->exponent = exponent;
    new_term->next = NULL;
    return new_term;
}

void insert_term(struct term **poly, int coefficient, int exponent)
{
    struct term *current = *poly;
    struct term *prev = NULL;
    while (current != NULL && exponent < current->exponent)
    {
        prev = current;
        current = current->next;
    }
    struct term *new_term = create_term(coefficient, exponent);
    if (prev == NULL)
    {
        new_term->next = current;
        *poly = new_term;
    }
    else
    {
        prev->next = new_term;
        new_term->next = current;
    }
}

struct term *add_polynomials(struct term *poly1, struct term *poly2)
{
    struct term *result = NULL;
    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->exponent > poly2->exponent)
        {
            insert_term(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        }
        else if (poly1->exponent < poly2->exponent)
        {
            insert_term(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        }
        else
        {
            int coefficient = poly1->coefficient + poly2->coefficient;
            if (coefficient != 0)
            {
                insert_term(&result, coefficient, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL)
    {
        insert_term(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }
    while (poly2 != NULL)
    {
        insert_term(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }
    return result;
}

void print_polynomial(struct term *poly)
{
    while (poly != NULL)
    {
        printf("%da^%d", poly->coefficient, poly->exponent);
        poly = poly->next;
        if (poly != NULL)
        {
            printf(" + ");
        }
    }
    printf("\n");
}

int main()
{
    struct term *poly1 = NULL;
    insert_term(&poly1, 3, 5);
    insert_term(&poly1, 2, 3);
    insert_term(&poly1, 1, 1);
    printf("1] : ");
    print_polynomial(poly1);

    struct term *poly2 = NULL;
    insert_term(&poly2, 3, 5);
    insert_term(&poly2, 2, 4);
    insert_term(&poly2, 1, 1);
    printf("2] : ");
    print_polynomial(poly2);
    printf("Addition : ");
    struct term *poly3 = add_polynomials(poly1, poly2);
    print_polynomial(poly3);
    return 0;
}
