#pragma warning(disable : 4996)

#include<windows.h> 
#include <stdio.h>
#include <stdlib.h>
#include<gl/Gl.h>
#include<GL/glut.h>

int n;
int m;

// The size of any of the units.
float unitSize = 15.0;

// Makes sure the unit labels are approximately in the middle of the unit.
int xLabelOffset = 4;
int yLabelOffset = 13;

// Shows how many 10-minute increments have passed. Theoretically can be any integer, but the program is handled to detect if it goes above 31.
int time = 0;

// Coordinate data for all the units.
double custerX[32] = { 0.0, 755.0, 805.0, 805.0, 790.0, 760.0, 710.0, 660.0, 615.0, 515.0, 410.0, 375.0, 390.0, 330.0, 215.0, 110.0, 110.0, 110.0, 110.0, 110.0, 110.0, 110.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
double custerY[32] = { 0.0, 90.0, 180.0, 180.0, 180.0, 250.0, 300.0, 350.0, 405.0, 405.0, 485.0, 585.0, 655.0, 645.0, 660.0, 755.0, 755.0, 755.0, 755.0, 755.0, 755.0, 755.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

double fX[32] = { 0.0, 755.0, 795.0, 795.0, 795.0, 770.0, 720.0, 670.0, 625.0, 525.0, 415.0, 375.0, 385.0, 345.0, 225.0, 120.0, 105.0, 105.0, 105.0, 105.0, 105.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
double fY[32] = { 0.0, 75.0, 170.0, 170.0, 170.0, 240.0, 290.0, 340.0, 400.0, 400.0, 475.0, 575.0, 650.0, 640.0, 650.0, 740.0, 760.0, 760.0, 760.0, 760.0, 760.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

double cX[32] = { 0.0, 760.0, 785.0, 785.0, 785.0, 780.0, 730.0, 680.0, 635.0, 540.0, 415.0, 380.0, 380.0, 360.0, 235.0, 140.0, 135.0, 135.0, 135.0, 135.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
double cY[32] = { 0.0, 60.0, 160.0, 160.0, 160.0, 230.0, 280.0, 330.0, 390.0, 400.0, 460.0, 565.0, 640.0, 635.0, 640.0, 725.0, 770.0, 770.0, 770.0, 770.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

double eX[32] = { 0.0, 760.0, 775.0, 775.0, 775.0, 785.0, 740.0, 690.0, 645.0, 555.0, 420.0, 385.0, 380.0, 370.0, 245.0, 160.0, 155.0, 155.0, 155.0, 155.0, 185.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
double eY[32] = { 0.0, 45.0, 150.0, 150.0, 150.0, 220.0, 270.0, 320.0, 380.0, 400.0, 445.0, 555.0, 630.0, 620.0, 630.0, 710.0, 780.0, 780.0, 780.0, 780.0, 765.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

double iX[32] = { 0.0, 765.0, 765.0, 765.0, 765.0, 790.0, 750.0, 700.0, 655.0, 570.0, 425.0, 385.0, 380.0, 370.0, 255.0, 180.0, 155.0, 155.0, 155.0, 155.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
double iY[32] = { 0.0, 30.0, 140.0, 140.0, 140.0, 210.0, 260.0, 310.0, 370.0, 405.0, 430.0, 545.0, 620.0, 610.0, 620.0, 695.0, 710.0, 710.0, 710.0, 710.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

double lX[32] = { 0.0, 765.0, 765.0, 765.0, 765.0, 790.0, 760.0, 710.0, 660.0, 585.0, 445.0, 385.0, 375.0, 370.0, 265.0, 200.0, 200.0, 200.0, 200.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
double lY[32] = { 0.0, 15.0, 130.0, 130.0, 130.0, 200.0, 250.0, 300.0, 360.0, 405.0, 425.0, 535.0, 610.0, 600.0, 610.0, 580.0, 580.0, 580.0, 580.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

double aX[32] = { 0.0, 825.0, 825.0, 825.0, 890.0, 945.0, 930.0, 830.0, 745.0, 670.0, 670.0, 675.0, 675.0, 740.0, 745.0, 700.0, 700.0, 700.0, 700.0, 700.0, 700.0, 700.0, 700.0, 705.0, 665.0, 590.0, 550.0, 550.0, 650.0, 720.0, 700.0, 700.0 };
double aY[32] = { 0.0, 75.0, 165.0, 165.0, 215.0, 300.0, 365.0, 450.0, 560.0, 645.0, 645.0, 585.0, 585.0, 555.0, 415.0, 320.0, 320.0, 320.0, 320.0, 320.0, 320.0, 320.0, 320.0, 310.0, 365.0, 430.0, 460.0, 460.0, 380.0, 325.0, 320.0, 320.0 };

double mX[32] = { 0.0, 820.0, 810.0, 815.0, 880.0, 945.0, 945.0, 855.0, 765.0, 685.0, 685.0, 675.0, 675.0, 730.0, 735.0, 725.0, 725.0, 725.0, 725.0, 725.0, 725.0, 725.0, 725.0, 725.0, 725.0, 725.0, 725.0, 705.0, 680.0, 705.0, 725.0, 725.0 };
double mY[32] = { 0.0, 60.0, 150.0, 155.0, 205.0, 275.0, 380.0, 475.0, 580.0, 660.0, 660.0, 580.0, 580.0, 560.0, 420.0, 330.0, 330.0, 330.0, 330.0, 330.0, 330.0, 330.0, 330.0, 330.0, 330.0, 330.0, 330.0, 325.0, 335.0, 315.0, 330.0, 330.0 };

double gX[32] = { 0.0, 820.0, 820.0, 805.0, 870.0, 935.0, 950.0, 855.0, 785.0, 700.0, 710.0, 680.0, 680.0, 750.0, 755.0, 750.0, 750.0, 750.0, 750.0, 750.0, 750.0, 750.0, 750.0, 750.0, 750.0, 750.0, 750.0, 690.0, 665.0, 715.0, 750.0, 750.0 };
double gY[32] = { 0.0, 45.0, 130.0, 140.0, 195.0, 275.0, 350.0, 450.0, 600.0, 675.0, 660.0, 570.0, 570.0, 560.0, 420.0, 315.0, 315.0, 315.0, 315.0, 315.0, 315.0, 315.0, 315.0, 315.0, 315.0, 330.0, 315.0, 330.0, 355.0, 315.0, 315.0, 315.0 };

double hX[32] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 765.0, 820.0, 820.0, 745.0, 710.0, 710.0, 710.0, 710.0, 710.0, 710.0, 695.0, 640.0, 565.0, 525.0, 525.0, 625.0, 685.0, 710.0, 710.0, 710.0, 710.0 };
double hY[32] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 40.0, 170.0, 245.0, 285.0, 290.0, 290.0, 290.0, 290.0, 290.0, 290.0, 320.0, 390.0, 445.0, 470.0, 470.0, 390.0, 315.0, 290.0, 290.0, 290.0, 290.0 };

double dX[32] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 765.0, 805.0, 835.0, 760.0, 690.0, 690.0, 690.0, 690.0, 690.0, 645.0, 565.0, 535.0, 535.0, 535.0, 535.0, 640.0, 690.0, 690.0, 690.0, 690.0, 690.0 };
double dY[32] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 25.0, 155.0, 230.0, 275.0, 305.0, 305.0, 305.0, 305.0, 325.0, 385.0, 445.0, 475.0, 475.0, 475.0, 475.0, 400.0, 325.0, 305.0, 305.0, 305.0, 305.0 };

double kX[32] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 765.0, 790.0, 850.0, 770.0, 760.0, 760.0, 760.0, 760.0, 760.0, 760.0, 715.0, 650.0, 580.0, 545.0, 545.0, 640.0, 700.0, 760.0, 760.0, 760.0, 760.0 };
double kY[32] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 10.0, 140.0, 215.0, 270.0, 295.0, 295.0, 295.0, 295.0, 295.0, 295.0, 320.0, 380.0, 435.0, 480.0, 480.0, 390.0, 330.0, 295.0, 295.0, 305.0, 295.0 };

double bX[32] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 765.0, 765.0, 775.0, 790.0, 815.0, 830.0, 830.0, 800.0, 765.0, 735.0, 735.0, 735.0, 695.0, 665.0, 680.0, 735.0, 735.0, 735.0, 735.0 };
double bY[32] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 25.0, 50.0, 100.0, 135.0, 170.0, 195.0, 240.0, 260.0, 280.0, 280.0, 280.0, 280.0, 315.0, 340.0, 305.0, 280.0, 280.0, 280.0, 280.0 };

double packtrainX[32] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 765.0, 765.0, 770.0, 785.0, 805.0, 820.0, 830.0, 820.0, 800.0, 760.0, 725.0, 725.0, 725.0, 725.0, 725.0, 725.0, 725.0, 725.0, 725.0 };
double packtrainY[32] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 10.0, 35.0, 85.0, 120.0, 160.0, 185.0, 225.0, 245.0, 265.0, 285.0, 300.0, 300.0, 300.0, 300.0, 300.0, 300.0, 300.0, 300.0, 300.0 };

double crazyHorseX[32] = { 640.0, 640.0, 640.0, 640.0, 640.0, 640.0, 640.0, 640.0, 655.0, 670.0, 670.0, 690.0, 690.0, 720.0, 675.0, 470.0, 300.0, 220.0, 210.0, 165.0, 120.0, 120.0, 160.0, 160.0, 160.0, 265.0, 395.0, 510.0, 615.0, 665.0, 685.0, 685.0 };
double crazyHorseY[32] = { 670.0, 670.0, 670.0, 670.0, 670.0, 670.0, 670.0, 670.0, 670.0, 670.0, 670.0, 595.0, 595.0, 585.0, 645.0, 665.0, 650.0, 660.0, 665.0, 700.0, 745.0, 745.0, 720.0, 720.0, 720.0, 665.0, 560.0, 510.0, 415.0, 350.0, 330.0, 330.0 };

double gallX[32] = {460.0, 460.0, 460.0, 460.0, 460.0, 460.0, 460.0, 460.0, 460.0, 460.0, 520.0, 470.0, 410.0, 375.0, 305.0, 160.0, 135.0, 140.0, 135.0, 140.0, 135.0, 140.0, 135.0, 140.0, 115.0, 115.0, 115.0, 115.0, 115.0, 115.0, 115.0, 115.0};
double gallY[32] = {770.0, 770.0, 770.0, 770.0, 770.0, 770.0, 770.0, 770.0, 770.0, 770.0, 730.0, 725.0, 675.0, 660.0, 700.0, 820.0, 800.0, 780.0, 800.0, 780.0, 800.0, 780.0, 800.0, 780.0, 760.0, 760.0, 760.0, 760.0, 760.0, 760.0, 760.0, 760.0};

// done
double naUnit1X[32] = {625.0, 625.0, 625.0, 625.0, 625.0, 625.0, 625.0, 625.0, 640.0, 675.0, 675.0, 700.0, 700.0, 710.0, 680.0, 680.0, 415.0, 230.0, 230.0, 145.0, 85.0, 85.0, 85.0, 140.0, 140.0, 140.0, 140.0, 140.0, 140.0, 140.0, 140.0, 140.0};
double naUnit1Y[32] = {655.0, 655.0, 655.0, 655.0, 655.0, 655.0, 655.0, 655.0, 655.0, 675.0, 560.0, 560.0, 560.0, 570.0, 650.0, 650.0, 675.0, 665.0, 665.0, 755.0, 750.0, 750.0, 750.0, 775.0, 775.0, 775.0, 775.0, 775.0, 775.0, 775.0, 775.0, 775.0};

// done
double naUnit2X[32] = { 605.0, 605.0, 605.0, 605.0, 605.0, 605.0, 605.0, 605.0, 630.0, 680.0, 680.0, 700.0, 700.0, 700.0, 695.0, 620.0, 315.0, 220.0, 220.0, 135.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0 };
double naUnit2Y[32] = { 645.0, 645.0, 645.0, 645.0, 645.0, 645.0, 645.0, 645.0, 655.0, 680.0, 680.0, 565.0, 565.0, 565.0, 665.0, 670.0, 640.0, 665.0, 665.0, 755.0, 745.0, 745.0, 745.0, 750.0, 750.0, 750.0, 750.0, 750.0, 750.0, 750.0, 750.0, 750.0 };

// done
double naUnit3X[32] = { 595.0, 595.0, 595.0, 595.0, 595.0, 595.0, 595.0, 595.0, 630.0, 685.0, 685.0, 700.0, 700.0, 700.0, 675.0, 650.0, 325.0, 235.0, 235.0, 145.0, 100.0, 100.0, 100.0, 100.0, 100.0, 225.0, 380.0, 500.0, 580.0, 650.0, 670.0, 675.0 };
double naUnit3Y[32] = { 655.0, 655.0, 655.0, 655.0, 655.0, 655.0, 655.0, 655.0, 670.0, 685.0, 685.0, 570.0, 570.0, 570.0, 580.0, 660.0, 660.0, 660.0, 670.0, 765.0, 740.0, 745.0, 745.0, 745.0, 745.0, 600.0, 500.0, 505.0, 405.0, 310.0, 280.0, 260.0 };

// done
double naUnit4X[32] = { 590.0, 590.0, 590.0, 590.0, 590.0, 590.0, 590.0, 590.0, 645.0, 665.0, 665.0, 695.0, 695.0, 695.0, 680.0, 660.0, 340.0, 225.0, 225.0, 155.0, 110.0, 110.0, 110.0, 110.0, 110.0, 240.0, 380.0, 450.0, 580.0, 695.0, 675.0, 675.0 };
double naUnit4Y[32] = { 680.0, 680.0, 680.0, 680.0, 680.0, 680.0, 680.0, 680.0, 475.0, 665.0, 665.0, 575.0, 575.0, 575.0, 575.0, 665.0, 650.0, 705.0, 705.0, 750.0, 735.0, 735.0, 735.0, 735.0, 735.0, 665.0, 626.0, 540.0, 430.0, 360.0, 325.0, 325.0 };

// done
double naUnit5X[32] = { 600.0, 600.0, 600.0, 600.0, 600.0, 600.0, 600.0, 600.0, 655.0, 660.0, 660.0, 695.0, 695.0, 695.0, 600.0, 475.0, 335.0, 220.0, 220.0, 155.0, 155.0, 155.0, 155.0, 155.0, 155.0, 250.0, 350.0, 365.0, 530.0, 645.0, 695.0, 695.0 };
double naUnit5Y[32] = { 705.0, 705.0, 705.0, 705.0, 705.0, 705.0, 705.0, 705.0, 680.0, 660.0, 660.0, 580.0, 580.0, 580.0, 700.0, 690.0, 675.0, 705.0, 705.0, 720.0, 740.0, 740.0, 740.0, 740.0, 740.0, 685.0, 635.0, 590.0, 450.0, 375.0, 335.0, 335.0 };

// done
double naUnit6X[32] = { 615.0, 615.0, 615.0, 615.0, 615.0, 615.0, 615.0, 615.0, 630.0, 655.0, 655.0, 690.0, 690.0, 690.0, 680.0, 585.0, 360.0, 235.0, 235.0, 165.0, 130.0, 155.0, 155.0, 155.0, 155.0, 155.0, 155.0, 155.0, 155.0, 155.0, 155.0, 155.0 };
double naUnit6Y[32] = { 690.0, 690.0, 690.0, 690.0, 690.0, 690.0, 690.0, 690.0, 680.0, 655.0, 655.0, 585.0, 585.0, 585.0, 590.0, 680.0, 640.0, 690.0, 690.0, 720.0, 740.0, 710.0, 710.0, 710.0, 710.0, 710.0, 710.0, 710.0, 710.0, 710.0, 710.0, 710.0 };

// done
double naUnit7X[32] = { 630.0, 630.0, 630.0, 630.0, 630.0, 630.0, 630.0, 630.0, 660.0, 650.0, 650.0, 690.0, 690.0, 690.0, 690.0, 690.0, 380.0, 235.0, 235.0, 170.0, 115.0, 115.0, 115.0, 115.0, 115.0, 255.0, 375.0, 410.0, 545.0, 640.0, 665.0, 665.0 };
double naUnit7Y[32] = { 700.0, 700.0, 700.0, 700.0, 700.0, 700.0, 700.0, 700.0, 690.0, 650.0, 650.0, 590.0, 590.0, 590.0, 670.0, 670.0, 625.0, 705.0, 705.0, 710.0, 730.0, 730.0, 730.0, 730.0, 730.0, 680.0, 605.0, 585.0, 450.0, 380.0, 310.0, 310.0 };

// done
double naUnit8X[32] = { 560.0, 560.0, 560.0, 560.0, 560.0, 560.0, 560.0, 560.0, 630.0, 690.0, 730.0, 690.0, 690.0, 690.0, 515.0, 390.0, 370.0, 230.0, 230.0, 175.0, 140.0, 205.0, 205.0, 205.0, 205.0, 205.0, 205.0, 205.0, 205.0, 205.0, 205.0, 205.0 };
double naUnit8Y[32] = { 765.0, 765.0, 765.0, 765.0, 765.0, 765.0, 765.0, 765.0, 725.0, 690.0, 660.0, 595.0, 595.0, 595.0, 690.0, 655.0, 645.0, 660.0, 660.0, 705.0, 710.0, 680.0, 680.0, 680.0, 680.0, 680.0, 680.0, 680.0, 680.0, 680.0, 680.0, 680.0 };

// done
double naUnit9X[32] = { 540.0, 540.0, 540.0, 540.0, 540.0, 540.0, 540.0, 540.0, 615.0, 680.0, 725.0, 685.0, 685.0, 685.0, 755.0, 560.0, 375.0, 230.0, 230.0, 155.0, 160.0, 165.0, 165.0, 165.0, 165.0, 220.0, 390.0, 520.0, 565.0, 635.0, 650.0, 650.0 };
double naUnit9Y[32] = { 775.0, 775.0, 775.0, 775.0, 775.0, 775.0, 775.0, 775.0, 730.0, 690.0, 665.0, 600.0, 600.0, 600.0, 575.0, 665.0, 665.0, 700.0, 700.0, 700.0, 715.0, 730.0, 730.0, 730.0, 730.0, 695.0, 580.0, 520.0, 385.0, 335.0, 315.0, 315.0 };

// done
double naUnit10X[32] = { 525.0, 525.0, 525.0, 525.0, 525.0, 525.0, 525.0, 525.0, 615.0, 695.0, 720.0, 685.0, 685.0, 695.0, 680.0, 680.0, 385.0, 225.0, 225.0, 150.0, 190.0, 190.0, 190.0, 190.0, 190.0, 220.0, 390.0, 520.0, 565.0, 635.0, 650.0, 650.0 };
double naUnit10Y[32] = { 760.0, 760.0, 760.0, 760.0, 760.0, 760.0, 760.0, 760.0, 740.0, 695.0, 675.0, 605.0, 605.0, 605.0, 655.0, 655.0, 660.0, 710.0, 710.0, 705.0, 670.0, 670.0, 670.0, 670.0, 670.0, 695.0, 580.0, 520.0, 385.0, 335.0, 315.0, 315.0 };

// done
double naUnit11X[32] = { 540.0, 540.0, 540.0, 540.0, 540.0, 540.0, 540.0, 540.0, 600.0, 705.0, 715.0, 680.0, 680.0, 715.0, 730.0, 700.0, 430.0, 300.0, 210.0, 145.0, 75.0, 75.0, 145.0, 155.0, 155.0, 155.0, 155.0, 155.0, 155.0, 155.0, 155.0, 155.0 };
double naUnit11Y[32] = { 740.0, 740.0, 740.0, 740.0, 740.0, 740.0, 740.0, 740.0, 735.0, 690.0, 680.0, 610.0, 610.0, 560.0, 435.0, 615.0, 665.0, 665.0, 690.0, 710.0, 745.0, 745.0, 760.0, 760.0, 760.0, 760.0, 760.0, 760.0, 760.0, 760.0, 760.0, 760.0 };

// done
double naUnit12X[32] = { 560.0, 560.0, 560.0, 560.0, 560.0, 560.0, 560.0, 560.0, 590.0, 705.0, 700.0, 670.0, 570.0, 720.0, 750.0, 705.0, 455.0, 320.0, 215.0, 170.0, 85.0, 85.0, 95.0, 95.0, 95.0, 95.0, 95.0, 95.0, 95.0, 95.0, 95.0, 95.0 };
double naUnit12Y[32] = { 740.0, 740.0, 740.0, 740.0, 740.0, 740.0, 740.0, 740.0, 730.0, 700.0, 690.0, 630.0, 660.0, 575.0, 460.0, 620.0, 650.0, 660.0, 690.0, 700.0, 740.0, 740.0, 745.0, 740.0, 740.0, 740.0, 740.0, 740.0, 740.0, 740.0, 740.0, 740.0 };

// done
double naUnit13X[32] = { 545.0, 545.0, 545.0, 545.0, 545.0, 545.0, 545.0, 545.0, 580.0, 640.0, 640.0, 705.0, 695.0, 735.0, 790.0, 720.0, 495.0, 360.0, 220.0, 185.0, 135.0, 135.0, 135.0, 135.0, 135.0, 185.0, 315.0, 435.0, 625.0, 715.0, 785.0, 785.0 };
double naUnit13Y[32] = { 645.0, 645.0, 645.0, 645.0, 645.0, 645.0, 645.0, 645.0, 650.0, 645.0, 645.0, 605.0, 655.0, 575.0, 500.0, 610.0, 665.0, 645.0, 680.0, 690.0, 770.0, 770.0, 770.0, 770.0, 770.0, 720.0, 685.0, 605.0, 465.0, 375.0, 320.0, 320.0 };

// done
double naUnit14X[32] = { 535.0, 535.0, 535.0, 535.0, 535.0, 535.0, 535.0, 535.0, 575.0, 650.0, 650.0, 695.0, 720.0, 720.0, 770.0, 735.0, 500.0, 380.0, 200.0, 205.0, 140.0, 140.0, 140.0, 140.0, 140.0, 175.0, 295.0, 420.0, 600.0, 700.0, 750.0, 770.0 };
double naUnit14Y[32] = { 630.0, 630.0, 630.0, 630.0, 630.0, 630.0, 630.0, 630.0, 665.0, 660.0, 660.0, 630.0, 590.0, 590.0, 500.0, 585.0, 675.0, 660.0, 660.0, 700.0, 700.0, 700.0, 700.0, 700.0, 700.0, 725.0, 700.0, 615.0, 515.0, 380.0, 355.0, 330.0 };

// done
double naUnit15X[32] = { 530.0, 530.0, 530.0, 530.0, 530.0, 530.0, 530.0, 530.0, 560.0, 660.0, 660.0, 670.0, 555.0, 750.0, 745.0, 740.0, 695.0, 470.0, 285.0, 200.0, 130.0, 130.0, 130.0, 130.0, 130.0, 155.0, 245.0, 380.0, 560.0, 675.0, 725.0, 725.0 };
double naUnit15Y[32] = { 655.0, 655.0, 655.0, 655.0, 655.0, 655.0, 655.0, 655.0, 655.0, 670.0, 670.0, 645.0, 655.0, 580.0, 430.0, 390.0, 630.0, 655.0, 665.0, 680.0, 780.0, 780.0, 780.0, 780.0, 780.0, 725.0, 690.0, 635.0, 530.0, 425.0, 350.0, 350.0 };

// done
double naUnit16X[32] = { 510.0, 510.0, 510.0, 510.0, 510.0, 510.0, 510.0, 510.0, 555.0, 635.0, 635.0, 680.0, 600.0, 730.0, 760.0, 735.0, 660.0, 495.0, 300.0, 205.0, 155.0, 155.0, 155.0, 155.0, 155.0, 135.0, 235.0, 370.0, 540.0, 650.0, 740.0, 740.0 };
double naUnit16Y[32] = { 655.0, 655.0, 655.0, 655.0, 655.0, 655.0, 655.0, 655.0, 560.0, 655.0, 655.0, 655.0, 675.0, 545.0, 430.0, 400.0, 650.0, 665.0, 675.0, 685.0, 765.0, 765.0, 765.0, 765.0, 765.0, 735.0, 695.0, 650.0, 550.0, 420.0, 350.0, 350.0 };

// done
double naUnit17X[32] = { 505.0, 505.0, 505.0, 505.0, 505.0, 505.0, 505.0, 505.0, 600.0, 660.0, 660.0, 575.0, 440.0, 390.0, 345.0, 285.0, 240.0, 240.0, 240.0, 240.0, 200.0, 200.0, 200.0, 200.0, 200.0, 200.0, 200.0, 200.0, 200.0, 200.0, 200.0, 200.0 };
double naUnit17Y[32] = { 640.0, 640.0, 640.0, 640.0, 640.0, 640.0, 640.0, 640.0, 665.0, 665.0, 665.0, 665.0, 650.0, 645.0, 640.0, 665.0, 695.0, 695.0, 695.0, 695.0, 755.0, 755.0, 755.0, 755.0, 755.0, 755.0, 755.0, 755.0, 755.0, 755.0, 755.0, 755.0 };

// done
double naUnit18X[32] = { 520.0, 520.0, 520.0, 520.0, 520.0, 520.0, 520.0, 520.0, 555.0, 665.0, 665.0, 560.0, 435.0, 380.0, 340.0, 300.0, 240.0, 240.0, 240.0, 240.0, 200.0, 200.0, 200.0, 200.0, 200.0, 200.0, 200.0, 200.0, 200.0, 200.0, 200.0, 200.0 };
double naUnit18Y[32] = { 635.0, 635.0, 635.0, 635.0, 635.0, 635.0, 635.0, 635.0, 650.0, 670.0, 670.0, 665.0, 655.0, 660.0, 655.0, 670.0, 685.0, 685.0, 685.0, 685.0, 740.0, 740.0, 740.0, 740.0, 740.0, 740.0, 740.0, 740.0, 740.0, 740.0, 740.0, 740.0 };

// done
double naUnit19X[32] = { 435.0, 435.0, 435.0, 435.0, 435.0, 435.0, 435.0, 435.0, 435.0, 435.0, 435.0, 410.0, 340.0, 340.0, 340.0, 210.0, 70.0, 85.0, 70.0, 85.0, 100.0, 100.0, 160.0, 160.0, 160.0, 160.0, 160.0, 160.0, 160.0, 160.0, 160.0, 160.0 };
double naUnit19Y[32] = { 780.0, 780.0, 780.0, 780.0, 780.0, 780.0, 780.0, 780.0, 780.0, 780.0, 780.0, 755.0, 735.0, 735.0, 735.0, 800.0, 785.0, 775.0, 785.0, 760.0, 760.0, 760.0, 715.0, 715.0, 715.0, 715.0, 715.0, 715.0, 715.0, 715.0, 715.0, 715.0 };

// done
double naUnit20X[32] = { 460.0, 460.0, 460.0, 460.0, 460.0, 460.0, 460.0, 460.0, 460.0, 460.0, 460.0, 395.0, 330.0, 330.0, 330.0, 220.0, 80.0, 80.0, 80.0, 80.0, 90.0, 90.0, 95.0, 95.0, 95.0, 95.0, 95.0, 95.0, 95.0, 95.0, 95.0, 95.0 };
double naUnit20Y[32] = { 795.0, 795.0, 795.0, 795.0, 795.0, 795.0, 795.0, 795.0, 795.0, 795.0, 795.0, 780.0, 740.0, 740.0, 740.0, 795.0, 790.0, 790.0, 790.0, 790.0, 770.0, 770.0, 765.0, 765.0, 765.0, 765.0, 765.0, 765.0, 765.0, 765.0, 765.0, 765.0 };

// done
double naUnit21X[32] = { 480.0, 480.0, 480.0, 480.0, 480.0, 480.0, 480.0, 480.0, 480.0, 480.0, 510.0, 470.0, 440.0, 440.0, 440.0, 240.0, 95.0, 95.0, 95.0, 95.0, 95.0, 95.0, 95.0, 95.0, 95.0, 95.0, 95.0, 95.0, 95.0, 95.0, 95.0, 95.0 };
double naUnit21Y[32] = { 775.0, 775.0, 775.0, 775.0, 775.0, 775.0, 775.0, 775.0, 775.0, 775.0, 755.0, 730.0, 665.0, 665.0, 665.0, 775.0, 790.0, 790.0, 790.0, 790.0, 775.0, 775.0, 775.0, 775.0, 775.0, 775.0, 775.0, 775.0, 775.0, 775.0, 775.0, 775.0 };

// done
double naUnit22X[32] = { 445.0, 445.0, 445.0, 445.0, 445.0, 445.0, 445.0, 445.0, 445.0, 445.0, 445.0, 450.0, 415.0, 385.0, 330.0, 185.0, 110.0, 110.0, 110.0, 110.0, 105.0, 125.0, 125.0, 125.0, 125.0, 125.0, 125.0, 125.0, 125.0, 125.0, 125.0, 125.0 };
double naUnit22Y[32] = { 755.0, 755.0, 755.0, 755.0, 755.0, 755.0, 755.0, 755.0, 755.0, 755.0, 755.0, 730.0, 680.0, 695.0, 690.0, 805.0, 795.0, 795.0, 795.0, 795.0, 775.0, 740.0, 740.0, 740.0, 740.0, 740.0, 740.0, 740.0, 740.0, 740.0, 740.0, 740.0 };

// done
double naUnit23X[32] = { 470.0, 470.0, 470.0, 470.0, 470.0, 470.0, 470.0, 470.0, 470.0, 470.0, 470.0, 410.0, 380.0, 380.0, 380.0, 175.0, 120.0, 120.0, 120.0, 120.0, 120.0, 120.0, 120.0, 120.0, 120.0, 120.0, 120.0, 120.0, 120.0, 120.0, 120.0, 120.0 };
double naUnit23Y[32] = { 750.0, 750.0, 750.0, 750.0, 750.0, 750.0, 750.0, 750.0, 750.0, 750.0, 750.0, 740.0, 730.0, 730.0, 730.0, 810.0, 800.0, 780.0, 800.0, 780.0, 780.0, 780.0, 780.0, 780.0, 780.0, 780.0, 780.0, 780.0, 780.0, 780.0, 780.0, 780.0 };

// done
double naUnit24X[32] = { 430.0, 430.0, 430.0, 430.0, 430.0, 430.0, 430.0, 430.0, 430.0, 495.0, 495.0, 430.0, 430.0, 430.0, 150.0, 130.0, 130.0, 130.0, 130.0, 115.0, 160.0, 160.0, 160.0, 160.0, 160.0, 160.0, 160.0, 160.0, 160.0, 160.0, 160.0, 160.0 };
double naUnit24Y[32] = { 705.0, 705.0, 705.0, 705.0, 705.0, 705.0, 705.0, 705.0, 705.0, 690.0, 690.0, 660.0, 660.0, 660.0, 810.0, 805.0, 805.0, 805.0, 805.0, 775.0, 785.0, 785.0, 785.0, 785.0, 785.0, 785.0, 785.0, 785.0, 785.0, 785.0, 785.0, 785.0 };

// done
double naUnit25X[32] = { 450.0, 450.0, 450.0, 450.0, 450.0, 450.0, 450.0, 450.0, 450.0, 450.0, 475.0, 475.0, 425.0, 425.0, 425.0, 120.0, 140.0, 140.0, 140.0, 140.0, 90.0, 105.0, 105.0, 105.0, 105.0, 105.0, 105.0, 105.0, 105.0, 105.0, 105.0, 105.0 };
double naUnit25Y[32] = { 700.0, 700.0, 700.0, 700.0, 700.0, 700.0, 700.0, 700.0, 700.0, 700.0, 700.0, 700.0, 665.0, 665.0, 665.0, 810.0, 810.0, 810.0, 810.0, 810.0, 780.0, 770.0, 770.0, 770.0, 770.0, 770.0, 770.0, 770.0, 770.0, 770.0, 770.0, 770.0 };

// done
double naUnit26X[32] = { 430.0, 430.0, 430.0, 430.0, 430.0, 430.0, 430.0, 430.0, 430.0, 430.0, 430.0, 430.0, 470.0, 470.0, 470.0, 130.0, 150.0, 145.0, 150.0, 145.0, 150.0, 145.0, 105.0, 115.0, 115.0, 150.0, 150.0, 150.0, 150.0, 150.0, 150.0, 150.0 };
double naUnit26Y[32] = { 685.0, 685.0, 685.0, 685.0, 685.0, 685.0, 685.0, 685.0, 680.0, 685.0, 685.0, 685.0, 670.0, 670.0, 670.0, 825.0, 805.0, 795.0, 805.0, 795.0, 805.0, 795.0, 785.0, 770.0, 770.0, 725.0, 725.0, 725.0, 725.0, 725.0, 725.0, 725.0 };

// done
double naUnit27X[32] = { 455.0, 455.0, 455.0, 455.0, 455.0, 455.0, 455.0, 455.0, 455.0, 455.0, 455.0, 455.0, 415.0, 415.0, 375.0, 305.0, 160.0, 160.0, 160.0, 160.0, 125.0, 120.0, 120.0, 120.0, 120.0, 120.0, 120.0, 120.0, 120.0, 120.0, 120.0, 120.0 };
double naUnit27Y[32] = { 680.0, 680.0, 680.0, 680.0, 680.0, 680.0, 680.0, 680.0, 680.0, 680.0, 680.0, 680.0, 675.0, 675.0, 665.0, 775.0, 815.0, 815.0, 815.0, 815.0, 780.0, 770.0, 770.0, 770.0, 770.0, 770.0, 770.0, 770.0, 770.0, 770.0, 770.0, 770.0 };

// done
double naUnit28X[32] = { 445.0, 445.0, 445.0, 445.0, 445.0, 445.0, 445.0, 445.0, 445.0, 445.0, 445.0, 445.0, 420.0, 420.0, 420.0, 280.0, 175.0, 170.0, 175.0, 170.0, 145.0, 145.0, 145.0, 145.0, 145.0, 145.0, 145.0, 145.0, 145.0, 145.0, 145.0, 145.0 };
double naUnit28Y[32] = { 670.0, 670.0, 670.0, 670.0, 670.0, 670.0, 670.0, 670.0, 670.0, 670.0, 670.0, 670.0, 675.0, 675.0, 675.0, 735.0, 810.0, 800.0, 810.0, 800.0, 705.0, 705.0, 705.0, 705.0, 705.0, 705.0, 705.0, 705.0, 705.0, 705.0, 705.0, 705.0 };

// done
double naUnit29X[32] = { 390.0, 390.0, 390.0, 390.0, 390.0, 390.0, 390.0, 390.0, 390.0, 390.0, 380.0, 380.0, 380.0, 380.0, 380.0, 210.0, 220.0, 190.0, 190.0, 190.0, 170.0, 170.0, 170.0, 170.0, 170.0, 170.0, 170.0, 170.0, 170.0, 170.0, 170.0, 170.0 };
double naUnit29Y[32] = { 775.0, 775.0, 775.0, 775.0, 775.0, 775.0, 775.0, 775.0, 775.0, 775.0, 730.0, 730.0, 730.0, 730.0, 730.0, 775.0, 800.0, 800.0, 800.0, 800.0, 735.0, 735.0, 735.0, 735.0, 735.0, 735.0, 735.0, 735.0, 735.0, 735.0, 735.0, 735.0 };

// done
double naUnit30X[32] = { 360.0, 360.0, 360.0, 360.0, 360.0, 360.0, 360.0, 360.0, 360.0, 360.0, 370.0, 370.0, 370.0, 370.0, 370.0, 155.0, 115.0, 115.0, 115.0, 115.0, 165.0, 185.0, 185.0, 185.0, 185.0, 185.0, 185.0, 185.0, 185.0, 185.0, 185.0, 185.0 };
double naUnit30Y[32] = { 770.0, 770.0, 770.0, 770.0, 770.0, 770.0, 770.0, 770.0, 770.0, 770.0, 725.0, 725.0, 725.0, 725.0, 725.0, 820.0, 815.0, 815.0, 815.0, 815.0, 745.0, 755.0, 755.0, 755.0, 755.0, 755.0, 755.0, 755.0, 755.0, 755.0, 755.0, 755.0 };

// done
double naUnit31X[32] = { 350.0, 350.0, 350.0, 350.0, 350.0, 350.0, 350.0, 350.0, 350.0, 350.0, 350.0, 350.0, 350.0, 350.0, 350.0, 120.0, 145.0, 145.0, 145.0, 145.0, 165.0, 165.0, 165.0, 200.0, 200.0, 200.0, 200.0, 200.0, 200.0, 200.0, 200.0, 200.0 };
double naUnit31Y[32] = { 760.0, 760.0, 760.0, 760.0, 760.0, 760.0, 760.0, 760.0, 760.0, 760.0, 730.0, 730.0, 730.0, 730.0, 730.0, 815.0, 825.0, 825.0, 825.0, 825.0, 755.0, 755.0, 755.0, 690.0, 690.0, 690.0, 690.0, 690.0, 690.0, 690.0, 690.0, 690.0 };

// done
double naUnit32X[32] = { 375.0, 375.0, 375.0, 375.0, 375.0, 375.0, 375.0, 375.0, 375.0, 375.0, 375.0, 375.0, 375.0, 375.0, 375.0, 340.0, 340.0, 340.0, 340.0, 320.0, 135.0, 80.0, 80.0, 80.0, 80.0, 165.0, 165.0, 165.0, 190.0, 190.0, 190.0, 190.0 };
double naUnit32Y[32] = { 760.0, 760.0, 760.0, 760.0, 760.0, 760.0, 760.0, 760.0, 760.0, 760.0, 760.0, 760.0, 760.0, 760.0, 760.0, 740.0, 740.0, 740.0, 740.0, 710.0, 825.0, 795.0, 795.0, 795.0, 795.0, 765.0, 765.0, 765.0, 680.0, 680.0, 680.0, 680.0 };

// done
double naUnit33X[32] = { 365.0, 365.0, 365.0, 365.0, 365.0, 365.0, 365.0, 365.0, 365.0, 365.0, 365.0, 365.0, 365.0, 365.0, 365.0, 360.0, 375.0, 375.0, 315.0, 175.0, 150.0, 150.0, 150.0, 150.0, 175.0, 175.0, 175.0, 175.0, 175.0, 175.0, 175.0, 175.0 };
double naUnit33Y[32] = { 745.0, 745.0, 745.0, 745.0, 745.0, 745.0, 745.0, 745.0, 745.0, 745.0, 745.0, 745.0, 745.0, 745.0, 745.0, 750.0, 730.0, 730.0, 685.0, 800.0, 835.0, 810.0, 810.0, 810.0, 780.0, 780.0, 780.0, 780.0, 780.0, 780.0, 780.0, 780.0 };

// done - finally finished inputting all the movement data!
double naUnit34X[32] = { 385.0, 385.0, 385.0, 385.0, 385.0, 385.0, 385.0, 385.0, 385.0, 385.0, 385.0, 385.0, 385.0, 385.0, 385.0, 380.0, 365.0, 365.0, 330.0, 335.0, 150.0, 125.0, 120.0, 120.0, 120.0, 180.0, 190.0, 190.0, 190.0, 190.0, 190.0, 190.0 };
double naUnit34Y[32] = { 745.0, 745.0, 745.0, 745.0, 745.0, 745.0, 745.0, 745.0, 745.0, 745.0, 745.0, 745.0, 745.0, 745.0, 745.0, 750.0, 730.0, 730.0, 700.0, 680.0, 805.0, 825.0, 805.0, 805.0, 805.0, 790.0, 780.0, 780.0, 780.0, 780.0, 780.0, 780.0 };

// These are used in the movement function so we can update the movements.
double x_pos;
double y_pos;

int* image;

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 400.0, 1.0, 400.0);
}

