#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

#include "sculptor.h"

Sculptor :: Sculptor (int _nx, int _ny, int _nz)
{
    nx = _nx;
    ny = _ny;
    nz = _nz;

    v = new Voxel ** [nx];

    if(v == nullptr)
    {
        std::cout << "v não armazenado" << std::endl;
                exit (0);
    }

    v[0] = new Voxel * [nx * ny];

    if(v[0] == nullptr)
    {
        std::cout << "v[0] não armazenado" << std::endl;
                exit (0);
    }

    v[0][0] = new Voxel [nx * ny * nz];

    if(v[0][0] == nullptr)
    {
        std::cout << "v[0][0] não armazenado" << std::endl;
                exit(0);
    }

    for(int i=0;i<nx;i++)
    {
        if(i < (nx-1))
        {
            v[i+1] = v[i] + ny;
        }

        for(int j=0;j<ny;j++)
        {
            if(j == ny-1 && i != (nx-1))
            {
                v[i+1][0] = v[i][j] + nz;
            }else
            {
                v[i][j+1] = v[i][j] + nz;
            }

            for(int k=0;k<nz;k++)
            {
                v[i][j][k].r = 0.0;
                v[i][j][k].g = 0.0;
                v[i][j][k].b = 0.0;
                v[i][j][k].a = 0.0;
                v[i][j][k].show = false;
            }
        }
    }
}

Sculptor :: ~Sculptor ()
{
    delete [] v[0][0];
    delete [] v[0];
    delete [] v;
}

void Sculptor :: setColor (float _r, float _g, float _b, float _a)
{
    r = _r;
    g = _g;
    b = _b;
    a = _a;
}

void Sculptor :: putVoxel(int _x, int _y, int _z)
{
    v[_x][_y][_z].show = true;
    v[_x][_y][_z].r = r;
    v[_x][_y][_z].g = g;
    v[_x][_y][_z].b = b;
    v[_x][_y][_z].a = a;
}

void Sculptor :: cutVoxel(int _x, int _y, int _z)
{
    v[_x][_y][_z].show = false;
    v[_x][_y][_z].r = r;
    v[_x][_y][_z].g = g;
    v[_x][_y][_z].b = b;
    v[_x][_y][_z].a = a;
}

void Sculptor :: writeOFF(const std::string filename)
{
    std::cout << "Arquivo sendo gerado..." << std::endl;

    int Nf, Nv, vox = 0, nfc = 0, face;

    std::ofstream fout;

    fout.open(filename);

    if(fout.is_open())
    {
        std::cout << "Arquivo aberto (OFF)" << std::endl;
    }else
    {
        std::cout << "Arquivo não aberto (OFF)" << std::endl;
                exit (1);
    }

    fout << "OFF" << std::endl;

    for(int i=0;i<nx;i++)
    {
        for(int j=0;j<ny;j++)
        {
            for(int k=0;k<nz;k++)
            {
                if(v[i][j][k].show)
                {
                    vox++;
                }
            }
        }
    }

    Nf = 6 * vox;
    Nv = 8 * vox;

    fout << Nv << " " << Nf << " 0" << std::endl;

    float bX, aX, bY, aY, bZ, aZ;

    for(int k=0;k<nz;k++)
    {
        bZ = -0.5 + k;
        aZ = 0.5 + k;

        for(int j=0;j<ny;j++)
        {
            bY = -0.5 + j;
            aY = 0.5 + j;

            for(int i=0;i<nx;i++)
            {
                bX = -0.5 + i;
                aX = 0.5 + i;

                if(v[i][j][k].show)
                {
                    fout << bX << " " << aY << " " << bZ << std::endl;
                    fout << bX << " " << bY << " " << bZ << std::endl;
                    fout << aX << " " << bY << " " << bZ << std::endl;
                    fout << aX << " " << aY << " " << bZ << std::endl;
                    fout << bX << " " << aY << " " << aZ << std::endl;
                    fout << bX << " " << bY << " " << aZ << std::endl;
                    fout << aX << " " << bY << " " << aZ << std::endl;
                    fout << aX << " " << aY << " " << aZ << std::endl;
                }
            }
        }
    }

    for(int k=0;k<nz;k++)
    {
        for(int j=0;j<ny;j++)
        {
            for(int i=0;i<nx;i++)
            {
                if(v[i][j][k].show)
                {
                    face = nfc * 8;

                    fout << "4 " << 0 + face << " " << 3 + face << " " << 2 + face << " " << 1 + face << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    fout << "4 " << 4 + face << " " << 5 + face << " " << 6 + face << " " << 7 + face << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    fout << "4 " << 0 + face << " " << 1 + face << " " << 5 + face << " " << 4 + face << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    fout << "4 " << 0 + face << " " << 4 + face << " " << 7 + face << " " << 3 + face << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    fout << "4 " << 3 + face << " " << 7 + face << " " << 6 + face << " " << 2 + face << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    fout << "4 " << 1 + face << " " << 2 + face << " " << 6 + face << " " << 5 + face << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;

                    nfc++;
                }
            }
        }
    }

    std::cout << "Arquivo gerado..." << std::endl;

    fout.close();
}
