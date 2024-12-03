#include <string>
#include <vector>

using namespace std;

int skill_bandage(vector<int> bandage, int health, vector<vector<int>> attacks);

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    return skill_bandage(bandage, health, attacks);
}

int skill_bandage(vector<int> bandage, int health, vector<vector<int>> attacks)
{
    int skill_time = bandage[0];
    int heal_per_second = bandage[1];
    int additional_heal = bandage[2];
    int sec = 0;
    int attackIdx = 0;
    int healStreak = 0;
    int max_health = health;
    while(sec++ < attacks[attacks.size() - 1][0])
    {
        int attackTime = attacks[attackIdx][0];
        int damage = attacks[attackIdx][1];
        if(sec == attackTime)
        {
            health -= damage;
            attackIdx++;
            healStreak = 0;
            if(health <= 0)
            {
                return -1;
            }
        }
        else
        {
            healStreak++;
            health = min(max_health, health + heal_per_second);
            if(healStreak == skill_time)
            {
                health = min(max_health, health + additional_heal);
                healStreak = 0;
            }
        }
    }
    return health;
}