// This renders text at coordinates x and y.
void writeText(float x, float y, char* string) {
	glRasterPos2f(x, y);
	for (char* c = string; *c != '\0'; c++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
	}
}

void writeSmallText(float x, float y, char* string) {
	glRasterPos2f(x, y);
	for (char* c = string; *c != '\0'; c++) {
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *c);
	}
}

// This allows the drawTime function to be initiated, similar to how glBegin allows a polygon to be rendered.
void beginText() {
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, n, 0, m);
	glMatrixMode(GL_MODELVIEW);
}

// This function is used once the text has finished rendering.
void endText() {
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

// Draw a rectangle (actually, a square) of size c to be rendered at coordinates a and b.
void drawRectangle(float a, float b, float c) {
	glVertex3f(a, 925-b, 1.0);
	glVertex3f((a + c), 925-b, 1.0);
	glVertex3f((a + c), (925-b - c), 1.0);
	glVertex3f(a, (925-b - c) , 1.0);
}

void display(void)
{

	glClear(GL_COLOR_BUFFER_BIT);
	glRasterPos2i(0, 0);
	glDrawPixels(n, m, GL_RGB, GL_UNSIGNED_INT, image);

	
	float a = 700.0;
	float b = 300.0;
	glColor3f(0.0, 0.0, 1.0);

	// Custer's headquarters
	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(custerX[time], custerY[time], unitSize);
	}
	glEnd();

	// F
	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(fX[time], fY[time], unitSize);
	}
	glEnd();

	// C
	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(cX[time], cY[time], unitSize);
	}
	glEnd();

	// E
	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(eX[time], eY[time], unitSize);
	}
	glEnd();

	// I
	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(iX[time], iY[time], unitSize);
	}
	glEnd();

	// L
	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(lX[time], lY[time], unitSize);
	}
	glEnd();

	// A (Reno's command, unit 1)
	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(aX[time], aY[time], unitSize);
	}
	glEnd();

	// M (Reno's command, unit 2)
	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(mX[time], mY[time], unitSize);
	}
	glEnd();

	// G (Reno's command, unit 3)
	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(gX[time], gY[time], unitSize);
	}
	glEnd();

	// H (Benteen's command, unit 1)
	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(hX[time], hY[time], unitSize);
	}
	glEnd();

	// D (Benteen's command, unit 2)
	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(dX[time], dY[time], unitSize);
	}
	glEnd();

	// K (Benteen's command, unit 3)
	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(kX[time], kY[time], unitSize);
	}
	glEnd();
	
	// B (Packtrain guard)
	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(bX[time], bY[time], unitSize);
	}
	glEnd();

	// Packtrain
	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(packtrainX[time], packtrainY[time], unitSize);
	}
	glEnd();

	glColor3f(1.0, 0.0, 0.0);

	// Native American units 1-34
	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(naUnit1X[time], naUnit1Y[time], unitSize);
	}
	glEnd();
	
	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(naUnit2X[time], naUnit2Y[time], unitSize);
	}
	glEnd();

	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(naUnit3X[time], naUnit3Y[time], unitSize);
	}
	glEnd();

	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(naUnit4X[time], naUnit4Y[time], unitSize);
	}
	glEnd();

	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(naUnit5X[time], naUnit5Y[time], unitSize);
	}
	glEnd();

	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(naUnit6X[time], naUnit6Y[time], unitSize);
	}
	glEnd();

	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(naUnit7X[time], naUnit7Y[time], unitSize);
	}
	glEnd();

	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(naUnit8X[time], naUnit8Y[time], unitSize);
	}
	glEnd();

	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(naUnit9X[time], naUnit9Y[time], unitSize);
	}
	glEnd();

	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(naUnit10X[time], naUnit10Y[time], unitSize);
	}
	glEnd();

	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(naUnit11X[time], naUnit11Y[time], unitSize);
	}
	glEnd();

	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(naUnit12X[time], naUnit12Y[time], unitSize);
	}
	glEnd();

	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(naUnit13X[time], naUnit13Y[time], unitSize);
	}
	glEnd();

	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(naUnit14X[time], naUnit14Y[time], unitSize);
	}
	glEnd();

	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(naUnit15X[time], naUnit15Y[time], unitSize);
	}
	glEnd();

	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(naUnit16X[time], naUnit16Y[time], unitSize);
	}
	glEnd();

	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(naUnit17X[time], naUnit17Y[time], unitSize);
	}
	glEnd();

	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(naUnit18X[time], naUnit18Y[time], unitSize);
	}
	glEnd();

	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(naUnit19X[time], naUnit19Y[time], unitSize);
	}
	glEnd();

	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(naUnit20X[time], naUnit20Y[time], unitSize);
	}
	glEnd();

	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(naUnit21X[time], naUnit21Y[time], unitSize);
	}
	glEnd();

	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(naUnit22X[time], naUnit22Y[time], unitSize);
	}
	glEnd();

	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(naUnit23X[time], naUnit23Y[time], unitSize);
	}
	glEnd();

	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(naUnit24X[time], naUnit24Y[time], unitSize);
	}
	glEnd();

	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(naUnit25X[time], naUnit25Y[time], unitSize);
	}
	glEnd();

	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(naUnit26X[time], naUnit26Y[time], unitSize);
	}
	glEnd();

	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(naUnit27X[time], naUnit27Y[time], unitSize);
	}
	glEnd();

	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(naUnit28X[time], naUnit28Y[time], unitSize);
	}
	glEnd();

	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(naUnit29X[time], naUnit29Y[time], unitSize);
	}
	glEnd();

	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(naUnit30X[time], naUnit30Y[time], unitSize);
	}
	glEnd();

	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(naUnit31X[time], naUnit31Y[time], unitSize);
	}
	glEnd();

	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(naUnit32X[time], naUnit32Y[time], unitSize);
	}
	glEnd();

	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(naUnit33X[time], naUnit33Y[time], unitSize);
	}
	glEnd();

	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(naUnit34X[time], naUnit34Y[time], unitSize);
	}
	glEnd();

