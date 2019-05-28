# Ray Tracing

## How to Compile

To parse files the program needs yaml-cpp library. Currently the 
library files are installed locally. If you have yaml-cpp 
installed, change the makefile to link with the yaml-cpp directory 
in your system. To compile:

```
make
```

## Usage

```
./bin/img_gen <yaml_file> > <log_file>
```

## Checklist

- [x] Buffer
- [ ] Scene Parser 
  - [x] Parse camera
  - [x] Parse background
  - [x] Parse spheres
  - [ ] Parse integrator
  - [ ] Parse lights
- [ ] Background
  - [x] 4 points gradient
  - [ ] image as background
- [ ] Camera
  - [x] OrthoCamera
  - [ ] PerspectiveCamera
- [x] Sphere
- [ ] Triangle
- [ ] main loop
- [ ] Sampler

### TODOS

- [x] Set output file name from the yaml file
- [x] Choose file format from yaml file
- [x] Set integrator in yaml file
- [ ] Derive Integrators from SampleIntegrator
  - [x] FlatIntegrator : public SampleIntegrator
  - [x] NormalMapIntegrator : public SampleIntegrator
  - [x] DepthIntegrator : public SampleIntegrator
    - [ ] Change from ray length to actual distance from camera
    - [x] Allow user to set start and end color
    - [x] Allow user to set min a max distances
  - [ ] Implement BlinnPhongIntegrator
- [ ] Lights
  - [ ] Create lights by file
- [ ] Use samples value to initialize integrators
- [ ] Implement classes as specified in the code examples of 
project 4
- [x] Remove buffer from Renderer to Scene class
- [x] Move loop "intersection with objects" from Renderer to Scene
- [x] Put pixels loop in  Integrator
- [ ] Organize folders include and src in subdirectories
- [ ] Implement Material
- [ ] create Triangle class
- [ ] create Triangle Mesh class
- [ ] Implement BVH
- [ ] Parse OBJ
- [x] Implement save_img function in Renderer class
- [ ] Implement Sampler class
- [ ] Move camera from Scene to Integrator
- [ ] Put background in yaml file inside scene tag

