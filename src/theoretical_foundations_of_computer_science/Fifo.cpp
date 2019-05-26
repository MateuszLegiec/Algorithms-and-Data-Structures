#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

struct el_FIFO
{
    int x;
    struct el_FIFO *next;
}

struct FIFO
{
    struct el_FIFO *head;
    struct el_FIFO *tail;
}

struct FIFO* push(struct FIFO *qqe, int el)
{
    struct el_FIFO *new_el = (struct el_FIFO*)malloc(sizeof(struct el_FIFO));
    new_el->x=el;
    new_el->next=NULL;
    if (qqe -> head == NULL)
    {
        qqe->head=new_el;
        qqe->tail=new_el;
    }
    else
    {
        qqe->tail->next=new_el;
        qqe->tail=new_el;
    }
}

struct FIFO* pop(struct FIFO *qqe)
{
    struct el_FIFO *temp;
    if (qqe-> head != NULL)
    {
        if (qqe-> head == qqe-> tail)
        {
            qqe-> head = NULL;
            qqe-> tail = NULL;

        }
        else
        {
            temp = qqe->head->next;
            free (qqe->head);
            qqe-> head= temp;
        }
    }
}
struct FIFO* display(struct FIFO *qqe)
{
    if (qqe-> head == NULL)
        cout<<"Fifo is empty"<<endl;
    else
    {
        struct FIFO *temp = (struct FIFO*)malloc(sizeof(struct FIFO));
        temp-> head = NULL;
        temp-> tail = NULL;
        while(qqe-> head != NULL){
            cout<<qqe->head->x;<<",";
            push(temp,qqe->head->x);
            pop(qqe);
        }
        cout<<endl;
        *qqe=*temp;
        free(temp);
    }
}

