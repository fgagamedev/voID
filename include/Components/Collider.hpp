#ifndef __COLLIDER__
#define __COLLIDER__

#include "Engine/Component.hpp"

using namespace std;

class Collider : public Component {
public:
    Collider(GameObject *owner, int layer) : Component(owner, C_PHYSICS) {
        m_componentLayer = layer;
  };
    virtual int GetLayer() final { return m_componentLayer; };

private:
    int m_componentLayer;
};

#endif
