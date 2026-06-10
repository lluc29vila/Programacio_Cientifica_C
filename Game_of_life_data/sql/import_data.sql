TRUNCATE TABLE life;

\copy life FROM 'life.csv' WITH (FORMAT csv, HEADER true);