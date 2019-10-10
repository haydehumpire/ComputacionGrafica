# Repositorio del curso de Computación Grafica - Ciencia de la computación 2019
Profesor: 
- Dr. Juan Carlos Gutierrez Caceres

Estudiante:
- Hayde Luzmila Humpire Cutipa

Requerimientos:
- Para la instalación de OpenGL se necesitara ejecutar los siguientes comandos para obtener lo necesario.

En Ubuntu:
```
$ sudo apt-get update
$ sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev
```

# 1.Circunferencia
El sistema de recomendación esta preparado para trabajar con 4 bases de datos: Books de 1M, Movielens de 10M, Movielens de 20M y Movielens de 27M.
```
for artist in neighborRatings: #buscar las calificaciones que el vecino hizo y el usuario no hizo
    if not artist in userRatings:
        if neighborRatings[artist] >= self.umbral or self.umbral==0: #Consideracion de umbral
            if artist not in recommendations:
                recommendations[artist] = neighborRatings[artist]
            else:
                recommendations[artist] = (recommendations[artist] + neighborRatings[artist])/2 #Obtener un ponderado

```
![bd_disponibles](Imagenes/bd_disponibles.PNG)

# 2.Recta-2D-3D
El sistema de recomendación esta preparado para trabajar con 4 bases de datos: Books de 1M, Movielens de 10M, Movielens de 20M y Movielens de 27M.
```
for artist in neighborRatings: #buscar las calificaciones que el vecino hizo y el usuario no hizo
    if not artist in userRatings:
        if neighborRatings[artist] >= self.umbral or self.umbral==0: #Consideracion de umbral
            if artist not in recommendations:
                recommendations[artist] = neighborRatings[artist]
            else:
                recommendations[artist] = (recommendations[artist] + neighborRatings[artist])/2 #Obtener un ponderado

```
![bd_disponibles](Imagenes/bd_disponibles.PNG)

# 3.Polígono
El sistema de recomendación esta preparado para trabajar con 4 bases de datos: Books de 1M, Movielens de 10M, Movielens de 20M y Movielens de 27M.
```
for artist in neighborRatings: #buscar las calificaciones que el vecino hizo y el usuario no hizo
    if not artist in userRatings:
        if neighborRatings[artist] >= self.umbral or self.umbral==0: #Consideracion de umbral
            if artist not in recommendations:
                recommendations[artist] = neighborRatings[artist]
            else:
                recommendations[artist] = (recommendations[artist] + neighborRatings[artist])/2 #Obtener un ponderado

```
![bd_disponibles](Imagenes/bd_disponibles.PNG)

# 4.Traslación, Rotación y Escalar 2D
El sistema de recomendación esta preparado para trabajar con 4 bases de datos: Books de 1M, Movielens de 10M, Movielens de 20M y Movielens de 27M.
```
for artist in neighborRatings: #buscar las calificaciones que el vecino hizo y el usuario no hizo
    if not artist in userRatings:
        if neighborRatings[artist] >= self.umbral or self.umbral==0: #Consideracion de umbral
            if artist not in recommendations:
                recommendations[artist] = neighborRatings[artist]
            else:
                recommendations[artist] = (recommendations[artist] + neighborRatings[artist])/2 #Obtener un ponderado

```
![bd_disponibles](Imagenes/bd_disponibles.PNG)

# 5.Pintar
El sistema de recomendación esta preparado para trabajar con 4 bases de datos: Books de 1M, Movielens de 10M, Movielens de 20M y Movielens de 27M.

```
for artist in neighborRatings: #buscar las calificaciones que el vecino hizo y el usuario no hizo
    if not artist in userRatings:
        if neighborRatings[artist] >= self.umbral or self.umbral==0: #Consideracion de umbral
            if artist not in recommendations:
                recommendations[artist] = neighborRatings[artist]
            else:
                recommendations[artist] = (recommendations[artist] + neighborRatings[artist])/2 #Obtener un ponderado

```
![bd_disponibles](Imagenes/bd_disponibles.PNG)


# Resultado Final: Animacion de todos los resultados 
Ejecución del codigo y prueba de funcionalidad:
![](ejecucion_video.gif)



