#include "BomberMan.hpp"
#include "ECS/SpriteRenderer.hpp"


typedef enum GameScreen {GAMEPLAY, DEVELOP, LOADING, TUTO, IA, OPTION} GameScreen;

int main()
{
    MyRaylib rayLib;
    PreMenu *Premenu = new PreMenu();
    Developpement *dev = new Developpement();
    Menu menuClass;
    rayLib.myInitWindow(1920, 1080, "Bomberman");
    ToggleFullscreen();
    rayLib.myRlDisableBackfaceCulling();
    InitAudioDevice();
    Music music = LoadMusicStream("../Models/Audio/harry_GreatHall.mp3");
    Font font = LoadFontEx("../Models/HARRYP__.TTF", 96, 0, 0);
    Sound fxWav = LoadSound("../Models/Audio/buttons_sound.wav");
    SetSoundVolume(fxWav, 0.2f);
    std::string loading_text = "PRESS SPACE";
    std::string play_text = "PLAY";
    std::string option_text = "OPTION";
    std::string tuto_text = "TUTO";
    std::string quit_text = "QUIT";
    float fontsize = (float)font.baseSize;
    std::vector <std::string> msg = {"Joueur 1", "I.A", "I.A", "I.A"};
    Rectangle Btn_play = {1920/2 - 111, 200, 230, 60};
    Rectangle Btn_tuto = {1920/2 - 111, 600, 230, 60};
    Rectangle Btn_next = {1800, 955, 100, 100};
    Rectangle Btn_back = {30, 955, 100, 100};
    float volume = 1.0f;
    float lastVolume = volume;
    std::string volumeText = dev->to_string_with_precision(volume * 100, 0);
    SetMasterVolume(volume);
    Rectangle btnMute = {575, 500, 70, 70};
    bool devSystem = false;
    bool BTN_START_PLAY = false;
    std::vector <bool> btnAction = {true, false, false, false};
    std::vector <Rectangle> ArrButtonsKey = {{980, 170, 90, 90}, {980, 395, 90, 90}, {980, 620, 90, 90}, {980, 840, 90, 90}};
    std::vector <Rectangle> ArrButtonsControllers = {{790, 170, 90, 90}, {790, 395, 90, 90}, {790, 620, 90, 90}, {790, 840, 90, 90}};
    std::vector <Rectangle> ArrButtonsPlayer = {{620, 120, 100, 160}, {620, 350, 100, 160}, {620, 570, 100, 160}, {620, 800, 100, 160}};
    std::array<std::string, 8> ArrCheck = {"", "", "", "", "", "", "", ""};
    int status1, status2, status3, status4 = 0;
    std::array<int, 4> ArrStats = {status1, status2, status3, status4};
    Image new_cursor = LoadImage("../Models/Cursor/cursor_nothing.png");
    Image new_cursor_press = LoadImage("../Models/Cursor/cursor_thunder.png");
    ImageResize(&new_cursor, 100, 100);
    ImageResize(&new_cursor_press, 100, 100);
    Texture2D cursor_wand_press = LoadTextureFromImage(new_cursor_press);
    Texture2D cursor_wand = LoadTextureFromImage(new_cursor);
    Vector2 ballPosition = { -100.0f, -100.0f };

    int framesCounter = 0;
    bool menu_check = false;
    bool play_button = false;
    GameScreen CurrentScreen = LOADING;

    EntityManager *manager = new EntityManager();
    EntityManager *load = new EntityManager();
    EntityManager *menu = new EntityManager();
    EntityManager *premenu = new EntityManager();
    EntityManager *tuto = new EntityManager();
    EntityManager *option = new EntityManager();
    Entity *btn_back = new Entity("btn_back");

    option->addEntity(btn_back);
    btn_back->addComponent<SpriteRenderer>("../Models/assets/back.png", Vector2 {100, 100});
    btn_back->getComponent<SpriteRenderer>().SetDrawPosition(Vector2 {30, 955});


    InitEntityToEntityLoad(load);
    InitEntityToEntityManager(manager);
    InitEntityToEntityMenu(menu, font);
    InitEntityPreMenu(premenu, font);
    InitEntityToEntityTuto(tuto);
    EntityManager *game = new EntityManager();
    InitEntityToEntityLoad(load);
    InitEntityToEntityManager(manager);
    InitEntityToGameEntityManager(game);
    manager->stockEntitiesName();
    BombRenderer *bomb = nullptr;

    PlayMusicStream(music);
    HideCursor();
    dev->init(manager);
    dev->LoadEntityDataNewGame(manager);
    rayLib.mySetTargetFPS(60);
    while (!rayLib.myWindowShouldClose()) {
        switch (CurrentScreen) {
            case DEVELOP: {
            if (IsKeyPressed(KEY_C)) {
                if (!devSystem)
                    devSystem = true;
                else
                    devSystem = false;
                }
                dev->SaveEntityDataNewGame(manager);
                dev->TransformEntitySelectedGestion(manager);
                dev->EntitySelectedGestion(manager);
                ballPosition= GetMousePosition();
                manager->update();
                UpdateMusicStream(music);
                if ((CheckCollisionPointRec(GetMousePosition(), Btn_play) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {
                    CurrentScreen = IA;
                    PlaySoundMulti(fxWav);
                    for (auto &ent : manager->entities)
                        if (ent->name == "camera" || ent->name == "Camera") {
                            ent->getComponent<CameraECS>().setGameplayOptions();
                        }
                } if ((CheckCollisionPointRec(GetMousePosition(), Btn_tuto) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {
                    CurrentScreen = TUTO;
                    PlaySoundMulti(fxWav);

                }   if ((CheckCollisionPointRec(GetMousePosition(), menuClass.getBtnOption()) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {
                    CurrentScreen = OPTION;
                    PlaySoundMulti(fxWav);
                }

                rayLib.myBeginDrawing();
                    rayLib.myClearBackground(BROWN);
                    rayLib.myBeginMode3D(manager->getEntityCamera());
                        manager->draw();
                        rayLib.myDrawGrid(100, 1.0f);
                    rayLib.myEndMode3D();
                    manager->draw();
                    if (manager->getEntityCamera().position.z == -40) {
                        EntitySelectionGestionMenu(menu);
                        menu->draw();
                        DrawTextEx(font, (char*)play_text.c_str(), {920, 208}, 45, 0, WHITE);
                        DrawTextEx(font, (char*)option_text.c_str(), {905, 408}, 45, 0, WHITE);
                        DrawTextEx(font, (char*)tuto_text.c_str(), {910, 608}, 45, 0, WHITE);
                        DrawTextEx(font, (char*)quit_text.c_str(), {920, 808}, 45, 0, WHITE);
                    }
                    if (devSystem)
                        dev->Draw();
                    DrawTexture(cursor_wand, ballPosition.x, ballPosition.y, WHITE);
                    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                        DrawTexture(cursor_wand_press, ballPosition.x, ballPosition.y, WHITE);
                rayLib.myEndDrawing();
            } break;
            // ICI /////////////////////////////////////////////////////////////////////////////////////////
            case GAMEPLAY: {
                game->update();
                if (rayLib.myIsKeyPressed(KEY_M))
                    CurrentScreen = LOADING;
                rayLib.myBeginDrawing();
                rayLib.myClearBackground(WHITE);
                rayLib.myBeginMode3D(manager->getEntityCamera());
                game->draw();
                rayLib.myEndMode3D();
                rayLib.myEndDrawing();
            } break;
            case IA: {
                GestionPreMenu(premenu, Premenu);
                ballPosition= GetMousePosition();
                manager->update();
                UpdateMusicStream(music);
                if ((CheckCollisionPointRec(GetMousePosition(), Btn_play) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)))
                    rayLib.myClearBackground(ORANGE);
                rayLib.myBeginDrawing();
                    rayLib.myClearBackground(BROWN);
                    rayLib.myBeginMode3D(manager->getEntityCamera());
                        manager->draw();
                        rayLib.myDrawGrid(100, 1.0f);
                    rayLib.myEndMode3D();
                    manager->draw();
                    premenu->draw();
                    DrawTextEx(font, (char*)Premenu->getPreMenuMsg()[0].c_str(), {300, 170}, fontsize, 0, BLACK);
                    DrawTextEx(font, (char*)Premenu->getPreMenuMsg()[1].c_str(), {300, 395}, fontsize, 0, BLACK);
                    DrawTextEx(font, (char*)Premenu->getPreMenuMsg()[2].c_str(), {300, 620}, fontsize, 0, BLACK);
                    DrawTextEx(font, (char*)Premenu->getPreMenuMsg()[3].c_str(), {300, 845}, fontsize, 0, BLACK);
                    DrawTextEx(font, (char*)Premenu->getPreMenu()[0].c_str(), {1000, 170},  fontsize, 0, BLACK);
                    DrawTextEx(font, (char*)Premenu->getPreMenu()[1].c_str(), {810, 170},  fontsize, 0, BLACK);
                    DrawTextEx(font, (char*)Premenu->getPreMenu()[2].c_str(), {1000, 395},  fontsize, 0, BLACK);
                    DrawTextEx(font, (char*)Premenu->getPreMenu()[3].c_str(), {810, 395},  fontsize, 0, BLACK);
                    DrawTextEx(font, (char*)Premenu->getPreMenu()[4].c_str(), {1000, 620},  fontsize, 0, BLACK);
                    DrawTextEx(font, (char*)Premenu->getPreMenu()[5].c_str(), {810, 620},  fontsize, 0, BLACK);
                    DrawTextEx(font, (char*)Premenu->getPreMenu()[6].c_str(), {1000, 845},  fontsize, 0, BLACK);
                    DrawTextEx(font, (char*)Premenu->getPreMenu()[7].c_str(), {810, 845},  fontsize, 0, BLACK);

                    if (CheckCollisionPointRec(GetMousePosition(), ArrButtonsKey[0]) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                        ArrCheck[1] = "";
                        ArrCheck[0] = "X";
                        ArrStats[0] = 1;
                    } else if (CheckCollisionPointRec(GetMousePosition(), ArrButtonsControllers[0]) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                        ArrCheck[0] = "";
                        ArrCheck[1] = "X";
                        ArrStats[0] = 2;
                    }

                    if (CheckCollisionPointRec(GetMousePosition(), Btn_next) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                        CurrentScreen = GAMEPLAY;
                    
                    if (CheckCollisionPointRec(GetMousePosition(), Btn_back) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                        CurrentScreen = DEVELOP;
                
                dev->Draw();
                DrawTexture(cursor_wand, ballPosition.x, ballPosition.y, WHITE);
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                    DrawTexture(cursor_wand_press, ballPosition.x, ballPosition.y, WHITE);
            rayLib.myEndDrawing();
            } break;
            // ICI /////////////////////////////////////////////////////////////////////////////////////////
            case LOADING: {
                framesCounter++;
                ballPosition= GetMousePosition();
                manager->update();
                // UpdateMusicStream(music);
                if (rayLib.myIsKeyPressed(KEY_SPACE))
                    CurrentScreen = DEVELOP;
                rayLib.myBeginDrawing();
                    rayLib.myClearBackground(WHITE);
                    load->draw();
                    DrawTexture(cursor_wand, ballPosition.x, ballPosition.y, WHITE);
                    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                        DrawTexture(cursor_wand_press, ballPosition.x, ballPosition.y, WHITE);
                    if ((framesCounter/30) % 2)
                        DrawTextEx(font, (char*)loading_text.c_str(), {720, 170}, 100, 0, WHITE);
                rayLib.myEndDrawing();
            }break;
            case TUTO: {
                manager->update();
                ballPosition= GetMousePosition();
                UpdateMusicStream(music);
                rayLib.myClearBackground(ORANGE);
                rayLib.myBeginDrawing();
                    rayLib.myClearBackground(BROWN);
                    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                        DrawTexture(cursor_wand_press, ballPosition.x, ballPosition.y, WHITE);
                    }
                    if (CheckCollisionPointRec(GetMousePosition(), Btn_back) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                        CurrentScreen = DEVELOP;

                    rayLib.myBeginMode3D(manager->getEntityCamera());
                        manager->draw();
                        rayLib.myDrawGrid(100, 1.0f);
                    rayLib.myEndMode3D();
                    manager->draw();
                dev->Draw();
                tuto->draw();
                DrawTexture(cursor_wand, ballPosition.x, ballPosition.y, WHITE);
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                    DrawTexture(cursor_wand_press, ballPosition.x, ballPosition.y, WHITE);
            rayLib.myEndDrawing();
            } break;
            case OPTION: {
                manager->update();
                UpdateMusicStream(music);
                ballPosition = GetMousePosition();
                if (CheckCollisionPointCircle(rayLib.myGetMousePosition(), (Vector2){450, 700}, 40) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && volume > 0.0f &&
                IsMusicStreamPlaying(music)) {
                    volume -= 0.01f;
                    volumeText = dev->to_string_with_precision(volume * 100, 0);
                    SetMasterVolume(volume);
                    lastVolume = volume;
                }
                if (CheckCollisionPointCircle(rayLib.myGetMousePosition(), (Vector2){750, 700}, 40) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && volume < 1.0f &&
                IsMusicStreamPlaying(music)) {
                    volume += 0.01f;
                    volumeText = dev->to_string_with_precision(volume * 100, 0);
                    SetMasterVolume(volume);
                    lastVolume = volume;
                }
                if (CheckCollisionPointRec(GetMousePosition(), Btn_back) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                    CurrentScreen = DEVELOP;
                if (rayLib.myCheckCollisionPointRec(rayLib.myGetMousePosition(), btnMute) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    if (!IsMusicStreamPlaying(music)) {
                        volume = lastVolume;
                        volumeText = dev->to_string_with_precision(volume * 100, 0);
                        ResumeMusicStream(music);
                    } else {
                        volume = 0.0f;
                        volumeText = dev->to_string_with_precision(volume * 100, 0);
                        PauseMusicStream(music);
                    }
                }
                rayLib.myBeginDrawing();
                    rayLib.myClearBackground(BROWN);
                    manager->draw();
                    option->draw();
                    DrawRectangle(300, 300, 1400, 600, BROWN);
                DrawRectangleRec(btnMute, BLACK);
                DrawCircle(450, 700, 40, BLACK);
                DrawTextEx(font, "Mute", {1000, 500}, 100, 0, BLACK);
                DrawTextEx(font, (char*)volumeText.c_str(), {550, 650}, 100, 0, BLACK);
                DrawTextEx(font, "Volume", {1000, 700}, 100, 0, BLACK);
                DrawCircle(750, 700, 40, BLACK);
                DrawTexture(cursor_wand, ballPosition.x, ballPosition.y, WHITE);
                DrawTextEx(font, "-", {435, 650}, 100, 0, WHITE);
                DrawTextEx(font, "+", {735, 650}, 100, 0, WHITE);
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                    DrawTexture(cursor_wand_press, ballPosition.x, ballPosition.y, WHITE);
                rayLib.myEndDrawing();
            } break;
    }
}
    UnloadMusicStream(music);
    CloseAudioDevice();     // Close audio device
    rayLib.myCloseWindow();
  	return 0;
}
