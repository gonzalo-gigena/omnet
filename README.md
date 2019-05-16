# Redes y Sistemas distribuidos

## Laboratorio 3
----
## Caso de estudio 1


**Intervalos usados 0.1 - 0.15 - 0.175**

  Con un **intervalo de generación de exponential(0.1)** el 99.5% de los paquetes generados fueron recibidos. Mientras que el 50.42% fueron procesados en el Sink, mientras que el 38.9% de los paquetes restantes fueron perdidos, debido a la falta de espacio en la cola del nodo receptor.
El otro 10.68% quedaron pendientes para ser procesados.


Al cambiar el  **intervalo a exponential(0.15)** se generan menos paquetes por aumentar el tiempo de generacion en NodeTx. El 100% de los paquetes generados fueron enviados a la Queue, pero solo el 76.4% de los recibidos fueron procesados por el receptor. En total se perdieron 8.2% de esos paquetes de la Queue al receptor (NodeRx).


Cuando probamos con un **intervalo de exponential(0.175)** dejamos de perder paquetes entre la Queue y el receptor a causa de aumentar el tiempo de generacion de paquetes en NodeTx. Sin embargo el Sink pudo procesar un 88% de los paquetes.

Luego de analizar estos tres intervalos, nos damos cuenta que tenemos un problema de flujo, causado por un emisor que genera muchos mas paquetes de los que puede procesar el receptor.
A medida que el intervalo de generacion aumentaba se producia una mejora de porcentaje de paquetes que podia procesar el receptor, pero a costa de enviar menos cantidad de paquetes. 

![chart](./images/chart.jpeg)
