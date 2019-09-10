#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "menu.h"
#include "settings.h"

#define DIR_FUENTES "Fuentes"
#define FUENTE_MENU "FutureMillennium.ttf"
#define FUENTE_SCORE "RobotCrush.ttf"

int main() {
ALLEGRO_TIMER *tempo;
   if(!al_init()){
      printf("Failed to initialize Allegro.\n");
      return -1;
   }

  
 
   if(!al_install_keyboard()){
     printf("Failed to initialize Keyboard.\n");
     return -1;
   }

   tempo=al_create_timer(1.0/60);
   if(tempo==NULL){
     printf("no funca el timer\n");
     return -1;
   }
   al_start_timer(tempo);

   ALLEGRO_EVENT_SOURCE *keyboard_event;
   keyboard_event=al_get_keyboard_event_source();
   if(keyboard_event==NULL){
     printf("Failed to get keyboard event source.\n");
     return -1;
   }
   ALLEGRO_EVENT_SOURCE *tempo_event;
   tempo_event=al_get_timer_event_source(tempo);
   if(tempo_event==NULL){
     printf("Failed to get timer event source.\n");
     return -1;
   }

   ALLEGRO_EVENT_QUEUE *queue;
   queue=al_create_event_queue();
   if(queue==NULL){
     printf("Failed to create event queue.\n");
     return -1;
   }

   if(!al_init_font_addon()){
     printf("Failed to initialize font addon.\n");
     return -1;
   } 
   if(!al_init_ttf_addon()){
     printf("Failed to initialize ttf addon.\n");
     return -1;
   }
  
   ALLEGRO_DISPLAY_MODE disp_data;
   al_get_display_mode(0, &disp_data);             //en disp_data se almacena el tamaño de la pantalla (ancho y alto)
   int screenW = disp_data.width;
   int screenH = disp_data.height;
   //al_set_new_display_flags(ALLEGRO_FULLSCREEN); //la proxima ventana se hace fullscreen
   ALLEGRO_DISPLAY *display = al_create_display(screenW, screenH);   
   if (display == NULL){
      printf("Failed to create display.\n");
      return -1;
   }
   ALLEGRO_FONT *font_score = al_load_ttf_font(DIR_FUENTES"/"FUENTE_SCORE, 200, 0);
   ALLEGRO_FONT *font200 = al_load_ttf_font(DIR_FUENTES"/"FUENTE_MENU, 200, 0);
   ALLEGRO_FONT *font100 = al_load_ttf_font(DIR_FUENTES"/"FUENTE_MENU, 100, 0);
   ALLEGRO_FONT *font75 = al_load_ttf_font(DIR_FUENTES"/"FUENTE_MENU, 75, 0);
   if (font200 == NULL){
      printf("Could not load 'FutureMillennium.ttf'.\n");
      return -1;
   }
   if (font100 == NULL){
      printf("Could not load 'FutureMillennium.ttf'.\n");
      return -1;
   }
   srand(time(NULL));
   al_register_event_source(queue, keyboard_event);
   al_register_event_source(queue, tempo_event);
   struct settings *mis_settings=crear_settings();
   menu(queue,font200,font100,screenW,screenH,font75,mis_settings,font_score);
}

