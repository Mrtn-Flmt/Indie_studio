/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-thibault.campagne
** File description:
** PreMenu
*/

#include <string>
#include <array>
#include <vector>

#ifndef PREMENU_HPP_
#define PREMENU_HPP_

class PreMenu {
    public:
        PreMenu() = default;
        ~PreMenu() = default;
        std::array <std::string, 8> getPreMenu() { return (ArrCheck); }
        void setPreMenu(std::array <std::string, 8> newArrCheck) { ArrCheck = newArrCheck; }
        std::vector <std::string> getPreMenuMsg() { return (msg); }
        void setPreMenuMsg(std::vector <std::string> newMsg) { msg = newMsg; }

    protected:
    private:
        std::vector <std::string> msg = {"Joueur 1", "I.A", "I.A", "I.A"};
        std::array <std::string, 8> ArrCheck = {"", "", "", "", "", "", "", ""};

};

#endif /* !PREMENU_HPP_ */
