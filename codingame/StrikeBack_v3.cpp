// GOLD LEAGUE
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


int nLaps, nCP;

typedef struct _CP {
    int x, y;
} CP;
vector<CP> CPs;

typedef struct _POD{
    int x, y;
    int vx, vy;
    int pCP = 0, nC = 0;
    int angle;
    int nextCP;
} POD;
vector<POD> pods(4);

double dist(CP p1, CP p2) {
    return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

bool crachPodOther(int i) {
    CP myP, oP1, oP2;
    double rx, ry, rs;
    int dx, dy;
    rs = abs(CPs[pods[i].nextCP].x - pods[i].x) + abs(CPs[pods[i].nextCP].y - pods[i].y);
    rx = (CPs[pods[i].nextCP].x - pods[i].x) / rs;
    ry = (CPs[pods[i].nextCP].y - pods[i].y) / rs;
    dx = rx > 0 ? 100*abs(rx) : -100*abs(rx);
    dy = ry > 0 ? 100*abs(ry) : -100*abs(ry);
    myP.x = pods[i].x + pods[i].vx + dx;
    myP.y = pods[i].y + pods[i].vy + dy;

    rs = abs(CPs[pods[2].nextCP].x - pods[2].x) + abs(CPs[pods[2].nextCP].y - pods[2].y);
    rx = (CPs[pods[2].nextCP].x - pods[2].x) / rs;
    ry = (CPs[pods[2].nextCP].y - pods[2].y) / rs;
    dx = rx > 0 ? 100*abs(rx) : -100*abs(rx);
    dy = ry > 0 ? 100*abs(ry) : -100*abs(ry);
    oP1.x = pods[2].x + pods[2].vx + dx;
    oP1.y = pods[2].y + pods[2].vy + dy;

    rs = abs(CPs[pods[3].nextCP].x - pods[3].x) + abs(CPs[pods[3].nextCP].y - pods[3].y);
    rx = (CPs[pods[3].nextCP].x - pods[3].x) / rs;
    ry = (CPs[pods[3].nextCP].y - pods[3].y) / rs;
    dx = rx > 0 ? 100*abs(rx) : -100*abs(rx);
    dy = ry > 0 ? 100*abs(ry) : -100*abs(ry);
    oP2.x = pods[3].x + pods[3].vx + dx;
    oP2.y = pods[3].y + pods[3].vy + dy;

    if (sqrt(pods[i].vx*pods[i].vx + pods[i].vy*pods[i].vy) > 300)
        return false;
    if (dist(myP, oP1) < 1500 && pods[i].nC < pods[2].nC && sqrt(pods[2].vx*pods[2].vx + pods[2].vy*pods[2].vy) > 500)
        return true;
    if (dist(myP, oP2) < 1500 && pods[i].nC < pods[3].nC && sqrt(pods[3].vx*pods[3].vx + pods[3].vy*pods[3].vy) > 500)
        return true;
    return false;
}

bool crashPodsSame() {
    CP p[2];
    double rx, ry, rs;
    int dx, dy;
    for (int i = 0; i < 2; ++i) {
        rs = abs(CPs[pods[i].nextCP].x - pods[i].x) + abs(CPs[pods[i].nextCP].y - pods[i].y);
        rx = (CPs[pods[i].nextCP].x - pods[i].x) / rs;
        ry = (CPs[pods[i].nextCP].y - pods[i].y) / rs;
        dx = rx > 0 ? 100*abs(rx) : -100*abs(rx);
        dy = ry > 0 ? 100*abs(ry) : -100*abs(ry);
        p[i].x = pods[i].x + pods[i].vx + dx;
        p[i].y = pods[i].y + pods[i].vy + dy;
    }
    if (dist(p[0], p[1]) < 1000) return true;
    return false;
}

int getSpeed(int i) {
    return sqrt(pods[i].vx*pods[i].vx + pods[i].vy*pods[i].vy);
}

int fasterPod = 0, fasterOther = 2;

int main()
{
    cin >> nLaps >> nCP;
    cerr << "laps: " << nLaps << ", nCP: " << nCP << endl;
    CPs = vector<CP>(nCP);
    for (int i = 0; i < nCP; ++i) {
        cin >> CPs[i].x >> CPs[i].y;
        cerr << i+1 << ": " << CPs[i].x << " " << CPs[i].y << endl;
    }

    while (1) {

        for (int i = 0; i < 4; ++i) {
            cin >> pods[i].x >> pods[i].y >> pods[i].vx >> pods[i].vy >> pods[i].angle >> pods[i].nextCP;
            pods[i].angle = -pods[i].angle;
            if (pods[i].angle <= -180)
                pods[i].angle += 360;
            if (pods[i].pCP != pods[i].nextCP) {
                pods[i].nC += 1;
                pods[i].pCP = pods[i].nextCP;
                if (i < 2 && pods[i].nC > pods[1-i].nC)
                    fasterPod = i;
                if (i >= 2 && pods[i].nC > pods[5-i].nC)
                    fasterOther = i;
            }
            cerr << pods[i].x << " " << pods[i].y << " " << pods[i].vx << " " << pods[i].vy << " " <<pods[i].angle << " " << pods[i].nextCP << endl;
        }

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        // You have to output the target position
        // followed by the power (0 <= thrust <= 100)
        // i.e.: "x y thrust"

        vector<int> speed(2, 0);
        for (int i = 0; i < 2; ++i) {
            int nextCheckpointDist = (int)sqrt((double)(pods[i].y - CPs[pods[i].nextCP].y)*(pods[i].y - CPs[pods[i].nextCP].y) + 
                                                       (pods[i].x - CPs[pods[i].nextCP].x)*(pods[i].x - CPs[pods[i].nextCP].x));


            int nextCheckpointAngle = abs(pods[i].angle - atan2(pods[i].y - CPs[pods[i].nextCP].y, CPs[pods[i].nextCP].x - pods[i].x) * 180 / PI);
            int nnextCP = (pods[i].nextCP + 1)%nCP;
            int nnextCheckpointAngle = abs(pods[i].angle - atan2(pods[i].y - CPs[nnextCP].y, CPs[nnextCP].x - pods[i].x) * 180 / PI);

            if (nextCheckpointAngle > 180)
                nextCheckpointAngle = 360 - nextCheckpointAngle;



            int ny = abs((CPs[pods[i].nextCP].y - pods[i].y) / (pods[i].vy+0.1));
            int nx = abs((CPs[pods[i].nextCP].x - pods[i].x) / (pods[i].vx+0.1));
            int nmax = (nx + ny)/2;
            int dx = 1.3*(CPs[pods[i].nextCP].x - (pods[i].x + nmax * pods[i].vx));
            int dy = 1.3*(CPs[pods[i].nextCP].y - (pods[i].y + nmax * pods[i].vy));
            if (nmax > 10) {
                dx = dy = 0;
            }
            cerr << "error: " << dx << " " << dy << endl;


            int nextCheckpointY = CPs[pods[i].nextCP].y;
            int nextCheckpointX = CPs[pods[i].nextCP].x;

            if (crashPodsSame() && i != fasterPod) {
                speed[i] = 100;
                cout << pods[fasterOther].x << " " << pods[fasterOther].y << " " << speed[i] << " "  << (nextCheckpointAngle) << " " << nextCheckpointDist << " " << speed[i] << endl;
                continue;
            }

            if (crachPodOther(i) && nnextCheckpointAngle > 90) {
                cout << nextCheckpointX << " " << nextCheckpointY << " SHIELD"  << " SHIELD" << endl;
                speed[i] = 1;
                continue;
            }

            if (speed[i] == 0 && abs(nextCheckpointAngle) < 10  && nextCheckpointDist > 3000 && abs(dx) < 1000 && abs(dy) < 1000) {
                cout << nextCheckpointX << " " << nextCheckpointY << " BOOST"  << " BOOST" << endl;
                speed[i] = 1;
                continue;
            }
            cerr << nextCheckpointDist << " " << abs(nextCheckpointAngle) << endl;
            cerr << "angle " << pods[i].angle << " " << atan2(pods[i].y - CPs[pods[i].nextCP].y, CPs[pods[i].nextCP].x - pods[i].x) * 180 / PI << endl;
            
            if (nextCheckpointDist < 2000) {
                if (nnextCheckpointAngle > 130) {
                    if (getSpeed(i) > 50)
                        speed[i] = 10;
                    else
                        speed[i] = 50;
                    cout << nextCheckpointX + dx << " " << nextCheckpointY + dy << " " << speed[i] << " "  << (nextCheckpointAngle) << " " << nextCheckpointDist << " " << speed[i] << endl;
                }
                else if (nnextCheckpointAngle > 90) {
                    speed[i] = 50;
                    cout << nextCheckpointX + dx << " " << nextCheckpointY + dy << " " << speed[i] << " "  << (nextCheckpointAngle) << " " << nextCheckpointDist << " " << speed[i] << endl;
                }
                else {
                    speed[i] = 100;
                    cout << nextCheckpointX + dx << " " << nextCheckpointY + dy << " " << speed[i] << " "  << (nextCheckpointAngle) << " " << nextCheckpointDist << " " << speed[i] << endl;
                }
            }
            else if (abs(nextCheckpointAngle) > 130) {
                if (getSpeed(i) > 50)
                    speed[i] = 10;
                else
                    speed[i] = 50;
                cout << nextCheckpointX + dx << " " << nextCheckpointY + dy << " " << speed[i] << " " << (nextCheckpointAngle) << " " << nextCheckpointDist << " " << speed[i] << endl;
            }
            else if (abs(nextCheckpointAngle) > 90 && nextCheckpointDist < 3000) {
                speed[i] = 60;
                cout << nextCheckpointX + dx << " " << nextCheckpointY + dy << " " << speed[i] << " " << (nextCheckpointAngle) << " " << nextCheckpointDist << " " << speed[i] << endl;
            }
            else if (abs(nextCheckpointAngle) > 90 && nextCheckpointDist < 4000) {
                speed[i] = 60;
                cout << nextCheckpointX + dx << " " << nextCheckpointY + dy << " " << speed[i] << " " << (nextCheckpointAngle) << " " << nextCheckpointDist << " " << speed[i] << endl;
            }
            else if (abs(nextCheckpointAngle) > 70 && nextCheckpointDist < 7000) {
                speed[i] = 80;
                cout << nextCheckpointX + dx << " " << nextCheckpointY + dy << " " << speed[i] << " " << (nextCheckpointAngle) << " " << nextCheckpointDist << " " << speed[i] << endl;
            }
            else if (abs(nextCheckpointAngle) > 20 && nextCheckpointDist < 4000) {
                speed[i] = 80;
                cout << nextCheckpointX + dx << " " << nextCheckpointY + dy << " " << speed[i] << " " << (nextCheckpointAngle) << " " << nextCheckpointDist << " " << speed[i] << endl;
            }
            else if (abs(nextCheckpointAngle) > 20 && nextCheckpointDist < 5000) {
                speed[i] = 80;
                cout << nextCheckpointX + dx << " " << nextCheckpointY + dy << " " << speed[i] << " " << (nextCheckpointAngle) << " " << nextCheckpointDist << " " << speed[i] << endl;
            }
            else if (abs(nextCheckpointAngle) < 2 && nextCheckpointDist > 6000 && abs(dx) < 1000 && abs(dy) < 1000) {
                speed[i] = 100;
                cout << nextCheckpointX + dx << " " << nextCheckpointY + dy << " BOOST "  << (nextCheckpointAngle) << " " << nextCheckpointDist << " BOOST" << endl;
            }
            else if (abs(nextCheckpointAngle) < 1 && nextCheckpointDist > 4000 && abs(dx) < 1000 && abs(dy) < 1000) {
                speed[i] = 100;
                cout << nextCheckpointX + dx << " " << nextCheckpointY + dy << " BOOST "  << (nextCheckpointAngle) << " " << nextCheckpointDist << " BOOST" << endl;
            }
            else {
                speed[i] = 100;
                cout << nextCheckpointX + dx << " " << nextCheckpointY + dy << " " << speed[i] << " " << (nextCheckpointAngle) << " " << nextCheckpointDist << " " << speed[i] << endl;
            }
        }
    }
}