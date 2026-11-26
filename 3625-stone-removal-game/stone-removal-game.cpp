class Solution {
public:
    bool canAliceWin(int n) {
        int stones = 10;
        bool alice = true;

        while (n >= stones) {
            n = n - stones;
            stones--;

            alice = !alice;
        }

        return !alice;
    }
};