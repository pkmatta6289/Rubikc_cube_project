#ifndef RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H
#define RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H

#include <vector>
#include <string>
#include <cstdint>

using namespace std;

class RubiksCube {
public:
    // Enum for the cube's faces
    enum class FACE {
        UP,
        LEFT,
        FRONT,
        RIGHT,
        BACK,
        DOWN
    };

    // Enum for the cube's colors
    enum class COLOR {
        WHITE,
        GREEN,
        RED,
        BLUE,
        ORANGE,
        YELLOW
    };

    // Enum for cube moves
    enum class MOVE {
        L,      // Left face clockwise
        LPRIME, // Left face counter-clockwise
        L2,     // Left face 180 degrees
        R,      // Right face clockwise
        RPRIME, // Right face counter-clockwise
        R2,     // Right face 180 degrees
        U,      // Upper face clockwise
        UPRIME, // Upper face counter-clockwise
        U2,     // Upper face 180 degrees
        D,      // Down face clockwise
        DPRIME, // Down face counter-clockwise
        D2,     // Down face 180 degrees
        F,      // Front face clockwise
        FPRIME, // Front face counter-clockwise
        F2,     // Front face 180 degrees
        B,      // Back face clockwise
        BPRIME, // Back face counter-clockwise
        B2      // Back face 180 degrees
    };

    // Virtual destructor for proper cleanup
    virtual ~RubiksCube() {}

    // Pure virtual function to get the color of a square
    virtual COLOR getColor(FACE face, unsigned row, unsigned col) const = 0;

    // Static function to get the letter representation of a color
    static char getColorLetter(COLOR color);

    // Pure virtual function to check if the cube is solved
    virtual bool isSolved() const = 0;

    // Static function to get the string representation of a move
    static string getMove(MOVE ind);

    // Print the cube in a planar format
    virtual void print() const = 0;

    // Shuffle the cube with a random sequence of moves
    vector<MOVE> randomShuffleCube(unsigned int times);

    // Apply a move to the cube
    virtual RubiksCube& move(MOVE ind) = 0;

    // Invert a move
    virtual RubiksCube& invert(MOVE ind) = 0;

    // Rotational Moves on the Rubik's Cube
    virtual RubiksCube& f() = 0;
    virtual RubiksCube& fPrime() = 0;
    virtual RubiksCube& f2() = 0;

    virtual RubiksCube& u() = 0;
    virtual RubiksCube& uPrime() = 0;
    virtual RubiksCube& u2() = 0;

    virtual RubiksCube& l() = 0;
    virtual RubiksCube& lPrime() = 0;
    virtual RubiksCube& l2() = 0;

    virtual RubiksCube& r() = 0;
    virtual RubiksCube& rPrime() = 0;
    virtual RubiksCube& r2() = 0;

    virtual RubiksCube& d() = 0;
    virtual RubiksCube& dPrime() = 0;
    virtual RubiksCube& d2() = 0;

    virtual RubiksCube& b() = 0;
    virtual RubiksCube& bPrime() = 0;
    virtual RubiksCube& b2() = 0;

    // Methods for corner operations
    virtual string getCornerColorString(uint8_t ind) const = 0;
    virtual uint8_t getCornerIndex(uint8_t ind) const = 0;
    virtual uint8_t getCornerOrientation(uint8_t ind) const = 0;
};

#endif // RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H
