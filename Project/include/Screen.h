#pragma once

class Screen
{
public:
    Screen();
    virtual void Update() = 0;
    virtual void Render() = 0;
    virtual void HandleEvents() = 0;
private:

};
