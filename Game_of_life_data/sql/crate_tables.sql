CREATE TABLE experiments (
    experiment_id SERIAL NOT NULL PRIMARY KEY,
    rows INTEGER,
    cols INTEGER,
    generations INTEGER,
    num_runs INTEGER,
    execution_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE runs (
    run_id SERIAL NOT NULL PRIMARY KEY,
    experiment_id INTEGER NOT NULL REFERENCES experiments(experiment_id),
    seed INTEGER NOT NULL
);

CREATE TABLE life (
    run_id INT NOT NULL REFERENCES runs(run_id),

    generation INT NOT NULL,
    row_num INT NOT NULL,
    col_num INT NOT NULL,

    state INT NOT NULL CHECK (state IN (0,1)),

    topology VARCHAR(20) NOT NULL,

    PRIMARY KEY (
        run_id,
        topology,
        num_gen
        generation,
        row_num,
        col_num
    )
);