-- Número de células vivas por generación

SELECT generation, COUNT(*) FROM life WHERE state = 1 GROUP BY generation;

-- Comparación entre topologías

SELECT topology, generation, COUNT(*) FROM life WHERE state = 1 GROUP BY topology, generation;