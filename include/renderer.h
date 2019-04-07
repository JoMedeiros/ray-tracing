#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "buffer.h"
#include "background.h"
#include "camera.h"

class Renderer 
{
public:
  Buffer* buffer;
  Background* bg;
  Camera* camera;
  void run();
  void save_img();
};

#endif
