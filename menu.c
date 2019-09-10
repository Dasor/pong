#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "settings.h"
#include "play.h"

void menu(ALLEGRO_EVENT_QUEUE *queue,ALLEGRO_FONT *font200,ALLEGRO_FONT *font100,int screenW,int screenH,ALLEGRO_FONT *font75, struct settings *mis_settings, ALLEGRO_FONT *font_score){
   int posicion_menu=0;
   bool exit = false;

   ALLEGRO_COLOR amarillo = al_map_rgb(227,209,10);
   ALLEGRO_COLOR blanco = al_map_rgb(255,255,255);

   al_clear_to_color(al_map_rgb(0,0,0));
   al_draw_text(font200, blanco, screenW/2, 0,ALLEGRO_ALIGN_CENTRE, "PONG");
   al_draw_text(font100, blanco, screenW/2, screenH/3,ALLEGRO_ALIGN_CENTRE, "Play");
   al_draw_text(font100, blanco, screenW/2, screenH/2,ALLEGRO_ALIGN_CENTRE, "Settings");
   al_draw_text(font100, blanco, screenW/2, (float)screenH/1.5,ALLEGRO_ALIGN_CENTRE, "Exit");
   al_flip_display();

   // Bucle general //
   ALLEGRO_EVENT ev;
   while(!exit) {
     // Recibir eventos //
     al_wait_for_event(queue, &ev);
     if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
       if(ev.keyboard.keycode == ALLEGRO_KEY_RIGHT || ev.keyboard.keycode == ALLEGRO_KEY_ENTER) {
         if(posicion_menu==1){ play(queue,screenW,screenH,mis_settings,font_score); }
         if(posicion_menu==2){settings(queue,font200,font100,screenW,screenH,font75,mis_settings);}
         if(posicion_menu==3){exit=true;} 
       }

       if(ev.keyboard.keycode == ALLEGRO_KEY_DOWN) {
         if(posicion_menu <= 2) posicion_menu++;
       }
       if(ev.keyboard.keycode == ALLEGRO_KEY_UP) {
         if(posicion_menu >= 2) posicion_menu--;
       }
       if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) exit = true; 
     
     
    
       // Dibujar //
       al_clear_to_color(al_map_rgb(0,0,0));
       al_draw_text(font200, blanco, screenW/2, 0,ALLEGRO_ALIGN_CENTRE, "PONG");

       if(posicion_menu == 0) {
         al_draw_text(font100, blanco, screenW/2, screenH/3,ALLEGRO_ALIGN_CENTRE, "Play");
         al_draw_text(font100, blanco, screenW/2, screenH/2,ALLEGRO_ALIGN_CENTRE, "Settings");
         al_draw_text(font100, blanco, screenW/2, (float)screenH/1.5,ALLEGRO_ALIGN_CENTRE, "Exit");
       }
       if(posicion_menu == 1) {
         al_draw_text(font100, amarillo, screenW/2, screenH/3,ALLEGRO_ALIGN_CENTRE, "Play");
         al_draw_text(font100, blanco, screenW/2, screenH/2,ALLEGRO_ALIGN_CENTRE, "Settings");
         al_draw_text(font100, blanco, screenW/2, (float)screenH/1.5,ALLEGRO_ALIGN_CENTRE, "Exit");
       }
       if(posicion_menu == 2) { 
         al_draw_text(font100, blanco, screenW/2, screenH/3,ALLEGRO_ALIGN_CENTRE, "Play");
         al_draw_text(font100, amarillo, screenW/2, screenH/2,ALLEGRO_ALIGN_CENTRE, "Settings");
         al_draw_text(font100, blanco, screenW/2, (float)screenH/1.5,ALLEGRO_ALIGN_CENTRE, "Exit");
       }
       if(posicion_menu == 3) {
         al_draw_text(font100, blanco, screenW/2, screenH/3,ALLEGRO_ALIGN_CENTRE, "Play");
         al_draw_text(font100, blanco, screenW/2, screenH/2,ALLEGRO_ALIGN_CENTRE, "Settings");
         al_draw_text(font100, amarillo, screenW/2, (float)screenH/1.5,ALLEGRO_ALIGN_CENTRE, "Exit");
       }
     
       al_flip_display();
     }
  }  
}
