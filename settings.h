#ifndef __SETTINGS__
#define __SETTINGS__

struct settings;

struct settings * crear_settings();
int get_max_puntos(struct settings * mis_settings);
int get_palo(struct settings * mis_settings);
int get_pelota(struct settings * mis_settings);

void settings (ALLEGRO_EVENT_QUEUE *queue,ALLEGRO_FONT *font200,ALLEGRO_FONT *font100,int screenW,int screenH,ALLEGRO_FONT *font75,struct settings *mis_settings);

#endif
