struct Point {
      int x;
      int y;
      Point() : x(0), y(0) {}
      Point(int a, int b) : x(a), y(b) {}
};
 
 
 // 1. <x, y> are int types. so it needs to convert that to double for slope computation.
 // 2. be clear about the definition of the duplicates: points[i] is the first duplicates
 // 3. the result is consisted of the starting point(s) and the slope points.
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if(points.size()<=2) return points.size();
        int m_points = 0;
        for(int i=0; i<points.size(); i++) {
            vector<double> slopes;
            slopes.clear();
            Point p = points[i];
            int dup = 1;
            for(int j=i+1; j<points.size(); j++) {
                Point q = points[j];
                if(p.x==q.x) {
                    if(p.y==q.y) {
                        dup++;
                    }else {
                        slopes.push_back(999999);
                    }
                }else {
                    double slope = ((double)p.y-q.y)/(p.x-q.x);
                    slopes.push_back(slope);
                }
            }
            std::sort(slopes.begin(), slopes.end());
            double tmp=999999; int max_count =0; int count =0;
            for(int j=0; j<slopes.size(); j++) {
                if(abs(slopes[j]-tmp)>0.0000001) {
                    max_count = max(max_count, count);
                    count =1;
                    tmp = slopes[j];
                }else {
                    count ++;
                }
            }
            if(slopes.size()>0) {
                max_count = max(max_count, count);
            }
            
            m_points = max(dup+max_count, m_points );
        }
        return m_points;
    }
