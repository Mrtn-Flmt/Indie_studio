/*
** EPITECH PROJECT, 2022
** SpriteInit.cpp
** File description:
** SpriteInit.cpp
*/

#include "ECS/SpriteRenderer.hpp"
#include "BomberMan.hpp"

void InitEntityToEntityLoad(EntityManager *load) {
    Entity *Loading_screen = new Entity("loading_screen");
    load->addEntity(Loading_screen);
    Loading_screen->addComponent<SpriteRenderer>("../Models/assets/loading_screen.png", Vector2 {1920, 1080});
    Loading_screen->getComponent<SpriteRenderer>().SetDrawPosition(Vector2{0, 0});
}

void InitEntityToEntityTuto(EntityManager *tuto) {
    Entity *tuto_screen = new Entity("tuto_bc");
    Entity *btn_back = new Entity("btn_back");
    tuto->addEntity(btn_back);
    btn_back->addComponent<SpriteRenderer>("../Models/assets/back.png", Vector2 {100, 100});
    btn_back->getComponent<SpriteRenderer>().SetDrawPosition(Vector2 {30, 955});

    tuto->addEntity(tuto_screen);
    tuto_screen->addComponent<SpriteRenderer>("../Models/assets/tuto.png", Vector2{900, 778});
    tuto_screen->getComponent<SpriteRenderer>().SetDrawPosition(Vector2{470, 100});
}

void EntitySelectionGestionMenu(EntityManager *menu) {
    bool check_play = false;
    bool check_option = false;
    bool check_tuto = false;
    bool check_quit = false;
    Rectangle Btn_play = {1920/2 - 111, 200, 230, 60};
    Rectangle Btn_option = {1920/2 - 111, 400, 230, 60};
    Rectangle Btn_tuto = {1920/2 - 111, 600, 230, 60};
    Rectangle Btn_quit = {1920/2 - 111, 800, 230, 60};

    if (CheckCollisionPointRec(GetMousePosition(), Btn_play) && check_play == false) {
        for(auto &entity : menu->entities) {
            if (entity->name == "play_btn")
                entity->getComponent<SpriteRenderer>().LoadSpriteRendererResize("../Models/assets/button_over.png", Vector2 {230, 60});
        }
        check_play == true;
    } else {
         for(auto &entity : menu->entities) {
            if (entity->name == "play_btn")
                entity->getComponent<SpriteRenderer>().LoadSpriteRendererResize("../Models/assets/button.png", Vector2 {230, 60});
        }
        check_play = false;
    }

    if (CheckCollisionPointRec(GetMousePosition(), Btn_option) && check_option == false) {
        for(auto &entity : menu->entities) {
            if (entity->name == "setting_btn")
                entity->getComponent<SpriteRenderer>().LoadSpriteRendererResize("../Models/assets/button_over.png", Vector2 {230, 60});
        }
        check_option == true;
    } else {
         for(auto &entity : menu->entities) {
            if (entity->name == "setting_btn")
                entity->getComponent<SpriteRenderer>().LoadSpriteRendererResize("../Models/assets/button.png", Vector2 {230, 60});
        }
        check_option = false;
    }

    if (CheckCollisionPointRec(GetMousePosition(), Btn_tuto) && check_tuto == false) {
        for(auto &entity : menu->entities) {
            if (entity->name == "tuto_btn")
                entity->getComponent<SpriteRenderer>().LoadSpriteRendererResize("../Models/assets/button_over.png", Vector2 {230, 60});
        }
        check_tuto == true;
    } else {
         for(auto &entity : menu->entities) {
            if (entity->name == "tuto_btn")
                entity->getComponent<SpriteRenderer>().LoadSpriteRendererResize("../Models/assets/button.png", Vector2 {230, 60});
        }
        check_tuto = false;
    }

    if (CheckCollisionPointRec(GetMousePosition(), Btn_quit) && check_quit == false) {
        for(auto &entity : menu->entities) {
            if (entity->name == "quit_hall")
                entity->getComponent<SpriteRenderer>().LoadSpriteRendererResize("../Models/assets/button_over.png", Vector2 {230, 60});
        }
        check_quit == true;
    } else {
         for(auto &entity : menu->entities) {
            if (entity->name == "quit_hall")
                entity->getComponent<SpriteRenderer>().LoadSpriteRendererResize("../Models/assets/button.png", Vector2 {230, 60});
        }
        check_quit = false;
    }
}

