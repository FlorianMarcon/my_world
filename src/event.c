/*
** EPITECH PROJECT, 2017
** event
** File description:
** event
*/


int	event()
{
	while (sfRenderWindow_pollEvent(win->window, &win->event)) {
		if (win->event.type == sfEvtClosed)
			sfRenderWindow_close(win->window);
		if (win->event.type)
	}
}
