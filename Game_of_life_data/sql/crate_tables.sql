CREATE TABLE runs (
    run_id SERIAL NOT NULL PRIMARY KEY,
    execution_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    rows INT,
    cols INT,
    generations INT,
    topology_mode VARCHAR(50),
    description TEXT
);

CREATE TABLE life (
    run_id INT NOT NULL REFERENCES runs(run_id),
    generation INT,
    row_num INT,
    col_num INT,
    state INT,
    topology VARCHAR(20)
);