void InitEntityToEntityMenu(EntityManager *menu, Font font) {
    Entity *title = new Entity("title");
    Entity *play_btn = new Entity("play_btn");
    Entity *setting_btn = new Entity("setting_btn");
    Entity *tuto_btn = new Entity("tuto_btn");
    Entity *quit_btn = new Entity("quit_hall");
    std::string play_text = "PLAY";
    std::string option_text = "OPTION";
    std::string tuto_text = "TUTO";
    std::string quit_text = "QUIT";
    menu->addEntity(title);
    menu->addEntity(play_btn);
    menu->addEntity(setting_btn);
    menu->addEntity(quit_btn);
    menu->addEntity(tuto_btn);


    title->addComponent<SpriteRenderer>("../Models/assets/title.png", Vector2 {600, 204});
    play_btn->addComponent<SpriteRenderer>("../Models/assets/button.png", Vector2 {230, 60});
    setting_btn->addComponent<SpriteRenderer>("../Models/assets/button.png", Vector2 {230, 60});
    tuto_btn->addComponent<SpriteRenderer>("../Models/assets/button.png", Vector2 {230, 60});
    quit_btn->addComponent<SpriteRenderer>("../Models/assets/button.png", Vector2 {230, 60});

    title->getComponent<SpriteRenderer>().SetDrawPosition(Vector2{100, 10});
    play_btn->getComponent<SpriteRenderer>().SetDrawPosition(Vector2{1920/2 - 111, 200});
    setting_btn->getComponent<SpriteRenderer>().SetDrawPosition(Vector2{1920/2 - 111, 400});
    tuto_btn->getComponent<SpriteRenderer>().SetDrawPosition(Vector2{1920/2 - 111, 600});
    quit_btn->getComponent<SpriteRenderer>().SetDrawPosition(Vector2{1920/2 - 111, 800});
}

