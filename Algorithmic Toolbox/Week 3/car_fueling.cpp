#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int num_stops = 0;
    int tank_state = tank;
    int avance = 0;
    for (size_t i = 0; i < stops.size(); i++){
        if(stops[i]-avance <= tank_state){
            tank_state = tank_state - (stops[i]-avance);
            avance = stops[i];
        }
        else{
            tank_state = tank;
            num_stops++;
            if(stops[i]-avance <= tank_state){
                tank_state = tank_state - (stops[i]-avance);
                avance = stops[i];
            }
            else{
                return -1;
            }
        }
    }
    if(dist - avance<= tank_state){
        return num_stops;
    }
    if(dist - avance <= tank){
        return num_stops+1;
    }
    return -1;
    
    
    
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
