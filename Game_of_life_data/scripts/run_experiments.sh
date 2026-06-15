#!/bin/bash

#Copilación programas

echo "Compiling programs..."

gcc -Wall -Wextra src/gen_life_world.c -o src/gen_life_world.exe

if [ $? -ne 0 ]; then
    echo "Error compiling gen_life_world.c"
    exit 1
fi

gcc -Wall -Wextra src/game_of_life_csv.c -o src/game_of_life_csv.exe

if [ $? -ne 0 ]; then
    echo "Error compiling game_of_life_csv.c"
    exit 1
fi

echo "Compilation successful."
echo ""

#Ejecución experimentos

echo "===== GAME OF LIFE EXPERIMENTS ====="

read -p "Rows: " ROWS
read -p "Columns: " COLS
read -p "Generations: " GENERATIONS
read -p "Number of experiments: " N_EXPERIMENTS

#PSQL
PSQL="psql -U postgres -d gameoflife -t -A -q"

echo ""
echo "Starting experiments..."
echo ""

#Lleno datos Tabla experimentos y guardo el experimento_id
EXPERIMENT_ID=$($PSQL -c "INSERT INTO experiments (rows, cols, generations, num_runs) VALUES ($ROWS, $COLS, $GENERATIONS, $N_EXPERIMENTS) RETURNING experiment_id;")
EXPERIMENT_ID=$(echo "$EXPERIMENT_ID" | tail -n 1 | xargs)

for ((RUN_NUM=1; RUN_NUM<=N_EXPERIMENTS; RUN_NUM++))
do
    echo "-----------------------------------"
    echo "Experiment $RUN_NUM / $N_EXPERIMENTS"
    echo "-----------------------------------"

    echo "Generating initial world..."

    #Semilla aleatoria
    SEED=$((RANDOM))
    ./src/gen_life_world.exe "$ROWS" "$COLS" "$SEED"

    echo "Running simulation..."

    RUN_ID=$($PSQL -c "INSERT INTO runs(experiment_id, seed) VALUES($EXPERIMENT_ID, $SEED) RETURNING run_id;")
    RUN_ID=$(echo "$RUN_ID" | tail -n 1 | xargs)

    echo "experiment_id = $EXPERIMENT_ID"
    echo "run_id = $RUN_ID"
    echo "seed = $SEED"

    ./src/game_of_life_csv.exe data/inputs/life_input.txt "$GENERATIONS" "$RUN_ID"

    echo "Simulation completed."

    # Importar datos
    $PSQL -c "\copy life(run_id,generation,row_num,col_num,state,topology) FROM 'data/outputs/life.csv' WITH (FORMAT csv, HEADER true);"
    if [ $? -ne 0 ]; 
        then
        echo "Error importing CSV."
        exit 1
    fi


    echo ""
done

echo "All experiments finished."