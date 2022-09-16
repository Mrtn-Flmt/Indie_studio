//
// Created by tcampagne on 02/06/22.
//

#ifndef YEP_400_MYRAYLIB_HPP
#define YEP_400_MYRAYLIB_HPP

#include "raylib.h"
#include "rlgl.h"

class MyRaylib {
public:
    MyRaylib() = default;
    ~MyRaylib() = default;

    void myInitWindow(int width, int height, const char *title);
    RLAPI void myRlDisableBackfaceCulling(void);
    void mySetCameraMode(Camera camera, int mode);
    bool myDirectoryExists(const char *dirPath);
    bool myFileExists(const char *fileName);
    char *myLoadFileText(const char *fileName);
    void mySetTargetFPS(int fps);
    bool myWindowShouldClose(void);
    bool myIsKeyPressed(int key);
    bool mySaveFileText(const char *fileName, char *text);
    bool myCheckCollisionPointRec(Vector2 point, Rectangle rec);
    Vector2 myGetMousePosition(void);
    bool myIsMouseButtonPressed(int button);
    void mySetMouseCursor(int cursor);
    int myGetCharPressed(void);
    float myGetMouseWheelMove(void);
    void myUpdateCamera(Camera *camera);
    void myBeginDrawing(void);
    void myClearBackground(Color color);
    void myBeginMode3D(Camera3D camera);
    void myDrawGrid(int slices, float spacing);
    void myEndMode3D(void);
    void myDrawRectangle(int posX, int posY, int width, int height, Color color);
    void myDrawRectangleRec(Rectangle rec, Color color);
    void myDrawText(const char *text, int posX, int posY, int fontSize, Color color);
    int myMeasureText(const char *text, int fontSize);
    void myBeginScissorMode(int x, int y, int width, int height);
    void myEndScissorMode(void);
    void myEndDrawing(void);
    void myCloseWindow(void);
    void mySetMaterialTexture(Material *material, int mapType, Texture2D texture);
    void mySetModelMeshMaterial(Model *model, int meshId, int materialId);
    void myDrawModelEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint);
    char **myGetDirectoryFiles(const char *dirPath, int *count);
    bool myIsFileExtension(const char *fileName, const char *ext);
    Model myLoadModel(const char *fileName);
    Texture2D myLoadTexture(const char *fileName);
    void myDrawCube(Vector3, float, float, float, Color);
    void myDrawSphere(Vector3, float, Color);
    void myDrawCylinder(Vector3, float, float, float, int, Color);
};


#endif //YEP_400_MYRAYLIB_HPP
