class FoodRatings {
    unordered_map< string,pair<int,string>>foodratingncuisine;
    unordered_map< string, set<pair<int,string>> >Cuisine;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
           Cuisine[cuisines[i]].insert({-ratings[i],foods[i]});
           foodratingncuisine[foods[i]]={ratings[i],cuisines[i]};
        }

    }
    
    void changeRating(string food, int newRating) {
        int oldrating=foodratingncuisine[food].first;
        string cuisine=foodratingncuisine[food].second;
        Cuisine[cuisine].erase({-oldrating,food});
        Cuisine[cuisine].insert({-newRating,food});
        foodratingncuisine[food]={newRating,cuisine};
    }
    
    string highestRated(string cuisine) {
      return  Cuisine[cuisine].begin()->second;
    }
};

