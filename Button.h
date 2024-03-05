#include "SceneManager.h"
#include <raylib.h>

class Button
{
public:
    Button(Vector2 position, Vector2 size, const char* text, Scene scene);
    ~Button();

    void Draw(Font ft);

    bool IsPressed();

private:
    Rectangle rectangle;
    const char* buttonText;
    Scene associatedScene;
    bool isPressed;
};
