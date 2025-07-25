#include "Zombie.hpp"

int main()
{   
    int n = 1;
    Zombie *horde = zombieHorde(n,"Zed");
    // if(!horde)
    //     return(1);
    for(int i = 0; i < n; i++)
    {
        horde[i].announce();
    }
    delete[] horde;
}