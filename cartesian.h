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

#ifndef __CARTESIAN_H_INCLUDED__
#define __CARTESIAN_H_INCLUDED__

/**********************************************************
*   Beginning of Class Declaration
*
*   This class is for single points on a cartesian plane.
***********************************************************
*/
class CartesianPoint{
protected:
    double x; // X cartesian coordinate
    double y; // y cartesian coordinate

public:
    // Setter and getter methods for the (x, y) coordinates
    void setX(double x);
    double getX();

    void setY(double y);
    double getY();
};

/**********************************************************
*   Beginning of Class Declaration
*
*   This class is for lines on a cartesian plane.
***********************************************************
*/
class CartesianLine : public CartesianPoint{
private:
    double x1; // Coordinates of point 1
    double y1;

    double x2; // Coordinates of point 2
    double y2;
public:
    // Constructor declaration sets up the private variables.
    CartesianLine(CartesianPoint point1, CartesianPoint point2);

    // Calculates the distance between the two points, same as the length
    // of the line that they form
    double distance();
    // calculates the slope of a line
    double slope();
    // calculates the y intercept of a line
    double yint();
    // prints the equation of a line
    void printEquation();
    // finds the x intercept of the line
    double xint();
    // prints various information about the line
    void printLineInfo();
    // returns true if the line is vertical
    bool isVerticalLine();
};


/**********************************************************
*   Beginning of Function Implementation
*
*   Parameters: two lines of type CartesianLine
*   Returns: true if the two lines are parallel, and false otherwise
***********************************************************
*/
bool IsParallel(CartesianLine line1, CartesianLine line2);


/**********************************************************
*   Beginning of Function Declaration
*
*   Finds the intersection point of two lines
*
*   Parameters: two lines of type CartesianLine
*   Returns: the intersectionPoint of type CartesianPoint
***********************************************************
*/
CartesianPoint intersection(CartesianLine line1, CartesianLine line2);


/**********************************************************
*   Beginning of Function Declaration
*
*   This function prints the intersection point of two lines
*
*   parameters: two lines of type CartesianLine
***********************************************************
*/
void PrintIntersectionInfo(CartesianLine line1, CartesianLine line2);

#endif
