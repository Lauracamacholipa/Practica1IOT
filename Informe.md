# Práctica 1 — Integración de Sensores y Actuadores en un Objeto Inteligente

**Carrera:** Ingeniería de Sistemas

**Docente**: Eduardo Enrique Marin Garcia

**Asignatura:** SIS-234 - Internet de las Cosas

**Integrantes**: 

- Laura Camacho Lipa
- Sergio Francisco Solis Luizaga
- Cristhian Butron

---

# **1. Requerimientos Funcionales y No Funcionales**

## 1.1. Requerimientos funcionales

**RF01:** El sistema será capaz de medir la distancia entre el sensor ultrasónico y un objeto ubicado frente a él dentro del rango de 2 cm a 200 cm.

**RF02:** El sistema será capaz de clasificar correctamente la distancia medida en tres rangos definidos (<30 cm, 30–100 cm y ≥100 cm) con una precisión mínima del 90%.

**RF03:** El sistema será capaz de activar el LED correspondiente al rango de distancia detectado con una tasa de activación correcta mínima del 95%.

| <30 cm | LED Rojo |
| --- | --- |
| 30-100 cm | LED Amarillo |
| >100 cm | LED Verde |

**RF04:** El sistema será capaz de actualizar el estado del actuador correspondiente después de detectarse un cambio de rango en la distancia medida.

## 1.2. Requerimientos no funcionales

**RNF01:** El código fuente deberá utilizar nombres descriptivos para variables, funciones y constantes.

**RNF02:** El código deberá incluir comentarios que describan la lógica del algoritmo y el funcionamiento de las funciones principales.

**RNF03:** El sistema deberá utilizar una arquitectura modular basada en clases para facilitar el mantenimiento y la extensión del código.

**RNF04:** El sistema deberá operar de forma estable durante sesiones de funcionamiento continuo de al menos 10 minutos sin presentar bloqueos o reinicios del microcontrolador.

# **2. Diseño del Sistema**

### 2.1. Diagrama de bloques

El diagrama de bloques muestra la interacción general entre los componentes principales del sistema, incluyendo el sensor ultrasónico, el microcontrolador y los actuadores representados por los LEDs.

<img width="755" height="130" alt="image" src="https://github.com/user-attachments/assets/363688c5-c026-4bce-a089-12b08382de92" />


### 2.2. Diagrama de circuito

El sistema electrónico fue representado mediante un diagrama esquemático elaborado en el software KiCad, donde se muestran las interconexiones entre el microcontrolador, el sensor ultrasónico y los elementos de señalización visual. El núcleo del circuito está constituido por el módulo ESP32-WROOM-32, el cual actúa como unidad de procesamiento y control del sistema.

Para la medición de distancia se emplea el sensor ultrasónico HC-SR04, el cual se conecta al microcontrolador mediante cuatro terminales.Asimismo, el sistema incluye tres diodos emisores de luz (LED) utilizados como indicadores visuales del rango de distancia detectado. Cada LED se conecta a un pin de salida digital del microcontrolador y se encuentra en serie con una resistencia de 200 Ω, cuya función es limitar la corriente que circula por el diodo para evitar su deterioro.
<img width="688" height="426" alt="image" src="https://github.com/user-attachments/assets/6ccbc779-8cfa-4669-8d35-0155c89208b1" />

### 2.3. Diagrama de arquitectura del sistema

El sensor HC-SR04 mide el tiempo de retorno del eco, el microcontrolador Arduino calcula la distancia y clasifica el resultado en uno de los tres rangos definidos, activando el LED correspondiente para indicar visualmente la distancia detectada.

![image.png](attachment:55d14427-39b7-492f-96c2-86a473d5cb49:image.png)

### 2.4. Diagramas estructurales y de comportamiento

El diagrama estructural muestra los componentes principales del sistema: el sensor ultrasónico HC-SR04 encargado de medir la distancia, el microcontrolador Arduino responsable del procesamiento de los datos y la clasificación del rango de distancia, y el sistema de LEDs que indica visualmente el resultado de la medición

![image.png](attachment:fc50120e-af58-4028-8514-c83298df9544:image.png)

Diagrama de comportamiento del algoritmo de medición y clasificación de distancia.

![image.png](attachment:9d83f4d3-9377-47a7-ae0c-d11901f77375:image.png)

# **3. Implementación**

El sistema fue implementado utilizando el microcontrolador Arduino y programado en el entorno **Arduino IDE**, empleando el lenguaje **C++**.

El diseño del software se estructuró de manera modular mediante el uso de clases, separando las responsabilidades del sistema en los siguientes componentes:

- **Clase `UltrasonicSensor`**: responsable de la lectura y filtrado de las mediciones del sensor ultrasónico.
- **Clase `Led`**: encargada de controlar el encendido, apagado y parpadeo de los LEDs.
- **Clase `DistanceController`**: implementa la lógica de clasificación de distancias y la activación de los actuadores.
- **Archivo principal `main.ino`**: inicializa el sistema y ejecuta el ciclo principal de control.

Durante la ejecución del programa, el microcontrolador realiza lecturas periódicas del sensor ultrasónico, calcula la distancia al objeto y clasifica el valor obtenido dentro de los rangos definidos. En función del rango detectado, el sistema activa el LED correspondiente para indicar visualmente la distancia medida.

El código fuente completo del proyecto se encuentra disponible en el repositorio del proyecto.

# **4. Pruebas y Validaciones**

## 4.1. Objetivo de las pruebas

El objetivo de las pruebas es verificar que el sistema desarrollado cumple con los requerimientos funcionales definidos, evaluando:

- la **precisión de medición del sensor ultrasónico**
- la **correcta clasificación de los rangos de distancia**
- la **activación adecuada de los LEDs según la distancia detectada**

