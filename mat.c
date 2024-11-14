#include "mat.h"
#include <stdlib.h>
#include <string.h>

Mat createMat(int row, int col, short channels, size_t elemSize1)
{
    Mat mat = {
        .rows      = row,
        .cols      = col,
        .channels  = channels,
        .step      = col * channels * elemSize1,
        .elemSize  = channels * elemSize1,
        .elemSize1 = elemSize1,
        .data      = (unsigned char*)malloc(row * mat.step),
    };
    return mat;
}

Mat copyMat(const Mat* m)
{
    Mat mat  = *m;
    mat.data = (unsigned char*)malloc(m->rows * m->step);
    return mat;
}

void deleteMat(Mat* m)
{
    free(m->data);
    m->data = NULL;
}