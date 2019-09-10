SANITY_FLAGS=-Wall -Wextra -Werror -fstack-protector-all -pedantic -Wno-unused -Wfloat-equal -Wshadow -Wpointer-arith -Wformat=2

pong: Main.c menu.c menu.h settings.c settings.h play.c play.h final.c final.h Makefile
	gcc Main.c menu.c settings.c play.c final.c -g $(SANITY_FLAGS) `pkg-config --cflags --libs allegro-5 allegro_acodec-5 allegro_audio-5 allegro_color-5 allegro_dialog-5 allegro_font-5 allegro_image-5 allegro_main-5 allegro_memfile-5 allegro_physfs-5 allegro_primitives-5 allegro_ttf-5` -o pong

run: pong
	./pong

clean:
	rm pong
