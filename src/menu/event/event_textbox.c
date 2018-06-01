/*
** EPITECH PROJECT, 2017
** event_textbox
** File description:
** event_textbox
*/

#include "menu.h"
#include "my.h"

int	is_about_textbox(text_box_t *textbox, window_t *window)
{
	sfVector2i pos = sfMouse_getPosition((sfWindow *)window->window);

	if (pos.x < textbox->position.x || (pos.x > textbox->position.x + 300))
		return (0);
	if (pos.y < textbox->position.y || pos.y > textbox->position.y + 100)
		return (0);
	return (1);
}
char	translate_key_in_char(sfKeyCode key)
{
	if (key <= 25)
		return (key + 'a');
	switch (key) {
		case 27: return ('1');
		case 28: return ('2');
		case 29: return ('3');
		case 51: return ('4');
		case 31: return ('5');
		case 56: return ('6');
		case 33: return ('7');
		case 34: return ('8');
		case 35: return ('9');
		case 26: return ('0');
		default: return ('\0');
	}
}
void	action_textbox(text_box_t *textbox, sfKeyCode key)
{
	int len = my_strlen(textbox->str);

	if (len >= SIZE)
		return;
	if (key == 59 && len != 0)
		textbox->str[len - 1] = '\0';
	else
		textbox->str[len] = translate_key_in_char(key);

}
void	event_textbox(menu_t *menu, window_t *window)
{
	sfKeyCode key;

	key = window->event.key.code;
	for (unsigned int i = 0; i != menu->nb_textbox; i++) {
		if (is_about_textbox(&menu->textbox[i], window)) {
			action_textbox(&menu->textbox[i], key);
		}
	}
}
