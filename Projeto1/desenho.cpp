#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "sculptor.h"

int main()
{
    Sculptor desenho(100, 50, 20);

    //Cabo
    desenho.setColor(0.05, 0.13, 0.05, 1);

    desenho.putEllipsoid(23, 12, 6, 7, 2, 1);

    //Cortes do cabo
    desenho.cutVoxel(23, 12, 7);
    desenho.cutVoxel(23, 12, 5);
    desenho.cutVoxel(23, 10, 6);
    desenho.cutVoxel(23, 14, 6);

    //Detalhes do Cabo
    desenho.setColor(0.13, 0.13, 0.13, 1);

    desenho.putBox(25, 27, 11, 11, 7, 7);
    desenho.putBox(25, 27, 13, 13, 7, 7);
    desenho.putBox(25, 27, 11, 11, 5, 5);
    desenho.putBox(25, 27, 13, 13, 5, 5);

    desenho.putVoxel(26, 10, 6);
    desenho.putVoxel(26, 14, 6);
    
    //Mais Detalhes Cabo
    desenho.putBox(27, 29, 7, 17, 5, 7);

    //Mais Cortes
    desenho.cutVoxel(27, 7, 7);
    desenho.cutVoxel(29, 7, 7);
    desenho.cutVoxel(27, 7, 5);
    desenho.cutVoxel(29, 7, 5);

    desenho.cutVoxel(27, 17, 7);
    desenho.cutVoxel(29, 17, 7);
    desenho.cutVoxel(27, 17, 5);
    desenho.cutVoxel(29, 17, 5);

    desenho.cutVoxel(27, 8, 7);
    desenho.cutVoxel(29, 8, 7);
    desenho.cutVoxel(27, 8, 5);
    desenho.cutVoxel(29, 8, 5);

    desenho.cutVoxel(27, 16, 7);
    desenho.cutVoxel(29, 16, 7);
    desenho.cutVoxel(27, 16, 5);
    desenho.cutVoxel(29, 16, 5);

    //Outro

    desenho.cutVoxel(29, 10, 7);
    desenho.cutVoxel(27, 10, 7);
    desenho.cutVoxel(29, 10, 5);
    desenho.cutVoxel(27, 10, 5);

    desenho.cutVoxel(29, 14, 7);
    desenho.cutVoxel(27, 14, 7);
    desenho.cutVoxel(29, 14, 5);
    desenho.cutVoxel(27, 14, 5);


    // ===========================================================================
    //Lamina
    desenho.setColor(0.65, 0.65, 0.65, 1);

    //Ingot
    desenho.putBox(30, 85, 10, 14, 5, 7);

    //Corte 1
    desenho.cutBox(30, 85, 10, 10, 5, 5);
    desenho.cutBox(30, 85, 10, 10, 7, 7);
    desenho.cutBox(30, 85, 14, 14, 5, 5);
    desenho.cutBox(30, 85, 14, 14, 7, 7);

    //Corte 2
    desenho.cutBox(68, 85, 11, 11, 5, 5);
    desenho.cutBox(68, 85, 11, 11, 7, 7);
    desenho.cutBox(68, 85, 13, 13, 5, 5);
    desenho.cutBox(68, 85, 13, 13, 7, 7);

    //Corte 3
    desenho.cutBox(69, 85, 10, 10, 6, 6);
    desenho.cutBox(69, 85, 14, 14, 6, 6);

    //Corte 4
    desenho.cutBox(71, 85, 12, 12, 7, 7);
    desenho.cutBox(71, 85, 12, 12, 5, 5);

    //Corte 5
    desenho.cutBox(72, 85, 11, 11, 6, 6);
    desenho.cutBox(73, 85, 12, 12, 6, 6);
    desenho.cutBox(72, 85, 13, 13, 6, 6);

    //Detalhes Cima e Baixo
    desenho.cutBox(36, 37, 11, 11, 7, 7);
    desenho.cutBox(36, 37, 13, 13, 7, 7);
    desenho.cutBox(36, 37, 11, 11, 5, 5);
    desenho.cutBox(36, 37, 13, 13, 5, 5);

    desenho.cutBox(45, 46, 11, 11, 7, 7);
    desenho.cutBox(45, 46, 13, 13, 7, 7);
    desenho.cutBox(45, 46, 11, 11, 5, 5);
    desenho.cutBox(45, 46, 13, 13, 5, 5);

    desenho.cutBox(54, 55, 11, 11, 7, 7);
    desenho.cutBox(54, 55, 13, 13, 7, 7);
    desenho.cutBox(54, 55, 11, 11, 5, 5);
    desenho.cutBox(54, 55, 13, 13, 5, 5);

    desenho.cutBox(63, 64, 11, 11, 7, 7);
    desenho.cutBox(63, 64, 13, 13, 7, 7);
    desenho.cutBox(63, 64, 11, 11, 5, 5);
    desenho.cutBox(63, 64, 13, 13, 5, 5);

    //Extra detalhe
    desenho.setColor(0.13, 0.13, 0.13, 1);

    desenho.putVoxel(30, 11, 7);
    desenho.putVoxel(30, 11, 5);
    desenho.putVoxel(30, 13, 7);
    desenho.putVoxel(30, 13, 5);

    desenho.writeOFF("./Projeto/Arquivos_OFF/desenho.off");

    desenho.~Sculptor();

    return 0;
}