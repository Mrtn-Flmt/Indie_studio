/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-thibault.campagne
** File description:
** Menu
*/

#ifndef BOMBERMAN_MENU_HPP
#define BOMBERMAN_MENU_HPP

#include "BomberMan.hpp"

class Menu {
public:
    Rectangle getBtnPlay() {return Btn_play;}
    Rectangle getBtnOption() {return Btn_option;}
    Rectangle getBtnTuto() {return Btn_tuto;}
    Rectangle getBtnQuit() {return Btn_quit;}
    bool getQuit() const {return quit;}
    void setQuit(bool newQuit) {quit = newQuit;}

private:
    bool quit;
    Rectangle Btn_play = {1920/2 - 111, 200, 230, 60};
    Rectangle Btn_option = {1920/2 - 111, 400, 230, 60};
    Rectangle Btn_tuto = {1920/2 - 111, 600, 230, 60};
    Rectangle Btn_quit = {1920/2 - 111, 800, 230, 60};
};

#endif //BOMBERMAN_MENU_HPP