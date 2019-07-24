#include "ofMain.h"
#include "Particle.hpp"
#include "Repeller.hpp"
#include <vector>

class ParticleSystem
{
private:
  glm::vec2 _origin;
  std::vector<Particle*> _particles;

public:
  ParticleSystem(glm::vec2 position);
  void addParticle();
  void run();
  void applyForce(glm::vec2 force);
  void applyRepeller(Repeller* repeller);
};
