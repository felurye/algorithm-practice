;A fórmula para calcular a área de uma circunferência é: area = π . raio2. Considerando para este problema que π = 3.14159:
;- Efetue o cálculo da área, elevando o valor de raio ao quadrado e multiplicando por π.

(def pi 3.14159)

(def raio (read-string (read-line)))
(def area (* pi (Math/pow raio 2)))

(println (format "A=%.4f" area))