void GestionPreMenu(EntityManager *premenu, PreMenu *Premenu) {
    static std::array<std::string, 8> ArrCheck = {"", "", "", "", "", "", "", ""};
    int status1, status2, status3, status4 = 0;
    static std::vector <std::string> msg = {"Joueur 1", "I.A", "I.A", "I.A"};
    std::array<int, 4> ArrStats = {status1, status2, status3, status4};
    static std::vector <bool> btnAction = {true, false, false, false};
    std::vector <Rectangle> ArrButtonsKey = {{980, 170, 90, 90}, {980, 395, 90, 90}, {980, 620, 90, 90}, {980, 840, 90, 90}};
    std::vector <Rectangle> ArrButtonsControllers = {{790, 170, 90, 90}, {790, 395, 90, 90}, {790, 620, 90, 90}, {790, 840, 90, 90}};
    std::vector <Rectangle> ArrButtonsPlayer = {{620, 120, 100, 160}, {620, 350, 100, 160}, {620, 570, 100, 160}, {620, 800, 100, 160}};

    if (CheckCollisionPointRec(GetMousePosition(), ArrButtonsPlayer[1]) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        if(btnAction[1] == true) {
            msg[1] = "Joueur 2";
            for(auto &entity : premenu->entities) {
                if (entity->name == "addPlayer2")
                    entity->getComponent<SpriteRenderer>().LoadSpriteRendererResize("../Models/assets/remove_player.png", Vector2 {90, 90});
            }
            ArrCheck[3] = "X";
            ArrCheck[2] = "";
            btnAction[1] = false;
            } else {
                msg[1] = "I.A";
                for(auto &entity : premenu->entities) {
                    if (entity->name == "addPlayer2")
                    entity->getComponent<SpriteRenderer>().LoadSpriteRendererResize("../Models/assets/add_player.png", Vector2 {90, 90});
                btnAction[1] = true;
            }
        }
    }

    if (CheckCollisionPointRec(GetMousePosition(), ArrButtonsPlayer[2]) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        if(btnAction[2] == true) {
            msg[2] = "Joueur 3";
            for(auto &entity : premenu->entities) {
            if (entity->name == "addPlayer3")
                entity->getComponent<SpriteRenderer>().LoadSpriteRendererResize("../Models/assets/remove_player.png", Vector2 {90, 90});
        }
                ArrCheck[5] = "X";
                ArrCheck[4] = "";
                btnAction[2] = false;
            } else {
                msg[2] = "I.A";
                for(auto &entity : premenu->entities) {
                    if (entity->name == "addPlayer3")
                    entity->getComponent<SpriteRenderer>().LoadSpriteRendererResize("../Models/assets/add_player.png", Vector2 {90, 90});
                btnAction[2] = true;
            }
        }
    }

    if (CheckCollisionPointRec(GetMousePosition(), ArrButtonsPlayer[3]) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        if(btnAction[3] == true) {
            msg[3] = "Joueur 4";
            for(auto &entity : premenu->entities) {
            if (entity->name == "addPlayer4")
                entity->getComponent<SpriteRenderer>().LoadSpriteRendererResize("../Models/assets/remove_player.png", Vector2 {90, 90});
        }
                ArrCheck[7] = "X";
                ArrCheck[6] = "";
                btnAction[3] = false;
            } else {
                msg[3] = "I.A";
                for(auto &entity : premenu->entities) {
                    if (entity->name == "addPlayer4")
                    entity->getComponent<SpriteRenderer>().LoadSpriteRendererResize("../Models/assets/add_player.png", Vector2 {90, 90});
                btnAction[3] = true;
            }
        }
    }

    if (CheckCollisionPointRec(GetMousePosition(), ArrButtonsKey[0]) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        ArrCheck[1] = "";
        ArrCheck[0] = "X";
        ArrStats[0] = 1;
    } else if (CheckCollisionPointRec(GetMousePosition(), ArrButtonsControllers[0]) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        ArrCheck[0] = "";
        ArrCheck[1] = "X";
        ArrStats[0] = 2;
    }
    
    if (msg[1] == "I.A") {
        ArrCheck[2] = "X";
        ArrCheck[3] = "X";
    } else if (CheckCollisionPointRec(GetMousePosition(), ArrButtonsKey[1]) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        ArrCheck[3] = "";
        ArrCheck[2] = "X";
        ArrStats[1] = 1;
    } else if (CheckCollisionPointRec(GetMousePosition(), ArrButtonsControllers[1]) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        ArrCheck[2] = "";
        ArrCheck[3] = "X";
        ArrStats[1] = 2;
    }

    if (msg[2] == "I.A") {
        ArrCheck[5] = "X";
        ArrCheck[4] = "X";
        
    } else if (CheckCollisionPointRec(GetMousePosition(), ArrButtonsKey[2]) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        ArrCheck[5] = "";
        ArrCheck[4] = "X";
        ArrStats[2] = 1;
    } else if (CheckCollisionPointRec(GetMousePosition(), ArrButtonsControllers[2]) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        ArrCheck[4] = "";
        ArrCheck[5] = "X";
        ArrStats[2] = 2;
    } 

    if (msg[3] == "I.A") {
        ArrCheck[7] = "X";
        ArrCheck[6] = "X";
    } else if (CheckCollisionPointRec(GetMousePosition(), ArrButtonsKey[3]) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        ArrCheck[7] = "";
        ArrCheck[6] = "X";
        ArrStats[3] = 1;
    } else if (CheckCollisionPointRec(GetMousePosition(), ArrButtonsControllers[3]) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        ArrCheck[6] = "";
        ArrCheck[7] = "X";
        ArrStats[3] = 2;
    }
    Premenu->setPreMenu(ArrCheck);
    Premenu->setPreMenuMsg(msg);
}



