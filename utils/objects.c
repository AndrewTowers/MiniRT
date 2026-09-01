/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andtruji <andtruji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 11:52:32 by andtruji          #+#    #+#             */
/*   Updated: 2026/09/01 18:53:10 by andtruji         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "mini_rt.h"

t_object    *new_object(t_figures type, void *figure)
{
    t_object    *obj;

    obj = malloc(sizeof(t_object));
    if (!obj)
        return (NULL);
    obj->type = type;
    obj->figure = figure;
    obj->next = NULL;
    return obj;
}

void    add_object(t_object **head, t_object *new_obj)
{
    t_object    *current;

    if (!head || !new_obj)
        return;
    if (*head == NULL)
        *head = new_obj;
    else
    {
        current = *head;
        while (current->next != NULL)
            current = current->next;
        current->next = new_obj;
    }
}

void    free_objects(t_object *head)
{
    t_object    *curr;

    while (head != NULL)
    {
        curr = head;
        head = head->next;
        if (curr->figure)
            free(curr->figure);
        free(curr);
    }
}
