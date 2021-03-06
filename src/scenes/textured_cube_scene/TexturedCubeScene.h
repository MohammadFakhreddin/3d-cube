#ifndef TexturedCubeScene_Class
#define TexturedCubeScene_Class

#include <memory>

#include "../base_scene/BaseScene.h"
#include "../../camera/Camera.h"
#include "../../open_gl/OpenGl.h"
#include "../../shaders/directional_light/DirectionalLight.h"
#include "../../3d/models/DiceCube.h"
#include "../../pipeline/Pipeline.h"

#define TEXTURED_CUBE_SCENE_SPEED 900.0f

class TexturedCubeScene : public BaseScene {

private:

  static constexpr float shapeRotationSpeed = 0.01f * TEXTURED_CUBE_SCENE_SPEED;

  static constexpr float lightTransformSpeed = 0.01f * TEXTURED_CUBE_SCENE_SPEED;

public:

  TexturedCubeScene(OpenGL& gl);

  void update(double deltaTime) override;

  void render(double deltaTime) override;

private:

  Camera cameraInstance;

  std::unique_ptr<Shape3d> cube;

  DiceCube dice;

  std::unique_ptr<DirectionalLight> directionalLight;

  std::unique_ptr<AmbientLight> ambientLight;

  float lightRotationX = 0.0f;

  float lightRotationY = 0.0f;

  float lightRotationZ = 0.0f;

  PipeLine pip;

};

#endif // !TexturedCubeScene_Class
