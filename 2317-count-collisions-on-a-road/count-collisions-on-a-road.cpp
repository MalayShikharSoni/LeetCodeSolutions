class Solution {
public:
    int countCollisions(string directions) {

        int toBeCollided = 0;
        int collisions = 0;
        bool lVisited = false;
        bool sVisited = false;
        bool rVisited = false;
        int size = directions.size();

        for (int i = 0; i < directions.size() - 1; i++) {

            char first = directions[i];
            char sec = directions[i + 1];

            if (first == 'L') {
                lVisited = true;
            } else if (first == 'S') {
                sVisited = true;
            } else {
                rVisited = true;
            }

            if ((first == 'L' && sec == 'L') && (sVisited || rVisited)) {
                toBeCollided++;
            }

            if (first == 'L' && sec == 'R') {
                if (sVisited || rVisited) {
                    collisions += toBeCollided;
                }
                toBeCollided = 0;
            }

            if (first == 'L' && sec == 'S') {
                if (sVisited || rVisited) {
                    collisions += toBeCollided;
                }
                toBeCollided = 0;
            }

            if (first == 'R' && sec == 'L') {
                collisions += 2;
                collisions += toBeCollided;
                toBeCollided = 0;
            }

            if (first == 'R' && sec == 'R') {
                toBeCollided++;
            }

            if (first == 'R' && sec == 'S') {
                collisions++;
                collisions += toBeCollided;
                toBeCollided = 0;
            }

            if (first == 'S' && sec == 'L') {
                toBeCollided++;
            }

            if (first == 'S' && sec == 'R') {
                toBeCollided = 0;
            }

            if (first == 'S' && sec == 'S') {
                continue;
            }
        }

        if (directions[size - 1] != 'R') {
            collisions += toBeCollided;
        }

        return collisions;
    }
};