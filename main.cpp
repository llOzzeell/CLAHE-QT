#include <QDebug>
#include <QProcess>
#include <QImage>
#include <stdio.h>
#include "CLAHE.c"

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    QImage image("/home/ozzee/input.bmp");

    unsigned int uiXRes = image.width(); // Image resolution in the X direction
    unsigned int uiYRes = image.height(); // Image resolution in the Y direction
    kz_pixel_t Min = 0; // Minimum greyvalue of input image (also becomes minimum of output image)
    kz_pixel_t Max = 255; // Maximum greyvalue of input image (also becomes maximum of output image)
    unsigned int uiNrX = 4; // Number of contextial regions in the X direction (min 2, max uiMAX_REG_X)
    unsigned int uiNrY = 4; // Number of contextial regions in the Y direction (min 2, max uiMAX_REG_Y)
    unsigned int uiNrBins = 256; // Number of greybins for histogram ("dynamic range")
    float fCliplimit = 32; // Normalized cliplimit (higher values give more contrast)

    qDebug() << "CLAHE finished. Result:" << CLAHE (image.bits(), uiXRes, uiYRes, Min, Max, uiNrX, uiNrY, uiNrBins, fCliplimit);

    image.save("/home/ozzee/output.bmp", "BMP");

    QProcess::startDetached("eog", QStringList() << "/home/ozzee/output.bmp");
    QProcess::startDetached("eog", QStringList() << "/home/ozzee/input.bmp");

    return 0;
}