## 4.2. Metodología de pruebas

Las pruebas se realizaron utilizando el prototipo implementado con el microcontrolador y el sensor ultrasónico.

El procedimiento seguido fue:

1. Colocar un objeto frente al sensor ultrasónico.
2. Medir la distancia real utilizando una regla.
3. Registrar la distancia medida por el sensor mostrada en el monitor serial.
4. Registrar el LED activado por el sistema.
5. Comparar los resultados con los valores esperados.

Se realizaron 30 mediciones experimentales, distribuidas en los tres rangos definidos en el sistema:

| Rango de distancia | LED esperado |
| --- | --- |
| < 30 cm | Rojo |
| 30 - 100 cm | Amarillo |
| > 100 cm | Verde |

## 4.3 Registro de mediciones

Durante las pruebas se obtuvieron las siguientes mediciones experimentales.

<img width="572" height="667" alt="image" src="https://github.com/user-attachments/assets/5d00a24b-34cf-449c-8a74-93bc0713eeb3" />


# **5. Resultados**

En esta sección se analizan los datos obtenidos durante las pruebas experimentales realizadas al sistema de medición de distancia con sensor ultrasónico.

A partir de las 30 mediciones realizadas, se calcularon los valores de error absoluto y error porcentual comparando la distancia real con la distancia medida por el sensor.

Los resultados muestran que el sistema presenta un error absoluto promedio de aproximadamente 1.46 cm y un error porcentual promedio cercano al 2.23 %.

Se observó que la diferencia entre la distancia real y la distancia medida aumenta ligeramente a distancias mayores, lo cual es un comportamiento esperado en sensores ultrasónicos debido a factores como la dispersión de la onda ultrasónica y las condiciones del entorno.

En cuanto al funcionamiento del sistema de clasificación por rangos de distancia, los resultados obtenidos fueron:

- Rango cercano (< 30 cm): activación correcta del LED rojo en todas las pruebas.
- Rango medio (30 – 100 cm): activación correcta del LED amarillo en todas las pruebas.
- Rango lejano (> 100 cm): activación correcta del LED verde en todas las pruebas.

Durante las 30 pruebas realizadas, el LED observado coincidió con el LED esperado en todos los casos, lo que representa un 100 % de precisión en la clasificación de distancias.

Estos resultados indican que el sistema funciona correctamente y cumple con los requerimientos funcionales establecidos para la medición y señalización de distancias.

# **6. Conclusiones**

A partir del desarrollo e implementación del sistema de medición de distancia utilizando un sensor ultrasónico y un microcontrolador, se puede concluir que el sistema cumple satisfactoriamente con los objetivos planteados al inicio del proyecto.

Las pruebas experimentales realizadas permitieron verificar el correcto funcionamiento del sensor y del algoritmo de medición, obteniendo un error promedio de aproximadamente 1.46 cm, lo cual se encuentra dentro de un rango aceptable para este tipo de sensores.

Asimismo, el sistema de señalización mediante LEDs demostró un funcionamiento correcto, activando el indicador correspondiente según el rango de distancia detectado. Durante las pruebas realizadas se obtuvo una coincidencia del 100 % entre el LED esperado y el LED observado.

Los resultados obtenidos demuestran que el sistema es capaz de medir distancias dentro del rango de operación establecido y clasificar correctamente dichas distancias mediante señales visuales, cumpliendo con los requerimientos funcionales definidos para el proyecto.

Finalmente, este proyecto permitió aplicar conceptos de programación de microcontroladores, adquisición de datos mediante sensores y validación experimental de sistemas electrónicos, fortaleciendo el aprendizaje práctico en el área de sistemas embebidos.

# **7. Recomendaciones**

A partir de los resultados obtenidos durante las pruebas del sistema, se proponen las siguientes recomendaciones para mejorar su desempeño y facilitar futuras implementaciones:

- Realizar calibraciones periódicas del sensor ultrasónico para reducir el error en las mediciones, especialmente en distancias mayores.
- Implementar un filtrado de datos, como el promedio de varias mediciones consecutivas, para disminuir las variaciones causadas por ruido o interferencias en la señal ultrasónica.
- Asegurar una correcta alineación del sensor con el objeto medido, ya que superficies inclinadas o irregulares pueden afectar la precisión de la medición.
- Evitar obstáculos o interferencias cercanas al sensor, debido a que pueden generar reflexiones adicionales de la señal ultrasónica y afectar los resultados.
- Considerar el uso de sensores de mayor precisión o mayor rango de medición en aplicaciones donde se requiera una exactitud más alta.

Estas recomendaciones pueden contribuir a mejorar la estabilidad, precisión y confiabilidad del sistema en aplicaciones futuras.

# **8. Anexos**

### **Anexo A — Registro completo de pruebas experimentales**

Excel donde se realizaron las 30 pruebas: https://docs.google.com/spreadsheets/d/1x_vcMCgnQGTEoDCdiTcxhVuf3NxjOjMr1PYVerR19v0/edit?usp=sharing 

### **Anexo B — Fotografías del prototipo experimental**

**Figura B1. Prototipo del sistema**
<img width="521" height="1156" alt="image" src="https://github.com/user-attachments/assets/d8ca3127-228e-466c-a25f-e6e52fda6d0d" />

<img width="521" height="721" alt="image" src="https://github.com/user-attachments/assets/ef867b12-8eff-4214-bd3e-ae3f1f38a690" />


**Figura B2. Prototipo del sistema durante las pruebas experimentales**
<img width="1156" height="521" alt="image" src="https://github.com/user-attachments/assets/87551caf-a192-4d0d-90da-2850f5d54f27" />

