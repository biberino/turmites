#include "global.hpp"
#include "board.hpp"
#include "translations.hpp"
#include "turmite.hpp"
#include "turmite_factory.hpp"

Board board;


std::vector<Turmite> turmite_arr;

int temp = 0;

namespace colors
{
void setupColors()
{
    colorVec.push_back(white);
    colorVec.push_back(blue);
    colorVec.push_back(red);
    colorVec.push_back(green);
    colorVec.push_back(violet);
    colorVec.push_back(brown);
    colorVec.push_back(darkbrown);
    colorVec.push_back(burlywood);
    colorVec.push_back(cadetblue);
    colorVec.push_back(chocolate);
    colorVec.push_back(cyan);
    colorVec.push_back(darkblue);
    colorVec.push_back(darkgray);
    colorVec.push_back(darkorchid);
    colorVec.push_back(deepskyblue);
    colorVec.push_back(himmel1);
    colorVec.push_back(himmel2);
    colorVec.push_back(himmel3);
    colorVec.push_back(himmel4);
    colorVec.push_back(himmel5);
    colorVec.push_back(gold);
    colorVec.push_back(greenyellow);
    colorVec.push_back(indigo);
    colorVec.push_back(khaki);
    colorVec.push_back(lightpink);
    colorVec.push_back(magenta);
    colorVec.push_back(mediumspringgreen);
    colorVec.push_back(goldenrod);
}
} // namespace colors

void init_turmites()
{
    turmite_arr = create_turmites();

}

void myDisplay(void)
{ // display callback
    board.draw();
    glutSwapBuffers(); // swap buffers
}

void main_loop(int value)
{

    for (size_t i = 0; i < update_mult; i++)
    {
        for (auto &a : turmite_arr)
        {
            a.update(board);
        }
    }

    glutPostRedisplay();
    glutTimerFunc(loop_timeout_ms, main_loop, 0);
}

void myKeyboard(unsigned char c, int x, int y)
{
    switch (c)
    {         // c is the key that is hit
    case 'q': // 'q' means quit
        exit(0);
        break;

    case 32: // Leertaste

        glutTimerFunc(loop_timeout_ms, main_loop, 0);
        std::cout << "Main Loop started" << '\n';
        break;
    }
}

int main(int argc, char *argv[])
{

    colors::setupColors();
    init_turmites();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(argv[0]);

    glutDisplayFunc(myDisplay); // setup callbacks
    // glutReshapeFunc(myReshape);
    // glutMouseFunc(myMouse);

    //glutPassiveMotionFunc(myMouseMove);
    glutKeyboardFunc(myKeyboard);
    //glutSpecialFunc(mySpecialKeboard);
    glutMainLoop();
    return 0;
}
