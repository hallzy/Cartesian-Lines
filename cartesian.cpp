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
#include <cmath> // for sqrt()

#include "cartesian.h"

//The 4 functions below are methods from the CartesianPoint Class
// Setter and getter methods for the (x, y) coordinates
void CartesianPoint::setX(double x){
    this->x = x;
}
double CartesianPoint::getX(){
    return x;
}

void CartesianPoint::setY(double y){
    this->y = y;
}
double CartesianPoint::getY(){
    return y;
}

//The 8 functions below are methods from the CartesianLine Class
// Constructor declaration sets up the private variables.
CartesianLine::CartesianLine(CartesianPoint point1, CartesianPoint point2){
    x1 = point1.getX();
    y1 = point1.getY();

    x2 = point2.getX();
    y2 = point2.getY();
}

// Calculates the distance between the two points, same as the length
// of the line that they form
double CartesianLine::distance(){
    // hypotenuse of a triangle, with legs of length x2-x1 and y2-y1
    return sqrt( ((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)) );
}
// calculates the slope of a line
double CartesianLine::slope(){
    return (y2-y1)/(x2-x1);
}
// calculates the y intercept of a line
double CartesianLine::yint(){
    // y2 = slope*x2 + b
    //b = y2 - slope*x2
    return y2 - (slope()*x2);
}
// prints the equation of a line
void CartesianLine::printEquation(){
    double b = yint();
    double m = slope();

    if(isVerticalLine()){ // if the line is a vertical line equation is x= x intercept
        std::cout << "x = " << x1;
    }
    else{ // if the line is not a vertical line and...
        if(b==0){
            if(m==0) // y-int and slope are 0, equation is y = 0
                std::cout << "y=0";
            else // if y-int is 0 and slope is not 0, y = mx
                std::cout << "y=" << m << "x";
        }
        else if(m == 0){ // if slope is 0 and y-int is not 0, equation is y = b
            std::cout << "y=" << b;
        }
        else{ // in the case where there is a slope and y-int to show...
                // if b is negative, replace the + with a -, otherwise
                //print as normal
            if(b < 0)
                std::cout << "y = " << m << "x - " << -b;
            else
                std::cout << "y = " << m << "x + " << b;
        }
    }
}
// finds the x intercept of the line
double CartesianLine::xint(){
    // if the line is a vertical line, return x1...
    // otherwise return the x-intercept of the line
    // y = mx + b
    // for x-intercept, let y = 0
    // x = -b/m
    return ((x1 == x2) ? x1 : -1*yint()/slope());
}
// prints various information about the line
void CartesianLine::printLineInfo(){
    std::cout << "Distance Between (" << x1 << ", " << y1 << ") and (" << x2 << ", " << y2 << ") is " << distance();
    std::cout << std::endl;
    std:: cout << "X intercept is " << xint() << std::endl;
    printEquation();
    std::cout << std::endl;
}

// returns true if the line is vertical
bool CartesianLine::isVerticalLine(){
    return ((x1 == x2) ? true : false);
}

// ****************************************************
//              END OF CLASS METHODS
// ****************************************************



//The below functions are not part of either class, but are prototyped in the
//cartesian.h file

/**********************************************************
*   Beginning of Function Implementation
*
*   Parameters: two lines of type CartesianLine
*   Returns: true if the two lines are parallel, and false otherwise
***********************************************************
*/
bool IsParallel(CartesianLine line1, CartesianLine line2){
    // if the slope if line1 and line2 are the same, then they are parallel
    // otherwise, they are not, and they will intersect
    return((line1.slope() == line2.slope()) ? true : false);
}


/**********************************************************
*   Beginning of Function Declaration
*
*   Finds the intersection point of two lines
*
*   Parameters: two lines of type CartesianLine
*   Returns: the intersectionPoint of type CartesianPoint
***********************************************************
*/
CartesianPoint intersection(CartesianLine line1, CartesianLine line2){
    //m1x+b1 = m2x + b2
    // (m1-m2)x = b2-b1
    // x = (b2-b1)/(m1-m2)
    CartesianPoint intersectionPoint; // contains the (x, y) coordinates of the intersection

    if(line1.isVerticalLine()){ // if line 1 is vertical make the x intersection coordinate
                                // the x value at which line1 is at
                                // This is because the x coordinate of intersection has to be
                                // the value of the vertical line... same reasoning for next case
        intersectionPoint.setX(line1.xint());
        intersectionPoint.setY((line2.slope()*intersectionPoint.getX()) + line2.yint());
    }
    else if(line2.isVerticalLine()){    // if line2 is vertical make the x intersection coordinate
                                        // the x value at which line2 is at
        intersectionPoint.setX(line2.xint());
        intersectionPoint.setY((line1.slope()*intersectionPoint.getX()) + line1.yint());
    }
    else{
            // y = m1x+b1
            // y = m2x+b2
            //m1x+b1 = m2x+b2
            // x = (b2-b1) / (m1-m2)
        intersectionPoint.setX((line2.yint()-line1.yint())/(line1.slope()-line2.slope()));
            // y = m1x + b1
            // I could have also used y = m2x + b2
        intersectionPoint.setY((line1.slope()*intersectionPoint.getX()) + line1.yint());
    }
    return intersectionPoint;
}

/**********************************************************
*   Beginning of Function Declaration
*
*   This function prints the intersection point of two lines
*
*   parameters: two lines of type CartesianLine
***********************************************************
*/
void PrintIntersectionInfo(CartesianLine line1, CartesianLine line2){

    if(IsParallel(line1, line2) == true){ // Parallel lines never intersect
        std::cout << "The lines never intersect because they are parallel!\n\n";
    }
    else{ // non parallel lines always intersect, so print the intersection point
        std::cout << "Line1 and Line2 intersect at (" << intersection(line1, line2).getX() <<
                ", " << intersection(line1, line2).getY() << ")\n\n";
    }
}
