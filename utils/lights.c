#include "../mini_rt.h"

void    free_lights(t_light *head)
{
    t_light *tmp;

    while (head)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}
