#pragma once

struct Particle {
  public:
    float x;
    float y;
    float radius;
    float velocity;
  
  Particle(float x_, float y_, float r_, float v_) : x(x_), y(y_), radius(r_), velocity(v_) {}
 };
