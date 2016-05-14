#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
#define PI 3.14159265

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{

    // game loop
    int speed = 1;
    int dx = 0, dy = 0;
    double e = 0;
    while (1) {
        int x;
        int y;
        int nextCheckpointX; // x position of the next check point
        int nextCheckpointY; // y position of the next check point
        int nextCheckpointDist; // distance to the next checkpoint
        int nextCheckpointAngle; // angle between your pod orientation and the direction of the next checkpoint
        cin >> x >> y >> nextCheckpointX >> nextCheckpointY >> nextCheckpointDist >> nextCheckpointAngle; cin.ignore();
        int opponentX;
        int opponentY;
        cin >> opponentX >> opponentY; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        // You have to output the target position
        // followed by the power (0 <= thrust <= 100)
        // i.e.: "x y thrust"
        double dfactor = 1;
        if (nextCheckpointDist > 6000)
            dfactor = 1;
        else if (nextCheckpointDist > 4000)
            dfactor = 2;
        else if (nextCheckpointDist > 2000)
            dfactor = 3;
        else
            dfactor = 0;
        if (nextCheckpointAngle < -5) {
            if (speed > 50)
                e = 3*dfactor;
            else
                e = 2*dfactor;
        }
        else if (nextCheckpointAngle < -3) {
            if (speed > 50)
                e = 2*dfactor;
            else
                e = 1*dfactor;
        }
        else if (nextCheckpointAngle < -1) {
            if (speed > 50)
                e = 1*dfactor;
            else
                e = 0.5*dfactor;
        }
        else if (nextCheckpointAngle > 5) {
            if (speed > 50)
                e = -3*dfactor;
            else
                e = -2*dfactor;
        }
        else if (nextCheckpointAngle > 3) {
            if (speed > 50)
                e = -2*dfactor;
            else
                e = -1*dfactor;
        }
        else if (nextCheckpointAngle > 1) {
            if (speed > 50)
                e = -1*dfactor;
            else
                e = -0.5*dfactor;
        }
        double angle = atan2((y-nextCheckpointY), (nextCheckpointX-x)) * 180 / PI + e;
        cerr << "angle: " << angle << endl;
        dy = -tan( angle * PI / 180.0 ) * (nextCheckpointX-x) + y - nextCheckpointY;
        
        if (speed == 0 && abs(nextCheckpointAngle) < 10) {
            cout << nextCheckpointX << " " << nextCheckpointY << " BOOST"  << " BOOST" << endl;
            speed = 1;
            continue;
        }
        cerr << nextCheckpointDist << " " << abs(nextCheckpointAngle) << endl;
        
        if (abs(nextCheckpointAngle) > 130) {
            speed = 0;
            cout << nextCheckpointX + dx << " " << nextCheckpointY + dy << " 0 " << (nextCheckpointAngle) << " " << nextCheckpointDist << " 0" << endl;
        }
        else if (abs(nextCheckpointAngle) > 90 && nextCheckpointDist < 3000) {
            speed = 20;
            cout << nextCheckpointX + dx << " " << nextCheckpointY + dy << " 20 " << (nextCheckpointAngle) << " " << nextCheckpointDist << " 20" << endl;
        }
        else if (abs(nextCheckpointAngle) > 90 && nextCheckpointDist < 4000) {
            speed = 40;
            cout << nextCheckpointX + dx << " " << nextCheckpointY + dy << " 40 " << (nextCheckpointAngle) << " " << nextCheckpointDist << " 40" << endl;
        }
        else if (abs(nextCheckpointAngle) > 70 && nextCheckpointDist < 7000) {
            speed = 60;
            cout << nextCheckpointX + dx << " " << nextCheckpointY + dy << " 60 " << (nextCheckpointAngle) << " " << nextCheckpointDist << " 60" << endl;
        }
        else if (abs(nextCheckpointAngle) > 20 && nextCheckpointDist < 4000) {
            speed = 40;
            cout << nextCheckpointX + dx << " " << nextCheckpointY + dy << " 40 " << (nextCheckpointAngle) << " " << nextCheckpointDist << " 40" << endl;
        }
        else if (abs(nextCheckpointAngle) > 20 && nextCheckpointDist < 5000) {
            speed = 60;
            cout << nextCheckpointX + dx << " " << nextCheckpointY + dy << " 60 " << (nextCheckpointAngle) << " " << nextCheckpointDist << " 60" << endl;
        }
        else if (abs(nextCheckpointAngle) > 2 && nextCheckpointDist < 5000) {
            speed = 70;
            cout << nextCheckpointX + dx << " " << nextCheckpointY + dy << " 70 " << (nextCheckpointAngle) << " " << nextCheckpointDist << " 70" << endl;
        }
        else if (abs(nextCheckpointAngle) > 0 && nextCheckpointDist < 4000) {
            speed = 80;
            cout << nextCheckpointX + dx << " " << nextCheckpointY + dy << " 80 "  << (nextCheckpointAngle) << " " << nextCheckpointDist << " 60" << endl;
        }
        else if (abs(nextCheckpointAngle) < 2 && nextCheckpointDist > 6000) {
            speed = 100;
            cout << nextCheckpointX + dx << " " << nextCheckpointY + dy << " BOOST "  << (nextCheckpointAngle) << " " << nextCheckpointDist << " BOOST" << endl;
        }
        else if (abs(nextCheckpointAngle) < 1 && nextCheckpointDist > 4000) {
            speed = 100;
            cout << nextCheckpointX + dx << " " << nextCheckpointY + dy << " BOOST "  << (nextCheckpointAngle) << " " << nextCheckpointDist << " BOOST" << endl;
        }
        else {
            speed = 100;
            cout << nextCheckpointX + dx << " " << nextCheckpointY + dy << " 100 " << (nextCheckpointAngle) << " " << nextCheckpointDist << " 100" << endl;
        }
    }
}