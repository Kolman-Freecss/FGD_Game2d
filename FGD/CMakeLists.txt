cmake_minimum_required(VERSION 3.10)
project(FGD)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(FGD
        include/BaseGame.h
        include/Character.h
        include/DAOManager.h
        include/DAOMap.h
        include/Drawable.h
        include/Enemy.h
        include/House.h
        include/Inventory.h
        include/Map.h
        include/Object.h
        include/Player.h
        include/Potion.h
        include/Shield.h
        include/Sword.h
        include/Weapon.h
        src/Dao/DAOManager.cpp
        src/Dao/DAOMap.cpp
        src/Main/Main.cpp
        src/Resources/grass.bmp
        src/Resources/house1.bmp
        src/Resources/Player_Front_With_Sword.bmp
        src/Resources/Sprite1.bmp
        src/BaseGame.cpp
        src/Character.cpp
        src/Drawable.cpp
        src/Enemy.cpp
        src/House.cpp
        src/Inventory.cpp
        src/Map.cpp
        src/Object.cpp
        src/Player.cpp
        src/Potion.cpp
        src/Shield.cpp
        src/Sword.cpp
        src/Weapon.cpp
        main.cpp)
