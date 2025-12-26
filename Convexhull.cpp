#include<iostream>
#include<utility>
#include<stack>
#include<vector>

class convexHull{
    private:

    std::vector<std::pair<float, float>> points;
    std::pair<float, float> startPoint = std::make_pair(INT16_MAX, INT16_MAX);
    
    void sort(int l, int r){
        if (l == r) return;
        int mid = (l+r)/2;
        sort(l, mid);
        sort(mid+1, r);
        std::vector<std::pair<float, float>> leftPoints(points.begin(), points.begin() + mid);
        std::vector<std::pair<float, float>> rightPoints(points.begin() + mid + 1, points.end() - 1);
        for (int idxL = 0, idxR = 0; idxL < points.size() || idxR < points.size();){
            if (leftPoints[idxL].first < rightPoints[idxR].first)
        }
    }

    public:

    void init(std::vector<std::pair<float, float>> initPoints){
        points = initPoints;
    }

    void findStartPoint(){
        for (int i = 0; i < points.size(); i++){
            if (points[i].second < startPoint.second){
                startPoint.second = points[i].second;
            }
        }
    }

    std::vector<std::pair<float, float>> convexFind(){
        
    }
};

int main(){
    int n;
    std::cin >> n;
    std::pair<float, float> points[n];
    for (int i = 0; i < n; i++){
        std::cin >> points[i].first >> points[i].second;
    }

    return 0;
}