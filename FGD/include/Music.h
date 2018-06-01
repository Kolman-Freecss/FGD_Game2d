#ifndef Music_h
#define Music_h

#include <allegro.h>

#include <vector>

class Music {


 public:
        Music();
        void init();

        /**
        Sonidos para reproducir
        */
        void soundMenu();
        static bool isPlayingMenu;
        void soundAttack();
        void soundMap1();
        static bool isPlayingMap1;
        void soundMap2();
        static bool isPlayingMap2;
        void soundMap3();
        static bool isPlayingMap3;
        void soundMap4();
        static bool isPlayingMap4;
        void soundMap5();
        static bool isPlayingMap5;
        void soundWin();
        static bool isPlayingWin;
        void soundLost();
        static bool isPlayingLost;
        //void soundWounded();

        void stopSoundMenu();
        void stopSoundMap1();
        void stopSoundMap2();
        void stopSoundMap3();
        void stopSoundMap4();
        void stopSoundMap5();
        void stopSoundWin();
        void stopSoundLost();


        static bool checkMusicOrNot;
        static void stopAllSounds();


 private:

    static SAMPLE *attack;
    static SAMPLE *menu;
    static SAMPLE *map1;
    static SAMPLE *map2;
    static SAMPLE *map3;
    static SAMPLE *map4;
    static SAMPLE *map5;
    static SAMPLE *wounded;
    static SAMPLE *win;
    static SAMPLE *lost;





};

#endif // Music_h
