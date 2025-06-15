#pragma once

#include "Click.hpp"

class Button
{
public:
    Button(Rectangle rec, std::string content, std::string pressedText, bool pressed, Color color = WHITE)
        : rec(rec),
          pos({rec.x, rec.y}),
          content(content),
          defaultText(content),
          pressedText(pressedText),
          pressed(pressed),
          color(color)
    {}

    Click click;

    Rectangle rec;
    Vector2 pos;
    std::string content;
    std::string defaultText;
    std::string pressedText;
    bool pressed;
    Color color;

    void Draw()
    {
        DrawRectangleRec(rec, color);
        DrawText(content.c_str(), pos.x + 10, pos.y + 20, 20, BLACK);
    }

    void IsPressed(Rectangle rec)
    {
        pressed = click.CheckClicked(rec, pressed);
    }

    void UpdateTextOnPress(bool changeText, bool toggleText)
    {
        if (!changeText) return;

        if (pressed)
        {
            if (toggleText)
            {
                content = (content == defaultText) ? pressedText : defaultText;
            }
            else
            {
                content = pressedText;
            }
        }
        else if (!toggleText)
        {
            content = defaultText;
        }
    }

    void Update(bool changeText = true, bool toggleText = false)
{
    // Detect a single new click over the button
    if (click.IsClick() && click.IsOver(rec))
    {
        // Toggle pressed state manually
        if (toggleText)
        {
            pressed = !pressed;
            content = (content == defaultText) ? pressedText : defaultText;
        }
        else if (changeText)
        {
            pressed = true;
            content = pressedText;
        }
    }
    else if (!toggleText)
    {
        pressed = false;
        content = defaultText;
    }
    Draw();
}

    void SetPressedText(const std::string& text)
    {
        pressedText = text;
    }
};
