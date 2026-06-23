-- Ver todos los experimentos
SELECT * FROM experiments;

-- Ver todos los runs y a qué experimento pertenecen
SELECT * FROM runs;

-- Contar cuántas filas tiene cada run en la tabla life
SELECT run_id, COUNT(*) AS total_filas
FROM life
GROUP BY run_id
ORDER BY run_id;

-- Ver qué topologías existen
SELECT DISTINCT topology FROM life;

-- Ver el rango de generaciones por run
SELECT run_id, MIN(generation) AS gen_min, MAX(generation) AS gen_max
FROM life
GROUP BY run_id;

-- Ver tamaño del tablero (filas x columnas) por run
SELECT run_id, MAX(row_num)+1 AS filas, MAX(col_num)+1 AS columnas
FROM life
GROUP BY run_id;

-- Runs por experimento, con su seed
SELECT r.run_id, r.experiment_id, r.seed, e.rows, e.cols, e.generations
FROM runs r
JOIN experiments e ON r.experiment_id = e.experiment_id
ORDER BY r.experiment_id, r.run_id;

-- Verificar si hay valores nulos o inesperados en state
SELECT DISTINCT state FROM life;

-- Verificar duplicados (no debería haber, por la primary key)
SELECT run_id, topology, generation, row_num, col_num, COUNT(*)
FROM life
GROUP BY run_id, topology, generation, row_num, col_num
HAVING COUNT(*) > 1;