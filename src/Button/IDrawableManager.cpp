#include "IDrawableManager.hpp"
#include <exception>
#include <memory>
#include <iostream>

int DrawableManager::AddButton(int xPosition, int yPosition, int width, int height, int color)
{
    std::shared_ptr<Drawable::IDrawable> currentButton = nullptr;
    try 
    {
        currentButton = std::shared_ptr<Drawable::IDrawable>(this->_drawableFactory.CreateButton(xPosition, yPosition, width, height));
    } 
    catch (std::exception e) 
    {
        std::cerr<<e.what();
        return 1;
    }
    this->_components.push_back(currentButton);
    return 0;
}

void DrawableManager::DrawEverything(Shaders::ShadersUtils& shader)
{
    for(std::shared_ptr<Drawable::IDrawable>& curr: this->_components)
    {
        curr->Draw(shader);
    }
}
void DrawableManager::CheckHover(int x, int y)
{
    for(std::shared_ptr<Drawable::IDrawable>& curr: this->_components)
    {
        curr->OnHover(x,y);
    }
}