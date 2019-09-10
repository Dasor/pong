#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <unistd.h>
#include "settings.h"


void final(int jugador_ganador,int score1,int score2,int screenW,int screenH,ALLEGRO_FONT *font_score){
ALLEGRO_COLOR blanco = al_map_rgb(255,255,255);
  if(jugador_ganador==1){
    al_clear_to_color(al_map_rgb(0,0,0));
    al_draw_textf(font_score,blanco,screenW/2+screenW/4-75,0,0,"%d",score2);
    al_draw_textf(font_score,blanco,screenW/2-screenW/4,0,0,"%d",score1);
    al_draw_text(font_score,blanco,screenW/2-screenW/3.5,screenH/2,0,"Player 1 Wins");
    al_flip_display();
    sleep(5);
    }
  if(jugador_ganador==2){
    al_clear_to_color(al_map_rgb(0,0,0));
    al_draw_textf(font_score,blanco,screenW/2+screenW/4-75,0,0,"%d",score2);
    al_draw_textf(font_score,blanco,screenW/2-screenW/4,0,0,"%d",score1);
    al_draw_text(font_score,blanco,screenW/2-screenW/3.5,screenH/2,0,"Player 2 Wins");  
    al_flip_display();
    sleep(5);
    }
   
  
}