// Below are the display functions for Crazy Horse and Gall.

	// Crazy Horse - this is intentionally displayed on top of the other Native American units
	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(crazyHorseX[time], crazyHorseY[time], unitSize);
	}
	glEnd();

	// Gall - this is intentionally displayed on top of the other Native American units
	glBegin(GL_POLYGON);
	if (time > 31) {
		drawRectangle(0, 0, unitSize);
	}
	else {
		drawRectangle(gallX[time], gallY[time], unitSize);
	}
	glEnd();

	float legendA = 100.0;
	float legendB = 500.0;

	glColor3f(1.0, 1.0, 1.0);
	// The legend
	glBegin(GL_POLYGON);
	glVertex3f(-10+legendA, 325 + legendB, 1.0);
	glVertex3f((-10 + legendA + 120), 325 +legendB, 1.0);
	glVertex3f((-10 + legendA + 120), 325 + (legendB - 120), 1.0);
	glVertex3f(-10 + legendA, 325 + (legendB - 120), 1.0);
	glEnd();

	// Blue square representing cavalry
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	drawRectangle(100, 150, unitSize);
	glEnd();

	// Red square representing Native Americans
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	drawRectangle(100, 180, unitSize);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	beginText();
	if (time == 0)
		writeText(50.0, 850.0, "1:30");
	else if (time == 1)
		writeText(50.0, 850.0, "1:40");
	else if (time == 2)
		writeText(50.0, 850.0, "1:50");
	else if (time == 3)
		writeText(50.0, 850.0, "2:00");
	else if (time == 4)
		writeText(50.0, 850.0, "2:10");
	else if (time == 5)
		writeText(50.0, 850.0, "2:20");
	else if (time == 6)
		writeText(50.0, 850.0, "2:30");
	else if (time == 7)
		writeText(50.0, 850.0, "2:40");
	else if (time == 8)
		writeText(50.0, 850.0, "2:50");
	else if (time == 9)
		writeText(50.0, 850.0, "3:00");
	else if (time == 10)
		writeText(50.0, 850.0, "3:10");
	else if (time == 11)
		writeText(50.0, 850.0, "3:20");
	else if (time == 12)
		writeText(50.0, 850.0, "3:30");
	else if (time == 13)
		writeText(50.0, 850.0, "3:40");
	else if (time == 14)
		writeText(50.0, 850.0, "3:50");
	else if (time == 15)
		writeText(50.0, 850.0, "4:00");
	else if (time == 16)
		writeText(50.0, 850.0, "4:10");
	else if (time == 17)
		writeText(50.0, 850.0, "4:20");
	else if (time == 18)
		writeText(50.0, 850.0, "4:30");
	else if (time == 19)
		writeText(50.0, 850.0, "4:40");
	else if (time == 20)
		writeText(50.0, 850.0, "4:50");
	else if (time == 21)
		writeText(50.0, 850.0, "5:00");
	else if (time == 22)
		writeText(50.0, 850.0, "5:10");
	else if (time == 23)
		writeText(50.0, 850.0, "5:20");
	else if (time == 24)
		writeText(50.0, 850.0, "5:30");
	else if (time == 25)
		writeText(50.0, 850.0, "5:40");
	else if (time == 26)
		writeText(50.0, 850.0, "5:50");
	else if (time == 27)
		writeText(50.0, 850.0, "6:00");
	else if (time == 28)
		writeText(50.0, 850.0, "6:10");
	else if (time == 29)
		writeText(50.0, 850.0, "6:20");
	else if (time == 30)
		writeText(50.0, 850.0, "6:30");
	else
		writeText(50.0, 850.0, "6:40 - Finished");
	glColor3f(1.0, 1.0, 1.0);
	if (time > 31)
		writeText(0.0, 0.0, "*");
	else {
		// label the cavalry units (except for the packtrain)
		writeSmallText(custerX[time] + xLabelOffset, 925 -custerY[time] - yLabelOffset, "*");
		writeSmallText(fX[time] + xLabelOffset, 925-fY[time] - yLabelOffset, "F");
		writeSmallText(cX[time] + xLabelOffset, 925 - cY[time] - yLabelOffset, "C");
		writeSmallText(eX[time] + xLabelOffset, 925 - eY[time] - yLabelOffset, "E");
		writeSmallText(iX[time] + xLabelOffset, 925 - iY[time] - yLabelOffset, "I");
		writeSmallText(lX[time] + xLabelOffset, 925 - lY[time] - yLabelOffset, "L");
		writeSmallText(aX[time] + xLabelOffset, 925 - aY[time] - yLabelOffset, "A");
		writeSmallText(mX[time] + xLabelOffset, 925 - mY[time] - yLabelOffset, "M");
		writeSmallText(gX[time] + xLabelOffset, 925 - gY[time] - yLabelOffset, "G");
		writeSmallText(hX[time] + xLabelOffset, 925 - hY[time] - yLabelOffset, "H");
		writeSmallText(dX[time] + xLabelOffset, 925 - dY[time] - yLabelOffset, "D");
		writeSmallText(kX[time] + xLabelOffset, 925 - kY[time] - yLabelOffset, "K");
		writeSmallText(bX[time] + xLabelOffset, 925 - bY[time] - yLabelOffset, "B");
		writeSmallText(gallX[time] + xLabelOffset, 925 - gallY[time] - yLabelOffset, "G");

		// label Crazy Horse and Gall
		writeSmallText(crazyHorseX[time] + xLabelOffset, 925 - crazyHorseY[time] - yLabelOffset, "C");
		writeSmallText(gallX[time] + xLabelOffset, 925 - gallY[time] - yLabelOffset, "G");
	}

	glColor3f(0.0, 0.0, 0.0);
	writeText(120.0, 800.0, "LEGEND");
	writeSmallText(120.0, 765.0, "Cavalry");
	writeSmallText(120.0, 738.0, "Native");
	writeSmallText(120.0, 727.0, "Americans");
	endText();
	

	glFlush();

}

