#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
    private:
        std::string _name;
    
    public:
        Zombie(std::string name);
        ~Zombie();
        void announce() const;
        std::string getName() const
        {
            return _name; 
        }
        
        void setName(std::string name)
        { 
            _name = name; 
        }
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif
