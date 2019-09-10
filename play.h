#ifndef __PLAY__
#define __PLAY__
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "settings.h"

void play (ALLEGRO_EVENT_QUEUE *queue,int screenW,int screenH,struct settings *mis_settings,ALLEGRO_FONT *font_scores);

#endif
