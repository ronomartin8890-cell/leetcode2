#include <iostream>
#include <unordered_map>
#include <set>
#include <string>
#include <vector>
using namespace std;

class FoodRatings {
private:
    // Map food -> {cuisine, rating}
    unordered_map<string, pair<string, int>> foodInfo;
    // Map cuisine -> set of (-rating, food) sorted by rating desc, then name asc
    unordered_map<string, set<pair<int, string>>> cuisineFoods;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];

            foodInfo[food] = {cuisine, rating};
            cuisineFoods[cuisine].insert({-rating, food});
        }
    }

    void changeRating(string food, int newRating) {
        auto& [cuisine, oldRating] = foodInfo[food];

        // Removed old entry from set
        cuisineFoods[cuisine].erase({-oldRating, food});
        // Update rating
        foodInfo[food].second = newRating;
        // Inserted new entry with updated rating
        cuisineFoods[cuisine].insert({-newRating, food});
    }

    string highestRated(string cuisine) {
        // The set is sorted by (-rating, food), so begin() is the highest rated
        return cuisineFoods[cuisine].begin()->second;
    }
};


int main() {
    vector<string> foods = {"kimchi","miso","sushi","moussaka","ramen","bulgogi"};
    vector<string> cuisines = {"korean","japanese","japanese","greek","japanese","korean"};
    vector<int> ratings = {9, 12, 8, 15, 14, 7};

    FoodRatings fr(foods, cuisines, ratings);

    cout << fr.highestRated("korean") << endl;   // kimchi
    cout << fr.highestRated("japanese") << endl; // ramen

    fr.changeRating("sushi", 16);
    cout << fr.highestRated("japanese") << endl; // sushi

    fr.changeRating("ramen", 16);
    cout << fr.highestRated("japanese") << endl; // ramen (tie -> lexicographically smaller)

    return 0;
}