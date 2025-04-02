#include <stdio.h>
#include <stdlib.h>

int robotSim(int* commands, int commandsSize, int** obstacles, int obstaclesSize, int* obstaclesColSize) {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    long long* obstacleSet = (long long*)calloc(obstaclesSize, sizeof(long long));
    for (int i = 0; i < obstaclesSize; i++) {
        obstacleSet[i] = ((long long)obstacles[i][0] * 60001) + obstacles[i][1];
    }
    int x = 0, y = 0;
    int direction = 0;
    long long maxDistance = 0;
    for (int i = 0; i < commandsSize; i++) {
        if (commands[i] == -1) {
            direction = (direction + 1) % 4;
        } 
        else if (commands[i] == -2) {
            direction = (direction - 1 + 4) % 4;
        } 
        else {
            for (int step = 0; step < commands[i]; step++) {
                int nextX = x + dx[direction];
                int nextY = y + dy[direction];
                long long nextPos = ((long long)nextX * 60001) + nextY;
                int isObstacle = 0;
                for (int j = 0; j < obstaclesSize; j++) {
                    if (obstacleSet[j] == nextPos) {
                        isObstacle = 1;
                        break;
                    }
                }
                if (isObstacle) {
                    break;
                }
                x = nextX;
                y = nextY;
                long long currentDistance = (long long)x * x + (long long)y * y;
                maxDistance = (currentDistance > maxDistance) ? currentDistance : maxDistance;
            }
        }
    }
    free(obstacleSet);
    return (int)maxDistance;
}