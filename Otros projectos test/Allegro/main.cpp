#include <allegro.h>
#include "inicia.h"

int main ()
{
    inicia_allegro(320,320);
    inicia_audio(70,70);

    BITMAP *buffer = create_bitmap(320,320);Z
    clear_to_color(buffer, 0x999999);

    textout_centre_ex(buffer, font, "Mi Primer Ventana", 160, 25, 0xFFFFFF, 0x999999);
    blit(buffer, screen, 0, 0, 0, 0, 640, 480);
    readkey();

    destroy_bitmap(buffer);

    return 0;
}
END_OF_MAIN ()


