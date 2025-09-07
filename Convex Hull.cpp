// 0 - based indexing
struct pt {
    double x, y;
    int idx;

    pt(double _x = 0, double _y = 0, int _idx = 0){
        x = _x, y = _y, idx = _idx;
    }
};

class CH{
public:
    double cross (pt a, pt b, pt c) {
        return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x); 
        // returns positive for counter-clockwise
    }

    bool cw(pt a, pt b, pt c, bool include_collinear){
        double area = cross(a, b, c);
        return (area < 0) | (!include_collinear & area == 0); // decides if it is clockwise or not
    }

    int n, sz;
    vector<pt>p, hull;

    void init(vector<pt>&a){
        n = (int)a.size();
        p = a;
    }

    void buildconvexhull(bool include_linear){
        sort(p.begin(), p.end(), [](pt a, pt b){
            if(a.x != b.x) return a.x < b.x;
            return a.y < b.y;
        });

        sz = 0;
        hull.clear();

        /// Building lower hull
        for(int i = 0; i < n; i++) {
            while (sz > 1 && cw(p[i], hull[sz - 1], hull[sz - 2], include_linear)){
                hull.pop_back(); 
                sz--;
            }
            hull.push_back(p[i]);
            sz++;
        }

        /// Building upper hull
        for(int i = n - 2, j = sz + 1; i >= 0; i--) {
            while (sz >= j && cw(p[i], hull[sz - 1], hull[sz - 2], include_linear)){
                hull.pop_back();
                sz--;
            }
            hull.push_back(p[i]);
            sz++;
        }

        hull.pop_back();
        sz--;
    }

    vector<pt>getconvexhull(){
        return hull;
    }
};
