#include "Particle.hpp"

class Confetti : public Particle
{
private:
  ofColor _color;

public:
  Confetti(glm::vec2 position);

  void display() override;
};
