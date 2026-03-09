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

![Sensor.png](attachment:2b058d79-32d3-4712-94a1-87b555a25612:Sensor.png)

### 2.2. Diagrama de circuito

El sistema electrónico fue representado mediante un diagrama esquemático elaborado en el software KiCad, donde se muestran las interconexiones entre el microcontrolador, el sensor ultrasónico y los elementos de señalización visual. El núcleo del circuito está constituido por el módulo ESP32-WROOM-32, el cual actúa como unidad de procesamiento y control del sistema.

Para la medición de distancia se emplea el sensor ultrasónico HC-SR04, el cual se conecta al microcontrolador mediante cuatro terminales.Asimismo, el sistema incluye tres diodos emisores de luz (LED) utilizados como indicadores visuales del rango de distancia detectado. Cada LED se conecta a un pin de salida digital del microcontrolador y se encuentra en serie con una resistencia de 200 Ω, cuya función es limitar la corriente que circula por el diodo para evitar su deterioro.
![image.png](attachment:0b5bc234-7592-4767-b0f1-a7689a24dac0:b3a6b9ea-1ab6-4b94-be5d-215cd7247ad3.png)