#include <MenuInitialState.h>
#include <allegro.h>
#include <GameState.h>
#include <GameStateManager.h>

using namespace std;

MenuInitialState::MenuInitialState(GameStateManager *game)
{
    this->game = game;

}

void MenuInitialState::init()
{


}

void MenuInitialState::getEvents()
{

}

void MenuInitialState::update()
{

        BITMAP *background_image = load_bitmap("src\\Resources\\background_menuinitial.bmp",NULL);
    stretch_blit(background_image, this->game->getBuffer(), 0, 0, background_image->w, background_image->h, 0, 0, GameStateManager::SIZE_WINDOW_X, GameStateManager::SIZE_WINDOW_Y);


}

void MenuInitialState::draw()
{

}

