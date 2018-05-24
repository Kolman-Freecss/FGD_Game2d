#ifndef LoginState_h
#define LoginState_h

#include <GameState.h>
#include <GameStateManager.h>

using namespace std;

class LoginState : public GameState{

 public:

     const static int MIDDLE_SCREEN_X = GameStateManager::SIZE_WINDOW_X / 2;
     const static int MIDDLE_SCREEN_Y = GameStateManager::SIZE_WINDOW_Y / 2;

    BITMAP *logo;
    BITMAP *background_image;

    BITMAP *login_user_password;
    BITMAP *login_user_password_pressed;
    BITMAP *enter;
    BITMAP *enter_pressed;
    BITMAP *finish;
    BITMAP *finish_pressed;
    BITMAP *register_user;
    BITMAP *register_user_pressed;
    BITMAP *cruz;

    //BITMAP *mouse = load_bitmap("src\\Resources\\Mouse.bmp",NULL);

    void userPressed();
    void passwordPressed();
    void enterPressed();
    void finishPressed();
    void registerPressed();
    void cruzPressed();

    /**
    Initial method
    */
    void init();

    void cleanUp(){};

    void pause(){};
    void resume(){};

    void getEvents();
    void update();
    void draw();

    LoginState(GameStateManager *game);

 private:
     /**
        Para mostrar el menu de registro o no (simularlo simplemente ocultando los otros botones)
     */
    bool checkRegister;

    /**
    Para saber en que cuadro estamos escribiendo
    */
    bool checkUser;
    bool checkPassword;

    void clickOut();

};

#endif // LoginState_h
