#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "sculptor.h"

int main()
{
    Sculptor teste(50,50,50);
    
    teste.setColor(1,0.3,0.3,1);

    teste.putBox(0,49,0,49,0,10);

    teste.cutBox(15,35,0,49,0,5);

    teste.setColor(0,1,0.9,1);

    teste.putSphere(40,40,40,9);

    teste.cutSphere(10,10,15,10);

    teste.setColor(1,0.5,0.8,1);

    teste.putVoxel(45,10,45);

    teste.cutVoxel(45,10,10);

    teste.cutEllipsoid(25,25,15,20,20,10);

    teste.setColor(1,0.6,0,1);

    teste.putEllipsoid(30,20,35,15,10,10);

    teste.writeOFF("./Projeto/Arquivos_OFF/teste.off");

    teste.~Sculptor();

    return 0;
}