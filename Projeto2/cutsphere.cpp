#include "cutsphere.h"
#include <cmath>

CutSphere :: CutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius)
{
    xcenter = _xcenter; ycenter = _ycenter; zcenter = _zcenter; radius = _radius;
}

CutSphere :: ~CutSphere()
{

}

void CutSphere :: draw(Sculptor &t)
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

                    t.cutVoxel(VoxelX, VoxelY, VoxelZ);
                }
            }
        }
    }
}
