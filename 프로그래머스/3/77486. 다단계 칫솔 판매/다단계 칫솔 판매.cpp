#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
unordered_map<string, pair<string, int>> people;

void MapInit(vector<string> enroll, vector<string> referral);

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    MapInit(enroll, referral);
    
    for(int i = 0; i < seller.size(); i++)
    {
        string seller_name = seller[i];
        int seller_profit = amount[i] * 100;
        while(1)
        {
            string referral_name = people[seller_name].first;
            people[seller_name].second += seller_profit - (int)(seller_profit * 0.1);
            
            seller_name = referral_name;
            seller_profit = (int)(seller_profit * 0.1);
            
            if(seller_name == "=") break;
            if(seller_profit == 0) break;
        }
    }
    
    for(int i = 0; i < enroll.size(); i++)
        answer.push_back(people[enroll[i]].second);
    
    return answer;
}

void MapInit(vector<string> enroll, vector<string> referral)
{
    for(int i = 0; i < enroll.size(); i++)
        people.insert({enroll[i], {referral[i], 0}});
}