void InitEntityPreMenu(EntityManager *premenu, Font font) {

    Entity *choiceTex1 = new Entity("choice1");
    Entity *choiceTex2 = new Entity("choice2");
    Entity *choiceTex3 = new Entity("choice3");
    Entity *choiceTex4 = new Entity("choice4");
    Entity *controllerTex1 = new Entity("controller");
    Entity *controllerTex2 = new Entity("controller");
    Entity *controllerTex3 = new Entity("controller");
    Entity *controllerTex4 = new Entity("controller");
    Entity *keyboardTex1 = new Entity("keyboard");
    Entity *keyboardTex2 = new Entity("keyboard");
    Entity *keyboardTex3 = new Entity("keyboard");
    Entity *keyboardTex4 = new Entity("keyboard");
    Entity *ticket1Tex = new Entity("ticket1");
    Entity *ticket2Tex = new Entity("ticket2");
    Entity *ticket3Tex = new Entity("ticket3");
    Entity *ticket4Tex = new Entity("ticket4");
    Entity *addPlayerTex1 = new Entity("addPlayer1");
    Entity *addPlayerTex2 = new Entity("addPlayer2");
    Entity *addPlayerTex3 = new Entity("addPlayer3");
    Entity *addPlayerTex4 = new Entity("addPlayer4");
    Entity *command1Tex = new Entity("command1");
    Entity *command2Tex = new Entity("command2");
    Entity *command3Tex = new Entity("command3");
    Entity *command4Tex = new Entity("command4");
    Entity *btn_next = new Entity("btn_next");
    Entity *btn_back = new Entity("btn_back");

    premenu->addEntity(choiceTex1);
    premenu->addEntity(choiceTex2);
    premenu->addEntity(choiceTex3);
    premenu->addEntity(choiceTex4);
    premenu->addEntity(controllerTex1);
    premenu->addEntity(controllerTex2);
    premenu->addEntity(controllerTex3);
    premenu->addEntity(controllerTex4);
    premenu->addEntity(keyboardTex1);
    premenu->addEntity(keyboardTex2);
    premenu->addEntity(keyboardTex3);
    premenu->addEntity(keyboardTex4);
    premenu->addEntity(ticket1Tex);
    premenu->addEntity(ticket2Tex);
    premenu->addEntity(ticket3Tex);
    premenu->addEntity(ticket4Tex);
    premenu->addEntity(addPlayerTex1);
    premenu->addEntity(addPlayerTex2);
    premenu->addEntity(addPlayerTex3);
    premenu->addEntity(addPlayerTex4);
    premenu->addEntity(command1Tex);
    premenu->addEntity(command2Tex);
    premenu->addEntity(command3Tex);
    premenu->addEntity(command4Tex);
    premenu->addEntity(btn_next);
    premenu->addEntity(btn_back);

    choiceTex1->addComponent<SpriteRenderer>("../Models/assets/selection.png", Vector2 {70, 70});
    choiceTex2->addComponent<SpriteRenderer>("../Models/assets/selection1.png",  Vector2 {70, 70});
    choiceTex3->addComponent<SpriteRenderer>("../Models/assets/selection2.png",  Vector2 {70, 70});
    choiceTex4->addComponent<SpriteRenderer>("../Models/assets/selection3.png",  Vector2 {70, 70});
    controllerTex1->addComponent<SpriteRenderer>("../Models/assets/controller_choice.png", Vector2 {90, 90});
    controllerTex2->addComponent<SpriteRenderer>("../Models/assets/controller_choice.png", Vector2 {90, 90});
    controllerTex3->addComponent<SpriteRenderer>("../Models/assets/controller_choice.png", Vector2 {90, 90});
    controllerTex4->addComponent<SpriteRenderer>("../Models/assets/controller_choice.png", Vector2 {90, 90});
    keyboardTex1->addComponent<SpriteRenderer>("../Models/assets/clavier_choice.png", Vector2 {90, 90});
    keyboardTex2->addComponent<SpriteRenderer>("../Models/assets/clavier_choice.png", Vector2 {90, 90});
    keyboardTex3->addComponent<SpriteRenderer>("../Models/assets/clavier_choice.png", Vector2 {90, 90});
    keyboardTex4->addComponent<SpriteRenderer>("../Models/assets/clavier_choice.png", Vector2 {90, 90});
    ticket1Tex->addComponent<SpriteRenderer>("../Models/assets/ticket_player.png", Vector2 {600, 200});
    ticket2Tex->addComponent<SpriteRenderer>("../Models/assets/ticket_player2.png", Vector2 {600, 200});
    ticket3Tex->addComponent<SpriteRenderer>("../Models/assets/ticket_player3.png", Vector2 {600, 200});
    ticket4Tex->addComponent<SpriteRenderer>("../Models/assets/ticket_player4.png", Vector2 {600, 200});
    addPlayerTex1->addComponent<SpriteRenderer>("../Models/assets/remove_player.png", Vector2 {90, 90});
    addPlayerTex2->addComponent<SpriteRenderer>("../Models/assets/add_player.png", Vector2 {90, 90});
    addPlayerTex3->addComponent<SpriteRenderer>("../Models/assets/add_player.png", Vector2 {90, 90});
    addPlayerTex4->addComponent<SpriteRenderer>("../Models/assets/add_player.png", Vector2 {90, 90});
    command1Tex->addComponent<SpriteRenderer>("../Models/assets/commande0.png", Vector2 {250, 250});
    command2Tex->addComponent<SpriteRenderer>("../Models/assets/commande1.png", Vector2 {250, 250});
    command3Tex->addComponent<SpriteRenderer>("../Models/assets/commande2.png", Vector2 {250, 250});
    command4Tex->addComponent<SpriteRenderer>("../Models/assets/commande3.png", Vector2 {250, 250});
    btn_back->addComponent<SpriteRenderer>("../Models/assets/back.png", Vector2 {100, 100});
    btn_next->addComponent<SpriteRenderer>("../Models/assets/next.png", Vector2 {100, 100});


    ticket1Tex->getComponent<SpriteRenderer>().SetDrawPosition(Vector2 {150, 100});
    ticket2Tex->getComponent<SpriteRenderer>().SetDrawPosition(Vector2 {150, 325});
    ticket3Tex->getComponent<SpriteRenderer>().SetDrawPosition(Vector2 {150, 550});
    ticket4Tex->getComponent<SpriteRenderer>().SetDrawPosition(Vector2 {150, 775});
    addPlayerTex1->getComponent<SpriteRenderer>().SetDrawPosition(Vector2 {620, 150});
    addPlayerTex2->getComponent<SpriteRenderer>().SetDrawPosition(Vector2 {620, 405});
    addPlayerTex3->getComponent<SpriteRenderer>().SetDrawPosition(Vector2 {620, 630});
    addPlayerTex4->getComponent<SpriteRenderer>().SetDrawPosition(Vector2 {620, 855});
    controllerTex1->getComponent<SpriteRenderer>().SetDrawPosition(Vector2 {790, 170});
    controllerTex2->getComponent<SpriteRenderer>().SetDrawPosition(Vector2 {790, 395});
    controllerTex3->getComponent<SpriteRenderer>().SetDrawPosition(Vector2 {790, 620});
    controllerTex4->getComponent<SpriteRenderer>().SetDrawPosition(Vector2 {790, 840});
    choiceTex1->getComponent<SpriteRenderer>().SetDrawPosition(Vector2 {890, 170});
    choiceTex2->getComponent<SpriteRenderer>().SetDrawPosition(Vector2 {890, 395});
    choiceTex3->getComponent<SpriteRenderer>().SetDrawPosition(Vector2 {890, 620});
    choiceTex4->getComponent<SpriteRenderer>().SetDrawPosition(Vector2 {890, 840});
    keyboardTex1->getComponent<SpriteRenderer>().SetDrawPosition(Vector2 {980, 170});
    keyboardTex2->getComponent<SpriteRenderer>().SetDrawPosition(Vector2 {980, 395});
    keyboardTex3->getComponent<SpriteRenderer>().SetDrawPosition(Vector2 {980, 620});
    keyboardTex4->getComponent<SpriteRenderer>().SetDrawPosition(Vector2 {980, 840});
    command1Tex->getComponent<SpriteRenderer>().SetDrawPosition(Vector2 {1350, 40});
    command2Tex->getComponent<SpriteRenderer>().SetDrawPosition(Vector2 {1350, 295});
    command3Tex->getComponent<SpriteRenderer>().SetDrawPosition(Vector2 {1350, 550});
    command4Tex->getComponent<SpriteRenderer>().SetDrawPosition(Vector2 {1350, 805});
    btn_next->getComponent<SpriteRenderer>().SetDrawPosition(Vector2 {1800, 955});
    btn_back->getComponent<SpriteRenderer>().SetDrawPosition(Vector2 {30, 955});
}
