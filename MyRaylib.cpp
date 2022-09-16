//
// Created by tcampagne on 02/06/22.
//

#include "MyRaylib.hpp"

void MyRaylib::myInitWindow(int width, int height, const char *title) {
    InitWindow(width, height, title);
}

RLAPI void MyRaylib::myRlDisableBackfaceCulling() {
    rlDisableBackfaceCulling();
}

void MyRaylib::mySetCameraMode(Camera camera, int mode) {
    SetCameraMode(camera, mode);
}

bool MyRaylib::myDirectoryExists(const char *dirPath) {
    return (DirectoryExists(dirPath));
}

bool MyRaylib::myFileExists(const char *fileName) {
    return (FileExists(fileName));
}

char* MyRaylib::myLoadFileText(const char *fileName) {
    return (LoadFileText(fileName));
}

void MyRaylib::mySetTargetFPS(int fps) {
    SetTargetFPS(fps);
}

bool MyRaylib::myWindowShouldClose() {
    return (WindowShouldClose());
}

bool MyRaylib::myIsKeyPressed(int key) {
    return (IsKeyPressed(key));
}

bool MyRaylib::mySaveFileText(const char *fileName, char *text) {
    return (SaveFileText(fileName, text));
}

bool MyRaylib::myCheckCollisionPointRec(Vector2 point, Rectangle rec) {
    return (CheckCollisionPointRec(point, rec));
}

Vector2 MyRaylib::myGetMousePosition() {
    return (GetMousePosition());
}

bool MyRaylib::myIsMouseButtonPressed(int button) {
    return (IsMouseButtonPressed(button));
}

void MyRaylib::mySetMouseCursor(int cursor) {
    SetMouseCursor(cursor);
}

int MyRaylib::myGetCharPressed() {
    return (GetCharPressed());
}

float MyRaylib::myGetMouseWheelMove() {
    return (GetMouseWheelMove());
}

void MyRaylib::myUpdateCamera(Camera *camera) {
    UpdateCamera(camera);
}

void MyRaylib::myBeginDrawing() {
    BeginDrawing();
}

void MyRaylib::myClearBackground(Color color) {
    ClearBackground(color);
}

void MyRaylib::myBeginMode3D(Camera3D camera) {
    BeginMode3D(camera);
}

void MyRaylib::myDrawGrid(int slices, float spacing) {
    DrawGrid(slices, spacing);
}

void MyRaylib::myEndMode3D() {
    EndMode3D();
}

void MyRaylib::myDrawRectangleRec(Rectangle rec, Color color) {
    DrawRectangleRec(rec, color);
}

void MyRaylib::myDrawRectangle(int posX, int posY, int width, int height, Color color) {
    DrawRectangle(posX, posY, width, height, color);
}

void MyRaylib::myDrawText(const char *text, int posX, int posY, int fontSize, Color color) {
    DrawText(text, posX, posY, fontSize, color);
}

int MyRaylib::myMeasureText(const char *text, int fontSize) {
    return (MeasureText(text, fontSize));
}

void MyRaylib::myBeginScissorMode(int x, int y, int width, int height) {
    BeginScissorMode(x, y, width, height);
}

void MyRaylib::myEndScissorMode() {
    EndScissorMode();
}

void MyRaylib::myEndDrawing() {
    EndDrawing();
}

void MyRaylib::myCloseWindow() {
    CloseWindow();
}

void MyRaylib::mySetMaterialTexture(Material *material, int mapType, Texture2D texture) {
    SetMaterialTexture(material, mapType, texture);
}

void MyRaylib::mySetModelMeshMaterial(Model *model, int meshId, int materialId) {
    SetModelMeshMaterial(model, meshId, materialId);
}

void MyRaylib::myDrawModelEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale,
                             Color tint) {
    DrawModelEx(model, position, rotationAxis, rotationAngle, scale, tint);
}

char** MyRaylib::myGetDirectoryFiles(const char *dirPath, int *count) {
    return (GetDirectoryFiles(dirPath, count));
}

bool MyRaylib::myIsFileExtension(const char *fileName, const char *ext) {
    return (IsFileExtension(fileName, ext));
}

Model MyRaylib::myLoadModel(const char *fileName) {
    return (LoadModel(fileName));
}

Texture2D MyRaylib::myLoadTexture(const char *fileName) {
    return (LoadTexture(fileName));
}

/*void MyRayLib::myDrawCube(Vector3 position, float width, float height, float length, Color color)
{
    DrawCube(position, width, height, length, color);
}*/