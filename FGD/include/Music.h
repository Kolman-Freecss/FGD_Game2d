#ifndef Music_h
#define Music_h

#include <allegro.h>

#include <vector>

class Music {


 public:
        Music();
        void init();
        void soundMap1();
        void stopSoundBackground();
        static SAMPLE *map1;
        static bool map1IsPlaying;
        static bool getMap1IsPlaying();
        static void setMap1IsPlaying(bool check);

 private:




};

#endif // Music_h
