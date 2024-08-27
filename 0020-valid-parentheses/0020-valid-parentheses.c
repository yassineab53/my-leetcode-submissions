#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct Element
{
    char del;
    struct Element *next;
} Element;
typedef struct Pile
{
    Element *head;
    int taille;
} Pile;

void initialiserPile(Pile *P)
{
    P->head = NULL;
    P->taille = 0;
}
void empiler(Pile *P, Element *nvElem)
{
    nvElem->next = P->head;
    P->head = nvElem;
    P->taille++;
}

void depiler(Pile *P)
{
    Element *tmp = P->head;
    P->head = tmp->next;
    tmp = NULL;
    free(tmp);
    P->taille--;
}
bool isValid(char* str) {
    Pile *P = (Pile *)malloc(sizeof(Pile));
    initialiserPile(P);
    int i = 0;
    bool flag = true;
    Element *dernier = NULL;
    while (str[i] != '\0')
    {
        if (str[i] == '{' || str[i] == '(' || str[i] == '[')
        {
            Element *elm = (Element *)malloc(sizeof(Element));
            elm->del = str[i];
            empiler(P, elm);
            dernier = elm;
        }
        else if (str[i] == '}' || str[i] == ')' || str[i] == ']')
        {
            if (P->taille == 0 || (dernier->del == '{' && str[i] != '}') || (dernier->del == '(' && str[i] != ')') || (dernier->del == '[' && str[i] != ']'))
            {
                flag = false;
                break;
            }
            else
            {
                depiler(P);
                if (P->taille > 0)
                {
                    dernier = P->head;
                }
                else
                {
                    dernier = NULL;
                }
            }
        }
        i++;
    }
    if (P->taille != 0)
        flag = false;

    free(P);
    return flag;
}
