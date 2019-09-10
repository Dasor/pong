#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#define DEFAULT_1 5
#define DEFAULT_2 4
#define DEFAULT_3 4

struct settings{
  int max_puntos;
  int palo;
  int pelota;
};

int get_max_puntos(struct settings * mis_settings) {
  return mis_settings->max_puntos;
}

int get_palo(struct settings * mis_settings) {
  return mis_settings->palo;
}

int get_pelota(struct settings * mis_settings) {
  return mis_settings->pelota;
}

struct settings * crear_settings(){
  struct settings *mis_settings=malloc(sizeof(struct settings));
  mis_settings->max_puntos=DEFAULT_1;
  mis_settings->palo=DEFAULT_2;
  mis_settings->pelota=DEFAULT_3;

  return mis_settings; 
}

void settings (ALLEGRO_EVENT_QUEUE *queue,ALLEGRO_FONT *font200,ALLEGRO_FONT *font100,int screenW,int screenH,ALLEGRO_FONT *font75,struct settings *mis_settings){
   int posicion_ajustes=0;
   bool exit=false;
   ALLEGRO_EVENT ev;
   ALLEGRO_COLOR amarillo = al_map_rgb(227,209,10);
   ALLEGRO_COLOR blanco = al_map_rgb(255,255,255);

   al_clear_to_color(al_map_rgb(0,0,0));
   al_draw_text(font200, blanco, screenW/2, 0,ALLEGRO_ALIGN_CENTRE, "Settings");
   al_draw_text(font100, blanco, screenW/2, screenH-800,ALLEGRO_ALIGN_CENTRE, "Max.Points");
   al_draw_textf(font75, blanco, screenW/2, screenH-700,ALLEGRO_ALIGN_CENTRE, "<-%d->",mis_settings->max_puntos);
   al_draw_text(font100, blanco, screenW/2, screenH-570,ALLEGRO_ALIGN_CENTRE, "Stick length");
   al_draw_textf(font75, blanco, screenW/2, screenH-470,ALLEGRO_ALIGN_CENTRE, "<-%d->",mis_settings->palo);
   al_draw_text(font100, blanco, screenW/2, screenH-300,ALLEGRO_ALIGN_CENTRE, "Ball speed");
   al_draw_textf(font75, blanco, screenW/2, screenH-200,ALLEGRO_ALIGN_CENTRE, "<-%d->",mis_settings->pelota);
   al_flip_display();
   
   while(exit==false) {
      // Recibir eventos //
     al_wait_for_event(queue, &ev);
     if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
       if(ev.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
         if(posicion_ajustes==1){
           if(mis_settings->max_puntos<=29){
             mis_settings->max_puntos++;
           }
         }
         if(posicion_ajustes==2){
           if(mis_settings->palo<=4){
             mis_settings->palo++;
           }
         } 
         if(posicion_ajustes==3){
           if(mis_settings->pelota<=4){
             mis_settings->pelota++;
           } 
         }
       }
       if(ev.keyboard.keycode == ALLEGRO_KEY_LEFT) {
         if(posicion_ajustes==1){
            if(mis_settings->max_puntos>=2){ 
              mis_settings->max_puntos--;
            }
         }
         if(posicion_ajustes==2){
           if(mis_settings->palo>=2){
             mis_settings->palo--;
           }
         }
         if(posicion_ajustes==3){
           if(mis_settings->pelota>=2){ 
             mis_settings->pelota--;
           } 
         }
       }
       if(ev.keyboard.keycode == ALLEGRO_KEY_DOWN) {
         if(posicion_ajustes <= 2) posicion_ajustes++;
       }
       if(ev.keyboard.keycode == ALLEGRO_KEY_UP) {
         if(posicion_ajustes >= 2) posicion_ajustes--;
       }
       if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) exit = true;        
     
   
       // Dibujar //
       al_clear_to_color(al_map_rgb(0,0,0));
       al_draw_text(font200, blanco, screenW/2, 0,ALLEGRO_ALIGN_CENTRE, "SETTINGS");
       if(posicion_ajustes==0){
         al_draw_text(font100, blanco, screenW/2, screenH-800,ALLEGRO_ALIGN_CENTRE, "Max.Points");
         al_draw_textf(font75, blanco, screenW/2, screenH-700,ALLEGRO_ALIGN_CENTRE, "<-%d->",mis_settings->max_puntos);
         al_draw_text(font100, blanco, screenW/2, screenH-570,ALLEGRO_ALIGN_CENTRE, "Stick length");
         al_draw_textf(font75, blanco, screenW/2, screenH-470,ALLEGRO_ALIGN_CENTRE, "<-%d->",mis_settings->palo);
         al_draw_text(font100, blanco, screenW/2, screenH-300,ALLEGRO_ALIGN_CENTRE, "Ball speed");
         al_draw_textf(font75, blanco, screenW/2, screenH-200,ALLEGRO_ALIGN_CENTRE, "<-%d->",mis_settings->pelota);
       } 
       if(posicion_ajustes==1){
         al_draw_text(font100, blanco, screenW/2, screenH-800,ALLEGRO_ALIGN_CENTRE, "Max.Points");
         al_draw_textf(font75, amarillo, screenW/2, screenH-700,ALLEGRO_ALIGN_CENTRE, "<-%d->",mis_settings->max_puntos);
         al_draw_text(font100, blanco, screenW/2, screenH-570,ALLEGRO_ALIGN_CENTRE, "Stick length");
         al_draw_textf(font75, blanco, screenW/2, screenH-470,ALLEGRO_ALIGN_CENTRE, "<-%d->",mis_settings->palo);
         al_draw_text(font100, blanco, screenW/2, screenH-300,ALLEGRO_ALIGN_CENTRE, "Ball speed");
         al_draw_textf(font75, blanco, screenW/2, screenH-200,ALLEGRO_ALIGN_CENTRE, "<-%d->",mis_settings->pelota);
       } 
       if(posicion_ajustes==2){
         al_draw_text(font100, blanco, screenW/2, screenH-800,ALLEGRO_ALIGN_CENTRE, "Max.Points");
         al_draw_textf(font75, blanco, screenW/2, screenH-700,ALLEGRO_ALIGN_CENTRE, "<-%d->",mis_settings->max_puntos);
         al_draw_text(font100, blanco, screenW/2, screenH-570,ALLEGRO_ALIGN_CENTRE, "Stick length");
         al_draw_textf(font75, amarillo, screenW/2, screenH-470,ALLEGRO_ALIGN_CENTRE, "<-%d->",mis_settings->palo);
         al_draw_text(font100, blanco, screenW/2, screenH-300,ALLEGRO_ALIGN_CENTRE, "Ball speed");
         al_draw_textf(font75, blanco, screenW/2, screenH-200,ALLEGRO_ALIGN_CENTRE, "<-%d->",mis_settings->pelota);
       } 
       if(posicion_ajustes==3){
         al_draw_text(font100, blanco, screenW/2, screenH-800,ALLEGRO_ALIGN_CENTRE, "Max.Points");
         al_draw_textf(font75, blanco, screenW/2, screenH-700,ALLEGRO_ALIGN_CENTRE, "<-%d->",mis_settings->max_puntos);
         al_draw_text(font100, blanco, screenW/2, screenH-570,ALLEGRO_ALIGN_CENTRE, "Stick length");
         al_draw_textf(font75, blanco, screenW/2, screenH-470,ALLEGRO_ALIGN_CENTRE, "<-%d->",mis_settings->palo);
         al_draw_text(font100, blanco, screenW/2, screenH-300,ALLEGRO_ALIGN_CENTRE, "Ball speed");
         al_draw_textf(font75, amarillo, screenW/2, screenH-200,ALLEGRO_ALIGN_CENTRE, "<-%d->",mis_settings->pelota);
     }   
       al_flip_display();
     }
  }
}



