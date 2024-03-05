#include "SceneManager.h"
#include "Button.h"
#include "raylib.h"

Button::Button(Vector2 position, Vector2 size, const char* text, Scene scene)
    : rectangle({ position.x, position.y, size.x, size.y }),
    buttonText(text),
    associatedScene(scene),
    isPressed(false)
{
}

Button::~Button()
{
}

void Button::Draw(Font ft)
{
    DrawRectangleRec(rectangle, isPressed ? RED : GRAY);
    DrawTextEx(ft, buttonText, Vector2{ rectangle.x + 10, rectangle.y + 10 }, 20, 2, WHITE);
}

bool Button::IsPressed()
{
    if (CheckCollisionPointRec(GetMousePosition(), rectangle) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        isPressed = true;
        return true;
    }
    else
    {
        isPressed = false;
        return false;
    }
}
