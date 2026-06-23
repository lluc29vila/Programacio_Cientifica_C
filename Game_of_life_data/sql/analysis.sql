-- Células vivas por generación, para un run específico
SELECT generation, topology, SUM(state) AS celulas_vivas
FROM life
WHERE run_id = 1
GROUP BY generation, topology
ORDER BY generation;

-- Generación con más células vivas, por run
SELECT run_id, generation, SUM(state) AS celulas_vivas
FROM life
GROUP BY run_id, generation
ORDER BY run_id, celulas_vivas DESC;

-- Última generación de cada run: ¿sobrevivió alguna célula?
SELECT run_id, generation, SUM(state) AS celulas_vivas
FROM life l
WHERE generation = (SELECT MAX(generation) FROM life WHERE run_id = l.run_id)
GROUP BY run_id, generation
ORDER BY run_id;

-- Comparar evolución promedio entre topologías (closed vs periodic)
SELECT topology, generation, AVG(celulas_vivas) AS promedio_vivas
FROM (
    SELECT run_id, topology, generation, SUM(state) AS celulas_vivas
    FROM life
    GROUP BY run_id, topology, generation
) sub
GROUP BY topology, generation
ORDER BY topology, generation;

-- Detectar si un run llegó a "extinción" (0 células vivas) y en qué generación
SELECT run_id, MIN(generation) AS generacion_extincion
FROM (
    SELECT run_id, generation, SUM(state) AS celulas_vivas
    FROM life
    GROUP BY run_id, generation
) sub
WHERE celulas_vivas = 0
GROUP BY run_id
ORDER BY run_id;

-- Detectar estabilización: generaciones consecutivas con el mismo número de células vivas
SELECT run_id, generation, celulas_vivas,
       celulas_vivas - LAG(celulas_vivas) OVER (PARTITION BY run_id ORDER BY generation) AS diferencia
FROM (
    SELECT run_id, generation, SUM(state) AS celulas_vivas
    FROM life
    GROUP BY run_id, generation
) sub
ORDER BY run_id, generation;

-- Celda específica: su estado a lo largo de todas las generaciones (para un run)
SELECT generation, state
FROM life
WHERE run_id = 1 AND row_num = 5 AND col_num = 5
ORDER BY generation;

-- Promedio de células vivas iniciales (generación 0) por experimento
SELECT e.experiment_id, AVG(sub.celulas_vivas) AS promedio_inicial
FROM (
    SELECT run_id, SUM(state) AS celulas_vivas
    FROM life
    WHERE generation = 0
    GROUP BY run_id
) sub
JOIN runs r ON sub.run_id = r.run_id
JOIN experiments e ON r.experiment_id = e.experiment_id
GROUP BY e.experiment_id;