#include <conio.h>
#include <Windows.h>
#include <iostream>
#include "Gun.h"



void HandleInput(bool* running, Gun* gun)
{
    if (_kbhit())
    {
        char key = _getch();
        std::cout << "Key pressed : " << key << std::endl;
        switch (key)
        {
        case 27:
            *running = false;
            break;
        case 'r':
            gun->Reload();
            break;
        case 'a':
            gun->Shoot();
            break;
        default:
            break;
        }
    }
}

int main()
{
    Gun gun;
    bool running = true;

    float dt = 0.16f;

    while (running)
    {
        HandleInput(&running, &gun);
        gun.Update(dt);

        Sleep(dt * 1000);
    }
    return 0;
}