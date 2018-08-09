for((i=$1;i<$2;i++))
do
    echo "Clearing model_output..."
    rm -r model_output/*
    mr=` printf "%02d/" $i `
    echo "Copying model_run_posterior${mr} into model_output..."
    cp -r model_run_posterior${mr}* model_output/
    echo "Running model..."
    ./run.sh 0 20
    echo "Copying model_output into model_run_posterior${mr} ..."
    rm -r model_run_posterior${mr}*
    cp -r model_output/* model_run_posterior${mr}
    echo "Running ./COLLECT.sh for ../model_run_posterior${mr} ..."
    cd scripts/
    ./COLLECT.sh ../model_run_posterior${mr} ../model_run_posterior${mr}
    cd ../
    echo "Copying model_run_posterior${mr}I* into scripts/calculations/balancefunction/model_run${mr}posterior/"
    cp -v model_run_posterior${mr}I* scripts/calculations/balancefunction/model_run${mr}posterior/
done