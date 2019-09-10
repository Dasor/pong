#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "settings.h"
#include "final.h"

#define DER 1
#define IZQ 2
#define ARR 1
#define ABJ 2

#define VELOCIDAD1 15
#define VELOCIDAD2 15

#define RADIO_PELOTA 15

#define J1 1
#define J2 2

int abs(int n) {
  return n < 0 ? -n : -n;
}

void play (ALLEGRO_EVENT_QUEUE *queue,int screenW,int screenH,struct settings *mis_settings,ALLEGRO_FONT *font_score){
  bool exit=false;
  bool w=false;
  bool s=false;
  bool up=false;
  bool down=false;
  int pelotaX=screenW/8;
  int pelotaY=0;
  int score1=0;
  int score2=0;
  int centro1=screenH/2;
  int centro2=screenH/2;
  int dX=DER;
  int dY=rand()%2+1;	
  int velocidad_pelota = get_pelota(mis_settings)*5;
  int max_puntos = get_max_puntos(mis_settings);
  int l_palo = get_palo(mis_settings)*24;
  int palo1X=screenW/2-screenW/4-screenW/8;
  int palo2X=screenW/2+screenW/4+screenW/8;
  int jugador_ganador=0;
  int velocidad_pelota_Y=velocidad_pelota;
  ALLEGRO_EVENT ev;
  ALLEGRO_COLOR blanco = al_map_rgb(255,255,255);
  ALLEGRO_COLOR negro = al_map_rgb(255,0,0);
  al_clear_to_color(al_map_rgb(0,0,0));

  while(exit==false && jugador_ganador==0){ 
    //pelota//
    if(pelotaX <= palo1X+RADIO_PELOTA  && pelotaX >= palo1X+RADIO_PELOTA-25 &&  (centro1-l_palo < pelotaY && centro1+l_palo > pelotaY)){
      dX=DER;
      velocidad_pelota_Y = velocidad_pelota + velocidad_pelota*(abs(pelotaY-centro1)/(float)l_palo*0.25);
    }
    if(pelotaX >= palo2X-RADIO_PELOTA  && pelotaX <= palo2X+RADIO_PELOTA+25 && (centro2-l_palo < pelotaY && centro2+l_palo > pelotaY)){
      dX=IZQ;
      velocidad_pelota_Y = velocidad_pelota + velocidad_pelota*(abs(pelotaY-centro2)/(float)l_palo*0.25);
    }
    if(pelotaY<=0){
    dY=ARR;
    }
    if(pelotaY>=screenH){
    dY=ABJ;
    }

    //score//
    if(pelotaX>=screenW){
      score1++;
      pelotaX=screenW/8;
      pelotaY=0;
    }
    if(pelotaX<=0){
      score2++;
      pelotaX=screenW-screenW/8;
      pelotaY=0;
    }

    //fin de la partida//
    if(score1==max_puntos){
      jugador_ganador=J1;
      al_pause_event_queue(queue,true);
      final(jugador_ganador,score1,score2,screenW,screenH,font_score);      
      al_pause_event_queue(queue,false);
      }  
     
    if(score2==max_puntos){
      jugador_ganador=J2;
      al_pause_event_queue(queue,true);
      final(jugador_ganador,score1,score2,screenW,screenH,font_score);
      al_pause_event_queue(queue,false);
      }  
     

    //recibir eventos//
    al_wait_for_event(queue, &ev);
    if(ev.type == ALLEGRO_EVENT_KEY_DOWN ){      
      if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
        exit = true;
      }  
      if(ev.keyboard.keycode == ALLEGRO_KEY_UP && centro1-l_palo>=0){
        centro1-=VELOCIDAD1;
        up=true;
      }
      if(ev.keyboard.keycode == ALLEGRO_KEY_DOWN && centro1+l_palo<=screenH ){
        centro1+=VELOCIDAD1; 
        down=true;
      }
      if(ev.keyboard.keycode == ALLEGRO_KEY_W && centro2-l_palo>=0){
        centro2-=VELOCIDAD1;
        w=true;
      }
      if(ev.keyboard.keycode == ALLEGRO_KEY_S && centro2+l_palo<=screenH){
        centro2+=VELOCIDAD1;
        s=true;
      }
    }						
    
    if(ev.type == ALLEGRO_EVENT_KEY_UP){
      if(ev.keyboard.keycode == ALLEGRO_KEY_W) {
        w=false;
      }
     if(ev.keyboard.keycode == ALLEGRO_KEY_S) {
        s=false;
      }
     if(ev.keyboard.keycode == ALLEGRO_KEY_UP) {
        up=false;
      }
     if(ev.keyboard.keycode == ALLEGRO_KEY_DOWN) {
        down=false;
      }
    }          

    //dibujar//
    if(ev.type==ALLEGRO_EVENT_TIMER) {  
      if(w == true && centro2-l_palo>=0) centro2-=VELOCIDAD2; 
      if(s == true && centro2+l_palo<=screenH) centro2+=VELOCIDAD2;    
      if(up == true && centro1-l_palo>=0) centro1-=VELOCIDAD2;
      if(down == true && centro1+l_palo<=screenH) centro1+=VELOCIDAD2;

      if(dX==DER)pelotaX=pelotaX+velocidad_pelota;
      if(dX==IZQ)pelotaX=pelotaX-velocidad_pelota;
      if(dY==ARR)pelotaY=pelotaY+velocidad_pelota_Y;
      if(dY==ABJ)pelotaY=pelotaY-velocidad_pelota_Y;   

      al_clear_to_color(al_map_rgb(0,0,0));
      for(int i=1;i<50;i+=2){
        al_draw_line(screenW/2,21.6*(i-2),screenW/2,21.6*(i-1),blanco,5);
      }
      al_draw_filled_circle(pelotaX,pelotaY, RADIO_PELOTA, blanco );
      al_draw_line(palo1X, centro1+l_palo, palo1X, centro1-l_palo, blanco, 25);
      al_draw_line(palo2X, centro2+l_palo, palo2X, centro2-l_palo, blanco, 25);

      al_draw_textf(font_score,blanco,screenW/2-screenW/4,0,0,"%d",score1);
      al_draw_textf(font_score,blanco,screenW/2+screenW/4-75,0,0,"%d",score2); 

      al_flip_display();      
    }

  }
}
