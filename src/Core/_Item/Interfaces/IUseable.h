#pragma once

#include "CoreDefinitions.h"

class Entity;

class IUseable
{
public:
  IUseable(TargetType target, EffectType effect_type, int duration)
      : m_target_type(target),
        m_effect_type(effect_type),
        m_duration(duration) {};

  virtual ~IUseable() = default;

  virtual void use(Entity *target) = 0;

  TargetType   get_target_type() const
  {
    return m_target_type;
  }

  EffectType get_effect_type() const
  {
    return m_effect_type;
  }

  int get_remaining_duration() const
  {
    return m_duration;
  }

protected:
  TargetType m_target_type;
  EffectType m_effect_type;
  int        m_duration;
};
