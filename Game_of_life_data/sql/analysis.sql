-- Células vivas por generación, para una run en específico
SELECT generation, topology, SUM(state) AS celulas_vivas
FROM life
WHERE run_id = 1
GROUP BY generation, topology
ORDER BY generation;

-- Lo mismo pero para una topology en específico
SELECT generation, SUM(state) AS celulas_vivas
FROM life
WHERE run_id = 1 AND topology = 'periodic'
GROUP BY generation
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

-- Comparar evolución promedio entre topologías en un mismo experimento para evitar comparar mundos de muy distinto tamanyo
SELECT topology, generation, AVG(celulas_vivas) AS promedio_vivas
FROM (
    SELECT l.run_id, l.topology, l.generation, SUM(l.state) AS celulas_vivas
    FROM life l
    JOIN runs r ON l.run_id = r.run_id
    WHERE r.experiment_id = 1
    GROUP BY l.run_id, l.topology, l.generation
) sub
GROUP BY topology, generation
ORDER BY topology, generation;

-- Detectar si una run llegó a la "extinción" (0 células vivas) y en qué generación
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
SELECT generation, topology, state
FROM life
WHERE run_id = 1 AND row_num = 5 AND col_num = 5
ORDER BY generation, topology;

-- Promedio de células vivas iniciales (generación 0) por experimento (se filtra por closed ya qe no importa al ser el mundo inicial), con el tamaño del mundo y la tasa de vivas inicial
SELECT e.experiment_id, ROUND(AVG(sub.celulas_vivas), 4) AS promedio_inicial, e.rows *e.cols AS total_celdas, ROUND(AVG(sub.celulas_vivas) / (e.rows * e.cols), 4) AS tanto_por_uno_vivas
FROM (
    SELECT run_id, SUM(state) AS celulas_vivas
    FROM life
    WHERE generation = 0 AND topology = 'closed'
    GROUP BY run_id
) sub
JOIN runs r ON sub.run_id = r.run_id
JOIN experiments e ON r.experiment_id = e.experiment_id
GROUP BY e.experiment_id, e.rows, e.cols;

-- Tabla anterior añadiendo maximos y minimos, desviación estandar y porcentiles
SELECT 
    topology, 
    generation, 
    AVG(celulas_vivas) AS promedio_vivas,
    STDDEV(celulas_vivas) AS sd_vivas,
    MIN(celulas_vivas) AS min_vivas,
    MAX(celulas_vivas) AS max_vivas
  FROM (
    SELECT l.run_id, l.topology, l.generation, SUM(l.state) AS celulas_vivas
    FROM life l
    JOIN runs r ON l.run_id = r.run_id
    WHERE r.experiment_id = 10
    GROUP BY l.run_id, l.topology, l.generation
  ) sub
  GROUP BY topology, generation
  ORDER BY topology, generation;q