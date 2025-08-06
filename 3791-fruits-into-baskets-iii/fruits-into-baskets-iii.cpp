class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        vector<int> sectorMax;
        int totalBaskets = baskets.size();
        int sectorSize = sqrt(totalBaskets);
        int count = 0, maxCapacity = 0;

        for (int i = 0; i < totalBaskets; i++) {
            if (count == sectorSize) {
                sectorMax.push_back(maxCapacity);
                maxCapacity = baskets[i];
                count = 1;
            } else {
                count++;
                maxCapacity = max(maxCapacity, baskets[i]);
            }
        }
        sectorMax.push_back(maxCapacity);

        int unplacedFruits = 0;

        for (int i = 0; i < fruits.size(); i++) {
            int sectorIndex = 0;
            bool fruitPlaced = false;

            for (int sectorStart = 0; sectorStart < totalBaskets;
                 sectorStart += sectorSize) {
                if (sectorMax[sectorIndex] < fruits[i]) {
                    sectorIndex++;
                    continue;
                }

                for (int b = sectorStart;
                     b < min(sectorStart + sectorSize, totalBaskets); b++) {
                    if (baskets[b] >= fruits[i]) {
                        baskets[b] = 0;
                        fruitPlaced = true;

                        sectorMax[sectorIndex] = 0;
                        for (int r = sectorStart;
                             r < min(sectorStart + sectorSize, totalBaskets);
                             r++) {
                            sectorMax[sectorIndex] =
                                max(sectorMax[sectorIndex], baskets[r]);
                        }

                        break;
                    }
                }

                if (fruitPlaced)
                    break;
                sectorIndex++;
            }

            if (!fruitPlaced)
                unplacedFruits++;
        }

        return unplacedFruits;
    }
};
