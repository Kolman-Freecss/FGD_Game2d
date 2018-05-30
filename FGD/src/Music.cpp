#include "Music.h"
#include <allegro.h>

SAMPLE* Music::menu =  load_sample("src\\Resources\\Music\\menuSound.wav");
SAMPLE* Music::attack =  load_sample("src\\Resources\\Music\\attack_sound.wav");
SAMPLE* Music::map1 =  load_sample("src\\Resources\\Music\\map1sound.wav");
SAMPLE* Music::map2 =  load_sample("src\\Resources\\Music\\map2sound.wav");
SAMPLE* Music::map3 =  load_sample("src\\Resources\\Music\\map3sound.wav");
SAMPLE* Music::map4 =  load_sample("src\\Resources\\Music\\map4sound.wav");
SAMPLE* Music::map5 =  load_sample("src\\Resources\\Music\\map5sound.wav");

//SAMPLE* Music::wounded =  load_sample("src\\Resources\\Music\\woundedSound.wav");

bool Music::checkMusicOrNot = true;

bool Music::isPlayingMenu = false;
bool Music::isPlayingMap1 = false;
bool Music::isPlayingMap2 = false;
bool Music::isPlayingMap3 = false;
bool Music::isPlayingMap4 = false;
bool Music::isPlayingMap5 = false;

Music::Music(){

    this->init();

}

/**
Funcion que carga todos los ficheros de audio
*/
void Music::init(){
    set_volume(230, 90);

}


void Music::soundMenu()
{
    play_sample( Music::menu, 100, 128, 2000, 0);
    Music::isPlayingMenu = true;
}

void Music::soundAttack()
{
    play_sample( Music::attack, 100, 128, 900, 0);
}


void Music::soundMap1()
{
    play_sample( Music::map1, 100, 128, 900, 1);
    Music::isPlayingMap1 = true;
}

void Music::soundMap2()
{
    play_sample( Music::map2, 100, 128, 900, 1);
    Music::isPlayingMap2 = true;
}

void Music::soundMap3()
{
    play_sample( Music::map3, 100, 128, 900, 1);
    Music::isPlayingMap3 = true;
}

void Music::soundMap4()
{
    play_sample( Music::map4, 100, 128, 900, 1);
    Music::isPlayingMap4 = true;
}

void Music::soundMap5()
{
    play_sample( Music::map5, 100, 128, 900, 1);
    Music::isPlayingMap5 = true;
}

void Music::stopAllSounds()
{
    if(Music::isPlayingMenu){
        stop_sample( Music::menu );
    }else if(Music::isPlayingMap1){
        stop_sample( Music::map1 );
    }else if(Music::isPlayingMap2){
        stop_sample( Music::map2 );
    }else if(Music::isPlayingMap3){
        stop_sample( Music::map3 );
    }else if(Music::isPlayingMap4){
        stop_sample( Music::map4 );
    }else if(Music::isPlayingMap5){
        stop_sample( Music::map5 );
    }


}



/////////////////// STOP SOUNDS //////////////////


void Music::stopSoundMenu(){
     stop_sample( Music::menu );
     Music::isPlayingMenu = false;
}

void Music::stopSoundMap1(){
     stop_sample( Music::map1 );
     Music::isPlayingMap1 = false;
}

void Music::stopSoundMap2(){
     stop_sample( Music::map2 );
     Music::isPlayingMap2 = false;
}

void Music::stopSoundMap3(){
     stop_sample( Music::map3 );
     Music::isPlayingMap3 = false;
}

void Music::stopSoundMap4(){
     stop_sample( Music::map4 );
     Music::isPlayingMap4 = false;
}

void Music::stopSoundMap5(){
     stop_sample( Music::map5 );
     Music::isPlayingMap5 = false;
}



////////////////// FIN STOP SOUNDS ////////////////



/*

void sonido_abrirpuerta(){
     play_sample ( spuerta1, 100,128, 1300, 0 );
}
}*/
