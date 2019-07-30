 /*
** EPITECH PROJECT, 2017
** graphic
** File description:
** graphic
*/

#include<SFML/Graphics/Color.h>
#include<SFML/Graphics.h>
#include<stdio.h>
#include<stdlib.h>

sfVector2i analyse_events(const sfRenderWindow *window)
{
	sfVector2i position = sfMouse_getPositionRenderWindow(window);
	
	return(position);
}

int display_background()
{
	sfVideoMode mode ={800, 600, 32};
	sfRenderWindow* window;
	sfTexture* texturebackground;
	sfTexture* textureDuck;
	sfSprite* spritebackground;
	sfSprite* spriteDuck;
	sfEvent event;
	sfClock* clock;
	sfTime time;
        float seconds;   
	sfIntRect rect;
	sfVector2i position;
	sfVector2f pos;
	float faster;

	rect.top = 0;
	rect.left = 0;
	rect.width = 110;
	rect.height = 110;

	window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);

	if(!window)
		return(0);
	texturebackground = sfTexture_createFromFile("background.png", NULL);
	if(!texturebackground)
		return(0);
	textureDuck = sfTexture_createFromFile("spritesheet.png", NULL);
	if(!textureDuck)
		return(0);
	
	spritebackground = sfSprite_create();
	spriteDuck = sfSprite_create();
        sfSprite_setTexture(spritebackground, texturebackground, sfTrue);
	sfSprite_setTexture(spriteDuck, textureDuck, sfTrue);
	sfSprite_setTextureRect(spriteDuck, rect);

	clock = sfClock_create();

        sfRenderWindow_setFramerateLimit(window, 300);

	while(sfRenderWindow_isOpen(window)){		
		while (sfRenderWindow_pollEvent(window, &event)){
			if(event.type == sfEvtMouseButtonPressed){
				position = analyse_events(window);
			}
			if(event.type == sfEvtClosed)
				sfRenderWindow_close(window);
		}
		
		sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_drawSprite(window, spritebackground, NULL);
		sfRenderWindow_drawSprite(window, spriteDuck, NULL);
		sfRenderWindow_display(window);

		if(pos.x >= 800){
			pos.x = -1;
			pos.y = rand()%540;
		}
		
		else
			pos.x = pos.x + 1 + faster;
		
		if(position.x >= pos.x  && position.x <= pos.x + 110 && position.y >= pos.y && position.y <= pos.y + 110){
                        pos.x = 0;
                        pos.y = rand()%540;
			faster = faster + 0.2f;

                        sfSprite_setPosition(spriteDuck, pos);
                }
		else if(pos.y >= 550)
			pos.y = 50;
		position.x = 0;
		sfSprite_setPosition(spriteDuck, pos);
		
		time = sfClock_getElapsedTime(clock);
		seconds = time.microseconds / 1000000.0;
		
		if(seconds > 0.2f){
			if(rect.left >= 220)
				rect.left = 0;
			else
				rect.left += 110;
			rect.top = 0;
			rect.width = 110;
			rect.height = 110;
			sfSprite_setTextureRect(spriteDuck, rect);

			sfClock_restart(clock);
		}		
	}

	sfSprite_destroy(spritebackground);
	sfSprite_destroy(spriteDuck);
	sfTexture_destroy(texturebackground);
	sfTexture_destroy(textureDuck);
	sfRenderWindow_destroy(window);
	return(1);
}

	int main()
	{
		display_background();
		return(1);
	}
