class FoodRatings {
    unordered_map< string,int >foodrating;
    unordered_map< string,string>foodcuisine;
    unordered_map< string, set<pair<int,string>> >Cuisine;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
           Cuisine[cuisines[i]].insert({-ratings[i],foods[i]});
           foodrating[foods[i]]=ratings[i];
           foodcuisine[foods[i]]=cuisines[i];
        }

    }
    
    void changeRating(string food, int newRating) {
        int oldrating=-1*foodrating[food];
        string cuisine=foodcuisine[food];
        auto it=Cuisine[cuisine].find({oldrating,food});
        Cuisine[cuisine].erase(it);
        Cuisine[cuisine].insert({-newRating,food});
        foodrating[food]=newRating;
    }
    
    string highestRated(string cuisine) {
      return  Cuisine[cuisine].begin()->second;
    }
};

