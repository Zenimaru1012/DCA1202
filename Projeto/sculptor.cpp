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

void Sculptor :: putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for(int i=x0;i<=x1;i++)
    {
        for(int j=y0;j<=y1;j++)
        {
            for(int k=z0;k<=z1;k++)
            {
                v[i][j][k].show = true;
                v[i][j][k].r = r;
                v[i][j][k].g = g;
                v[i][j][k].b = b;
                v[i][j][k].a = a;
            }
        }
    }
}

void Sculptor :: cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for(int i=x0;i<=x1;i++)
    {
        for(int j=y0;j<=y1;j++)
        {
            for(int k=z0;k<=z1;k++)
            {
                v[i][j][k].show = false;
                v[i][j][k].r = r;
                v[i][j][k].g = g;
                v[i][j][k].b = b;
                v[i][j][k].a = a;
            }
        }
    }
}

void Sculptor :: putSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    float dx, dy, dz;

    int x1 = xcenter - radius - 1, x2 = xcenter + radius + 1;
    int y1 = ycenter - radius - 1, y2 = ycenter + radius + 1;
    int z1 = zcenter - radius - 1, z2 = zcenter + radius + 1;

    for(int i=x1;i<x2;i++)
    {
        for(int j=y1;j<y2;j++)
        {
            for(int k=z1;k<z2;k++)
            {
                dx = ((static_cast <float> (i) - xcenter) / (radius)) * ((static_cast <float> (i) - xcenter) / (radius));
                dy = ((static_cast <float> (j) - ycenter) / (radius)) * ((static_cast <float> (j) - ycenter) / (radius));
                dz = ((static_cast <float> (k) - zcenter) / (radius)) * ((static_cast <float> (k) - zcenter) / (radius));

                if(dx + dy + dz <= 1)
                {
                    int VoxelX = static_cast<int>(round(static_cast<float>(i)));
                    int VoxelY = static_cast<int>(round(static_cast<float>(j)));
                    int VoxelZ = static_cast<int>(round(static_cast<float>(k)));

                    v[VoxelX][VoxelY][VoxelZ].show = true;
                    v[VoxelX][VoxelY][VoxelZ].r = r;
                    v[VoxelX][VoxelY][VoxelZ].g = g;
                    v[VoxelX][VoxelY][VoxelZ].b = b;
                    v[VoxelX][VoxelY][VoxelZ].a = a;
                }
            }
        }
    }
}

void Sculptor :: cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    float dx, dy, dz;

    int x1 = xcenter - radius - 1, x2 = xcenter + radius + 1;
    int y1 = ycenter - radius - 1, y2 = ycenter + radius + 1;
    int z1 = zcenter - radius - 1, z2 = zcenter + radius + 1;

    for(int i=x1;i<x2;i++)
    {
        for(int j=y1;j<y2;j++)
        {
            for(int k=z1;k<z2;k++)
            {
                dx = ((static_cast <float> (i) - xcenter) / (radius)) * ((static_cast <float> (i) - xcenter) / (radius));
                dy = ((static_cast <float> (j) - ycenter) / (radius)) * ((static_cast <float> (j) - ycenter) / (radius));
                dz = ((static_cast <float> (k) - zcenter) / (radius)) * ((static_cast <float> (k) - zcenter) / (radius));

                if(dx + dy + dz <= 1)
                {
                    int VoxelX = static_cast<int>(round(static_cast<float>(i)));
                    int VoxelY = static_cast<int>(round(static_cast<float>(j)));
                    int VoxelZ = static_cast<int>(round(static_cast<float>(k)));

                    v[VoxelX][VoxelY][VoxelZ].show = false;
                    v[VoxelX][VoxelY][VoxelZ].r = r;
                    v[VoxelX][VoxelY][VoxelZ].g = g;
                    v[VoxelX][VoxelY][VoxelZ].b = b;
                    v[VoxelX][VoxelY][VoxelZ].a = a;
                }
            }
        }
    }
}

void Sculptor :: putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    float dx, dy, dz;

    int x1 = xcenter - rx - 1, x2 = xcenter + rx + 1;
    int y1 = ycenter - ry - 1, y2 = ycenter + ry + 1;
    int z1 = zcenter - rz - 1, z2 = zcenter + rz + 1;

    for(int i=x1;i<x2;i++)
    {
        for(int j=y1;j<y2;j++)
        {
            for(int k=z1;k<z2;k++)
            {
                dx = (pow(static_cast<float> (i - xcenter),2)) / (rx * rx);
                dy = (pow(static_cast<float> (j - ycenter),2)) / (ry * ry);
                dz = (pow(static_cast<float> (k - zcenter),2)) / (rz * rz);

                if((dx + dy + dz) <= 1)
                {
                    int VoxelX = static_cast<int>(round(static_cast<float>(i)));
                    int VoxelY = static_cast<int>(round(static_cast<float>(j)));
                    int VoxelZ = static_cast<int>(round(static_cast<float>(k)));

                    v[VoxelX][VoxelY][VoxelZ].show = true;
                    v[VoxelX][VoxelY][VoxelZ].r = r;
                    v[VoxelX][VoxelY][VoxelZ].g = g;
                    v[VoxelX][VoxelY][VoxelZ].b = b;
                    v[VoxelX][VoxelY][VoxelZ].a = a;
                }
            }
        }
    }
}

void Sculptor :: cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    float dx, dy, dz;

    int x1 = xcenter - rx - 1, x2 = xcenter + rx + 1;
    int y1 = ycenter - ry - 1, y2 = ycenter + ry + 1;
    int z1 = zcenter - rz - 1, z2 = zcenter + rz + 1;

    for(int i=x1;i<x2;i++)
    {
        for(int j=y1;j<y2;j++)
        {
            for(int k=z1;k<z2;k++)
            {
                dx = (pow(static_cast<float> (i - xcenter),2)) / (rx * rx);
                dy = (pow(static_cast<float> (j - ycenter),2)) / (ry * ry);
                dz = (pow(static_cast<float> (k - zcenter),2)) / (rz * rz);

                if((dx + dy + dz) <= 1)
                {
                    int VoxelX = static_cast<int>(round(static_cast<float>(i)));
                    int VoxelY = static_cast<int>(round(static_cast<float>(j)));
                    int VoxelZ = static_cast<int>(round(static_cast<float>(k)));

                    v[VoxelX][VoxelY][VoxelZ].show = false;
                    v[VoxelX][VoxelY][VoxelZ].r = r;
                    v[VoxelX][VoxelY][VoxelZ].g = g;
                    v[VoxelX][VoxelY][VoxelZ].b = b;
                    v[VoxelX][VoxelY][VoxelZ].a = a;
                }
            }
        }
    }
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