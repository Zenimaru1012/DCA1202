#include "putellipsoid.h"
#include <cmath>

PutEllipsoid :: PutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz, float _r, float _g, float _b, float _a)
{
    xcenter = _xcenter; ycenter = _ycenter; zcenter = _zcenter;
    rx = _rx; ry = _ry; rz = _rz;
    r = _r; g = _g; b = _b; a = _a;
}

PutEllipsoid :: ~PutEllipsoid()
{

}

void PutEllipsoid :: draw(Sculptor &t)
{
    t.setColor(r, g, b, a);

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

                    t.putVoxel(VoxelX, VoxelY, VoxelZ);
                }
            }
        }
    }
}
