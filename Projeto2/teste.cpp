#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "sculptor.h"
#include "figurageometrica.h"
#include "putvoxel.h"
#include "cutvoxel.h"
#include "putbox.h"
#include "cutbox.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"

int main()
{
    std::ifstream ler;
    ler.open("Arquivos/teste.txt");

    if(!ler)
    {
        std::cout << "Não abriu" << std::endl;
        exit(1);
    }

    std::vector <std::string> linhas;
    std::string linha;
    std::vector <int>::iterator it;

    while(std::getline(ler, linha))
    {
        linhas.push_back(linha);
    }

    int nx = 0, ny = 0, nz = 0;

    std::stringstream head(linhas[0]);

    std::string nome;
    head >> nome;
    head >> nx >> ny >> nz;

    Sculptor t(nx, ny, nz);
    std::vector <FiguraGeometrica *> figura;

    for(int i=1;i<linhas.size(); i++)
    {
        std::stringstream tipo(linhas[i]);
        tipo >> nome;

        if(nome == "putVoxel")
        {
            int x, y, z;
            float r, g, b, a;
            tipo >> x >> y >> z >> r >> g >> b >> a;
            figura.push_back(new PutVoxel(x,y,z,r,g,b,a));
        }

        else if(nome == "cutVoxel")
        {
            int x, y, z;
            tipo >> x >> y >> z;
            figura.push_back(new CutVoxel(x,y,z));
        }

        else if(nome == "putBox")
        {
            int x0, x1, y0, y1, z0, z1;
            float r, g, b, a;
            tipo >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
            figura.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
        }

        else if(nome == "cutBox")
        {
            int x0, x1, y0, y1, z0, z1;
            tipo >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
            figura.push_back(new CutBox(x0, x1, y0, y1, z0, z1));
        }

        else if(nome == "putSphere")
        {
            int x, y, z, raio;
            float r, g, b, a;
            tipo >> x >> y >> z >> raio >> r >> g >> b >> a;
            figura.push_back(new PutSphere(x, y, z, raio, r, g, b, a));
        }

        else if(nome == "cutSphere")
        {
            int x, y, z, raio;
            tipo >> x >> y >> z >> raio;
            figura.push_back(new CutSphere(x, y, z, raio));
        }

        else if(nome == "putEllipsoid")
        {
            int x, y, z, rx, ry, rz;
            float r, g, b, a;
            tipo >> x >> y >> z >> rx >> ry >> rz >> r >> g >> b >> a;
            figura.push_back(new PutEllipsoid(x, y, z, rx, ry, rz, r, g, b, a));
        }

        else if(nome == "cutEllipsoid")
        {
            int x, y, z, rx, ry, rz;
            tipo >> x >> y >> z >> rx >> ry >> rz;
            figura.push_back(new CutEllipsoid(x, y, z, rx, ry, rz));
        }
    }

    for(int i=0; i<figura.size(); i++)
    {
        figura[i] -> draw(t);
    }

    for(int i=0; i<figura.size(); i++)
    {
        delete figura[i];
    }

    t.writeOFF("ArquivosOFF/teste.off");
    ler.close();

    return 0;
}
