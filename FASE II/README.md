# Repositorio de Computación Grafica Cs 2019
Fase II 

Viendo la escena desde otro punto de vista: CÁMARAS
- Mover la cámara con el mouse
- Cambios de perspectiva de la cámara (ortogonal a perspectiva) 
- Mover el objeto en la proyección (con las teclas)

Requerimientos:
- OpenGL (ubuntu)
```
$ sudo apt-get update
$ sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev
```
# 1. Mover la cámara con el mouse
```
GlutMouseFunc(mouse); //Pulsado de Botones
    glutMotionFunc(NULL); //Movimiento con Botones pulsados
    glutPassiveMotionFunc(MouseMotion); //Movimientos sin Botones pulsados
```

![bd_disponibles](Imagenes/LineaMiddlePoint2D.png)

# 2. Cambios de perspectiva de la cámara (ortogonal a perspectiva) 
![](Imagenes/Escalar.gif)

# 3. Mover el objeto en la proyección (con las teclas)
![](Imagenes/Escalar.gif)


