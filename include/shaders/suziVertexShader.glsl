
    #version 330
    uniform mat4 model;
    uniform mat4 view;
    uniform mat4 project;
    layout(location=0) in vec3 vp;
    layout(location=1) in vec3 vn;
    out vec3 FragPos;
    out vec3 Normal;
    void main () {
         FragPos = vec3(model * vec4(vp, 1.0));
         Normal = mat3(transpose(inverse(model))) * vn;
         gl_Position = project * view * model * vec4(vp, 1.0);
    }