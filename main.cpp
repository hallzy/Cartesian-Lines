/*********************************************************************************
* Steven Hall
*
* Last Modification: September 18, 2014
*
* This program takes a minimum of two points, and using those two points will
* combine the two points into a one single line. It will calculate the function
* f(x) of the line. When two lines are produced, the program also displays the
* intersection point of the two lines.
**********************************************************************************
*/

#include <iostream>
#include <cmath>

#include "cartesian.h"


/**********************************************************
*   Beginning of main()
***********************************************************
*/
int main()
{
    // Create 4 points.
    // These points are of type CartesianPoint which is defined in cartesian.h and
    // cartesian.cpp in the CartesianPoint Class
    CartesianPoint point1;
    CartesianPoint point2;

    CartesianPoint point3;
    CartesianPoint point4;

    double input; // The user input for all of the coordinates

    // Note that we are going to create a line made of points 1 and 2 and another line
    // made of points 3 and 4.

    std::cout << "Enter the coordinates of the first point in the form \"x y\": ";

    // Initialzie the first two points
    std::cin >> input;
    point1.setX(input);

    std::cin >> input;
    point1.setY(input);



    std::cout << "Enter the coordinates of the second point in the form \"x y\": ";

    std::cin >> input;
    point2.setX(input);

    std::cin >> input;
    point2.setY(input);



    //initialize the second 2 points
    std::cout << "Enter the coordinates of the third point in the form \"x y\": ";

    std::cin >> input;
    point3.setX(input);

    std::cin >> input;
    point3.setY(input);



    std::cout << "Enter the coordinates of the fourth point in the form \"x y\": ";

    std::cin >> input;
    point4.setX(input);

    std::cin >> input;
    point4.setY(input);

    //create a line made of point 1 and point 2
    //initialize 2 lines
    // These lines are of type CartesianLine which is defined in cartesian.h and
    // cartesian.cpp in the CartesianLine Class
    CartesianLine line1(point1, point2);
    CartesianLine line2(point3, point4);

    // Print out some information about the line.
    std::cout << "Line1: \n";
    line1.printLineInfo();
    std::cout << std::endl << std::endl;

    std::cout << "Line2: \n";
    line2.printLineInfo();
    std::cout << std::endl;

    // Prints information on the intersection of the two lines.
    PrintIntersectionInfo(line1, line2);

    return 0;
}
