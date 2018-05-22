#include "Music.h"
#include <allegro.h>

SAMPLE* Music::map1 =  load_sample("src\\Resources\\Music\\wah_fuzz.wav");
bool Music::map1IsPlaying = false;

Music::Music(){

    this->init();

}

/**
Funcion que carga todos los ficheros de audio
*/
void Music::init(){
    set_volume(230, 90);

}

void Music::soundMap1()
{
    play_sample( Music::map1, 100, 128, 900, 1);
    Music::setMap1IsPlaying(true);
}

void Music::stopSoundBackground(){
     stop_sample( Music::map1 );
     Music::setMap1IsPlaying(false);
}

bool Music::getMap1IsPlaying()
{
    return Music::map1IsPlaying;
}

void Music::setMap1IsPlaying(bool check)
{
    Music::map1IsPlaying = check;
}


/*void sonido_pasos(){
     play_sample ( spasos, 100,128, 3300, 0 );
}

void sonido_abrirpuerta(){
     play_sample ( spuerta1, 100,128, 1300, 0 );
}

void sonido_ambiente(){
     play_sample ( sbosque, 80,128, 900, 1 );
}

void para_sonido_ambiente(){
     stop_sample( sbosque );
}*/
