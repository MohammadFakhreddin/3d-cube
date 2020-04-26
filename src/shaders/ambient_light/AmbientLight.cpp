#include "./AmbientLight.h"

#include <cassert>

/*
AmbientLight::AmbientLight(
  const float& colorR,
  const float& colorG,
  const float& colorB
) 
  :
  color(colorR,colorG,colorB)
{

  assert(colorR >= 0.0f && colorR <= 1.0f);
  assert(colorG >= 0.0f && colorG <= 1.0f);
  assert(colorB >= 0.0f && colorB <= 1.0f);

  color.setR(colorR);
  color.setG(colorG);
  color.setB(colorB);

}

AmbientLight(const Matrix3X1Float& paramColor)
{
  assert(color.getR() >= 0.0f && color.getR() <= 1.0f);
  assert(color.getG() >= 0.0f && color.getG() <= 1.0f);
  assert(color.getB() >= 0.0f && color.getB() <= 1.0f);

  color.assign(paramColor);

}*/

AmbientLight::AmbientLight(const float& colorR, const float& colorG, const float& colorB)
{
  color.setR(colorR);
  color.setG(colorG);
  color.setB(colorB);
  assert(checkForColorValidation());
}

AmbientLight::AmbientLight(const Matrix3X1Float& paramColor)
{
  color.assign(paramColor);
  assert(checkForColorValidation());
}

bool AmbientLight::checkForColorValidation() {
  if (!(color.getR() >= 0.0f && color.getR() <= 1.0f)) {
    Logger::log("ColorR is out of range:" + std::to_string(color.getR()));
    return false;
  }
  if (!(color.getG() >= 0.0f && color.getG() <= 1.0f)) {
    Logger::log("ColorG is out of range:" + std::to_string(color.getG()));
    return false;
  }
  if (!(color.getB() >= 0.0f && color.getB() <= 1.0f)) {
    Logger::log("ColorB is out of range:" + std::to_string(color.getB()));
    return false;
  }
  return true;
}

void AmbientLight::computeLightIntensity(
  Matrix4X1Float& output
) const {
  output.assign(color);
}
