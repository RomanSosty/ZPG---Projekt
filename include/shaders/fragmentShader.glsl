#version 330
in vec3 FragPos;
in vec3 Normal;
out vec4 frag_color;
uniform vec3 lightPos;

uniform vec3 lightColor;
uniform vec3 objectColor;
    uniform vec3 viewPos;
    uniform float shininess;
    void main () {
         vec3 ambient = 0.1 * objectColor; // ambientní složka osvětlení
         vec3 lightDir = normalize(lightPos - FragPos);
         float diff = max(dot(Normal, lightDir),0.0);
         vec3 diffuse = diff * lightColor * objectColor; // difúzní složka
         vec3 viewDir = normalize(viewPos - FragPos);
         vec3 reflectDir = reflect(-lightDir, Normal);
         float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
         vec3 specular = spec * lightColor; // spekulární složka osvětlení
         vec3 result = (ambient + diffuse + specular);
         frag_color = vec4(result, 1.0);
    }