"Draw a Spirograph"\
"Compile Command: g++ main.cpp spirograph.cpp formula.cpp displaytext.cpp saveimage.cpp -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 -o spirograph.exe"\
"ANGLE_OF_ROTATION should be double (2 should be input as 2.0)"\
/* TODO:
change cmd line argument to read arguments from an input file instead of putting them all in the cmd line
add cmd line argument as a flag to signal to save images or not
add other types of curves like hypotrochoids
refactor to a virtual graph class with subclasses spirograph, hypotrochoid, faris etc...
add makefile/equivilent to save compile time
implement interactive method to run multiple times and change values
add more color integration
add timestamp snippet
overload enter keymapping in comment blocks to newline and *
 */
