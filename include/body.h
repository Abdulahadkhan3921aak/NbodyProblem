#include <vector2.h>
#include <cmath>
#include <omp.h>

class body
{
private:
    /* data */
    vector2 position;
    vector2 velocity;
    vector2 acceleration;
    vector2 mass;
    vector2 force;
    float size;   // on screen size
    float color;  // color on screen
    vector2 radius; // radius of the body

public:
    body(vector2 pos, vector2 vel, vector2 acc, vector2 m, vector2 f, float s, float c, vector2 r);
    ~body();
    void set_position(vector2 pos);
    void set_velocity(vector2 vel);
    void set_acceleration(vector2 acc);
    void set_mass(vector2 m);
    void set_force(vector2 f);
    void set_size(float s);
    void set_color(float c);
    void set_radius(vector2 r);
};