// When the mouse clicks, increment the clock by 1 and reset the display.
void mouse(int button, int state, int x, int y) {
	if ( (button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN) ) {
		time++;
		display();
	}
}

void myreshape(int h, int w)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLfloat)n, 0.0, (GLfloat)m);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glViewport(0, 0, h, w);
}

int main(int argc, char** argv)
{
	FILE* fd;
	int k, nm;
	char c;
	char b[70];
	float s;
	char red, green, blue;
	int x, y;

	fd = fopen("lb.ppm", "r");
	if (fd == 0)
	{
		exit(0);
	}


	fscanf(fd, "%s", b);
	if ((b[0] != 'P') || (b[1] != '6'))
	{
		printf("%s is not a PPM file!\n", b);
		exit(0);
	}

	fscanf(fd, "%c", &c);

	fscanf(fd, "%c", &c);
	while (c == '#')
	{
		fscanf(fd, "%[^\n]", b);
		printf("%s\n", b);
		fscanf(fd, "%c", &c);
		printf("%c", c);
	}

	ungetc(c, fd);

	fscanf(fd, "%d %d %d", &n, &m, &k);

	printf("%d rows  %d columns  max value = %d\n", n, m, k);

	nm = n * m;

	image = (int*)malloc(3 * sizeof(GLint) * nm);

	s = 255. / k;

	for (x = 0; x < m; x++)
	{
		for (y = n - 1; y >= 0; y--)
		{
			fscanf(fd, "%c", &red);
			fscanf(fd, "%c", &green);
			fscanf(fd, "%c", &blue);

			image[3 * nm - 3 * (x * n + y) - 3] = green;
			image[3 * nm - 3 * (x * n + y) - 2] = blue;
			image[3 * nm - 3 * (x * n + y) - 1] = red;

		}
	}


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(n, m);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("CS 460 Project - Little Bighorn");
	glutReshapeFunc(myreshape);
	glutDisplayFunc(display);
	glPixelTransferf(GL_RED_SCALE, s);
	glPixelTransferf(GL_GREEN_SCALE, s);
	glPixelTransferf(GL_BLUE_SCALE, s);
	glPixelStorei(GL_UNPACK_SWAP_BYTES, GL_TRUE);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glutMouseFunc(mouse);
	myInit();
	glutMainLoop();
	return 0;
}

