#include "global.hpp"
#include "board.hpp"
#include "ant.hpp"
#include "basic_rule.hpp"
#include "translations.hpp"

Board board;
int x = pixel_darstellbar_x / 2;
int y = pixel_darstellbar_y / 2;

std::vector<Ant> ants;

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

void init_ants()
{
    Ant a(new BasicRule(0, 1, turn_right), v2(x, y), v2(0, -1));

    a.add_rule(new BasicRule(0, 1, turn_right));
    a.add_rule(new BasicRule(1, 2, turn_left));
    a.add_rule(new BasicRule(2, 3, turn_left));
    a.add_rule(new BasicRule(3, 0, turn_right));
    a.add_rule(new BasicRule(4, 5, turn_right));
    a.add_rule(new BasicRule(5, 6, turn_right));
    a.add_rule(new BasicRule(6, 7, turn_right));
    a.add_rule(new BasicRule(7, 8, turn_right));

    a.add_rule(new BasicRule(8, 9, turn_left));
    a.add_rule(new BasicRule(9, 10, turn_left));
    a.add_rule(new BasicRule(10, 11, turn_left));
    a.add_rule(new BasicRule(11, 12, turn_left));
    a.add_rule(new BasicRule(12, 13, turn_left));
    a.add_rule(new BasicRule(13, 14, turn_left));
    a.add_rule(new BasicRule(14, 15, turn_left));
    a.add_rule(new BasicRule(15, 0, turn_left));


    ants.push_back(a);
    //ants.push_back(a);

    Ant b(new BasicRule(0, 1, turn_right), v2(x, y), v2(0, -1));

    b.add_rule(new BasicRule(1, 0, turn_left));
    //b.add_rule(new BasicRule(2, 0, turn_right));
    //ants.push_back(b);
}

void myDisplay(void)
{ // display callback
    board.draw();
    glutSwapBuffers(); // swap buffers
}

void ant_loop(int value)
{

    for (size_t i = 0; i < update_mult; i++)
    {
        for (auto &a : ants)
        {
            a.update(board);
        }
    }

    glutPostRedisplay();
    glutTimerFunc(loop_timeout_ms, ant_loop, 0);
}

void myKeyboard(unsigned char c, int x, int y)
{
    switch (c)
    {         // c is the key that is hit
    case 'q': // 'q' means quit
        exit(0);
        break;

    case 32: // Leertaste

        glutTimerFunc(loop_timeout_ms, ant_loop, 0);
        std::cout << "Game Loop started" << '\n';
        break;
    }
}

int main(int argc, char *argv[])
{

    colors::setupColors();
    init_ants();

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
